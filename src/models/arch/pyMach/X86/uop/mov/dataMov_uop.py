import base.uop.uop_base as ub
import base.operand.opr_simple as opr

class UOP_MOV(ub.UOP_BASE):

    def __init__(self, _name : str, _cxxType_prefix : str, _execUnit : int):
        super().__init__(_cxxType_prefix, _name,
                         1              ,     1,
                         "UOP_COMP", _execUnit
                         )
        self.io_input .addAcceptType(0, {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM})
        self.io_output.addAcceptType(0, {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM})