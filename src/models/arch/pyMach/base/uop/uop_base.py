###### temporary
import base.operand.listOpr as oprLs
import base.operand.opr_simple as oprSm


class UopUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)


class UOP_BASE:
    io_input       : oprLs.LISTOPR_BASE
    io_output      : oprLs.LISTOPR_BASE
    name           : str
    namePrefix     = "uop"
    cxxType_prefix = "UOP_CHILD" #### please remind that cxxType is not finally
    cxxTypeParent = "UOP_BASE"

    def __init__(self, _name : str,_inputSize: int, _outputSize   : int):
        self.io_input  = oprLs.LISTOPR_BASE(_inputSize)
        self.io_output = oprLs.LISTOPR_BASE(_outputSize)
        self.name      = _name

        ###### check that current uop depend on other successor uop
    def isSucInternalDepend(self,sucUop):
        for sucDesOpr in sucUop.io_output.getOprs():
            ###### check type that is temporaly register
            if type(sucDesOpr) == oprSm.OPR_TEMP:
                if sucDesOpr in self.io_input.getOprs():
                    return True
        return False

    def genCXXType(self) -> str:
        return "{PREFIX}${INPUT_KEY}${OUTPUT_KEY}".format(
            PREFIX     = self.cxxType_prefix,
            INPUT_KEY  = self.io_input.genCXX_decodeKey(),
            OUTPUT_KEY = self.io_output.genCXX_decodeKey()
        )

    def genCXXVarName(self) -> str:
        return self.namePrefix + "_" +self.name


    def genCXX_header(self):
        headerFile = "class {UOP_TYPE} : public {UOP_BASE_TYPE}{{\n" \
                     "public:\n" \
                     "  {UOP_TYPE}();\n" \
                     "  void doDepenCheck(UOP_WINDOW* uop_window) override;\n" \
                     "  void addMeta({PARAMLIST})\n" \
                     "}};".format(UOP_TYPE = self.genCXXType(),
                                  UOP_BASE_TYPE = self.cxxTypeParent,
                                  PARAMLIST = self.genCXX_refIoParamListDeclaration()
                                  )
        return headerFile

    def genCXX_cpp(self):
        ##### add operand to initialize method
        cppFile = "void {UOP_TYPE}::addMeta({PARAMLIST}){{\n".format(
                                            UOP_TYPE=self.genCXXType(),
                                            PARAMLIST=self.genCXX_refIoParamListDeclaration()
                                            )

        for opr in self.io_input.getOprs():
            cppFile = cppFile + "       " + opr.genCXX_callAddMeta() + ";\n"
        for opr in self.io_output.getOprs():
            cppFile = cppFile + "       " + opr.genCXX_callAddMeta() + ";\n"
        cppFile = cppFile + "}}\n"
        ############################################################################
        ##### add do depend check function #### this is core of program
        cppFile = cppFile + \
            "void {UOP_TYPE}::doDepenCheck(UOP_WINDOW* uop_window){{\n"

        for opr in self.io_input.getOprs():
            for myDepend in opr.genCXX_callDependCheck():
                cppFile = cppFile + "       " + myDepend + ";\n"
        for opr in self.io_output.getOprs():
            for myDepend in opr.genCXX_callDependCheck():
                cppFile = cppFile + "       " + myDepend + ";\n"

        cppFile = cppFile + "}}\n"
        ############################################################################

        return cppFile

    ####### paramlist for c++ that have variable type for example    "OPR_REG& r1, OPR_REG& r2, OPR_MEM& r3"
    def genCXX_refIoParamListDeclaration(self):
        preRet : str
        BothSide = (self.io_input.getSize() > 0) and (self.io_output.getSize() > 0)
        preRet = self.io_input.genCXX_refVarDeclaration() + \
                 " ," if BothSide else " " + \
               self.io_output.genCXX_refVarDeclaration()
        return preRet

    def genCXX_callIoParamList(self):
        preRet : str
        BothSide = (self.io_input.getSize() > 0) and (self.io_output.getSize() > 0)
        preRet = self.io_input.genCXX_call() + \
                 " ," if BothSide else " " + \
                 self.io_output.genCXX_call()
        return preRet