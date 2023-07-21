import base.operand.opr_simple as opr_sim

class OPR_MEM_W_IPR(opr_sim.OPR_MEM):

    def __init__(self, name: str, isSrc : bool):
        super().__init__(name, isSrc)
        self.uniqDecodeName = "MIP"




class OPR_REG_W_RD_IPTR(opr_sim.OPR_REG):

    def __init__(self, name: str, isSrc : bool):
        super().__init__(name, isSrc)

    def genCXX_typeInitializer(self, **kwargs) -> str:
            return "{OPRTYPE}({AREG}, -1)".format(
                OPRTYPE = self.genCXX_varType(),
                AREG    = "ARCH_RIP"
            )

