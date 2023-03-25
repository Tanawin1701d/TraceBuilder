//
// Created by tanawin on 24/12/2565.
//

#include "tracer.h"

TRACER_BASE::TRACER_BASE(THREAD_ID          _tid,
                         RESULT_FRONT_END*  _resFed,
                         UOP_WINDOW*        _uopWindow,
                         DECODER_BASE*      _decoder,
                         MEM_MNG*           _memMng,
                         THREAD_MODEL*      _threadModel) :
tid         (_tid),
resFed      (_resFed),
uopWindow   (_uopWindow),
decoder     (_decoder),
memMng      (_memMng),
threadModel (_threadModel),
nextMopId   (0)
{

    assert( _decoder     != nullptr);
    assert( _resFed      != nullptr);
    assert( _uopWindow   != nullptr);
    assert( _memMng      != nullptr);
    assert( _threadModel != nullptr);

}


void
TRACER_BASE::cvtLoadOrStoreToPhyAddr(RT_OBJ&           rt_obj,
                                     RT_INSTR&         rt_instr,
                                     CVT_RT_OBJ& results,
                                     bool              isLoad) { /// else is store

    /////// for load
    int idx = 0;
    int opNum;
    ////// from rt_instr
    auto& ldOprs = rt_instr.getSrcLdOperands();
    auto& stOprs = rt_instr.getDesStOperands();

    ///// from rt_obj which from traced front-end
    uint64_t* dynVirAddr = isLoad ? rt_obj.loadAddr     : rt_obj.storeAddr;
    uint8_t*  dynOpNums  = isLoad ? rt_obj.loadMemOpNum : rt_obj.storeMemOpNum;

    ///// to result
    uint64_t* resPhyAddrs   = isLoad ? results.phyLoadAddr : results.phyStoreAddr;
    uint8_t*  resopNums     = isLoad ? results.loadMemOpNum: results.storeMemOpNum;

    while(idx < maxMemOpPerLS){
        opNum = dynOpNums[idx];
        if (opNum == DUMMY_MEM_OP_NUM){
            break;
        }

        //// get data from rt_obj and rt_instr
        uint64_t addr = dynVirAddr[idx];
        uint64_t size = isLoad ? ldOprs[opNum].getSize() : stOprs[opNum].getSize();

        //// convert virtual address to physical address
        vector<ADAS> addrCvtResults; /// TODO fornow wew assume 1 operand per 1 ADAS
        memMng->v2pConvert(addr, (int)size, addrCvtResults);
        assert(!addrCvtResults.empty());
        //// fill the converted result
        resPhyAddrs[idx]  = addrCvtResults[0].addr;
        resopNums  [idx]  = opNum;

        //// iterate to next
        idx++;
    }

}




void
TRACER_BASE::cvt_rtobj_tracable(RT_OBJ&           rt_obj,
                                RT_INSTR&         rt_instr,
                                CVT_RT_OBJ& results) {
    /////// for load
    cvtLoadOrStoreToPhyAddr(rt_obj, rt_instr, results, true);
    /////// for store
    cvtLoadOrStoreToPhyAddr(rt_obj, rt_instr, results, false);

}


void
TRACER_BASE::onGetDynTraceValue(dynTraceData dyndata) {

    /////// convert virtual memory address to simulated address
    auto* rt_instr = rt_instrs[dyndata.rawData.fetchId];
    CVT_RT_OBJ cvt_trace_data{};
    cvt_rtobj_tracable(dyndata.rawData, *rt_instr, cvt_trace_data);
    ////// fill data to rt_instr
    rt_instr->fillDynData(cvt_trace_data); ///// please remind that in the future we need to clear the filled data
    /////// generate micro-op
    inflight_uops.clear();
    rt_instr->genUOPS(inflight_uops);
    /////// interact with uop windows BUT DO NOT PUSH TO UOP WINDOW
            ////// we must notify result front-end first
    for (auto* uop: inflight_uops){
        uop->setSeqNum(nextMopId++);
        uop->doDepenCheck(uopWindow);
    }
    /////// send to result front-end
    resFed->onGetUopsResult(inflight_uops, rt_instr);
    /////// push data to uop window
    for (auto* uop : inflight_uops){
        uopWindow->addUop(uop);
    }

}


void
TRACER_BASE::onInitialize(uint64_t lastRTinstr) {

    //// for fetch (build new) the runtime instruction for this worker
    //// and decode it to get macrop and push it to our runtime instruction.
    for (uint64_t rtInstrId = 0; rtInstrId < lastRTinstr; rtInstrId++){
        auto* rt_instr = threadModel->getInstrTemplate(rtInstrId);
        assert(rt_instr != nullptr);
        auto* mop = decoder->decodeMOP(*rt_instr);
        assert(mop != nullptr);
        rt_instr->setMacroop(mop);
        rt_instrs.push_back(rt_instr);
    }
    ////////////////////////////////////////////////////////////////////////

}