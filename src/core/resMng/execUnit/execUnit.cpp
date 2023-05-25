//
// Created by tanawin on 25/5/2566.
//


#include"execUnit.h"

EXEC_UNIT_RES::EXEC_UNIT_RES(EXEC_UNIT_ID fromId, EXEC_UNIT_ID toId)
: excludeIdFrom(fromId),
  excludeIdTo(toId)
{
    std::fill(maxAvailable, maxAvailable + MAX_UNIT_ID, 0);

}

int EXEC_UNIT_RES::getMaxAvailable(EXEC_UNIT_ID resId) {
    return (resId <= excludeIdFrom && resId >= excludeIdTo)
    ? INT32_MAX : maxAvailable[resId];
}

void EXEC_UNIT_RES::setMaxAvailable(EXEC_UNIT_ID id, int size){
    assert(id < MAX_UNIT_ID);
    maxAvailable[id] = size;
}