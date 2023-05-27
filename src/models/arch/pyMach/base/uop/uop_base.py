import itertools

###### temporary
import base.operand.listOpr as oprLs
import base.operand.opr_simple as oprSm


class UopUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)


class UOP_BASE:
    io_output        : oprLs.LISTOPR_BASE
    io_input         : oprLs.LISTOPR_BASE
    name             : str
    namePrefix       = "uop"
    uopTypePrefix    = "UOP_TYPE"
    cxxType_prefix   = "UOP_CHILD" #### please remind that cxxType is not finally
    cxxTypeParent    = "UOP_BASE"
    isAutodepenCheck = True
    ############ for uop infomation
    uopType          = "UOP_DUMMY" #### for now, it can be one of [UOP_COMP,UOP_LOAD,UOP_STORE,UOP_IMM,UOP_DUMMY]
    execUnit         = -1 #### exec unit in int type

    def __init__(self, _cxxType_prefix : str, _name       : str,
                       _inputSize      : int, _outputSize : int,
                       _uopType        : str, _execUnit : int
                 ):
        self.io_input       = oprLs.LISTOPR_BASE(_inputSize)
        self.io_output      = oprLs.LISTOPR_BASE(_outputSize)
        self.name           = _name
        self.cxxType_prefix = _cxxType_prefix
        self.uopType        = _uopType
        self.execUnit       = _execUnit
        #UOP_COMP,UOP_LOAD,UOP_STORE,UOP_IMM,
        ###### check that current uop depend on other successor uop
    def isSucInternalDepend(self,sucUop):
        for sucDesOpr in sucUop.io_output.getOprs():
            ###### check type that is temporaly register
            if type(sucDesOpr) is oprSm.OPR_TEMP:
                if sucDesOpr in self.io_input.getOprs():
                    return True
        return False

    ########## genCXX_allPossible will use it to check
    def isSyntasizable(self, input_oprs: tuple, output_oprs: tuple) -> bool:   ##### list of operand type
        ####### check sizing
        if (len(input_oprs) != self.io_input.getSize()) or (len(output_oprs) != self.io_output.getSize()):
            return False

        for idx, input_opr in enumerate(input_oprs):
            if type(input_opr) not in self.io_input.getAcceptableTypeOpr(idx):
                return False
        for idx, output_opr in enumerate(output_oprs):
            if type(output_opr) not in self.io_output.getAcceptableTypeOpr(idx):
                return False
        return True

    def addIo(self, _inputs: list, _outputs: list):
        ####### in this version we assume _input and _output is fully use
        self.io_input .setOprs(_inputs )
        self.io_output.setOprs(_outputs)
    def genCXXType(self) -> str:
        return "{PREFIX}${INPUT_KEY}${OUTPUT_KEY}${EXEC_UNIT}".format(
            PREFIX     = self.cxxType_prefix,
            INPUT_KEY  = self.io_input.genCXX_decodeKey(),
            OUTPUT_KEY = self.io_output.genCXX_decodeKey(),
            EXEC_UNIT  = str(self.execUnit)
        )

    def genCXXVarName(self) -> str:
        return self.namePrefix + "_" +self.name

    ####### paramlist for c++ that have variable type for example    "OPR_REG& r1, OPR_REG& r2, OPR_MEM& r3"
    def genCXX_refIoParamListDeclaration(self):
        preRet : str
        BothSide = (self.io_input.getSize() > 0) and (self.io_output.getSize() > 0)
        preRet = self.io_input.genCXX_refVarDeclaration() + \
                 (" ," if BothSide else " ") + \
                 self.io_output.genCXX_refVarDeclaration()
        return preRet

    def genCXX_callIoParamList(self):
        preRet : str
        BothSide = (self.io_input.getSize() > 0) and (self.io_output.getSize() > 0)
        preRet = self.io_input.genCXX_call() + \
                 (" ," if BothSide else " ") + \
                 self.io_output.genCXX_call()
        return preRet

    def genCXX_header(self):

        headerFile = "class {UOP_TYPE} : public {UOP_BASE_TYPE}{{\n" \
                     "public:\n" \
                     "  {UOP_TYPE}():UOP_BASE(){{}};\n" \
                     "  void doDepenCheck(UOP_WINDOW* uop_window) override;\n" \
                     "  void addMeta({PARAMLIST});\n" \
                     "}};".format(UOP_TYPE      = self.genCXXType(),
                                  UOP_BASE_TYPE = self.cxxTypeParent,
                                  PARAMLIST     = self.genCXX_refIoParamListDeclaration()
                                  )
        return headerFile

    def genCXX_cpp(self):
        ##### add operand to initialize method
        cppFile = "void {UOP_TYPE}::addMeta({PARAMLIST}){{\n".format(
                                            UOP_TYPE=self.genCXXType(),
                                            PARAMLIST=self.genCXX_refIoParamListDeclaration()
                                            )
        ######## for reg or mem operand lets it call operand and add it to dep group
        for opr in self.io_input.getOprs():
            cppFile = cppFile + "       " + opr.genCXX_callAddMeta() + ";\n"
        for opr in self.io_output.getOprs():
            cppFile = cppFile + "       " + opr.genCXX_callAddMeta() + ";\n"

        if self.execUnit < -1 :
            raise(UopUsageError(f"uop cpp generating fail! due to invalid exec_unit or forget to assign exec unit : {str(self.execUnit)}"))

        ######### set type and exec unit
        cppFile = cppFile + "       setUopType({UOP_TYPE});\n".format(UOP_TYPE = self.uopTypePrefix + "::" + self.uopType)
        cppFile = cppFile + "       setExecUnit({EXEC_UNIT_ID});\n".format(EXEC_UNIT_ID = self.execUnit)

        cppFile = cppFile + "}\n"



        ############################################################################
        ##### add do depend check function #### this is core of program
        cppFile = cppFile + \
            "void {UOP_TYPE}::doDepenCheck(UOP_WINDOW* uop_window){{\n".format(UOP_TYPE=self.genCXXType())

        if self.isAutodepenCheck:
            if oprSm.OPR_REG in self.io_input.getOprTypes():
                cppFile = cppFile + "   doRegDepenCheck(uop_window);\n"
            if (oprSm.OPR_MEM in self.io_input.getOprTypes()) or (oprSm.OPR_MEM in self.io_output.getOprTypes()):
                cppFile = cppFile + "   doMemDepenCheck(uop_window);\n"
        else:
            UopUsageError("manual depencheck is not available for this version")
        cppFile = cppFile + "}\n"
        ############################################################################

        return cppFile


    def genCXX_all(self):
            ######  uuid                   header            c++ code
            return self.genCXXType(), self.genCXX_header(), self.genCXX_cpp()


    # def genPseudoOpr(self, isInput : bool, opr_name_prefix: str):
    #     targetOprList  = self.io_input if isInput else self.io_output
    #     ###### it is list of set of operand type
    #     for oprs in itertools.product(*targetOprList.getAcceptableTypeOprs()):
    #         for idx, MY_OPR in enumerate(oprs):  #### MY_OPR is operand CLASS template
    #             if MY_OPR is oprSm.OPR_REG:
    #                 targetOprList.setOpr(idx, MY_OPR(opr_name_prefix + str(idx), isInput), True)
    #             elif MY_OPR is oprSm.OPR_MEM:
    #                 targetOprList.setOpr(idx, MY_OPR(opr_name_prefix + str(idx), isInput), True)
    #             elif MY_OPR is oprSm.OPR_TEMP:
    #                 targetOprList.setOpr(idx, MY_OPR(opr_name_prefix + str(idx))      , True)
    #             elif MY_OPR is oprSm.OPR_IMM:
    #                 targetOprList.setOpr(idx, MY_OPR(opr_name_prefix + str(idx))      , True)
    #             else:
    #                 ##### none type will occure here
    #                 UopUsageError(f"[UOP gen] can not set un recognize type as operand {MY_OPR}")
    #         yield
    #
    # def genCXX_allPossible(self):
    #     self.io_input.clearOprMember()
    #     self.io_output.clearOprMember()
    #     ########## in case both input and output have their at least one operand
    #     if (self.io_input.getSize()  != 0) and (self.io_output.getSize()  != 0):
    #         for _ in self.genPseudoOpr(True, "a"):
    #             for _ in self.genPseudoOpr(False, "b"):
    #                 yield self.genCXXType(), self.genCXX_header(), self.genCXX_cpp()
    #         return
    #     ########## in case there are only input but output is 0 membership
    #     if self.io_input.getSize() != 0:
    #         for _ in self.genPseudoOpr(True, "a"):
    #             yield self.genCXXType(), self.genCXX_header(), self.genCXX_cpp()
    #         return
    #
    #     ########## in case there are only output but output is 0 membership
    #     if self.io_output.getSize() != 0:
    #         for _ in self.genPseudoOpr(False, "b"):
    #             yield self.genCXXType(), self.genCXX_header(), self.genCXX_cpp()
    #         return
    #
    #     ########## in case there is no operand in uop
    #     yield self.genCXXType(), self.genCXX_header(), self.genCXX_cpp()
    #     return