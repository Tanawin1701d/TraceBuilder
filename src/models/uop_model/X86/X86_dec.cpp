#include"X86_dec.h"
#include"models/inst_model/rt_instr.h"
namespace traceBuilder::model {







X86_DECODER::X86_DECODER(): DECODER_BASE(){



     decodeStorage.insert({"mydecKey$M_R$R", (MOP_BASE*)(new MPREFIX$M_R$R())});
}




MOP_BASE*
X86_DECODER::decodeMOP(RT_INSTR& rt_instr) {

auto finder = decodeStorage.find(rt_instr.getDecodeKey());
return ( finder == decodeStorage.end() ) ? simpleMop: finder->second;

}
}
