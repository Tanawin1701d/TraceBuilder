# X86 MICRO-OP model generator
### model composed of 3 mojor sections
- decoder
- macro-op
- micro-op

## decoder 
- template located at ```template/decoder/*.mach``` file
- syntax 
  - ```DECODER FROM <MNEMONIC> INPUT [<INPUT_TYPE>]  OUTPUT [<OUTPUT_TYPE>] TO <MACRO_OP_NAME>```
    - ```MNEMONIC``` is name of instruction that recorded from instrument tool
    - ```INPUT_TYPE``` is input operand from instrument tool. it can be R(register) I(immediate) L(load operand)
    - ```OUTPUT_TYPE``` is output operand from instrucment tool. it can be R(register) S(store operand)
    - ```MACRO_OP_NAME``` is macro op name that will be declared further
- generating structure
    - ```
      DECODE = {    mnemonic   : "add",
                    inputType  : "RLI"   <varTypeAKA> <varTypeAKA2>
                    outputType : "RS"
                    macroop    : "ADD_I_M"
                }
      ```
      

## macro-op
- template located at ```template/mop/*.mach``` file
- syntax
  -  ```  
        MACROOP <NAME>
              INPUT [<INPUT_TYPE> <INPUT_NAME>]
              OUTPUT [<OUTPUT_TYPE> <OUTPUT_NAME>]
              TEMP  [TEMPVAR_NAME]
              MICROOP <MICROOP_NAME> <relativeName1> INPUT [<VARNAME>] OUTPUT [<VARNAME>]
              MICROOP <MICROOP_NAME> <relativeName2> INPUT [<VARNAME>] OUTPUT [<VARNAME>]
                    .
                    .
                    .
        MACROOP_END
     ```
      - ```NAME``` name of macroop
      - ```INPUT_TYPE``` input operand type it can be ```REG``` register operand ```MEM``` load memory operand
      - ```INPUT_NAME``` name for each operand 
      - ```TEMP``` temporal register variable name
      - ```MICROOP_NAME``` type of microop that macroop need to generate
      - ```relativeName*``` name of microop that associate with microop type
      - ```VARNAME```   varname that input/output for each microop need
- cpp input/output operand association
  - ```REG``` is stand for ```REG_OPERAND``` in c++ operand
  - ```MEM``` is stand for ```LD_OPERAND``` in c++ operand(for variable that declared in INPUT SECTION)
  - ```MEM``` is stand for ```ST_OPERAND``` in c++ operand(for variable that declared in OUTPUT SECTION)
  - in detail, you can read at ```models/inst_model/operand.h``` for ```REG_OPERAND,LD_OPERAND,ST_OPERAND```
- generating structure
  - ```
         MOPSTORAGE= {
                   name: "add",
                   input: { varName: ("MEM", id_int)} # id is order number associated with RT_instruction pool
                   output: {varName: ("REG", id_int)}
                   varTemp {varName}
                   microops:
                         <microop Name>:
                               type   : "type"
                               input  : [varName, varName, varNameTemp, varNameTemp2]
                               output : [varName, varName, varNameTemp]
                               dep    : {<microop Name1>,<microop Name2>, ...} ## depency micro-op name 
         }
    ``` 
- warning
  - macro-op input/output order must orderly correspond with decoder by ignoring immediate operand
  - however, the rt_instruction operand pool at input/output immediate operand will be ignore too
## micro-op
- template located at ```template/uop/*.mach``` file
- syntax
  - ```
        MICROOP <UOP_NAME>
            INPUT  [<IN_TYPE> <IN_NAME>]
            OUTPUT [<OUT_TYPE> <OUT_NAME>]
        MICROOP_END
    ```
    - ```UOP_NAME``` is micro-op name
    - ```IN_TYPE/OUT_TYPE``` is input type. it can be ```REG``` for register operand, ```TREG``` for temporal register operand and ```MEM``` for load or store memory operand
    - ```IN_NAME/OUT_NAME``` is input and out name for each operand

- cpp input/output operand association
    - ```REG``` is stand for  ```REG_OPERAND``` in c++ operand
    - ```TREG``` is stand for ```TREGNUM``` in c++ operand
    - ```MEM``` is stand for ```LD_OPERAND/ST_OPERAND``` in c++ operand
    - In detail,  you can read at ```core/resMng``` directory

- generating structure
  - ```
        UOPSTORAGE { name: "add", 
                     input: [REG, TREG, MEM],
                     inputName: [jennis, mewnich, orn],
                     output: [REG, TREG, MEM],
                     outputName: [jennis, mewnich, orn] 
        }
    ``` 