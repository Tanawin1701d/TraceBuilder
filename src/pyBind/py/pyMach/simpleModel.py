import traceBuilder      as tbd
import model.model       as model

UOP_COMP = tbd.UOP_TYPE.UOP_COMP

class simple_model (MODEL):
    def decode(self, rt_instr, mop):
        srcOprs = self.getSrcOprs(rt_instr)
        desOprs = self.getDesOprs(rt_instr)

        tempOpr  = OPR_TREG(0)
        tempOpr2 = OPR_TREG(1)



        a1 = UOP(UOP_COMP, 0)
        a1.addLink(srcOprs[0], subRegIdx = 0, isSrc = True)
        a1.addLink(tempOpr, isSrc = False)

        a2 = UOP(UOP_STORE, memReadUnit)
        a2.addLink(tempOpr, isSrc = True)
        a2.addLink(desOprs[0], startByte = 0, stopByte = 8)

        if desOprs[0].getData().baseReg.archRegId == rip:
            a3 = UOP(UOP_COMP, rdipReader)
            a2.addLink(tempOpr2, isSrc = True)
