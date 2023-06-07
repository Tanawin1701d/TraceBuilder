import os
from termcolor import colored

import base.generator.header as hd




hppList = [] #### list of generated string
cppList = [] #### list of generated string
genAlready = set()

class UopGenUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)


def addToUopGenGroup(uop): #### expect uop type

    uuid, hpp, cpp = uop.genCXX_all()

    if (type(hpp) is not str) or (type(cpp) is not str):
        UopGenUsageError("can not prepare Generate cxx type error")

    if uuid in genAlready:
        return

    hppList.append(hpp)
    cppList.append(cpp)
    genAlready.add(uuid)


def writeAllHppUop():
    headerStr = "#ifndef {ARCH}_UOPL_H\n" \
                "#define {ARCH}_UOPL_H\n" \
                "#include\"{INC_DEP}\"\n" \
                "#include\"{INC_UOP}\"\n" \
                "\n\n\n\n".format(
                    ARCH = hd.ARCH,
                    INC_DEP = hd.INC_DEP_BASE,
                    INC_UOP = hd.INC_UOP_BASE
                )
    ####### add namespace
    headerStr = headerStr + "namespace {NSP_MODEL} {{\n\n\n\n".format(NSP_MODEL = hd.NSP_MODEL)

    headerStr = headerStr + \
        "///////////////////////////////////////////////////////////////\n\n\n\n"\
        .join(hppList)

    headerStr = headerStr + "\n}\n" ###### close namespace

    headerStr = headerStr + "\n#endif"




    #### write file
    desPath = os.path.join(hd.ARCH_HOME_DIR, hd.UOP_HFILE_NAME)
    with open(desPath, "w") as writeFile:
        writeFile.write(headerStr)
    writeFile.close()
    print(colored(f"[UOP writer] uop header file is generated and closed gracefully", "green"))


def writeAllCppUop():
    cppStr = "#include\"{UOP_HFILE_NAME}\"\n" \
             "#include\"{INC_UOP_WD}\"\n".format(UOP_HFILE_NAME = hd.UOP_HFILE_NAME,
                                              INC_UOP_WD     =hd.INC_UOP_WD
                                              )

    cppStr = cppStr + "namespace {NSP_MODEL} {{\n\n\n\n".format(NSP_MODEL = hd.NSP_MODEL)
    #cppStr = cppStr + "using namespace {NSP_CORE};\n".format(NSP_CORE = hd.NSP_CORE)
    #cppStr = cppStr + "using namespace {NSP_UTIL};\n".format(NSP_UTIL = hd.NSP_UTIL)
    cppStr = cppStr + "using namespace {NSP_STAT};\n".format(NSP_STAT = hd.NSP_STAT)
    cppStr = cppStr + "\n\n\n\n"

    cppStr = cppStr + "///////////////////////////////////////////////////////////////\n\n\n\n"\
                        .join(cppList)

    cppStr = cppStr + "\n}\n" #### close namespace

    #### write file
    desPath = os.path.join(hd.ARCH_HOME_DIR, hd.UOP_CFILE_NAME)
    with open(desPath, "w") as writeFile:
        writeFile.write(cppStr)
    writeFile.close()
    print(colored(f"[UOP writer] uop cppbody file is generated and closed gracefully", "green"))

def writeAll():
    writeAllHppUop()
    writeAllCppUop()
