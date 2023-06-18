import base.operand.opr_base as opr_base

TEMPLATE_REG_META  =  "addRegMeta ({REGNUM}, {DIREC})"
TEMPLATE_MEM_META_PHYAREA  =  "addMemMeta_phyArea ({ADAS}, {DIREC})"
TEMPLATE_MEM_META_VIRAREA  =  "addMemMeta_virArea ({ADAS}, {DIREC})"
TEMPLATE_MEM_META_STATIC  =  "addMemMeta_Static ({MEM_OPR_META})" ######
TEMPLATE_TREG_META =  "addTRegMeta({REGNUM}, {DIREC})"
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
        opr_base.OperandUsageError("addmeta for mem is migrate to genCXX_callAddMeta_{Area, Static}")

    def genCXX_callAddMeta_phyArea(self) -> str:
        preRet = TEMPLATE_MEM_META_PHYAREA.format(
            ADAS = self.genCXX_varCall() + ".getMeta_phyArea()",
            DIREC = "true" if self.isSrc else "false"
        )
        return preRet

    def genCXX_callAddMeta_virArea(self) -> str:
        preRet = TEMPLATE_MEM_META_VIRAREA.format(
            ADAS=self.genCXX_varCall() + ".getMeta_virArea()",
            DIREC="true" if self.isSrc else "false"
        )
        return preRet

    def genCXX_callAddMeta_Static(self) -> str:
        preRet = TEMPLATE_MEM_META_STATIC.format(
            MEM_OPR_META = self.genCXX_varCall() + ".getMeta_Static()",
        )
        return preRet

class OPR_TEMP(opr_base.OPR_BASE):
    kwargeforInitVar = "tregId" #### to initialize this class you must provide this kw type(int)

    def getVarType(self):
        return OPR_TEMP

    def __init__(self, _name: str):
        super().__init__(_name, "OPR_TREG", True, "T")

    def genCXX_typeInitializer(self, **kwargs) -> str:
        if (self.kwargeforInitVar in kwargs) and (type(kwargs[self.kwargeforInitVar]) == int):
            return "{TEMPTYPE}({INITVAL})".format(TEMPTYPE = self.genCXX_varType(),
                                                  INITVAL = kwargs[self.kwargeforInitVar])

    def genCXX_callAddMeta(self, isSrc) -> str:
        raise opr_base.OperandUsageError("can not call add meta for temp operand. Please use genCXX_callAddMetaWithDirec instead.")

    def genCXX_callAddMetaWithDirec(self, isSrc)-> str:
        preRet = TEMPLATE_TREG_META.format(
            REGNUM=self.genCXX_varCall() + "." + "getMeta()",
            DIREC="true" if isSrc else "false"
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
