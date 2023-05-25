import itertools as iter
import base.mop.mop_group_base as mop_group
import base.mop.mop_gen        as mop_gen
import base.operand.opr_simple as opr
import X86.mop.alu.comp_mop    as mop_alu_x86
import X86.mop.mov.mov_mop     as mop_mov_x86

class MOP_GROUP_COMP(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["ADC" , "ADD", "AND" , "OR" , "ROL",
                "ROR" , "SAL", "SAR" , "SBB", "SHL",
                "SHLD", "SHR", "SHRD", "SUB", "XCHG", "XOR",
                "CMP" , "INC", "RCL" , "RCR", "V64_COMP", "JMP"]

    decKeys1 = ["MUL", "IMUL", "MULX", "V64_MUL"]

    decKeys2 = ["DIV", "IDIV", "V64_DIV"]

    srcOpr   = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]

    desOpr   = [opr.OPR_REG, opr.OPR_MEM]


    def __init__(self):
        ###### simple alu
        super().__init__(5, mop_alu_x86.MOP_COMP_ALL)
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr,["SIM_ALU"], [self.decKeys0]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr,["MUL_ALU"], [self.decKeys1]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr,["DIV_ALU"], [self.decKeys2]))


class MOP_GROUP_COMP128(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["V128_COMP"]
    decKeys1 = ["V128_MUL"]
    decKeys2 = ["V128_DIV"]

    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(5, mop_alu_x86.MOP_COMP128_ALL)
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr,["SIM128_ALU"], [self.decKeys0]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr,["MUL128_ALU"], [self.decKeys0]))
        self.addMopArgExtractComb((self.srcOpr, self.srcOpr, self.desOpr,["DIV128_ALU"], [self.decKeys0]))

###### mov mop group

class MOP_GROUP_MOV(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["MOV", "LEA", "PUSH", "POP", "V64_MOV", "JMP"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(4, mop_mov_x86.MOP_MOV_ALL)
        self.addMopArgExtractComb((self.srcOpr, self.desOpr, ["SIM_MOV"], [self.decKeys0]))

class MOP_GROUP_MOV128(mop_group.MOP_GROUP_BASE):
    decKeys0 = ["V128_MOV"]
    srcOpr = [opr.OPR_REG, opr.OPR_IMM, opr.OPR_MEM]
    desOpr = [opr.OPR_REG, opr.OPR_MEM]

    def __init__(self):
        super().__init__(4, mop_mov_x86.MOP_MOV256_ALL)
        self.addMopArgExtractComb((self.srcOpr, self.desOpr, ["SIM_MOV128"], [self.decKeys0]))