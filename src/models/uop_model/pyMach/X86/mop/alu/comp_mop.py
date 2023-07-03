import base.mop.mop_base as mb
import base.operand.opr_simple as opr
import  X86.mop.cen_mop     as mop_cen_x86
import X86.uop.alu.comp_uop as  uop_comp_x86

class MOP_COMP_ALL(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type, _cxxType_prefix:str, _suggest_comp_class:str, _decKeys: list):
                                                                                                #### comp class is class execution unit of compute microop
        super().__init__()
        ##### src operand
        srcPreUse0, srcCanUse0, uopUsed0 = self.initSrcLoad(srcOpr0Type, "0", True)
        srcPreUse1, srcCanUse1, uopUsed1 = self.initSrcLoad(srcOpr1Type, "1", True)
        ##### create operand for receive result from uop
        oprFromUop0 = None
        oprFromUop1 = None
        ###### init result operand 0
        if desOpr0Type == opr.OPR_MEM:
            #### needed operand
            oprFromUop0 = opr.OPR_TEMP("preDes_0")
        elif desOpr0Type == opr.OPR_REG:
            #### needed operand
            oprFromUop0 = opr.OPR_REG("r_des_0", False)
        else:
            raise mb.MopUsageError(f"can't build MOP_COMP_ALL with destination to {desOpr0Type}")
        ###### init result operand 1
        if desOpr1Type == opr.OPR_MEM:
            #### needed operand
            oprFromUop1 = opr.OPR_TEMP("preDes_1")
        elif desOpr1Type == opr.OPR_REG:
            #### needed operand
            oprFromUop1 = opr.OPR_REG("r_des_1", False)
        elif desOpr1Type == opr.OPR_DUMMY:
            #### needed operand
            oprFromUop1 = opr.OPR_DUMMY("dummy_output_1")
        else:
            raise mb.MopUsageError(f"can't build MOP_COMP_ALL with destination to {desOpr1Type}")
        ##### create uop for computation
        comp_uop = uop_comp_x86.UOP_COMP("uop_comp", _suggest_comp_class)
        comp_uop.addIo([srcCanUse0, srcCanUse1], [oprFromUop0, oprFromUop1])
        self.uopListSummary.append(comp_uop)
        ##### des operand
        self.initDesStore(oprFromUop0, desOpr0Type, "0", True)
        self.initDesStore(oprFromUop1, desOpr1Type, "1", True)
        ##### init macro op
        self.autoInit(_cxxType_prefix,
                      self.inputListSummary,
                      self.outputListSummary,
                      self.tempListSummary,
                      self.uopListSummary,
                      _decKeys)


class MOP_COMP128_ALL(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, srcOpr0Type, srcOpr1Type, desOpr0Type, desOpr1Type, _cxxType_prefix:str, _suggest_comp_class:str, _decKeys: list):
        super().__init__()
        ##### src operand
        srcPreUse0, srcCanUse0, uopUsed0 = self.initSrcLoad128(srcOpr0Type, "0", True)
        srcPreUse1, srcCanUse1, uopUsed1 = self.initSrcLoad128(srcOpr1Type, "1", True)
        ##### create operand for receive result from uop
        oprFromUop0 = None
        oprFromUop1 = None
        if desOpr0Type == opr.OPR_MEM:
            #### needed operand
            oprFromUop0 = opr.OPR_TEMP("preDes")
        elif desOpr0Type == opr.OPR_REG:
            #### needed operand
            oprFromUop0 = opr.OPR_REG("r_des_0", False)
        else:
            raise mb.MopUsageError(f"can't build MOP_COMP_ALL with destination to {desOpr0Type}")
        ###### init result operand 1
        if desOpr1Type == opr.OPR_MEM:
            #### needed operand
            oprFromUop1 = opr.OPR_TEMP("preDes_1")
        elif desOpr1Type == opr.OPR_REG:
            #### needed operand
            oprFromUop1 = opr.OPR_REG("r_des_1", False)
        elif desOpr1Type == opr.OPR_DUMMY:
            #### needed operand
            oprFromUop1 = opr.OPR_DUMMY("dummy_output_1")
        else:
            raise mb.MopUsageError(f"can't build MOP_COMP_ALL with destination to {desOpr1Type}")
        ##### create uop for computation
        comp_uop_0 = uop_comp_x86.UOP_COMP("uop_comp_0", _suggest_comp_class)
        comp_uop_0.addIo([srcCanUse0, srcCanUse1], [oprFromUop0, oprFromUop1])
        self.uopListSummary.append(comp_uop_0)

        comp_uop_1 = uop_comp_x86.UOP_COMP("uop_comp_1", _suggest_comp_class)
        comp_uop_1.addIo([srcCanUse0, srcCanUse1], [oprFromUop0, oprFromUop1])
        self.uopListSummary.append(comp_uop_1)
        ##### des operand
        self.initDesStore128(oprFromUop0, desOpr0Type, "0", True)
        self.initDesStore128(oprFromUop1, desOpr1Type, "1", True)
        ##### init macro op
        self.autoInit(_cxxType_prefix,
                      self.inputListSummary,
                      self.outputListSummary,
                      self.tempListSummary,
                      self.uopListSummary,
                      _decKeys)