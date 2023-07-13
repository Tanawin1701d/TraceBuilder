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
        ld0Data = self.initIoOp(srcOpr0Type, oprs.OPR_TEMP, cxxTypeIO_suggest,
                                                               "oprLdFrom0", "uopLd0", "oprLdTo0", uopOprSize, archOprSize)
        ld1Data = self.initIoOp(srcOpr1Type, oprs.OPR_TEMP, cxxTypeIO_suggest,
                                                               "oprLdFrom1", "uopLd1", "oprLdTo1", uopOprSize, archOprSize)

        ##### init store io
        st0Data = self.initIoOp(oprs.OPR_TEMP, desOpr0Type, cxxTypeIO_suggest,
                                                               "oprStFrom0", "uopSt0", "oprStTo0", uopOprSize, archOprSize)
        st1Data = self.initIoOp(oprs.OPR_TEMP, desOpr1Type, cxxTypeIO_suggest,
                                                               "oprStFrom1", "uopSt1", "oprStTo1", uopOprSize, archOprSize)

        neededComp = list()
        ##### init comp
        for idx in range(self.getAmtUopForEachIo(uopOprSize, archOprSize)):
            inOpr0 = self.getIoForCompFromInitIo(*ld0Data, idx,  True)
            inOpr1 = self.getIoForCompFromInitIo(*ld1Data, idx,  True)
            resOpr0 = self.getIoForCompFromInitIo(*st0Data, idx,  False)
            resOpr1 = self.getIoForCompFromInitIo(*st1Data, idx,  False)

            compUop = self.initCompOp(inOpr0, inOpr1, resOpr0, resOpr1,
                                      f"compUop_{idx}", cxxTypeCompUop_prefix,
                                      idx, uopOprSize, archOprSize,
                                      idx, uopOprSize, archOprSize
                                      )
            neededComp.append(compUop)



        ###### add to preBuilt List
        self.addIoToPreBuiltList(*ld0Data)
        self.addIoToPreBuiltList(*ld1Data)

        for compUop in neededComp:
            self.addUopToPreBuiltList(compUop)

        self.addIoToPreBuiltList(*st0Data)
        self.addIoToPreBuiltList(*st1Data)

        ####### finalize mop
        self.finalizeMop(cxxTypeMop_prefix, _decKeys)



class MOP_COMP_128_BASE_X86(MOP_COMP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list):

        super().__init__(cxxTypeMop_prefix, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix, cxxTypeIO_suggest, _decKeys, 8, 16)

class MOP_COMP_256_BASE_X86(MOP_COMP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list):

        super().__init__(cxxTypeMop_prefix, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix, cxxTypeIO_suggest, _decKeys, 8, 32)

class MOP_COMP_64_BASE_X86(MOP_COMP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                 cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list):
        super().__init__(cxxTypeMop_prefix, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                         cxxTypeCompUop_prefix, cxxTypeIO_suggest, _decKeys, 8, 8)