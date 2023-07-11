import base.operand.opr_simple as oprSm
CENUM_META_SRC_REG   = "META_SRC_MREG"
CENUM_META_SRC_TEMP  = "META_SRC_TEMP"
CENUM_META_SRC_MEM   = "META_SRC_MEM"
CENUM_META_DES_REG   = "META_DES_MREG"
CENUM_META_DES_TEMP  = "META_DES_TEMP"
CENUM_META_DES_MEM   = "META_DES_MEM"

oprTypeToStr = {
    oprSm.OPR_REG : "MREG",
    oprSm.OPR_MEM : "MEM",
    oprSm.OPR_TEMP: "TEMP",
    oprSm.OPR_IMM : "IMM"
}

oprTypeToMetaType = {
   oprSm.OPR_REG : "MREG_META",
   oprSm.OPR_MEM : "MEM_META",
   oprSm.OPR_TEMP: "TREG_META",
   oprSm.OPR_IMM : "IMM_META"
}



def getMetaEnum(opr, isSrc: bool):
    preRet = "META"
    preRet = preRet + "_{DIREC}_".format(DIREC = "SRC" if isSrc else "DES" )
    preRet = preRet + oprTypeToStr.get(type(opr), "ERROR_WITH_TYPE_" + str(type(opr)))
    return preRet







def getMetaType(opr):
    return oprTypeToMetaType.get(type(opr), "ERROR_STRUCT_TYPE_WITH_" + str(type(opr)))