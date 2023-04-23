#include"X86_dec.h"
#include"models/inst_model/rt_instr.h"




X86_DECODER::X86_DECODER(): DECODER_BASE(){



     decodeStorage.insert({"ADC$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"ADD$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"AND$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"OR$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"ROL$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"ROR$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"SAL$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"SAR$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"SBB$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"SHL$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"SHLD$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"SHR$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"SHRD$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"SUB$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"XCHG$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"XOR$M_I$M", (MOP_BASE*)(new MOP_COMP$M_I$M())});
     decodeStorage.insert({"ADC$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"ADD$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"AND$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"OR$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"ROL$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"ROR$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"SAL$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"SAR$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"SBB$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"SHL$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"SHLD$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"SHR$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"SHRD$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"SUB$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"XCHG$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"XOR$M_M$M", (MOP_BASE*)(new MOP_COMP$M_M$M())});
     decodeStorage.insert({"ADC$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"ADD$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"AND$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"OR$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"ROL$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"ROR$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"SAL$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"SAR$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"SBB$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"SHL$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"SHLD$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"SHR$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"SHRD$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"SUB$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"XCHG$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"XOR$R_I$M", (MOP_BASE*)(new MOP_COMP$R_I$M())});
     decodeStorage.insert({"ADC$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"ADD$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"AND$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"OR$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"ROL$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"ROR$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"SAL$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"SAR$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"SBB$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"SHL$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"SHLD$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"SHR$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"SHRD$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"SUB$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"XCHG$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"XOR$R_M$M", (MOP_BASE*)(new MOP_COMP$R_M$M())});
     decodeStorage.insert({"ADC$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"ADD$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"AND$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"OR$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"ROL$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"ROR$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"SAL$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"SAR$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"SBB$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"SHL$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"SHLD$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"SHR$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"SHRD$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"SUB$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"XCHG$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"XOR$R_R$M", (MOP_BASE*)(new MOP_COMP$R_R$M())});
     decodeStorage.insert({"ADC$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"ADD$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"AND$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"OR$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"ROL$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"ROR$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"SAL$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"SAR$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"SBB$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"SHL$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"SHLD$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"SHR$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"SHRD$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"SUB$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"XCHG$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"XOR$M_I$R", (MOP_BASE*)(new MOP_COMP$M_I$R())});
     decodeStorage.insert({"ADC$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"ADD$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"AND$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"OR$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"ROL$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"ROR$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"SAL$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"SAR$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"SBB$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"SHL$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"SHLD$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"SHR$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"SHRD$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"SUB$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"XCHG$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"XOR$M_M$R", (MOP_BASE*)(new MOP_COMP$M_M$R())});
     decodeStorage.insert({"ADC$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"ADD$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"AND$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"OR$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"ROL$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"ROR$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"SAL$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"SAR$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"SBB$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"SHL$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"SHLD$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"SHR$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"SHRD$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"SUB$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"XCHG$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"XOR$R_I$R", (MOP_BASE*)(new MOP_COMP$R_I$R())});
     decodeStorage.insert({"ADC$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"ADD$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"AND$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"OR$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"ROL$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"ROR$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"SAL$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"SAR$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"SBB$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"SHL$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"SHLD$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"SHR$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"SHRD$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"SUB$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"XCHG$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"XOR$R_M$R", (MOP_BASE*)(new MOP_COMP$R_M$R())});
     decodeStorage.insert({"ADC$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"ADD$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"AND$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"OR$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"ROL$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"ROR$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"SAL$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"SAR$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"SBB$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"SHL$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"SHLD$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"SHR$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"SHRD$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"SUB$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"XCHG$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
     decodeStorage.insert({"XOR$R_R$R", (MOP_BASE*)(new MOP_COMP$R_R$R())});
}




MOP_BASE*
X86_DECODER::decodeMOP(RT_INSTR& rt_instr) {

auto finder = decodeStorage.find(rt_instr.getDecodeKey());
return ( finder == decodeStorage.end() ) ? simpleMop: finder->second;

}