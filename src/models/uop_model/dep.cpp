//
// Created by tanawin on 12/2/2566.
//

#include "dep.h"
#include "core/tracers/uop_wd.h"

namespace traceBuilder::model {


    bool DEP_BASE::addDep(UOP_BASE *uop) {
        auto find_iterator = predecessors.find(uop);
        bool isNew = find_iterator == predecessors.end();
        if (isNew)
            predecessors.insert(uop);
        return isNew;
    }

////////////////////////////////////
////// register dependency
////////////////////////////////////

    bool REG_DEP::addRegDep(UOP_BASE *uop) {
        return addDep(uop);
    }

    std::unordered_set<UOP_BASE *> &
    REG_DEP::getRegDep() {
        return predecessors;
    }

    void
    REG_DEP::addRegMeta(const REGNUM regnum, bool isSrc) {
        if (regnum == unusedReg) { return; }
        std::vector<REGNUM> *targetVec = isSrc ? &srcReg : &desReg;
        targetVec->push_back(regnum);
    }

    std::vector<REGNUM> &REG_DEP::getdesReg() {
        return desReg;
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

    bool MEM_DEP::addMemDep(UOP_BASE *uop) {
        assert(uop != nullptr);
        return addDep(uop);
    }

    std::unordered_set<UOP_BASE *> &
    MEM_DEP::getMemDep() {
        return predecessors;
    }

    void MEM_DEP::addMemMeta(ADAS adas, bool isLoad) {
        std::vector<ADAS> *targetVec = isLoad ? &loadAdas : &storeAdas;
        targetVec->push_back(adas);
    }
////////////////////////////////////
////// temporary register dependency
////////////////////////////////////

    bool TEM_DEP::addTemDep(UOP_BASE *uop) {
        return addDep(uop);
    }

    std::unordered_set<UOP_BASE *> &
    TEM_DEP::getTemDep() {
        return predecessors;
    }

    void
    TEM_DEP::addTRegMeta(TREGNUM tregnum) {
        srcTRegs.push_back(tregnum);
    }

////////////////////////////////////
////// exec_unit dep
////////////////////////////////////

    bool
    EXEC_UNIT_DEP::addExecDep(UOP_BASE *uop) {
        assert(uop != nullptr);
        return addDep(uop);
    }

    std::unordered_set<UOP_BASE *> &
    EXEC_UNIT_DEP::getExecDep() {
        return predecessors;
    }

}