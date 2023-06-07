import base.uop.uop_base as ub
import base.operand.opr_simple as opr
import X86.uop.resMap as resMap

class UOP_COMP(ub.UOP_BASE):

    def __init__(self, _name : str, _cxxType_prefix : str):
        super().__init__(_cxxType_prefix, _name,
                         2, 2,
                         resMap.cxxTypeToUopType.get(_cxxType_prefix, resMap.default_uopType), resMap.cxxTypeToExecUnit.get(_cxxType_prefix, 0)
                         )

        ##### TODO exec unit must be intepret from _cxxType_prefix
        self.io_input.addAcceptTypes(
            [
             {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP}, ### input list 1
             {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM} ### input list 1
             ]
        )
        self.io_output.addAcceptTypes(
            [
              {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP}, ####output possible list
              {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_DUMMY}  ####output possible list
            ]
        )
