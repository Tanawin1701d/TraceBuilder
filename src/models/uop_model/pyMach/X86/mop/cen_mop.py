import base.mop.mop_base as mb
import base.operand.opr_simple as oprs
import X86.uop.alu.comp_uop as  uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86
import X86.uop.resMap as resMap


class MOP_BASE_X86(mb.MOP_BASE):

    PREBUILT_inputOprList : list
    PREBUILT_outputOprList: list
    PREBUILT_temOprList   : list
    PREBUILT_uopList      : list

    regRelatedOprTypes = [oprs.OPR_REG, oprs.OPR_TEMP]
    oprBeSrcDesAble       = [oprs.OPR_REG, oprs.OPR_MEM]
    oprBeTempAble         = [oprs.OPR_TEMP]



    #### <= 64 bit mode
    #### ([oprSrc_grp], [uop_grp], [oprDes_grp])
    ##### If which side is instr related opr that side must have only one element in list

    def __init__(self):
        self.PREBUILT_inputOprList  = list()
        self.PREBUILT_outputOprList = list()
        self.PREBUILT_temOprList    = list()
        self.PREBUILT_uopList       = list()
        self.decKeys                = list()

    def addIoToPreBuiltList(self, oprSrcs, uops, oprDeses, isInput : bool = True):

        for oprSrc, uop, oprDes in zip(oprSrcs, uops, oprDeses):

            if type(oprSrc) == oprs.OPR_MEM and (type(oprDes) == oprs.OPR_TEMP or type(oprDes) == oprs.OPR_REG):
                #### case load
                self.PREBUILT_inputOprList.append(oprSrc)
                if type(oprDes) == oprs.OPR_TEMP:
                    self.PREBUILT_temOprList.append(oprDes)
                else:##### suppose type reg
                    self.PREBUILT_outputOprList.append(oprDes)
                self.PREBUILT_uopList.append(uop)
            elif (type(oprSrc) == oprs.OPR_TEMP or type(oprSrc) == oprs.OPR_REG) and type(oprDes) == oprs.OPR_MEM:
                #### case store
                if type(oprSrc) == oprs.OPR_TEMP:
                    self.PREBUILT_temOprList.append(oprSrc)
                else:#### suppose type reg
                    self.PREBUILT_inputOprList.append(oprSrc)
                self.PREBUILT_outputOprList.append(oprDes)
                self.PREBUILT_uopList.append(uop)
            elif type(oprSrc) == oprs.OPR_IMM and (type(oprDes) == oprs.OPR_TEMP or type(oprDes) == oprs.OPR_REG ):
                self.PREBUILT_inputOprList.append(oprSrc)
                if type(oprDes) == oprs.OPR_TEMP:
                    self.PREBUILT_temOprList.append(oprDes)
                else: #### reg
                    self.PREBUILT_outputOprList.append(oprDes)
                self.PREBUILT_uopList.append(uop)
            elif oprSrc == oprDes and uop == None:
                if isInput:
                    self.PREBUILT_inputOprList.append(oprSrc)
                else:
                    self.PREBUILT_outputOprList.append(oprDes)
            elif oprSrc != oprDes and uop != None:
                self.PREBUILT_inputOprList.append(oprSrc)
                self.PREBUILT_uopList.append(uop)
                self.PREBUILT_outputOprList.append(oprDes)
            else:
                mb.MopUsageError("can't add opr to prebuilt list")

    def addUopToPreBuiltList(self, uop):
        self.PREBUILT_uopList.append(uop)

    def getAmtUopForEachIo(self, uopOpSize, archOprSize):
        if uopOpSize > archOprSize or uopOpSize < 1 or archOprSize < 1:
            mb.MopUsageError(f"getAmt uop for io error got uopAmt:{uopOpSize} arch:{archOprSize} ")
        return (archOprSize + uopOpSize - 1) // uopOpSize

    def initLdMemOp(self, desOprType, cxxTypeIO_suggest: str, srcName: str, desName : str, uopName : str, uopOprSize: int, archOprSize: int):
        ##### return (opr0,uopForMem, opr1) opr0 -> uopForMem -> opr1
        if desOprType not in self.regRelatedOprTypes:
            mb.MopUsageError(f"initLdMemOp can't store to operand {str(desOprType)}")

        memSrcOpr = oprs.OPR_MEM(srcName, True)
        preRetSrcOprs = [memSrcOpr]
        preRetUops   = []
        preRetDesOprs = []

        for idx_inldGrp in range(self.getAmtUopForEachIo(uopOprSize, archOprSize)):
            ###### des Opr
            temDesOpr = oprs.OPR_REG (f"{desName}_{idx_inldGrp}", False) if desOprType == oprs.OPR_REG else \
                        oprs.OPR_TEMP(f"{desName}_{idx_inldGrp}")
            ###### uop for loader
            ldUop       = uop_mov_x86.UOP_MOV(f"{uopName}_{idx_inldGrp}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest),
                                              idx_inldGrp, uopOprSize, archOprSize)
            ldUop.addIo([memSrcOpr], [temDesOpr])
            ###### add for pre return
            preRetUops.append(ldUop)
            preRetDesOprs.append(temDesOpr)
        #####################################################################################################
        return (preRetSrcOprs, preRetUops, preRetDesOprs)


    def initStMemOp(self, srcOprType, cxxTypeIO_suggest: str, srcName: str, desName : str, uopName : str, uopOprSize: int, archOprSize: int):
        if srcOprType not in self.regRelatedOprTypes:
            mb.MopUsageError(f"initStMemOp can't get from operand {str(srcOprType)}")

        memDesOpr = oprs.OPR_MEM(desName, False)
        preRetSrcOprs = []
        preRetUops    = []
        preRetDesOprs = [memDesOpr]

        for idx_inStGrp in range(self.getAmtUopForEachIo(uopOprSize, archOprSize)):
            ##### srcOpr
            temSrcOpr = oprs.OPR_REG(f"{srcName}_{idx_inStGrp}", True) if srcOprType == oprs.OPR_REG else \
                        oprs.OPR_TEMP(f"{srcName}_{idx_inStGrp}")
            ##### uop for storer
            stUop = uop_mov_x86.UOP_MOV(f"{uopName}_{idx_inStGrp}", resMap.ioSuggest_to_cxxType(cxxTypeIO_suggest), idx_inStGrp, uopOprSize, archOprSize)
            stUop.addIo([temSrcOpr], [memDesOpr])
            ##### add for pre return
            preRetSrcOprs.append(temSrcOpr)
            preRetUops.append(stUop)

        return (preRetSrcOprs, preRetUops, preRetDesOprs)

    """
    initIoUopNOpr is used to initialize uop and opr that relate to load/store from memory
    for intuition, 
    """
    def initMemOp(self, srcType, desType, cxxTypeIO_suggest: str, srcName: str, desName: str, uopName: str, uopOpSize: int = 8, archOprSize: int = 8):

        if srcType == oprs.OPR_MEM and (desType in self.regRelatedOprTypes):
            return self.initLdMemOp(desType, cxxTypeIO_suggest, srcName, desName, uopName, uopOpSize, archOprSize)
        elif desType == oprs.OPR_MEM and (srcType in self.regRelatedOprTypes):
            return self.initStMemOp(srcType, cxxTypeIO_suggest, srcName, desName, uopName, uopOpSize, archOprSize)

    """
    initImmOp is used to initialze uop and opr that relate to load from imm(instr)
    """
    def initImmOp(self, desType, srcName: str, desName: str, uopName: str, uopOprSize: int, archOprSize: int):

        srcOpr = oprs.OPR_IMM(srcName)
        preRetSrcOpr = [srcOpr]
        preRetUops   = list()
        preRetDesOpr = list()

        for idx_inLdGrp in range(self.getAmtUopForEachIo(uopOprSize, archOprSize)):
            desOpr = oprs.OPR_REG(desName, False) if desType == oprs.OPR_REG else \
                     oprs.OPR_TEMP(desName)
            ############################## comp uop
            ldUop = uop_mov_x86.UOP_MOV(uopName, resMap.cxxTypeUOP_IMM, 0, 8, 8)
            ldUop.addIo([srcOpr], [desOpr])

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
            return ([preRetOpr], [None], [preRetOpr])
        elif srcType == oprs.OPR_TEMP and desType == oprs.OPR_REG:
            preRetOpr = oprs.OPR_REG(desName, True)
            return ([preRetOpr], [None], [preRetOpr])
        elif srcType == oprs.OPR_DUMMY or desType == oprs.OPR_TEMP:
            preRetOpr = oprs.OPR_DUMMY(srcName)
            return ([preRetOpr], [None], [preRetOpr])
        elif srcType == oprs.OPR_TEMP or desType == oprs.OPR_DUMMY:
            preRetOpr = oprs.OPR_DUMMY(desName)
            return ([preRetOpr], [None], [preRetOpr])
        else:
            mb.MopUsageError(f"initReduceRedundantOp got conversion error src: {str(srcType)} des: {str(desType)}")

    """
    for macrops predictly desire the needed of mem operation but if it op that conversion reg to temp or temp to reg
    we use initReduceRedundantOp instead and not declare new uop
    """
    def initIoOp(self,srcType, desType, cxxTypeIO_suggest: str, srcName: str, desName: str, uopName: str, uopOpSize: int = 8, archOprSize: int = 8):
        ##### return (oprFrom , relateduop, oprTo)
        result = (None, None, None)
        #### check that we are mem op
        if oprs.OPR_MEM in (srcType, desType):
            result = self.initMemOp(srcType, desType, cxxTypeIO_suggest, srcName, desName, uopName, uopOpSize, archOprSize)
        elif oprs.OPR_IMM == srcType:
            result = self.initImmOp(desType, srcName, desName, uopName, uopOpSize, archOprSize)
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


    def finalizeMop(self, cxxTypeMop_prefix: str, decKeys: list):
        self.decKeys = decKeys
        self.autoInit(cxxTypeMop_prefix,
                      self.PREBUILT_inputOprList,
                      self.PREBUILT_outputOprList,
                      self.PREBUILT_temOprList,
                      self.PREBUILT_uopList,
                      decKeys
                      )
