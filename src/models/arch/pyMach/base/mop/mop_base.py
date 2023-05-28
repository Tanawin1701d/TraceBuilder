import base.operand.listOpr as oprLs
import base.operand.opr_simple as oprSim

class MopUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)


class MOP_BASE:
    io_input       : oprLs.LISTOPR_BASE
    io_output      : oprLs.LISTOPR_BASE
    temp_opr       : oprLs.LISTOPR_BASE  ##### temporary operand which shared with uopList
    uopList        : list
    decKeys        : list
    uopInterDep    : list ## list of list which contains dependent precedence uop

    cxxType_prefix = "MOP_CHILD"
    cxxTypeParent  = "MOP_BASE"


    def autoInit(self, _cxxType_prefix : str, _inputs:list, _outputs:list, _temp:list, _uops:list, _decKeys: list):
        self.cxxType_prefix = _cxxType_prefix
        ####### initialize mainStructure

        ######## set input operand
        self.io_input = oprLs.LISTOPR_BASE(len(_inputs))
        self.io_input.autoInit(_inputs)
        ######## set output operand
        self.io_output = oprLs.LISTOPR_BASE(len(_outputs))
        self.io_output.autoInit(_outputs)
        ######## set temporary operand
        self.temp_opr = oprLs.LISTOPR_BASE(len(_temp))
        self.temp_opr.autoInit(_temp)
        ######## set uops
        self.uopList  = _uops
        ######## set decoder Key
        self.decKeys = _decKeys

    def getUops(self):
        return self.uopList

    def genUopDep(self):
        self.uopInterDep = [[] for _ in range(len(self.uopList))]

        ##### please remind that temporary register is expected to shared producer
        for cur_idx, cur_uop in enumerate(self.uopList):
            for suc_uop in self.uopList[0: cur_idx]:
                if cur_uop.isSucInternalDepend(suc_uop):
                    self.uopInterDep[cur_idx].append(cur_uop)

    def genCXXType(self)-> str: ### also used in c++
        return "{PREFIX}${INPUT_SUFFIX}${OUTPUT_SUFFIX}".format(
            PREFIX           = self.cxxType_prefix,
            INPUT_SUFFIX     = self.io_input.genCXX_decodeKey(),
            OUTPUT_SUFFIX    = self.io_output.genCXX_decodeKey(),
        )

    ##### this is seperated by $
    def genCXX_decodeKey(self) -> list:
        preResult = []
        for decodeKey in self.decKeys:
            preResult.append("{INSTR_PREFIX}${INPUT_KEY}${OUTPUT_KEY}".format(
                INSTR_PREFIX = decodeKey,
                INPUT_KEY  = self.io_input.genCXX_decodeKey(),
                OUTPUT_KEY = self.io_output.genCXX_decodeKey(),
            ))
        return preResult

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
                  "    auto srcPool = _rt_instr->getSrcMacroPoolOperands();\n" \
                  "    auto desPool = _rt_instr->getDesMacroPoolOperands();\n"

        ##########################################################################################
        ##### new represent SRC EXTERNAL operand
        for idx, opr in enumerate(self.io_input.getOprs()):
            ###### declare variable with ref type
             cppFile = cppFile + "    {VAR_REF_DECLARE} = * (({VAR_TYPE}*)srcPool[{IDX}]);\n"\
                                    .format(VAR_REF_DECLARE = opr.genCXX_refVarDeclaration(),
                                            VAR_TYPE        = opr.genCXX_varType(),
                                            IDX             =  str(idx)
                                            )
        ##### new represent DES EXTERNAL operand
        for idx, opr in enumerate(self.io_output.getOprs()):
            ###### declare variable with ref type
             cppFile = cppFile + "    {VAR_REF_DECLARE} = * (({VAR_TYPE}*)desPool[{IDX}]);\n"\
                                    .format(VAR_REF_DECLARE = opr.genCXX_refVarDeclaration(),
                                            VAR_TYPE        = opr.genCXX_varType(),
                                            IDX=str(idx)
                                            )
        ##### new variable TEMP operand
        for idx, opr in enumerate(self.temp_opr.getOprs()):
            ###### declare variable with ref type
             cppFile = cppFile + "    {VAR_DECLARE};\n"\
                                    .format(VAR_DECLARE = opr.genCXX_varDeclaration(),
                                            )
        cppFile = cppFile + "///////////////////////////////////////////////////////////////////\n"
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
            for depMop in self.uopInterDep[idx]:
                cppFile = cppFile + \
                    "    {UOP_NAME}->addTemDep({DEP_UOP_NAME});\n".format(UOP_NAME = currentUop.genCXXVarName(),
                                                                       DEP_UOP_NAME = depMop.genCXXVarName()
                                                                       )
            cppFile = cppFile + \
                "    results.push_back({UOP_NAME});\n".format(UOP_NAME = currentUop.genCXXVarName())
            cppFile = cppFile + "///////////////////////////////////////////////////////////////////\n"

        cppFile = cppFile + "\n}\n"
        ##########################################################################################
        return cppFile

    def genCXX_all(self):
        self.genUopDep()
        return self.genCXXType(), self.genCXX_header(), self.genCXX_cpp()