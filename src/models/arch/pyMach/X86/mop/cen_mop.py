import base.mop.mop_base as mb
import base.operand.opr_simple as opr
import X86.uop.alu.comp_uop as  uop_comp_x86
import X86.uop.mov.dataMov_uop as uop_mov_x86




class MOP_BASE_X86(mb.MOP_BASE):

    inputListSummary, outputListSummary, tempListSummary, uopListSummary = [[], [], [], []]


    """
    @brief generate uop and neccessary operand to load to value and add to preBuilt list
    @param[in] srcOprType operandType CLASS
    @param[in] uuid the id for generate variable
    @return (<operand1>, <operand2>, <related uop>) ex  
    [mem/imm]=<operand1> -> related_uop -> <operand2> 
    reg/temp]=<operand2> other is none  
    """
    def initSrcLoad(self, srcOprType, uuid: str, addToSummaryList: bool):
        #        v------------ operand that need to load first
        #              v----- operand that ready to inject to compute unit
        res = (None, None, None)  # <------- uop that use for loading
        if srcOprType == opr.OPR_REG or srcOprType == opr.OPR_TEMP:
            ####### create related operand
            srcRegOpr = srcOprType(f"r_src_{uuid}", True)
            ####### add to pre macro-op built list
            if addToSummaryList:
                self.inputListSummary.append(srcRegOpr)
            ####### pre return value
            res = (None, srcRegOpr, None)
        elif srcOprType == opr.OPR_MEM or srcOprType == opr.OPR_IMM:
            #
            # ##### determine is mem or imm
            memLoad = srcOprType == opr.OPR_MEM
            ####### create related operand
            srcOpr = srcOprType(f"m_src_{uuid}", True) if memLoad else \
                     srcOprType(f"i_src_{uuid}")
            desTempOpr = opr.OPR_TEMP(f"t_{uuid}")
            ####### create related uop
            relatedUop = uop_mov_x86.UOP_MOV(f"uop_ld_{uuid}","MOV_MEM_LD")
            relatedUop.addIo([srcOpr], [desTempOpr])
            ####### add to pre marcro-op built list
            if addToSummaryList:
                self.inputListSummary.append(srcOpr)
                self.tempListSummary.append(desTempOpr)
                self.uopListSummary.append(relatedUop)
            ####### pre return value
            res = (srcOpr, desTempOpr, relatedUop)
        else:
            raise mb.MopUsageError(f"invalid src operand for mop generating@initSrcLoad got {srcOprType}")
        return res

    """
    @brief generate uop and neccessary operand to store to value and add to preBuilt list
    @param[in] fromOpr operand that need to store
    @param[in] toOprType type of operand that need to store actually
    @param[in] uuid uuid that is needed built variable
    @return (<operand1>, <operand2>, <related uop>) ex  
    [mem/imm]=<operand1> -> related_uop -> <operand2> 
    reg/temp]=<operand2> other is none  
    """
    def initDesStore(self, fromOpr, toOprType, uuid: str, addToSummaryList: bool):
        res = (None, None, None)

        if type(fromOpr) not in [opr.OPR_REG, opr.OPR_TEMP]:
            raise mb.MopUsageError(f"can't store from {type(fromOpr)}")

        if toOprType == opr.OPR_MEM:
            if type(fromOpr) != opr.OPR_TEMP:
                raise mb.MopUsageError(f"mop gen error can't store to mem with src {type(toOprType)}")
            ##### determine uop argument
            ##### create operand
            desOpr = opr.OPR_MEM(f"m_des_{uuid}", False)
            ##### create uop
            relatedUop = uop_mov_x86.UOP_MOV(f"uop_st_{uuid}", "MOV_MEM_ST")
            relatedUop.addIo([fromOpr], [desOpr])
            ##### add to macro-op built list
            if addToSummaryList:
                self.tempListSummary.append(fromOpr)
                self.outputListSummary.append(desOpr)
                self.uopListSummary.append(relatedUop)
            res = (fromOpr, desOpr, relatedUop)
        elif toOprType == opr.OPR_REG:
            if type(fromOpr) != opr.OPR_REG:
                raise mb.MopUsageError(f"can't store to reg with the same type [redundant]")
            res = (None, fromOpr, None)
            if addToSummaryList:
                self.outputListSummary.append(fromOpr)
        else:
            raise mb.MopUsageError(f"can't store to type {toOprType}")

        return res

    """
    @brief generate uop and neccessary operand to load 256 bit to value and add to preBuilt list
    @param[in] srcOprType operandType CLASS
    @param[in] uuid the id for generate variable
    @return (<operand1>, <operand2>, [<related uopl>, <related uoph>]) ex.  
    [mem/imm]=<operand1> -> related_uopl related_uoph -> <operand2> 
    reg/temp]=<operand2> other is none  
    """
    def initSrcLoad256(self, srcOprType, uuid: str, addToSummaryList: bool):
        #        v------------ operand that need to load first
        #              v----- operand that ready to inject to compute unit
        res = (None, None, None)  # <------- uop that use for loading
        if srcOprType == opr.OPR_REG or srcOprType == opr.OPR_TEMP:
            ####### create related operand
            srcRegOpr = srcOprType(f"r_src_{uuid}", True)
            ####### add to pre macro-op built list
            if addToSummaryList:
                self.inputListSummary.append(srcRegOpr)
            ####### pre return value
            res = (None, srcRegOpr, None)
        elif srcOprType == opr.OPR_MEM or srcOprType == opr.OPR_IMM:
            #
            # ##### determine is mem or imm
            memLoad = srcOprType == opr.OPR_MEM
            ####### create related operand
            srcOpr = srcOprType(f"m_src_{uuid}", True) if memLoad else \
                     srcOprType(f"i_src_{uuid}")

            desTempOpr = opr.OPR_TEMP(f"t_{uuid}")
            ####### create related uop
            ##### low
            relatedUopl = uop_mov_x86.UOP_MOV(f"uop_ldl_{uuid}","MOV_MEM_LD")
            relatedUopl.addIo([srcOpr], [desTempOpr])
            ##### high
            relatedUoph = uop_mov_x86.UOP_MOV(f"uop_ldh_{uuid}", "MOV_MEM_LD")
            relatedUoph.addIo([srcOpr], [desTempOpr])
            ####### add to pre marcro-op built list
            if addToSummaryList:
                self.inputListSummary.append(srcOpr)
                self.tempListSummary.append(desTempOpr)
                self.uopListSummary.append(relatedUoph)
                self.uopListSummary.append(relatedUopl)
            ####### pre return value
            res = (srcOpr, desTempOpr, [relatedUoph, relatedUopl])
        else:
            raise mb.MopUsageError(f"invalid src operand for mop generating@initSrcLoad got {srcOprType}")
        return res

    """
    @brief generate uop and neccessary operand to store to value and add to preBuilt list
    @param[in] fromOpr operand that need to store
    @param[in] type of operand that need to store actually
    @return (<operand1>, <operand2>, <related uop>) ex  
    [mem/imm]=<operand1> -> related_uop0 related_uop1 -> <operand2> 
    reg/temp]=<operand2> other is none  
    """
    def initDesStore256(self, fromOpr, toOprType, uuid: str, addToSummaryList: bool):
        res = (None, None, None)

        if type(fromOpr) not in [opr.OPR_REG, opr.OPR_TEMP]:
            raise mb.MopUsageError(f"can't store from {type(fromOpr)}")

        if toOprType == opr.OPR_MEM:
            if type(fromOpr) != opr.OPR_TEMP:
                raise mb.MopUsageError(f"mop gen error can't store to mem with src {type(toOprType)}")
            ##### determine uop argument
            ##### create operand
            desOpr = opr.OPR_MEM(f"m_des_{uuid}", False)
            ##### create uop
            relatedUopl = uop_mov_x86.UOP_MOV(f"uop_stl_{uuid}", "MOV_MEM_ST")
            relatedUopl.addIo([fromOpr], [desOpr])
            relatedUoph = uop_mov_x86.UOP_MOV(f"uop_sth_{uuid}", "MOV_MEM_ST")
            relatedUopl.addIo([fromOpr], [desOpr])
            ##### add to macro-op built list
            if addToSummaryList:
                self.tempListSummary.append(fromOpr)
                self.outputListSummary.append(desOpr)
                self.uopListSummary.append(relatedUopl)
                self.uopListSummary.append(relatedUoph)
            res = (fromOpr, desOpr, [relatedUoph, relatedUopl])
        elif toOprType == opr.OPR_REG:
            if type(fromOpr) != opr.OPR_REG:
                raise mb.MopUsageError(f"can't store to reg with the same type [redundant]")
            res = (None, fromOpr, None)
            if addToSummaryList:
                self.outputListSummary.append(fromOpr)
        else:
            raise mb.MopUsageError(f"can't store to type {toOprType}")

        return res
