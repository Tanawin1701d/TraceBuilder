//
// Created by tanawin on 24/12/2565.
//

#include "tracer.h"

namespace traceBuilder::core {

    using namespace traceBuilder::model;


    TRACER_BASE::TRACER_BASE(THREAD_ID _tid,
                             RESULT_FRONT_END *_resFed,
                             UOP_WINDOW *_uopWindow,
                             DECODER_BASE *_decoder,
                             MEM_MNG *_memMng,
                             THREAD_MODEL *_threadModel) :
            tid(_tid),
            resFed(_resFed),
            uopWindow(_uopWindow),
            decoder(_decoder),
            memMng(_memMng),
            threadModel(_threadModel),
            nextUopId(1) {
        assert(_decoder != nullptr);
        assert(_resFed != nullptr);
        assert(_uopWindow != nullptr);
        assert(_memMng != nullptr);
        assert(_threadModel != nullptr);
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
                sizes[idx] = ldOpr[idx].getSize();
            }
        } else { //// store
            vAddrs = rt_obj.storeAddr;
            amt = rt_obj.amt_store;
            results.amt_store = amt; /////// fill number of stored operand
            pAddrs = results.phyStoreAddr;
            assert((amt) == rt_instr.countDesStOperands());
            /////// fill size that operand need to store
            sizes = new uint64_t[amt];
            auto &stOpr = rt_instr.getDesStOperands();
            for (size_t idx = 0; idx < amt; idx++) {
                sizes[idx] = stOpr[idx].getSize();
            }
        }
        /////// fill the physical address
        for (size_t idx = 0; idx < amt; idx++) {
            std::vector<ADAS> phyAddressResult;
            memMng->v2pConvert(vAddrs[idx], (int) sizes[idx], phyAddressResult);
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


    void
    TRACER_BASE::onGetDynTraceValue(dynTraceData dyndata) {

        /////// convert virtual memory address to simulated address
        assert(dyndata.rawData.fetchId < rt_instrs.size());
        auto *rt_instr = rt_instrs[dyndata.rawData.fetchId];
        //////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////// stat /////////
        //////////////////////////////////////////////////////////////////////////
        stat::MAIN_STAT["dynTrace"]["MNEMONIC"][rt_instr->getMnemonic()].asUINT()++;
        stat::MAIN_STAT["dynTrace"]["MNEMONIC"][rt_instr->getMnemonic()][rt_instr->getMacroop()->getIsAutoGen() ? "miss"
                                                                                                          : "hit"].asUINT()++;
        stat::MAIN_STAT["dynTrace"]["MOP_COUNT"].asUINT()++;

        if (rt_instr->getMacroop()->getIsAutoGen()) {
            stat::MAIN_STAT["dynTrace"]["needUpgrade"][rt_instr->getDebugDecodeKey() + "----" +
                                                 rt_instr->getDebugName()].asUINT()++;
        }

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
        rt_instr->fillDynData(cvt_trace_data); ///// please remind that in the future we need to clear the filled data
        /////// generate micro-op
        inflight_uops.clear();
        rt_instr->genUOPS(inflight_uops);
        /////// interact with uop windows BUT DO NOT PUSH TO UOP WINDOW
        ////// we must notify result front-end first
        for (auto *uop: inflight_uops) {
            stat::MAIN_STAT["dynTrace"]["UOP_COUNT"].asUINT()++;
            uop->setSeqNum(nextUopId++);
            uop->doDepenCheck(uopWindow);
        }
        /////// send to result front-end
        resFed->onGetUopsResult(inflight_uops, rt_instr);
        /////// push data to uop window
        for (auto *uop: inflight_uops) {
            uop->finalizeTemDep(uopWindow);
            uopWindow->addUop(uop);
        }

    }


    void
    TRACER_BASE::onInitialize(uint64_t lastRTinstr) {

        //// for fetch (build new) the runtime instruction for this worker
        //// and decode it to get macrop and push it to our runtime instruction.
        for (uint64_t rtInstrId = 0; rtInstrId < lastRTinstr; rtInstrId++) {
            auto *rt_instr = threadModel->getInstrTemplate(rtInstrId);
            assert(rt_instr != nullptr);
            auto *mop = decoder->decodeMOP(*rt_instr);
            assert(mop != nullptr);
            rt_instr->setMacroop(mop);
            rt_instrs.push_back(rt_instr);
        }
        ////////////////////////////////////////////////////////////////////////

    }

}