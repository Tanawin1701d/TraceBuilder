import base.mop.mop_group_base as mop_group
import base.operand.opr_simple as opr
import X86.mop.mov.mov_mop     as mop_mov_x86


###### mov mop group

class MOP_GROUP_MOV(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["MOV", "LEA", "PUSH", "POP", "V64_MOV", "JMP", "MOVSXD", "MOVZX"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(4, mop_mov_x86.MOP_MOV_ALL)
        self.addMopArgExtractComb((self.srcOpr, self.desOpr, ["MOV_SIM"], [self.decKeys0]))

class MOP_GROUP_MOV128(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["V128_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(4, mop_mov_x86.MOP_MOV256_ALL)
        self.addMopArgExtractComb((self.srcOpr, self.desOpr, ["MOV128_SIM"], [self.decKeys0]))