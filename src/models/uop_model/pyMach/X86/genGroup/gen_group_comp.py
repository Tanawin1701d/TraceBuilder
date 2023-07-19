import base.mop.mop_group_base as mop_group
import base.operand.opr_simple as opr
import X86.mop.alu.comp_mop    as mop_alu_x86
import X86.mop.alu.compSemiVec as mop_alu_semi_x86
import X86.uop.resMap          as resMap
import X86.operand.opr         as x86_opr
class MOP_GROUP_COMP(mop_group.MOP_GROUP_BASE):
    decKeys_intAlu = ["ADC" , "ADD", "AND" , "OR" , "ROL",
                      "ROR" , "SAL", "SAR" , "SBB", "SHL",
                      "SHLD", "SHR", "SHRD", "SUB", "XCHG", "XOR",
                      "CMP" , "RCL" ,"RCR",  "JMP","LEA",
                      "CMPXCHG", "CALL_NEAR"]

    decKeys_intMul = ["MUL", "IMUL", "MULX"]

    decKeys_intDiv = ["DIV", "IDIV"]

    decKeys_fAlu   = ["FADD"  , "FSUB"  , "FSUBR", "FADDP",
                      "FSUBP" , "FSUBRP", "FIADD", "FISUB", "FISUBR"]

    decKeys_fmul   = ["FMUL", "FMULP", "FIMUL"]

    decKeys_fdiv   = ["FDIV", "FDIVR", "FIDIV"]

    decKeys_single    = ["NOT", "NEG", "INC", "DEC", "RET_NEAR"]

    srcOpr   = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]

    desOpr   = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]

    desOprWDummy = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR, opr.OPR_DUMMY]

    def __init__(self):
        ###### simple alu
        super().__init__("MOP_GROUP_COMP",8, mop_alu_x86.MOP_COMP_64_BASE_X86)
                                                                                            #### please remind that mop name "COMP*** should not colid with other"
        self.addMopArgExtractComb((["COMP_INT"      ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["IntAlu"   ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intAlu]))
        ### for neg and not
        self.addMopArgExtractComb((["COMP_INT_S_SRC"] ,self.srcOpr, [opr.OPR_DUMMY], self.desOpr, [opr.OPR_DUMMY], ["IntAlu"   ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_single]))
        ################################################################################################################################
        self.addMopArgExtractComb((["COMP_MUL"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["IntMult"  ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intMul]))
        self.addMopArgExtractComb((["COMP_DIV"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["IntDiv"   ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intDiv]))
        self.addMopArgExtractComb((["COMP_FLT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["FloatAdd" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fAlu]))
        self.addMopArgExtractComb((["COMP_FLT_MUL"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["FloatMult"], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fmul]))
        self.addMopArgExtractComb((["COMP_FLT_DIV"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["FloatDiv" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fdiv]))


class MOP_GROUP_COMP_SIMD64(mop_group.MOP_GROUP_BASE):
    decKeys_intAlu = ["V64_INT_ALU"]
    decKeys_intMul = ["V64_INT_MUL"]
    decKeys_intDiv = ["V64_INT_DIV"]
    decKeys_fAlu   = ["V64_FLT_ALU"]
    decKeys_fMul   = ["V64_FLT_MUL"]
    decKeys_fDiv   = ["V64_FLT_DIV"]

    decKeys_fAluS = ["V64_FLTS_ALU","V128_FLTS_ALU", "V256_FLTS_ALU", "V64X_FLTS_ALU","V128X_FLTS_ALU", "V256X_FLTS_ALU"]
    decKeys_fMulS = ["V64_FLTS_MUL","V128_FLTS_MUL", "V256_FLTS_MUL", "V64X_FLTS_MUL","V128X_FLTS_MUL", "V256X_FLTS_MUL"]
    decKeys_fDivS = ["V64_FLTS_DIV","V128_FLTS_DIV", "V256_FLTS_DIV", "V64X_FLTS_DIV","V128X_FLTS_DIV", "V256X_FLTS_DIV"]


    srcOpr   = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOpr   = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOprWDummy = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR, opr.OPR_DUMMY]

    def __init__(self):
        ###### simple alu
        super().__init__("MOP_GROUP_COMP_SIMD64", 8, mop_alu_x86.MOP_COMP_64_BASE_X86)
                                                                                            #### please remind that mop name "COMP*** should not colid with other"
        self.addMopArgExtractComb((["COMP64_INT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdAlu"      ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intAlu]))
        self.addMopArgExtractComb((["COMP64_MUL"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdMult"     ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intMul]))
        self.addMopArgExtractComb((["COMP64_DIV"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdDiv"      ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intDiv]))
        self.addMopArgExtractComb((["COMP64_FLT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatAlu" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fAlu]))
        self.addMopArgExtractComb((["COMP64_FLT_MUL"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatMult"], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fMul]))
        self.addMopArgExtractComb((["COMP64_FLT_DIV"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatDiv" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fDiv]))

        self.addMopArgExtractComb((["COMP_FLTS"    ], self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy,["SimdFloatAlu"], [resMap.cxxTypeIO_suggest_FLT], [self.decKeys_fAluS]))
        self.addMopArgExtractComb((["COMP_FLTS_MUL"], self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy,["SimdFloatMult"], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fMulS]))
        self.addMopArgExtractComb((["COMP_FLTS_DIV"], self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy,["SimdFloatDiv"], [resMap.cxxTypeIO_suggest_FLT], [self.decKeys_fDivS]))


class MOP_GROUP_COMP128(mop_group.MOP_GROUP_BASE):
    decKeys_intAlu = ["V128_INT_ALU"]
    decKeys_intMul = ["V128_INT_MUL"]
    decKeys_intDiv = ["V128_INT_DIV"]
    decKeys_fAlu   = ["V128_FLT_ALU"]
    decKeys_fMul   = ["V128_FLT_MUL"]
    decKeys_fDiv   = ["V128_FLT_DIV"]


    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOpr = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOprWDummy = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR, opr.OPR_DUMMY]

    def __init__(self):
        super().__init__("MOP_GROUP_COMP_SIMD128",8, mop_alu_x86.MOP_COMP_128_BASE_X86)
                                                                                            #### please remind that mop name "COMP*** should not colid with other"
        self.addMopArgExtractComb((["COMP128_INT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdAlu"      ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intAlu]))
        self.addMopArgExtractComb((["COMP128_MUL"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdMult"     ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intMul]))
        self.addMopArgExtractComb((["COMP128_DIV"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdDiv"      ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intDiv]))
        self.addMopArgExtractComb((["COMP128_FLT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatAlu" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fAlu]))
        self.addMopArgExtractComb((["COMP128_FLT_MUL"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatMult"], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fMul]))
        self.addMopArgExtractComb((["COMP128_FLT_DIV"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatDiv" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fDiv]))



class MOP_GROUP_COMP256(mop_group.MOP_GROUP_BASE):
    decKeys_intAlu = ["V256_INT_ALU"]
    decKeys_intMul = ["V256_INT_MUL"]
    decKeys_intDiv = ["V256_INT_DIV"]
    decKeys_fAlu   = ["V256_FLT_ALU"]
    decKeys_fMul   = ["V256_FLT_MUL"]
    decKeys_fDiv   = ["V256_FLT_DIV"]

    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOpr = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOprWDummy = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR, opr.OPR_DUMMY]

    def __init__(self):
        super().__init__("MOP_GROUP_COMP_SIMD256",8, mop_alu_x86.MOP_COMP_256_BASE_X86)
                                                                                            #### please remind that mop name "COMP*** should not colid with other"
        self.addMopArgExtractComb((["COMP256_INT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdAlu"      ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intAlu]))
        self.addMopArgExtractComb((["COMP256_MUL"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdMult"     ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intMul]))
        self.addMopArgExtractComb((["COMP256_DIV"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdDiv"      ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intDiv]))
        self.addMopArgExtractComb((["COMP256_FLT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatAlu" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fAlu]))
        self.addMopArgExtractComb((["COMP256_FLT_MUL"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatMult"], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fMul]))
        self.addMopArgExtractComb((["COMP256_FLT_DIV"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatDiv" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fDiv]))


class MOP_GROUP_COMP128X(mop_group.MOP_GROUP_BASE):
    decKeys_intAlu = ["V128X_INT_ALU"]
    decKeys_intMul = ["V128X_INT_MUL"]
    decKeys_intDiv = ["V128X_INT_DIV"]
    decKeys_fAlu   = ["V128X_FLT_ALU"]
    decKeys_fMul   = ["V128X_FLT_MUL"]
    decKeys_fDiv   = ["V128X_FLT_DIV"]

    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOpr = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOprWDummy = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR, opr.OPR_DUMMY]

    def __init__(self):
        super().__init__("MOP_GROUP_COMP_SIMD128X",8, mop_alu_semi_x86.MOP_COMP_SEMI128_BASE_X86)
                                                                                            #### please remind that mop name "COMP*** should not colid with other"
        self.addMopArgExtractComb((["COMP128X_INT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdAlu"      ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intAlu]))
        self.addMopArgExtractComb((["COMP128X_MUL"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdMult"     ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intMul]))
        self.addMopArgExtractComb((["COMP128X_DIV"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdDiv"      ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intDiv]))
        self.addMopArgExtractComb((["COMP128X_FLT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatAlu" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fAlu]))
        self.addMopArgExtractComb((["COMP128X_FLT_MUL"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatMult"], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fMul]))
        self.addMopArgExtractComb((["COMP128X_FLT_DIV"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatDiv" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fDiv]))



class MOP_GROUP_COMP256X(mop_group.MOP_GROUP_BASE):
    decKeys_intAlu = ["V256X_INT_ALU"]
    decKeys_intMul = ["V256X_INT_MUL"]
    decKeys_intDiv = ["V256X_INT_DIV"]
    decKeys_fAlu   = ["V256X_FLT_ALU"]
    decKeys_fMul   = ["V256X_FLT_MUL"]
    decKeys_fDiv   = ["V256X_FLT_DIV"]

    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOpr = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR]
    desOprWDummy = [opr.OPR_REG, opr.OPR_MEM, x86_opr.OPR_MEM_W_IPR, opr.OPR_DUMMY]

    def __init__(self):
        super().__init__("MOP_GROUP_COMP_SIMD256X", 8, mop_alu_semi_x86.MOP_COMP_SEMI256_BASE_X86)
                                                                                            #### please remind that mop name "COMP*** should not colid with other"
        self.addMopArgExtractComb((["COMP256X_INT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdAlu"      ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intAlu]))
        self.addMopArgExtractComb((["COMP256X_MUL"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdMult"     ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intMul]))
        self.addMopArgExtractComb((["COMP256X_DIV"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdDiv"      ], [resMap.cxxTypeIO_suggest_INT],[self.decKeys_intDiv]))
        self.addMopArgExtractComb((["COMP256X_FLT"    ] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatAlu" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fAlu]))
        self.addMopArgExtractComb((["COMP256X_FLT_MUL"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatMult"], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fMul]))
        self.addMopArgExtractComb((["COMP256X_FLT_DIV"] ,self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatDiv" ], [resMap.cxxTypeIO_suggest_FLT],[self.decKeys_fDiv]))