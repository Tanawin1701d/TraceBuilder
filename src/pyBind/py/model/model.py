import warnings
import traceBuilder as tbd
import base.sysVal  as sysVal


class MODEL_USAGE_ERR(Exception):
    def __init__(self, message):
        super.__init__(message)

class MODEL_USAGE_WARN():
    def __init__(self, message):
        pass #warnings.warn(message)


pendingUops = dict() #### dict of key = threadId  value = list() of uop
pendingReg  = dict() #### dict of key = threadId value = list() of reg operand
pendingTReg = dict() #### dict of key = threadId value = list() of treg operand
pendingImmOpr = dict() ####dict of key = theadId value = list() of treg operand

class MODEL:

    def initialAutoAddedStructure(self):
        tid = sysVal.getThreadId()
        pendingUops[tid] = list()
        pendingReg[tid]  = list()
        pendingTReg[tid] = list()
        pendingImmOpr[tid] = list()

    def addAutoUopToMop(self, mop: tbd.MOP):
        tid = sysVal.getThreadId()
        if tid not in pendingUops:
            raise MODEL_USAGE_ERR("can't find auto uop list to add to system")
        toAddUops = pendingUops[tid]
        if len(toAddUops) == 0:
            print("[TBD FED][MODEL BASE] warning modeler got 0 uop for mop")
        mop.addUopAgents(toAddUops)

    def addAutoRegOprToMop(self, mop: tbd.MOP):
        tid = sysVal.getThreadId()
        if tid not in pendingReg:
            raise MODEL_USAGE_ERR("can't find auto reg opr list to add to system")
        toAddRegOprs = pendingReg[tid]
        for opr in toAddRegOprs:
            mop.addOprReg(opr)

    def addAutoTregOprToMop(self, mop: tbd.MOP):
        tid = sysVal.getThreadId()
        if tid not in pendingTReg:
            raise MODEL_USAGE_ERR("can't find auto treg opr list to add to system")
        toAddTregOprs = pendingTReg[tid]
        for opr in toAddTregOprs:
            mop.addOprTemp(opr)

    def addAutoImmOprToMop(self, mop: tbd.MOP):
        tid = sysVal.getThreadId()
        if tid not in pendingImmOpr:
            raise MODEL_USAGE_ERR("can't find auto imm opr list to add to system")
        toAddImmOprs = pendingImmOpr[tid]
        for opr in toAddImmOprs:
            mop.addOprImm(opr)

    def clearAutoAddedUop(self):
        tid = sysVal.getThreadId()
        if tid not in pendingUops:
            raise MODEL_USAGE_ERR("can't find auto uop list that is added to system")
        pendingUops.pop(tid)

    def clearAutoAdded_OPR_REG(self):
        tid = sysVal.getThreadId()
        if tid not in pendingReg:
            raise MODEL_USAGE_ERR("can't clear auto reg opr that is added to system")
        pendingReg.pop(tid)

    def clearAutoAdded_OPR_TREG(self):
        tid = sysVal.getThreadId()
        if tid not in pendingTReg:
            raise MODEL_USAGE_ERR("can't clear auto treg opr that is added to system")
        pendingTReg.pop(tid)

    def clearAutoAdded_OPR_IMM(self):
        tid = sysVal.getThreadId()
        if tid not in pendingImmOpr:
            raise MODEL_USAGE_ERR("can't clear auto timm opr that is added to system")
        pendingImmOpr.pop(tid)

    def decode(self, rt_instr, mop):
        ######## you must return list
        raise MODEL_USAGE_ERR("this is base class of model you should not be here")

    def startDecodeCore(self, core: tbd.CORE, model_tid: int):

        tmd = core.getThreadModel(model_tid)
        amtInstr = tmd.getAmountInstr()

        tid = sysVal.getThreadId()
        ####### decode for each instruction
        for instrId in range(amtInstr):
            ##### runtime instr
            rt_instr = tmd.getRtInstr(instrId)
            ##### prepare storage for auto add uop
            self.initialAutoAddedStructure()
            ##### mop
            mop = tbd.MOP(rt_instr)
            ##### send to decoder
            self.decode(rt_instr, mop)
            ##### auto push auto added element to system
            self.addAutoUopToMop(mop)
            self.addAutoRegOprToMop(mop)
            self.addAutoTregOprToMop(mop)
            self.addAutoImmOprToMop(mop)
            ##### clear auto uop
            self.clearAutoAddedUop()
            self.clearAutoAdded_OPR_REG()
            self.clearAutoAdded_OPR_TREG()
            self.clearAutoAdded_OPR_IMM()
            ##### send mop to cxx to save model
            tmd.addDecodedInstr(instrId, mop)

class UOP:




    REGLINK_ARGS  = ["subRegIdx", "isSrc"]
    TREGLINK_ARGS = ["isSrc"]
    MEMLINK_ARGS  = ["startByte", "stopByte", "isSrc"]
    ILINK_ARGS    = []
    UOPDep_ARGS  = []

    def __init__(self, uopType: tbd.UOP_TYPE, execUnit: int, addToCxx: bool = True):
        ##### cxx class

        if not (execUnit > 0 and execUnit <= 52):
            MODEL_USAGE_ERR("invalid exec Type")

        self.uop = tbd.UOP(uopType, execUnit)
        ##### add to pending uop for auto initializing
        if addToCxx:
            tid = sysVal.getThreadId()
            pendingUops[tid].append(self.uop)

        ##### cnt checker
        self.cntCheck = [0 for _ in range(6)]

    def addLink(self, opr, **kwargs):
        if type(opr) == tbd.OPR_REG or type(opr) == OPR_REG:
            self.checkArg(self.REGLINK_ARGS, **kwargs)
            opr = opr if type(opr) == tbd.OPR_REG else opr.getCxxOpr()
            self.uop.addLink_OPR_REG(opr, *[kwargs[arg] for arg in self.REGLINK_ARGS])
            self.checkOprCnt(opr, kwargs["isSrc"])

        elif type(opr) == tbd.OPR_TREG or type(opr) == OPR_TREG:
            self.checkArg(self.TREGLINK_ARGS, **kwargs)
            opr = opr if type(opr) == tbd.OPR_TREG else opr.getCxxOpr()
            self.uop.addLink_OPR_TREG(opr, *[kwargs[arg] for arg in self.TREGLINK_ARGS])
            self.checkOprCnt(opr, kwargs["isSrc"])
        elif type(opr) == tbd.OPR_MEM:
            self.checkArg(self.MEMLINK_ARGS, **kwargs)
            self.uop.addLink_OPR_MEM(opr, *[kwargs[arg] for arg in self.MEMLINK_ARGS])
            self.checkOprCnt(opr, kwargs["isSrc"])
        elif type(opr) == tbd.OPR_IMM or type(opr) == OPR_IMM:
            self.checkArg(self.ILINK_ARGS, **kwargs)
            opr = opr if type(opr) == tbd.OPR_IMM else opr.getCxxOpr()
            self.uop.addLink_OPR_IMM(opr, *[kwargs[arg] for arg in self.ILINK_ARGS])
        else:
            raise MODEL_USAGE_ERR(f"{type(opr)} cant add Link with {kwargs}")

    def checkOprCnt(self, opr, isSrc: bool):
        idxMap = {tbd.OPR_REG: 0, tbd.OPR_TREG: 1, tbd.OPR_MEM: 2}
        idx = idxMap[type(opr)] * 2 + int(isSrc)
        self.cntCheck[idx] = self.cntCheck[idx] + 1
        if self.cntCheck[idx] > 15:
            raise MODEL_USAGE_ERR("exeed opr")

    def checkArg(self, args: list, **kwargs):
        for arg in args:
            if arg not in kwargs:
                raise MODEL_USAGE_ERR(f"{arg} not in Args")
        return

class OPR_REG:
    def __init__(self, archReg: tbd.AREGNUM, addToCxx: bool = True):
        self.reg = tbd.OPR_REG(archReg)
        if addToCxx:
            tid = sysVal.getThreadId()
            pendingReg[tid].append(self.reg)

    def getCxxOpr(self):
        return self.reg

    def getData(self):
        return self.reg.getData()

class OPR_TREG:
    def __init__(self, tregId: int, addToCxx: bool = True):
        self.treg = tbd.OPR_TREG(tregId)
        if addToCxx:
            tid = sysVal.getThreadId()
            pendingTReg[tid].append(self.treg)

    def getCxxOpr(self):
        return self.treg

    def getData(self):
        return self.treg.getData()

class OPR_IMM:
    def __init__(self, addToCxx: bool = True):
        self.immOpr = tbd.OPR_IMM()
        if addToCxx:
            tid = sysVal.getThreadId()
            pendingImmOpr[tid].append(self.immOpr)

    def getCxxOpr(self):
        return self.immOpr

    def getData(self):
        return self.immOpr.getData()



########################## get opr helper
def getSrcOprs(instr: tbd.INSTR):
    amt = instr.getSrcCount()
    preRet = [None for _ in range(amt)]
    for opr in instr.getSrcRegOpr():
        idx = opr.getMcSideIdx()
        preRet[idx] = opr
    for opr in instr.getSrcLdOpr():
        idx = opr.getMcSideIdx()
        preRet[idx] = opr
    for opr in instr.getSrcImmOpr():
        idx = opr.getMcSideIdx()
        preRet[idx] = opr
    if None in preRet:
        raise MODEL_USAGE_ERR(f"get SrcUop error from rt: {instr.getDecodeKey()} got : {preRet}")
    return preRet

def getDesOprs(instr: tbd.INSTR):
    amt = instr.getDesCount()
    preRet = [None for _ in range(amt)]
    for opr in instr.getDesRegOpr():
        idx = opr.getMcSideIdx()
        preRet[idx] = opr
    for opr in instr.getDesStOpr():
        idx = opr.getMcSideIdx()
        preRet[idx] = opr
    if None in preRet:
        raise MODEL_USAGE_ERR(f"get DesUop error from rt: {instr.getDecodeKey()} got : {preRet}")
    return preRet

def getDebugInstrStr(instr: tbd.INSTR):
    ###### TODO
    return instr.getDecodeKey()
