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

}

void
UOP_WINDOW::tryPopFromQ(){
    if ( !uop_window.empty() ) {
        /////// who will be deleted
        UOP_BASE* preDelete = uop_window.back();
        assert(preDelete != nullptr);
        ////// notify dep helper on pop oldest uop to window
        for(auto& depHelpEle: depHelperPool){
            depHelpEle->onPopFromWd(preDelete, this);
        }
        /////// pop data from window
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
    ////// notify dep helper on adding new uop to window
    for(auto& depHelpEle : depHelperPool){
        depHelpEle->onPushToWd(newUop, this);
    }
    ///// push and pop side from the queue is critical
    uop_window.push_front(newUop);


}
