
opcode = [
"JMP","JE",
"JNE","JZ",
"JNZ","JL",
"JLE","JG",
"JGE","JA",
"JAE","JB",
"JBE"
]


srcOperand1 = [
        "",
        "R"
]

srcOperand2 = [
        "R",
        "M",
        "I"
]

desOperand = [
    "R"
]


with open("general_jump.dec.mach", "w") as wf:

    for op in opcode:
        for src_opr1 in srcOperand1:
            for src_opr2 in srcOperand2:
                for des_opr in desOperand:
                    wf.write(f"DECODER FROM {op}  INPUT {src_opr1}{src_opr2}   "
                             f"OUTPUT {des_opr} TO JMP_{src_opr1}_{src_opr2}_{des_opr}\n")
                    

wf.close()


