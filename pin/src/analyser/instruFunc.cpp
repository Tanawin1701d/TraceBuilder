#include "instruFunc.h"

RT_OBJ preWriteObj;
int cur_fetchId = 0;


VOID L_TRACE(ADDRINT addr, UINT32 lsFieldId){
    preWriteObj.loadAddr[lsFieldId] = addr;
    preWriteObj.amt_load++;
}

VOID S_TRACE(ADDRINT addr, UINT32 lsFieldId){
    preWriteObj.storeAddr[lsFieldId] = addr;     // update address;
    preWriteObj.amt_store++;
}

VOID ButtomEachIntr(UINT32 fetchId){
    writeDynamicTraceFile(preWriteObj);
}

int getAndIncFetchId(){
    cur_fetchId++;
    return cur_fetchId-1;
}