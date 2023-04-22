import base.uop.uop_base as ub
import base.operand.opr_simple as opr

class UOP_MOV(ub.UOP_BASE):

    def __init__(self, _name: str):
        super().__init__("MOV", _name, 1, 1)
        self.io_input.addAcceptType(0, {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM})