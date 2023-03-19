#include"x86_dec.h"
#include"../../../../inst_model/rt_instr.h"
DECODER_X86::DECODER_X86(): DECODER_BASE(){
     decodeStorage.insert({"add$RL$R", (MOP_BASE*)(new MOP_ADD_R_M())});
     decodeStorage.insert({"minus$RL$R", (MOP_BASE*)(new MOP_ADD_R_M())});
}






MOP_BASE*
DECODER_X86::decodeMOP(RT_INSTR& rt_instr) {
auto finder = decodeStorage.find(rt_instr.getDecodeKey());
return ( finder == decodeStorage.end() ) ? simpleMop: finder->second;

}
