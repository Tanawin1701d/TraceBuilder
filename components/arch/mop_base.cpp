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

    /////////// give one micro-op for one imm operand
    vector<UOP_BASE*> immOperand;
    for (auto& immOpr: rt_instr->getSrcImmOperands()){
            auto ldUop = new UOP_SIMPLE();
            immOperand.push_back(ldUop);
    }
    /////////// give one micro-op for one imm operand
    vector<UOP_BASE*> ldOperand;
    for (auto& )

}