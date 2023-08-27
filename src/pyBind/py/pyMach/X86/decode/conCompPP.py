import traceBuilder as tbd
from model.model import *
from pyMach.X86.resMap import *
from pyMach.X86.decode.base import *

from pyMach.X86.decode.conComp import *

##############################################################################
########## for now push and pop register is fixed to normal consistent
########## due to lack information about mach level meta data for push and pop
##############################################################################


def decodeCompPP(instr: tbd.INSTR, mop: tbd.MOP):
    decodeConsistantComp(instr, mop)

