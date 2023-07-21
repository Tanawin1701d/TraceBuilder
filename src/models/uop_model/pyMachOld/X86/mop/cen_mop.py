import base.mop.mop_base as mb
import base.operand.opr_simple as oprs
import X86.operand.opr as x86_opr
import X86.uop.alu.comp_uop as  uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86
import X86.uop.resMap as resMap


class MOP_BASE_X86(mb.MOP_BASE):

    PREBUILT_inputOprList : list
    PREBUILT_outputOprList: list
    PREBUILT_temOprList   : list
    PREBUILT_uopList      : list

    MAX_LEGACY_OPR_SIZE = 8 ### size in byte

    regRelatedOprTypes = [oprs.OPR_REG, oprs.OPR_TEMP]
    oprBeSrcDesAble       = [oprs.OPR_REG, oprs.OPR_MEM, x86_opr.OPR_MEM_W_IPR, oprs.OPR_IMM]
    oprBeTempAble         = [oprs.OPR_TEMP]
    memOprAble            = [oprs.OPR_MEM, x86_opr.OPR_MEM_W_IPR]



    #### <= 64 bit mode
    #### ([oprSrc_grp], [uop_grp], [oprDes_grp])
    ##### If which side is instr related opr that side must have only one element in list

    def __init__(self):
        self.PREBUILT_inputOprList  = list()
        self.PREBUILT_outputOprList = list()
        self.PREBUILT_temOprList    = list()
        self.PREBUILT_uopList       = list()
        self.decKeys                = list()


    def areThereMipNeed(self, oprands: list):
        if x86_opr.OPR_MEM_W_IPR in oprands:
            return True
        return False

    def addIoToPreBuiltList(self, oprSrcs: list, uops: list, oprDeses:list):

        for op in oprSrcs:
            if type(op) in self.oprBeSrcDesAble:
                self.PREBUILT_inputOprList.append(op)
            elif type(op) == oprs.OPR_TEMP:
                self.PREBUILT_temOprList.append(op)
            else:
                mb.MopUsageError(f"add opr type {op} to src opr prebuilt list error")
        for op in oprDeses:
            if type(op) in self.oprBeSrcDesAble:
                self.PREBUILT_outputOprList.append(op)
            elif type(op) == oprs.OPR_TEMP:
                self.PREBUILT_temOprList.append(op)
            else:
                mb.MopUsageError(f"add opr type {op} to des prebuilt list error")
        for uop in uops:
            self.PREBUILT_uopList.append(uop)



    def addUopToPreBuiltList(self, uop):
        self.PREBUILT_uopList.append(uop)

    def getAmtUopForEachIo(self, uopOpSize, archOprSize):
        if uopOpSize > archOprSize or uopOpSize < 1 or archOprSize < 1:
            mb.MopUsageError(f"getAmt uop for io error got uopAmt:{uopOpSize} arch:{archOprSize} ")
        return (archOprSize + uopOpSize - 1) // uopOpSize

    def initLdMemOp(self, srcOprType, desOprType, oprTempRip, cxxTypeIO_suggest: str, srcName: str, desName : str, uopName : str, uopOprSize: int, archOprSize: int):
        ##### return (opr0,uopForMem, opr1) opr0 -> uopForMem -> opr1
        if desOprType not in self.regRelatedOprTypes:
            mb.MopUsageError(f"initLdMemOp can't store to operand {str(desOprType)}")
        if srcOprType not in self.memOprAble:
            mb.MopUsageError(f"initLdMemOp can't load from operand {str(srcOprType)}")
        #### if the mem operand not Rip make it dummy
        if srcOprType != x86_opr.OPR_MEM_W_IPR:
            oprTempRip = oprs.OPR_DUMMY("ldMemRipDummy")

        memSrcOpr = srcOprType(srcName, True)
        preRetSrcOprs = [memSrcOpr]
        preRetUops   = []
        preRetDesOprs = []

        for idx_inldGrp in range(self.getAmtUopForEachIo(uopOprSize, archOprSize)):
            ###### des Opr
            temDesOpr = oprs.OPR_REG (f"{desName}_{idx_inldGrp}", False) if desOprType == oprs.OPR_REG else \
                        oprs.OPR_TEMP(f"{desName}_{idx_inldGrp}")
            ###### uop for loader
            ldUop       = uop_mov_x86.UOP_MOV(f"{uopName}_{idx_inldGrp}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest, oprs.OPR_MEM, type(temDesOpr)),
                                              idx_inldGrp, uopOprSize, archOprSize)
            ldUop.addIo([memSrcOpr, oprTempRip], [temDesOpr])
            ###### add for pre return
            preRetUops.append(ldUop)
            preRetDesOprs.append(temDesOpr)
        #####################################################################################################
        return (preRetSrcOprs, preRetUops, preRetDesOprs)


    def initStMemOp(self, srcOprType, desOprType, oprTempRip,  cxxTypeIO_suggest: str, srcName: str, desName : str, uopName : str, uopOprSize: int, archOprSize: int):
        if srcOprType not in self.regRelatedOprTypes:
            mb.MopUsageError(f"initStMemOp can't get from operand {str(srcOprType)}")
        if desOprType not in self.memOprAble:
                mb.MopUsageError(f"initStMemOp can't store to operand {str(srcOprType)}")
        #### if the mem operand not Rip make it dummy
        if desOprType != x86_opr.OPR_MEM_W_IPR:
            oprTempRip = oprs.OPR_DUMMY("ldMemRipDummy")

        memDesOpr = desOprType(desName, False)
        preRetSrcOprs = []
        preRetUops    = []
        preRetDesOprs = [memDesOpr]

        for idx_inStGrp in range(self.getAmtUopForEachIo(uopOprSize, archOprSize)):
            ##### srcOpr
            temSrcOpr = oprs.OPR_REG(f"{srcName}_{idx_inStGrp}", True) if srcOprType == oprs.OPR_REG else \
                        oprs.OPR_TEMP(f"{srcName}_{idx_inStGrp}")
            ##### uop for storer
            stUop = uop_mov_x86.UOP_MOV(f"{uopName}_{idx_inStGrp}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest, type(temSrcOpr), oprs.OPR_MEM), idx_inStGrp, uopOprSize, archOprSize)
            stUop.addIo([temSrcOpr, oprTempRip], [memDesOpr])
            ##### add for pre return
            preRetSrcOprs.append(temSrcOpr)
            preRetUops.append(stUop)

        return (preRetSrcOprs, preRetUops, preRetDesOprs)

    """
    init Uop for read instr pointer to temporal register
    """
    def initRdInstrPtr(self, srcName: str, UopName: str, desName: str):
        srcOpr = x86_opr.OPR_REG_W_RD_IPTR(srcName, True)
        desOpr = oprs.OPR_TEMP(desName)
        uop    = uop_mov_x86.UOP_MOV(UopName, resMap.ioSuggest_to_cxxType(resMap.cxxTypeIO_suggest_INT, oprs.OPR_REG, oprs.OPR_REG), 0, 8, 8)
        uop.addIo([srcOpr], [desOpr])
        return ([srcOpr], [uop], [desOpr])

    """
    initIoUopNOpr is used to initialize uop and opr that relate to load/store from memory
    for intuition, 
    """
    def initMemOp(self, srcType, desType, oprTempRip, cxxTypeIO_suggest: str, srcName: str, desName: str, uopName: str, uopOpSize: int = 8, archOprSize: int = 8):

        if srcType in self.memOprAble and (desType in self.regRelatedOprTypes):
            return self.initLdMemOp(srcType, desType, oprTempRip, cxxTypeIO_suggest, srcName, desName, uopName, uopOpSize, archOprSize)
        elif desType in self.memOprAble and (srcType in self.regRelatedOprTypes):
            return self.initStMemOp(srcType, desType, oprTempRip, cxxTypeIO_suggest, srcName, desName, uopName, uopOpSize, archOprSize)

    """
    initImmOp is used to initialze uop and opr that relate to load from imm(instr)
    """
    def initImmOp(self, desType, cxxTypeIO_suggest: str, srcName: str, desName: str, uopName: str, uopOprSize: int, archOprSize: int):

        srcOpr = oprs.OPR_IMM(srcName)
        preRetSrcOpr = [srcOpr]
        preRetUops   = list()
        preRetDesOpr = list()

        for idx_inLdGrp in range(self.getAmtUopForEachIo(uopOprSize, archOprSize)):
            desOpr = oprs.OPR_REG(f"{desName}_{idx_inLdGrp}", False) if desType == oprs.OPR_REG else \
                     oprs.OPR_TEMP(f"{desName}_{idx_inLdGrp}")
            ############################## comp uop
            ldUop = uop_mov_x86.UOP_MOV(f"{uopName}_{idx_inLdGrp}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest, oprs.OPR_IMM, desType), 0, 8, 8)
            ldUop.addIo([srcOpr, oprs.OPR_DUMMY("iptrLoader")], [desOpr])

            preRetUops.append(ldUop)
            preRetDesOpr.append(desOpr)

        return (preRetSrcOpr, preRetUops, preRetDesOpr)



    """
    initReduceRedundant
    for some case that io for load/st uop is not neccessary like reg to temp or temp to reg operation
    we return (srcOpr, None, None) for compatible with mem op
    """
    def initReduceRedundantOp(self, srcType, desType, srcName: str, desName: str):
        #####  sanitize operand type
        if srcType == desType:
            mb.MopUsageError("initReduceRedundantOp got something neccessary initialization")
        if srcType not in self.regRelatedOprTypes:
            mb.MopUsageError(f"initReduceRedundantOp got unacceptable src type {str(srcType)}")
        if desType not in self.regRelatedOprTypes:
            mb.MopUsageError(f"initReduceRedundantOp got unacceptable des type {str(desType)}")

        if srcType == oprs.OPR_REG and desType == oprs.OPR_TEMP:
            preRetOpr = oprs.OPR_REG(srcName, True)
            return ([preRetOpr], [], [])
        elif srcType == oprs.OPR_TEMP and desType == oprs.OPR_REG:
            preRetOpr = oprs.OPR_REG(desName, False)
            return ([], [], [preRetOpr])
        elif srcType == oprs.OPR_DUMMY or desType == oprs.OPR_TEMP:
            preRetOpr = oprs.OPR_DUMMY(srcName)
            return ([preRetOpr], [], [])
        elif srcType == oprs.OPR_TEMP or desType == oprs.OPR_DUMMY:
            preRetOpr = oprs.OPR_DUMMY(desName)
            return ([], [], [preRetOpr])
        else:
            mb.MopUsageError(f"initReduceRedundantOp got conversion error src: {str(srcType)} des: {str(desType)}")

    """
    for macrops predictly desire the needed of mem operation but if it op that conversion reg to temp or temp to reg
    we use initReduceRedundantOp instead and not declare new uop
    """
    def initIoOp(self,srcType, desType, oprTempRip, cxxTypeIO_suggest: str, srcName: str, uopName: str,desName: str, uopOpSize: int = 8, archOprSize: int = 8):
        ##### return (oprFrom , relateduop, oprTo)
        result = (None, None, None)
        #### check that we are mem op
        if set(self.memOprAble).intersection({srcType, desType}):
            result = self.initMemOp(srcType, desType, oprTempRip, cxxTypeIO_suggest, srcName, desName, uopName, uopOpSize, archOprSize)
        elif oprs.OPR_IMM == srcType:
            result = self.initImmOp(desType, cxxTypeIO_suggest, srcName, desName, uopName, uopOpSize, archOprSize)
        else:
            result = self.initReduceRedundantOp(srcType, desType, srcName, desName)
        return result

    """
    built simple uop 
    """
    def initCompOp(self, srcOpr0, srcOpr1, desOpr0, desOpr1,
                   uopName: str, cxxTypePrefix,
                   in_idxInGrp : int, in_uopOprSize : int, in_archOprSize : int,
                   out_idxInGrp: int, out_uopOprSize: int, out_archOprSize: int
                   ):
                                                      ## add uop to preBuilt list
        ####### build uop add add operand
        uopComp = uop_comp_x86.UOP_COMP(uopName, cxxTypePrefix,
                                        in_idxInGrp , in_uopOprSize , in_archOprSize,
                                        out_idxInGrp, out_uopOprSize, out_archOprSize)
        uopComp.addIo([srcOpr0, srcOpr1], [desOpr0, desOpr1])

        return uopComp

    """
    after init io from function initIO we must clean data that return to give to add io to comp uop
    some input is from operand from ld/st uop or some from register operand
    """
    def getIoForCompFromInitIo(self, oprFroms, uops, oprTos, idx, isLoad):
        if isLoad:
            return oprTos[idx] if len(oprTos) > 0 else oprFroms[0]
        else: ### store
            return oprFroms[idx] if len(oprFroms) > 0 else oprTos[0]


    def finalizeMop(self, cxxTypeMop_prefix: str, decKeys: list):
        self.decKeys = decKeys
        self.autoInit(cxxTypeMop_prefix,
                      self.PREBUILT_inputOprList,
                      self.PREBUILT_outputOprList,
                      self.PREBUILT_temOprList,
                      self.PREBUILT_uopList,
                      decKeys
                      )
