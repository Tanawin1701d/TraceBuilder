//
// Created by tanawin on 13/2/2566.
//

#include "decoder.h"

vector<UOP_BASE*> DECODER::decode(RT_INSTR &rt_instr) {
    //////// imm operand build
    vector<UOP_BASE*> immOprs;
    for (const auto& immOpr: rt_instr.getSrcImmOperands()){
        immOprs.push_back( new SIMPLE_IMM_UOP(immOpr) );
    }
    //////// load operand build
    vector<UOP_BASE*> ldOprs;
    for (const auto& ldOpr: rt_instr.getSrcLdOperands()){
        ldOprs.push_back(new SIMPLE_LOAD_UOP(ldOpr));
    }
    //////// compute operand build
    UOP_BASE* compOpr = new SIMPLE_COMP_REG_UOP(rt_instr.getSrcRegOperands(),
                                                rt_instr.getDesRegOperands());
    //////// store operand build
    vector<UOP_BASE*> stOprs;
    for (const auto& stOpr: rt_instr.getDesStOperands()){
        stOprs.push_back(new SIMPLE_STORE_UOP(stOpr));
    }

    ////////// curdependency connector ////// for now we assume that there is at least one compute uop
    //// connect compute instruction depend on imm
    assert(compOpr);
    for (auto immOpr : immOprs) {
        compOpr->addTemDep(immOpr);
    }
    //// connect compute instruction depend on ld uop
    for (auto ldOpr: ldOprs){
        compOpr->addTemDep(ldOpr);
    }
    //// connect store instruction to compute instruction dependency
    for (auto stOpr : stOprs){
        stOpr->addExeDep(compOpr);
    }
    ///////// pool all uop and sent back to main program
    vector<UOP_BASE*> preRet;
    preRet.insert(preRet.end(), immOprs.begin(), immOprs.end());
    preRet.insert(preRet.end(), ldOprs.begin(), ldOprs.end());
    preRet.push_back(compOpr);
    preRet.insert(preRet.end(), stOprs.begin(), stOprs.end());
    return preRet;
}
