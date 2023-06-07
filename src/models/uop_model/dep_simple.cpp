//
// Created by tanawin on 7/6/2566.
//

#include "dep_simple.h"

namespace traceBuilder::model {

////////////////////////////////////
////// register dependency
////////////////////////////////////
    void
    REG_DEP::addRegMeta(const REGNUM regnum, bool isSrc) {
        if (regnum == unusedReg) { return; }
        std::vector<REGNUM> *targetVec = isSrc ? &srcReg : &desReg;
        targetVec->push_back(regnum);
    }

////////////////////////////////////
////// memory addresss dependency
////////////////////////////////////

    bool MEM_DEP::scanOverlap(ADAS adas, std::vector<ADAS> &adasVec) {
        for (auto &loadCheck: adasVec) {
            if (isADASoverlap(loadCheck, adas)) {
                return true;
            }
        }
        return false;
    }

    bool MEM_DEP::isdependOnMem(const ADAS adas, bool isLoad) {

        //// if statement is load after load excluding
        if ((!isLoad) && scanOverlap(adas, loadAdas))
            return true;

        return scanOverlap(adas, storeAdas);

    }

    void MEM_DEP::addMemMeta(ADAS adas, bool isLoad) {
        std::vector<ADAS> *targetVec = isLoad ? &loadAdas : &storeAdas;
        targetVec->push_back(adas);
    }
////////////////////////////////////
////// temporary register dependency
////////////////////////////////////
    void
    TEM_DEP::addTemDep(UOP_BASE* uop) {
        preAddedDep.push_back(uop);
    }

    void
    TEM_DEP::finalizeTemDep(UOP_WINDOW* trace_window){
        for (auto uop : preAddedDep){
            addDep(uop, trace_window);
        }
    }

    void
    TEM_DEP::addTRegMeta(TREGNUM tregnum) {
        srcTRegs.push_back(tregnum);
    }

////////////////////////////////////
////// exec_unit dep
////////////////////////////////////

}