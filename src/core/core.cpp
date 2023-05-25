//
// Created by tanawin on 2/3/2566.
//

#include "core.h"


CORE::CORE(MEM_MNG* _memMng, DECODER_BASE* _decBase, EXEC_UNIT_RES* _execUnit_info):
amountThread(0),
memMng(_memMng),
decoder(_decBase),
execUnit_info(_execUnit_info)
{
    assert(_memMng  != nullptr);
    assert(_decBase != nullptr);
    assert(_execUnit_info != nullptr);
}


void
CORE::addWorker(TRACE_TOOL_FRONT_END* _trace_tool,
                RESULT_FRONT_END*     _result_frontEnd,
                int                   _obsSize
                     ){

    /////// for now we assume that each trace worker have their own thread model
    //////////// In the future, we might support shared thread model to optimize the performance

    ////////// build uop window and thread model for tracer and traceTool
    UOP_WINDOW*   uopWindow = new UOP_WINDOW(_obsSize, execUnit_info);
    THREAD_MODEL* tmd       = new THREAD_MODEL();
    ///////// tracer
    TRACER_BASE* tracer = new TRACER_BASE(amountThread,
                                          _result_frontEnd,
                                          uopWindow,
                                          decoder,
                                          memMng,
                                          tmd
                                          );
    ///////// traceTool
    _trace_tool->setListenners(tmd, tracer);
    ///////// add Tracer
    traceWorkers.insert({amountThread, tracer});
    traceTools  .insert({amountThread, _trace_tool});
    amountThread++;
}


void
CORE::start(bool parallel){

    if (parallel) {
        //////TODO make it run in parallel
        assert(false);
    }else{
        for (auto& traceTool: traceTools){
            assert(traceTool.second != nullptr);
            traceTool.second->start();
        }
    }
}