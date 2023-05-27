ExecUnit_dummy = 99

cxxTypeToExecUnit = {
    "INT_SIM_ALU" : 1,
    "INT_MUL_DIV_ALU" : 2,
    "FLOAT_SIM_ALU": 3,
    "FLOAT_MUL_DIV_ALU": 4,
    "SIM128_ALU" : 5,
    "MOV_MEM_LD" : 6,
    "MOV_MEM_ST" : ExecUnit_dummy,
    "MOV_REG"    : 1

}

cxxTypeToGemType = {
    "MOV_MEM_LD" : "UOP_LOAD",
    "MOV_MEM_ST" : "UOP_STORE"
}
default_gemType = "UOP_COMP"

cxxTypeUOP_LOAD  = "MOV_MEM_LD"
cxxTypeUOP_STORE = "MOV_MEM_ST"
cxxTypeUOP_MOVREG = "MOV_REG"