//
// Created by tanawin on 2/3/2566.
//

#include "resultFed_gemLagacy.h"
#include "core/core.h"

namespace traceBuilder::core {

    RESULT_FRONT_END_GEM_LAGACY::
    RESULT_FRONT_END_GEM_LAGACY(const std::string &filePath_data,
                                const std::string &filePath_instr,
                                const int freq,
                                const int windowSize)
            : lastTick(0) {
        instrProtoStream = new ProtoOutputStream(filePath_instr);
        dataProtoStream = new ProtoOutputStream(filePath_data);
        ////// write header for instruction dep trace
        ProtoMessage::PacketHeader inst_pkt_header;
        inst_pkt_header.set_obj_id("gem5");
        inst_pkt_header.set_tick_freq(freq);
        instrProtoStream->write(inst_pkt_header);
        ////// write header for data dep trace
        ProtoMessage::InstDepRecordHeader data_rec_header;
        data_rec_header.set_obj_id("gem5");
        data_rec_header.set_tick_freq(freq);
        data_rec_header.set_window_size(windowSize);
        dataProtoStream->write(data_rec_header);

    }

    RESULT_FRONT_END_GEM_LAGACY::~RESULT_FRONT_END_GEM_LAGACY() {
        delete dataProtoStream;
        delete instrProtoStream;
        std::cout << getProgPf(__FILE__, __LINE__) << " flushed protoStream" << std::endl;
    }

    void
    RESULT_FRONT_END_GEM_LAGACY::onGetUopsResult(
            std::vector<UOP_BASE *> &uops,
            RT_INSTR *rt_instr
    ) {
#ifdef debug
        std::cout << "current instruction is " << rt_instr->getDebugName() << std::endl;
        for (auto uop: uops){
            std::cout << "uop sn " << uop->getSeqNum() << " register dep ";
            for (auto regdepUop: uop->getRegDep()){
                std::cout << regdepUop->getSeqNum() << " ";
            }
            std::cout << "memory dep ";
            for (auto memDepUop : uop->getMemDep()){
                std::cout << memDepUop->getSeqNum() << " ";
            }
            std::cout << "temp Register Dep ";
            for (auto tempDepUop : uop->getTemDep()){
                std::cout << tempDepUop->getSeqNum();
            }
            std::cout << "\n";

        }
    std::cout << "--------------------------------\n";
#endif



        ////////////////////////////////////////////////////////
        //////// generate dynamic data record FOR gem5
        ////////////////////////////////////////////////////////
        for (auto *uop: uops) {
            assert(uop != nullptr);
            ///////////////////////////////// build protobuffer
            ProtoMessage::InstDepRecord dep_pkt;
            dep_pkt.set_seq_num(uop->getSeqNum());
            dep_pkt.set_flags(0);
            dep_pkt.set_comp_delay(execUnit_info->getLatencyCycle(uop->getExecUnit()) * 500);
            dep_pkt.set_weight(0);
            dep_pkt.set_pc(0);
            ///////////////////////////////////////////////////////
            ////////// add dependency for each uop instruction type
            ///////////////////////////////////////////////////////
            ///// you can trust that the uops dependency which get from ONGETUOPSRESULTS is not deleted
            //////// by uop window but it maybe deleted after this function is finised.
            for (auto regDepUop: uop->getRegDep_iter()) {
                //std::cout << "reg added" << std::endl;
                stat::MAIN_STAT["DepGem5"]["reg"].asUINT()++;

            }
            for (auto *tempRegDepUop: uop->getTemDep()) {
                //std::cout << "temp added" << std::endl;
                stat::MAIN_STAT["DepGem5"]["Treg"].asUINT()++;

            }
            for (auto *execDepUop: uop->getExecDep_iter()) {
                //std::cout << "exec added" << std::endl;
                stat::MAIN_STAT["DepGem5"]["Exec"].asUINT()++;

            }
            for (auto *memDepUop: uop->getMemDep_iter()) {
                //std::cout << "mem added" << std::endl;
                stat::MAIN_STAT["DepGem5"]["mem"].asUINT()++;

            }


            /////// get all dep
            //////////////////
            ////  the tem dep is not associated with RWS because the it is used with out uop window help
            /////// all dep w/o tem dep
            for (auto depUop: uop->getDep_Rwd_pool().getDep_iter()) {
                dep_pkt.add_reg_dep(depUop->getSeqNum());
            }
            /////// tem dep
            for (auto depUop: uop->getTemDep()) {
                dep_pkt.add_reg_dep(depUop->getSeqNum());
            }


            /////////////////////////////////////////////////////
            ////////// add explicit for each uop instruction type
            /////////////////////////////////////////////////////
            ///////////// for compute instruction
            if (uop->getUopType() == UOP_COMP || uop->getUopType() == UOP_IMM) {
                dep_pkt.set_type(ProtoMessage::InstDepRecord_RecordType_COMP);
            }
                ///////////// for load instruction
            else if (uop->getUopType() == UOP_LOAD) {
                dep_pkt.set_type(ProtoMessage::InstDepRecord_RecordType_LOAD);
                auto &allLdAdas = uop->get_load_phyAdas();
                if (!allLdAdas.empty()) {
                    dep_pkt.set_p_addr(allLdAdas[0].addr);
                    dep_pkt.set_size(allLdAdas[0].size);
                }
                ///////////// for store instruction
            } else if (uop->getUopType() == UOP_STORE) {
                dep_pkt.set_type(ProtoMessage::InstDepRecord_RecordType_STORE);
                auto &allStAdas = uop->get_store_phyAdas();
                if (!allStAdas.empty()) {
                    dep_pkt.set_p_addr(allStAdas[0].addr);
                    dep_pkt.set_size(allStAdas[0].size);
                }
            } else {
                std::string errorCode = "can't convert to google protobuffer uopType: "
                                        + std::to_string(uop->getUopType());
                throw std::invalid_argument(errorCode.c_str());
            }

            dataProtoStream->write(dep_pkt);
        }


        ////////////////////////////////////////////////////////
        //////// generate dynamic static record FOR gem5
        ////////////////////////////////////////////////////////
        std::vector<ADAS> phyInstrResult;
        mng->v2pConvert(rt_instr->getAddr(), rt_instr->getSize(), phyInstrResult);
        ProtoMessage::Packet instr_pkt;
        lastTick += 100;
        instr_pkt.set_tick(lastTick);
        instr_pkt.set_flags(256);
        instr_pkt.set_cmd(1);
        instr_pkt.set_addr(phyInstrResult[0].addr);
        instr_pkt.set_size(phyInstrResult[0].size);
        instrProtoStream->write(instr_pkt);

    }

    void RESULT_FRONT_END_GEM_LAGACY::setRes(CORE* _core,
                                             SHARED_TRACEINFO* _sharedInfo,
                                             SPECIFIC_TRACEINFO* _specificInfo){
        execUnit_info = _sharedInfo->execUnit_info;
        mng           = _sharedInfo->memMng;
        assert(execUnit_info != nullptr);
    }

    void BIND_RESULT_FRONT_END_GEM_LAGACY(py::module& m){
        py::class_<RESULT_FRONT_END_GEM_LAGACY, RESULT_FRONT_END>(m, "RESULT_FRONT_END_GEM_LAGACY")
                .def(py::init<std::string&, std::string&, const int, const int>());
    }



}