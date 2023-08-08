import traceBuilder as tbd
from model.model import *
from pyMach.X86.resMap import *
from pyMach.X86.decode.base import *
from pyMach.X86.decode.conMov import *


def decodePushPop(instr: tbd.INSTR, mop:tbd.MOP):
    ####### use mov to move data from memory first
    decodeConsistantMov(instr, mop)
    ####### change rsp stack
    execUnit, uopClass = gem5_opclass["IntAlu"]
    UOP_SUB = UOP(uopClass, execUnit)
    UOP_SUB.addLink(OPR_REG(RSP_REG),subRegIdx = 0, isSrc=True)
    UOP_SUB.addLink(OPR_REG(RSP_REG),subRegIdx = 0, isSrc=False)
