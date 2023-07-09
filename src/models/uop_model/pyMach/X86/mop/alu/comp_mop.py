import base.mop.mop_base as mb
import base.operand.opr_simple as oprs
import  X86.mop.cen_mop     as mop_cen_x86
import X86.uop.alu.comp_uop as  uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86


# class MOP_COMP(mb.MOP_BASE):
#     def __init__(self):
#         super().__init__()
#         loadOpr1 = opr.OPR_MEM("loadOpr1", True)
#         tempOpr1 = opr.OPR_TEMP("loadTemp1")
#
#         u_mov1 = uop_mov_x86.UOP_MOV("testLoadUop", "MOVCXX")
#         u_mov1.addIo([loadOpr1], [tempOpr1])
#         u_mov1.addMetaArgs([["0", "4"]],[["false"]])
#
#         regLd = opr.OPR_REG("regOprload", False)
#         stOpr1 = opr.OPR_REG("storeOpr1",False)
#         u_comp1 = uop_comp_x86.UOP_COMP("testCompUop", "COMPUOP")
#         u_comp1.addIo([tempOpr1, regLd], [stOpr1, opr.OPR_DUMMY("ddd")])
#         u_comp1.addMetaArgs([["false"], []], [[], []])
#
#
#         self.autoInit("MPREFIX",
#                                [loadOpr1, regLd],
#                                [stOpr1         ],
#                                [tempOpr1       ],
#                                [u_mov1, u_comp1],
#                                ["mydecKey"     ])


class MOP_COMP_ALL(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                 cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list):
        super().__init__()

        ##### init load io
        ld0Data = oprLdFrom0, uopLd0, oprLdTo0 = self.initIoOp(srcOpr0Type, oprs.OPR_TEMP, cxxTypeIO_suggest, "oprLdFrom0", "uopLd0", "oprLdTo0")
        ld1Data = oprLdFrom1, uopLd1, oprLdTo1 = self.initIoOp(srcOpr1Type, oprs.OPR_TEMP, cxxTypeIO_suggest, "oprLdFrom1", "uopLd1", "oprLdTo1")

        ##### init store io
        st0Data = oprStFrom0, uopSt0, oprStTo0 = self.initIoOp(oprs.OPR_TEMP, desOpr0Type, cxxTypeIO_suggest, "oprStFrom0", "uopSt0", "oprStTo0")
        st1Data = oprStFrom1, uopSt1, oprStTo1 = self.initIoOp(oprs.OPR_TEMP, desOpr1Type, cxxTypeIO_suggest, "oprStFrom1", "uopSt1", "oprStTo1")

        ##### init comp
        compUop = self.initCompOp(oprLdTo0, oprLdTo1, oprStFrom0, oprStFrom1,"compUop", cxxTypeCompUop_prefix, False)


        ###### add to preBuilt List
        self.addIoToPreBuiltList(*ld0Data, True)
        self.addIoToPreBuiltList(*ld1Data, True)

        self.addUopToPreBuiltList(compUop)

        self.addIoToPreBuiltList(*st0Data, False)
        self.addIoToPreBuiltList(*st1Data, False)

        ####### finalize mop
        self.finalizeMop(cxxTypeMop_prefix, _decKeys)

class MOP_COMP_128(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type,
                       cxxTypeCompUop_prefix: str, cxxTypeIO_suggest: str, _decKeys: list):
        super().__init__()

        ##### init load io
        ld0Data = oprLdFrom0, uopLd0, oprLdTo0 = self.initIoOp(srcOpr0Type, oprs.OPR_TEMP, cxxTypeIO_suggest, "oprLdFrom0", "uopLd0", "oprLdTo0")
        ld1Data = oprLdFrom1, uopLd1, oprLdTo1 = self.initIoOp(srcOpr1Type, oprs.OPR_TEMP, cxxTypeIO_suggest, "oprLdFrom1", "uopLd1", "oprLdTo1")

        ##### init store io
        st0Data = oprStFrom0, uopSt0, oprStTo0 = self.initIoOp(oprs.OPR_TEMP, desOpr0Type, cxxTypeIO_suggest, "oprStFrom0", "uopSt0", "oprStTo0")
        st1Data = oprStFrom1, uopSt1, oprStTo1 = self.initIoOp(oprs.OPR_TEMP, desOpr1Type, cxxTypeIO_suggest, "oprStFrom1", "uopSt1", "oprStTo1")

        ##### init comp
        compUop = self.initCompOp(oprLdTo0, oprLdTo1, oprStFrom0, oprStFrom1,"compUop", cxxTypeCompUop_prefix, False)


        ###### add to preBuilt List
        self.addIoToPreBuiltList(*ld0Data, True)
        self.addIoToPreBuiltList(*ld1Data, True)

        self.addUopToPreBuiltList(compUop)

        self.addIoToPreBuiltList(*st0Data, False)
        self.addIoToPreBuiltList(*st1Data, False)

        ####### finalize mop
        self.finalizeMop(cxxTypeMop_prefix, _decKeys)