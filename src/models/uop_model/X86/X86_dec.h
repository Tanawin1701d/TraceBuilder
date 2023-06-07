#ifndef X86_DECL_H
#define X86_DECL_H
#include"models/uop_model/decoder.h"
#include"X86_mop.h"




namespace traceBuilder::model {



class RT_INSTR;
class X86_DECODER : public DECODER_BASE{
private:
       std::unordered_map<std::string, MOP_BASE*> decodeStorage;
public:
       X86_DECODER();
       MOP_BASE* decodeMOP(RT_INSTR& rt_instr) override;
};
}

#endif