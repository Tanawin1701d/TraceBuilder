import base.uop.uop_base as ub
import base.operand.opr_simple as opr

class UOP_COMP(ub.UOP_BASE):

    def __init__(self, _name : str):
        super().__init__("COMP", _name, 2, 1)
        self.io_input.addAcceptTypes(
            [
             {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP}, ### input list 1
             {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM} ### input list 1
             ]
        )
        self.io_output.addAcceptTypes(
            [
              {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP} ####output possible list
            ]
        )


class UOP_CMP(ub.UOP_BASE):

    def __init__(self, _name : str):
        super().__init__("CMP", _name, 1, 1)
        self.io_input .addAcceptType(0, {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM})
        self.io_output.addAcceptType(0, {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM})