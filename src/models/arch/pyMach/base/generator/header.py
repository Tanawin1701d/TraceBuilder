import os
from colorama import init
from termcolor import colored
ARCH          = "X86"
THIS_FILE_DIR = os.path.dirname(os.path.realpath(__file__))
TARGET_DIR    = f"../../../{ARCH}"
ARCH_HOME_DIR = os.path.join(THIS_FILE_DIR, TARGET_DIR)

INC_DEP_BASE  = "models/arch/dep.h"
INC_UOP_WD    = "core/tracers/uop_wd.h"
INC_UOP_BASE  = "models/arch/uop_base.h"
INC_MOP_BASE  = "models/arch/mop_base.h"
INC_DEC_BASE  = "models/arch/decoder.h"
INC_RT_INSTR  = "models/inst_model/rt_instr.h"


###### inside file name
### uop
UOP_HFILE_NAME = "{ARCH}_uop.h".format(ARCH = ARCH)
UOP_CFILE_NAME = "{ARCH}_uop.cpp".format(ARCH = ARCH)
### mop
MOP_HFILE_NAME = "{ARCH}_mop.h"  .format(ARCH = ARCH)
MOP_CFILE_NAME = "{ARCH}_mop.cpp".format(ARCH = ARCH)
### dec
DEC_HFILE_NAME = "{ARCH}_dec.h"  .format(ARCH = ARCH)
DEC_CFILE_NAME = "{ARCH}_dec.cpp".format(ARCH = ARCH)

def initializeDir():
    if not os.path.exists(ARCH_HOME_DIR):
        print(colored(f"[{ARCH} INIT] directory not exist -> create New One", "yellow"))
        os.mkdir(ARCH_HOME_DIR)

def writeFile(desPath, dayta):
    with open(desPath, "w") as writeFile:
        writeFile.write(dayta)
    writeFile.close()