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
        assert(rt_instr != nullptr);
        /** create instr record*/
        ProtoMessage::InstrRecord instrRec;
        instrRec.set_instr_num(curInstrNum++);
        instrRec.set_fetch_num(rt_instr->getRtInstrId());
        /** set vaddress but for now we use physical addr instead*/
        std::vector<ADAS> prePhyAddrsResult;
        //std::cout << "v address " << rt_instr->getAddr() << std::endl;
        memMng->v2pConvert(rt_instr->getAddr(), rt_instr->getSize(), prePhyAddrsResult);
        instrRec.set_v_instraddr(prePhyAddrsResult[0].addr);
        instrRec.set_v_instrsize(prePhyAddrsResult[0].size);
        //std::cout << "p address " << prePhyAddrsResult[0].addr << std::endl;

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
                    setMemHelper (uop_base, machRec, true);
                    break;
                case UOP_STORE:
                    setTempRegHelper(uop_base, machRec, true);
                    setMemHelper    (uop_base, machRec, false);
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
        META_GRP<REG_META>* regMetaPtr;
        if (isSrc){
            regMetaPtr = uop_base->getMetaPtr<META_CLASS::META_SRC_REG, REG_META>();
        }else{
            regMetaPtr = uop_base->getMetaPtr<META_CLASS::META_DES_REG, REG_META>();
        }
        /** destination to insert new regNum*/ //void (ProtoMessage::machRecord::*  inseter)(uint32_t);
        auto inseter = isSrc ? &ProtoMessage::machRecord::add_srcarchregid
                             : &ProtoMessage::machRecord::add_desarchregid;
        /**insert*/
        for (auto regNum : *regMetaPtr){
            stat::MAIN_STAT["DEP_REG"][std::to_string(regNum)].asUINT()++;
            (machRec->*inseter)(regNum);
        }


    }

    void
    TBD_GEM5_ISA::setTempRegHelper(UOP_BASE *uop_base, ProtoMessage::machRecord *machRec, bool isSrc) {
        /** src for get regNum*/
        META_GRP<TREG_META>* regMetaPtr;
        if (isSrc){
            regMetaPtr = uop_base->getMetaPtr<META_CLASS::META_SRC_TEMP, TREG_META>();
        }else{
            regMetaPtr = uop_base->getMetaPtr<META_CLASS::META_DES_TEMP, TREG_META>();
        }
        /** destination to insert new regNum*/ //void (ProtoMessage::machRecord::*  inseter)(uint32_t);
        auto inseter = isSrc ? &ProtoMessage::machRecord::add_srctempregid
                             : &ProtoMessage::machRecord::add_destempregid;
        /**insert*/
        for (auto tregNum : *regMetaPtr){
            stat::MAIN_STAT["DEP_TEMP"][std::to_string(tregNum)].asUINT()++;
            (machRec->*inseter)(tregNum);
        }
    }

    void
    TBD_GEM5_ISA::setMemHelper(UOP_BASE *uop_base, ProtoMessage::machRecord *machRec, bool isLoad) {
        META_GRP<MEM_META>* memMetaPtr;
        if (isLoad){
            memMetaPtr = uop_base->getMetaPtr<META_CLASS::META_SRC_MEM, MEM_META>();
        }else{
            memMetaPtr = uop_base->getMetaPtr<META_CLASS::META_DES_MEM, MEM_META>();
        }
        ////////// add base reg
        /**for now we assume that for each microop have only one mem ref*/
        if (!memMetaPtr->empty()) {
            auto& memMeta = (*memMetaPtr)[0];
            if (memMeta.baseReg != UNUSEDREG) {
                stat::MAIN_STAT["DEP_TEMP_MEM_bREG"][std::to_string(memMeta.baseReg)].asUINT()++;
                machRec->add_srcarchregid(memMeta.baseReg);
            }
            ///////// add index register
            if (memMeta.indexReg != UNUSEDREG) {
                stat::MAIN_STAT["DEP_TEMP_MEM_iREG"][std::to_string(memMeta.indexReg)].asUINT()++;
                machRec->add_srcarchregid(memMeta.indexReg);
            }

            /** virtual address*/
            machRec->set_v_addr(memMeta.v_area.addr);
            machRec->set_v_size(memMeta.v_area.size);
            /** physical address*/
            machRec->set_p_effaddr(memMeta.p_area.addr);
            machRec->set_p_effsize(memMeta.p_area.size);

        }


    }

    void BIND_RESULT_FRONT_END_TBDGEMISA(py::module& m){
        py::class_<TBD_GEM5_ISA, RESULT_FRONT_END>(m, "TBD_GEM5_ISA")
                .def(py::init<const std::string&>());
    }


}