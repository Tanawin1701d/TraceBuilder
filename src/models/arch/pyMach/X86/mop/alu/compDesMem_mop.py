import base.mop.mop_base as mb
import base.operand.opr_simple as opr
import X86.uop.alu.comp_uop as  uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86


class MOP_COMP_ALL(mb.MOP_BASE):

    uopVarUsedCount = 0
    srcVarUsedCount = 0
    tempvarUsedCount = 0

    def initSrcLoad(self, srcOprType):
        #        v------------ operand that need to load first
        #              v----- operand that ready to inject to compute unit
        res = (None, None, None) # <------- uop that use for loading
        if srcOprType == opr.OPR_REG or srcOprType == opr.OPR_TEMP:
            srcRegOpr = srcOprType(f"r_src_{str(self.srcVarUsedCount)}", True)
            res =  (None, srcRegOpr, None)
            self.srcVarUsedCount = self.srcVarUsedCount + 1
        elif srcOprType == opr.OPR_MEM or srcOprType == opr.OPR_IMM:

            cxxType, execUnit, memLoad = ("MEM_LOAD", 100, True ) if srcOprType == opr.OPR_MEM else \
                                         ("IMM_LOAD", 102, False)

            ####### create related uop to load value from src
            srcOpr     = srcOprType(f"m_src_{str(self.srcVarUsedCount)}", True) if memLoad else \
                         srcOprType(f"i_src_{str(self.srcVarUsedCount)}"      )
            desTempOpr =  opr.OPR_TEMP(f"t_{str(self.tempvarUsedCount)}")

            relatedUop = uop_mov_x86.UOP_MOV(f"uop_ld_{self.uopVarUsedCount}",
                                             cxxType,
                                             execUnit
                                             )
            relatedUop.addIo([srcOpr], [desTempOpr])

            self.uopVarUsedCount  = self.uopVarUsedCount  + 1
            self.srcVarUsedCount  = self.srcVarUsedCount  + 1
            self.tempvarUsedCount = self.tempvarUsedCount + 1

            res = (srcOpr, desTempOpr, relatedUop)
        else:
            raise mb.MopUsageError(f"invalid src operand for mop generating@initSrcLoad got {srcOprType}")

        return res




    def __init__(self, srcOpr0Type, srcOpr1Type, desOpr0Type, compUnit:str):

        ####### reserve uop

        ##### src operand
        srcPreUse0, srcCanUse0, uopUsed0 = self.initSrcLoad(srcOpr0Type)
        srcPreUse1, srcCanUse1, uopUsed1 = self.initSrcLoad(srcOpr1Type)

        ##### computation

        ##### des operand
        desOprFromUop = None
        desNeededOpr

        if desOpr0Type == opr.OPR_MEM:
            desOprFromUop = opr.OPR_TEMP(f"t_{str(self.tempvarUsedCount)}")
            self.tempvarUsedCount = self.tempvarUsedCount + 1

        compUop = uop_comp_x86.UOP_COMP(f"uop_comp_{self.uopVarUsedCount}", compUnit)

        compUop.addIo([srcCanUse0, srcCanUse1], [])

        self.uopVarUsedCount = self.uopVarUsedCount + 1

        if desOpr0Type == opr.OPR_MEM:
            pass
        elif desOpr0Type == opr.OPR_REG:
            pass


class MOP_COMP_R_R_M(mb.MOP_BASE):

    def __init__(self):
        ####### build system
        oprR1   = opr.OPR_REG("r1", True)
        oprR2   = opr.OPR_REG("r2", True)
        oprPRERDES = opr.OPR_TEMP("rdes")
        oprSt   = opr.OPR_MEM("stdes", False)

        compUop = uop_comp_x86.UOP_COMP("alu_uop"); compUop.addIo([oprR1, oprR2], [oprPRERDES])
        stUop   = uop_mov_x86.UOP_MOV("st_uop"); stUop.addIo([oprPRERDES], [oprSt])

        ###### add to system
        self.autoInit("MOP_COMP", [oprR1, oprR2], [oprSt], [oprPRERDES], [compUop, stUop])


class MOP_COMP_R_M_M(mb.MOP_BASE):

    def __init__(self):
        ####### build system
        oprR1   = opr.OPR_REG("r1", True)
        oprM1   = opr.OPR_MEM("m1", True)
        oprT1   = opr.OPR_TEMP("t1")
        oprPRERDES = opr.OPR_TEMP("rdes")
        oprSt   = opr.OPR_MEM("stdes", False)


        movUop  = uop_mov_x86.UOP_MOV("mov_Uop");   movUop .addIo([oprM1], [oprT1])
        compUop = uop_comp_x86.UOP_COMP("alu_uop"); compUop.addIo([oprR1, oprT1], [oprPRERDES])
        stUop   = uop_mov_x86.UOP_MOV("st_uop"); stUop.addIo([oprPRERDES], [oprSt])


        ###### add to system
        self.autoInit("MOP_COMP", [oprR1, oprM1], [oprSt], [oprT1,oprPRERDES], [movUop,compUop,stUop])

class MOP_COMP_R_I_M(mb.MOP_BASE):

    def __init__(self):
        ####### build system
        oprR1   = opr.OPR_REG("r1", True)
        oprI1   = opr.OPR_IMM("i1"      )
        oprT1   = opr.OPR_TEMP("t1")
        oprPRERDES = opr.OPR_TEMP("rdes")
        oprSt   = opr.OPR_MEM("stdes", False)


        movUop  = uop_mov_x86.UOP_MOV("mov_Uop")  ; movUop .addIo([oprI1], [oprT1])
        compUop = uop_comp_x86.UOP_COMP("alu_uop"); compUop.addIo([oprR1, oprT1], [oprPRERDES])
        stUop   = uop_mov_x86.UOP_MOV("st_uop"); stUop.addIo([oprPRERDES], [oprSt])

        ###### add to system
        self.autoInit("MOP_COMP", [oprR1, oprI1], [oprSt], [oprT1, oprPRERDES], [movUop, compUop, stUop])

class MOP_COMP_M_I_M(mb.MOP_BASE):

    def __init__(self):
        ####### build system
        oprM1   = opr.OPR_MEM("m1", True)
        oprT1   = opr.OPR_TEMP("t1")
        opr_I2  = opr.OPR_IMM("i2")
        oprT2   = opr.OPR_TEMP("t2")
        oprPRERDES = opr.OPR_TEMP("rdes")
        oprSt   = opr.OPR_MEM("stdes", False)


        movUop  = uop_mov_x86.UOP_MOV("mov_Uop") ;  movUop .addIo([oprM1], [oprT1])
        movUop2 = uop_mov_x86.UOP_MOV("mov_Uop2");  movUop2.addIo([opr_I2], [oprT2])
        compUop = uop_comp_x86.UOP_COMP("alu_uop"); compUop.addIo([oprT1, oprT2], [oprPRERDES])
        stUop   = uop_mov_x86.UOP_MOV("st_uop"); stUop.addIo([oprPRERDES], [oprSt])


        ###### add to system
        self.autoInit("MOP_COMP", [oprM1, opr_I2], [oprSt], [oprT1, oprT2, oprPRERDES], [movUop, movUop2, compUop, stUop])

class MOP_COMP_M_M_M(mb.MOP_BASE):

    def __init__(self):
        ####### build system
        oprM1   = opr.OPR_MEM("m1", True)
        oprT1   = opr.OPR_TEMP("t1")
        opr_M2  = opr.OPR_MEM("i2", True)
        oprT2   = opr.OPR_TEMP("t2")
        oprPRERDES = opr.OPR_TEMP("rdes")
        oprSt   = opr.OPR_MEM("stdes", False)


        movUop  = uop_mov_x86.UOP_MOV("mov_Uop") ;  movUop .addIo([oprM1], [oprT1])
        movUop2 = uop_mov_x86.UOP_MOV("mov_Uop2");  movUop2.addIo([opr_M2], [oprT2])
        compUop = uop_comp_x86.UOP_COMP("alu_uop"); compUop.addIo([oprT1, oprT2], [oprPRERDES])
        stUop   = uop_mov_x86.UOP_MOV("st_uop"); stUop.addIo([oprPRERDES], [oprSt])


        ###### add to system
        self.autoInit("MOP_COMP", [oprM1, opr_M2], [oprSt], [oprT1, oprT2, oprPRERDES], [movUop,movUop2,compUop,stUop])