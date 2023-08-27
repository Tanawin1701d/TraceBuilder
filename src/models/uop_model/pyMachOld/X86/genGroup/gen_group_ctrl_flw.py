import base.mop.mop_group_base as mop_group
import base.operand.opr_simple as opr
import X86.mop.ctrlFlow.ctrl_mop  as mop_ctrl_flw_x86
import X86.operand.opr         as x86_opr

class MOP_GROUP_CMP(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["CMP", "TEST", "JNB"]

    srcOpr   = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]

    def __init__(self):
        ####### simple compare
        super().__init__("MOP_GROUP_CMP", 5, mop_ctrl_flw_x86.MOP_CMP_ALL)
        self.addMopArgExtractComb((["CMP_ALL"],self.srcOpr, self.srcOpr, ["IntAlu"], [self.decKeys0]))


class MOP_GROUP_JMP(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["JMP", "JE", "JZ",  "JL", "JB",
                "JLE", "JBE", "JG", "JA", "JGE",
                "JAE", "JNL", "JNE", "JNZ","JNB",
                "JNBE", "JNLE", "JS"]

    srcOpr   = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    srcOprWDummy = [opr.OPR_REG, opr.OPR_DUMMY, x86_opr.OPR_MEM_W_IPR]
    desOpr   = [opr.OPR_REG]

    def __init__(self):
        super().__init__("MOP_GROUP_JMP", 6, mop_ctrl_flw_x86.MOP_JMP_ALL)
        self.addMopArgExtractComb(( ["CTRL_ALL"], self.srcOpr, self.srcOprWDummy, self.desOpr, ["IntAlu"], [self.decKeys0]))