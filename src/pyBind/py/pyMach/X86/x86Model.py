import traceBuilder as tbd

from model.model import *
from pyMach.X86.decode.conComp import *
from pyMach.X86.decode.conCompPP import *
from pyMach.X86.decode.conCompSimdScalar import *
from pyMach.X86.decode.conMov import *
from pyMach.X86.decode.conMovConst import *
from pyMach.X86.decode.jmpInstr import *
from pyMach.X86.decode.mov64Simd import *
from pyMach.X86.decode.pushPop import *


class x86_model(MODEL):


    def __init__(self):
        super().__init__()
        resMap.initializeMapper()

    def decode(self, instr: tbd.INSTR, mop: tbd.MOP):
        mnemonic = instr.getMnemonic()
        opType = getInstrDecodeType(mnemonic)
        print(mnemonic)
        if mnemonic == "AND":
            print("eror")
        if   opType == "consistentComp"            : decodeConsistantComp(instr, mop)
        elif opType == "consistentCompAndPushPop"  : decodeCompPP        (instr, mop)
        elif opType == "compSimdScalar"            : decodeCompSimdScalar(instr, mop)
        elif opType == "cvtpackSimd"               : decodeConsistantComp(instr, mop)
        elif opType == "compSimdWithInt"           : decodeConsistantComp(instr, mop)
        elif opType == "movHLLH"                   : decodeConsistantMov (instr, mop)
        elif opType == "pushPop"                   : decodePushPop       (instr, mop)
        elif opType == "mov64bc"                   : decodeMov64Simd     (instr, mop)
        elif opType == "mov64Simd"                 : decodeMov64Simd     (instr, mop)
        elif opType == "consistentMov"             : decodeConsistantMov (instr, mop)
        elif opType == "consistentMovAndPop"       : decodeConsistantMov (instr, mop)
        elif opType == "jmpInstr"                  : decodebranch        (instr, mop)
        elif opType == "consistentMovConst"        : decodeConsistantComp(instr, mop)
        else                                       : mop.setWeakDecode(); decodeConsistantComp(instr, mop)