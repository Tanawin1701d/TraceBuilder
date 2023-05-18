import base.mop.mop_base as mb
import base.operand.opr_simple as opr
import  X86.mop.cen_mop     as mop_cen_x86
import X86.uop.alu.comp_uop as  uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86

class MOP_MOV_ALL(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, srcOpr0Type, desOpr0Type, _cxxType_prefix:str):

        #### load the value
        if srcOpr0Type in [opr.OPR_IMM, opr.OPR_MEM]:
            memLoad = srcOpr0Type == opr.OPR_MEM

            ####### create related operand
            srcOpr = opr.OPR_MEM(f"m_src_0", True) if memLoad else \
                     opr.OPR_IMM(f"i_src_0")
            tempOpr = opr.OPR_TEMP(f"t_0")
            desOpr  = desOpr0Type(f"x_des_0", False) ##### Flase is des for reg and mem
            ####### create related uop
            loadUop = uop_mov_x86.UOP_MOV(f"uop_ld_0", "MOV")
            if desOpr0Type == opr.OPR_MEM:
                loadUop.addIo([srcOpr], [tempOpr])
                storeUop = uop_mov_x86.UOP_MOV(f"uop_st_0", "MOV")
                storeUop.addIo([tempOpr], [desOpr])
                #### crucial
                self.autoInit(_cxxType_prefix, [srcOpr], [desOpr], [tempOpr],[loadUop, storeUop])
            else: ### supposed to reg operand
                loadUop.addIo([srcOpr], [desOpr])
                #### crucial
                self.autoInit(_cxxType_prefix, [srcOpr], [desOpr], [], [loadUop])

        elif srcOpr0Type == opr.OPR_REG:
            srcOpr  = opr.OPR_REG("r_src_0", True)
            desOpr  = desOpr0Type("x_des_0", False)
            storeUop = uop_mov_x86.UOP_MOV(f"uop_st_0", "MOV")
            storeUop.addIo([srcOpr], desOpr)
            self.autoInit(_cxxType_prefix, [srcOpr], [desOpr], [], [storeUop])