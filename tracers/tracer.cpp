//
// Created by tanawin on 24/12/2565.
//

#include "tracer.h"


TRACER_BASE::TRACER_BASE(THREAD_ID      _tid,
                         TRACE_MANAGER* _traceMng,
                         UOP_WINDOW *   _uopWindow,
                         MEM_MNG *      _memMng,
                         DECODER *      _decoder,
                         THREAD_MODEL*  _threadModel) :
tid         (_tid),
traceMng    (_traceMng),
uopWindow   (_uopWindow),
memMng      (_memMng),
decoder     (_decoder),
threadModel (_threadModel){

    assert( _traceMng    != nullptr);
    assert( _uopWindow   != nullptr);
    assert( _memMng      != nullptr);
    assert( _decoder     != nullptr);
    assert( _threadModel != nullptr);


}

void TRACER_BASE::onGetDynTraceValue(dynTraceData dyndata) {

    //// assign runtime trace value to runtime instruction operand
    auto rtInstr =
            threadModel->getRtInstrfromRtTrace(dyndata.rawData);
    //// decode current runtime instruction tot microop
    ///////// less vector index means it should execute first(dead lock prevention)
    auto uops = decoder->decode(rtInstr);
    //// connect inter microop to dependency
    for (auto uopPtr: uops){
        ///// TODO we might execute after assign dependency to occupy some resource

        //////// assign dependency
        uopWindow->depAssign(uopPtr);
    }

    //// TODO sent microop to result front end

}