//
// Created by tanawin on 2/3/2566.
//

#include "core.h"


CORE::CORE(MEM_MNG* _memMng):
memMng(_memMng),
last_tid(0)
{
    assert(_memMng != nullptr);
}


void
CORE::addTraceWorker(TRACE_TOOL_FRONT_END* _trace_tool,
                     RESULT_FRONT_END*     _result_frontEnd,
                     int                   _obsSize
                     ){

    traceWorkers.emplace_back(
            last_tid++,
            _trace_tool,
            _result_frontEnd,
            memMng,
            _obsSize
            );
}


void
CORE::start(bool parallel){

    if (parallel) {
        //////TODO make it run
        assert(false);
    }else{
        for (auto& worker: traceWorkers){
            worker.start();
        }
    }
}