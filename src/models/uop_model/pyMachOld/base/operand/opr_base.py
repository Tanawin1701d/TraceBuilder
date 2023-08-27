class OperandUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)


TEMPLATE_GET_META  =  "{OPR_NAME}.getMeta({ARGS})"


class OPR_BASE :
    name               : str #### name of variable in c++ w/o prefix (uniq)
    namePrefix         = "opr"
    cxxType            : str #### variable type in c++
    isInternal         : bool #### is operand is exposed to architecture instruction
    uniqDecodeName     : str
    addMetaArgsType    : list ##### list of args type that needed to get meta data
    addMetaArgsVarName : list ##### name of args type that needed to get meta data

    def checkAddMetaArgsValid(self, arg: list):
        return len(arg) == len(self.addMetaArgsType)

    ##### get variable type
    def getVarType(self): ### overidable
        return None
    def getUniqDecodeName(self) -> str:
        return self.uniqDecodeName
    ##### get variable type in string (c++)
    def genCXX_varType(self):
        return self.cxxType

    ##### generate c++ variable declaration
    def genCXX_refVarDeclaration(self) -> str: ### overidable
        if len(self.cxxType) == 0:
            raise OperandUsageError("can not using this operand")
        return f"{self.cxxType}& {self.namePrefix}_{self.name}"

    ##### generate c++ variable declaration
    def genCXX_varDeclaration(self) -> str:
        if len(self.cxxType) == 0:
            raise OperandUsageError("can not using this operand")
        return f"{self.cxxType} {self.namePrefix}_{self.name}"

    ##### generate c++ class constructor for operand
    def genCXX_typeInitializer(self, **kwargs) -> str:
            raise OperandUsageError("can not initialize variable in this case")

    def genCXX_varCall(self) -> str:   ###### also var name
        if len(self.name) == 0:
            raise OperandUsageError("can not call this operand due to unnamed")
        return f"{self.namePrefix}_{self.name}"

    ######### this is in meta data
    def genCXX_callAddMeta(self) -> str: ## for add meta data of operand to dep base class
        return TEMPLATE_GET_META.format(OPR_NAME=self.genCXX_varCall(),ARGS=self.genCXX_getMetaCallArgs())


    #### gen ref var declaration to config get metadata
    def genCXX_getMetaVarArgsDeclaration(self):
        ziped = zip(self.addMetaArgsType, self.addMetaArgsVarName)
        return ", ".join("{t} {vn}".format(t = t, vn = vn) for t, vn in ziped)


    #### gen call var declaration to config get metadata
    def genCXX_getMetaCallArgs(self):
        return ", ".join("{vn}".format(vn = vn) for vn in self.addMetaArgsVarName)

    def genCXX_getMetaEnumToPush(self, **kwargs):
        return "INVLID_ENUM"
    def genCXX_getMetaTypeToPush(self, **kwargs):
        return "INVALID_STRUCT"

    #### uop use this fucntion to get value that should be added to meta get method
    def genCXX_getFillMetaHelper_forVec(self, idxInGrp: int, uopOprSize: int, archOprSize: int) -> list:
        return list()



    ##### constructor
    def __init__(self, _name: str,
                       _cxxType: str,
                       _isInternal: bool,
                       _uniqDecodeName : str,
                       _addMetaArgsType : list,
                       _addMetaArgsVarName : list):
        self.name               = _name
        self.cxxType            = _cxxType
        self.isInternal         = _isInternal
        self.uniqDecodeName     = _uniqDecodeName
        self.addMetaArgsType    = _addMetaArgsType.copy()
        self.addMetaArgsVarName = _addMetaArgsVarName.copy()