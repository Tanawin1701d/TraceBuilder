//
// Created by tanawin on 2/3/2566.
//

#include "resultFed_gemLagacy.h"


RESULT_FRONT_END_GEM_LAGACY::
RESULT_FRONT_END_GEM_LAGACY(const std::string& filePath_data, const std::string& filePath_instr)
: lastTick(0){
    dataProtoStream  = new ProtoOutputStream(filePath_data) ;
    instrProtoStream = new ProtoOutputStream(filePath_instr);
}

RESULT_FRONT_END_GEM_LAGACY::~RESULT_FRONT_END_GEM_LAGACY() {
    delete dataProtoStream;
    delete instrProtoStream;
    std::cout << getProgPf(__FILE__, __LINE__) << " flushed protoStream" << std::endl;
}

void
RESULT_FRONT_END_GEM_LAGACY::onGetUopsResult(
        std::vector<UOP_BASE*> &uops,
        RT_INSTR* rt_instr
        ) {
    ////////////////////////////////////////////////////////
    //////// generate dynamic data record FOR gem5
    ////////////////////////////////////////////////////////
    for (auto* uop: uops){
        assert(uop != nullptr);
        ///////////////////////////////// build protobuffer
        ProtoMessage::InstDepRecord dep_pkt;
        dep_pkt.set_seq_num(uop->getSeqNum());
        dep_pkt.set_flags(0);
        dep_pkt.set_comp_delay(500);
        dep_pkt.set_weight(1);
        dep_pkt.set_pc(0);
        ///////////////////////////////////////////////////////
        ////////// add dependency for each uop instruction type
        ///////////////////////////////////////////////////////
        ///// you can trust that the uops dependency which get from ONGETUOPSRESULTS is not deleted
        //////// by uop window but it maybe deleted after finish this function.
        for (auto* regDepUop: uop->getRegDep()){
            MAIN_STAT["DepGem5"]["reg"]++;
            dep_pkt.add_reg_dep(regDepUop->getSeqNum());
        }
        for (auto* tempRegDepUop: uop->getTemDep()){
            MAIN_STAT["DepGem5"]["reg"]++;
            dep_pkt.add_reg_dep(tempRegDepUop->getSeqNum());
        }
        for (auto* memDepUop: uop->getMemDep()){
            MAIN_STAT["DepGem5"]["mem"]++;
            dep_pkt.add_rob_dep(memDepUop->getSeqNum());
        }

        /////////////////////////////////////////////////////
        ////////// add explicit for each uop instruction type
        /////////////////////////////////////////////////////
        ///////////// for compute instruction
        if (uop->getUopType() == UOP_COMP || uop->getUopType() == UOP_IMM){
            dep_pkt.set_type(ProtoMessage::InstDepRecord_RecordType_COMP);
        }
        ///////////// for load instruction
        else if (uop->getUopType() == UOP_LOAD) {
            dep_pkt.set_type(ProtoMessage::InstDepRecord_RecordType_LOAD);
            auto& allLdAdas = uop->getAll_LD_ADAS();
            if (!allLdAdas.empty()){
                dep_pkt.set_p_addr(allLdAdas[0].addr);
                dep_pkt.set_size(allLdAdas[0].size);
            }
        ///////////// for store instruction
        }else if (uop->getUopType() == UOP_STORE){
            dep_pkt.set_type(ProtoMessage::InstDepRecord_RecordType_STORE);
            auto& allStAdas = uop->getAll_ST_ADAS();
            if (!allStAdas.empty()){
                dep_pkt.set_p_addr(allStAdas[0].addr);
                dep_pkt.set_size(allStAdas[0].size);
            }
        }else{
            std::string errorCode = "can't convert to google protobuffer uopType: "
                               + std::to_string(uop->getUopType());
            throw std::invalid_argument(errorCode.c_str());
        }

        dataProtoStream->write(dep_pkt);
    }

    ////////////////////////////////////////////////////////
    //////// generate dynamic static record FOR gem5
    ////////////////////////////////////////////////////////

    ProtoMessage::Packet instr_pkt;
    lastTick += 500;
    instr_pkt.set_tick(lastTick);
    instr_pkt.set_cmd(0);
    instr_pkt.set_addr(lastTick % 1000000);
    instr_pkt.set_size(4);
    instrProtoStream->write(instr_pkt);

}
