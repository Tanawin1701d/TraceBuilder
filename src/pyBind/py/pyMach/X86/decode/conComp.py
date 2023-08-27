import traceBuilder as tbd
from model.model import *
from pyMach.X86.resMap import *
from pyMach.X86.decode.base import *

def decodeConsistantComp(instr: tbd.INSTR, mop: tbd.MOP):
    curTempId = 0
    maxRegSize = getMaxRegSize(instr)
    amt_simdGrp = (maxRegSize + ARCH_REG_SIZE - 1) // ARCH_REG_SIZE
    isFlt       = isFltInstr(instr)
    isSimd      = isSimdInstr(instr)
    ##############################################################################################
    ################################### SRC OPERAND MANAGEMENT ###################################
    ##############################################################################################
    DES_IP_TREG, curTempId = initRipReader(instr, curTempId)
    oprToCompute = [list() for _ in range(amt_simdGrp)]
    ########### get src mem load operand
    for MEM_OPR in instr.getSrcLdOpr():
        LD_TREGS, curTempId = initLdOrStUopRelTemp(MEM_OPR, DES_IP_TREG,
                                                   ARCH_REG_FLT_SIZE if isFltNormInstr(instr) else ARCH_REG_SIZE,
                                                   True, isFlt, curTempId)
        if len(LD_TREGS) != amt_simdGrp:
            ####### if inconsistant mem operand we broad cast that operand
            for idx in range(amt_simdGrp):
                oprToCompute[idx].extend(LD_TREGS)
            MODEL_USAGE_WARN(f"ld memOpr got inequal of simd operand for instr {getDebugInstrStr(instr)}")
        else:
            for idx, ld_treg in enumerate(LD_TREGS):
                oprToCompute[idx].append(ld_treg)
    ########### get src reg operand
    for REG_OPR in instr.getSrcRegOpr():
        for srcOprOfGrp in oprToCompute:
            srcOprOfGrp.append(REG_OPR)
    ########## imm src Operand
    for IMM in instr.getSrcImmOpr():
        [TEMP_OPR], curTempId = initLdImmToTemp(IMM, isFlt, curTempId)
        for srcOprOfGrp in oprToCompute:
            srcOprOfGrp.append(TEMP_OPR)
    ##############################################################################################
    ################################### DES OPERAND MANAGEMENT ###################################
    ##############################################################################################
    oprToStoreResult = [list() for _ in range(amt_simdGrp)]
    ########### get des mem load operand
    for MEM_OPR in instr.getDesStOpr():
        ST_TREGS, curTempId = initLdOrStUopRelTemp(MEM_OPR, DES_IP_TREG,
                                                   ARCH_REG_FLT_SIZE if isFltNormInstr(instr) else ARCH_REG_SIZE,
                                                   False, isFlt,curTempId)
        if len(ST_TREGS) != amt_simdGrp:
            for idx in range(amt_simdGrp):
                oprToCompute[idx].extend(ST_TREGS)
            MODEL_USAGE_WARN(f"st memOpr got inequal of simd operand for instr {getDebugInstrStr(instr)}")
        else:
            for idx, st_treg in enumerate(ST_TREGS):
                oprToStoreResult[idx].append(st_treg)

        if len(ST_TREGS) > 100:
            print("xcxcxcxc")

    ########### des reg operand
    for REG_OPR in instr.getDesRegOpr():
        for desOprOfGrp in oprToStoreResult:
            desOprOfGrp.append(REG_OPR)
    ############################################################################################
    ################################## COMP OPERAND MANAGEMENT #################################
    ############################################################################################
    for groupIdx, (srcOprsOfGrp, desOprsOpfGrp) in enumerate(zip(oprToCompute, oprToStoreResult)):
        execUnit, uopType = getCompOpclass(instr)
        COMP_UOP = UOP(uopType, execUnit)
        for srcOpr in srcOprsOfGrp:
            COMP_UOP.addLink(srcOpr, subRegIdx=groupIdx, isSrc=True)  ##### for temp operand subRegIdx is redundant
        for desOpr in desOprsOpfGrp:
            COMP_UOP.addLink(desOpr, subRegIdx=groupIdx, isSrc=False)
    ############################################################################################
