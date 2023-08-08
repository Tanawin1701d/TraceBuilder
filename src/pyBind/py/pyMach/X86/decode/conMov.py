import traceBuilder as tbd
from model.model import *
from pyMach.X86.resMap import *
from pyMach.X86.decode.base import *

def decodeConsistantMov(instr: tbd.INSTR, mop: tbd.MOP):
    curTempId = 0
    maxRegSize = getMaxRegSize(instr)
    amt_simdGrp = (maxRegSize + ARCH_REG_SIZE - 1) // ARCH_REG_SIZE

    oprToLoads = [list() for _ in range(amt_simdGrp)]
    oprToStore = [list() for _ in range(amt_simdGrp)]

    requiredLdRip = False
    requiredStRip = False

    mnemonic = instr.getMnemonic()
    immFlt = mnemonicToMemTransfer.get(mnemonic, "int") == "flt"
    ##############################################################################################
    ################################### SRC OPERAND MANAGEMENT ###################################
    ##############################################################################################
    DES_IP_TREG, curTempId = initRipReader(instr, curTempId)

    for oprImm in instr.getSrcImmOpr():
        [TEMP_OPR], curTempId = initLdImmToTemp(oprImm, immFlt, curTempId)
        for oprToLoadPerGrp in oprToLoads:
            oprToLoadPerGrp.append(TEMP_OPR)
    for oprReg in instr.getSrcRegOpr():
        for oprToLoadPerGrp in oprToLoads:
            oprToLoadPerGrp.append(oprReg)
    for oprMem in instr.getSrcLdOpr():
        requiredLdRip = requiredLdRip or (oprMem.getData().baseReg.archRegId == RIP_REG_NUM)
        for oprToLoadPerGrp in oprToLoads:
            oprToLoadPerGrp.append(oprMem)

    ##############################################################################################
    ################################### DES OPERAND MANAGEMENT ###################################
    ##############################################################################################

    for oprReg in instr.getDesRegOpr():
        for oprToStorePerGrp in oprToStore:
            oprToStorePerGrp.append(oprReg)
    for oprMem in instr.getDesStOpr():
        requiredStRip = requiredStRip or (oprMem.getData().baseReg.archRegId == RIP_REG_NUM)
        for idx, oprToStorePerGrp in enumerate(oprToStore):
            oprToStorePerGrp.append(oprMem)


    ##############################################################################################
    ################################### UOP MANAGEMENT ###################################
    ##############################################################################################
    ########### get src mem load operand
    for idx in range(amt_simdGrp):
        ########### first uop
        execUnit, uopClass = getTransferOpClass(instr)
        UOP_MOV = UOP(uopClass, execUnit)
        for opr in oprToLoads[idx]:
            UOP_MOV.addLink(opr, isSrc=True, subRegIdx=idx,
                           startByte=idx * ARCH_REG_SIZE,
                           stopByte=(idx + 1) * ARCH_REG_SIZE)

        for opr in oprToStore[idx]:
            ##### it is supposed to be reg
            UOP_MOV.addLink(opr, isSrc=False, subRegIdx=idx,
                           startByte=idx * ARCH_REG_SIZE,
                           stopByte=(idx + 1) * ARCH_REG_SIZE)

        if requiredLdRip or requiredStRip:
            UOP_MOV.addLink(DES_IP_TREG, isSrc = True)