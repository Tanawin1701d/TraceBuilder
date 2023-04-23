import base.mop.mop_base as mb
import base.operand.opr_simple as opr
import X86.uop.alu.comp_uop as  uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86

class MOP_COMP_R_R_R(mb.MOP_BASE):

    def __init__(self):
        ####### build system
        oprR1   = opr.OPR_REG("r1", True)
        oprR2   = opr.OPR_REG("r2", True)
        oprRDES = opr.OPR_REG("rdes", False)

        compUop = uop_comp_x86.UOP_COMP("alu_uop"); compUop.addIo([oprR1, oprR2], [oprRDES])

        ###### add to system
        self.autoInit("MOP_COMP", [oprR1, oprR2], [oprRDES], [], [compUop])


class MOP_COMP_R_M_R(mb.MOP_BASE):

    def __init__(self):
        ####### build system
        oprR1   = opr.OPR_REG("r1", True)
        oprM1   = opr.OPR_MEM("m1", True)
        oprT1   = opr.OPR_TEMP("t1")
        oprRDES = opr.OPR_REG("rdes", False)

        movUop  = uop_mov_x86.UOP_MOV("mov_Uop");   movUop .addIo([oprM1], [oprT1])
        compUop = uop_comp_x86.UOP_COMP("alu_uop"); compUop.addIo([oprR1, oprT1], [oprRDES])

        ###### add to system
        self.autoInit("MOP_COMP", [oprR1, oprM1], [oprRDES], [oprT1], [movUop, compUop])

class MOP_COMP_R_I_R(mb.MOP_BASE):

    def __init__(self):
        ####### build system
        oprR1   = opr.OPR_REG("r1", True)
        oprI1   = opr.OPR_IMM("i1"      )
        oprT1   = opr.OPR_TEMP("t1")
        oprRDES = opr.OPR_REG("rdes", False)

        movUop  = uop_mov_x86.UOP_MOV("mov_Uop")  ; movUop .addIo([oprI1], [oprT1])
        compUop = uop_comp_x86.UOP_COMP("alu_uop"); compUop.addIo([oprR1, oprT1], [oprRDES])

        ###### add to system
        self.autoInit("MOP_COMP", [oprR1, oprI1], [oprRDES], [oprT1], [movUop, compUop])

class MOP_COMP_M_I_R(mb.MOP_BASE):

    def __init__(self):
        ####### build system
        oprM1   = opr.OPR_MEM("m1", True)
        oprT1   = opr.OPR_TEMP("t1")
        opr_I2  = opr.OPR_IMM("i2")
        oprT2   = opr.OPR_TEMP("t2")
        oprRDES = opr.OPR_REG("rdes", False)

        movUop  = uop_mov_x86.UOP_MOV("mov_Uop") ;  movUop .addIo([oprM1], [oprT1])
        movUop2 = uop_mov_x86.UOP_MOV("mov_Uop2");  movUop2.addIo([opr_I2], [oprT2])
        compUop = uop_comp_x86.UOP_COMP("alu_uop"); compUop.addIo([oprT1, oprT2], [oprRDES])

        ###### add to system
        self.autoInit("MOP_COMP", [oprM1, opr_I2], [oprRDES], [oprT1, oprT2], [movUop, movUop2, compUop])

class MOP_COMP_M_M_R(mb.MOP_BASE):

    def __init__(self):
        ####### build system
        oprM1   = opr.OPR_MEM("m1", True)
        oprT1   = opr.OPR_TEMP("t1")
        opr_M2  = opr.OPR_MEM("i2", True)
        oprT2   = opr.OPR_TEMP("t2")
        oprRDES = opr.OPR_REG("rdes", False)

        movUop  = uop_mov_x86.UOP_MOV("mov_Uop") ;  movUop .addIo([oprM1], [oprT1])
        movUop2 = uop_mov_x86.UOP_MOV("mov_Uop2");  movUop2.addIo([opr_M2], [oprT2])
        compUop = uop_comp_x86.UOP_COMP("alu_uop"); compUop.addIo([oprT1, oprT2], [oprRDES])

        ###### add to system
        self.autoInit("MOP_COMP", [oprM1, opr_M2], [oprRDES], [oprT1, oprT2], [movUop,movUop2,compUop])