import base.mop.mop_base as mb
import base.operand.opr_simple as oprs
import X86.mop.cen_mop as mop_cen_x86
import X86.uop.alu.comp_uop as uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86
import X86.uop.resMap as resMap


class MOP_MOV_BASE_X86(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, desOpr0Type,
                 cxxTypeIO_suggest: str, _decKeys: list,
                 uopOprSize: int, archOprSize: int):

        super().__init__()

        if (srcOpr0Type not in self.oprBeSrcDesAble) or (desOpr0Type not in self.oprBeSrcDesAble):
            mb.MopUsageError("MOV MOP is get invalid type")

        isLoad = desOpr0Type != oprs.OPR_MEM

        preSrcOprs = [srcOpr0Type("srcOpr", True)]  #### oprBeSrcAble's opr type accepts same construction
        preUops = []
        preDesOprs = [desOpr0Type("desOpr", False)]

        if oprs.OPR_MEM in (srcOpr0Type, desOpr0Type):
            cxxType = resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest, isLoad)
        elif srcOpr0Type == oprs.OPR_IMM:
            cxxType = resMap.cxxTypeUOP_IMM
        else:
            cxxType = resMap.cxxTypeUOP_MOVREG

        for uopIdx in range(self.getAmtUopForEachIo(uopOprSize, archOprSize)):
            uop = uop_mov_x86.UOP_MOV(f"movUop_{uopIdx}", cxxType,
                                      uopIdx, uopOprSize, archOprSize)
            uop.addIo(preSrcOprs, preDesOprs)
            preUops.append(uop)

        self.addIoToPreBuiltList(preSrcOprs, preUops, preDesOprs)

        self.finalizeMop(cxxTypeMop_prefix, _decKeys)
