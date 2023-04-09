//
// Created by tanawin on 7/1/2566.
//
/////// header file is in tracer.h
#include "uop_wd.h"


///// constructor
UOP_WINDOW::UOP_WINDOW(int _window_size){
    ///// minimum uop window is 10
    assert(_window_size >= 10);
    window_size = _window_size;
    //// this is used for record who is the latest modifier
    for (auto & lastOwner : lastOwnerReg){
        lastOwner = nullptr;
    }
}

void
UOP_WINDOW::tryPopFromQ(){
    if ( !uop_window.empty() ) {
        UOP_BASE* preDelete = uop_window.back();

        for (REGNUM desReg: preDelete->getdesReg()){
            //// we can ensure that no unused reg(-1) righthere
            if (preDelete == lastOwnerReg[desReg]){
                lastOwnerReg[desReg] = nullptr;
            }
        }


        delete preDelete;
        uop_window.pop_back();
    }
}

//// check is full?
bool
UOP_WINDOW::isFull() {
    return uop_window.size() >= window_size;
}

void
UOP_WINDOW::addUop(UOP_BASE* newUop){
    assert(newUop != nullptr);
    if (isFull())
        tryPopFromQ();
    ///// push and pop side from the queue is critical
    uop_window.push_front(newUop);

    for (REGNUM desReg: newUop->getdesReg()){
        //// we can ensure that no unused reg(-1) righthere
        lastOwnerReg[desReg] = newUop;
    }

}

UOP_BASE *UOP_WINDOW::regDependHelp(REGNUM regNum) {
    assert(regNum != unusedReg);
    return lastOwnerReg[regNum];
}

