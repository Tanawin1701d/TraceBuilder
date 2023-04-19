import OPERAND as op




class myMop (MOP_BASE):
    ### input/output is parent class variable
    input[0]    = op.REG       ### REG act as external variable
    input[1]    = op.MEM       ### MEM act as external variable
    output[0]   = op.REG       ### REG act as external variable
    internal[0] = op.TREG      ### TREG act as internal variable 

    myload_uop    = load_uop()
    myload.setInput  (tuple (input[0:2]))
    myload.setOutput ((internal[0]))
    
    uopMembers.addToCaculated(myload)
    

    myAdd_uop        = add_uop()
    myAdd_uop.setInput ((input[0], internal[0]))
    myAdd_uop.setOutput((output[0]))

    uopMembers.addToCaculated(myAdd_uop)



class myMopInwzaa (MOP_BASE):
    def __init__(amount: int):
        ### input/output is parent class variable
        
            for i in range(amount):
                input   [2*i    ] = op.REG       ### REG act as external variable
                input   [2*i + 1] = op.MEM       ### MEM act as external variable
                output  [i]       = op.REG       ### REG act as external variable
                internal[i]       = op.TREG      ### TREG act as internal variable 

                myload_uop    = load_uop()
                myload.setInput (tuple (input  [2*i:2*i+2]))
                myload.setOutput(tuple (internal[i]))

                uopMembers.addToCaculated(myload)

                myAdd_uop        = add_uop()
                myAdd_uop.input.setInput((input[2*i], internal[i]))
                myAdd_uop.setOutput((output[i]))

                uopMembers.addToCaculated(myAdd_uop)


class load_uop (UOP_BASE):
    input[0]  = op.REG
    output[0] = op.MEM

    
