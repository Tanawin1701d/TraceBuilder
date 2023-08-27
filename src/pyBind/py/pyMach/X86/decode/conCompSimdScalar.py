import traceBuilder as tbd
from model.model import *
from pyMach.X86.resMap import *
from pyMach.X86.decode.base import *



def decodeCompSimdScalar(instr: tbd.INSTR, mop: tbd.MOP):
    curTempId = 0

    isFlt = isFltInstr(instr)
    isSimd= isSimdInstr(instr)

    ##############################################################################################
    ################################### SRC OPERAND MANAGEMENT ###################################
    ##############################################################################################
    DES_IP_TREG, curTempId = initRipReader(instr, curTempId)
    oprToCompute = []

    for MEM_OPR in instr.getSrcLdOpr():
        execUnit, uopType = getMemOpClass(True, isSimd, isFlt)
        memData = MEM_OPR.getData()
        TempOpr = OPR_TREG(curTempId); curTempId = curTempId + 1
        LD_UOP  = UOP(uopType, execUnit)
        LD_UOP.addLink(MEM_OPR,
                       startByte = 0,
                       stopByte  = memData.size,
                       isSrc     = True
                       )
        LD_UOP.addLink(TempOpr, isSrc = False)
        oprToCompute.append(TempOpr)
        if MEM_OPR.getData().baseReg.archRegId == RIP_REG_NUM:
            LD_UOP.addLink(DES_IP_TREG, isSrc=True)

    for REG_OPR in instr.getSrcRegOpr():
        oprToCompute.append(REG_OPR)

    for IMM in instr.getSrcImmOpr():
        [TEMP_OPR], curTempId = initLdImmToTemp(IMM, isFlt, curTempId)
        oprToCompute.append(TEMP_OPR)

    ##############################################################################################
    ################################### DES OPERAND MANAGEMENT ###################################
    ##############################################################################################

    oprToStoreResult = []

    for MEM_OPR in instr.getDesStOpr():
        execUnit, uopType = getMemOpClass(False, isSimd, isFlt)
        memData = MEM_OPR.getData()

        TempOpr = OPR_TREG(curTempId); curTempId = curTempId + 1
        ST_UOP  = UOP(uopType, execUnit)
        ST_UOP.addLink(MEM_OPR,
            startByte = 0,
            stopByte  = memData.size,
            isSrc     = False
        )
        ST_UOP.addLink(TempOpr, isSrc = False)
        oprToStoreResult.append(TempOpr)
        if MEM_OPR.getData().baseReg.archRegId == RIP_REG_NUM:
            ST_UOP.addLink(DES_IP_TREG, isSrc=True)

    for REG_OPR in instr.getDesRegOpr():
        oprToStoreResult.append(REG_OPR)

    ############################################################################################
    ################################## COMP OPERAND MANAGEMENT #################################
    ############################################################################################
    execUnit, uopType = getCompOpclass(instr)
    COMP_UOP = UOP(uopType, execUnit)
    for srcOpr in oprToCompute:
        COMP_UOP.addLink(srcOpr, subRegIdx=0, isSrc=True)
    for desOpr in oprToStoreResult:
        COMP_UOP.addLink(desOpr, subRegIdx=0, isSrc=False)