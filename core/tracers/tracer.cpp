//
// Created by tanawin on 24/12/2565.
//

#include "tracer.h"


TRACER_BASE::TRACER_BASE(THREAD_ID          _tid,
                         TRACE_MANAGER*     _traceMng,
                         RESULT_FRONT_END*  _resFed,
                         UOP_WINDOW*        _uopWindow,
                         MEM_MNG*           _memMng,
                         THREAD_MODEL*      _threadModel) :
tid         (_tid),
traceMng    (_traceMng),
resFed      (_resFed),
uopWindow   (_uopWindow),
memMng      (_memMng),
threadModel (_threadModel){

    assert( _traceMng    != nullptr);
    assert( _resFed      != nullptr);
    assert( _uopWindow   != nullptr);
    assert( _memMng      != nullptr);
    assert( _threadModel != nullptr);

}

void TRACER_BASE::onGetDynTraceValue(dynTraceData dyndata) {

    //// get runtime instruction from cache xor base
    RT_INSTR_ID curId = (RT_INSTR_ID)dyndata.rawData.fetchId;

    //// retrive from cache or thread model and update to cache
    auto finder = rt_instr_cache.find(dyndata.rawData.fetchId);
    if ( finder == rt_instr_cache.end()){
        finder  =  rt_instr_cache.insert({curId, threadModel->getInstrTemplate(curId)}).first;
    }
    RT_INSTR* cur_rt_instr = (*finder).second;

    /////**********************************************************************************************
    ///// please note that runtime instruction is act as an individual instruction for each instruction
    /// but, for now, we use it as a shared class due to optimization need
    ///// *********************************************************************************************


    //// convert the static resource from dynTraceData to convertedDynData with resource occupy
    convertedDynData cvtDynData{};
    //// fill fetch id
    cvtDynData.fetchId = dyndata.rawData.fetchId;
    //// copy and occupy resouce
    for (uint32_t arrIdx = 0; arrIdx < maxMemOpPerLS; arrIdx++){
        cvtDynData.loadMemOpNum [arrIdx] = dyndata.rawData.loadMemOpNum[arrIdx];
        cvtDynData.storeMemOpNum[arrIdx] = dyndata.rawData.storeMemOpNum[arrIdx];
        //// occupy resource
        //// for now we assume that  each load store operand only use 1 consecutive address
        if (dyndata.rawData.loadMemOpNum[arrIdx] != DUMMY_MEM_OP_NUM) {
            vector<ADAS> memmaped;
            ADDR size = cur_rt_instr->getSrcLdOperands()[dyndata.rawData.loadMemOpNum[arrIdx]].getSize();
            memMng->v2pConvert(dyndata.rawData.loadAddr[arrIdx], (int)size, memmaped);
            cvtDynData.phyLoadAddr[arrIdx] = memmaped[0].addr;
        }
        if (dyndata.rawData.storeMemOpNum[arrIdx] != DUMMY_MEM_OP_NUM) {
            vector<ADAS> memmaped;
            ADDR size = cur_rt_instr->getDesStOperands()[dyndata.rawData.storeMemOpNum[arrIdx]].getSize();
            memMng->v2pConvert(dyndata.rawData.storeAddr[arrIdx], (int)size, memmaped);
            cvtDynData.phyStoreAddr[arrIdx] = memmaped[0].addr;
        }
    }
    //// fill data to runtime instruction
    cur_rt_instr->fillDynData(cvtDynData);
    //// generate uops
    cur_rt_instr->genUOPS(inflight_uops);
    //// connect dependency
    for (auto uop : inflight_uops){
        uopWindow->depAssign(uop); /// we dont have to check uop dep with in same runtime instruction because macrop will handle it
    }
    //// add to uops window
    for (auto uop : inflight_uops){
        uopWindow->addUop(uop);
    }
    //// invoke result front-end
    resFed->onGetUopsResult(inflight_uops);
    ///// clear inflight uops denote that the mop is not currently deleted. it  clear that pointer in vector
    inflight_uops.clear();
}