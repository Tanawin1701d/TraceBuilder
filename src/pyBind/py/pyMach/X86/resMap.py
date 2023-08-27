import traceBuilder as tbd
from model.model import *

RIP_REG_NUM       = 16
RSP_REG_NUM       = 6
ARCH_REG_SIZE     = 8  ### byte
ARCH_REG_FLT_SIZE = 10

RSP_REG = tbd.AREGNUM(RSP_REG_NUM, 1)
RIP_REG = tbd.AREGNUM(RIP_REG_NUM, 1)

INS_TYPE_NORM_INT = 0
INS_TYPE_NORM_FLT = 1
INS_TYPE_SIMD_INT = 2
INS_TYPE_SIMD_FLT = 3

UOPTYPE_COMP = tbd.UOP_TYPE.UOP_COMP
UOPTYPE_LOAD = tbd.UOP_TYPE.UOP_LOAD
UOPTYPE_STORE = tbd.UOP_TYPE.UOP_STORE
UOPTYPE_IMM = tbd.UOP_TYPE.UOP_IMM

possibleDecodeType = ["consistentComp", "consistentCompAndPushPop", "compSimdScalar", "cvtpackSimd", "compSimdWithInt",
                      "movHLLH", "pushPop",
                      "mov64bc", "mov64Simd", "consistentMov", "consistentMovAndPop", "jmpInstr", "consistentMovConst"]
ignoreDecodeType = "ignore"

####### MAPPER ##############################################
mnemonicToDecoderType = dict()
mnemonicToOpClassName = dict()
mnemonicToMemTransfer = dict()
mnemonicToRegTransfer = dict()

isMapperInitialized = False


def initializeMapper():
    global isMapperInitialized
    if isMapperInitialized:
        return
    ###########

    file = open("pyMach/X86/x86DecodeMeta.csv")
    cnt = 0
    for line in file.readlines():
        decodeType, gemOpClassName, memTransferType, regTransferType, mnemonic = line.split(',')

        decodeType = decodeType.strip()
        gemOpClassName = gemOpClassName.strip()
        memTransferType = memTransferType.strip()
        regTransferType = regTransferType.strip()
        mnemonic = mnemonic.strip()

        if decodeType in possibleDecodeType:
            mnemonicToOpClassName[mnemonic] = gemOpClassName
            mnemonicToDecoderType[mnemonic] = decodeType
            mnemonicToMemTransfer[mnemonic] = memTransferType
            mnemonicToRegTransfer[mnemonic] = regTransferType
            cnt = cnt + 1
            if "Simd" in gemOpClassName:
                #### for now, we weakly support avx256
                mnemonicToOpClassName["V" + mnemonic] = gemOpClassName
                mnemonicToDecoderType["V" + mnemonic] = decodeType
                mnemonicToMemTransfer["V" + mnemonic] = memTransferType
                mnemonicToRegTransfer["V" + mnemonic] = regTransferType
                cnt = cnt + 1

    file.close()
    print(f"[TBD FED] instruction mapper map got {cnt} instr matched")
    isMapperInitialized = True


############################################################# get op and decode type
def getInstrOpClassName(mnemonic: str):
    return mnemonicToOpClassName.get(mnemonic, "IntAlu")


def getInstrDecodeType(mnemonic: str):
    return mnemonicToDecoderType.get(mnemonic, "UnKnown")


def getMemOpClass(isLoad: bool, isSimd: bool = False, isFlt: bool = False):
    if isSimd:
        return gem5_opclass["Mem{rw}Float".format(rw="Read" if isLoad else "Write")]
    else:
        return gem5_opclass["Mem{rw}{iof}".format(rw="Read" if isLoad else "Write",
                                                  iof="Float" if isFlt else "")]


def getImmOpClass(isFlt: bool = False):
    return gem5_opclass["FloatAdd"] if isFlt else gem5_opclass["IntAlu"]


def getTransferOpClass(instr: tbd.INSTR):
    mnemonic = instr.getMnemonic()

    ####### check is there mem operand to used
    thereIsMemOpr = False
    isMemLoad     = False
    isMemStore    = False
    if len(instr.getSrcLdOpr()) > 0:
        thereIsMemOpr = True; isMemLoad = True
    if len(instr.getDesStOpr()) > 0:
        thereIsMemOpr = True; isMemStore = True

    if thereIsMemOpr:
        #### TODO handle case load and store at the same time
        return getMemOpClass(isMemLoad, False, "flt" == mnemonicToMemTransfer.get(mnemonic, "int"))


    ######## case transfer with in reg

    regTransferType = mnemonicToRegTransfer.get(mnemonic, "int")

    if regTransferType == "auto":
        srcRegId = instr.getSrcRegOpr()[0].getData().archRegId
        desRegId = instr.getDesRegOpr()[0].getData().archRegId

        isSrcSimd = srcRegId >= 200 and srcRegId <= 260
        isDesSimd = desRegId >= 200 and desRegId <= 260

        if isSrcSimd != isDesSimd:
            return gem5_opclass["SimdMisc"]
        else:
            return gem5_opclass["IntAlu"]

    elif regTransferType == "int":
        return gem5_opclass["IntAlu"]
    elif regTransferType == "flt":
        return gem5_opclass["FloatAdd"]
    else:
        MODEL_USAGE_ERR("transfer instruction have no op class")

def getCompOpclass(instr: tbd.INSTR):
    opClassName = getInstrOpClassName(instr.getMnemonic())
    return gem5_opclass.get(opClassName, "IntAlu")


############################################################## instr class

######### this is used for compute instruction not for transfer instruction
def getInstrType(instr: tbd.INSTR):
    mnemonic = instr.getMnemonic()
    gem5OpClass = getInstrOpClassName(mnemonic)
    if "SimdFloat" in gem5OpClass:
        return INS_TYPE_SIMD_FLT
    elif "Simd" in gem5OpClass:
        return INS_TYPE_SIMD_INT
    elif "Float" in gem5OpClass:
        return INS_TYPE_NORM_FLT
    else:
        return INS_TYPE_NORM_INT


def isFltInstr(instr: tbd.INSTR):
    instrType = getInstrType(instr)
    return instrType in [INS_TYPE_SIMD_FLT, INS_TYPE_NORM_FLT]


def isFltNormInstr(instr: tbd.INSTR):
    instrType = getInstrType(instr)
    return instrType == INS_TYPE_NORM_FLT


def isSimdInstr(instr: tbd.INSTR):
    instrType = getInstrType(instr)
    return instrType in [INS_TYPE_SIMD_FLT, INS_TYPE_SIMD_INT]


######################################################################################


gem5_opclass = {
    "No_OpClass": (0, UOPTYPE_COMP),
    "IntAlu": (1, UOPTYPE_COMP),  ## used
    "IntMult": (2, UOPTYPE_COMP),  ## used
    "IntDiv": (3, UOPTYPE_COMP),  ## used
    "FloatAdd": (4, UOPTYPE_COMP),  ## used
    "FloatCmp": (5, UOPTYPE_COMP),
    "FloatCvt": (6, UOPTYPE_COMP),  ###### unknown
    "FloatMult": (7, UOPTYPE_COMP),  ## used
    "FloatMultAcc": (8, UOPTYPE_COMP),  ###### unknown
    "FloatDiv": (9, UOPTYPE_COMP),  # used
    "FloatMisc": (10, UOPTYPE_COMP),  ###### unknown
    "FloatSqrt": (11, UOPTYPE_COMP),  # skip
    "SimdAdd": (12, UOPTYPE_COMP),
    "SimdAddAcc": (13, UOPTYPE_COMP),
    "SimdAlu": (14, UOPTYPE_COMP),
    "SimdCmp": (15, UOPTYPE_COMP),
    "SimdCvt": (16, UOPTYPE_COMP),
    "SimdMisc": (17, UOPTYPE_COMP),
    "SimdMult": (18, UOPTYPE_COMP),
    "SimdMultAcc": (19, UOPTYPE_COMP),
    "SimdShift": (20, UOPTYPE_COMP),
    "SimdShiftAcc": (21, UOPTYPE_COMP),
    "SimdDiv": (22, UOPTYPE_COMP),
    "SimdSqrt": (23, UOPTYPE_COMP),
    "SimdFloatAdd": (24, UOPTYPE_COMP),
    "SimdFloatAlu": (25, UOPTYPE_COMP),
    "SimdFloatCmp": (26, UOPTYPE_COMP),
    "SimdFloatCvt": (27, UOPTYPE_COMP),
    "SimdFloatDiv": (28, UOPTYPE_COMP),
    "SimdFloatMisc": (29, UOPTYPE_COMP),
    "SimdFloatMult": (30, UOPTYPE_COMP),
    "SimdFloatMultAcc": (31, UOPTYPE_COMP),
    "SimdFloatSqrt": (32, UOPTYPE_COMP),
    "SimdReduceAdd": (33, UOPTYPE_COMP),
    "SimdReduceAlu": (34, UOPTYPE_COMP),
    "SimdReduceCmp": (35, UOPTYPE_COMP),
    "SimdFloatReduceAdd": (36, UOPTYPE_COMP),
    "SimdFloatReduceCmp": (37, UOPTYPE_COMP),
    "SimdAes": (38, UOPTYPE_COMP),
    "SimdAesMix": (39, UOPTYPE_COMP),
    "SimdSha1Hash": (40, UOPTYPE_COMP),
    "SimdSha1Hash2": (41, UOPTYPE_COMP),
    "SimdSha256Hash": (42, UOPTYPE_COMP),
    "SimdSha256Hash2": (43, UOPTYPE_COMP),
    "SimdShaSigma2": (44, UOPTYPE_COMP),
    "SimdShaSigma3": (45, UOPTYPE_COMP),
    "SimdPredAlu": (46, UOPTYPE_COMP),
    "MemRead": (47, UOPTYPE_LOAD),
    "MemWrite": (48, UOPTYPE_STORE),
    "MemReadFloat": (49, UOPTYPE_LOAD),
    "MemWriteFloat": (50, UOPTYPE_STORE),
    "IprAccess": (51, UOPTYPE_COMP),
    "InstPrefetch": (52, UOPTYPE_COMP),
}