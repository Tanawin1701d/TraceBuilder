import os
from colorama import init
from termcolor import colored

# DECODE= { mnemonic: "add",
#               inputType: "RLI"   <varTypeAKA> <varTypeAKA2>
#               outputType: "RS"
#               macroop: "ADD_I_M"
# }

REF_VALS = {"DECODER","FROM", "INPUT", "OUTPUT", "TO"}
REF_VAL_DECODE_BEGIN  = "DECODER"
REF_VAL_DECODE_FROM   = "FROM"
REF_VAL_DECODE_INPUT  = "INPUT"
REF_VAL_DECODE_OUTPUT = "OUTPUT"
REF_VAL_DECODE_TO     = "TO"

DEC_IO_INPUT_TYPES = ["R", "I", "L"]
DEC_IO_OUTPUT_TYPE = ["R", "S"]


##### for meta data
DEC_META_NAME           = "mnemonic"
DEC_META_INPUT          = "inputType"
DEC_META_OUTPUT         = "outputType"
DEC_META_MACROOP        = "macroop"



##### for cxx writing
SCRIPT_DIR_PATH=os.path.dirname(os.path.realpath(__file__))
DES_PREFIX     = "../../build/decoder"
INC_MOP        = "../../../mop_base.h"
INC_MOP_X86    = "../mop/x86_mop.h"
INC_RT_INSTR   = "../../../../inst_model/rt_instr.h"
INC_DEC_BASE   = "../../../decoder.h"
HEAD_FILE_NAME = "x86_dec.h"
CXX_FILE_NAME = "x86_dec.cpp"
MACH_FILE_TYPE = ".mach"
# write to file
def dec_writeCXX_file(cxx_eles):
    headerStr = "#ifndef X86_DEC_H\n" \
                "#define X86_DEC_H\n" \
                f"#include\"{INC_MOP_X86}\"\n" \
                f"#include\"{INC_MOP}\"\n" \
                f"#include\"{INC_DEC_BASE}\"\n"\
                "\n\n\n\n\n\n\n"

    headerStr = headerStr + cxx_eles[0] + "\n"

    headerStr = headerStr + "#endif\n"

    cxxStr    =  f"#include\"{HEAD_FILE_NAME}\"\n"
    cxxStr    = cxxStr + f"#include\"{INC_RT_INSTR}\"\n"
    cxxStr    = cxxStr + cxx_eles[1] + "\n"
    ##############################
    headerWritePath = os.path.join(DES_PREFIX, HEAD_FILE_NAME)
    cxxWritePath = os.path.join(DES_PREFIX, CXX_FILE_NAME)

    headerFile   = open(os.path.join(SCRIPT_DIR_PATH,headerWritePath), "w")
    cxxWriteFile = open(os.path.join(SCRIPT_DIR_PATH,cxxWritePath), "w")

    headerFile.write(headerStr)
    cxxWriteFile.write(cxxStr)
    #########################################
    headerFile.close()
    cxxWriteFile.close()


# gen constructor and method
def dec_genCPP_constructorMethod(interpreted_decList):

    cppStr = "DECODER_X86::DECODER_X86(): DECODER_BASE(){\n"

    for interpreted_map in interpreted_decList:
        cppStr = cppStr + "     decodeStorage.insert({{\"{RTKEY}\", (MOP_BASE*)(new MOP_{MOPNAME}())}});\n"\
                            .format(RTKEY = "$".join([interpreted_map[DEC_META_NAME],
                                                      interpreted_map[DEC_META_INPUT],
                                                      interpreted_map[DEC_META_OUTPUT]])   ,
                                    MOPNAME = interpreted_map[DEC_META_MACROOP]
                                     )
    cppStr = cppStr + "}\n"

    return cppStr

def dec_genCPP_decodeMopMethod(interpreted_decList):

    cppStr = "MOP_BASE*\n" \
             "DECODER_X86::decodeMOP(RT_INSTR& rt_instr) {\n" \
             "" \
             "auto finder = decodeStorage.find(rt_instr.getDecodeKey());\n" \
             "return ( finder == decodeStorage.end() ) ? simpleMop: finder->second;\n" \
             "\n" \
             "}"
    return cppStr

# mop gen cxx method for each file
def dec_genCXX_methods(interpreted_decList):
    headerStr = "class DECODER_X86 : DECODER_BASE{\n" \
                "private:\n" \
                "       unordered_map<std::string, MOP_BASE*> decodeStorage;\n" \
                "public:\n" \
                "                 DECODER_X86();\n" \
                "       MOP_BASE* decodeMOP(RT_INSTR& rt_instr) override;\n" \
                "};\n"

    cppStr    = dec_genCPP_constructorMethod(interpreted_decList) + "\n\n\n\n\n\n"\
                + dec_genCPP_decodeMopMethod  (interpreted_decList)

    return headerStr, cppStr

# interpret microop
def interpret_decoder(linesToken):

    retDec = dict()

    for singleLineToken in linesToken:
        retDec.clear()
        retDec.update({DEC_META_NAME    :  singleLineToken[2]})
        retDec.update({DEC_META_INPUT   :  singleLineToken[4]})
        retDec.update({DEC_META_OUTPUT  :  singleLineToken[6]})
        retDec.update({DEC_META_MACROOP :  singleLineToken[8]})
        print(colored(f"[DEC GEN] interpret DEC: {retDec[DEC_META_NAME]}", "blue"))
        yield retDec

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
    print(colored(f"[DEC GEN] start reading file {srcFilePath}", "cyan"))
    with open(srcFilePath, "r") as srcFile:
        lines = srcFile.readlines()
        for line in lines:
            splitedToken = line.strip().split()
            if (len(splitedToken) > 0) and (splitedToken[0] in REF_VALS):
                result.append(splitedToken)
    return result


def start():
    init()
    print(colored("[DEC GEN]===================== start decoder generator =====================", "magenta"))
    tokenListsPool = []
    for singleFileTokenList in readFiles():
        tokenListsPool = tokenListsPool + singleFileTokenList

    interpretedDecPool = interpret_decoder(tokenListsPool)

    headerStr, cppStr =  dec_genCXX_methods(interpretedDecPool)
    dec_writeCXX_file((headerStr, cppStr))
    return interpretedDecPool
