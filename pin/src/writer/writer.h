#ifndef __WRITER__WRITER_HH__
#define __WRITER__WRITER_HH__

#include <iostream>
#include <fstream>
#include "pin.H"


const int maxMemOpPerLS = 2;
#pragma pack(push, 1)
struct RT_OBJ{
    uint64_t loadAddr     [maxMemOpPerLS];
    uint64_t storeAddr    [maxMemOpPerLS];
    uint32_t fetchId;
    uint8_t  amt_load;
    uint8_t  amt_store;
};
#pragma pack(pop)

/** static file tracing*/
void writeStaticTraceFile(std::string& rawDayta, bool forceFlush);
void initStaticTraceFile(std::string filePath);
void finzStaticTraceFile();
/** dynamic tracing file*/
void writeDynamicTraceFile(RT_OBJ& rt_obj);
void initDynamicTraceFile(std::string filePath);
void finzDynamicTraceFile();



#endif //__WRITER__WRITER_HH__