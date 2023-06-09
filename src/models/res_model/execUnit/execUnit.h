//
// Created by tanawin on 16/5/2566.
//

#ifndef TRACEBUILDER_EXECUNIT_H
#define TRACEBUILDER_EXECUNIT_H

#include <pybind11/pybind11.h>
#include <cstdint>
#include <cassert>
#include <algorithm>

namespace traceBuilder::model {


    typedef int EXEC_UNIT_ID;

    static const int DUMMY_EXEC_UNIT_ID = 99;
    static const int MAX_UNIT_ID = 100;

    class EXEC_UNIT_RES {
    private:
        int maxAvailable[MAX_UNIT_ID];
        int cycleUsed[MAX_UNIT_ID];
        EXEC_UNIT_ID excludeIdFrom;
        EXEC_UNIT_ID excludeIdTo;

    public:
        EXEC_UNIT_RES(EXEC_UNIT_ID fromId, EXEC_UNIT_ID toId);

        int getMaxAvailable(EXEC_UNIT_ID resId);

        void setMaxAvailable(EXEC_UNIT_ID id, int size);

        int getLatencyCycle(EXEC_UNIT_ID id);

        void setLatencyCycle(EXEC_UNIT_ID id, int cycleSize);
    };

    ////////////////////////////////////////////////////////////////////////////////////////
    ///////// pybind declaration

    namespace py = pybind11;
    void BIND_EXEC_UNIT_RES(py::module& m);

}

#endif //TRACEBUILDER_EXECUNIT_H
