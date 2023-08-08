import traceBuilder as tbd
from model.model import *
from pyMach.X86.resMap import *
from pyMach.X86.decode.base import *

def decodeMov64Simd(instr: tbd.INSTR, mop: tbd.MOP):
    curTempId = 0

    amtUopToZeroFill = 0

    mnemonic = instr.getMnemonic()
    immFlt = mnemonicToMemTransfer.get(mnemonic, "int") == "flt"

    oprToLoad   = []
    oprToStore  = []

    sizeToLdSt = ARCH_REG_SIZE
    requiredLdRip = False
    requiredStRip = False
    isMemLoad     = False
    isMemStore    = False
    ##############################################################################################
    ################################### SRC OPERAND MANAGEMENT ###################################
    ##############################################################################################
    DES_IP_TREG, curTempId = initRipReader(instr, curTempId)

    for oprImm in instr.getSrcImmOpr():
        [TEMP_OPR], curTempId = initLdImmToTemp(oprImm, immFlt, curTempId)
        oprToLoad.append(TEMP_OPR)

    for oprReg in instr.getSrcRegOpr():
        oprToLoad.append(oprReg)

    for oprMem in instr.getSrcLdOpr():
        isMemLoad = True
        oprToLoad.append(oprMem)
        sizeToLdSt = oprMem.getData().size
        requiredLdRip = requiredLdRip or (oprMem.getData().baseReg.archRegId == RIP_REG_NUM)

        ######## calulate how much instruction too full fill
            ####### only load should full fill with zero otherwise just mov
        effectiveSize = oprMem.getData().size
        amtUopToZeroFill =max( (getMaxRegSize(instr) - effectiveSize + ARCH_REG_SIZE - 1) // ARCH_REG_SIZE, 0)

    ##############################################################################################
    ################################### DES OPERAND MANAGEMENT ###################################
    ##############################################################################################

    for oprReg in instr.getDesRegOpr():
        oprToStore.append(oprReg)
    for oprMem in instr.getDesStOpr():
        isMemStore = True
        oprToStore.append(oprMem)
        sizeToLdSt = oprMem.getData().size
        requiredStRip = requiredStRip or (oprMem.getData().baseReg.archRegId == RIP_REG_NUM)

    ##############################################################################################
    ################################### UOP MANAGEMENT ###################################
    ##############################################################################################

    #isLoadAndStore = isMemLoad and isMemStore

    ###### fill zero fill
    if isMemLoad and (not isMemStore):
        ############ fullfill uop
        fillOps = []
        for i in range(amtUopToZeroFill):
            execUnit, opType = getImmOpClass(immFlt)
            fillUop = UOP(opType, execUnit)
            srcImm = OPR_IMM()
            fillUop.addLink(srcImm)
            fillOps.append(fillUop)

        ############# fill all opr with zero
        for oprToFullFillReg in instr.getDesRegOpr():
            maxSubRegIdx = oprToFullFillReg.getData().maxSubRegId
            for idx, uopFill in enumerate(fillOps):
                uopFill.addLink(oprToFullFillReg, isSrc=False, subRegIdx = maxSubRegIdx - 1 - idx)



    ############ first uop
    execUnit, uopType = getTransferOpClass(instr)
    UOP_MOV = UOP(uopType, execUnit)
    for opr in oprToLoad:
        UOP_MOV.addLink(opr, isSrc = True, subRegIdx = 0,
                       startByte = 0, stopByte  = sizeToLdSt
                        )
    if requiredLdRip or requiredStRip:
        UOP_MOV.addLink(DES_IP_TREG, isSrc = True)

    for opr in oprToStore:
        UOP_MOV.addLink(opr, isSrc = False, subRegIdx = 0,
                             startByte = 0, stopByte = sizeToLdSt)