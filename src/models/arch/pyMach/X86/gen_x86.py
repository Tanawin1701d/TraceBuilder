import X86.uop.gen_x86 as uop_gen
import X86.mop.gen_x86 as mop_gen
import base.generator.header as hd

def gen():
    hd.initializeDir()
    uop_gen.gen()
    mop_gen.gen()