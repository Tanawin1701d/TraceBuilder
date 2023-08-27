//
// Created by tanawin on 24/12/2565.
//

#include "tracer.h"
#include "core/core.h"

namespace traceBuilder::core {

    using namespace traceBuilder::model;


    TRACER_BASE::TRACER_BASE(CORE *_core,
                             SHARED_TRACEINFO* _sharedInfo,
                             SPECIFIC_TRACEINFO* _specificInfo):
            sharedSimEle(_sharedInfo),
            specificSimEle(_specificInfo){

        assert(sharedSimEle != nullptr);
        assert(specificSimEle != nullptr);
    }


    void
    TRACER_BASE::cvtLoadOrStoreToPhyAddr(RT_OBJ &rt_obj,
                                         RT_INSTR &rt_instr,
                                         CVT_RT_OBJ &results,
                                         bool isLoad) { /// else is store


        uint64_t *vAddrs; ///// virtual address
        uint8_t amt;     ///// amount operand need to convert
        uint64_t *pAddrs; ///// physical address FOR FILL RESULT
        uint64_t *sizes;   ///// size that need to load

        if (isLoad) {
            vAddrs = rt_obj.loadAddr;
            amt = rt_obj.amt_load;
            results.amt_load = amt; ////// fill number of loaded operand
            pAddrs = results.phyLoadAddr;
            assert((amt) == rt_instr.countSrcLdOpeands());
            /////// fill size that operand need to load
            sizes = new uint64_t[amt];
            auto &ldOpr = rt_instr.getSrcLdOperands();
            for (size_t idx = 0; idx < amt; idx++) {
                sizes[idx] = ldOpr[idx].getData().size;
            }
        } else { //// store
            vAddrs = rt_obj.storeAddr;
            amt = rt_obj.amt_store;
            results.amt_store = amt; /////// fill number of stored operand
            pAddrs = results.phyStoreAddr;
            //std::cout << "amt " << amt << " rt amt " << rt_instr.countDesStOperands() <<std::endl;
            assert((amt) == rt_instr.countDesStOperands());
            /////// fill size that operand need to store
            sizes = new uint64_t[amt];
            auto &stOpr = rt_instr.getDesStOperands();
            for (size_t idx = 0; idx < amt; idx++) {
                sizes[idx] = stOpr[idx].getData().size;
            }
        }
        /////// fill the physical address
        for (size_t idx = 0; idx < amt; idx++) {
            std::vector<ADAS> phyAddressResult;
            sharedSimEle->memMng->v2pConvert(vAddrs[idx], (int) sizes[idx], phyAddressResult);
            pAddrs[idx] = phyAddressResult[0].addr; ///// for now we assume mem mng return only size of one
        }
        delete[] sizes;

    }


    void
    TRACER_BASE::cvt_rtobj_tracable(RT_OBJ &rt_obj,
                                    RT_INSTR &rt_instr,
                                    CVT_RT_OBJ &results) {
        /////// for load
        cvtLoadOrStoreToPhyAddr(rt_obj, rt_instr, results, true);
        /////// for store
        cvtLoadOrStoreToPhyAddr(rt_obj, rt_instr, results, false);
    }

    uint64_t
    TRACER_BASE::genSeqNum_fromIdx(size_t idx){
        return specificSimEle->uopWindow->getLastPushSeqNum() + idx + 1;
    }


    void
    TRACER_BASE::onGetDynTraceValue(dynTraceData dyndata) {

        /////// convert virtual memory address to simulated address
        assert(dyndata.rawData.fetchId < specificSimEle->threadModel->getAmountInstr());
        auto rt_instr = specificSimEle->threadModel->getRtInstr(dyndata.rawData.fetchId);

        //////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////// stat /////////
        //////////////////////////////////////////////////////////////////////////
        stat::MAIN_STAT["dynTrace"]["MNEMONIC"][rt_instr->getMnemonic()].asUINT()++;
        stat::MAIN_STAT["dynTrace"]["MOP_COUNT"].asUINT()++;

        if ((stat::MAIN_STAT["dynTrace"]["MOP_COUNT"].asUINT() % 1000000) == 0) {
            std::cout << util::getProgPf(__FILE__, __LINE__) << " pass : " << stat::MAIN_STAT["dynTrace"]["MOP_COUNT"].asUINT()
                      << " instructions" << std::endl;
        }
        ///////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////
        CVT_RT_OBJ cvt_trace_data{};
        cvt_rtobj_tracable(dyndata.rawData, *rt_instr, cvt_trace_data);
        ////// fill data to rt_instr
        rt_instr->fillDynData(dyndata.rawData, cvt_trace_data); ///// please remind that in the future we need to clear the filled data
        /////// generate micro-op
        inflight_uops.clear();
        rt_instr->genUOPS(inflight_uops);
        /////// interact with uop windows BUT DO NOT PUSH TO UOP WINDOW
        ////// we must notify result front-end first
        for (size_t idx = 0; idx < inflight_uops.size(); idx++) {
            stat::MAIN_STAT["dynTrace"]["UOP_COUNT"].asUINT()++;
            auto uop = inflight_uops[idx];
            ///// fullfil uop meta data before doDepenCHeck
            uop->setSeqNum(genSeqNum_fromIdx(idx));
            uop->doAllDepenCheck(specificSimEle->uopWindow);
        }
        /////// send to result front-end
        specificSimEle->resultFed->onGetUopsResult(inflight_uops, rt_instr);
        /////// push data to uop window
        for (auto *uop: inflight_uops) {
            specificSimEle->uopWindow->addUop(uop);
        }

    }

}