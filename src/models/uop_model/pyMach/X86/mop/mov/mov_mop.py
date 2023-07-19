import base.mop.mop_base as mb
import base.operand.opr_simple as oprs
import X86.mop.cen_mop as mop_cen_x86
import X86.operand.opr as x86_opr
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

        ######## get rip
        oprForGetRip = [oprs.OPR_DUMMY("dummyRipOpr")]
        if self.areThereMipNeed([srcOpr0Type, desOpr0Type]):
            ldRipOpr, ldUop, oprForGetRip = self.initRdInstrPtr("ldRip", "ripLoader", "desRip")
            self.PREBUILT_uopList.append(ldUop[0])
            self.PREBUILT_temOprList.append(ldRipOpr[0])
            self.PREBUILT_temOprList.append(oprForGetRip[0])
        ###########################################################################################

        srcOprs  = [srcOpr0Type("src_single", True)]
        tempOprs = []
        compUops = []
        desOprs  = [desOpr0Type("des_single", False)]

        amtRep = self.getAmtUopForEachIo(srcUopOprSize, srcArchOprSize)

        srcTempOprRip = oprForGetRip[0] if srcOpr0Type == x86_opr.OPR_MEM_W_IPR else oprs.OPR_DUMMY("dumySrc")
        desTempOprRip = oprForGetRip[0] if desOpr0Type == x86_opr.OPR_MEM_W_IPR else oprs.OPR_DUMMY("dumyDes")

        if srcOpr0Type == oprs.OPR_IMM or (srcOpr0Type in self.memOprAble):

            if desOpr0Type in self.memOprAble:

                ################
                ##### IMM TO MEM
                ################
                ######## get move to temporary register first
                for i in range(amtRep):
                    tempOpr = oprs.OPR_TEMP(f"tm_{i}")
                    uop = uop_mov_x86.UOP_MOV(f"ld_{i}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest, srcOpr0Type, oprs.OPR_TEMP), i, srcUopOprSize, srcArchOprSize)
                    uop.addIo([*srcOprs, srcTempOprRip], [tempOpr])
                    tempOprs.append(tempOpr)
                    compUops.append(uop)
                ####### get move from tem reg to mem
                for i in range(amtRep):
                    uop = uop_mov_x86.UOP_MOV(f"st_{i}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest, oprs.OPR_TEMP, oprs.OPR_MEM), i, srcUopOprSize, srcArchOprSize)
                    uop.addIo([tempOprs[i], desTempOprRip], desOprs)
                    compUops.append(uop)

                ######## get move to mem
            elif desOpr0Type == oprs.OPR_REG:
                ################
                #### IMM TO REG
                ################
                for i in range(amtRep):
                    uop = uop_mov_x86.UOP_MOV(f"to_{i}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest, srcOpr0Type, oprs.OPR_REG), i, srcUopOprSize, srcArchOprSize)
                    uop.addIo([*srcOprs, srcTempOprRip], desOprs)
                    compUops.append(uop)

        elif srcOpr0Type == oprs.OPR_REG:
                for i in range(amtRep):
                    #### TO REG OR MEM

                    uop = uop_mov_x86.UOP_MOV(f"to_{i}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest, srcOpr0Type, desOpr0Type), i, srcUopOprSize, srcArchOprSize)
                    uop.addIo([*srcOprs, desTempOprRip], desOprs)
                    compUops.append(uop)


        ##### manually add to prebuilt list
        self.PREBUILT_inputOprList  = self.PREBUILT_inputOprList + srcOprs
        self.PREBUILT_uopList       = self.PREBUILT_uopList + compUops
        self.PREBUILT_temOprList    = self.PREBUILT_temOprList + tempOprs
        self.PREBUILT_outputOprList = self.PREBUILT_outputOprList + desOprs

        self.finalizeMop(cxxTypeMop_prefix, _decKeys)
