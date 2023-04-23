import base.mop.mop_base as mb
import base.operand.opr_simple as opr
import X86.uop.alu.comp_uop as  uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86

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