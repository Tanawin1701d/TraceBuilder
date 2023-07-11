import os
from colorama import init
from termcolor import colored

import base.dec.dec_gen as dec_gen
import base.mop.mop_gen as mop_gen
import base.uop.uop_gen as uop_gen

ARCH          = "X86"
THIS_FILE_DIR = os.path.dirname(os.path.realpath(__file__))
TARGET_DIR    = f"../../../{ARCH}"
ARCH_HOME_DIR = os.path.join(THIS_FILE_DIR, TARGET_DIR)

######### namespace
NSP_MODEL = "traceBuilder::model"
NSP_CORE  = "core"
NSP_UTIL  = "util"
NSP_STAT  = "stat"

######### model include path
INC_DEP_SIM   = "models/uop_model/dep/dep_simple.h"
INC_META_BASE = "models/uop_model/metaData/metaBase.h"
INC_UOP_BASE  = "models/uop_model/uop_base.h"
INC_MOP_BASE  = "models/uop_model/mop_base.h"
INC_DEC_BASE  = "models/uop_model/decoder.h"
INC_RT_INSTR  = "models/inst_model/rt_instr.h"
######### core include path
INC_UOP_WD    = "core/tracers/uop_wd.h"
###### file name
### uop
UOP_HFILE_NAME = "{ARCH}_uop.h".format(ARCH = ARCH)
UOP_CFILE_NAME = "{ARCH}_uop.cpp".format(ARCH = ARCH)
### mop
MOP_HFILE_NAME = "{ARCH}_mop.h"  .format(ARCH = ARCH)
MOP_CFILE_NAME = "{ARCH}_mop.cpp".format(ARCH = ARCH)
### dec
DEC_HFILE_NAME = "{ARCH}_dec.h"  .format(ARCH = ARCH)
DEC_CFILE_NAME = "{ARCH}_dec.cpp".format(ARCH = ARCH)

#### variable that used in C++
CVAR_ADDR       = "ADDR"
CVAR_REGIDX     = "int"



def initializeDir():
    if not os.path.exists(ARCH_HOME_DIR):
        print(colored(f"[{ARCH} INIT] directory not exist -> create New One", "yellow"))
        os.mkdir(ARCH_HOME_DIR)

def writeFile(desPath, dayta):
    with open(desPath, "w") as writeFile:
        writeFile.write(dayta)
    writeFile.close()

def flush():
    uop_gen.writeAll()
    mop_gen.writeAll()
    dec_gen.writeAll()