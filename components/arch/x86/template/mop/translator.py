import os

# MOPSTORAGE= { name: "add",
#
#               input: { varName: T_MEM_LD}
#               output: {varName: T_MEM_LD}
#               varTemp {varName }
#               microops:
#                     <microop Name>:
#                           input: [varName, varName, varNameTemp, varNameTemp2]
#                           output: [varName, varName, varNameTemp]
#                           dep: {<microop Name1>,<microop Name2>, ...}
#
#
# }

REF_VALS = {"MACROOP_END", "INPUT", "OUTPUT", "TEMP", "MICROOP", "MACROOP"}
REF_VAL_MACRO_BEGIN = "MACROOP"
REF_VAL_MACRO_END   = "MACROOP_END"
REF_VAL_MACRO_INPUT = "INPUT"
REF_VAL_MACRO_OUPUT = "OUTPUT"
REF_VAL_MACRO_TEMP  = "TEMP"
REF_VAL_MACRO_UOP   = "MICROOP"
REF_VAL_MACRO_UOP_INPUT  = "INPUT"
REF_VAL_MACRO_UOP_OUTPUT = "OUTPUT"



MOP_IO_TYPES = ["O_REG", "O_MEM_LD", "O_MEM_ST", "O_IMM"]  ## we will drop imm out

MOP_STORAGE = dict()

##### for cxx generating
ioTypeMap = {"TEMP"   : "REGNUM",
             "O_REG"    : "REG_OPERAND",
             "O_MEM_LD" : "LD_OPERAND",
             "O_MEM_ST" : "ST_OPERAND"
             }

MOP_IO_TYPE_TEMP   = "TEMP"
MOP_IO_TYPE_REG    = "O_REG"
MOP_IO_TYPE_LD_MEM = "O_MEM_LD"
MOP_IO_TYPE_ST_MEM = "O_MEM_ST"



##### for meta data
MOP_META_NAME           = "name"
MOP_META_INPUT          = "input"
MOP_META_OUTPUT         = "output"
MOP_META_VARTEMP        = "varTemp"
MOP_META_MICROOP        = "microops"
MOP_META_MICROOP_INPUT  = "input"
MOP_META_MICROOP_OUTPUT = "output"
MOP_META_MICROOP_DEP    = "dep"


##### for cxx writing
DES_PREFIX = "../../build/mop"
INC_DEP = "../../../dep.h"
INC_UOP = "../../../uop_base.h"
HEAD_FILE_NAME = "x86_mop.h"
CXX_FILE_NAME = "x86_mop.cpp"
MACH_FILE_TYPE = ".mach"


def initMopMeta(mopMeta):
    mopMeta.update({MOP_META_NAME,    str() })
    mopMeta.update({MOP_META_INPUT,   dict()})
    mopMeta.update({MOP_META_OUTPUT,  dict()})
    mopMeta.update({MOP_META_VARTEMP, set() })
    mopMeta.update({MOP_META_MICROOP, dict()})

def initUopMeta(uopMeta):
    uopMeta.update({MOP_META_MICROOP_INPUT , list()})
    uopMeta.update({MOP_META_MICROOP_OUTPUT, list()})
    uopMeta.update({MOP_META_MICROOP_DEP   , set()})

def interpretMacroop(linesToken):
    mopMeta = None
    definedVar = {}
    varTempDep = dict()  ##### map vartempName to microop name

    for singleLineTok in  linesToken:
        tokKey = singleLineTok[0]
        if tokKey == REF_VAL_MACRO_BEGIN:
            mopMeta = dict()
            initMopMeta(mopMeta)
            mopMeta[MOP_META_NAME] = singleLineTok[1]
            definedVar.clear()
            varTempDep.clear()
        elif tokKey == REF_VAL_MACRO_END:
            yield mopMeta
        elif tokKey == REF_VAL_MACRO_INPUT:
            if len(singleLineTok) >= 3:
                for vt, vn in zip(singleLineTok[1::2], singleLineTok[2::2]):
                    if vt not in [MOP_IO_TYPE_REG, MOP_IO_TYPE_LD_MEM]:
                        raise KeyError(f"there is no type {vt}")
                    if vn in definedVar:
                        raise ValueError(f"there is variable {vn} already")
                    if vn in MOP_IO_TYPES:
                        raise ValueError(f"can not use varName as the same as MOP_IO_TYPE")
                    mopMeta[MOP_META_INPUT].update({vn, vt})
                    definedVar.update(vn)

        elif tokKey == REF_VAL_MACRO_OUPUT:
            if len(singleLineTok) >= 3:
                for vt, vn in zip(singleLineTok[1::2], singleLineTok[2::2]):
                    if vt != MOP_IO_TYPE_ST_MEM:
                        raise KeyError(f"there is no type {vt}")
                    if vn in definedVar:
                        raise ValueError(f"there is variable {vn} already")
                    if vn in MOP_IO_TYPES:
                        raise ValueError(f"can not use varName as the same as MOP_IO_TYPE")
                    mopMeta[MOP_META_OUTPUT].update({vn, vt})
                    definedVar.update(vn)
        elif tokKey == REF_VAL_MACRO_TEMP:
            if len(singleLineTok) >= 3:
                for vt, vn in zip(singleLineTok[1::2], singleLineTok[2::2]):
                    if vt !=  MOP_IO_TYPE_TEMP:
                        raise KeyError(f"there is no type {vt}")
                    if vn in definedVar:
                        raise ValueError(f"there is variable {vn} already")
                    if vn in MOP_IO_TYPES:
                        raise ValueError(f"can not use varName as the same as MOP_IO_TYPE")
                    mopMeta[MOP_META_VARTEMP].update(vn)
                    definedVar.update(vn)
        elif tokKey == REF_VAL_MACRO_UOP:
            interpretMicroop(mopMeta, definedVar, singleLineTok, varTempDep)

def interpretMicroop(mopMeta, definedVar, singleLineTok, varTempDep):
    microopName = singleLineTok[1]
    mopMeta[MOP_META_MICROOP].update({microopName, dict()})
    initUopMeta(mopMeta[MOP_META_MICROOP][microopName])

    for token in singleLineTok[2::]:
        if token == REF_VAL_MACRO_UOP_INPUT:
            if token not in definedVar:
                raise ValueError(f"argument to microop is not readable {token}  @  {str(singleLineTok)}")
            if token in mopMeta[MOP_META_VARTEMP]: ## for now token is temp variable name
                mopMeta[MOP_META_MICROOP][microopName][MOP_META_MICROOP_DEP]\
                    .update(varTempDep[token])
                     ### if there are any errors the vartempDep will raise itself
            else:
                mopMeta[MOP_META_MICROOP][microopName][MOP_META_MICROOP_INPUT]\
                    .append(token)
        elif token == REF_VAL_MACRO_UOP_OUTPUT:
            pass





# Recursive function to find all .mach files
def find_mach_files(dir_path):
    mach = []
    for file in os.listdir(dir_path):
        file_path = os.path.join(dir_path, file)
        if os.path.isfile(file_path) and file_path.endswith(MACH_FILE_TYPE):
            mach.append(file_path)
        elif os.path.isdir(file_path):
            mach += find_mach_files(file_path)
    return mach

##sequence generator in current folder that script is belonged to.
##return list of token lists from readFile()
def readFiles():
    targetFilePaths = find_mach_files(".")
    for targetFilePath in targetFilePaths:
        yield readFile(targetFilePath)
##read specific file and do tokenize string
# return list of token list
def readFile(srcFilePath):
    result = []
    print("[uop generator] start reading file {}".format(srcFilePath))
    with open(srcFilePath, "r") as srcFile:
        lines = srcFile.readlines()
        for line in lines:
            splitedToken = line.strip().split()
            if (len(splitedToken) > 0) and (splitedToken[0] in REF_VALS):
                result.append(splitedToken)
    return result