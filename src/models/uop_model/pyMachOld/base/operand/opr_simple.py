import base.operand.opr_base as opr_base
import base.generator.header as hdr




class OPR_REG(opr_base.OPR_BASE):
    isSrc : False
    def getVarType(self):
        return OPR_REG

    def __init__(self, _name: str, _isSrc : bool):
        super().__init__(_name, "OPR_REG", False, "R", [hdr.CVAR_REGIDX], [_name + "subRegIdx"])
        ##### overide cxx type
        self.isSrc = _isSrc

    def genCXX_getFillMetaHelper_forVec(self, idxInGrp: int, uopOprSize: int, archOprSize: int) -> list:
        return [str(idxInGrp)]

    def genCXX_getMetaEnumToPush(self, **kwargs):
        return f"META_{'SRC' if self.isSrc else 'DES'}_MREG"

    def genCXX_getMetaTypeToPush(self, **kwargs):
        return "MREG_META"


class OPR_MEM(opr_base.OPR_BASE):

    isSrc = False
    def getVarType(self):
        return OPR_MEM

    def __init__(self, _name: str, _isSrc : bool):
        super().__init__(_name, "OPR_MEM", False, "M", [hdr.CVAR_ADDR  , hdr.CVAR_ADDR],
                                                       [_name + "b_byte_", _name + "e_byte_"])
                                                        #### for uniq situation
        self.isSrc = _isSrc

    def genCXX_getFillMetaHelper_forVec(self, idxInGrp: int, uopOprSize: int, archOprSize: int) -> list:
        return [str(idxInGrp*uopOprSize), str((idxInGrp+1)*uopOprSize)]

    def genCXX_getMetaEnumToPush(self, **kwargs):
        return f"META_{'SRC' if self.isSrc else 'DES'}_MEM"

    def genCXX_getMetaTypeToPush(self, **kwargs):
        return "MEM_META"

class OPR_TEMP(opr_base.OPR_BASE):
    kwargeforInitVar = "tregId" #### to initialize this class you must provide this kw type(int)
    kwargeForGetMetaEnumSide = "isSrc"

    def getVarType(self):
        return OPR_TEMP

    def __init__(self, _name: str):
        super().__init__(_name, "OPR_TREG", True, "T", [], [])

    def genCXX_typeInitializer(self, **kwargs) -> str:
        if (self.kwargeforInitVar in kwargs) and (type(kwargs[self.kwargeforInitVar]) == int):
            return "{TEMPTYPE}(START_TREGID + {INITVAL})".format(TEMPTYPE = self.genCXX_varType(),
                                                  INITVAL = kwargs[self.kwargeforInitVar])

    def genCXX_getMetaEnumToPush(self, **kwargs):
        isSrc = kwargs[self.kwargeForGetMetaEnumSide]
        return f"META_{'SRC' if isSrc else 'DES'}_TEMP"

    def genCXX_getMetaTypeToPush(self, **kwargs):
        return "TREG_META"

class OPR_IMM(opr_base.OPR_BASE):

    def getVarType(self):
        return OPR_IMM

    def __init__(self, _name: str, _isSrc: bool = True):
        super().__init__(_name, "OPR_IMM", False, "I", [], [])

    def genCXX_getMetaEnumToPush(self, **kwargs):
        return f"META_SRC_IMM"

    def genCXX_getMetaTypeToPush(self, **kwargs):
        return "IMM_META"

class OPR_DUMMY(opr_base.OPR_BASE):
    def getVarType(self):
        return OPR_DUMMY

    def __init__(self, _name: str):
        super().__init__(_name, "OPR_DUMMY", True, "X", [], [])