import base.mop.mop_base as mb
import base.operand.opr_simple as oprs
import X86.mop.cen_mop as mop_cen_x86
import X86.uop.alu.comp_uop as uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86
import X86.uop.resMap as resMap


class MOP_MOV_BASE_X86(mop_cen_x86.MOP_BASE_X86):
    def __init__(self, cxxTypeMop_prefix: str, srcOpr0Type, desOpr0Type,
                 cxxTypeIO_suggest: str, _decKeys: list,
                 srcUopOprSize: int, srcArchOprSize: int):

        super().__init__()

        if (srcOpr0Type not in self.oprBeSrcDesAble) or (desOpr0Type not in self.oprBeSrcDesAble):
            mb.MopUsageError("MOV MOP is get invalid type")

        preSrcOprs  = [srcOpr0Type("srcOpr", True)]  #### oprBeSrcAble's opr type accepts same construction
        preTempOprs = []
        preUops     = []
        preDesOprs  = [desOpr0Type("desOpr", False)]

        isLoad = srcOpr0Type == oprs.OPR_MEM

        for i in range(self.getAmtUopForEachIo(srcUopOprSize, srcArchOprSize)):
            uop = uop_mov_x86.UOP_MOV(f"ld_{i}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest, isLoad),
                                      i, srcUopOprSize, srcArchOprSize
                                      )
            preUops.append(uop)

            if desOpr0Type == oprs.OPR_MEM:
                tpOpr = oprs.OPR_TEMP(f"ld_to_{i}")
                uop.addIo(preSrcOprs, [tpOpr])
                preTempOprs.append(tpOpr)
            else:
                uop.addIo(preSrcOprs, preDesOprs)

        ######### in case we need to send temp to memory

        if desOpr0Type == oprs.OPR_MEM:
            for i in range(self.getAmtUopForEachIo(srcUopOprSize, srcArchOprSize)):
                uop = uop_mov_x86.UOP_MOV(f"st_{i}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest, True),
                                          i, srcUopOprSize, srcArchOprSize
                                          )
                preUops.append(uop)
                uop.addIo([preTempOprs[0]], preDesOprs)
        elif len(preTempOprs) > 0:
            mb.MopUsageError("mov mop with temp reg use must be store to some where")


        ##### manually add to prebuilt list
        self.PREBUILT_inputOprList  = preSrcOprs
        self.PREBUILT_uopList       = preUops
        self.PREBUILT_temOprList    = preTempOprs
        self.PREBUILT_outputOprList = preDesOprs

        self.finalizeMop(cxxTypeMop_prefix, _decKeys)
