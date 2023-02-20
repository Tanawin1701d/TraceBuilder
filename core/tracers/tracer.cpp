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
    //// copy the static resource from dynTraceData to convertedDynData
    convertedDynData cvtDynData;
    cvtDynData.fetchId = dyndata.rawData.fetchId;
    for (uint32_t arrIdx = 0; arrIdx < maxMemOpPerLS; arrIdx++){
        cvtDynData.loadMemOpNum[arrIdx] = dyndata.rawData.loadMemOpNum[arrIdx];
        cvtDynData.storeMemOpNum[arrIdx] = dyndata.rawData.storeMemOpNum[arrIdx];
    }

    
    //// occupy resource


    //// assign runtime trace value to runtime instruction operand
    //////////////// analysis runtime information then decode
    auto rtInstr ;

    //// decode current runtime instruction tot microop
    ///////// less vector index means it should execute first(dead lock prevention)
    auto uops = decoder->decode(rtInstr);
    //// we assume that decoder already assign dependency to intra micro-op group for each instruciton
    //// connect inter microop to assign dependency
    for (auto uopPtr: uops){
        ///// TODO we might execute after assign dependency
        //////// assign dependency
        uopWindow->depAssign(uopPtr);
    }

    //// TODO sent microop to result front end

}