#import base.mop.mop_base as mb
import X86.uop.resMap as resMap
import base.operand.opr_simple as oprs
import X86.mop.cen_mop as mop_cen_x86
import X86.uop.ctrlFlow.ctrl_uop as uop_ctrl_flw_x86


class MOP_CMP_ALL(mop_cen_x86.MOP_BASE_X86):
    def __init__(self,  _cxxType_prefix:str, srcOpr0Type, srcOpr1Type, comp_class:str, _decKeys: list):

        super().__init__()

        oprForGetRip = [oprs.OPR_DUMMY("dummyRipOpr")]
        if self.areThereMipNeed([srcOpr0Type, srcOpr1Type]):
            ldRipOpr, ldUop, oprForGetRip = self.initRdInstrPtr("ldRip", "ripLoader", "desRip")
            self.PREBUILT_uopList.append(ldUop[0])
            self.PREBUILT_temOprList.append(ldRipOpr[0])
            self.PREBUILT_temOprList.append(oprForGetRip[0])

        ld0Data  = self.initIoOp(srcOpr0Type, oprs.OPR_TEMP, oprForGetRip[0], resMap.cxxTypeIO_suggest_INT,
                                                               "oprLdFrom0", "uopLd0", "oprLdTo0", 8, 8
                                                               )
        ld1Data  = self.initIoOp(srcOpr1Type, oprs.OPR_TEMP, oprForGetRip[0], resMap.cxxTypeIO_suggest_INT,
                                                               "oprLdFrom1", "uopLd1", "oprLdTo1", 8, 8
                                                               )

        ######## uop
        compUop = uop_ctrl_flw_x86.UOP_CMP("cmp", comp_class)
        inOpr0 = self.getIoForCompFromInitIo(*ld0Data, 0, True)
        inOpr1 = self.getIoForCompFromInitIo(*ld1Data, 0, True)
        compUop.addIo([inOpr0, inOpr1], [])

        ##### add io to prebuilt list
        self.addIoToPreBuiltList(*ld0Data)
        self.addIoToPreBuiltList(*ld1Data)
        ##### add comp uop to prebuilt list
        self.addUopToPreBuiltList(compUop)

        ##### finalize
        self.finalizeMop("CMP_MOP", _decKeys)

class MOP_JMP_ALL(mop_cen_x86.MOP_BASE_X86):
    def __init__(self,  cxxTypeMop_prefix:str, srcOpr0Type, srcOpr1Type, desOpr0Type,
                        cxxTypeCompUop_prefix:str, _decKeys: list):
        super().__init__()


        oprForGetRip = [oprs.OPR_DUMMY("dummyRipOpr")]
        if self.areThereMipNeed([srcOpr0Type, srcOpr1Type]):
            ldRipOpr, ldUop, oprForGetRip = self.initRdInstrPtr("ldRip", "ripLoader", "desRip")
            self.PREBUILT_uopList.append(ldUop[0])
            self.PREBUILT_temOprList.append(ldRipOpr[0])
            self.PREBUILT_temOprList.append(oprForGetRip[0])

        ld0Data  = self.initIoOp(srcOpr0Type, oprs.OPR_TEMP, oprForGetRip[0], resMap.cxxTypeIO_suggest_INT,
                                                               "oprLdFrom0", "uopLd0", "oprLdTo0", 8, 8
                                                               )
        ld1Data  = self.initIoOp(srcOpr1Type, oprs.OPR_TEMP, oprForGetRip[0], resMap.cxxTypeIO_suggest_INT,
                                                               "oprLdFrom1", "uopLd1", "oprLdTo1", 8, 8
                                                               )

        st1Data  = self.initIoOp(oprs.OPR_TEMP, desOpr0Type,  oprForGetRip[0], resMap.cxxTypeIO_suggest_INT,
                                                               "oprStFrom1", "uopSt1", "oprStTo1", 8, 8
                                                               )


        ######## uop
        compUop = uop_ctrl_flw_x86.UOP_JMP("jmp", cxxTypeCompUop_prefix)
        inOpr0 = self.getIoForCompFromInitIo(*ld0Data, 0, True)
        inOpr1 = self.getIoForCompFromInitIo(*ld1Data, 0, True)
        otOpr = self.getIoForCompFromInitIo(*st1Data, 0, False)
        compUop.addIo([inOpr0, inOpr1], [otOpr])

        ##### add io to prebuilt list
        self.addIoToPreBuiltList(*ld0Data)
        self.addIoToPreBuiltList(*ld1Data)
        ##### add comp uop to prebuilt list
        self.addUopToPreBuiltList(compUop)
        #### add io to prebuilt list
        self.addIoToPreBuiltList(*st1Data)

        ##### finalize
        self.finalizeMop(cxxTypeMop_prefix, _decKeys)