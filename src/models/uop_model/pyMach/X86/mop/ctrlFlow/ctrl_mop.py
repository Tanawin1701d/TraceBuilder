import base.mop.mop_base as mb
import base.operand.opr_simple as opr
import X86.mop.cen_mop as mop_cen_x86
import X86.uop.ctrlFlow.ctrl_uop as uop_ctrl_flw_x86


# class MOP_CMP_ALL(mop_cen_x86.MOP_BASE_X86):
#     def __init__(self, srcOpr0Type, srcOpr1Type, _cxxType_prefix:str, _suggest_comp_class:str, _decKeys: list):
#
#         super().__init__()
#         ###### src operand
#         srcPreUse0, srcCanUse0, uopUsed0 = self.initSrcLoad(srcOpr0Type, "0", True)
#         srcPreUse1, srcCanUse1, uopUsed1 = self.initSrcLoad(srcOpr1Type, "1", True)
#         ###### create uop for compare
#         cmpUop = uop_ctrl_flw_x86.UOP_CMP("uop_cmp", _suggest_comp_class)
#         cmpUop.addIo([srcCanUse0, srcCanUse1], [])
#         cmpUop.addMetaArgs([[], []], [])
#         self.uopListSummary.append(cmpUop)
#         ##### init macro op
#         self.autoInit(_cxxType_prefix,
#                       self.inputListSummary,
#                       self.outputListSummary,
#                       self.tempListSummary,
#                       self.uopListSummary,
#                       _decKeys
#                       )
#
#
# class MOP_JMP_ALL(mop_cen_x86.MOP_BASE_X86):
#     def __init__(self, srcOpr0Type, srcOpr1Type, _cxxType_prefix:str, _suggest_comp_class:str, _decKeys: list):
#         super().__init__()
#         ###### src operand
#         srcPreUse0, srcCanUse0, uopUsed0 = self.initSrcLoad(srcOpr0Type, "0", True)
#         ###### from uop operand assume it is reg
#         desOpr = srcOpr1Type(f"reg_des_1", False)
#         ###### create uop for compare
#         jmpUop = uop_ctrl_flw_x86.UOP_JMP("uop_jmp", _suggest_comp_class)
#         jmpUop.addIo([srcCanUse0], [desOpr])
#         jmpUop.addMetaArgs([[]],[[]])
#         self.uopListSummary.append(jmpUop)
#         ###### des operand
#         desPreUse0, desCanUse0, uopUsed_des = self.initDesStore(desOpr, srcOpr1Type, "0", True)
#         ##### init macro op
#         self.autoInit(_cxxType_prefix,
#                       self.inputListSummary,
#                       self.outputListSummary,
#                       self.tempListSummary,
#                       self.uopListSummary,
#                       _decKeys
#                       )