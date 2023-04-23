import base.uop.uop_gen as u_gen

import X86.uop.alu.comp_uop    as u_alu
import X86.uop.mov.dataMov_uop as u_mov



def gen():
    ##### generate all posible comp
    uop_comp = u_alu.UOP_COMP("simple_comp")
    u_gen.addToUopGenGroup(uop_comp)

    #####  generate all mov comp
    uop_mov = u_mov.UOP_MOV("simple_mov")
    u_gen.addToUopGenGroup(uop_mov)


    ##### write all to data
    u_gen.writeAll()