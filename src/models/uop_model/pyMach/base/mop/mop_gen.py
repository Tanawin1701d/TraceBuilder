import os
from termcolor import colored
import base.mop.mop_base    as mop_base
import base.generator.header as hd

hppList = [] #### list of generated string
cppList = [] #### list of generated string
genAlready = set()
genGroupAlready = set()
fileSuffix = str()
class MopGenUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)


def addToMopGenGroup(mop): #### expect mop type

    if isinstance(mop, mop_base.MOP_BASE):
        uuid, hpp, cpp = mop.genCXX_all()

        if (type(hpp) is not str) or (type(cpp) is not str):
            MopGenUsageError("can not prepare Generate cxx type error")

        if uuid in genAlready:
            return

        hppList.append(hpp)
        cppList.append(cpp)
        genAlready.add(uuid)

    elif isinstance(mop, None):
        pass
        ####### for mop generating groups


def writeAllHppMop():
    headerStr = "#ifndef {ARCH}_MOPL_{FILE_SUFFIX}_H\n" \
                "#define {ARCH}_MOPL_{FILE_SUFFIX}_H\n" \
                "#include\"{INC_DEP}\"\n" \
                "#include\"{INC_MOP}\"\n" \
                "#include\"{INC_MYUOP}\"\n" \
                "\n\n\n\n".format(
                    ARCH = hd.ARCH,
                    INC_DEP = hd.INC_DEP_SIM,
                    INC_MOP = hd.INC_MOP_BASE,
                    INC_MYUOP = hd.UOP_HFILE_NAME,
                    FILE_SUFFIX = fileSuffix
                )

    headerStr = headerStr + "namespace {NSP_MODEL} {{\n\n\n\n".format(NSP_MODEL = hd.NSP_MODEL)
    headerStr = headerStr + "class RT_INSTR;\n\n\n"
    headerStr = headerStr + \
        "///////////////////////////////////////////////////////////////\n\n\n\n"\
        .join(hppList)

    headerStr = headerStr + "\n}\n" ##### close namespace
    headerStr = headerStr + "\n#endif"

    #### write file
    desPath = os.path.join(hd.ARCH_HOME_DIR, hd.getMopHeaderFileName(fileSuffix))
    hd.writeFile(desPath, headerStr)
    print(colored(f"[UOP writer] mop header file is generated and closed gracefully", "green"))


def writeAllCppMop():
    cppStr = "#include\"{MOP_HFILE_NAME}\"\n" \
             "#include\"{INC_RT_INSTR}\"\n\n\n\n".format(MOP_HFILE_NAME = hd.getMopHeaderFileName(fileSuffix),
                                                INC_RT_INSTR   = hd.INC_RT_INSTR
                                              )
    cppStr = cppStr + "namespace {NSP_MODEL} {{\n\n\n\n".format(NSP_MODEL = hd.NSP_MODEL)
    #cppStr = cppStr + "using namespace {NSP_CORE};\n".format(NSP_CORE=hd.NSP_CORE)
    #cppStr = cppStr + "using namespace {NSP_UTIL};\n".format(NSP_UTIL=hd.NSP_UTIL)
    cppStr = cppStr + "using namespace {NSP_STAT};\n".format(NSP_STAT=hd.NSP_STAT)
    cppStr = cppStr + "\n\n\n\n"

    cppStr = cppStr + "///////////////////////////////////////////////////////////////\n\n\n\n"\
                        .join(cppList)

    cppStr = cppStr + "\n}\n" ##### close namespace

    #### write file
    desPath = os.path.join(hd.ARCH_HOME_DIR, hd.getMopCxxFileName(fileSuffix))
    hd.writeFile(desPath, cppStr)
    print(colored(f"[UOP writer] mop cppbody file is generated and closed gracefully", "green"))

def writeFile(name: str):
    global fileSuffix
    if name not in genGroupAlready:
        fileSuffix = name
        writeAllHppMop()
        writeAllCppMop()
    hppList.clear()
    cppList.clear()
