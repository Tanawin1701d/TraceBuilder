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

//#pragma pack(push, 1)
struct RT_OBJ{
    uint64_t loadAddr[3];
    uint64_t storeAddr[3];
    uint32_t fetchId;
    uint8_t  loadMemOpNum[3];
    uint8_t  storeMemOpNum[3];
};
//#pragma pack(pop)

///// these pragma is derived from 
//https://stackoverflow.com/questions/32109646/how-to-write-a-struct-to-file-in-c-and-read-the-file

const UINT32 maxRtTracing =  400000000; 
const UINT32 maxMemOpPerLS = 3;

//FILE* trace;
static std::ofstream* outputFile_instr;
static std::ofstream* outputFile_trace;
static std::ofstream* outputFile_traceDb;

static std::string   preWrite;
static std::string   preWriteRuntimeDebg;
struct RT_OBJ* preWriteRt; /// 400 M times 52 bytes
UINT32 preWriteRt_idx = 0;
UINT32 INSTRID        = 0;

VOID tryFlush(){
    if (preWrite.size() >= 4000000000){
        *outputFile_instr << preWrite;
        preWrite.clear();
    }
}

VOID flushDb(std::string dayta){
    *outputFile_traceDb << dayta;
}


std::string getDebugOutcome(RT_OBJ example){
    std::string prePrint;
    for (int i = 0; i < 3; i++){
        prePrint  += "L " + std::to_string(example.loadAddr[i])  + "  memop addr "
                  + std::to_string(example.loadMemOpNum[i]) 
                  + "\n";
    }
    for (int i = 0; i < 3; i++){
        prePrint  += "S " + std::to_string(example.storeAddr[i]) + " memop addr " 
                  + std::to_string(example.loadMemOpNum[i])        
                  + "\n";       
    }
    prePrint  += "F " + std::to_string(example.fetchId) + "\n";
    return prePrint;
}

VOID flushRuntimeData(){
    if (preWriteRt_idx){
        outputFile_trace->write((char*)preWriteRt, sizeof(RT_OBJ)*preWriteRt_idx);
        ////// this is used for debug
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

// inline void bufferInitialize(UINT32 pwIdx){
//         preWriteRt[pwIdx].loadIdx    = 0;
//         preWriteRt[pwIdx].storeIdx   = 0;
// }

VOID ButtomEachIntr(
        UINT32 fetchId
                ){
    preWriteRt[preWriteRt_idx].fetchId = fetchId;
    //// we print debug before debug
    preWriteRuntimeDebg += getDebugOutcome(preWriteRt[preWriteRt_idx]);
    flushDb(preWriteRuntimeDebg);
    preWriteRuntimeDebg.clear();
    ////////////////////////////////
    preWriteRt_idx++;
    if ( preWriteRt_idx >= maxRtTracing){
        flushRuntimeData();
        //reset index of the buffer
        preWriteRt_idx = 0;
    }
    //bufferInitialize(preWriteRt_idx);
     /// initilize for next instruction
    /// this is crucial due to inconsistent state exist

}

// The Instruction function is called for every instruction
VOID Instruction(INS ins, VOID* v)
{
    
    //instruction
    std::string _instrName   = INS_Disassemble(ins);
    ADDRINT instrAddr = INS_Address(ins);
    UINT32  instrSize = INS_Size(ins);

    char buffer[32];
    sprintf(buffer, "%lx", instrAddr);
    std::string instrAddrHex(buffer);



    ///////////////////////// for compute instruction
    UINT32 numOperands = INS_OperandCount(ins);
    for (UINT32 opIdx = 0; opIdx < numOperands; opIdx++){
        if (INS_OperandIsReg(ins, opIdx)){
                bool isSrc = INS_OperandRead(ins, opIdx);
                bool isDes = INS_OperandWritten(ins, opIdx);
                REG reg = INS_OperandReg(ins, opIdx);
                //if (reg != REG_RFLAGS)
                assert(!INS_OperandIsMemory(ins, opIdx));
                assert(isSrc || isDes);
                preWrite += "C ";
                if (isSrc)
                    preWrite += "S"; // source register
                if (isDes)
                    preWrite += "D"; // des register
                preWrite += " ";
                preWrite += reg ? REG_StringShort(static_cast<REG>(reg)) : "-1";
                preWrite += "\n";
        }
    }

    ///////////////////////// for load store instruction
    UINT32 memOperands = INS_MemoryOperandCount(ins);

    UINT32 loaded_amt = 0;
    UINT32 stored_amt = 0;

    for (UINT32 memOp = 0; memOp < memOperands; memOp++){
        UINT32 opIdxMtc   = INS_MemoryOperandIndexToOperandIndex(ins, memOp);
        REG    baseReg    = INS_OperandMemoryBaseReg (ins, opIdxMtc);
        REG    indexReg   = INS_OperandMemoryIndexReg(ins, opIdxMtc);
        bool   isLoad     = INS_MemoryOperandIsRead (ins, memOp);
        bool   isStore    = INS_MemoryOperandIsWritten(ins, memOp);
        UINT32 memRefSize = INS_MemoryOperandSize(ins, memOp);

        ////// for instruction template
        if (isLoad)
            preWrite += "L";
        if (isStore)
            preWrite += "S";
        assert(isLoad || isStore);
        preWrite += " ";
        preWrite += baseReg  ? REG_StringShort(static_cast<REG>(baseReg)) : "-1";
        preWrite += " ";
        preWrite += indexReg ? REG_StringShort(static_cast<REG>(indexReg)) : "-1";
        preWrite += " ";
        preWrite += std::to_string(memRefSize);
        preWrite += " ";
        preWrite += std::to_string(memOp);
        preWrite += "\n";
        /// there is memory operand that act like load and store at a time
        /// so we need to add all to the serializer
        if (isLoad){
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
        
    }
    
    
    ////////////////////////// for insert predicated of the end of instruction
    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, 
                            (AFUNPTR)ButtomEachIntr,
                            IARG_UINT32, INSTRID,
                            IARG_CALL_ORDER, 
                            CALL_ORDER_LAST,
                            IARG_END
                            );

    preWrite += "F ";
    preWrite += "0x" + instrAddrHex;
    preWrite += " ";
    preWrite += std::to_string(instrSize);
    preWrite += " ";
    preWrite += std::to_string(INSTRID);
    preWrite += " ";
    preWrite += _instrName;
    preWrite += "\n";

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
    //bufferInitialize(0);
    PIN_Init(argc, argv);
    //preWrite.reserve(4000001000);
    // prewrite for run time tracing file
    preWriteRt         = new RT_OBJ[maxRtTracing];
    outputFile_instr   = new std::ofstream(outputinstrFileKnob.Value()),
    outputFile_trace   = new std::ofstream(outputdataFileKnob .Value()),
    outputFile_traceDb = new std::ofstream(outputdebugtraceKnob.Value());
    preWrite.reserve(2000001000);

    // Register the Instruction function to be called for every instruction
    INS_AddInstrumentFunction(Instruction, nullptr);
    PIN_AddFiniFunction(Fini, 0);
    // Start the program and never return
    PIN_StartProgram();

    return 0;
}