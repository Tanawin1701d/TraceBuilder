#ifndef X86_DEC_H
#define X86_DEC_H
#include"../mop/x86_mop.h"
#include"../../../mop_base.h"
#include"../../../decoder.h"







class DECODER_X86 : public DECODER_BASE{
private:
       unordered_map<std::string, MOP_BASE*> decodeStorage;
public:
                 DECODER_X86();
       MOP_BASE* decodeMOP(RT_INSTR& rt_instr) override;
};

#endif
