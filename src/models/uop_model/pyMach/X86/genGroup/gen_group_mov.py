import base.mop.mop_group_base as mop_group
import base.operand.opr_simple as opr
import X86.mop.mov.mov_mop     as mop_mov_x86
import X86.uop.resMap          as resMap

###### mov mop group

class MOP_GROUP_MOV(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["MOV", "LEA", "PUSH", "POP", "JMP", "MOVSXD", "MOVZX", "V64_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(7, mop_mov_x86.MOP_MOV_BASE_X86)
        self.addMopArgExtractComb((["MOV_SIM"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_INT], [self.decKeys0],
                                   [8], [8])
                                  )

class MOP_GROUP_MOV128(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["V128_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(7, mop_mov_x86.MOP_MOV_BASE_X86)
        self.addMopArgExtractComb((["MOV_SIM"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_INT], [self.decKeys0],
                                   [8], [16])
                                  )