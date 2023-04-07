//
// Created by tanawin on 25/3/2566.
//

#ifndef TRACEBUILDER_SIMPLEPINGEM_H
#define TRACEBUILDER_SIMPLEPINGEM_H

#include<iostream>

class SIMPLE_PIN_GEM{
    std::string inputPinFile_instr;
    std::string inputPinFile_data;
    std::string outProtoFile_instr;
    std::string outProtoFile_data;

public:
    SIMPLE_PIN_GEM(const std::string _inputPinFile_instr,
                   const std::string _inputPinFile_data,
                   const std::string _outProtoFile_instr,
                   const std::string _outProtoFile_data
                   );


   void start();



};

#endif //TRACEBUILDER_SIMPLEPINGEM_H
