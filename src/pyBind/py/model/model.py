import traceBuilder as tbd
import base.sysVal  as sysVal


class MODEL_USAGE_ERR(Exception):
    def __init__(self, message):
        super.__init__(message)


pendingUops = dict() #### dict of key = threadId  value = list() of uop
pendingReg  = dict() #### dict of key = threadId value = list() of reg operand
pendingTReg = dict() #### dict of key = threadId value = list() of treg operand

class MODEL:

    def initialAutoAddedStructure(self):
        tid = sysVal.getThreadId()
        pendingUops[tid] = list()
        pendingReg[tid]  = list()
        pendingTReg[tid] = list()

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
            ##### auto push auto added uop to mop
            self.addAutoUopToMop(mop)
            ##### clear auto uop
            self.clearAutoAddedUop()
            self.clearAutoAdded_OPR_REG()
            self.clearAutoAdded_OPR_TREG()
            ##### send mop to cxx to save model
            tmd.addDecodedInstr(instrId, mop)

    def getSrcOprs(self, instr: tbd.INSTR):
        amt = len(instr.getSrcPoolOpr())
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
            raise MODEL_USAGE_ERR(f"get SrcUop error from rt: {instr.getSrcPoolOpr} got : {preRet}")
        return preRet

    def getDesOprs(self, instr: tbd.INSTR):
        amt = len(instr.getDesPoolOpr())
        preRet = [None for _ in range(amt)]
        for opr in instr.getDesRegOpr():
            idx = opr.getMcSideIdx()
            preRet[idx] = opr
        for opr in instr.getDesStOpr():
            idx = opr.getMcSideIdx()
            preRet[idx] = opr

        if None in preRet:
            raise MODEL_USAGE_ERR(f"get DesUop error from rt: {instr.getDesPoolOpr} got : {preRet}")
        return preRet




class UOP:

    REGLINK_ARGS  = ["subRegIdx", "isSrc"]
    TREGLINK_ARGS = ["isSrc"]
    MEMLINK_ARGS  = ["startByte", "stopByte", "isSrc"]
    ILINK_ARGS    = []
    UOPDep_ARGS  = []

    def __init__(self, uopType: tbd.UOP_TYPE, execUnit: int, addToCxx: bool = True):
        ##### cxx class
        self.uop = tbd.UOP(uopType, execUnit)
        ##### add to pending uop for auto initializing
        if addToCxx:
            tid = sysVal.getThreadId()
            pendingUops[tid].append(self.uop)

    def addLink(self, opr, **kwargs):
        if type(opr) == tbd.OPR_REG:
            self.checkArg(self.REGLINK_ARGS, **kwargs)
            self.uop.addLink_OPR_REG(opr, *[kwargs[arg] for arg in self.REGLINK_ARGS])
        elif type(opr) == tbd.OPR_TREG:
            self.checkArg(self.TREGLINK_ARGS, **kwargs)
            self.uop.addLink_OPR_TREG(opr, *[kwargs[arg] for arg in self.TREGLINK_ARGS])
        elif type(opr) == tbd.OPR_MEM:
            self.checkArg(self.MEMLINK_ARGS, **kwargs)
            self.uop.addLink_OPR_MEM(opr, *[kwargs[arg] for arg in self.MEMLINK_ARGS])
        elif type(opr) == tbd.OPR_IMM:
            self.checkArg(self.ILINK_ARGS, **kwargs)
            self.uop.addLink_OPR_IMM(opr, *[kwargs[arg] for arg in self.ILINK_ARGS])
        else:
            raise MODEL_USAGE_ERR(f"{opr} cant add Link with {kwargs}")

    def checkArg(self, args: list, **kwargs):
        for arg in args:
            if arg not in kwargs:
                raise MODEL_USAGE_ERR(f"{arg} not in Args")
        return

class OPR_REG:
    def __init__(self, archRegId: int, idxInPool: int = -1, addToCxx: bool = True):
        self.reg = tbd.OPR_REG(archRegId, idxInPool)
        if addToCxx:
            tid = sysVal.getThreadId()
            pendingReg[tid].append(self.reg)

    def getData(self):
        self.reg.getData()

class OPR_TREG:
    def __init__(self, tregId: int, addToCxx: bool = True):
        self.treg = tbd.OPR_TREG(tregId)
        if addToCxx:
            tid = sysVal.getThreadId()
            pendingReg[tid].append(self.treg)

    def getData(self):
        self.treg.getData()