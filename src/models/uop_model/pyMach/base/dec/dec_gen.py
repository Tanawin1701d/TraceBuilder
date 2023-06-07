import os
from termcolor import colored

import base.generator.header as hd

decStorage = []    ##### list of tuple which contain trace decode at first index and mop class type at second

class DecGenUsageError(Exception):
    def __init__(self, message):
        super().__init__(message)

def addToDecGenGroup(mop):

    for decodeIdentifier in mop.genCXX_decodeKey():
        decStorage.append((decodeIdentifier,mop.genCXXType()))


def writeAllHppDec():
    headerStr = "#ifndef {ARCH}_DECL_H\n" \
                "#define {ARCH}_DECL_H\n" \
                "#include\"{INC_DEC}\"\n" \
                "#include\"{INC_MYMOP}\"\n" \
                "\n\n\n\n".format(
                    ARCH = hd.ARCH,
                    INC_DEC   = hd.INC_DEC_BASE,
                    INC_MYMOP = hd.MOP_HFILE_NAME
                )

    ###### add namespace
    headerStr = headerStr + "namespace {NSP_MODEL} {{\n\n\n\n".format(NSP_MODEL = hd.NSP_MODEL)

    headerStr = headerStr + \
        "class RT_INSTR;\n" \
        "class {ARCH}_DECODER : public DECODER_BASE{{\n" \
        "private:\n"\
        "       std::unordered_map<std::string, MOP_BASE*> decodeStorage;\n" \
        "public:\n" \
        "       {ARCH}_DECODER();\n" \
        "       MOP_BASE* decodeMOP(RT_INSTR& rt_instr) override;\n" \
        "}};".format(ARCH = hd.ARCH)

    headerStr = headerStr + "\n}\n" ###### close namespace
    headerStr = headerStr + "\n#endif"

    #### write file
    desPath = os.path.join(hd.ARCH_HOME_DIR, hd.DEC_HFILE_NAME)
    hd.writeFile(desPath, headerStr)
    print(colored(f"[DEC writer] dec header file is generated and closed gracefully", "green"))
    ##########################################################################################


def writeAllCppDec():
    cppStr = "#include\"{DEC_HFILE_NAME}\"\n" \
             "#include\"{INC_RT_INSTR}\"\n".format(DEC_HFILE_NAME = hd.DEC_HFILE_NAME,
                                                  INC_RT_INSTR=hd.INC_RT_INSTR
                                                  )
    cppStr = cppStr + "namespace {NSP_MODEL} {{\n\n\n\n".format(NSP_MODEL = hd.NSP_MODEL)
    #cppStr = cppStr + "using namespace {NSP_CORE};\n".format(NSP_CORE = hd.NSP_CORE)
    cppStr = cppStr + "\n\n\n\n"

    ############ generate constructor
    cppStr = cppStr + "{ARCH}_DECODER::{ARCH}_DECODER(): DECODER_BASE(){{\n\n\n\n".format(ARCH = hd.ARCH)
    for traceCode, mopClass in decStorage:
        cppStr = cppStr + "     decodeStorage.insert({{\"{RTKEY}\", (MOP_BASE*)(new {MOPTYPE}())}});\n"\
                                    .format(RTKEY = traceCode, MOPTYPE = mopClass)
    cppStr = cppStr + "}\n\n\n\n\n"
    ########################################################################################################
    ############ generate mapper
    cppStr = cppStr + \
             "MOP_BASE*\n" \
             "{ARCH}_DECODER::decodeMOP(RT_INSTR& rt_instr) {{\n" \
             "\n" \
             "auto finder = decodeStorage.find(rt_instr.getDecodeKey());\n" \
             "return ( finder == decodeStorage.end() ) ? simpleMop: finder->second;\n" \
             "\n" \
             "}}".format(ARCH = hd.ARCH)

    cppStr = cppStr + "\n}\n" #### close namespace
    ######### write file
    desPath = os.path.join(hd.ARCH_HOME_DIR, hd.DEC_CFILE_NAME)
    hd.writeFile(desPath, cppStr)
    print(colored(f"[DEC writer] dec cpp body file is generated and closed gracefully", "green"))

def writeAll():
    writeAllHppDec()
    writeAllCppDec()


