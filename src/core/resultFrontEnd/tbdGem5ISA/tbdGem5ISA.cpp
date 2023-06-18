//
// Created by tanawin on 17/6/2566.
//

#include "tbdGem5ISA.h"
#include "core/core.h"


namespace traceBuilder::core{

    TBD_GEM5_ISA::TBD_GEM5_ISA(const std::string &machProtoFilePath):
    curInstrNum(0){

        desFileStream = new ProtoOutputStream(machProtoFilePath);
        assert(desFileStream);
        /** set header packet and write it*/
        ProtoMessage::headerRecord header;
        header.set_obj_id("gem5");
        header.set_ver(0);
        desFileStream->write(header);
    }

    void TBD_GEM5_ISA::onGetUopsResult(std::vector<UOP_BASE*>& result, RT_INSTR* rt_instr) {
        /** sanity check*/

        /** create instr record*/
        ProtoMessage::InstrRecord instrRec;
        instrRec.set_instr_num(curInstrNum++);
        instrRec.set_fetch_num(rt_instr->getRtInstrId());
        /** set vaddress but for now we use physical addr instead*/
        std::vector<ADAS> prePhyAddrsResult;
        memMng->v2pConvert(rt_instr->getAddr(), rt_instr->getSize(), prePhyAddrsResult);
        instrRec.set_v_instraddr(prePhyAddrsResult[0].addr);
        instrRec.set_v_instrsize(prePhyAddrsResult[0].size);

        /** create mach record and add to instr rec*/
        for (auto uop_base: result) {
            ProtoMessage::machRecord* machRec = instrRec.add_uops();
            /** set shared data*/
            machRec->set_seq_num(uop_base->getSeqNum());
            machRec->set_funcunit(uop_base->getExecUnit());
            auto uopType = uop_base->getUopType();
            machRec->set_rectype(static_cast<ProtoMessage::machRecord_RecordType>(uopType));

            /** set the data for specific uop type*/
            switch (uopType){

                case UOP_COMP:
                    setArchRegHelper(uop_base, machRec, true);
                    setArchRegHelper(uop_base, machRec, false);
                    setTempRegHelper(uop_base, machRec, true);
                    setTempRegHelper(uop_base, machRec, false);
                    break;
                case UOP_LOAD:
                    setTempRegHelper (uop_base, machRec, false);
                    setMemAreaHelper (uop_base, machRec, true);
                    setMemRegHelper  (uop_base, machRec);
                    break;
                case UOP_STORE:
                    setTempRegHelper(uop_base, machRec, true);
                    setMemAreaHelper(uop_base, machRec, false);
                    setMemRegHelper  (uop_base, machRec);
                    break;
                case UOP_IMM:
                    setArchRegHelper(uop_base, machRec, false);
                    setTempRegHelper(uop_base, machRec, false);
                    break;
                case UOP_DUMMY:
                    break;
            }
        }



        desFileStream->write(instrRec);


    }

    void TBD_GEM5_ISA::setRes(CORE *core,
                              SHARED_TRACEINFO *sharedInfo,
                              SPECIFIC_TRACEINFO *specificInfo) {
        memMng = sharedInfo->memMng;
        assert(memMng);
    }

    void
    TBD_GEM5_ISA::setArchRegHelper(UOP_BASE *uop_base, ProtoMessage::machRecord *machRec, bool isSrc) {
        /** src for get regNum*/
        auto& regNums = isSrc ? uop_base->getSrcRegs() : uop_base->getDesRegs();
        /** destination to insert new regNum*/ //void (ProtoMessage::machRecord::*  inseter)(uint32_t);
        auto inseter = isSrc ? &ProtoMessage::machRecord::add_srcarchregid
                             : &ProtoMessage::machRecord::add_desarchregid;
        /**insert*/
        for (auto regNum : regNums){
            (machRec->*inseter)(regNum);
        }


    }

    void
    TBD_GEM5_ISA::setTempRegHelper(UOP_BASE *uop_base, ProtoMessage::machRecord *machRec, bool isSrc) {
        /** src for get regNum*/
        auto& TregNums = isSrc ? uop_base->getSrcTRegs() : uop_base->getdesTRegs();
        /** destination to insert new regNum*/ //void (ProtoMessage::machRecord::*  inseter)(uint32_t);
        auto inseter = isSrc ? &ProtoMessage::machRecord::add_srctempregid
                             : &ProtoMessage::machRecord::add_destempregid;
        /**insert*/
        for (auto tregNum : TregNums){
            (machRec->*inseter)(tregNum);
        }
    }

    void
    TBD_GEM5_ISA::setMemRegHelper(UOP_BASE *uop_base, ProtoMessage::machRecord *machRec) {
        auto& memMeta = uop_base->getMemMetaStatic();
        ////////// add base reg
        if (memMeta.baseRegId != UNUSEDREG){
            machRec->add_srcarchregid(memMeta.baseRegId);
        }
        ///////// add index register
        if (memMeta.indexRegId != UNUSEDREG){
            machRec->add_srcarchregid(memMeta.baseRegId);
        }


    }

    void
    TBD_GEM5_ISA::setMemAreaHelper(UOP_BASE *uop_base, ProtoMessage::machRecord *machRec, bool isLoad) {
        std::vector<ADAS>& virAddr = isLoad ? uop_base->get_load_virAdas() : uop_base->get_store_virAdas();
        std::vector<ADAS>& phyAddr = isLoad ? uop_base->get_load_phyAdas() : uop_base->get_store_phyAdas();
        /** due to proto buf will only stereo type wheather it is load or not rectype will classify it*/
        /** and for now, for each uop are not support multi address pointing support we will choose only first element*/
        assert(!virAddr.empty());
        assert(!phyAddr.empty());
        /** set virtual address*/
        machRec->set_v_addr(virAddr[0].addr);
        machRec->set_v_size(virAddr[0].size);
        /** set physical address*/
        machRec->set_p_effaddr(phyAddr[0].addr);
        machRec->set_p_effsize(phyAddr[0].size);
    }

    void BIND_RESULT_FRONT_END_TBDGEMISA(py::module& m){
        py::class_<TBD_GEM5_ISA, RESULT_FRONT_END>(m, "TBD_GEM5_ISA")
                .def(py::init<const std::string&>());
    }


}