#include "pin.H"
#include <iostream>
#include "writer/writer.h"
#include "analyser/main_instr.h"

KNOB<std::string> outputinstrFileKnob(KNOB_MODE_WRITEONCE, "pintool",
    "i", "/tmp/instr.txt", "output for instruction model");

KNOB<std::string> outputdataFileKnob(KNOB_MODE_WRITEONCE, "pintool",
    "d", "/tmp/runtimeTrace.txt", "output for runtime tracing");

KNOB<std::string> outputdebugtraceKnob(KNOB_MODE_WRITEONCE, "pintool",
    "db", "/tmp/runtimeTrace.dbg", "output for runtime debugging");

VOID Fini(INT32 code, VOID* v)
{
    printf("write remain to disk\n");
    finzStaticTraceFile();
    finzDynamicTraceFile();
}

int main(int argc, char* argv[])
{
    // Initialize the Pin tool
    PIN_Init(argc, argv);
    /** initialize recorder*/
    initStaticTraceFile (outputinstrFileKnob.Value());
    initDynamicTraceFile(outputdataFileKnob .Value());
    // Register the Instruction function to be called for every instruction
    INS_AddInstrumentFunction(MAIN_instrument, nullptr);
    // register when last instruction is executed
    PIN_AddFiniFunction(Fini, 0);
    // Start the program and never return
    PIN_StartProgram();

    return 0;
}