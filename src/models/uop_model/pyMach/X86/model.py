import traceBuilder as tbd
import resMap
from src.pyBind.py.model.model import UOP, OPR_REG, OPR_TREG, MODEL_USAGE_ERR, MODEL





class x86_model(MODEL):
    RIP_REG = 16
    ##### predict functional unit for non simd
    def predictCompFu(self, mnemonic: str, isFpu: bool):
        pass
    ##### predict functional unit for non simd
    def predictMemFu(self, mnemonic: str, isFpu: bool):
        pass

    def isIntVector(self, mnemonic: str) -> bool:
        pass

    def isFltVector(self, mnemonic: str) -> bool:
        pass

    def isInt(self, mnemonic: str) -> bool:
        pass

    def isFlt(self, mnemonic: str) -> bool:
        pass

    def shouldReadRip(self, oprs):
        pass

    """
    create uop for ld/store data from/to memory for specific memory operand related with temp 
    :return (list of tempOpr, tempId Next)
    """

    def initLdOrStUopRelTemp(self, LDST_MEM: tbd.OPR_MEM, SRC_RIP_REG: tbd.OPR_TREG, sizePerOpr: int, isLoad: bool, isFlt: bool, tempId: int):
        if sizePerOpr < 1:
            raise MODEL_USAGE_ERR("sizePerUop is invalid")
        resultTempOpr = list()
        ##### prepare data for ##########################################################
        memOprData = LDST_MEM.getData()
        execUnit, uopType = self.getMemOpClass(isLoad, isFlt)
        #################################################################################
        for i in range((memOprData.size + sizePerOpr - 1) // sizePerOpr):
            ##### build des temp operand
            DES_TREG = OPR_TREG(tempId); resultTempOpr.append(DES_TREG); tempId = tempId + 1
            ##### build mem uop and link it
            MEM_UOP = UOP(uopType, execUnit)
            MEM_UOP.addLink(LDST_MEM, startByte =sizePerOpr * i, stopByte =sizePerOpr * (i + 1), isSrc = isLoad)
            MEM_UOP.addLink(DES_TREG, isSrc = isLoad)
            ########## link for rip if needed
            if memOprData.baseReg.archRegId == self.RIP_REG:
                MEM_UOP.addLink(SRC_RIP_REG, isSrc = True)
            ###########################################################################################
        return (resultTempOpr, tempId) #### return the result value of mem loading and tempId is next tempId

    def initLdImmToTemp(self, IMM: tbd.OPR_IMM, isFlt: bool, tempId: int):
        IMM


    def getMemOpClass(self, isLoad : bool, isFlt: bool = False):
        return 0, 0

    def decodeComp(self, instr: tbd.INSTR, mop: tbd.MOP, isFlt: bool):
        srcOprs = self.getSrcOprs(instr)
        desOprs = self.getDesOprs(instr)
        curTempId = 0

        DES_IP_TREG = None
        if self.shouldReadRip(srcOprs) or self.shouldReadRip(desOprs):
            ####### build uop for load rdip if need
            execUnit, uopType = resMap.gem5_opclass["IntAlu"]
            RDIP_UOP = UOP(uopType, execUnit)
            SRC_IP_REG   = OPR_REG(16); RDIP_UOP.addLink(SRC_IP_REG, subRegIdx = 0, isSrc = True)
            DES_IP_TREG  = OPR_TREG(curTempId); RDIP_UOP.addLink(DES_IP_TREG, isSrc = False)
            curTempId = curTempId + 1


        toComputeOpr = list()
        ######## build uop for memory operand ######################################################
        for MEM_OPR in instr.getSrcLdOpr():
            LD_TREGS, nextTregId = self.initLdOrStUopRelTemp(MEM_OPR, DES_IP_TREG, 8,True,isFlt, curTempId)
            curTempId = nextTregId
            toComputeOpr.extend(LD_TREGS)
        ######## build uop for imm operand ######################################################

        ######## add regOpr to to compute list #####################################################
        toComputeOpr.extend(instr.getSrcRegOpr())









    def decodeSimd(self, instr: tbd.INSTR, mop: tbd.MOP, isFlt: bool):
        pass

    def decodeMov(self, instr: tbd.INSTR, mop: tbd.MOP, isFlt: bool):
        pass



    def decode(self, instr: tbd.INSTR, mop: tbd.MOP):

        mnemonic = instr.getMnemonic()

        if self.isMov(mnemonic):
            self.decodeMov(instr, mop, self.isFlt() or self.isFltVector())
        if self.isFltVector(mnemonic):
            self.decodeSimd(instr, mop, True)
        elif self.isIntVector(mnemonic):
            self.decodeSimd(instr, mop, False)
        elif self.isFlt(mnemonic):
            self.decodeComp(instr, mop, True)
        elif self.isInt(mnemonic):
            self.decodeComp(instr, mop, False)

