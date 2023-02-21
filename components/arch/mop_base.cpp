//
// Created by tanawin on 21/2/2566.
//

#include "mop_base.h"
#include "../inst_model/operand.h"
#include "../inst_model/rt_instr.h"

void MOP_BASE::set_rt_instr(RT_INSTR* _rt_instr) {
    assert(_rt_instr != nullptr);
    rt_instr = _rt_instr;
}

vector<UOP_BASE*> MOP_SIMPLE::genUop(){
    assert(rt_instr != nullptr);
    vector<UOP_BASE*> retUOP;
    /////////// give one micro-op for one imm operand
    vector<UOP_BASE*> immUops;
    for (auto& immOpr: rt_instr->getSrcImmOperands()){
            auto immUop = new UOP_SIMPLE();
            immUops.push_back(immUop);
            retUOP.push_back(immUop);
    }
    /////////// give one micro-op for one imm operand
    vector<UOP_BASE*> ldUops;
    for (auto& ldOpr: rt_instr->getSrcLdOperands()){
        auto ldUop = new UOP_SIMPLE();
        ldUop->addMemMeta(ldOpr.getValue(), true);
        ldUops.push_back(ldUop);
        retUOP.push_back(ldUop);
    }
    //////////// give only one uop for all reg compute node
    auto compUop = new UOP_SIMPLE();
    for (auto srcRegOpr: rt_instr->getSrcRegOperands()){
        compUop->addRegMeta(srcRegOpr.getValue(), true);
    }
    for (auto desRegOpr: rt_instr->getDesRegOperands()){
        compUop->addRegMeta(desRegOpr.getValue(), false);
    }
    retUOP.push_back(compUop);
    /////////// give one micro-op for one store operand
    vector<UOP_BASE*> stUops;
    for (auto& stOpr: rt_instr->getDesStOperands()){
        auto stUop = new UOP_SIMPLE();
        stUop->addMemMeta(stOpr.getValue(), false);
        stUops.push_back(stUop);
        retUOP.push_back(stUop);
    }

    /////////// dependency connection
    ////////////// connect comp uop to imm uop and ld uop
    for (auto ldUop: ldUops){
        compUop->addRegDep(ldUop);
    }
    for (auto immUop: immUops){
        compUop->addTemDep(immUop);
    }
    ////////////// connect store uop to comp uop
    for (auto stUop: stUops){
        stUop->addMemDep(compUop);
    }
    /////////////return the pooled uop
    return retUOP;
}