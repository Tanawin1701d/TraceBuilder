# TRACEBUILDER

### TraceBuilder is micro-operation modeling with runtime flow model generator.
 - The micro-operations can be easily implemented in python.
 - The runtime generator is written in c++

### micro-op modeler
- all example x86 model source code is in ```src/pyBind/py```
- to implement your model, you must create these class and import base class correctly
   - ``` python
     import traceBuilder as tbd
     from model.model import *
     #if model is in different folder you must import them correctly
     
     class myModel(MODEL):
     
        def __init__(self):
            super().__init__()
            resMap.initializeMapper()
     
        def  decode(self, instr: tbd.INSTR, mop: tbd.MOP):
            pass
            ####your model
     ```     
- what is instr(args at line 11)?
  - before generating the runtime flow model, instr is the instruction of the benchmark programe
  - it contains all meta-data like mnemonic, operand type, operand meta data
  - you can use these methods to get that value
    - ```instr.getMnemonic() #return mnemonic of that instruction            ```
    - ```instr.getSrcRegOpr() #return [source register operands]```
    - ```instr.getSrcLdOpr() #return [source memory operands]```
    - ```instr.getSrcImmOpr() #return [source immediate operands]```
    - ```instr.getSrcCount() #return source operand coutoperand ```
    - ```instr.getDesRegOpr() #return [destination register operands]```
    - ```instr.getDesStOpr() #return [destination memory operands]```
    - ```instr.getDesCount() #return destination operand coutoperand```
  - the detail of each operand types can see at ```src/models/inst_model/operand.cpp```
- how to build uop model?
  - to build uop ```COMP_UOP = UOP(uopType, execUnit)```
  - to add dependency ```COMP_UOP.addLink(desOperand, args**)```
  - you can see more infomation at ```src/models/uop_model/agent```

### flow model generator
  - to run and config the simple running file is at ```src/pyBind/py/tbdFrontEnd.py```

### detail of the simulator you can see at ```https://docs.google.com/presentation/d/1fUrAWHXKKqLYUo_7FKFLMHbaONUqICxzms0gpraydP0/edit?usp=sharing```

    
