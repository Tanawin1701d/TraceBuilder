import traceBuilder as tbd
from core.core import *
from model.model import *
import pyMach.X86.resMap as resMap



def getMaxRegSize(instr: tbd.INSTR):
    maxRegStr = 1
    for opr in instr.getDesRegOpr() + instr.getDesRegOpr():
        maxRegStr = max(opr.getData().maxSubRegId * resMap.ARCH_REG_SIZE, maxRegStr)
    # for opr in instr.getSrcLdOpr() + instr.getDesStOpr():
    #     maxRegStr = max(opr.getData().size, maxRegStr)
    return maxRegStr

#####################################################################################################
################################# uop/operand build helper ##########################################
#####################################################################################################
def initLdOrStUopRelTemp(LDST_MEM   : tbd.OPR_MEM,
                         SRC_RIP_REG: tbd.OPR_TREG,
                         sizePerOpr : int,
                         isLoad     : bool,
                         isFlt      : bool,
                         tempId     : int):
    if sizePerOpr < 1:
        raise MODEL_USAGE_ERR("sizePerUop is invalid")
    resultTempOpr = list()
    ##### prepare data for ##########################################################
    memOprData = LDST_MEM.getData()
    memOprData.size = sizePerOpr if memOprData.size > 64 else memOprData.size ### prevent some volatility uop
    execUnit, uopType = resMap.getMemOpClass(isLoad, isFlt)
    #################################################################################
    for i in range((memOprData.size + sizePerOpr - 1) // sizePerOpr):
        ##### build des temp operand
        DES_TREG = OPR_TREG(tempId)
        resultTempOpr.append(DES_TREG)
        tempId = tempId + 1
        ##### build mem uop and link it
        MEM_UOP = UOP(uopType, execUnit)
        MEM_UOP.addLink(LDST_MEM, startByte=sizePerOpr * i, stopByte=min(sizePerOpr * (i + 1), memOprData.size), isSrc=isLoad)
        MEM_UOP.addLink(DES_TREG, isSrc= not isLoad)
        ########## link for rip if needed
        if memOprData.baseReg.archRegId == resMap.RIP_REG_NUM:
            MEM_UOP.addLink(SRC_RIP_REG, isSrc=True)
        ###########################################################################################
    return resultTempOpr, tempId  #### return the result value of mem loading and tempId is next tempId


def initLdImmToTemp(IMM: tbd.OPR_IMM, isFlt: bool, tempId: int):
    DES_TEMP_OPR = OPR_TREG(tempId)
    tempId = tempId + 1
    execUnit, uopType = resMap.getImmOpClass(isFlt)
    IMM_UOP = UOP(uopType, execUnit)
    IMM_UOP.addLink(IMM)
    IMM_UOP.addLink(DES_TEMP_OPR, isSrc=False)

    return [DES_TEMP_OPR], tempId

def shouldReadRip(oprs: list):
    for opr in oprs:
        if type(opr) == tbd.OPR_MEM : #### there is no type OPR_MEM type as a proxy class
            if opr.getData().baseReg.archRegId == resMap.RIP_REG_NUM:
                return True
    return False

def initRipReader(instr: tbd.INSTR, tempId: int):
    srcOprs = getSrcOprs(instr)
    desOprs = getDesOprs(instr)
    #############################################################################################
    #################################  rdip if needed ###########################################
    #############################################################################################
    DES_IP_TREG = None
    if shouldReadRip(srcOprs) or shouldReadRip(desOprs):
        ####### build uop for load rdip if need
        execUnit, uopType = resMap.gem5_opclass["IntAlu"]
        SRC_IP_REG  = OPR_REG(resMap.RIP_REG)
        DES_IP_TREG = OPR_TREG(tempId)
        ###### uop
        RDIP_UOP    = UOP(uopType, execUnit)
        RDIP_UOP.addLink(SRC_IP_REG, subRegIdx=0, isSrc=True)
        RDIP_UOP.addLink(DES_IP_TREG, isSrc=False)
        ###### increase reg id
        tempId = tempId + 1
    return DES_IP_TREG, tempId