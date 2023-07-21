import traceBuilder      as tbd
import model.model       as model

UOP_COMP = tbd.UOP_TYPE.UOP_COMP

class simple_model (model.MODEL):
    def decode(self, rt_instr, mop):
        x = model.UOP(UOP_COMP, 0)

        for opr in rt_instr.getSrcRegOpr():
            x.addLink(opr, subRegIdx = 0, isSrc = True)
        for opr in rt_instr.getSrcLdOper():
            x.addLink(opr, startByte = 0, stopByte = 8, isSrc = True)

        for opr in rt_instr.getDesRegOpr():
            x.addLink(opr, subRegIdx = 0, isSrc = False)
        for opr in rt_instr.getDesStOpr():
            x.addLink(opr, startByte = 0, stopByte = 8, isSrc = False)
