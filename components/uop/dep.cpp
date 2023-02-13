//
// Created by tanawin on 12/2/2566.
//

#include "dep.h"

bool DEP_BASE::addDep(UOP_BASE* uop) {

    auto find_iterator = predecessors.find(uop);
    bool isNew = find_iterator != predecessors.end();
    if(isNew)
        predecessors.insert(uop);
    return isNew;
}

////// register dependency

void REG_DEP::addRegDep(UOP_BASE *uop) {
    predecessors.insert(uop);
}

std::unordered_set<UOP_BASE*>&
REG_DEP::getRegDep() {
    return predecessors;
}



////// memory addresss dependency

void MEM_DEP::addMemDep(UOP_BASE *uop) {
    predecessors.insert(uop);
}

std::unordered_set<UOP_BASE*>&
MEM_DEP::getMemDep() {
    return predecessors;
}

////// execution dep

void EXE_DEP::addExeDep(UOP_BASE *uop) {
    predecessors.insert(uop);
}

std::unordered_set<UOP_BASE*>&
EXE_DEP::getExeDep() {
    return predecessors;
}

////// temporary register dependency

void TEM_DEP::addTemDep(UOP_BASE *uop) {
    predecessors.insert(uop);
}

std::unordered_set<UOP_BASE*>&
TEM_DEP::getTemDep() {
    return predecessors;
}
