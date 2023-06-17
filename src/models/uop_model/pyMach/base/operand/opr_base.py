class OperandUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)




class OPR_BASE :
    name           : str #### name of variable in c++ w/o prefix (uniq)
    namePrefix     = "opr"
    cxxType        : str #### variable type in c++
    isInternal     : bool #### is operand is exposed to architecture instruction
    uniqDecodeName : str
    ### TODO dependency dectection

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

    ######### this is used inside uop only
    def genCXX_callAddMeta(self) -> str: ## for add meta data of operand to dep base class
        return "/* base class addMeta called */"

    ##### constructor
    def __init__(self, _name: str, _cxxType: str, _isInternal: bool, _uniqDecodeName : str):
        self.name = _name
        self.cxxType = _cxxType
        self.isInternal = _isInternal
        self.uniqDecodeName = _uniqDecodeName