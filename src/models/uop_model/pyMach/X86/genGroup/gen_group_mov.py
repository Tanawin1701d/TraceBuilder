import base.mop.mop_group_base as mop_group
import base.operand.opr_simple as opr
import X86.mop.mov.mov_mop     as mop_mov_x86
import X86.uop.resMap          as resMap

###### mov mop group

class MOP_GROUP_MOV(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["MOV", "LEA", "PUSH", "POP", "JMP", "MOVSXD", "MOVZX", "V64_INT_MOV"]
    decKeys1 = ["V64_FLT_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(7, mop_mov_x86.MOP_MOV_BASE_X86)
        self.addMopArgExtractComb((["MOV_INT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_INT], [self.decKeys0],
                                   [8], [8])
                                  )

        self.addMopArgExtractComb((["MOV_FLT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_FLT], [self.decKeys1],
                                   [8], [8])
                                  )

class MOP_GROUP_MOV128(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["V128_INT_MOV"]
    decKeys1 = ["V128_FLT_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(7, mop_mov_x86.MOP_MOV_BASE_X86)
        self.addMopArgExtractComb((["MOV128_INT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_INT], [self.decKeys0],
                                   [8], [16])
                                  )

        self.addMopArgExtractComb((["MOV128_FLT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_FLT], [self.decKeys1],
                                   [8], [16])
                                  )

class MOP_GROUP_MOV256(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["V256_INT_MOV"]
    decKeys1 = ["V256_FLT_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(7, mop_mov_x86.MOP_MOV_BASE_X86)
        self.addMopArgExtractComb((["MOV256_INT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_INT], [self.decKeys0],
                                   [8], [32])
                                  )

        self.addMopArgExtractComb((["MOV256_FLT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_FLT], [self.decKeys1],
                                   [8], [32])
                                  )

##############################################################################################

class MOP_GROUP_MOV128X(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["V128X_INT_MOV"]
    decKeys1 = ["V128X_FLT_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(7, mop_mov_x86.MOP_MOV_BASE_X86)
        self.addMopArgExtractComb((["MOV128X_INT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_INT], [self.decKeys0],
                                   [8], [8])
                                  )

        self.addMopArgExtractComb((["MOV128X_FLT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_FLT], [self.decKeys1],
                                   [8], [8])
                                  )

class MOP_GROUP_MOV256X(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["V256X_INT_MOV"]
    decKeys1 = ["V256X_FLT_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(7, mop_mov_x86.MOP_MOV_BASE_X86)
        self.addMopArgExtractComb((["MOV256X_INT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_INT], [self.decKeys0],
                                   [8], [8])
                                  )

        self.addMopArgExtractComb((["MOV256X_FLT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_FLT], [self.decKeys1],
                                   [8], [8])
                                  )