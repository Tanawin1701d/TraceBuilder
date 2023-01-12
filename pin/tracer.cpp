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


//FILE* trace;
static std::ofstream* outputFile_instr;
static std::ofstream* outputFile_trace;

static std::string preWrite;
static std::string preWriteT;
UINT32 INSTRID = 0;

int pagemapFile;




VOID tryFlush(){
    if (preWrite.size() >= 4000000000){
        *outputFile_instr << preWrite;
        preWrite.clear();
    }
}

VOID tryFlushT(){
    if (preWriteT.size() >= 4000000000){
        *outputFile_trace << preWriteT;
        preWriteT.clear();
    }
}



VOID LD_TRACE(ADDRINT addr, BOOL isLoad, UINT32 memop){
    preWriteT += isLoad ? "L " : "S ";

    char buffer[32];
    sprintf(buffer, "%lx", addr);
    std::string ldAddrHex(buffer);

    preWriteT += "0x";
    preWriteT += ldAddrHex;
    preWriteT += " ";
    preWriteT += std::to_string(memop);
    preWriteT += "\n";
}

VOID ButtomEachIntr(
                char* instr_id
                ){

    //fprintf(trace, "---------- %s -----\n", str);
    preWriteT += "F ";
    preWriteT += instr_id;
    preWriteT += "\n";
    tryFlushT();

}

// The Instruction function is called for every instruction
VOID Instruction(INS ins, VOID* v)
{

    // instruction id 
    std::string _instrIdRaw = std::to_string(INSTRID);
    char* instrIdStr = new char[256];
    std::copy(_instrIdRaw.begin(), _instrIdRaw.end(), instrIdStr);
    instrIdStr[_instrIdRaw.length()] = '\0';
    
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

        INS_InsertPredicatedCall(ins, IPOINT_BEFORE, 
                            (AFUNPTR)LD_TRACE,
                            IARG_MEMORYOP_EA, memOp,
                            IARG_BOOL, isLoad,
                            IARG_UINT32, memOp,
                            IARG_END
                            );
    }
    
    
    ////////////////////////// for insert predicated of the end of instruction
    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, 
                            (AFUNPTR)ButtomEachIntr,
                            IARG_PTR, (void*)instrIdStr,
                            IARG_CALL_ORDER, 
                            CALL_ORDER_LAST,
                            IARG_END
                            );

    preWrite += "F ";
    preWrite += "0x" + instrAddrHex;
    preWrite += " ";
    preWrite += std::to_string(instrSize);
    preWrite += " ";
    preWrite += _instrIdRaw;
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
    *outputFile_trace << preWriteT;
    preWrite.clear();
    preWriteT.clear();
    outputFile_instr->close();     
    outputFile_trace->close();
}

KNOB<std::string> outputinstrFileKnob(KNOB_MODE_WRITEONCE, "pintool",
    "i", "/tmp/instr.txt", "output for instruction model");

KNOB<std::string> outputdataFileKnob(KNOB_MODE_WRITEONCE, "pintool",
    "d", "/tmp/runtimeTrace.txt", "output for runtime tracing");



int main(int argc, char* argv[])
{
    // Initialize the Pin tool
    PIN_Init(argc, argv);

    //preWrite.reserve(4000001000);

    outputFile_instr = new std::ofstream(outputinstrFileKnob.Value()),
    outputFile_trace = new std::ofstream(outputdataFileKnob.Value()),
    preWrite.reserve(2000001000);
    preWriteT.reserve(4000001000);

    // Register the Instruction function to be called for every instruction
    INS_AddInstrumentFunction(Instruction, nullptr);
    PIN_AddFiniFunction(Fini, 0);
    // Start the program and never return
    PIN_StartProgram();

    return 0;
}