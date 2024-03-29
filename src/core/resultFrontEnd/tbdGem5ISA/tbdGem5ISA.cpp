//
// Created by tanawin on 17/6/2566.
//

#include "tbdGem5ISA.h"
#include "core/core.h"
#include "stat/statPool.h"


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

    void TBD_GEM5_ISA::onGetUopsResult(std::vector<UOP_BASE*>& result, RT_INSTR_PTR rt_instr) {
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

            bool skip = shouldSkipUop(uop_base);

            ProtoMessage::machRecord* machRec = instrRec.add_uops();

            /** set shared data*/
            machRec->set_seq_num(uop_base->getSeqNum());
            EXEC_UNIT_ID execUnit = skip ? 0: uop_base->getExecUnit();
            assert(execUnit != 99);
            machRec->set_funcunit(execUnit);
            stat::MAIN_STAT["EXEC_UNIT"][std::to_string(execUnit)].asUINT()++;
            if (skip) {
                stat::MAIN_STAT["EXEC_UNIT"]["skip"]["amount"].asUINT()++;
                stat::MAIN_STAT["EXEC_UNIT"]["skip"]["instrName"][rt_instr->getDecodeKey()].asUINT()++;
            }
            auto uopType = uop_base->getUopType();
            machRec->set_rectype(skip ? ProtoMessage::machRecord_RecordType::machRecord_RecordType_UOP_COMP :
                                        static_cast<ProtoMessage::machRecord_RecordType>(uopType));

            /** set the data for specific uop type*/
            switch (uopType){

                case UOP_COMP:
                    setArchRegHelper(uop_base, machRec, true);
                    setArchRegHelper(uop_base, machRec, false);
                    setTempRegHelper(uop_base, machRec, true);
                    setTempRegHelper(uop_base, machRec, false);
                    break;
                case UOP_LOAD:
                    setArchRegHelper (uop_base, machRec, false);
                    setTempRegHelper (uop_base, machRec, false);
                    setMemHelper     (uop_base, machRec, true);
                    break;
                case UOP_STORE:
                    setArchRegHelper(uop_base, machRec, true);
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
        META_GRP<MREG_META>* regMetaPtr;
        if (isSrc){
            regMetaPtr = uop_base->getMetaPtr<META_CLASS::META_SRC_MREG, MREG_META>();
        }else{
            regMetaPtr = uop_base->getMetaPtr<META_CLASS::META_DES_MREG, MREG_META>();
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
            (machRec->*inseter)(tregNum + START_TREGID);
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
            if (memMeta.baseReg != UNUSED_AREG) {
                MREGNUM baseRegMid = archRegToMReg(memMeta.baseReg, 0);
                stat::MAIN_STAT["DEP_TEMP_MEM_bREG"][std::to_string(baseRegMid)].asUINT()++;
                machRec->add_srcarchregid(baseRegMid);
            }
            ///////// add index register
            if (memMeta.indexReg != UNUSED_AREG) {
                MREGNUM indexRegMid = archRegToMReg(memMeta.indexReg, 0);
                stat::MAIN_STAT["DEP_TEMP_MEM_iREG"][std::to_string(indexRegMid)].asUINT()++;
                machRec->add_srcarchregid(indexRegMid);
            }

            /** virtual address*/
            machRec->set_v_addr(memMeta.v_area.addr);
            machRec->set_v_size(memMeta.v_area.size);
            /** physical address*/
            machRec->set_p_effaddr(memMeta.p_area.addr);
            machRec->set_p_effsize(memMeta.p_area.size);

        }


    }

    bool TBD_GEM5_ISA::shouldSkipUop(UOP_BASE *uop_base) {
        /** check that the uop should be sukppressed*/
        auto uopType = uop_base->getUopType();

        if (uopType == UOP_LOAD){
            auto ldMetaPtr = uop_base->getMetaPtr<META_CLASS::META_SRC_MEM, MEM_META>();
            if (ldMetaPtr->empty()){return true;}
            auto& memMeta = (*ldMetaPtr)[0];
            return memMeta.suppressed;
        }else if (uopType == UOP_STORE){
            auto stMetaPtr = uop_base->getMetaPtr<META_CLASS::META_DES_MEM, MEM_META>();
            if (stMetaPtr->empty()){return true;}
            auto& memMeta = (*stMetaPtr)[0];
            return memMeta.suppressed;
        }
        return false;

    }


    void BIND_RESULT_FRONT_END_TBDGEMISA(py::module& m){
        py::class_<TBD_GEM5_ISA, RESULT_FRONT_END, std::shared_ptr<TBD_GEM5_ISA>>(m, "TBD_GEM5_ISA")
                .def(py::init<const std::string&>())
                .def("test", &TBD_GEM5_ISA::test)
                ;
    }


}