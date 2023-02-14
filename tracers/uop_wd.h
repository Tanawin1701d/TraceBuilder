//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_INSTRWD_H
#define TRACEBUILDER_INSTRWD_H

#endif //TRACEBUILDER_INSTRWD_H

#include<deque>
#include "../components/uop/uop_base.h"

class UOP_WINDOW{
private:
    std::deque<UOP_BASE*> uop_window;
    int window_size;
    bool isFull();
    void popFromQ();

public:
    UOP_WINDOW(int _window_size);
    void depAssign(UOP_BASE* newUop);
    void addUop(UOP_BASE* newUop);


};