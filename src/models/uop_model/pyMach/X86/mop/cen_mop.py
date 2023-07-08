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
    PREBUILT_decKeys      : list

    regRelatedOprTypes = [oprs.OPR_REG, oprs.OPR_TEMP]
    oprBeSrcDesAble       = [oprs.OPR_REG, oprs.OPR_TEMP]
    oprBeTempAble         = [oprs.OPR_TEMP]



    def __init__(self):
        self.PREBUILT_inputOprList  = list()
        self.PREBUILT_outputOprList = list()
        self.PREBUILT_temOprList    = list()
        self.PREBUILT_uopList       = list()
        self.decKeys                = list()

    def addToPreBuitList(self, oprSrc, uop, oprDes):
        if oprSrc in self.oprBeSrcDesAble:
            self.PREBUILT_inputOprList.append(oprSrc)
        elif oprSrc in self.oprBeTempAble:
            self.PREBUILT_temOprList.append(oprSrc)

        self.PREBUILT_uopList
        ######################
        ############## REDUCE REDUNDANT MUEST BE FIXED
        ##############

    def initLdMemOp(self, desOprType, srcName: str, desName : str, uopName : str):
        ##### return (opr0,uopForMem, opr1) opr0 -> uopForMem -> opr1
        if desOprType not in self.regRelatedOprTypes:
            mb.MopUsageError(f"initLdMemOp can't store to operand {str(desOprType)}")

        memSrcOpr   = oprs.OPR_MEM(srcName, True)
        temDesOpr = oprs.OPR_REG(desName, False) if desOprType == oprs.OPR_REG else \
                      oprs.OPR_TEMP(desName)
        ######################################################################################################
        ldUop       = uop_mov_x86.UOP_MOV(uopName, resMap.cxxTypeUOP_LOAD)
        ldUop.addIo([memSrcOpr], [temDesOpr])
        ldUop.addMetaArgs([  [] ],[[]])
                    #        ^------------- list of list of argument that want this uop fill when it's generated
        #####################################################################################################
        return (memSrcOpr, ldUop, temDesOpr)

    def initStMemOp(self, srcOprType, srcName: str, desName : str, uopName : str):
        if srcOprType not in self.regRelatedOprTypes:
            mb.MopUsageError(f"initStMemOp can't get from operand {str(srcOprType)}")

        temSrcOpr = oprs.OPR_REG(srcName, True) if srcOprType == oprs.OPR_REG else \
                    oprs.OPR_TEMP(srcName)
        memDesOpr = oprs.OPR_MEM(desName, False)
        #####################################################################################################
        stUop       = uop_mov_x86.UOP_MOV(uopName, resMap.cxxTypeUOP_STORE)
        stUop.addIo([temSrcOpr], [memDesOpr])
        stUop.addMetaArgs([[]],[[]])
        #####################################################################################################
        return (temSrcOpr, stUop, memDesOpr)

    """
    initIoUopNOpr is used to initialize uop and opr that relate to load/store from memory
    for intuition, 
    """
    def initMemOp(self, srcType, desType, srcName: str, desName: str, uopName: str):

        if srcType == oprs.OPR_MEM and (desType in self.regRelatedOprTypes):
            return self.initLdMemOp(desType, srcName, desName, uopName)
        elif desType == oprs.OPR_MEM and (srcType in self.regRelatedOprTypes):
            return self.initStMemOp(srcType, srcName, desName, uopName)

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
            return (oprs.OPR_REG(srcName, True), None, None)
        elif srcType == oprs.OPR_TEMP and desType == oprs.OPR_REG:
            return (oprs.OPR_REG(desName, True), None, None)
        else:
            mb.MopUsageError(f"initReduceRedundantOp got conversion error src: {str(srcType)} des: {str(desType)}")

    """
    for macrops predictly desire the needed of mem operation but if it op that conversion reg to temp or temp to reg
    we use initReduceRedundantOp instead and not declare new uop
    """
    def initIoOp(self,srcType, desType, srcName: str, desName: str, uopName: str, autoAddToPreBuiltList: bool):
        ##### return (oprFrom , relateduop, oprTo)

        #### check that we are mem op
        if oprs.OPR_MEM in (srcType, desType):
            return self.initMemOp(srcType, desType, srcName, desName, uopName)
        else:
            return self.initReduceRedundantOp(srcType, desType, srcName, desName)







# class MOP_BASE_X86(mb.MOP_BASE):
#
#     inputListSummary  : list
#     outputListSummary : list
#     tempListSummary   : list
#     uopListSummary    : list
#
#     def __init__(self):
#         self.inputListSummary = []
#         self.outputListSummary = []
#         self.tempListSummary = []
#         self.uopListSummary = []
#
#     """
#     @brief generate uop and neccessary operand to load to value and add to preBuilt list
#     @param[in] srcOprType operandType CLASS
#     @param[in] uuid the id for generate variable
#     @return (<operand1>, <operand2>, <related uop>) ex
#     [mem/imm]=<operand1> -> related_uop -> <operand2>
#     reg/temp]=<operand2> other is none
#     """
#     def initSrcLoad(self, srcOprType, uuid: str, addToSummaryList: bool):
#         #        v------------ operand that need to load first
#         #              v----- operand that ready to inject to compute unit
#         res = (None, None, None)  # <------- uop that use for loading
#         if srcOprType == opr.OPR_REG:
#             ####### create related operand
#             srcRegOpr = srcOprType(f"r_src_{uuid}", True)
#             ####### add to pre macro-op built list
#             if addToSummaryList:
#                 self.inputListSummary.append(srcRegOpr)
#             ####### pre return value
#             res = (None, srcRegOpr, None)
#         elif srcOprType == opr.OPR_MEM or srcOprType == opr.OPR_IMM:
#             #
#             # ##### determine is mem or imm
#             isMemLoad = srcOprType == opr.OPR_MEM
#             ####### create related operand
#             srcOpr = srcOprType(f"m_src_{uuid}", True) if isMemLoad else \
#                      srcOprType(f"i_src_{uuid}")
#             desTempOpr = opr.OPR_TEMP(f"t_{uuid}")
#             ####### create related uop
#             relatedUop = uop_mov_x86.UOP_MOV(f"uop_ld_{uuid}",resMap.cxxTypeUOP_LOAD if isMemLoad else resMap.cxxTypeUOP_IMM)
#             relatedUop.addIo([srcOpr], [desTempOpr])
#             ####### add to pre marcro-op built list
#             if addToSummaryList:
#                 self.inputListSummary.append(srcOpr)
#                 self.tempListSummary.append(desTempOpr)
#                 self.uopListSummary.append(relatedUop)
#             ####### pre return value
#             res = (srcOpr, desTempOpr, relatedUop)
#         else:
#             raise mb.MopUsageError(f"invalid src operand for mop generating@initSrcLoad got {srcOprType}")
#         return res
#
#     """
#     @brief generate uop and neccessary operand to store to value and add to preBuilt list
#     @param[in] fromOpr operand that need to store
#     @param[in] toOprType type of operand that need to store actually
#     @param[in] uuid uuid that is needed built variable
#     @return (<operand1>, <operand2>, <related uop>) ex
#     [mem/imm]=<operand1> -> related_uop -> <operand2>
#     reg/temp]=<operand2> other is none
#     """
#     def initDesStore(self, fromOpr, toOprType, uuid: str, addToSummaryList: bool):
#         res = (None, None, None)
#
#         if type(fromOpr) not in [opr.OPR_REG, opr.OPR_TEMP, opr.OPR_DUMMY]:
#             raise mb.MopUsageError(f"can't store from {type(fromOpr)}")
#
#         if toOprType == opr.OPR_MEM:
#             if type(fromOpr) != opr.OPR_TEMP:
#                 raise mb.MopUsageError(f"mop gen error can't store to mem with src {type(toOprType)}")
#             ##### determine uop argument
#             ##### create operand
#             desOpr = opr.OPR_MEM(f"m_des_{uuid}", False)
#             ##### create uop
#             relatedUop = uop_mov_x86.UOP_MOV(f"uop_st_{uuid}", resMap.cxxTypeUOP_STORE)
#             relatedUop.addIo([fromOpr], [desOpr])
#             ##### add to macro-op built list
#             if addToSummaryList:
#                 self.tempListSummary.append(fromOpr)
#                 self.outputListSummary.append(desOpr)
#                 self.uopListSummary.append(relatedUop)
#             res = (fromOpr, desOpr, relatedUop)
#         elif toOprType == opr.OPR_REG:
#             if type(fromOpr) != opr.OPR_REG:
#                 raise mb.MopUsageError(f"can't store to reg with the different type")
#             res = (None, fromOpr, None)
#             if addToSummaryList:
#                 self.outputListSummary.append(fromOpr)
#         elif toOprType == opr.OPR_DUMMY:
#             if type(fromOpr) != opr.OPR_DUMMY:
#                 raise mb.MopUsageError(f"can't store to dummy with the different type")
#             res = (None, fromOpr, None)
#             if addToSummaryList:
#                 self.outputListSummary.append(fromOpr)
#         else:
#             raise mb.MopUsageError(f"can't store to type {toOprType}")
#
#         return res
#
#     """
#     @brief generate uop and neccessary operand to load 256 bit to value and add to preBuilt list
#     @param[in] srcOprType operandType CLASS
#     @param[in] uuid the id for generate variable
#     @return (<operand1>, <operand2>, [<related uopl>, <related uoph>]) ex.
#     [mem/imm]=<operand1> -> related_uopl related_uoph -> <operand2>
#     reg/temp]=<operand2> other is none
#     """
#     def initSrcLoad128(self, srcOprType, uuid: str, addToSummaryList: bool):
#         #        v------------ operand that need to load first
#         #              v----- operand that ready to inject to compute unit
#         res = (None, None, None)  # <------- uop that use for loading
#         if srcOprType == opr.OPR_REG or srcOprType == opr.OPR_TEMP:
#             ####### create related operand
#             srcRegOpr = srcOprType(f"r_src_{uuid}", True)
#             ####### add to pre macro-op built list
#             if addToSummaryList:
#                 self.inputListSummary.append(srcRegOpr)
#             ####### pre return value
#             res = (None, srcRegOpr, None)
#         elif srcOprType == opr.OPR_MEM or srcOprType == opr.OPR_IMM:
#             #
#             # ##### determine is mem or imm
#             memLoad = srcOprType == opr.OPR_MEM
#             ####### create related operand
#             srcOpr = srcOprType(f"m_src_{uuid}", True) if memLoad else \
#                      srcOprType(f"i_src_{uuid}")
#
#             desTempOpr = opr.OPR_TEMP(f"t_{uuid}")
#             ####### create related uop
#             ##### low
#             relatedUopl = uop_mov_x86.UOP_MOV(f"uop_ldl_{uuid}", resMap.cxxTypeUOP_LOAD if memLoad else resMap.cxxTypeUOP_IMM)
#             relatedUopl.addIo([srcOpr], [desTempOpr])
#             ##### high
#             relatedUoph = uop_mov_x86.UOP_MOV(f"uop_ldh_{uuid}", resMap.cxxTypeUOP_LOAD if memLoad else resMap.cxxTypeUOP_IMM)
#             relatedUoph.addIo([srcOpr], [desTempOpr])
#             ####### add to pre marcro-op built list
#             if addToSummaryList:
#                 self.inputListSummary.append(srcOpr)
#                 self.tempListSummary.append(desTempOpr)
#                 self.uopListSummary.append(relatedUoph)
#                 self.uopListSummary.append(relatedUopl)
#             ####### pre return value
#             res = (srcOpr, desTempOpr, [relatedUoph, relatedUopl])
#         else:
#             raise mb.MopUsageError(f"invalid src operand for mop generating@initSrcLoad got {srcOprType}")
#         return res
#
#     """
#     @brief generate uop and neccessary operand to store to value and add to preBuilt list
#     @param[in] fromOpr operand that need to store
#     @param[in] type of operand that need to store actually
#     @return (<operand1>, <operand2>, <related uop>) ex
#     [mem/imm]=<operand1> -> related_uop0 related_uop1 -> <operand2>
#     reg/temp]=<operand2> other is none
#     """
#     def initDesStore128(self, fromOpr, toOprType, uuid: str, addToSummaryList: bool):
#         res = (None, None, None)
#
#         if type(fromOpr) not in [opr.OPR_REG, opr.OPR_TEMP, opr.OPR_DUMMY]:
#             raise mb.MopUsageError(f"can't store from {type(fromOpr)}")
#
#         if toOprType == opr.OPR_MEM:
#             if type(fromOpr) != opr.OPR_TEMP:
#                 raise mb.MopUsageError(f"mop gen error can't store to mem with src {type(toOprType)}")
#             ##### determine uop argument
#             ##### create operand
#             desOpr = opr.OPR_MEM(f"m_des_{uuid}", False)
#             ##### create uop
#             relatedUopl = uop_mov_x86.UOP_MOV(f"uop_stl_{uuid}", resMap.cxxTypeUOP_STORE)
#             relatedUopl.addIo([fromOpr], [desOpr])
#             relatedUoph = uop_mov_x86.UOP_MOV(f"uop_sth_{uuid}", resMap.cxxTypeUOP_STORE)
#             relatedUoph.addIo([fromOpr], [desOpr])
#             ##### add to macro-op built list
#             if addToSummaryList:
#                 self.tempListSummary.append(fromOpr)
#                 self.outputListSummary.append(desOpr)
#                 self.uopListSummary.append(relatedUopl)
#                 self.uopListSummary.append(relatedUoph)
#             res = (fromOpr, desOpr, [relatedUoph, relatedUopl])
#         elif toOprType == opr.OPR_REG or toOprType == opr.OPR_DUMMY:
#             if type(fromOpr) != toOprType :
#                 raise mb.MopUsageError(f"can't store to reg with the same type [redundant]")
#             res = (None, fromOpr, None)
#             if addToSummaryList:
#                 self.outputListSummary.append(fromOpr)
#         else:
#             raise mb.MopUsageError(f"can't store to type {toOprType}")
#
#         return res
