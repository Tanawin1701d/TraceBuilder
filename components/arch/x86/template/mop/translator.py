import os

# MOPSTORAGE= { name: "add",
#
#               input: { varName: (T_MEM_LD, id)}
#               output: {varName: (T_MEM_ST, id)}
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
INC_UOP = "../../../mop_base.h"
INC_UOP_X86 = "../uop/x86_uop.h"
INC_RT_INSTR= "../../../../inst_model/rt_instr.h"
HEAD_FILE_NAME = "x86_mop.h"
CXX_FILE_NAME = "x86_mop.cpp"
MACH_FILE_TYPE = ".mach"

def mop_writeCXX_methods(cxx_eles): #tuple (cpp, header)
    ######### header
    headerStr = "#ifndef X86_MOPL_H\n" \
                "#define X86_MOPL_H\n" \
                f"#include\"{INC_DEP}\"\n" \
                f"#include\"{INC_UOP}\"\n" \
                f"#include\"{INC_UOP_X86}\"\n" \
                "\n\n\n\n"
    headerStr = headerStr + "\n".join([x[0] for x in cxx_eles] ) + "\n"
    headerStr = headerStr + "#endif\n"
    ######### cplusplus
    cxxStr    = f"#include\"{HEAD_FILE_NAME}\"\n"
    cxxStr    = cxxStr + f"#include\"{INC_RT_INSTR}\"\n"
    cxxStr    = cxxStr + "\n ".join([x[1] for x in cxx_eles])
    ##########################################

    headerWritePath = os.path.join(DES_PREFIX, HEAD_FILE_NAME)
    cxxWritePath = os.path.join(DES_PREFIX, CXX_FILE_NAME)

    headerFile   = open(headerWritePath, "w")
    cxxWriteFile = open(cxxWritePath, "w")

    headerFile.write(headerStr)
    cxxWriteFile.write(cxxStr)

    headerFile.close()
    cxxWriteFile.close()

def uop_genParam_addMeta(interpret_mop, uopMeta):
    retList = []
    for varName in uopMeta[MOP_META_MICROOP_INPUT]:
        if varName in interpret_mop[MOP_META_INPUT]:
            vt, id    = interpret_mop[MOP_META_INPUT][varName]
            vtCxx = ioTypeMap[vt]
            retList.append(f"(({vtCxx}*)(srcPool[{id}]))->getMeta()")
        elif varName in interpret_mop[MOP_META_VARTEMP]:
            retList.append(varName)
        else:
            raise (AttributeError(f"error can interpret like this {varName}  {str(uopMeta)}"))

    for varName in uopMeta[MOP_META_MICROOP_OUTPUT]:
        if varName in interpret_mop[MOP_META_OUTPUT]:
            vt, id = interpret_mop[MOP_META_OUTPUT][varName]
            vtCxx = ioTypeMap[vt]
            retList.append(f"(({vtCxx}*)(desPool[{id}]))->getMeta()")
        elif varName in interpret_mop[MOP_META_VARTEMP]:
            retList.append(varName)
        else:
            print(interpret_mop[MOP_META_OUTPUT])
            raise (AttributeError(f"error can interpret like this {varName}  {str(uopMeta)}"))

    return ", ".join(retList)

def mop_genCXX_method_genUop(interpret_mop):
    retStr = str()

    retStr = "vector<UOP_BASE*> MOP_{MOPNAME}::genUop(){{\n".format(MOPNAME = interpret_mop[MOP_META_NAME])

    #### init vector
    retStr = retStr + "     vector<UOP_BASE*> retUops;\n"
    #### get pool
    retStr = retStr + "     auto srcPool = rt_instr->getSrcMacroPoolOperands();\n" ## type vector<OPERAND*>
    retStr = retStr + "     auto desPool = rt_instr->getDesMacroPoolOperands();\n" ## type vector<OPERAND*>
    retStr = retStr + "     TREGNUM " + ",".join(list(interpret_mop[MOP_META_VARTEMP])) + ";\n"
    ####  create uop pointer
    retStr = retStr + "\n\n\n     ///------------------------create uop \n"
    for uopName, uopMeta in interpret_mop[MOP_META_MICROOP].items():
        #### init uop and add meta data
        retStr = retStr + "     auto var_{UOPTYPE} = new {UOPTYPE}();\n"\
                          "     var_{UOPTYPE}->addMeta({PARAM});\n".format(UOPTYPE = "UOP_"+uopName,
                                                                            PARAM   = uop_genParam_addMeta(interpret_mop, uopMeta)
                                                                            )

        #### push back to pool
        retStr = retStr + "     retUops.push_back(var_{UOPTYPE});\n".format(UOPTYPE = "UOP_"+uopName)

    retStr = retStr + "\n\n\n     ///------------------------connect uop temp variable dep \n"

    #### connect temp dependency
    for uopName, uopMeta in interpret_mop[MOP_META_MICROOP].items():
        for depType in uopMeta[MOP_META_MICROOP_DEP]:
            retStr = retStr + "     var_{UOPTYPE}->addTemDep(var_{DEPUOP});\n"\
                .format(UOPTYPE = "UOP_"+uopName,
                        DEPUOP  = "UOP_" + depType)

    #### return vector
    retStr = retStr + "return retUops;\n"


    retStr = retStr + "}"
    return retStr

def mop_genCXX_methods(interpret_mop):
    headerStr = "class MOP_{MOPNAME} : MOP_BASE{{\n" \
                "public:\n" \
                "\n" \
                "   vector<UOP_BASE*> genUop() override;\n" \
                "}};"\
        .format(MOPNAME = interpret_mop[MOP_META_NAME])

    cppStr    = mop_genCXX_method_genUop(interpret_mop)

    return headerStr, cppStr

def initMopMeta(mopMeta):
    mopMeta.update({MOP_META_NAME    : str() })
    mopMeta.update({MOP_META_INPUT   : dict()})
    mopMeta.update({MOP_META_OUTPUT  : dict()})
    mopMeta.update({MOP_META_VARTEMP : set() })
    mopMeta.update({MOP_META_MICROOP : dict()})

def initUopMeta(uopMeta):
    uopMeta.update({MOP_META_MICROOP_INPUT  : list()})
    uopMeta.update({MOP_META_MICROOP_OUTPUT : list()})
    uopMeta.update({MOP_META_MICROOP_DEP    : set()})

def interpretMacroop(linesToken):
    mopMeta = None
    definedVar = set()
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
                for id, (vt, vn) in enumerate(zip(singleLineTok[1::2], singleLineTok[2::2])):
                    if vt not in [MOP_IO_TYPE_REG, MOP_IO_TYPE_LD_MEM]:
                        raise KeyError(f"there is no type {vt}")
                    if vn in definedVar:
                        raise ValueError(f"there is variable {vn} already")
                    if vn in MOP_IO_TYPES:
                        raise ValueError(f"can not use varName as the same as MOP_IO_TYPE")
                    mopMeta[MOP_META_INPUT].update({vn: (vt, id)})
                    definedVar.add(vn)

        elif tokKey == REF_VAL_MACRO_OUPUT:
            if len(singleLineTok) >= 3:
                for id, (vt, vn) in enumerate(zip(singleLineTok[1::2], singleLineTok[2::2])):
                    print (vt, "    ", vn)
                    if vt not in  [MOP_IO_TYPE_ST_MEM, MOP_IO_TYPE_REG]:
                        raise KeyError(f"there is no type {vt}")
                    if vn in definedVar:
                        raise ValueError(f"there is variable {vn} already")
                    if vn in MOP_IO_TYPES:
                        raise ValueError(f"can not use varName as the same as MOP_IO_TYPE")
                    mopMeta[MOP_META_OUTPUT].update({vn: (vt, id)})
                    definedVar.add(vn)
        elif tokKey == REF_VAL_MACRO_TEMP:
            if len(singleLineTok) >= 2:
                for vn in singleLineTok[1::]:
                    if vn in definedVar:
                        raise ValueError(f"there is variable {vn} already")
                    if vn in MOP_IO_TYPES:
                        raise ValueError(f"can not use varName as the same as MOP_IO_TYPE")
                    mopMeta[MOP_META_VARTEMP].add(vn)
                    definedVar.add(vn)
        elif tokKey == REF_VAL_MACRO_UOP:
            interpretMicroop(mopMeta, definedVar, singleLineTok, varTempDep)
        else:
            raise AttributeError("can't type of macroop instruction {}".format(str(linesToken)))

def interpretMicroop(mopMeta, definedVar, singleLineTok, varTempDep):
    microopName = singleLineTok[1]
    mopMeta[MOP_META_MICROOP].update({microopName: dict()})
    initUopMeta(mopMeta[MOP_META_MICROOP][microopName])

    inputIdx = singleLineTok.index(REF_VAL_MACRO_UOP_INPUT)
    outputIdx = singleLineTok.index(REF_VAL_MACRO_UOP_OUTPUT)
    ### interpret input variable
    for token in singleLineTok[inputIdx+1:outputIdx:]:
        if token not in definedVar:
            raise ValueError(f"argument to microop is not readable {token}  @  {str(singleLineTok)} from {definedVar}")
        if token in mopMeta[MOP_META_VARTEMP]: ## for now token is temp variable name
            mopMeta[MOP_META_MICROOP][microopName][MOP_META_MICROOP_DEP]\
                .add(varTempDep[token])
                 ### if there are any errors the vartempDep will raise itself
        mopMeta[MOP_META_MICROOP][microopName][MOP_META_MICROOP_INPUT].append(token)

    for token in singleLineTok[outputIdx+1::]:
        if token not in definedVar:
            raise ValueError(f"argument to microop is not readable {token}  @  {str(singleLineTok)} from {definedVar}")
        if token in mopMeta[MOP_META_VARTEMP]:
            varTempDep.update({token: microopName})
        mopMeta[MOP_META_MICROOP][microopName][MOP_META_MICROOP_OUTPUT].append(token)

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
    print("[mop generator] start reading file {}".format(srcFilePath))
    with open(srcFilePath, "r") as srcFile:
        lines = srcFile.readlines()
        for line in lines:
            splitedToken = line.strip().split()
            if (len(splitedToken) > 0) and (splitedToken[0] in REF_VALS):
                result.append(splitedToken)
    return result


def start():
    for tokensList in readFiles():
        cxxSrcs = []
        for mopMeta in interpretMacroop(tokensList):
            cxxSrcs.append(mop_genCXX_methods(mopMeta))
        mop_writeCXX_methods(cxxSrcs)

start()