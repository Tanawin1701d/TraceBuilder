#include "instruFunc.h"

/** first time that this object is built the function is initialized to default value*/
RT_OBJ preWriteObj;
inline void cleanPrewriteObj();

/** these following functions is used to injected to main program*/


VOID L_TRACE(ADDRINT addr, UINT32 lsFieldId){
    preWriteObj.loadAddr[lsFieldId] = addr;
    preWriteObj.amt_load++;
}

VOID S_TRACE(ADDRINT addr, UINT32 lsFieldId){
    preWriteObj.storeAddr[lsFieldId] = addr;     // update address;
    preWriteObj.amt_store++;
}

VOID ButtomEachIntr(UINT32 fetchId){
    preWriteObj.fetchId = fetchId;
    writeDynamicTraceFile(preWriteObj);
    cleanPrewriteObj();
}
/** for clear preWriteObj*/

inline void cleanPrewriteObj(){
    preWriteObj = RT_OBJ();
}