import traceBuilder as tbd

preFixStr = "[TBD FED]"

class SESSION:
    preFixStr_ses = "[SESSION]"
    def __init__(self, sessionName, memMng, ExecUnit):
        self.sessionName = sessionName
        self.core        = tbd.CORE(memMng, ExecUnit)
        self.model       = None

    def addWorker(self, traceFed, resultFed, traceWindowSize):
        self.core.addWorker(traceFed, resultFed, traceWindowSize)

    def addModel(self, model):
        self.model = model

    def start(self):
        ##### static trace
        print(f"{preFixStr}{self.preFixStr_ses} start static trace!")
        self.core.startStaticTrace()
        print(f"{preFixStr}{self.preFixStr_ses} finish static trace!")

        ##### decode instruction
        print(f"{preFixStr}{self.preFixStr_ses} start decode instructions")
        for model_tid in range(self.core.getAmtThread()):
            self.model.startDecodeCore(self.core, model_tid)
        print(f"{preFixStr}{self.preFixStr_ses} finish decode instructions")

        ##### finish dynamic trace
        print(f"{preFixStr}{self.preFixStr_ses} start dynamic trace!")
        self.core.startDynTrace()
        print(f"{preFixStr}{self.preFixStr_ses} finish decode instructions")