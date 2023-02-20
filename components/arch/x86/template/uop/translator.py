import os

# UOPSTORAGE { name: "add", input: [REG, TREG, MEM],
#                           inputName: [jennis, mewnich, orn],
#                           output: [REG, TREG, MEM],
#                           outputName: [jennis, mewnich, orn] }

REF_VAL = {"MICROOP", "INPUT", "OUTPUT", "MICROOP_END"}
UOP_IO_TYPE = ["TREG", "REG", "MEM"]
UOP_STORAGE = dict()

##### for cxx generating
ioTypeMap = {"REG": "REGNUM", "MEM": "ADAS", "TREG": "REGNUM"}
START_PARAMETER = 'a'

##### for cxx writing
DES_PREFIX = "../../build/uop"
INC_DEP = "../../../dep.h"
INC_UOP = "../../../uop_base.h"
HEAD_FILE_NAME = "x86_uop.h"
CXX_FILE_NAME = "x86_uop.cpp"


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

    headerFile = open(headerWritePath, "w")
    cxxWriteFile = open(cxxWritePath, "w")

    headerFile.write(headerStr)
    cxxWriteFile.write(cxxStr)

    headerFile.close()
    cxxWriteFile.close()


def uop_genCXX_init_param(interpreted_uop):
    first = True
    ret = str()
    for vt, vn in zip(interpreted_uop["input"] + interpreted_uop["output"],
                      interpreted_uop["inputName"] + interpreted_uop["outputName"]
                      ):
        if first:
            first = False
        else:
            ret += ", "
        ret = ret + ioTypeMap[vt] + " " + vn
    return ret


def uop_genCXX_func_init_head(interpreted_uop):
    ret = "void addMeta( "
    ret += uop_genCXX_init_param(interpreted_uop)
    ret = ret + " );"
    return ret


def uop_genCXX_func_init_file(interpreted_uop):
    ret = "void UOP_{CLASS_NAME}::addMeta({PARAM}){{\n".format(CLASS_NAME=interpreted_uop["name"],
                                                          PARAM=uop_genCXX_init_param(interpreted_uop)
                                                          )
    ret = ret + "///////// input\n"
    for vt, vn in zip(interpreted_uop["input"], interpreted_uop["inputName"]):
        if vt == "REG":
            ret = ret + "   addRegMeta({REGNUM}, {BOOL_IS_SRC});\n".format(REGNUM=vn, BOOL_IS_SRC="true")
        if vt == "MEM":
            ret = ret + "   addMemMeta({ADAS}, {BOOL_IS_SRC});\n".format(ADAS=vn, BOOL_IS_SRC="true")
        if vt == "TREG":
            pass  ### macroop will handle it self

    ret = ret + "///////// output\n"

    for vt, vn in zip(interpreted_uop["output"], interpreted_uop["outputName"]):
        if vt == "REG":
            ret = ret + "   addRegMeta({REGNUM}, {BOOL_IS_SRC});\n".format(REGNUM=vn, BOOL_IS_SRC="false")
        if vt == "MEM":
            ret = ret + "   addMemMeta({ADAS}, {BOOL_IS_SRC});\n".format(ADAS=vn, BOOL_IS_SRC="false")
        if vt == "TREG":
            pass  ### macroop will handle it self

    ret += "}"
    return ret


def uop_genCXX(interpreted_uop):
    results = None
    #######   #include \"../../../uop_base.h\"
    headerFile = " \n" \
                 "class UOP_{VAR_NAME} : public UOP_BASE{{\n" \
                 "public:\n" \
                 "  UOP_{VAR_NAME}() = default;\n" \
                 "  void doDepenCheck(UOP_WINDOW* uop_window) override;\n" \
                 "  {FUNC_INIT}\n" \
                 "}};\n".format(VAR_NAME=interpreted_uop["name"],
                               FUNC_INIT=uop_genCXX_func_init_head(interpreted_uop))

    cxxFile = "void UOP_{VAR_NAME}::doDepenCheck(UOP_WINDOW* uop_window) {{\n" \
              "    {REG_CHECK}\n" \
              "    {MEM_CHECK}\n" \
              "    ///// for future use\n" \
              "    /////   doExeDepenCheck(uop_window)\n" \
              "\n" \
              "}}\n" \
              "\n" \
              "{FUNC_INIT}\n" \
              "".format(VAR_NAME=interpreted_uop["name"],
                        REG_CHECK="doRegDepenCheck(uop_window);" if "REG" in interpreted_uop["input"] else "",
                        MEM_CHECK="doMemDepenCheck(uop_window);" if (("MEM" in interpreted_uop["input"]) or
                                                                     ("MEM" in interpreted_uop["output"]))
                        else "",
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

        if REP == "MICROOP":
            uopResult.update({"name": linetok[1]})
            print("est",uopResult)
        elif (REP == "INPUT") or (REP == "OUTPUT"):
            varSide = REP.lower()  # convert to input or output
            varSideName = varSide + "Name"
            uopResult.update({varSide: []})
            uopResult.update({varSideName: []})
            if len(linetok) >= 3:
                for vt, vm in zip(linetok[1::2], linetok[2::2]):
                    if vt not in UOP_IO_TYPE:
                        raise ValueError("there is no this type of microop")
                    uopResult[varSide].append(vt)
                    uopResult[varSideName].append(vm)
        elif REP == "MICROOP_END":
            #print(uopResult)
            yield uopResult
            uopResult.clear()
        else:
            raise ValueError("there is {}".format(REP))


# Recursive function to find all .mach files
def find_mach_files(dir_path):
    mach = []
    for file in os.listdir(dir_path):
        file_path = os.path.join(dir_path, file)
        if os.path.isfile(file_path) and file_path.endswith(".mach"):
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
            if (len(splitedToken) > 0) and (splitedToken[0] in REF_VAL):
                result.append(splitedToken)
    return result


def start():
    for tokenLists in readFiles():
        # it is list of  token list per line in each file.
        # [ #line1#["INPUT", REG, REG, MEM], #line2#["OUTPUT", REG, REG, MEM]]
        cxx_headandcpp_list = []
        for interpreted_uop in uop_interpret(tokenLists):
            cxx_method_str = uop_genCXX(interpreted_uop)
            cxx_headandcpp_list.append(cxx_method_str)
        uop_CXX_write(cxx_headandcpp_list)

start()
