#include "writer/writer.h"


/** static file which contain static instruction with meta data with these format*/
/*
*   R S regname
*   L S baseReg indexReg size memOperandNum
*   I S immVal
*   R S regname
*   S D baseReg indexReg size memOperandNum
*   N mnemonic$RLIR$S
*   F S id virtualaddress size  name
*/

const size_t             staticWriteLim = 1 << 20; 
std::string           staticWriteBuffer;
std::ofstream* staticFileStream;

inline void flushStaticTraceFile() {
    *staticFileStream << staticWriteBuffer;
    staticWriteBuffer.clear();
}


void writeStaticTraceFile(std::string& rawDayta, bool forceFlush){
    staticWriteBuffer += rawDayta;
    if (staticWriteBuffer.size() >= staticWriteLim || forceFlush){
        flushStaticTraceFile();
    }

}

void initStaticTraceFile(std::string filePath){
    staticFileStream   = new std::ofstream(filePath);
    assert(staticFileStream != nullptr);
}

void finzStaticTraceFile(){
    flushStaticTraceFile();
    staticFileStream->close();
}

/** dynamic file which contain effective memory address and fetch id */

const   size_t dynWriteLim = 40000000;
RT_OBJ*        dynWriteBuffer; /// 400 M times 52 bytes
        size_t dynCurBuffSize;
std::ofstream* dynFileStream;

inline void flushDynTraceFile(){
    if (!dynCurBuffSize){
        return;
    }
    dynFileStream->write((char*)dynWriteBuffer, sizeof(RT_OBJ)*dynCurBuffSize);
    dynCurBuffSize = 0;
}

void writeDynamicTraceFile(RT_OBJ& rt_obj){
        dynWriteBuffer[dynCurBuffSize++] = std::move(rt_obj);
        if (dynCurBuffSize >= dynWriteLim){
            flushDynTraceFile();
        }
}
void initDynamicTraceFile(std::string filePath){
    assert(dynWriteLim > 0);
    dynCurBuffSize = 0;
    dynWriteBuffer = new RT_OBJ[dynWriteLim];
    dynFileStream = new std::ofstream(filePath);
}
void finzDynamicTraceFile(){
    flushDynTraceFile();
    dynFileStream->close();

}