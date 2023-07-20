//
// Created by tanawin on 9/6/2566.
//
#include<pybind11/pybind11.h>

/** trace front end*/
#include"core/core.h"
#include"core/tracerFrontEnd/traceToolFed.h"
#include"core/tracerFrontEnd/legacyPin/lagacy_pin.h"

/** result front end*/
#include"core/resultFrontEnd/resultFed.h"
#include"core/resultFrontEnd/legacyGem5/resultFed_gemLagacy.h"
#include "core/resultFrontEnd/tbdGem5ISA/tbdGem5ISA.h"

/** model*/
#include"models/res_model/execUnit/execUnit.h"
#include"models/res_model/memMng/MemMng.h"
#include"models/uop_model/agent/mop_agent.h"
#include"models/uop_model/agent/uop_agent.h"
#include"models/inst_model/operand.h"
#include"models/inst_model/rt_instr.h"
#include"models/thread_model/thread_model.h"
#include"models/uop_model/uop_base.h"

/** statPool*/
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
    core::BIND_RESULT_FRONT_END_TBDGEMISA(m);
    /////// model
    model::BIND_EXEC_UNIT_RES(m);
    model::BIND_MEM_MNG(m);

    model::BIND_MOP_AGENT(m);
    model::BIND_UOP_AGENT(m);

    model::BIND_OPERAND(m);
    model::BIND_RT_INSTR(m);

    model::BIND_THREAD_MODEL(m);

    model::BIND_UOP_TYPE(m);






    ////// stat;
    mystat::BIND_STAT(m);
}