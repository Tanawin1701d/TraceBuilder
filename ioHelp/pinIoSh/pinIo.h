//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_PINIO_H
#define TRACEBUILDER_PINIO_H

#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

const uint32_t maxMemOpPerLS = 2;

#pragma pack(push, 1)
struct RT_OBJ{
    uint64_t loadAddr[maxMemOpPerLS];
    uint64_t storeAddr[maxMemOpPerLS];
    uint32_t fetchId;
    uint8_t  loadMemOpNum[maxMemOpPerLS];
    uint8_t  storeMemOpNum[maxMemOpPerLS];
};
#pragma pack(pop)

std::string to_string(const RT_OBJ& obj, vector<string>& fetchStr);

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