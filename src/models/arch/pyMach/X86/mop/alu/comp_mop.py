import base.mop.mop_base as mb
import base.operand.opr_simple as opr
import  X86.mop.cen_mop     as mop_cen_x86
import X86.uop.alu.comp_uop as  uop_comp_x86
#import X86.uop.mov.dataMov_uop as uop_mov_x86


class MOP_COMP_ALL(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, srcOpr0Type, srcOpr1Type, desOpr0Type, _cxxType_prefix:str):
        ##### src operand
        srcPreUse0, srcCanUse0, uopUsed0 = self.initSrcLoad(srcOpr0Type, "0", True)
        srcPreUse1, srcCanUse1, uopUsed1 = self.initSrcLoad(srcOpr1Type, "1", True)
        ##### create operand for receive result from uop
        oprFromUop = None
        if desOpr0Type == opr.OPR_MEM:
            #### needed operand
            oprFromUop = opr.OPR_TEMP("preDes")
        elif desOpr0Type == opr.OPR_REG:
            #### needed operand
            oprFromUop = opr.OPR_REG("r_des_0", False)
        else:
            raise mb.MopUsageError(f"can't build MOP_COMP_ALL with destination to {desOpr0Type}")
        ##### create uop for computation
        comp_uop = uop_comp_x86.UOP_COMP("uop_comp", _cxxType_prefix)
        comp_uop.addIo([srcCanUse0, srcCanUse1], [oprFromUop])
        ##### des operand
        self.initDesStore(oprFromUop, desOpr0Type, "0", True)
        ##### init macro op
        self.autoInit(_cxxType_prefix,
                      self.inputListSummary,
                      self.outputListSummary,
                      self.tempListSummary,
                      self.uopListSummary)