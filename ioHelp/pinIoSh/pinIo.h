//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_PINIO_H
#define TRACEBUILDER_PINIO_H

#include<iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)
struct RT_OBJ{
    uint64_t loadAddr[3];
    uint64_t storeAddr[3];
    uint32_t fetchId;
    uint8_t  loadMemOpNum[3];
    uint8_t  storeMemOpNum[3];
};
#pragma pack(pop)


class PIN_IO{

private:
    string fileName;

    ifstream* inputFile;
public:
    explicit PIN_IO(const string& _fileName);
    ~ PIN_IO();
    /// return true is it can get the new instruction
    /// false if it is end of file
    bool readInstr(RT_OBJ& result);

};

#endif //TRACEBUILDER_PINIO_H