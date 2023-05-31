//
// Created by tanawin on 25/3/2566.
//

#include "simplePinGem.h"
#include "core/tracerFrontEnd/legacyPin/lagacy_pin.h"
#include "core/resultFrontEnd/legacyGem5/resultFed_gemLagacy.h"
#include "core/core.h"
#include "models/arch/X86/X86_dec.h"


SIMPLE_PIN_GEM::SIMPLE_PIN_GEM(const std::string _inputPinFile_instr,
                               const std::string _inputPinFile_data,
                               const std::string _outProtoFile_instr,
                               const std::string _outProtoFile_data):
inputPinFile_instr(_inputPinFile_instr),
inputPinFile_data(_inputPinFile_data),
outProtoFile_instr(_outProtoFile_instr),
outProtoFile_data(_outProtoFile_data)
{}


void
SIMPLE_PIN_GEM::start(){

    ///////// front end from pintool and gem5

    LAGACY_PIN_TRACER*           pinTracer   = new LAGACY_PIN_TRACER(inputPinFile_instr, inputPinFile_data);
    RESULT_FRONT_END_GEM_LAGACY* gemFrontend = new RESULT_FRONT_END_GEM_LAGACY (outProtoFile_data, outProtoFile_instr, 1000000000, 100);

    //////// mem manager && decoder
    ADDR           memSize       = ((ADDR)1) << (4 + 30);
    MEM_MNG*       memMng        = new MEM_MNG(12, 6, memSize, 0);
    X86_DECODER*   x86Dec        = new X86_DECODER();
    EXEC_UNIT_RES* execUnit_info = new EXEC_UNIT_RES(98,99);
    execUnit_info->setMaxAvailable(1,6); ///"INT_SIM_ALU"
    execUnit_info->setMaxAvailable(2,2); ///"INT_MUL_DIV_ALU"
    execUnit_info->setMaxAvailable(3,4); ///"FLOAT_SIM_ALU"
    execUnit_info->setMaxAvailable(4,2); ///"FLOAT_MUL_DIV_ALU"
    execUnit_info->setMaxAvailable(5,1); ///"SIM128_ALU"
    execUnit_info->setMaxAvailable(6,4); ///"MOV_MEM_LD"
    execUnit_info->setLatencyCycle(1,1); ///"INT_SIM_ALU"
    execUnit_info->setLatencyCycle(2,3); ///"INT_MUL_DIV_ALU"
    execUnit_info->setLatencyCycle(3,2); ///"FLOAT_SIM_ALU"
    execUnit_info->setLatencyCycle(4,4); ///"FLOAT_MUL_DIV_ALU"
    execUnit_info->setLatencyCycle(5,1); ///"SIM128_ALU"
    execUnit_info->setLatencyCycle(6,1); ///"MOV_MEM_LD"
    gemFrontend->setExecUnit_info(execUnit_info);
    //////// core start
    CORE*  traceCore = new CORE(memMng, x86Dec, execUnit_info);
    traceCore->addWorker(pinTracer, gemFrontend, 100);
    ///////////////////////////////////////////////////////////////////////////////
    //////// start simulation

    traceCore->start(false);

    delete pinTracer;
    delete gemFrontend;
    delete memMng;
    delete x86Dec;

}