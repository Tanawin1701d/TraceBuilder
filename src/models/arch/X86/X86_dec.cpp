MOP_BASE*
X86_DECODER::decodeMOP(RT_INSTR& rt_instr) {

auto finder = decodeStorage.find(rt_instr.getDecodeKey());
return ( finder == decodeStorage.end() ) ? simpleMop: finder->second;

}