import sys
import os
import time

thisFolderPath = os.path.dirname(os.path.realpath(__file__))
projectPath    = os.path.join(thisFolderPath, "../")
tbdLibDirPath     = os.path.join(projectPath, "cmake-build-debug/")


sys.path.append(tbdLibDirPath)

import traceBuilder as tbd
pid = os.getpid()
print("Process ID:", pid)

cmd = int(input("fluidAnimate press 1 / blackholes press 2"))
if (cmd != 1 and cmd != 2):
    exit(1)
cmd = "fluidanimate" if cmd == 1 else "blackscholes"



mem_mng = tbd.MEM_MNG(12, 6, 1 << (4 + 30), 0)

exec_res = tbd.EXEC_UNIT_RES(98,99)
exec_res.setMaxAvailable(1, 6) #///"INT_SIM_ALU"
exec_res.setMaxAvailable(2, 2) #///"INT_MUL_DIV_ALU"
exec_res.setMaxAvailable(3, 4) #///"FLOAT_SIM_ALU"
exec_res.setMaxAvailable(4, 2) #///"FLOAT_MUL_DIV_ALU"
exec_res.setMaxAvailable(5, 1) #///"SIM128_ALU"
exec_res.setMaxAvailable(6, 4) #///"MOV_MEM_LD"
exec_res.setLatencyCycle(1, 1) #///"INT_SIM_ALU"
exec_res.setLatencyCycle(2, 3) #///"INT_MUL_DIV_ALU"
exec_res.setLatencyCycle(3, 2) #///"FLOAT_SIM_ALU"
exec_res.setLatencyCycle(4, 4) #///"FLOAT_MUL_DIV_ALU"
exec_res.setLatencyCycle(5, 1) #///"SIM128_ALU"
exec_res.setLatencyCycle(6, 1) #///"MOV_MEM_LD"



PinStaticPath = os.path.join(projectPath, "pin/PinOutput/{workLoad}/static" .format(workLoad = cmd))
PinDynPath    = os.path.join(projectPath, "pin/PinOutput/{workLoad}/dynamic".format(workLoad = cmd))
pinFed        = tbd.LAGACY_PIN_TRACER(PinStaticPath, PinDynPath)

gem5dynPath   = os.path.join(projectPath, "pin/TbOutput/{workLoad}/tbdIsaDyn256_mini").format(workLoad = cmd)
gem5Fed       = tbd.TBD_GEM5_ISA(gem5dynPath)

core          = tbd.CORE(mem_mng, exec_res)
core.addWorker(pinFed, gem5Fed, 256)

start = time.time()
core.start(False)
end = time.time()



print("time use is ", end - start)

tbd.finalizeStat()
gem5StatPath   = os.path.join(projectPath, "pin/TbOutput/{workLoad}/tbdIsaDyn256Stat_mini").format(workLoad = cmd)
tbd.saveStat(gem5StatPath)

