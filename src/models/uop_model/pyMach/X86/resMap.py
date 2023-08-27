import traceBuilder as tbd
UOPTYPE_COMP   = tbd.UOP_TYPE.UOP_COMP
UOPTYPE_LOAD   = tbd.UOP_TYPE.UOP_LOAD
UOPTYPE_STORE  = tbd.UOP_TYPE.UOP_STORE
UOPTYPE_IMM    = tbd.UOP_TYPE.UOP_IMM

INT_ALU = ["AAA","AAD","AAM","AAS","ADC","ADD","AND","ARPL", "CMP","DEC","DIV"
    ,"IDIV","IMUL","INC","NEG","NOT","OR","RCL","RCR","ROL","ROR","SAL"
    ,"SAR","SBB","SHL","SHLD","SHR","SHRD","SUB","TEST","XADD","XBTS","XCHG","XOR"
           ]

INT_MUL = ["IMUL", "MUL", "MULX"]

INT_DIV = ["DIV", "IDIV"]

FLT_ADD = ["FSUB","FSUBP","FSUBR","FSUBRP","FADD","FADDP","FIADD","FABS", "FCHS"]

FLT_CMP = ["FCOMP", "FCOMPP", "FICOMP", "FUCOMP", "FUCOMPP"]

FLT_CVT = ["FINIT","FIST","FISTP","FISTTP", "FRNDINT"]

FLT_MUL = ["FIMUL", "FMUL", "FMULP"]

FLT_DIV = ["FDIV", "FDIVP", "FDIVR", "FDIVRP", "FIDIV", "FIDIVR"]

FLT_SQRT = ["FSIN", "FSINCOS", "FCOS", "FPTAN", "FYL2X", "FYL2XP1"]

SIMD_ADD_SFF = ["SAD", "ADD", "SUB", "AVG"]
SIMD_ALU_SFF = ["XOR", "OR", "AND"]
SIMD_CMP_SFF     = ["MIN", "MAX"]
SIMD_CVT_SFF     = ["CMP"]
SIMD_MUL_SFF     = ["MUL"]
SIMD_SHIFT_SFF  = ["SRL","SRA", "SLL"]



SIMD_FLT_ADD = ["ADD", "SUB"]
SIMD_FLT_ALU = ["RCPPS"]
SIMD_FLT_CMP = ["MIN", "MAX"]
SIMD_FLT_CVT = ["CVTT"]
SIMD_FLT_DIV = ["DIV"]
SIMD_FLT_MUL = ["MUL"]
SIMD_FLT_SQRT= ["SQRT"]

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
    "MemRead"                  : (47, UOPTYPE_LOAD),
    "MemWrite"                 : (48, UOPTYPE_STORE),
    "MemReadFloat"             : (49, UOPTYPE_LOAD),
    "MemWriteFloat"            : (50, UOPTYPE_STORE),
    "IprAccess"                : (51, UOPTYPE_COMP),
    "InstPrefetch"             : (52, UOPTYPE_COMP),
}