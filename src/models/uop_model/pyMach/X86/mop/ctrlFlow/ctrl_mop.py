import base.mop.mop_base as mb
import X86.uop.resMap as resMap
import base.operand.opr_simple as oprs
import X86.mop.cen_mop as mop_cen_x86
import X86.uop.ctrlFlow.ctrl_uop as uop_ctrl_flw_x86


class MOP_CMP_ALL(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, srcOpr0Type, srcOpr1Type, _cxxType_prefix:str, _suggest_comp_class:str, _decKeys: list):

        super().__init__()

        ld0Data = oprLdFrom0, uopLd0, oprLdTo0 = self.initIoOp(srcOpr0Type, oprs.OPR_TEMP, resMap.cxxTypeIO_suggest_INT,
                                                               "oprLdFrom0", "uopLd0", "oprLdTo0", 8, 8
                                                               )
        ld1Data = oprLdFrom1, uopLd1, oprLdTo1 = self.initIoOp(srcOpr1Type, oprs.OPR_TEMP, resMap.cxxTypeIO_suggest_INT,
                                                               "oprLdFrom1", "uopLd1", "oprLdTo1", 8, 8
                                                               )

        if len(oprLdFrom0) != 1 :
            mb.MopUsageError(f"MOP_CMP_ALL operand invalid with value {len(oprLdFrom0)}  value {len(oprLdFrom1)}")

        compUop = uop_ctrl_flw_x86.UOP_CMP("cmp", "IntAlu")
        compUop.addIo([oprLdTo0, oprLdTo1], [])

        ##### add io to prebuilt list
        self.addIoToPreBuiltList(*ld0Data, True)
        self.addIoToPreBuiltList(*ld1Data, True)
        ##### add comp uop to prebuilt list
        self.addUopToPreBuiltList(compUop)

        ##### finalize
        self.finalizeMop("CMP_MOP", _decKeys)

class MOP_JMP_ALL(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, srcOpr0Type, srcOpr1Type, desOpr0Type, _cxxType_prefix:str, _suggest_comp_class:str, _decKeys: list):
        super().__init__()

        ld0Data = oprLdFrom0, uopLd0, oprLdTo0 = self.initIoOp(srcOpr0Type, oprs.OPR_TEMP, resMap.cxxTypeIO_suggest_INT,
                                                               "oprLdFrom0", "uopLd0", "oprLdTo0", 8, 8
                                                               )
        ld1Data = oprLdFrom1, uopLd1, oprLdTo1 = self.initIoOp(srcOpr1Type, oprs.OPR_TEMP, resMap.cxxTypeIO_suggest_INT,
                                                               "oprLdFrom1", "uopLd1", "oprLdTo1", 8, 8
                                                               )

        st1Data = oprStFrom1, uopSt1, oprStTo1 = self.initIoOp(desOpr0Type, oprs.OPR_TEMP, resMap.cxxTypeIO_suggest_INT,
                                                               "oprStFrom1", "uopSt1", "oprStTo1", 8, 8
                                                               )

        if len(oprLdFrom0) != 1:
            mb.MopUsageError(f"MOP_CMP_ALL operand invalid with value {len(oprLdFrom0)}  value {len(oprLdFrom1)}")

        compUop = uop_ctrl_flw_x86.UOP_JMP("cmp", "IntAlu")
        compUop.addIo([oprLdTo0, oprLdTo1], [oprStFrom1])

        ##### add io to prebuilt list
        self.addIoToPreBuiltList(*ld0Data, True)
        self.addIoToPreBuiltList(*ld1Data, True)
        ##### add comp uop to prebuilt list
        self.addUopToPreBuiltList(compUop)
        #### add io to prebuilt list
        self.addIoToPreBuiltList(*st1Data, False)

        ##### finalize
        self.finalizeMop("JMP", _decKeys)