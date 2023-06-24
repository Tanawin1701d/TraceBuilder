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
        if (regnum == UNUSEDREG) { return; }
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
        if ((!isLoad) && scanOverlap(adas, _phyLoadAdas))
            return true;

        return scanOverlap(adas, _phyStoreAdas);

    }

    void MEM_DEP::addMemMeta_phyArea(ADAS phyAdas, bool isLoad) {
        std::vector<ADAS>* targetVec = isLoad ? &_phyLoadAdas : &_phyStoreAdas;
        targetVec->push_back(phyAdas);
    }

    void MEM_DEP::addMemMeta_virArea(traceBuilder::model::ADAS virAdas, bool isLoad){
        std::vector<ADAS>* targetVec = isLoad ? &_virLoadAdas : &_virStoreAdas;
        targetVec->push_back(virAdas);
    }

    void MEM_DEP::addMemMeta_Static(traceBuilder::model::MEM_OPR_META meta) {
        _meta = meta;
    }
////////////////////////////////////
////// temporary register dependency
////////////////////////////////////
    void
    TEM_DEP::addTemDep(UOP_BASE* uop) {
        DEP_ULS_BASE::addDep(uop, nullptr);
    }

    void
    TEM_DEP::addTRegMeta(TREGNUM tregnum, bool isSrc) {
        std::vector<TREGNUM>& targetVec = isSrc ? srcTRegs : desTReg;
        targetVec.push_back(tregnum);
    }

////////////////////////////////////
////// exec_unit dep
////////////////////////////////////

}