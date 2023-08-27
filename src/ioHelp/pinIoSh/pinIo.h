//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_PINIO_H
#define TRACEBUILDER_PINIO_H

// #include<iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>

//const uint32_t maxMemOpPerLS = 2;
//
//#pragma pack(push, 1)
//struct RT_OBJ{
//    uint64_t loadAddr[maxMemOpPerLS];
//    uint64_t storeAddr[maxMemOpPerLS];
//    uint32_t fetchId;
//    uint8_t  amt_load;
//    uint8_t  amt_store;
//};
//#pragma pack(pop)

// std::string to_string(const RT_OBJ& obj, std::vector<std::string>& fetchStr);

//class PIN_IO{
//
//private:
//    std::string fileName;
//
//    std::ifstream* inputFile;
//public:
//    explicit PIN_IO(const std::string& _fileName);
//    ~ PIN_IO();
//    /// return true is it can get the new instruction
//    /// false if it is end of file
//    bool readInstr(RT_OBJ& result);
//
//};

#endif //TRACEBUILDER_PINIO_H