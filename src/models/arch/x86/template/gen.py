import os
import sys

sys.path.append(os.path.dirname(os.path.realpath(__file__)))


import uop.translator as uop
import mop.translator as mop
import decoder.translator as dec

decOPR_to_mopOPR = {
                      "R"     : "O_REG",
                      "L"     : "O_MEM_LD",
                      "S"     : "O_MEM_ST",
                      "I"     : "DUMMY"
}

mopOPR_to_uopOPR = {  "TEMP"   : "TREG",
                      "O_REG"    : "REG",
                      "O_MEM_LD" : "MEM",
                      "O_MEM_ST" : "MEM"
                    }

def satisfyDecWithMop( singleDec, MOP_DICT ):
    print(singleDec)
    if singleDec[dec.DEC_META_NAME] not in MOP_DICT:
        raise ValueError(f"there is no MACROOP to map from {singleDec}")

    micoopName = singleDec[dec.DEC_META_NAME]

    ##### check input
    input_operandOrder = 0
    for inptType in singleDec[dec.DEC_META_INPUT]: # iterate every input of decoder
        findAns = False
        if inptType != "I":
            ### exhaustsive search with input at associate mop, so we have to search the identical input operand order
            for typeTuple in MOP_DICT[micoopName][mop.MOP_META_INPUT].values():
                if (typeTuple[1] == input_operandOrder)  and (typeTuple[0] == mopOPR_to_uopOPR[inptType]):
                    input_operandOrder = input_operandOrder + 1
                    findAns = True
                    break
            if not findAns :
                raise ValueError(f"decode operand and macroop operand mismatch dec: {singleDec} with mop: {MOP_DICT[micoopName]}")
    ## it count operand order tempvariable is exclude
    if input_operandOrder != len(MOP_DICT[micoopName][mop.MOP_META_INPUT]):
        raise (AttributeError(f"not suffice amount of parameter in {singleDec} to mop {MOP_DICT[micoopName]}"))


    ##### check output
    output_operandOrder = 0
    for outputType in singleDec[dec.DEC_META_OUTPUT]:
        findAns = False
        if outputType != "I":
            ### exhaustsive search with output at associate mop, so we have to search the identical input operand order
            for typeTuple in MOP_DICT[micoopName][mop.MOP_META_OUTPUT].values():
                if (typeTuple[1] == output_operandOrder)  and (typeTuple[0] == mopOPR_to_uopOPR[outputType]):
                    output_operandOrder = output_operandOrder + 1
                    findAns = True
                    break
            if not findAns :
                raise ValueError(f"decode operand and macroop operand mismatch dec: {singleDec} with mop: {MOP_DICT[micoopName]}")
    ## it count operand order tempvariable is exclude
    if output_operandOrder != len(MOP_DICT[micoopName][mop.MOP_META_OUTPUT]):
        raise (AttributeError(f"not suffice amount of parameter in {singleDec} to mop {MOP_DICT[micoopName]}"))



def satisfyMopWithUop(singleMop, UOP_DICT):
    # mopdict is name -> mopmeta data
    for uopName, uopMeta in singleMop[mop.MOP_META_MICROOP].items():
        if not (uopMeta[mop.MOP_META_MICROOP_TYPE] in UOP_DICT):
            raise (ValueError(f"there is no microop type for name {uopName} "
                              f"in uop dictionary from mop {singleMop[mop.MOP_META_NAME]}"))
        ##### check input
        inputInUopManner = [] # the input type that uop accept ex. T_MEM_LD -> MEM(ADAS)
        for varname in uopMeta[mop.MOP_META_MICROOP_INPUT]:
            if varname in singleMop[mop.MOP_META_INPUT]:
                mopOrType = singleMop[mop.MOP_META_INPUT][varname][0] # 0 mean get type of mop operand name
                uopOrType = mopOPR_to_uopOPR[mopOrType]
                inputInUopManner.append(uopOrType)
            else:
                inputInUopManner.append(mopOPR_to_uopOPR["TEMP"])
        if inputInUopManner != UOP_DICT[uopMeta[mop.MOP_META_MICROOP_TYPE]][uop.UOP_MT_INPUT_VT]:
            raise(ValueError(f"[MACROOP] input error! mop: {singleMop} but uop{UOP_DICT[uopName]}"))


        ##### check output
        outputInUopManner = []
        for varname in uopMeta[mop.MOP_META_MICROOP_OUTPUT]:
            if varname in singleMop[mop.MOP_META_OUTPUT]:
                mopOrType = singleMop[mop.MOP_META_OUTPUT][varname][0] # 0 mean get type of mop operand name
                uopOrType = mopOPR_to_uopOPR[mopOrType]
                outputInUopManner.append(uopOrType)
            else:
                outputInUopManner.append(mopOPR_to_uopOPR["TEMP"])
        if outputInUopManner != UOP_DICT[uopMeta[mop.MOP_META_MICROOP_TYPE]][uop.UOP_MT_OUTPUT_VT]:
            raise(ValueError(f"[MACROOP] output error! mop: {singleMop} but uop{UOP_DICT[uopName]}"))

def convertUopListToUopDict(uopList):
    ret = dict()

    for singleUop in uopList:
        ret.update({singleUop[uop.UOP_MT_NAME]: singleUop})

    return  ret

def convertMopListToMopDict(mopList):
    ret = dict()
    for singleMop in mopList:
        ret.update({singleMop[mop.MOP_META_NAME]: singleMop})
    return ret


def start():
    uopMetaList  = uop.start()
    UOPDICT      = convertUopListToUopDict(uopMetaList)

    mopMetaList  = mop.start()
    MOPDICT      = convertMopListToMopDict(mopMetaList)

    ###### satisfy mop
    for singleMop in mopMetaList:
        satisfyMopWithUop(singleMop, UOPDICT)
    ###################################################

    decMetaList =  dec.start()

    ###### satisfy dec
    for singleDec in decMetaList:
        satisfyDecWithMop(singleDec, MOPDICT)
    ###################################################

start()
