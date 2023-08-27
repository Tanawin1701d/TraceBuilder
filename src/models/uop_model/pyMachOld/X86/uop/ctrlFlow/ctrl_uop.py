import base.uop.uop_base as ub
import base.operand.opr_simple as opr
import X86.uop.resMap as resMap

class UOP_CMP(ub.UOP_BASE):

    def __init__(self, _name : str, _cxxType_prefix : str):
        super().__init__(_cxxType_prefix, _name,
                         2, 0,
                         resMap.cxxTypeToUopType(_cxxType_prefix), resMap.cxxTypeToExecUnit(_cxxType_prefix)
                         )
        self.io_input.addAcceptType(0, {opr.OPR_REG, opr.OPR_TEMP, opr.OPR_IMM})
        self.io_input.addAcceptType(1, {opr.OPR_REG, opr.OPR_TEMP, opr.OPR_IMM})

    def addIo(self, _inputs: list, _outputs: list):
        super().addIo(_inputs, _outputs)
        for idx in range(len(_inputs)):
            self.io_input_metaArgs[idx] = _inputs[idx].genCXX_getFillMetaHelper_forVec \
                (0, 8, 8)
        for idx in range(len(_outputs)):
            self.io_output_metaArgs[idx] = _outputs[idx].genCXX_getFillMetaHelper_forVec \
                (0, 8, 8)



class UOP_JMP(ub.UOP_BASE):
    def __init__(self, _name : str, _cxxType_prefix : str):
        super().__init__(_cxxType_prefix, _name,
                         2, 1,
                         resMap.cxxTypeToUopType(_cxxType_prefix), resMap.cxxTypeToExecUnit(_cxxType_prefix)
                         )
        self.io_input .addAcceptType(0, {opr.OPR_REG, opr.OPR_TEMP})
        self.io_input .addAcceptType(1, {opr.OPR_REG, opr.OPR_TEMP, opr.OPR_DUMMY})

        self.io_output.addAcceptType(0, {opr.OPR_REG})

    def addIo(self, _inputs: list, _outputs: list):
        super().addIo(_inputs, _outputs)
        for idx in range(len(_inputs)):
            self.io_input_metaArgs[idx] = _inputs[idx].genCXX_getFillMetaHelper_forVec \
                (0, 8, 8)
        for idx in range(len(_outputs)):
            self.io_output_metaArgs[idx] = _outputs[idx].genCXX_getFillMetaHelper_forVec \
                (0, 8, 8)