import base.mop.mop_group_base as mop_group
import base.operand.opr_simple as opr
import X86.mop.alu.comp_mop    as mop_alu_x86
class MOP_GROUP_COMP(mop_group.MOP_GROUP_BASE):
    decKeys_intAlu = ["ADC" , "ADD", "AND" , "OR" , "ROL",
                      "ROR" , "SAL", "SAR" , "SBB", "SHL",
                      "SHLD", "SHR", "SHRD", "SUB", "XCHG", "XOR",
                      "CMP" , "INC", "RCL" , "RCR",  "JMP", "LEA",
                      "CMPXCHG", "V64_INT_ALU"]

    decKeys_intMul = ["MUL", "IMUL", "MULX", "V64_MUL", "V64_INT_MUL"]

    decKeys_intDiv = ["DIV", "IDIV", "V64_DIV", "V64_INT_DIV"]

    decKeys_fAlu   = ["FADD"  , "FSUB"  , "FSUBR", "FADDP",
                      "FSUBP" , "FSUBRP", "FIADD", "FISUB", "FISUBR", "V64_FLT_ALU"]

    decKeys_fmul   = ["FMUL", "FMULP", "FIMUL", "V64_FLT_MUL"]

    decKeys_fdiv   = ["FDIV", "FDIVR", "FIDIV", "V64_FLT_DIV"]

    srcOpr   = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]

    desOpr   = [opr.OPR_REG, opr.OPR_MEM]

    desOprWDummy = [opr.OPR_REG, opr.OPR_MEM, opr.OPR_DUMMY]

    def __init__(self):
        ###### simple alu
        super().__init__(6, mop_alu_x86.MOP_COMP_ALL)

        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["IntAlu"] ,   [self.decKeys_intAlu]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["IntMult"],   [self.decKeys_intMul]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["IntDiv"],    [self.decKeys_intDiv]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["FloatAdd"],  [self.decKeys_fAlu]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["FloatMult"], [self.decKeys_fmul]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["FloatDiv"],  [self.decKeys_fdiv]))



class MOP_GROUP_COMP128(mop_group.MOP_GROUP_BASE):
    decKeys_intAlu = ["V128_INT_ALU"]
    decKeys_intMul = ["V128_INT_MUL"]
    decKeys_intDiv = ["V128_INT_DIV"]
    decKeys_fAlu   = ["V128_FLT_ALU"]
    decKeys_fMul   = ["V128_FLT_MUL"]
    decKeys_fDiv   = ["V128_FLT_DIV"]

    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]
    desOprWDummy = [opr.OPR_REG, opr.OPR_MEM, opr.OPR_DUMMY]

    def __init__(self):
        super().__init__(6, mop_alu_x86.MOP_COMP128_ALL)
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdAlu"      ], [self.decKeys_intAlu]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdMult"     ], [self.decKeys_intMul]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdDiv"      ], [self.decKeys_intDiv]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatAlu" ], [self.decKeys_fAlu  ]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatMult"], [self.decKeys_fMul  ]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SimdFloatDiv" ], [self.decKeys_fDiv  ]))