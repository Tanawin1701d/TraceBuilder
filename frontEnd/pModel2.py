import os
import sys

thisFolderPath = os.path.dirname(os.path.realpath(__file__))
projectPath    = os.path.join(thisFolderPath, "../")
tbdFedPath    = os.path.join(thisFolderPath, "../src/pyBind/py")
sys.path.append(tbdFedPath)

for path in sys.path:
    print(path)

import tbdFrontEnd
import core.core as core
import simpleModel as md
import traceBuilder as tbd

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
gem5dynPath   = os.path.join(projectPath, "pin/TbOutput/{workLoad}/DynTbdIsa_testNewPy").format(workLoad = cmd)
gem5Fed       = tbd.TBD_GEM5_ISA(gem5dynPath)
gem5Fed.test()
###################################################

session = core.SESSION("testSession", mem_mng, exec_res)
session.addWorker(pinFed, gem5Fed, 256)
session.addModel(md.simple_model())
session.start()