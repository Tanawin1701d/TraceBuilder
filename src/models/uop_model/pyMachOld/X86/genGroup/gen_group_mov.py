import base.mop.mop_group_base as mop_group
import base.operand.opr_simple as opr
import X86.mop.mov.mov_mop     as mop_mov_x86
import X86.uop.resMap          as resMap
import X86.operand.opr         as x86_opr

###### mov mop group

class MOP_GROUP_MOV(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["MOV", "LEA", "PUSH", "POP", "JMP", "MOVSXD", "MOVZX", "MOVSX","V64_INT_MOV"]
    decKeys1 = ["V64_FLT_MOV", "V64_FLTS_MOV", "V128_FLTS_MOV", "V256_FLTS_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOpr = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]

    def __init__(self):
        super().__init__("MOP_GROUP_MOV",7, mop_mov_x86.MOP_MOV_BASE_X86)
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
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOpr = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]

    def __init__(self):
        super().__init__("MOP_GROUP_MOV128", 7, mop_mov_x86.MOP_MOV_BASE_X86)
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
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOpr = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]

    def __init__(self):
        super().__init__("MOP_GROUP_MOV256", 7, mop_mov_x86.MOP_MOV_BASE_X86)
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
    decKeys0 = ["V128X_INT_MOV", "V256X_INT_MOV",  ]
    decKeys1 = ["V64X_FLT_MOV", "V128X_FLT_MOV", "V256X_FLT_MOV",  "V64X_FLTS_MOV", "V128X_FLTS_MOV", "V256X_FLTS_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOpr = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]

    def __init__(self):
        super().__init__("MOP_GROUP_MOV128X", 7, mop_mov_x86.MOP_MOV_BASE_X86)
        self.addMopArgExtractComb((["MOV128X_INT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_INT], [self.decKeys0],
                                   [8], [8])
                                  )

        self.addMopArgExtractComb((["MOV128X_FLT"], self.srcOpr, self.desOpr,
                                   [resMap.cxxTypeIO_suggest_FLT], [self.decKeys1],
                                   [8], [8])
                                  )