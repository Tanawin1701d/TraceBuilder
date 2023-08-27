#ifndef __ANALYSER_INSTRUFUNC_H__
#define __ANALYSER_INSTRUFUNC_H__

#include "pin.H"
#include "writer/writer.h"


VOID L_TRACE(ADDRINT addr, UINT32 lsFieldId);

VOID S_TRACE(ADDRINT addr, UINT32 lsFieldId);

VOID ButtomEachIntr(UINT32 fetchId);

int getAndIncFetchId();


#endif