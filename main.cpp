#include <iostream>
#include "tracers/tracer.h"
#include "tracers/statPool.h"
#include "components/inst/instr_model.h"
int main() {

    auto instr_md_mng = INSTR_MODEL_MANAGER("/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/rawFile/testProtoInstr");
    ADDR memSize = ((ADDR)1) << (4 + 30); ///// 16 gigabyte
    auto mem_mng      = MEM_MNG(12, 6, memSize, 0);
            ///// 12 bit means 4 kb page size ///// 6 bit mean 64 byte cache line size
    auto tracer = ETRACER("/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/rawFile/testProtoData",
                          "/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/generatedFile/dynamicDataProto.txt",
                          "/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/generatedFile/instrBetaProto.txt",
                          64,
                          &instr_md_mng,
                          &mem_mng
            );
    tracer.step();
    printStat();
//    ProtoOutputStream* protoFile_data = new ProtoOutputStream("/tmp/fuckProto");
//    ProtoMessage::Packet inst_fetch_pkt;
//    inst_fetch_pkt.set_tick(0);
//    inst_fetch_pkt.set_cmd(1); /// 1 means read.
//    inst_fetch_pkt.set_pc(0);
//    inst_fetch_pkt.set_flags(0);
//    inst_fetch_pkt.set_addr(0);
//    inst_fetch_pkt.set_size(0);
//    protoFile_data->write(inst_fetch_pkt);
//    delete protoFile_data;
    return 0;
}