import os
# UOPSTORAGE { name: "add", input: [REG, TREG, MEM], output: [REG, TREG, MEM] }

REF_VAL = {"MICROOP","INPUT","OUTPUT","MICROOP_END"}
UOP_IO_TYPE = ["TREG","REG","MEM"]
UOP_STORAGE = dict()

DES_PREFIX = "../../"

def uop_genCXX(interpreted_uop):
    pass

def uop_CXX_write(cxx_methods):
    pass

#interpret each microp
#return UOPSTORAGE
def uop_interpret(lines_token):
    for lines_token in lines_token:
        # assume that we have at least one token for each line
        uopResult = dict()
        REP = lines_token[0]

        if REP == "MICROOP":
            uopResult.update({"name", lines_token[1]})
        elif (REP == "INPUT") or (REP == "OUTPUT"):
            varSide = REP.lower() # convert to input or output
            uopResult.update({varSide, []})
            for vt in lines_token[1:]:
                if vt not in UOP_IO_TYPE:
                    raise ValueError("there is no this type of microop")
                uopResult[varSide].append(vt)
        elif REP == "MICROOP_END":
            yield uopResult
            uopResult.clear()



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
#return list of token list
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
        #[ #line1#["INPUT", REG, REG, MEM], #line2#["OUTPUT", REG, REG, MEM]]
        cxx_method_list = []
        for interpreted_uop in uop_interpret(tokenLists):
            cxx_method_str = uop_genCXX(interpreted_uop)
            cxx_method_list.append(cxx_method_str)
        uop_CXX_write(cxx_method_list)




