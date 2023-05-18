import inspect
import base.mop.mop_gen as m_gen
import base.dec.dec_gen  as d_gen
import X86.mop.alu.compDesReg_mop as comp_mop_1
import X86.mop.alu.comp_mop as comp_mop_2

def gen():
    mopDesReg = inspect.getmembers(comp_mop_1, inspect.isclass)
    mopDesMem = inspect.getmembers(comp_mop_2, inspect.isclass)
    decoderMnemonic = ["ADC" , "ADD", "AND", "OR" , "ROL",
                       "ROR" , "SAL", "SAR", "SBB", "SHL",
                       "SHLD", "SHR","SHRD", "SUB","XCHG", "XOR"]

    for mopTemplate in mopDesMem:
        mop = mopTemplate[1]() ##### initialize class
        m_gen.addToMopGenGroup(mop)
        d_gen.addToDecGenGroup(decoderMnemonic,mop)
    for mopTemplate in mopDesReg:
        mop = mopTemplate[1]() ##### initialize class
        m_gen.addToMopGenGroup(mop)
        d_gen.addToDecGenGroup(decoderMnemonic,mop)

    m_gen.writeAll()
    d_gen.writeAll()