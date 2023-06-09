import sys
import os

thisFolderPath = os.path.dirname(os.path.realpath(__file__))
projectPath    = os.path.join(thisFolderPath, "../")
tbdLibDirPath     = os.path.join(projectPath, "cmake-build-debug/")


sys.path.append(tbdLibDirPath)

import traceBuilder as tbd
pid = os.getpid()
print("Process ID:", pid)
x = input()

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



PinStaticPath = os.path.join(projectPath, "pin/PinOutput/fluidanimate/static")
PinDynPath    = os.path.join(projectPath, "pin/PinOutput/fluidanimate/dynamic")
pinFed        = tbd.LAGACY_PIN_TRACER(PinStaticPath, PinDynPath)

gem5InstrPath = os.path.join(projectPath, "pin/TbOutput/fluidanimate/testRunInstr")
gem5dynPath   = os.path.join(projectPath, "pin/TbOutput/fluidanimate/testRunDyn")
gem5Fed       = tbd.RESULT_FRONT_END_GEM_LAGACY(gem5InstrPath, gem5dynPath, 1000000000, 200)

core          = tbd.CORE(mem_mng, exec_res)
core.addWorker(pinFed, gem5Fed, 200)
core.start(False)

tbd.finalizeStat()
gem5StatPath   = os.path.join(projectPath, "pin/TbOutput/fluidanimate/testRunStat")
tbd.saveStat(gem5StatPath)

