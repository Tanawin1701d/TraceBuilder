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

#pragma pack(push, 1)
struct RT_OBJ{
    uint64_t loadAddr     [maxMemOpPerLS];
    uint64_t storeAddr    [maxMemOpPerLS];
    uint32_t fetchId;
    uint8_t  loadMemOpNum [maxMemOpPerLS];
    uint8_t  storeMemOpNum[maxMemOpPerLS];
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
    if (preWrite.size() >= 4000000000 || forceFlush){
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
    for (int i = 0; i < 2; i++) {
        ss << (int)obj.loadMemOpNum[i] << ", ";
    }
    ss.seekp(-2, ss.cur);
    ss << "], storeMemOpNum: [";
    for (int i = 0; i < 2; i++) {
        ss << (int)obj.storeMemOpNum[i] << ", ";
    }
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
        preWriteRt[initIdx].loadMemOpNum [i] = UNUSED_MEMOP;
        preWriteRt[initIdx].storeMemOpNum[i] = UNUSED_MEMOP;
    }

}

VOID L_TRACE(ADDRINT addr, UINT32 lsFieldId, UINT32 memop){
    preWriteRt[preWriteRt_idx].loadAddr    [lsFieldId] = addr;
    preWriteRt[preWriteRt_idx].loadMemOpNum[lsFieldId] = (uint8_t)memop;
}

VOID S_TRACE(ADDRINT addr, UINT32 lsFieldId, UINT32 memop){
    preWriteRt[preWriteRt_idx].storeAddr    [lsFieldId] = addr;     // update address;
    preWriteRt[preWriteRt_idx].storeMemOpNum[lsFieldId] = (uint8_t)memop; //update memory operand number
}

VOID ButtomEachIntr(
        UINT32 fetchId
                ){
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

    //decode string varible
    std::string srcKey;
    std::string desKey;
    std::string resKey;

    // rflags register
    std::string rflagsStr = "rflags";

    ///////////////////////// for compute instruction
    UINT32 numOperands = INS_OperandCount(ins);



    for (UINT32 opIdx = 0; opIdx < numOperands; opIdx++){
        if (INS_OperandIsReg(ins, opIdx)){
                bool isSrc = INS_OperandRead   (ins, opIdx);
                bool isDes = INS_OperandWritten(ins, opIdx);
                REG  reg   = INS_OperandReg    (ins, opIdx);
                //if (reg != REG_RFLAGS)
                assert(!INS_OperandIsMemory(ins, opIdx));
                assert(isSrc || isDes);
                
                std::string preRegStr;


                preRegStr += "R "; // source register
                preRegStr += "X "; // source register
                preRegStr += reg ? REG_StringShort(static_cast<REG>(reg)) : "-1";
                preRegStr += "\n";

                std::string regStr = REG_StringShort(static_cast<REG>(reg));

                if (isSrc && regStr != rflagsStr){
                    preRegStr[2]  = 'S';
                    preWrite     += preRegStr;
                    srcKey       += 'R';
                }
       
                if (isDes && regStr != rflagsStr){
                    preRegStr[2]  = 'D';
                    preWrite     += preRegStr;
                    desKey       += 'R';
                }
                
        }else if (INS_OperandIsMemory(ins, opIdx)){

            ///////// for memory operand

            REG    baseReg    = INS_OperandMemoryBaseReg  (ins, opIdx);
            REG    indexReg   = INS_OperandMemoryIndexReg (ins, opIdx);
            bool   isLoad     = INS_MemoryOperandIsRead   (ins, memOp);
            bool   isStore    = INS_MemoryOperandIsWritten(ins, memOp);
            UINT32 memRefSize = INS_MemoryOperandSize     (ins, memOp);


            std::string preMemStr;
            
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
                                IARG_UINT32, memOp,
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
        }else if (INS_OperandIsImmediate(ins, opIdx)){
            std::string preImmStr;
            preImmStr += "I S ";
            preImmStr += std::to_string(INS_OperandImmediate(ins, opIdx));
            preImmStr += '\n';
            preWrite  += preImmStr;
            srcKey    += 'I';
        }
    }
    
    //////// handle decode key
    resKey = "N " + INS_Mnemonic(ins) + "$" + srcKey + "$" + desKey;
    preWrite += resKey + "\n";

    
    ////////////////////////// for insert predicated of the end of instruction
    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, 
                            (AFUNPTR)ButtomEachIntr,
                            IARG_UINT32, INSTRID,
                            IARG_CALL_ORDER, 
                            CALL_ORDER_LAST,
                            IARG_END
                            );

    preWrite += "F S";
    preWrite += " ";
    preWrite += std::to_string(INSTRID);
    preWrite += " ";
    preWrite += "0x" + instrAddrHex;
    preWrite += " ";
    preWrite += std::to_string(instrSize);
    preWrite += " ";
    preWrite += _instrName;
    preWrite += "\n";
    preWrite += "---------------------------------\n";

    INSTRID++;
    tryFlush();

    
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
    tryFlush(true);

    PIN_AddFiniFunction(Fini, 0);
    // Start the program and never return
    PIN_StartProgram();

    return 0;
}