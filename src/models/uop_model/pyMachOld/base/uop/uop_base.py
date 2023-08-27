###### temporary
import base.operand.listOpr as oprLs
import base.operand.opr_simple as oprSm
import base.dep.dep as dep

class UopUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)





class UOP_BASE:
    io_input          : oprLs.LISTOPR_BASE
    io_input_metaArgs : list ##### list of args list to build config when uop need to get meta data
    io_output         : oprLs.LISTOPR_BASE
    io_output_metaArgs: list ##### list of args list to build config when uop need to get meta data
    name              : str
    namePrefix        = "uop"
    uopTypePrefix     = "UOP_TYPE"
    cxxType_prefix    = "UOP_CHILD" #### please remind that cxxType is not finally
    cxxTypeParent     = "UOP_BASE"
    isAutodepenCheck  = True
    ############ for uop infomation
    uopType           = "UOP_DUMMY" #### for now, it can be one of [UOP_COMP,UOP_LOAD,UOP_STORE,UOP_IMM,UOP_DUMMY]
    execUnit          = -1 #### exec unit in int type

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

        self.addMetaArgs([[] for i in range(self.io_input.size)],
                         [[] for i in range(self.io_output.size)]
                        )

        #UOP_COMP,UOP_LOAD,UOP_STORE,UOP_IMM,
        ###### check that current uop depend on other successor uop
    def isPreInternalDepend(self,preUop):
        for preDesOpr in preUop.io_output.getOprsWoDummy():
            ###### check type that is temporaly register
            if type(preDesOpr) is oprSm.OPR_TEMP:
                if preDesOpr in self.io_input.getOprsWoDummy():
                    return True
        return False

    def checkMetaArgs(self, oprList: oprLs.LISTOPR_BASE, argsList: list):
        if oprList.size != len(argsList):
            raise UopUsageError("amount of args for generate not match")
        for idx, opr in enumerate(oprList.getOprsWoDummy()):
            if not opr.checkAddMetaArgsValid(argsList[idx]):
                raise UopUsageError("check args error with {OPR} with {ARG}".format(OPR = opr,ARG =  argsList[idx]))


    def addIo(self, _inputs: list, _outputs: list):
        ####### in this version we assume _input and _output is fully use
        ######### metaDataArgs is list of args list which correspond with uop
        self.io_input .setOprs(_inputs )
        self.io_output.setOprs(_outputs)
        ###### set argument for get meta data

    def addMetaArgs(self, _io_input_metaArgs: list, _io_output_metaArgs: list):
        self.io_input_metaArgs = _io_input_metaArgs
        self.io_output_metaArgs = _io_output_metaArgs
        #self.checkMetaArgs(self.io_input, self.io_input_metaArgs)
        #self.checkMetaArgs(self.io_output, self.io_output_metaArgs)


    #### get value to fill this should be used from mop NOT in UOP generating
    def genCXX_addMetaArgFill(self, isSrc: bool):
        isFirst = True
        flatAllEle = []
        for metaParam in self.io_input_metaArgs if isSrc else self.io_output_metaArgs:
            eachEle = ", ".join(metaParam)
            if len(eachEle) > 0:
                flatAllEle.append(eachEle)


        return ", ".join(flatAllEle)

    def genCXX_callAddMetaUopFromMop(self):
        preWriteList = [ self.io_input.genCXX_call() + "\n"     , self.io_output.genCXX_call() + "\n",
                         self.genCXX_addMetaArgFill(True) + "\n", self.genCXX_addMetaArgFill(False) ]
        preWriteList = list(filter(lambda x: len(x) > 0 and x != "\n", preWriteList))

        return ", ".join(preWriteList)



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
    def genCXX_declareAddMetaParamList(self):
        decAddMetaParamPool = [self.io_input.genCXX_refVarDeclaration(), self.io_output.genCXX_refVarDeclaration(),
                               self.io_input.genCXX_addMetaArgsDeclaration(), self.io_output.genCXX_addMetaArgsDeclaration()
                               ]
        #print(decAddMetaParamPool)
        decAddMetaParamPool = list(filter(lambda x: len(x) > 0, decAddMetaParamPool))
        #print(decAddMetaParamPool)
        return ", ".join(decAddMetaParamPool)

    ###### this is used by mop to config and init by operand
    # def genCXX_callAddMetaParamList(self):
    #
    #     ##### add operand to initialize method
    #     addMetaParamPool = [self.io_input.genCXX_call()           , self.io_output.genCXX_call(),
    #                         self.io_input.genCXX_addMetaArgsCall(), self.io_output.genCXX_addMetaArgsCall()]
    #     addMetaParamPool = list(filter(lambda x: len(x) > 0, addMetaParamPool))
    #     return ", ".join(addMetaParamPool)


    def genCXX_header(self):

        headerFile = "class {UOP_TYPE} : public {UOP_BASE_TYPE}{{\n" \
                     "public:\n" \
                     "  {UOP_TYPE}():UOP_BASE(){{}};\n" \
                     "  void doPlannedDepenCheck(UOP_WINDOW* uop_window) override;\n" \
                     "  void addMeta({PARAMLIST});\n" \
                     "}};".format(UOP_TYPE      = self.genCXXType(),
                                  UOP_BASE_TYPE = self.cxxTypeParent,
                                  PARAMLIST     = self.genCXX_declareAddMetaParamList()
                                  )
        return headerFile

    def genCXX_cpp(self):


        cppFile = "void {UOP_TYPE}::addMeta({PARAMLIST}){{\n".format(
                                            UOP_TYPE=self.genCXXType(),
                                            PARAMLIST=self.genCXX_declareAddMetaParamList()
                                            )
        ######## for reg or mem operand lets it call operand and add it to dep group
        cppFile = cppFile + "///////////////// add meta data\n"
        for idx, opr in enumerate(self.io_input.getOprsWoDummy()):

            cppFile = cppFile + "       " + "getMetaPtr<{METACLASS},{METATYPE}>()->addMeta({GETMETA});\n"\
                .format(
                    METACLASS = opr.genCXX_getMetaEnumToPush(isSrc = True),
                    METATYPE  = opr.genCXX_getMetaTypeToPush(),
                    GETMETA   = opr.genCXX_callAddMeta()
                )

        for idx, opr in enumerate(self.io_output.getOprsWoDummy()):
            cppFile = cppFile + "       " + "getMetaPtr<{METACLASS},{METATYPE}>()->addMeta({GETMETA});\n" \
                .format(
                METACLASS=opr.genCXX_getMetaEnumToPush(isSrc = True),
                METATYPE=opr.genCXX_getMetaTypeToPush(),
                GETMETA=opr.genCXX_callAddMeta()
            )
        cppFile = cppFile + "///////////////// finish meta data\n"

        if self.execUnit < -1 :
            raise(UopUsageError(f"uop cpp generating fail! due to invalid exec_unit or forget to assign exec unit : {str(self.execUnit)}"))

        ######### set type and exec unit
        cppFile = cppFile + "       setUopType({UOP_TYPE});\n".format(UOP_TYPE = self.uopTypePrefix + "::" + self.uopType)
        cppFile = cppFile + "       setExecUnit({EXEC_UNIT_ID});\n".format(EXEC_UNIT_ID = self.execUnit)

        cppFile = cppFile + "}\n"



        ############################################################################
        ##### add do depend check function #### this is core of program
        cppFile = cppFile + \
            "void {UOP_TYPE}::doPlannedDepenCheck(UOP_WINDOW* uop_window){{\n".format(UOP_TYPE=self.genCXXType())

        if self.isAutodepenCheck:
            if oprSm.OPR_REG in self.io_input.getOprTypesWoDummy():
                cppFile = cppFile + "   doDepenCheck<{DEPCLASS}>(uop_window);\n".format(DEPCLASS = dep.oprTypeToDepClassMap[oprSm.OPR_REG])
            if (oprSm.OPR_MEM in self.io_input.getOprTypesWoDummy()) or (oprSm.OPR_MEM in self.io_output.getOprTypesWoDummy()):
                cppFile = cppFile + "   doDepenCheck<{DEPCLASS}>(uop_window);\n".format(DEPCLASS = dep.oprTypeToDepClassMap[oprSm.OPR_MEM])
            cppFile = cppFile + "   doDepenCheck<{DEPCLASS}>(uop_window);\n".format(DEPCLASS = dep.DEPCLASS_DEP_EXEC_UNIT)
        else:
            UopUsageError("manual depencheck is not available for this version")
        cppFile = cppFile + "}\n"
        ############################################################################

        return cppFile


    def genCXX_all(self):
            ######  uuid                   header            c++ code
            return self.genCXXType(), self.genCXX_header(), self.genCXX_cpp()