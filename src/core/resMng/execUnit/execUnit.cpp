//
// Created by tanawin on 25/5/2566.
//


#include"execUnit.h"

EXEC_UNIT_RES::EXEC_UNIT_RES(EXEC_UNIT_ID fromId, EXEC_UNIT_ID toId)
: excludeIdFrom(fromId),
  excludeIdTo(toId)
{
    std::fill(maxAvailable, maxAvailable + MAX_UNIT_ID, 0);
    std::fill(cycleUsed, cycleUsed + MAX_UNIT_ID, 1);

}

int EXEC_UNIT_RES::getMaxAvailable(EXEC_UNIT_ID resId) {
    return (resId <= excludeIdFrom && resId >= excludeIdTo)
    ? INT32_MAX : maxAvailable[resId];
}

void EXEC_UNIT_RES::setMaxAvailable(EXEC_UNIT_ID id, int size){
    assert(id < MAX_UNIT_ID);
    maxAvailable[id] = size;
}

int EXEC_UNIT_RES::getLatencyCycle(EXEC_UNIT_ID id) {
    assert(id < MAX_UNIT_ID);
    return cycleUsed[id];
}

void EXEC_UNIT_RES::setLatencyCycle(EXEC_UNIT_ID id, int cycleSize) {
    assert(id < MAX_UNIT_ID && cycleSize > 0);
    cycleUsed[id] = cycleSize;
}