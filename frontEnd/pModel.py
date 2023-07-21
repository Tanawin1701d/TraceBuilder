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

exec_res = tbd.EXEC_UNIT_RES(0, 100)

###### pin
PinStaticPath = os.path.join(projectPath, "pin/PinOutput/{workLoad}/static2" .format(workLoad = cmd))
PinDynPath    = os.path.join(projectPath, "pin/PinOutput/{workLoad}/dynamic2".format(workLoad = cmd))
pinFed        = tbd.LAGACY_PIN_TRACER(PinStaticPath, PinDynPath)
###### gem5 result frontend
gem5dynPath   = os.path.join(projectPath, "pin/TbOutput/{workLoad}/DynTbdIsa_testNewPy").format(workLoad = cmd)
gem5Fed       = tbd.TBD_GEM5_ISA(gem5dynPath)
###### core
core          = tbd.CORE(mem_mng, exec_res)
core.addWorker(pinFed, gem5Fed, 256)

start = time.time()
core.startStaticTrace()
threadModel = core.getThreadModel(0)

######## get Rt instr
for i in range(threadModel.getAmountInstr()):
    rt_instr = threadModel.getRtInstr(i)
    uop      = tbd.UOP(tbd.UOP_TYPE.UOP_COMP, 1)
    #print(type(rt_instr))
    for opr in rt_instr.getSrcRegOpr():
        uop.addLink_OPR_REG(opr, 0, True)
    for opr in rt_instr.getSrcLdOper():
        uop.addLink_OPR_MEM(opr, 0, 8, True)
    for opr in rt_instr.getDesRegOpr():
        uop.addLink_OPR_REG(opr, 0, False)
    for opr in rt_instr.getDesStOpr():
        uop.addLink_OPR_MEM(opr, 0, 8, False)
    mop      = tbd.MOP(rt_instr)
    mop.addUopAgents([uop])
    threadModel.decodeInstr(i, mop)

core.startDynTrace()
end = time.time()



print("time use is ", end - start)

tbd.finalizeStat()
gem5StatPath   = os.path.join(projectPath, "pin/TbOutput/{workLoad}/DynTbdIsa_stat_testNewPy").format(workLoad = cmd)
tbd.saveStat(gem5StatPath)

