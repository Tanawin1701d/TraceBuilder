#import base.mop.mop_base as mb
import base.operand.opr_simple as oprs
import  X86.mop.cen_mop     as mop_cen_x86
#import X86.uop.alu.comp_uop as  uop_comp_x86
#import X86.uop.mov.dataMov_uop as uop_mov_x86


class MOP_COMP_SEMI_BASE_X86(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                 cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list, uopOprSize: int, archOprSize: int):
        super().__init__()

        oprForGetRip = [oprs.OPR_DUMMY("dummyRipOpr")]
        if self.areThereMipNeed([srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type]):
            ldRipOpr, ldUop, oprForGetRip = self.initRdInstrPtr("ldRip", "ripLoader", "desRip")
            self.PREBUILT_uopList.append(ldUop[0])
            self.PREBUILT_temOprList.append(ldRipOpr[0])
            self.PREBUILT_temOprList.append(oprForGetRip[0])

        ##### init load io
        ld0Data = self.initIoOp(srcOpr0Type, oprs.OPR_TEMP, oprForGetRip[0], cxxTypeIO_suggest,
                                                               "oprLdFrom0", "uopLd0", "oprLdTo0", self.MAX_LEGACY_OPR_SIZE, self.MAX_LEGACY_OPR_SIZE)
        ld1Data = self.initIoOp(srcOpr1Type, oprs.OPR_TEMP, oprForGetRip[0], cxxTypeIO_suggest,
                                                               "oprLdFrom1", "uopLd1", "oprLdTo1", self.MAX_LEGACY_OPR_SIZE, self.MAX_LEGACY_OPR_SIZE)

        ##### init store io
        st0Data = self.initIoOp(oprs.OPR_TEMP, desOpr0Type, oprForGetRip[0], cxxTypeIO_suggest,
                                                               "oprStFrom0", "uopSt0", "oprStTo0", self.MAX_LEGACY_OPR_SIZE, self.MAX_LEGACY_OPR_SIZE)
        st1Data = self.initIoOp(oprs.OPR_TEMP, desOpr1Type, oprForGetRip[0], cxxTypeIO_suggest,
                                                               "oprStFrom1", "uopSt1", "oprStTo1", self.MAX_LEGACY_OPR_SIZE, self.MAX_LEGACY_OPR_SIZE)

        neededComp = list()
        ##### init comp
        for idx in range(self.getAmtUopForEachIo(uopOprSize, archOprSize)):
            inOpr0 = self.getIoForCompFromInitIo (*ld0Data, 0,  True)
            inOpr1 = self.getIoForCompFromInitIo (*ld1Data, 0,  True)
            resOpr0 = self.getIoForCompFromInitIo(*st0Data, 0,  False)
            resOpr1 = self.getIoForCompFromInitIo(*st1Data, 0,  False)

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




class MOP_COMP_SEMI128_BASE_X86(MOP_COMP_SEMI_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list):

        super().__init__(cxxTypeMop_prefix, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix, cxxTypeIO_suggest, _decKeys, 8, 16)

class MOP_COMP_SEMI256_BASE_X86(MOP_COMP_SEMI_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list):

        super().__init__(cxxTypeMop_prefix, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix, cxxTypeIO_suggest, _decKeys, 8, 32)