import base.uop.uop_base as ub
import base.operand.opr_simple as opr
import X86.uop.resMap as resMap

class UOP_COMP(ub.UOP_BASE):

    in_idxInGrp: int
    in_uopOprSize: int
    in_archOprSize: int

    out_idxInGrp: int
    out_uopOprSize: int
    out_archOprSize: int
    def __init__(self, _name : str, _cxxType_prefix : str,
                 _in_idxInGrp: int, _in_uopOprSize: int, _in_archOprSize: int,
                 _out_idxInGrp: int, _out_uopOprSize: int, _out_archOprSize: int
                 ):
        super().__init__(_cxxType_prefix, _name,
                         2, 2,
                         resMap.cxxTypeToUopType(_cxxType_prefix), resMap.cxxTypeToExecUnit(_cxxType_prefix)
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

        self.in_idxInGrp   = _in_idxInGrp
        self.in_uopOprSize   = _in_uopOprSize
        self.in_archOprSize   = _in_archOprSize
        self.out_idxInGrp   = _out_idxInGrp
        self.out_uopOprSize   = _out_uopOprSize
        self.out_archOprSize   = _out_archOprSize

    def addIo(self, _inputs: list, _outputs: list):
        super().addIo(_inputs, _outputs)
        for idx in range(len(_inputs)):
            self.io_input_metaArgs[idx] = _inputs[idx].genCXX_getFillMetaHelper_forVec \
                (self.in_idxInGrp, self.in_uopOprSize, self.in_archOprSize)

        for idx in range(len(_outputs)):
            self.io_output_metaArgs[idx] = _outputs[idx].genCXX_getFillMetaHelper_forVec \
                (self.out_idxInGrp, self.out_uopOprSize, self.out_archOprSize)
