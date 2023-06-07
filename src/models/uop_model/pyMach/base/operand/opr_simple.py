import base.operand.opr_base as opr_base

TEMPLATE_REG_META  =  "addRegMeta ({REGNUM}, {DIREC})"
TEMPLATE_MEM_META  =  "addMemMeta ({ADAS}, {DIREC})"
TEMPLATE_TREG_META =  "addTRegMeta({REGNUM})"
TEMPLATE_DEPEND_REG_CHECK = "doRegDepenCheck({WINDOW_NAME})"
TEMPLATE_DEPEND_MEM_CHECK = "doRegDepenCheck({WINDOW_NAME})"

class OPR_REG(opr_base.OPR_BASE):
    isSrc : False
    def getVarType(self):
        return OPR_REG

    def __init__(self, _name: str, _isSrc : bool):
        super().__init__(_name, "OPR_REG", False, "R")
        ##### overide cxx type
        self.isSrc = _isSrc
    ###### generate adding meta data to uop
    def genCXX_callAddMeta(self) -> str:
        preRet = TEMPLATE_REG_META.format(
                    REGNUM = self.genCXX_varCall()+"."+"getMeta()",
                    DIREC  =   "true" if self.isSrc else "false"
                                            )
        return preRet



class OPR_MEM(opr_base.OPR_BASE):

    isSrc = False
    def getVarType(self):
        return OPR_MEM

    def __init__(self, _name: str, _isSrc : bool):
        super().__init__(_name, "OPR_MEM", False, "M")
        self.isSrc = _isSrc

    def genCXX_callAddMeta(self) -> str:
        preRet = TEMPLATE_MEM_META.format(
                    ADAS = self.genCXX_varCall()+"."+"getMeta()",
                    DIREC  =   "true" if self.isSrc else "false"
                                            )
        #print("ddfdf", preRet)
        return preRet


class OPR_TEMP(opr_base.OPR_BASE):

    def getVarType(self):
        return OPR_TEMP

    def __init__(self, _name: str):
        super().__init__(_name, "OPR_TREG", True, "T")

    def genCXX_callAddMeta(self) -> str:
        preRet = TEMPLATE_TREG_META.format(
                    REGNUM = self.genCXX_varCall()+"."+"getMeta()"
                                            )
        return preRet

class OPR_IMM(opr_base.OPR_BASE):

    def getVarType(self):
        return OPR_IMM

    def __init__(self, _name: str):
        super().__init__(_name, "OPR_IMM", False, "I")

    def genCXX_callAddMeta(self) -> str:
        return "/* imm had no meta data*/"


class OPR_DUMMY(opr_base.OPR_BASE):
    def getVarType(self):
        return OPR_DUMMY

    def __init__(self, _name: str):
        super().__init__(_name, "OPR_DUMMY", True, "X")

    def genCXX_callAddMeta(self) -> str:
        raise opr_base.OperandUsageError("can not call addMeta in DUMMY OPERAND")
