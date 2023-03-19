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
}

void
UOP_WINDOW::tryPopFromQ(){
    if ( !uop_window.empty() ) {
        UOP_BASE *preDelete = uop_window.back();
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
UOP_WINDOW::depAssign(UOP_BASE* newUop) {

    assert(newUop != nullptr);
    newUop->doDepenCheck(this);
}

void
UOP_WINDOW::addUop(UOP_BASE* newUop){
    assert(newUop != nullptr);
    if (isFull())
        uop_window.pop_back();
    ///// push and pop side from the queue is critical
    uop_window.push_front(newUop);
}