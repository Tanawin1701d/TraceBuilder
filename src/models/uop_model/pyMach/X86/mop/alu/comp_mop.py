import base.mop.mop_base as mb
import base.operand.opr_simple as oprs
import  X86.mop.cen_mop     as mop_cen_x86
import X86.uop.alu.comp_uop as  uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86




class MOP_COMP_BASE_X86(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                 cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list, uopOprSize:int, archOprSize:int):
        super().__init__()

        ##### init load io
        ld0Data = oprLdFrom0, uopLd0, oprLdTo0 = self.initIoOp(srcOpr0Type, oprs.OPR_TEMP, cxxTypeIO_suggest,
                                                               "oprLdFrom0", "uopLd0", "oprLdTo0", uopOprSize, archOprSize)
        ld1Data = oprLdFrom1, uopLd1, oprLdTo1 = self.initIoOp(srcOpr1Type, oprs.OPR_TEMP, cxxTypeIO_suggest,
                                                               "oprLdFrom1", "uopLd1", "oprLdTo1", uopOprSize, archOprSize)

        ##### init store io
        st0Data = oprStFrom0, uopSt0, oprStTo0 = self.initIoOp(oprs.OPR_TEMP, desOpr0Type, cxxTypeIO_suggest,
                                                               "oprStFrom0", "uopSt0", "oprStTo0", uopOprSize, archOprSize)
        st1Data = oprStFrom1, uopSt1, oprStTo1 = self.initIoOp(oprs.OPR_TEMP, desOpr1Type, cxxTypeIO_suggest,
                                                               "oprStFrom1", "uopSt1", "oprStTo1", uopOprSize, archOprSize)

        if len(oprLdTo0) != len(oprLdTo1) or len(oprStFrom0) != len(oprStFrom1) or len(oprLdTo0) != len(oprStFrom0):
            mb.MopUsageError("error simd opr count error")

        neededComp = list()
        ##### init comp
        for idx, inOpr0, inOpr1, resOpr0, resOpr1 in enumerate(zip(oprLdTo0, oprLdTo1, oprStFrom0, oprStFrom1)):
            compUop = self.initCompOp(inOpr0, inOpr1, resOpr0, resOpr1,
                                      f"compUop_{idx}", cxxTypeCompUop_prefix,
                                      idx, uopOprSize, archOprSize,
                                      idx, uopOprSize, archOprSize
                                      )
            neededComp.append(compUop)



        ###### add to preBuilt List
        self.addIoToPreBuiltList(*ld0Data, True)
        self.addIoToPreBuiltList(*ld1Data, True)

        for compUop in neededComp:
            self.addUopToPreBuiltList(compUop)

        self.addIoToPreBuiltList(*st0Data, False)
        self.addIoToPreBuiltList(*st1Data, False)

        ####### finalize mop
        self.finalizeMop(cxxTypeMop_prefix, _decKeys)



class MOP_COMP_128_BASE_X86(MOP_COMP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list):

        super().__init__(cxxTypeMop_prefix, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix, cxxTypeIO_suggest, _decKeys, 8, 16)

class MOP_COMP_64_BASE_X86(MOP_COMP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                 cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list):
        super().__init__(cxxTypeMop_prefix, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                         cxxTypeCompUop_prefix, cxxTypeIO_suggest, _decKeys, 8, 8)