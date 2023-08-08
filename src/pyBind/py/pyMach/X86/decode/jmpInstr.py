import traceBuilder as tbd
from model.model import *
from pyMach.X86.resMap import *
from pyMach.X86.decode.base import *

def decodebranch(instr: tbd.INSTR, mop: tbd.MOP):
    mnemonic = instr.getMnemonic()

    # conBranchPrefix = ["JO","JNO","JB","JNAE","JC","JNB","JAE","JNC","JZ","JE",
    #                    "JNZ","JNE","JBE","JNA","JNBE","JA","JS","JNS","JP","JPE",
    #                    "JNP","JPO","JL","JNGE","JNL","JGE","JLE","JNG","JNLE""JG"]

    #if mnemonic in conBranchPrefix:
    current_tempId = 0
    toWriteOprs = []

    execUnit, uopType = resMap.gem5_opclass["IntAlu"]

    ##### check there is requried for rip src
    requiredRipSrc = False
    for r_opr in instr.getSrcRegOpr():
        if r_opr.getData().archRegId == RIP_REG_NUM:
            requiredRipSrc = True
    for m_opr in instr.getSrcLdOpr():
        if m_opr.getData().baseReg.archRegId == RIP_REG_NUM:
            requiredRipSrc = True

    TREG = None
    if requiredRipSrc:
        REG      = OPR_REG(RIP_REG)
        TREG     = OPR_TREG(current_tempId); current_tempId = current_tempId + 1
        RDIP_UOP = UOP(uopType, execUnit)
        RDIP_UOP.addLink(REG , isSrc = True, subRegIdx = 0)
        RDIP_UOP.addLink(TREG, isSrc = False)
        toWriteOprs.append(TREG)


    ####### collect other operand to make jmp instr more completely

        """ 
            due to pintool tracing did not recognize imm operand 
            we must make our psuedo operand for make simulation more precisely in case there is no reg or mem operand
        """
    needPsuedoImm = True
    for r_opr in instr.getSrcRegOpr():
        if r_opr.getData().archRegId != RIP_REG_NUM:
            needPsuedoImm = False
            toWriteOprs.append(r_opr)

    for m_opr in instr.getSrcLdOpr():
        needPsuedoImm = False
        resultTempOpr, current_tempId = initLdOrStUopRelTemp(m_opr, TREG, ARCH_REG_SIZE, True, False, current_tempId)
        toWriteOprs.extend(resultTempOpr)

    # for imm_opr in instr.getSrcImmOpr():
    #     [TEMP_OPR], current_tempId = initLdImmToTemp(imm_opr, False, current_tempId)
    #     toWriteOprs.append(TEMP_OPR)

    if needPsuedoImm:
        srcImmOpr = OPR_IMM()
        [des_temp_opr], current_tempId = initLdImmToTemp(srcImmOpr, False, current_tempId)
        toWriteOprs.append(des_temp_opr)


    WRIP_UOP    = UOP(uopType, execUnit)
    DES_RIP_REG = OPR_REG(RIP_REG)

    for toWriteOpr in toWriteOprs:
        WRIP_UOP.addLink(toWriteOpr, subRegIdx = 0, isSrc = True)
        ######### due to only REG and TREG operand not neccessary for startByte argument
    WRIP_UOP.addLink(DES_RIP_REG, isSrc = False, subRegIdx = 0)