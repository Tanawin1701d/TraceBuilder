//
// Created by tanawin on 14/2/2566.
//

#include "traceToolFed.h"
#include "staticTraceVar.h"
#include "../../components/thread_model/thread_model.h"

TRACE_TOOL_FRONT_END::TRACE_TOOL_FRONT_END(){}

void
TRACE_TOOL_FRONT_END::setListenners(THREAD_MODEL* _tmd,
                                    TRACER_BASE* _tracer){
    tmd = _tmd;
    tracer = _tracer;

    assert(tmd != nullptr);
    assert(tracer != nullptr);
}

