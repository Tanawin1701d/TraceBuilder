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
cxxTypeUOP_LOAD   = "MOV_MEM_LD"
cxxTypeUOP_STORE  = "MOV_MEM_ST"
cxxTypeUOP_IMM    = "MOV_MEM_LDI"
cxxTypeUOP_MOVREG = "MOV_REG"

UOPTYPE_COMP     = "UOP_COMP"
UOPTYPE_LOAD     = "UOP_LOAD"
UOPTYPE_STORE    = "UOP_STORE"
UOPTYPE_IMM      = "UOP_IMM"


##### is op class is related to gem5 opclass to precisely inject microop to specific f unit
gem5_opclass  = {
"No_OpClass"       : (0,  UOPTYPE_COMP ),
"IntAlu"           : (1,  UOPTYPE_COMP ), ## used
"IntMult"          : (2,  UOPTYPE_COMP ), ## used
"IntDiv"           : (3,  UOPTYPE_COMP ), ## used
"FloatAdd"         : (4,  UOPTYPE_COMP ), ## used
"FloatCmp"         : (5,  UOPTYPE_COMP ),
"FloatCvt"         : (6,  UOPTYPE_COMP ), ###### unknown
"FloatMult"        : (7,  UOPTYPE_COMP ), ## used
"FloatMultAcc"     : (8,  UOPTYPE_COMP ), ###### unknown
"FloatDiv"         : (9,  UOPTYPE_COMP ), #used
"FloatMisc"        : (10, UOPTYPE_COMP ), ###### unknown
"FloatSqrt"        : (11, UOPTYPE_COMP ), #skip
"SimdAdd"          : (12, UOPTYPE_COMP ),
"dAddAcc"          : (13, UOPTYPE_COMP ),
"SimdAlu"          : (14, UOPTYPE_COMP ),
"SimdCmp"          : (15, UOPTYPE_COMP ),
"SimdCvt"          : (16, UOPTYPE_COMP ),
"SimdMisc"         : (17, UOPTYPE_COMP ),
"SimdMult"         : (18, UOPTYPE_COMP ),
"SimdMultAcc"      : (19, UOPTYPE_COMP ),
"SimdShift"        : (20, UOPTYPE_COMP ),
"SimdShiftAcc"     : (21, UOPTYPE_COMP ),
"SimdDiv"          : (22, UOPTYPE_COMP ),
"SimdSqrt"         : (23, UOPTYPE_COMP ),
"SimdFloatAdd"     : (24, UOPTYPE_COMP ),
"SimdFloatAlu"     : (25, UOPTYPE_COMP ),
"SimdFloatCmp"     : (26, UOPTYPE_COMP ),
"SimdFloatCvt"     : (27, UOPTYPE_COMP ),
"SimdFloatDiv"     : (28, UOPTYPE_COMP ),
"SimdFloatMisc"    : (29, UOPTYPE_COMP ),
"SimdFloatMult"    : (30, UOPTYPE_COMP ),
"SimdFloatMultAcc" : (31, UOPTYPE_COMP ),
"SimdFloatSqrt"    : (32, UOPTYPE_COMP ),
cxxTypeUOP_LOAD    : (33, UOPTYPE_LOAD ),
cxxTypeUOP_STORE   : (34, UOPTYPE_IMM  ),
cxxTypeUOP_IMM     : (0, UOPTYPE_STORE),
cxxTypeUOP_MOVREG  : (0 , UOPTYPE_COMP ),

}

def cxxTypeToExecUnit(cxxPrefix : str):
    return gem5_opclass.get(cxxPrefix, (0, ""))[0] #### if there is no cxxPrefix return noop class instead

def cxxTypeToUopType(cxxPrefix: str):
    return gem5_opclass.get(cxxPrefix, (0, "UOP_COMP"))[1]
