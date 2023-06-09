//
// Created by tanawin on 9/6/2566.
//
#include<pybind11/pybind11.h>
#include"core/core.h"
#include"core/tracerFrontEnd/traceToolFed.h"
#include"core/tracerFrontEnd/legacyPin/lagacy_pin.h"
#include"core/resultFrontEnd/resultFed.h"
#include"core/resultFrontEnd/legacyGem5/resultFed_gemLagacy.h"
#include"models/res_model/execUnit/execUnit.h"
#include"models/res_model/memMng/MemMng.h"
#include"stat/statPool.h"


namespace py = pybind11;
namespace model = traceBuilder::model;
namespace core  = traceBuilder::core;
namespace mystat  = traceBuilder::stat;

PYBIND11_MODULE( traceBuilder, m){
    model::BIND_CORE(m);
    /////// core trace tool
    core::BIND_TRACE_TOOL_FRONT_END(m);
    core::BIND_LAGACY_PIN_TRACER(m);
    /////// core result tool
    core::BIND_RESULT_FRONT_END(m);
    core::BIND_RESULT_FRONT_END_GEM_LAGACY(m);
    /////// model
    model::BIND_EXEC_UNIT_RES(m);
    model::BIND_MEM_MNG(m);
    ////// stat;
    mystat::BIND_STAT(m);
}