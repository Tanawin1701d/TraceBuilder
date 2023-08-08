import sys
import os

thisFolderPath = os.path.dirname(os.path.realpath(__file__))
projectPath    = os.path.join(thisFolderPath, "../../../")
tbdLibDirPath  = os.path.join(projectPath, "cmake-build-debug/")
sys.path.append(tbdLibDirPath)

import traceBuilder as tbd
import core.core    as core
import pyMach.X86.x86Model as md

pid = os.getpid()
print("Process ID:", pid)

cmd = int(input("fluidAnimate press 1 / blackholes press 2"))
if (cmd != 1 and cmd != 2):
    exit(1)
cmd = "fluidanimate" if cmd == 1 else "blackscholes"



##### declare resource
mem_mng = tbd.MEM_MNG(12, 6, 1 << (4 + 30), 0)
exec_res = tbd.EXEC_UNIT_RES(0, 100)
###### pin
PinStaticPath = os.path.join(projectPath, "pin/PinOutput/{workLoad}/static2" .format(workLoad = cmd))
PinDynPath    = os.path.join(projectPath, "pin/PinOutput/{workLoad}/dynamic2".format(workLoad = cmd))
pinFed        = tbd.LAGACY_PIN_TRACER(PinStaticPath, PinDynPath)
###### gem5 result frontend
gem5dynPath   = os.path.join(projectPath, "pin/TbOutput/{workLoad}/DynTbdIsa3").format(workLoad = cmd)
gem5Fed       = tbd.TBD_GEM5_ISA(gem5dynPath)
gem5Fed.test()
###################################################

session = core.SESSION("testSession", mem_mng, exec_res)
session.addWorker(pinFed, gem5Fed, 256)
session.addModel(md.x86_model())
session.start()


###### get stat file
tbd.finalizeStat()
gem5StatPath   = os.path.join(projectPath, "pin/TbOutput/{workLoad}/DynTbdIsaStat3").format(workLoad = cmd)
tbd.saveStat(gem5StatPath)