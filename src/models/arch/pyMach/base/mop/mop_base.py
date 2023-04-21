import base.operand.listOpr as oprLs

class MopUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)


class MOP_BASE:
    io_input       : oprLs.LISTOPR_BASE
    io_output      : oprLs.LISTOPR_BASE
    temp_opr       : oprLs.LISTOPR_BASE  ##### temporary operand which shared with uopList
    uopList        : list()
    uopInterDep    : list()

    cxxType_prefix = "MOP_CHILD"
    cxxTypeParent  = "MOP_BASE"

    def __init__(self, _name : str, _inputSize : int, _outputSize : int):
        self.io_input  = oprLs.LISTOPR_BASE(_inputSize)
        self.io_output = oprLs.LISTOPR_BASE(_outputSize)

    def genUopDep(self):
        self.uopInterDep = [[] for _ in range(len(self.uopList))]

        ##### please remind that temporary register is expected to shared producer
        for cur_idx, cur_uop in enumerate(self.uopList):
            for suc_uop in self.uopList[0: cur_idx]:
                if cur_uop.isSucInternalDepend(suc_uop):
                    self.uopInterDep[cur_idx].append(cur_uop)

    def genCXXType(self)-> str:
        return "{PREFIX}${INPUT_KEY}${OUTPUT_KEY}".format(
            PREFIX     = self.cxxType_prefix,
            INPUT_KEY  = self.io_input.genCXX_decodeKey(),
            OUTPUT_KEY = self.io_output.genCXX_decodeKey()
        )


    def genCXX_header(self):
        headerFile =\
            "class {MOP_TYPE} : public MOP_BASE{{\n" \
            "public:\n" \
            "\n" \
            "   void genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr) override;\n"\
            "}};".format(MOP_TYPE = self.genCXXType())

        return headerFile

    def genCXX_cpp(self):
        cppFile = "void {MOP_TYPE}::genUop(std::vector<UOP_BASE*>& results, RT_INSTR* _rt_instr){{\n" \
                  "    MAIN_STAT[\"mopGen\"][\"{MOP_TYPE}\"].asUINT()++;\n".\
                    format(MOP_TYPE = self.genCXXType())

        cppFile = cppFile + \
                  "    auto srcPool = rt_instr->getSrcMacroPoolOperands();\n" \
                  "    auto desPool = rt_instr->getDesMacroPoolOperands();\n"

        ##########################################################################################
        ##### new represent SRC EXTERNAL operand
        for idx, opr in enumerate(self.io_input.getOprs()):
            ###### declare variable with ref type
             cppFile = cppFile + "{VAR_REF_DECLARE} = * (({VAR_TYPE}*)srcPool[idx])\n"\
                                    .format(VAR_REF_DECLARE = opr.genCXX_refVarDeclaration(),
                                            VAR_TYPE        = opr.genCXX_varType()
                                            )
        ##### new represent DES EXTERNAL operand
        for idx, opr in enumerate(self.io_output.getOprs()):
            ###### declare variable with ref type
             cppFile = cppFile + "{VAR_REF_DECLARE} = * (({VAR_TYPE}*)desPool[idx]);\n"\
                                    .format(VAR_REF_DECLARE = opr.genCXX_refVarDeclaration(),
                                            VAR_TYPE        = opr.genCXX_varType()
                                            )
        ##### new variable SRC/DES operand
        for idx, opr in enumerate(self.temp_opr.getOprs()):
            ###### declare variable with ref type
             cppFile = cppFile + "{VAR_REF_DECLARE} = * (({VAR_TYPE}*)new {VAR_TYPE}());\n"\
                                    .format(VAR_REF_DECLARE = opr.genCXX_refVarDeclaration(),
                                            VAR_TYPE        = opr.genCXX_varType()
                                            )
        ##########################################################################################
        ##### generate for each uop and connect dependency to it
        for idx, currentUop in enumerate(self.uopList):
            cppFile = cppFile + \
                "    auto {UOP_NAME} = new {UOP_TYPE}();\n" \
                "    {UOP_NAME}->addMeta({PARAM});\n"\
                    .format(UOP_NAME = currentUop.genCXXVarName(),
                            UOP_TYPE = currentUop.genCXXType(),
                            PARAM    = currentUop.genCXX_callIoParamList()
                            )
            for depIdx, currentDep in enumerate(self.uopList[idx]):
                cppFile = cppFile + \
                    "    {UOP_NAME}->addTemDep({DEP_UOP_NAME})\n".format(UOP_NAME = currentUop.genCXXVarName(),
                                                                       DEP_UOP_NAME = currentDep[depIdx].genCXXVarName()
                                                                       )
            cppFile = cppFile + "///////////////////////////////////////////////////////////////////"

        cppFile = cppFile + "}}\n"
        ##########################################################################################
        return cppFile