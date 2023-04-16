import itertools

opcode = [
            ("V256_PSEUDO_MOV", "MOV_V64"),
            ("V128_PSEUDO_MOV", "MOV_V128"),
            ("V64_PSEUDO_MOV" , "MOV_V128")
        ]

srcOperand1 = [
        "R",
        "M",
        "I"
]

desOperand = [
    "R",
    "M"
]

productList = [opcode, srcOperand1, desOperand]

with open("vec_mov.dec.mach", "w") as wf:

    for ele in itertools.product(*productList):
        ele_mnemonic = ele[0][0]
        ele_src1     = ele[1]
        ele_des1     = ele[2]
        ele_mop      = ele[0][1]

        if (ele_src1 == "M") and (ele_des1 == "M"):
            continue

        wf.write(f"DECODER FROM {ele_mnemonic}  INPUT {ele_src1}   "
                 f"OUTPUT {ele_des1} TO {ele_mop}_{ele_src1}_{ele_des1}\n")