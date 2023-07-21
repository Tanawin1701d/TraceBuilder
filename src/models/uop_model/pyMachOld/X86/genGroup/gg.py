import base.mop.mop_group_base as mop_group
import base.operand.opr_simple as opr
import X86.mop.alu.comp_mop as cm

class MOP_GROUP_MOV128(mop_group.MOP_GROUP_BASE):

    def __init__(self):
        super().__init__(0, cm.MOP_COMP)
        self.addMopArg(())