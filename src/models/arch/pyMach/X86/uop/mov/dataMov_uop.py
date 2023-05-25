import base.uop.uop_base as ub
import base.operand.opr_simple as opr
import X86.uop.resMap as resMap


class UOP_MOV(ub.UOP_BASE):

    def __init__(self, _name : str, _cxxType_prefix : str):
        super().__init__(_cxxType_prefix, _name,
                         1              ,     1,
                         "UOP_COMP", resMap.cxxTypeToExecUnit.get(_cxxType_prefix, 0)
                         )
        self.io_input .addAcceptType(0, {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM})
        self.io_output.addAcceptType(0, {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM})