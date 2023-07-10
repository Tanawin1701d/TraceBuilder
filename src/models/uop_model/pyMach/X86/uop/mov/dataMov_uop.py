import base.uop.uop_base as ub
import base.operand.opr_simple as opr
import X86.uop.resMap as resMap


class UOP_MOV(ub.UOP_BASE):
    idxInGrp    : int
    uopOprSize  : int
    archOprSize : int

    #### idx in group is used when vector instrution need to load by using multiple uop with using same arch operand
    def __init__(self, _name : str, _cxxType_prefix : str,
                 _idxInGrp: int, _uopOprSize: int, _archOprSize: int):
        ##TODO uopdate idxInGrp to get
        super().__init__(_cxxType_prefix, _name,
                         1, 1,
                         resMap.cxxTypeToUopType(_cxxType_prefix), resMap.cxxTypeToExecUnit(_cxxType_prefix)
                         )
        self.io_input .addAcceptType(0, {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM})
        self.io_output.addAcceptType(0, {opr.OPR_REG, opr.OPR_MEM, opr.OPR_TEMP, opr.OPR_IMM})

        idxInGrp    =  _idxInGrp
        uopOprSize  = _uopOprSize
        archOprSize = _archOprSize

    def addIo(self, _inputs: list, _outputs: list):
        super().addIo(_inputs, _outputs)
        for idx in range(len(_inputs)):
            self.io_input_metaArgs[idx] = _inputs[idx].genCXX_getFillMetaHelper_forVec\
                                          (self.idxInGrp,self.uopOprSize,self.archOprSize)

        for idx in range(len(_outputs)):
            self.io_output_metaArgs[idx] = _outputs[idx].genCXX_getFillMetaHelper_forVec\
                                          (self.idxInGrp,self.uopOprSize,self.archOprSize)



