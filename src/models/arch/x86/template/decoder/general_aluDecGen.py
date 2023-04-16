import itertools

opcode = ["ADC", "ADD", 
          "AND", "OR", 
          "ROL", "ROR", 
          "SAL", "SAR", 
          "SBB", "SHL",
          "SHLD", "SHR",
          "SHRD", "SUB",
          "XCHG", "XOR"
          ]


srcOperand1 = [
        "R",
        "M"
]

srcOperand2 = [
        "I",
        "R",
        "M"
]

desOperand = [
    "R",
    "M"
]


with open("general_alu.dec.mach", "w") as wf:

    for op in opcode:
        for src_opr1 in srcOperand1:
            for src_opr2 in srcOperand2:
                for des_opr in desOperand:
                    wf.write(f"DECODER FROM {op}  INPUT {src_opr1}{src_opr2}   "
                             f"OUTPUT {des_opr} TO COMP_{src_opr1}_{src_opr2}_{des_opr}\n")
                    

wf.close()
