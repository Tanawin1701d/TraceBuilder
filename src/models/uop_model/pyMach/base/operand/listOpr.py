import base.operand.opr_simple as opr_simple
class ListOprUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)


#####################################################################
####dummy Operand handler protocol
######### dummy can occur only last consecutive index at operand list
#####################################################################
class LISTOPR_BASE :
    acceptableType: list
    opr_ele       : list #### operand element
    opr_type      : list #### operand type
    size          : int  #### operand type

    def __init__(self, _size: int):
        self.initializeStructure(_size)

    ###### auto initialize with sample operand
    def  autoInit(self, _inputs):
        self.addAcceptTypes     ([{type(my_opr)} for my_opr  in _inputs ])
        self.setOprs            (_inputs)
        self.checkModelIntegrity()

    def initializeStructure(self, _size: int):
        if _size < 0:
            raise ListOprUsageError("can not create list that size less than 0")
        self.size = _size
        self.acceptableType = [set() for _ in range(self.size)]
        self.opr_ele  = [None for _ in range(self.size)]
        self.opr_type = [None for _ in range(self.size)]

    ###### add accept type to input list
    def addAcceptTypes(self, newAcceptList: list):
        ##### check type
        if len(newAcceptList)  > self.size:
            raise ListOprUsageError(f"can not addAcceptType "
                                    f"more than declared size: {self.size}")
        for st in newAcceptList :
            if type(st) is not set:
                raise ListOprUsageError(f"can not addAcceptType with invalid argument args:{st}")
            ### we might set errror for invalid type in set

        for oprIdx, acceptSet in enumerate(newAcceptList) :
            self.addAcceptType(oprIdx, acceptSet)

    def addAcceptType(self, idx: int, setOfPerOprType: set):
        if idx > self.size:
            raise ListOprUsageError(f"can not addAccepttype more than declared size: {self.size}")
        self.acceptableType[idx] = self.acceptableType[idx] = \
            self.acceptableType[idx].union(setOfPerOprType)
    ##############################################################################################
    ##### add (aka set) operand to input/output list
    def setOprs(self, newAddOpr: list):
        ###### check size
        if len(newAddOpr) > self.size:
            raise ListOprUsageError(f"can not addOprs size:{self.size}")

        for idx, opr in enumerate(newAddOpr):
            self.setOpr(idx, opr, True)

    def setOpr(self, idx: int, opr, force : bool):
        if idx > self.size:
            raise ListOprUsageError(f"can not addOpr idx:{idx}")
        if (not force) and (self.opr_ele[idx] is not None):
            raise ListOprUsageError(f"can not addOpr because it is exist already idx:{self.size}")
        if type(opr) not in self.acceptableType[idx]:
            raise ListOprUsageError(f"can not addOpr idx:{idx} due to invalid type")

        self.opr_ele [idx] = opr
        self.opr_type[idx] = type(opr)
    ##############################################################################################
    ####### get method
    def getOprs(self):
        return self.opr_ele

    def getOprsWoDummy(self):
        self.checkModelIntegrity()
        return self.opr_ele[:self.getDummyStartIdx()]

    def getOpr(self, idx: int):
        if idx > self.size:
            raise ListOprUsageError(f"can not get Opr with idx {idx}")
        return self.opr_ele[idx]

    def getAcceptableTypeOprs(self) -> list:
        return self.acceptableType

    def getAcceptableTypeOpr(self, idx) -> list:
        if idx > self.size:
            raise ListOprUsageError(f"can not get acceptable with idx {idx}")
        return self.acceptableType[idx]

    def getOprTypes(self):
        return self.opr_type

    def getOprTypesWoDummy(self):
        return self.opr_type[:self.getDummyStartIdx()]

    def getOprType(self, idx) -> list:
        if idx > self.size:
            raise ListOprUsageError(f"can not get operand type with idx {idx}")
        return self.acceptableType[idx]

    def getSize(self):
        return self.size

    def getSizeWoDummy(self):
        return self.getDummyStartIdx()

    def getDummyStartIdx(self):
        try:
            index = self.opr_type.index(opr_simple.OPR_DUMMY)
            return index
        except ValueError:
            return self.size

    def clearOprMember(self):
        for idx in range(self.size):
            self.opr_ele[idx]  = None
            self.opr_type[idx] = None

    ##############################################################################################
    ####### gen cxx method
    def genCXX_refVarDeclaration(self) -> str:
        return ", ".join([oprRef.genCXX_refVarDeclaration() for oprRef in self.opr_ele[:self.getDummyStartIdx()]])

    def genCXX_call(self) -> str:
        return ", ".join([opr.genCXX_varCall() for opr in self.opr_ele[:self.getDummyStartIdx()]])

    def genCXX_decodeKey(self) -> str:
        return "_".join([opr.getUniqDecodeName() for opr in self.getOprsWoDummy()])
    ##############################################################################################
    ######## manner checking
    def checkModelIntegrity(self):
        dummy_occur = False
        for iter_type in self.opr_type:
            if iter_type == opr_simple.OPR_DUMMY:
                dummy_occur = True
                continue
            if (iter_type != opr_simple.OPR_DUMMY) and dummy_occur:
                raise ListOprUsageError("dummy opr occur in invalid order ; {OPRTYPE}".format(OPRTYPE = self.opr_type))