//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_INSTRWD_H
#define TRACEBUILDER_INSTRWD_H

#endif //TRACEBUILDER_INSTRWD_H

#include<deque>
#include "../../models/arch/uop_base.h"

class UOP_WINDOW{
private:
    std::deque<UOP_BASE*> uop_window;
    int window_size;
    bool isFull();
    void tryPopFromQ();

public:
    UOP_WINDOW(int _window_size);
    void depAssign(UOP_BASE* newUop);
    void addUop(UOP_BASE* newUop);
    std::deque<UOP_BASE*>* getUopwindow() { return &uop_window;}

};