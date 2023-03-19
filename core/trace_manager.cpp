//
// Created by tanawin on 2/3/2566.
//

#include "trace_manager.h"

#include "core.h"

TRACE_MANAGER::TRACE_MANAGER(
        THREAD_ID             _tid,
        TRACE_TOOL_FRONT_END* _traceTool,
        RESULT_FRONT_END*     _resFed,
        MEM_MNG*              _memMng,
        int                   _obsSize
):
        traceTool(_traceTool),
        resFed(_resFed),
        memMng(_memMng),
        uopWindow(new UOP_WINDOW(_obsSize)),
        threadModel(new THREAD_MODEL())

{
    tracer = new TRACER_BASE(_tid,this,resFed,
                             uopWindow, memMng, threadModel);
    ///////////////
    traceTool->setListenners(threadModel, tracer);
    assert(traceTool != nullptr);
    assert(resFed    != nullptr);
    assert(memMng    != nullptr);
}

TRACE_MANAGER::~TRACE_MANAGER() {
    ////////// we only delete trace worker component
    delete uopWindow;
    delete threadModel;
    delete tracer;
    ////// other component let user delete by himself
}

void TRACE_MANAGER::start() {
    traceTool->start();
}
