import base.operand.opr_simple as oprs

ExecUnit_dummy = 99

# cxxTypeToExecUnit = {
#     "INT_SIM_ALU" : 1,
#     "INT_MUL_DIV_ALU" : 2,
#     "FLOAT_SIM_ALU": 3,
#     "FLOAT_MUL_DIV_ALU": 4,
#     "SIM128_ALU" : 5,
#     "SIM64_ALU"  : 5,
#     "MOV_MEM_LD" : 6,
#     "MOV_MEM_ST" : ExecUnit_dummy,
#     "MOV_MEM_LDI": 1,
#     "MOV_REG"    : 1,
#     "CMP_SIM_ALU": 1,
#     "JMP_SIM_ALU": 1
#
# }
#
# cxxTypeToUopType = {
#     "MOV_MEM_LD"  : "UOP_LOAD",
#     "MOV_MEM_LDI" : "UOP_IMM",
#     "MOV_MEM_ST"  : "UOP_STORE"
# }
# default_uopType = "UOP_COMP"
#

class ResUsageError(Exception):
    def __init__(self, message):
        super().__init__(self, message)


cxxTypeUOP_LOAD_INT  = "MOV_MEM_LD_INT"
cxxTypeUOP_LOAD_FLT  = "MOV_MEM_LD_FLT"
cxxTypeUOP_STORE_INT = "MOV_MEM_ST_INT"
cxxTypeUOP_STORE_FLT = "MOV_MEM_ST_FLT"

cxxTypeUOP_MOV_INT_IMM        = "MOV_IMM_INT"
cxxTypeUOP_MOV_FLT_IMM        = "MOV_IMM_FLT"
cxxTypeUOP_MOV_INT_REG_REG    = "MOV_REG_INT"
cxxTypeUOP_MOV_FLT_REG_REG    = "MOV_REG_FLT"


cxxTypeIO_suggest_FLT = "FLT"
cxxTypeIO_suggest_INT = "INT"

UOPTYPE_COMP     = "UOP_COMP"
UOPTYPE_LOAD     = "UOP_LOAD"
UOPTYPE_STORE    = "UOP_STORE"
UOPTYPE_IMM      = "UOP_IMM"


##### is op class is related to gem5 opclass to precisely inject microop to specific f unit
##### for now we use opclass as same as cxx prefix too
gem5_opclass  = {
"No_OpClass"               : (0,  UOPTYPE_COMP),
"IntAlu"                   : (1,  UOPTYPE_COMP), ## used
"IntMult"                  : (2,  UOPTYPE_COMP), ## used
"IntDiv"                   : (3,  UOPTYPE_COMP), ## used
"FloatAdd"                 : (4,  UOPTYPE_COMP), ## used
"FloatCmp"                 : (5,  UOPTYPE_COMP),
"FloatCvt"                 : (6,  UOPTYPE_COMP), ###### unknown
"FloatMult"                : (7,  UOPTYPE_COMP), ## used
"FloatMultAcc"             : (8,  UOPTYPE_COMP), ###### unknown
"FloatDiv"                 : (9,  UOPTYPE_COMP), #used
"FloatMisc"                : (10, UOPTYPE_COMP), ###### unknown
"FloatSqrt"                : (11, UOPTYPE_COMP), #skip
"SimdAdd"                  : (12, UOPTYPE_COMP),
"dAddAcc"                  : (13, UOPTYPE_COMP),
"SimdAlu"                  : (14, UOPTYPE_COMP),
"SimdCmp"                  : (15, UOPTYPE_COMP),
"SimdCvt"                  : (16, UOPTYPE_COMP),
"SimdMisc"                 : (17, UOPTYPE_COMP),
"SimdMult"                 : (18, UOPTYPE_COMP),
"SimdMultAcc"              : (19, UOPTYPE_COMP),
"SimdShift"                : (20, UOPTYPE_COMP),
"SimdShiftAcc"             : (21, UOPTYPE_COMP),
"SimdDiv"                  : (22, UOPTYPE_COMP),
"SimdSqrt"                 : (23, UOPTYPE_COMP),
"SimdFloatAdd"             : (24, UOPTYPE_COMP),
"SimdFloatAlu"             : (25, UOPTYPE_COMP),
"SimdFloatCmp"             : (26, UOPTYPE_COMP),
"SimdFloatCvt"             : (27, UOPTYPE_COMP),
"SimdFloatDiv"             : (28, UOPTYPE_COMP),
"SimdFloatMisc"            : (29, UOPTYPE_COMP),
"SimdFloatMult"            : (30, UOPTYPE_COMP),
"SimdFloatMultAcc"         : (31, UOPTYPE_COMP),
"SimdFloatSqrt"            : (32, UOPTYPE_COMP),
"SimdReduceAdd"            : (33, UOPTYPE_COMP),
"SimdReduceAlu"            : (34, UOPTYPE_COMP),
"SimdReduceCmp"            : (35, UOPTYPE_COMP),
"SimdFloatReduceAdd"       : (36, UOPTYPE_COMP),
"SimdFloatReduceCmp"       : (37, UOPTYPE_COMP),
"SimdAes"                  : (38, UOPTYPE_COMP),
"SimdAesMix"               : (39, UOPTYPE_COMP),
"SimdSha1Hash"             : (40, UOPTYPE_COMP),
"SimdSha1Hash2"            : (41, UOPTYPE_COMP),
"SimdSha256Hash"           : (42, UOPTYPE_COMP),
"SimdSha256Hash2"          : (43, UOPTYPE_COMP),
"SimdShaSigma2"            : (44, UOPTYPE_COMP),
"SimdShaSigma3"            : (45, UOPTYPE_COMP),
"SimdPredAlu"              : (46, UOPTYPE_COMP),
cxxTypeUOP_LOAD_INT        : (47, UOPTYPE_LOAD),
cxxTypeUOP_STORE_INT       : (48, UOPTYPE_STORE),
cxxTypeUOP_LOAD_FLT        : (49, UOPTYPE_LOAD),
cxxTypeUOP_STORE_FLT       : (50, UOPTYPE_STORE),
"IprAccess"                : (51, UOPTYPE_COMP),
"InstPrefetch"             : (52, UOPTYPE_COMP),
cxxTypeUOP_MOV_INT_IMM     : ( 1, UOPTYPE_IMM),
cxxTypeUOP_MOV_FLT_IMM     : ( 4, UOPTYPE_IMM),
cxxTypeUOP_MOV_INT_REG_REG : ( 1, UOPTYPE_COMP),
cxxTypeUOP_MOV_FLT_REG_REG : ( 4, UOPTYPE_COMP)

}

def cxxTypeToExecUnit(cxxPrefix : str):
    return gem5_opclass.get(cxxPrefix, (0, ""))[0] #### if there is no cxxPrefix return noop class instead

def cxxTypeToUopType(cxxPrefix: str):
    return gem5_opclass.get(cxxPrefix, (0, "UOP_COMP"))[1]


##### incase there is no mem we should considter as float or int alu    it might be imm or test type
def ioSuggest_to_cxxType(cxxSugest : str, srcType, desType):

    if cxxSugest not in [cxxTypeIO_suggest_FLT, cxxTypeIO_suggest_INT]:
        raise ResUsageError(f"can't convert io suggest: {cxxSugest} to cxx typePrefix")

    if srcType == oprs.OPR_IMM:
        #### expect destype as temp
        return cxxTypeUOP_MOV_INT_IMM     if cxxSugest == cxxTypeIO_suggest_INT else cxxTypeUOP_MOV_FLT_IMM
    elif srcType == oprs.OPR_MEM:
        return cxxTypeUOP_LOAD_INT        if cxxSugest == cxxTypeIO_suggest_INT else cxxTypeUOP_LOAD_FLT
    elif desType == oprs.OPR_MEM:
        return cxxTypeUOP_STORE_INT       if cxxSugest == cxxTypeIO_suggest_INT else cxxTypeUOP_STORE_FLT
    else: ### supposed to reg - reg what ever treg or reg
        return cxxTypeUOP_MOV_INT_REG_REG if cxxSugest == cxxTypeIO_suggest_INT else cxxTypeUOP_MOV_FLT_REG_REG
