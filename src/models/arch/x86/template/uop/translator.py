import os
from colorama import init
from termcolor import colored
# UOPSTORAGE { name: "add", input: [REG, TREG, MEM],
#                           inputName: [jennis, mewnich, orn],
#                           output: [REG, TREG, MEM],
#                           outputName: [jennis, mewnich, orn]
#                           uopType: "UOP_COMP"}

REF_VALS          = {"MICROOP", "INPUT", "OUTPUT", "TYPE", "MICROOP_END"}
REF_VAL_UOP_START = "MICROOP"
REF_VAL_INPUT     = "INPUT"
REF_VAL_OUTPUT    = "OUTPUT"
REF_VAL_TYPE      = "TYPE"
REF_VAL_UOP_END   = "MICROOP_END"

UOP_IO_TYPES = ["TREG", "REG", "MEM"]
UOP_CLUSTER_TYPES = ["UOP_COMP","UOP_LOAD","UOP_STORE", "UOP_IMM","UOP_DUMMY"]
##ioTYPE
UOP_IO_TYPE_TREG = "TREG"
UOP_IO_TYPE_REG  = "REG"
UOP_IO_TYPE_MEM  = "MEM"

ioTypeMap = {
    "TREG" : "TREGNUM",
    "REG"  : "REG_OPERAND",
    "MEM"  : "MEM_OPERAND"
}

##uopMeta
UOP_MT_NAME  = "name"
UOP_MT_INPUT_VT    = "input"
UOP_MT_INPUT_VN = "inputName"
UOP_MT_OUTPUT_VT = "output"
UOP_MT_OUTPUT_VN = "outputName"
UOP_MT_TYPE      = "uopType"

UOP_STORAGE = dict()

##### for cxx writing
SCRIPT_DIR_PATH=os.path.dirname(os.path.realpath(__file__))
DES_PREFIX = "../../build/uop"
INC_DEP = "../../../dep.h"
INC_UOP = "../../../uop_base.h"
HEAD_FILE_NAME = "x86_uop.h"
CXX_FILE_NAME = "x86_uop.cpp"
MACH_FILE_TYPE = ".mach"


def uop_CXX_write(cxx_eles):
    headerStr = "#ifndef X86_UOPL_H\n" \
                "#define X86_UOPL_H\n" \
                f"#include\"{INC_DEP}\"\n" \
                f"#include\"{INC_UOP}\"\n" \
                "\n\n\n\n"
    headerStr = headerStr + "\n".join(cxx_ele[0] for cxx_ele in cxx_eles)
    headerStr = headerStr + "\n#endif"

    cxxStr = f"#include\"{HEAD_FILE_NAME}\"\n"
    cxxStr = cxxStr + "\n".join(cxx_ele[1] for cxx_ele in cxx_eles)

    headerWritePath = os.path.join(DES_PREFIX, HEAD_FILE_NAME)
    cxxWritePath = os.path.join(DES_PREFIX, CXX_FILE_NAME)

    headerFile = open(os.path.join(SCRIPT_DIR_PATH, headerWritePath), "w")
    cxxWriteFile = open(os.path.join(SCRIPT_DIR_PATH,cxxWritePath), "w")

    headerFile.write(headerStr)
    cxxWriteFile.write(cxxStr)

    headerFile.close()
    cxxWriteFile.close()


def uop_genCXX_init_param(interpreted_uop):
    first = True
    ret = str()
    ### VarType VarName
    for vt, vn in zip(interpreted_uop[UOP_MT_INPUT_VT] + interpreted_uop[UOP_MT_OUTPUT_VT],
                      interpreted_uop[UOP_MT_INPUT_VN] + interpreted_uop[UOP_MT_OUTPUT_VN]
                      ):
        if first:
            first = False
        else:
            ret += ", "
        ret = ret + ioTypeMap[vt] + "* " + vn
    return ret


def uop_genCXX_func_init_head(interpreted_uop):
    ret = "void addMeta( "
    ret += uop_genCXX_init_param(interpreted_uop)
    ret = ret + " );"
    return ret


def uop_genCXX_func_init_file(interpreted_uop):
    ret = "void UOP_{CLASS_NAME}::addMeta({PARAM}){{\n".format(CLASS_NAME=interpreted_uop[UOP_MT_NAME],
                                                          PARAM=uop_genCXX_init_param(interpreted_uop)
                                                          )
    ret = ret + "///////// input\n"
    for vt, vn in zip(interpreted_uop[UOP_MT_INPUT_VT], interpreted_uop[UOP_MT_INPUT_VN]):
        ret  = ret + f"///{vt} with name {vn}\n"
        if vt == UOP_IO_TYPE_REG:
            ret  = ret + "addRegMeta({REGNUM}, true);\n".format(REGNUM = vn + "->getMeta()")
        if vt == UOP_IO_TYPE_MEM:
            ret  = ret + "addMemMeta({ADAS}  , true);\n".format(ADAS   = vn + "->getMeta()"      )
            ret  = ret + "addRegMeta({REGNUM}, true);\n".format(REGNUM = vn + "->getBaseRegId()" )
            ret  = ret + "addRegMeta({REGNUM}, true);\n".format(REGNUM = vn + "->getIndexRegId()")
        if vt == UOP_IO_TYPE_TREG:
            ret  = ret + "addTRegMeta({TREGNUM}, true);\n".format(TREGNUM = "*"+vn)

    ret = ret + "///////// output\n"

    for vt, vn in zip(interpreted_uop[UOP_MT_OUTPUT_VT], interpreted_uop[UOP_MT_OUTPUT_VN]):
        ret  = ret + f"///{vt} with name {vn}\n"
        if vt == UOP_IO_TYPE_REG:
            ret  = ret + "addRegMeta({REGNUM}, false);\n".format(REGNUM = vn + "->getMeta()")
        if vt == UOP_IO_TYPE_MEM:
            ret  = ret + "addMemMeta({ADAS}, false);\n" .format(ADAS   = vn + "->getMeta()"      )
            ret  = ret + "addRegMeta({REGNUM}, true);\n".format(REGNUM = vn + "->getBaseRegId()" )
            ret  = ret + "addRegMeta({REGNUM}, true);\n".format(REGNUM = vn + "->getIndexRegId()")
        if vt == UOP_IO_TYPE_TREG:
            ret  = ret + "addTRegMeta({TREGNUM}, false);\n".format(TREGNUM = "*"+vn)

    ret += "}"
    return ret


def uop_genCXX(interpreted_uop):
    results = None
    #######   #include \"../../../uop_base.h\"
    headerFile = " \n" \
                 "class UOP_{VAR_NAME} : public UOP_BASE{{\n" \
                 "public:\n" \
                 "  UOP_{VAR_NAME}();\n" \
                 "  void doDepenCheck(UOP_WINDOW* uop_window) override;\n" \
                 "  {FUNC_INIT}\n" \
                 "}};\n".format(VAR_NAME=interpreted_uop[UOP_MT_NAME],
                               FUNC_INIT=uop_genCXX_func_init_head(interpreted_uop))

    isAnyMemOpr = (UOP_IO_TYPE_MEM in interpreted_uop[UOP_MT_INPUT_VT]) or (UOP_IO_TYPE_MEM in interpreted_uop[UOP_MT_OUTPUT_VT])
    isAnyRegOpr = UOP_IO_TYPE_REG   in interpreted_uop[UOP_MT_INPUT_VT]

    cxxFile = "" \
              "/////////////// UOP_{VAR_NAME}\n" \
              "\n" \
              "UOP_{VAR_NAME}::UOP_{VAR_NAME}() : UOP_BASE({UOP_TYPE}){{}}" \
              "\n" \
              "\n" \
              "void UOP_{VAR_NAME}::doDepenCheck(UOP_WINDOW* uop_window) {{\n" \
              "    {REG_CHECK}\n" \
              "    {MEM_CHECK}\n" \
              "    ///// for future use\n" \
              "    /////   doExeDepenCheck(uop_window)\n" \
              "\n" \
              "}}\n" \
              "\n" \
              "{FUNC_INIT}\n" \
              "\n" \
              "//////////////////////////////////////\n" \
              "\n" \
              "\n".format(VAR_NAME=interpreted_uop[UOP_MT_NAME],
                        REG_CHECK="doRegDepenCheck(uop_window);" if isAnyMemOpr or isAnyRegOpr else "",
                        MEM_CHECK="doMemDepenCheck(uop_window);" if isAnyMemOpr                else "",
                        UOP_TYPE = interpreted_uop[UOP_MT_TYPE],
                        FUNC_INIT=uop_genCXX_func_init_file(interpreted_uop)
                        )

    return headerFile, cxxFile


# interpret each microp
# return UOPSTORAGE
def uop_interpret(lines_token):

    uopResult = dict()
    for linetok in lines_token:
        # assume that we have at least one token for each line
        #print(linetok)
        REP = linetok[0]
        if REP == REF_VAL_UOP_START:
            uopResult.update({"name": linetok[1]})
        elif (REP == REF_VAL_INPUT) or (REP == REF_VAL_OUTPUT):
            varSide = REP.lower()  # convert to input or output
            varSideName = varSide + "Name"
            uopResult.update({varSide: []})
            uopResult.update({varSideName: []})
            if len(linetok) >= 3:
                for vt, vm in zip(linetok[1::2], linetok[2::2]):
                    if vt not in UOP_IO_TYPES:
                        raise ValueError(f"there is no this io type of microop {linetok}")
                    uopResult[varSide].append(vt)
                    uopResult[varSideName].append(vm)
        elif REP == REF_VAL_TYPE:
            if linetok[1] not in UOP_CLUSTER_TYPES:
                raise ValueError(f"there is no this microopo type of microoop ")
            uopResult.update({UOP_MT_TYPE: linetok[1]})
        elif REP == REF_VAL_UOP_END:
            print(colored(f"[UOP GEN]interpret UOP: {uopResult[UOP_MT_NAME]} successfully", "blue"))
            yield uopResult
            uopResult.clear()
        else:
            raise ValueError("there is {}".format(REP))


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
    targetFilePaths = find_mach_files(SCRIPT_DIR_PATH)
    for targetFilePath in targetFilePaths:
        yield readFile(targetFilePath)


##read specific file and do tokenize string
# return list of token list
def readFile(srcFilePath):
    result = []
    print(colored(f"[UOP GEN] start reading file: {srcFilePath}", "cyan"))
    with open(srcFilePath, "r") as srcFile:
        lines = srcFile.readlines()
        for line in lines:
            splitedToken = line.strip().split()
            if (len(splitedToken) > 0) and (splitedToken[0] in REF_VALS):
                result.append(splitedToken)
    return result


def start():
    init()
    print(colored("[DEC GEN]===================== start micro operation generator =====================", "magenta"))
    interpreted_uopPool = []
    cxx_headandcpp_list = []
    for tokenLists in readFiles():
        # it is list of  token list per line in each file.
        # [ #line1#["INPUT", REG, REG, MEM], #line2#["OUTPUT", REG, REG, MEM]]
        for interpreted_uop in uop_interpret(tokenLists): #### tokenList of each file
            #single micro-op
            interpreted_uopPool.append(interpreted_uop.copy())
            cxx_method_str = uop_genCXX(interpreted_uop)
            cxx_headandcpp_list.append(cxx_method_str)

    uop_CXX_write(cxx_headandcpp_list)
    return interpreted_uopPool