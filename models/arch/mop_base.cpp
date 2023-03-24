//
// Created by tanawin on 21/2/2566.
//

#include "mop_base.h"
#include "models/inst_model/rt_instr.h"

////////////////////////////////////////////////////////////////////

void
MOP_SIMPLE::genUop(vector<UOP_BASE*>& results,
                   RT_INSTR*          rt_instr){
    assert(rt_instr != nullptr);
    ////////////////////////////////////////////////////////////////
    ///
    /// generate simple micro-op
    ///
    ////////////////////////////////////////////////////////////////
    /////////// give one micro-op for one imm operand
    vector<UOP_BASE*> immUops;
    for (auto& immOpr: rt_instr->getSrcImmOperands()){
            auto immUop = new UOP_SIMPLE(UOP_IMM);
            immUops.push_back(immUop);
            results.push_back(immUop);
    }
    /////////// give one micro-op for one load operand
    vector<UOP_BASE*> ldUops;
    for (auto& ldOpr: rt_instr->getSrcLdOperands()){
        auto ldUop = new UOP_SIMPLE(UOP_LOAD);
        ldUop->addMemMeta(ldOpr.getMeta(), true);
        ldUops.push_back(ldUop);
        results.push_back(ldUop);
    }
    //////////// give only one uop for all reg compute node
    auto compUop = new UOP_SIMPLE(UOP_COMP);
    for (auto srcRegOpr: rt_instr->getSrcRegOperands()){
        compUop->addRegMeta(srcRegOpr.getMeta(), true);
    }
    for (auto desRegOpr: rt_instr->getDesRegOperands()){
        compUop->addRegMeta(desRegOpr.getMeta(), false);
    }
    results.push_back(compUop);
    /////////// give one micro-op for one store operand
    vector<UOP_BASE*> stUops;
    for (auto& stOpr: rt_instr->getDesStOperands()){
        auto stUop = new UOP_SIMPLE(UOP_STORE);
        stUop->addMemMeta(stOpr.getMeta(), false);
        stUops.push_back(stUop);
        results.push_back(stUop);
    }
    ////////////////////////////////////////////////////////////////
    ///
    /// connect dependency
    ///
    ////////////////////////////////////////////////////////////////

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
}

