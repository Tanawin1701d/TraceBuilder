import itertools

opcode = [
            ("V256_PSEUDO_COMP", "COMP_V64"),
            ("V128_PSEUDO_COMP","COMP_V128"),
            ("V64_PSEUDO_COMP", "COMP_V128")
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

productList = [opcode, srcOperand1, srcOperand2, desOperand]

with open("vec_alu.dec.mach", "w") as wf:

    for ele in itertools.product(*productList):
        ele_mnemonic = ele[0][0]
        ele_src1     = ele[1]
        ele_src2     = ele[2]
        ele_des1     = ele[3]
        ele_mop      = ele[0][1]
        wf.write(f"DECODER FROM {ele_mnemonic}  INPUT {ele_src1}{ele_src2}   "
                 f"OUTPUT {ele_des1} TO {ele_mop}_{ele_src1}_{ele_src2}_{ele_des1}\n")