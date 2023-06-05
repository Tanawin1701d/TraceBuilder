import base.mop.mop_group_base as mop_group
import base.operand.opr_simple as opr
import X86.mop.alu.comp_mop    as mop_alu_x86
class MOP_GROUP_COMP(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["ADC" , "ADD", "AND" , "OR" , "ROL",
                "ROR" , "SAL", "SAR" , "SBB", "SHL",
                "SHLD", "SHR", "SHRD", "SUB", "XCHG", "XOR",
                "CMP" , "INC", "RCL" , "RCR",  "JMP", "LEA",
                "CMPXCHG"]

    decKeys1 = ["MUL", "IMUL", "MULX", "DIV", "IDIV"]

    decKeys2 = ["V64_COMP"]

    srcOpr   = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]

    desOpr   = [opr.OPR_REG, opr.OPR_MEM]

    desOprWDummy = [opr.OPR_REG, opr.OPR_MEM, opr.OPR_DUMMY]


    def __init__(self):
        ###### simple alu
        super().__init__(6, mop_alu_x86.MOP_COMP_ALL)
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["INT_SIM_ALU"]      , [self.decKeys0]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["INT_MUL_DIV_ALU"]  , [self.decKeys1]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy, ["SIM64_ALU"]       , [self.decKeys2]))


class MOP_GROUP_COMP128(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["V128_COMP"]

    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]
    desOprWDummy = [opr.OPR_REG, opr.OPR_MEM, opr.OPR_DUMMY]

    def __init__(self):
        super().__init__(6, mop_alu_x86.MOP_COMP128_ALL)
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr, self.desOprWDummy,["SIM128_ALU"], [self.decKeys0]))