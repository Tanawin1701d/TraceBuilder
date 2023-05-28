#include "pin.H"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <fstream>
#include <sstream>


//// struct of runtime trace file

const UINT32 maxRtTracing =  40000000; 
const UINT32 maxMemOpPerLS = 2;
const uint8_t UNUSED_MEMOP = -1;

const std::string REG64_PREFIX  = "mm";
const std::string REG128_PREFIX = "xmm";
const std::string REG256_PREFIX = "ymm";
const size_t      REG64_PREFIX_SIZE      = 2;
const size_t      REG128_256_PREFIX_SIZE = 3;

#pragma pack(push, 1)
struct RT_OBJ{
    uint64_t loadAddr     [maxMemOpPerLS];
    uint64_t storeAddr    [maxMemOpPerLS];
    uint32_t fetchId;
    uint8_t  amt_load;
    uint8_t  amt_store;
};
#pragma pack(pop)

///// these pragma is derived from 
//https://stackoverflow.com/questions/32109646/how-to-write-a-struct-to-file-in-c-and-read-the-file

//FILE* trace;
static std::ofstream* outputFile_instr;
static std::ofstream* outputFile_trace;
static std::ofstream* outputFile_traceDb;

//prewrite for optimize file buffering
static std::string   preWrite;
static std::string   preWriteRuntimeDebg;
struct RT_OBJ*       preWriteRt; /// 400 M times 52 bytes
UINT32 preWriteRt_idx = 0;
UINT32 INSTRID        = 0;

VOID tryFlush(bool forceFlush = false){
    if ((preWrite.size() >= 4000000000) || forceFlush){
        //std::cout << "flushing static trace" << std::endl;
        *outputFile_instr << preWrite;
        preWrite.clear();
    }
}

VOID flushDb(std::string dayta){
    *outputFile_traceDb << dayta;
}


std::string getDebugOutcome(const RT_OBJ& obj) {
    std::ostringstream ss;
    ss << "loadAddr: [";
    for (int i = 0; i < 2; i++) {
        ss << "0x" << std::hex << obj.loadAddr[i] << ", ";
    }
    ss.seekp(-2, ss.cur);
    ss << "], storeAddr: [";
    for (int i = 0; i < 2; i++) {
        ss << "0x" << std::hex << obj.storeAddr[i] << ", ";
    }
    ss.seekp(-2, ss.cur);
    ss << "], fetchId: " << std::dec << obj.fetchId << ", loadMemOpNum: [";
    // for (int i = 0; i < 2; i++) {
    //     ss << (int)obj.loadMemOpNum[i] << ", ";
    // }
    ss.seekp(-2, ss.cur);
    ss << "], storeMemOpNum: [";
    // for (int i = 0; i < 2; i++) {
    //     ss << (int)obj.storeMemOpNum[i] << ", ";
    // }
    ss.seekp(-2, ss.cur);
    ss << "]";
    return ss.str();
}


VOID flushRuntimeData(){
    if (preWriteRt_idx){
        outputFile_trace->write((char*)preWriteRt, sizeof(RT_OBJ)*preWriteRt_idx);
        ////// this is used for debug
    }
}

VOID bufferInitialize(UINT32 initIdx){

    for (uint32_t i = 0; i < maxMemOpPerLS; i++){
        preWriteRt[initIdx].amt_load  = 0;
        preWriteRt[initIdx].amt_store = 0;
    }

}

VOID L_TRACE(ADDRINT addr, UINT32 lsFieldId){
    preWriteRt[preWriteRt_idx].loadAddr[ lsFieldId ] = addr;
    preWriteRt[preWriteRt_idx].amt_load++;
}

VOID S_TRACE(ADDRINT addr, UINT32 lsFieldId){
    preWriteRt[preWriteRt_idx].storeAddr[lsFieldId] = addr;     // update address;
    preWriteRt[preWriteRt_idx].amt_store++;
}

VOID ButtomEachIntr(UINT32 fetchId){
    preWriteRt[preWriteRt_idx].fetchId = fetchId;
    //// we print debug before debug
    //preWriteRuntimeDebg += getDebugOutcome(preWriteRt[preWriteRt_idx]) + '\n';
    //flushDb(preWriteRuntimeDebg);
    //preWriteRuntimeDebg.clear();
    ////////////////////////////////
    preWriteRt_idx++;
    if ( preWriteRt_idx >= maxRtTracing){
        flushRuntimeData();
        //reset index of the buffer
        preWriteRt_idx = 0;
    }
    /// initilize for next instruction
    /// this is crucial due to inconsistent state exist
    bufferInitialize(preWriteRt_idx);
}

// The Instruction function is called for every instruction
VOID Instruction(INS ins, VOID* v)
{

    if ( INS_IsNop(ins) ){
        return;
    }
    
    //instruction
    std::string _instrName   = INS_Disassemble(ins);
    ADDRINT instrAddr        = INS_Address(ins);
    UINT32  instrSize        = INS_Size(ins);

    char buffer[32];
    sprintf(buffer, "%lx", instrAddr);
    std::string instrAddrHex(buffer);

    //mem_id counter
    UINT32 memOp = 0;
    UINT32 loaded_amt = 0;
    UINT32 stored_amt = 0;

    //instruction mode
    BOOL isVec_64  = false; ////// dtect avx and sse instruction
    BOOL isVec_128 = false; 
    BOOL isVec_256 = false;

    //decode string varible
    std::string srcKey;
    std::string desKey;
    std::string resKey;
    UINT32      opr_count = 0;

    // rflags register
    std::string rflagsStr = "rflags";

    ///////////////////////// for compute instruction
    UINT32 numOperands = INS_OperandCount(ins);

    if (INS_IsLea(ins)){
        //////// this is conrner case that pintool not verbose anything about source of effective address
        std::string preRegStr;
        ////////////////
        ///////////    memory location = baseReg + (IndexReg * scale) + displacement
        //////// WRITE DES OPERAND
        REG desReg = INS_OperandReg(ins, 0);
        preRegStr += "R "; // source register
        preRegStr += "D "; // source register
        preRegStr += REG_StringShort(static_cast<REG>(desReg));
        preRegStr += "\n";
        desKey += "R";
        opr_count += 1;
        //////// WRITE BASE OPERAND
        REG srcReg1 = INS_OperandMemoryBaseReg(ins, 1);
        if (srcReg1 != REG_INVALID()){
            preRegStr += "R "; // source register
            preRegStr += "S "; // source register
            preRegStr += REG_StringShort(static_cast<REG>(srcReg1));
            preRegStr += "\n";
            srcKey += "R";
            opr_count += 1;
        }
        //////// WRITE Index OPERAND
        REG srcReg2 = INS_OperandMemoryIndexReg(ins, 1);
        if (srcReg2 != REG_INVALID()){
            preRegStr += "R "; // source register
            preRegStr += "S "; // source register
            preRegStr += REG_StringShort(static_cast<REG>(srcReg2));
            preRegStr += "\n";
            srcKey += "R";
            opr_count += 1;
        }
        preWrite += preRegStr;
    }else{

        for (UINT32 opIdx = 0; opIdx < numOperands; opIdx++){
            ////// register operand
            if (INS_OperandIsReg(ins, opIdx)){
                    bool isSrc = INS_OperandRead   (ins, opIdx);
                    bool isDes = INS_OperandWritten(ins, opIdx);
                    REG  reg   = INS_OperandReg    (ins, opIdx);
                    //if (reg != REG_RFLAGS)
                    assert(!INS_OperandIsMemory(ins, opIdx));
                    assert(isSrc || isDes);

                    std::string preRegStr;

                    //////// WRITE REG OPERAND
                    preRegStr += "R "; // source register
                    preRegStr += "X "; // source register
                    preRegStr += reg ? REG_StringShort(static_cast<REG>(reg)) : "-1";
                    preRegStr += "\n";

                    std::string regStr = REG_StringShort(static_cast<REG>(reg));

                    /////// check is it is vector extension operand
                    if (regStr.size() > REG64_PREFIX_SIZE){
                            ////// check mm
                            if(regStr.substr(0, REG64_PREFIX_SIZE) == REG64_PREFIX){
                                isVec_64 = true;
                            }

                    }
                    if (regStr.size() > REG128_256_PREFIX_SIZE){
                            ////// check xmm ymm
                            if(regStr.substr(0, REG128_256_PREFIX_SIZE) == REG128_PREFIX){
                                isVec_128 = true;
                            }else if (regStr.substr(0, REG128_256_PREFIX_SIZE) == REG256_PREFIX){
                                isVec_256 = true;
                            }
                    }

                    /////// flag register is ignore
                    if (isSrc && regStr != rflagsStr){
                        preRegStr[2]  = 'S';
                        preWrite     += preRegStr;
                        srcKey       += 'R';
                        opr_count++; //// this is used to help predict operand type x86
                    }
                    /////// flag register is ignore
                    if (isDes && regStr != rflagsStr){
                        preRegStr[2]  = 'D';
                        preWrite     += preRegStr;
                        desKey       += 'R';
                        opr_count++; //// this is used to help predict operand type x86
                    }
                ////////////////////////////////////////////////////////
                
            }else if (INS_OperandIsMemory(ins, opIdx)){

                ///////// for memory operand

                REG    baseReg    = INS_OperandMemoryBaseReg  (ins, opIdx);
                REG    indexReg   = INS_OperandMemoryIndexReg (ins, opIdx);
                bool   isLoad     = INS_MemoryOperandIsRead   (ins, memOp);
                bool   isStore    = INS_MemoryOperandIsWritten(ins, memOp);
                UINT32 memRefSize = INS_MemoryOperandSize     (ins, memOp);


                std::string preMemStr;
                //////// WRITE LOAD STORE
                assert(isLoad || isStore);
                preMemStr += "X ";
                preMemStr += "Y ";
                preMemStr += baseReg  ? REG_StringShort(static_cast<REG>(baseReg)) : "-1";
                preMemStr += " ";
                preMemStr += indexReg ? REG_StringShort(static_cast<REG>(indexReg)) : "-1";
                preMemStr += " ";
                preMemStr += std::to_string(memRefSize);
                preMemStr += " ";
                preMemStr += std::to_string(memOp);
                preMemStr += "\n";

                if (isLoad){
                    preMemStr[0] =  'L';
                    preMemStr[2] =  'S';
                    preWrite += preMemStr;
                    srcKey   += 'L';
                    assert(loaded_amt < maxMemOpPerLS);
                    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, 
                                    (AFUNPTR)L_TRACE,
                                    IARG_MEMORYOP_EA, memOp,
                                    IARG_UINT32, loaded_amt,
                                    IARG_END
                                    );
                    loaded_amt++;
                }
                if (isStore){
                    preMemStr[0] = 'S';
                    preMemStr[2] = 'D';
                    preWrite += preMemStr;
                    desKey   += 'S';
                    assert(stored_amt < maxMemOpPerLS);
                    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, 
                                    (AFUNPTR)S_TRACE,
                                    IARG_MEMORYOP_EA, memOp,
                                    IARG_UINT32, stored_amt,
                                    IARG_UINT32, memOp,
                                    IARG_END
                                    );
                    stored_amt++;
                }
                memOp++;
                opr_count++; //// this is used to help predict operand type x86
                ////////////////////////////////////////////////////////
             }else if (INS_OperandIsImmediate(ins, opIdx)){
                 /////////////////// immediate operand
                 std::string preImmStr;
                 preImmStr += "I S ";
                 preImmStr += std::to_string(INS_OperandImmediate(ins, opIdx));
                 preImmStr += '\n';
                 preWrite  += preImmStr;
                 srcKey    += 'I';
                 opr_count++;
             }
    }
    
    }
    //////// WRITE decode key and debug string
    resKey = "N " + INS_Mnemonic(ins) + "$" + srcKey + "$" + desKey + "  " + _instrName;
    preWrite += resKey + "\n";

    
    ////////////////////////// for insert predicated of the end of instruction
    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, 
                            (AFUNPTR)ButtomEachIntr,
                            IARG_UINT32, INSTRID,
                            IARG_CALL_ORDER, 
                            CALL_ORDER_LAST,
                            IARG_END
                            );

    //////// WRITE FETCH INSTRUCTION
    preWrite += "F S";
    preWrite += " ";
    preWrite += std::to_string(INSTRID);
    preWrite += " ";
    preWrite += "0x" + instrAddrHex;
    preWrite += " ";
    preWrite += std::to_string(instrSize);
    preWrite += " ";

    ////// for vector instruction we will add prefix before use
    bool isVec = isVec_256 || isVec_128 || isVec_64;
    if (isVec){
        ///////// add prefix for each size
        if (isVec_256){
            preWrite += "V256_";
        }else if (isVec_128){
            preWrite += "V128_";
        }else if (isVec_64){
            preWrite += "V64_";
        }
        ///////// add pseudo suffix operand size
        if (opr_count == 2){
            preWrite += "MOV";
        }else{
            preWrite += "COMP";
        }
    }else{
        preWrite += INS_Mnemonic(ins);
    }

    preWrite += "\n";
    preWrite += "---------------------------------\n";

    INSTRID++;
    tryFlush(true);

    
}

VOID Fini(INT32 code, VOID* v)
{
    printf("write remain to disk\n");
    *outputFile_instr << preWrite;
    flushRuntimeData();
    preWrite.clear();
    outputFile_instr->close();     
    outputFile_trace->close();
}




KNOB<std::string> outputinstrFileKnob(KNOB_MODE_WRITEONCE, "pintool",
    "i", "/tmp/instr.txt", "output for instruction model");

KNOB<std::string> outputdataFileKnob(KNOB_MODE_WRITEONCE, "pintool",
    "d", "/tmp/runtimeTrace.txt", "output for runtime tracing");

KNOB<std::string> outputdebugtraceKnob(KNOB_MODE_WRITEONCE, "pintool",
    "db", "/tmp/runtimeTrace.dbg", "output for runtime debugging");

int main(int argc, char* argv[])
{
    // Initialize the Pin tool

    PIN_Init(argc, argv);
    //preWrite.reserve(4000001000);

    ///////////////////////////////////////////////////
    // prewrite for run time tracing file
    preWriteRt         = new RT_OBJ[maxRtTracing];
    bufferInitialize(0);
    ///////////////////////////////////////////////////
    outputFile_instr   = new std::ofstream(outputinstrFileKnob .Value()),
    outputFile_trace   = new std::ofstream(outputdataFileKnob  .Value()),
    outputFile_traceDb = new std::ofstream(outputdebugtraceKnob.Value());
    ///////////////////////////////////////////////////
    // prewrite for static tracing file
    preWrite.reserve(2000001000);
    ///////////////////////////////////////////////////
    // Register the Instruction function to be called for every instruction
    INS_AddInstrumentFunction(Instruction, nullptr);
    //// flush static trace
    //tryFlush(true);
    //outputFile_instr->close();

    PIN_AddFiniFunction(Fini, 0);
    // Start the program and never return
    PIN_StartProgram();

    return 0;
}