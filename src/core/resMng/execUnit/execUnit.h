//
// Created by tanawin on 16/5/2566.
//

#ifndef TRACEBUILDER_EXECUNIT_H
#define TRACEBUILDER_EXECUNIT_H
#include <cstdint>
#include <cassert>
#include <algorithm>
typedef int EXEC_UNIT_ID;

static const int DUMMY_EXEC_UNIT_ID = 99;
static const int MAX_UNIT_ID = 100;

class EXEC_UNIT_RES{
private:
    int maxAvailable[MAX_UNIT_ID];
    int cycleUsed   [MAX_UNIT_ID];
    EXEC_UNIT_ID excludeIdFrom;
    EXEC_UNIT_ID excludeIdTo;

public:
    EXEC_UNIT_RES(EXEC_UNIT_ID fromId, EXEC_UNIT_ID toId);
    int  getMaxAvailable(EXEC_UNIT_ID resId);
    void setMaxAvailable(EXEC_UNIT_ID id, int size);
    int  getLatencyCycle(EXEC_UNIT_ID id);
    void setLatencyCycle(EXEC_UNIT_ID id, int cycleSize);
};

#endif //TRACEBUILDER_EXECUNIT_H
