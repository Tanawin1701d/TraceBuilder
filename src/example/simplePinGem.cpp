//
// Created by tanawin on 25/3/2566.
//

#include "simplePinGem.h"
#include "core/tracerFrontEnd/legacyPin/lagacy_pin.h"
#include "core/resultFrontEnd/legacyGem5/resultFed_gemLagacy.h"
#include "core/core.h"
#include "models/arch/x86/build/decoder/x86_dec.h"


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
    RESULT_FRONT_END_GEM_LAGACY* gemFrontend = new RESULT_FRONT_END_GEM_LAGACY (outProtoFile_data, outProtoFile_instr);

    //////// mem manager && decoder
    ADDR memSize        = ((ADDR)1) << (4 + 30);
    MEM_MNG* memMng     = new MEM_MNG(12, 6, memSize, 0);
    DECODER_X86* x86Dec = new DECODER_X86();

    //////// core start
    CORE*  traceCore = new CORE(memMng, x86Dec);
    traceCore->addWorker(pinTracer, gemFrontend, 100);
    ///////////////////////////////////////////////////////////////////////////////
    //////// start simulation

    traceCore->start(false);

    delete pinTracer;
    delete gemFrontend;
    delete memMng;
    delete x86Dec;

}
