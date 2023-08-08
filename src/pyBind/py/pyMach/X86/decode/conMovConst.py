import traceBuilder as tbd
from model.model import *
from pyMach.X86.resMap import *
from pyMach.X86.decode.base import *


def decodeMovConst(instr: tbd.INSTR, mop: tbd.MOP):
    currentTempId = 0


    DES_TEMP_OPR = OPR_TREG(currentTempId); currentTempId = currentTempId + 1
    execUnit, uopType = resMap.getImmOpClass(True)
    IMM_UOP = UOP(uopType, execUnit)
    IMM_UOP.addLink(DES_TEMP_OPR, isSrc=False)

    if len(instr.getDesStOpr()) > 0:
        ################ to mem store operand
        for MEM_OPR in instr.getDesStOpr():
            execUnit, uopType = getMemOpClass(False, False, True)
            UOP_ST = UOP(uopType, execUnit)
            UOP_ST.addLink(DES_TEMP_OPR, isSrc = True)
            UOP_ST.addLink(MEM_OPR, startByte = 0, stopByte = ARCH_REG_SIZE, isSrc = False)

    else:
        for REG_OPR in instr.getDesRegOpr():
            IMM_UOP.addLink(REG_OPR, isSrc = False, subRegIdx = 0)