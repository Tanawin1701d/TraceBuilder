//

#include "tracer.h"

//
// Created by tanawin on 7/1/2566.

void ETRACER::INSTR_WINDOW::addReg(REGNUM regNum, uint64_t seqNum){
    regDep[regNum]++;
    regResult[regNum] = seqNum;

}

void ETRACER::INSTR_WINDOW::rmReg(REGNUM regNum){
    assert(regDep[regNum] >= 0);
    regDep[regNum]--;
}

ETRACER::INSTR_WINDOW::INSTR_WINDOW(INSTR_MODEL_MANAGER* _instr_model_mng):
instrModelMng(_instr_model_mng)
{}

void ETRACER::INSTR_WINDOW::tryPushWindow(COMP_INSTR* newOp) {
    if (!newOp)
        return ;
    tryPopWindow();
    /// update reg dependency
    INSTR_MODEL* instrModel = instrModelMng->getInstrModel(newOp->getInstrMdId());
    for (auto regNum : instrModel->getDesRegComp()){
        addReg(regNum, newOp->getSeqNum());
    }
    ////////////////////////////////////
    currentWindow.push_front((INSTR*) newOp);
    assert(currentWindow.size() <= MAX_WINDOWSIZE);
}

void ETRACER::INSTR_WINDOW::tryPushWindow(MEM_INSTR *newOp) {
    if (!newOp)
        return ;
    tryPopWindow();
    ////////////////////////////////////
    currentWindow.push_front((INSTR*) newOp);
    assert(currentWindow.size() <= MAX_WINDOWSIZE);
    /// update mem dependency
    /// todo we might use optimize mem dep finder
}

void ETRACER::INSTR_WINDOW::assignRegDepHelp(unordered_set<uint64_t> &result, REGNUM regNum) {
    if (regDep[regNum] > 0){
        result.insert(regResult[regNum]);
    }
}

void ETRACER::INSTR_WINDOW::assignMemDepHelp(unordered_set<uint64_t> &result, ADDR effAddr, int effSize, bool isLoad) {

    for (auto instrPtr : currentWindow){
        if ( (instrPtr->instr_type == LOAD) ||
             (instrPtr->instr_type == STORE))
        {
            auto memInstrPtr = (MEM_INSTR*) instrPtr;

            if (memInstrPtr->isEffective(effAddr, effSize, isLoad)){
                result.insert(instrPtr->getSeqNum());
            }
        }
    }
}

void ETRACER::INSTR_WINDOW::tryPopWindow() {
    /// ejct reg dep
    /// TODO for now only comp operand is used reg dep
    assert(currentWindow.size() <= MAX_WINDOWSIZE);
    if (currentWindow.size() == MAX_WINDOWSIZE){
        // pop size is crucial
        auto instrPtr = currentWindow.back();
        //////  eject reg dep in case comop operand
        if (instrPtr->instr_type == COMP) {
            INSTR_MODEL* instrModel = instrModelMng->getInstrModel(instrPtr->getInstrMdId());
            for (auto regNum: instrModel->getDesRegComp()) {
                rmReg(regNum);
            }
        }
        ///////////////////
        ////////// delete it
        delete instrPtr; /////// destructor is assumed to virtual function
        currentWindow.pop_back();
    }
}