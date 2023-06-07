//
// Created by tanawin on 7/1/2566.
//
/////// header file is in tracer.h
#include "uop_wd.h"

namespace traceBuilder::core {


///// constructor
    UOP_WINDOW::UOP_WINDOW(EXEC_UNIT_RES *exeUnit_pool):
            last_push_seq(-1)
    {
        ///// minimum uop window is 10
        assert(UOP_WINDOW_SIZE > 10);
        assert(exeUnit_pool != nullptr);
        ///// insert new dep help to depHelperPool
        depHelperPool.resize(DEP_HELP_IDX::HELP_SIZE);
        depHelperPool[DEP_HELP_IDX::HELP_REG] = new DEP_HELP_REG();
        depHelperPool[DEP_HELP_IDX::HELP_ISS_BAR] = new DEP_HELP_ISS_BARIER(exeUnit_pool);

    }

    void
    UOP_WINDOW::tryPopFromQ() {
        if (!uop_window.empty()) {
            /////// who will be deleted
            UOP_BASE *preDelete = uop_window.back();
            /////// update last push to queue
            if (preDelete->getSeqNum() == last_push_seq){
                last_push_seq = -1;
            }
            assert(preDelete != nullptr);
            ////// notify dep helper on pop oldest uop to window
            for (auto &depHelpEle: depHelperPool) {
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
        return uop_window.size() >= UOP_WINDOW_SIZE;
    }

    void
    UOP_WINDOW::addUop(UOP_BASE *newUop) {
        assert(newUop != nullptr);
        if (isFull())
            tryPopFromQ();
        /////// increase last added to queue
        ++last_push_seq;
        ///// check that sequence number is correctly assigned from tracer
        assert(last_push_seq == newUop->getSeqNum());
        ////// notify dep helper on adding new uop to window
        for (auto &depHelpEle: depHelperPool) {
            depHelpEle->onPushToWd(newUop, this);
        }
        ///// push and pop side from the queue is critical
        /////// update last push to queue
        last_push_seq = newUop->getSeqNum();
        uop_window.push_front(newUop);

    }


}