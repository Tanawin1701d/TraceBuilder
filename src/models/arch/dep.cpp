//
// Created by tanawin on 12/2/2566.
//

#include "dep.h"
#include "core/tracers/uop_wd.h"

bool DEP_BASE::addDep(UOP_BASE* uop) {

    auto find_iterator = predecessors.find(uop);
    bool isNew = find_iterator != predecessors.end();
    if(isNew)
        predecessors.insert(uop);
    return isNew;
}

////// register dependency


bool REG_DEP::isdependOnReg(const REGNUM &sucReg){
    return std::find(desReg.begin(), desReg.end(),sucReg) != desReg.end();
}

void REG_DEP::doRegDepenCheck(UOP_WINDOW *traceWindow){
    assert(traceWindow != nullptr);
    auto uopWindow_ptr = traceWindow->getUopwindow();
    ////// TODO we might upgrade for clever method to achieve better performance
    for (auto& uopWindow_itr : *uopWindow_ptr){
        for (auto mySrcReg: srcReg){
            if (uopWindow_itr->isdependOnReg(mySrcReg)){
                addRegDep(uopWindow_itr);
            }
        }
    }


}

void REG_DEP::addRegMeta(const REGNUM regnum, bool isSrc) {
    std::vector<REGNUM>* targetVec = isSrc ? &srcReg : &desReg;
    targetVec->push_back(regnum);
}


bool REG_DEP::addRegDep(UOP_BASE *uop) {
    return addDep(uop);
}

std::unordered_set<UOP_BASE*>&
REG_DEP::getRegDep() {
    return predecessors;
}


////// memory addresss dependency

bool MEM_DEP::scanOverlap(const ADAS adas, std::vector<ADAS>& adasVec){
    for(auto& loadCheck: adasVec){
        if (isADASoverlap(loadCheck, adas)){
            return true;
        }
    }
    return false;
}

bool MEM_DEP::isdependOnMem(const ADAS adas, bool isLoad)  {

    //// if statement is load after load excluding
    if ( (!isLoad) && scanOverlap(adas, loadAdas) )
        return true;

    return scanOverlap(adas,storeAdas);

}

void MEM_DEP::doMemDepenCheck(UOP_WINDOW *traceWindow) {
    assert(traceWindow != nullptr);
    auto uopWindow_ptr = traceWindow->getUopwindow();
    ////// TODO we might upgrade for clever method to achieve better performance
    for (auto & uopWindow_itr : *uopWindow_ptr){
        for (auto& ldAdas : loadAdas){
            if (uopWindow_itr->isdependOnMem(ldAdas, true))
                addMemDep(uopWindow_itr);
        }
        for (auto& stAdas : storeAdas){
            if (uopWindow_itr->isdependOnMem(stAdas, false))
                addMemDep(uopWindow_itr);
        }
    }
}

void MEM_DEP::addMemMeta(ADAS adas, bool isLoad) {
    std::vector<ADAS>* targetVec = isLoad ? &loadAdas : &storeAdas;
    targetVec->push_back(adas);
}

bool MEM_DEP::addMemDep(UOP_BASE *uop) {
    assert(uop != nullptr);
    return addDep(uop);
}

std::unordered_set<UOP_BASE*>&
MEM_DEP::getMemDep() {
    return predecessors;
}

////// execution dep

bool EXE_DEP::addExeDep(UOP_BASE *uop) {
    assert(uop != nullptr);
    return addDep(uop);
}

std::unordered_set<UOP_BASE*>&
EXE_DEP::getExeDep() {
    return predecessors;
}

////// temporary register dependency


bool TEM_DEP::addTemDep(UOP_BASE *uop) {
    return addDep(uop);
}



bool
TEM_DEP::isdepenOnTEM(const TREGNUM sucTreg) {
    return std::find(desTRegs.begin(), desTRegs.end(), sucTreg)
            != desTRegs.end();
}

void
TEM_DEP::doTEMDepenCheck(std::vector<UOP_BASE *>& predecessor) {
    for (auto uop_ptr: predecessor){
        for (auto src_treg: srcTRegs) {
            if (uop_ptr->isdepenOnTEM(src_treg)){
                addTemDep(uop_ptr);
            }
        }
    }
}

void
TEM_DEP::addTRegMeta(const TREGNUM tregnum, bool isSrc){
   auto& pushVec = isSrc ? srcTRegs : desTRegs;
   pushVec.push_back(tregnum);
}

std::unordered_set<UOP_BASE*>&
TEM_DEP::getTemDep() {
    return predecessors;
}
