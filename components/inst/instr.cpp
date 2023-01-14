//
// Created by tanawin on 28/12/2565.
//
#include "instr.h"

#include <utility>
#include"../../tracers/tracer.h"



////INSTR
INSTR::INSTR(ETRACER* _reader, uint64_t _instrMdId, bool needGenSeqN = true):
seqNum(needGenSeqN ? _reader->genSeqN() : 0),
instrMdId(_instrMdId)
{}

uint64_t
INSTR::getSeqNum() const {
    return seqNum;
}

uint64_t
INSTR::getInstrMdId() const{
    return instrMdId;
}



////MEM

MEM_INSTR::MEM_INSTR(ETRACER *_reader,
                     const RT_OBJ& tracedData,
                     const int lsIdx, /// index to point to operand in mem instr
                     bool robModeDepIsLoad,
                     uint64_t _instrMdId
) : INSTR(_reader, _instrMdId) {
    ///////// split raw data to vector
    ///////////////////////////////////////////////////////
    /// initialize variable and get instruction model
    memop = robModeDepIsLoad ? tracedData.loadMemOpNum [lsIdx]
                             : tracedData.storeMemOpNum[lsIdx];
    INSTR_MODEL* instrModel = _reader->instrModelMng->getInstrModel(_instrMdId);
    auto srcRegAndEffSize = instrModel->getSrcRegLS(robModeDepIsLoad, memop);
    virAddr = robModeDepIsLoad ? tracedData.loadAddr[lsIdx]
                               : tracedData.storeAddr[lsIdx];
    addrSize = srcRegAndEffSize.second;
    vector<ADAS> tempPhyAddrResults;
    _reader->memMng->v2pConvert(virAddr, addrSize, tempPhyAddrResults);
    assert(!tempPhyAddrResults.empty());
        //// TODO for now we assume that only addresss alignment is match only one cache block and page too
    phyAddr = tempPhyAddrResults[0].addr;
    /////////////////////////////////////////////////////////
    /// deal with rob dependency
    _reader->instrWindow.assignMemDepHelp(robDependency, phyAddr, addrSize, false); // for now load after load gem5 trace cpu will deal with it automatically
    /// deta with reg dependency
    for (auto srcRegNum: srcRegAndEffSize.first)
        _reader->instrWindow.assignRegDepHelp(regDependency, srcRegNum);
    /////////////////////////////////////////////////////////

}


bool
MEM_INSTR::isOverLapAddr(ADDR _newAddr, int _newSize) const {
    assert( (_newAddr + (uintptr_t)_newSize) > _newAddr); /// to Prevent overflow and size is 0
    ADDR _effLastAddr = phyAddr + (uintptr_t)addrSize;
    ADDR _newLastAddr = _newAddr + (uintptr_t)_newSize;

    return ((_newAddr >= phyAddr ) && (_newAddr < _effLastAddr)) ||
           ((phyAddr  >= _newAddr) && (phyAddr  < _newLastAddr));

}


////LOAD
bool
LOAD_INSTR::isEffective(ADDR _newAddr, int _newSize, int _newIsLoS) {
    //if (_newIsLoS) return false; // load after load prevention
    return isOverLapAddr(_newAddr, _newSize);

}

LOAD_INSTR::LOAD_INSTR(      ETRACER* _reader,
                       const RT_OBJ&  _tracedData,
                             int      _lsIdx, /// index to point to operand in mem instr
                             uint64_t _instrMdId)
    :MEM_INSTR(_reader,
               _tracedData,
               _lsIdx,
               true,
               _instrMdId){

    instr_type = INSTR_TYPE::LOAD;

}


////STORE
bool
STORE_INSTR::isEffective(ADDR _newAddr, int _newSize, int _newIsLoS) {
    return isOverLapAddr(_newAddr, _newSize);
}

STORE_INSTR::STORE_INSTR(      ETRACER* _reader,
                               const RT_OBJ&  _tracedData,
                               int      _lsIdx, /// index to point to operand in mem instr
                               uint64_t _instrMdId):
MEM_INSTR(_reader,
          _tracedData,
          _lsIdx,
          false,
          _instrMdId){
    if (_reader->newCInstr) {
        robDependency.insert(_reader->newCInstr->getSeqNum());
    }else{
        // cout << "[warning] seq: " << seqNum << " has no compute instruction\n";
    }
    instr_type = INSTR_TYPE::STORE;

}




////COMP

COMP_INSTR::COMP_INSTR(ETRACER *_reader, uint64_t _instrMdId) :
INSTR(_reader,
      _instrMdId,
      true) {

    INSTR_MODEL* instrModel = _reader->instrModelMng->getInstrModel(_instrMdId);
    auto srcRegs= instrModel->getSrcRegComp();

    ///////// deal with register dependency from instruction window
    for (auto srcReg : srcRegs){
        _reader->instrWindow.assignRegDepHelp(regDependency, srcReg);
    }

    ////// deal with reg dependency from self load operand for example = add rbx [rcx + 0xff]
    for (auto  ldInstr: _reader->newLdInstr){
        regDependency.insert(ldInstr->getSeqNum());
    }

    instr_type = INSTR_TYPE::COMP;
}



/////FETCH

FETCH_INSTR::FETCH_INSTR(ETRACER* _reader, const RT_OBJ& traced):
INSTR(_reader, -1, false)
{
    instrMdId = traced.fetchId;
    INSTR_MODEL* instrModel = _reader->instrModelMng->getInstrModel(instrMdId);

    virAddr = instrModel->getInstrAddr();
    virSize = instrModel->getInstrSize();
    /////////// get physical address and its alignment
    _reader->memMng->v2pConvert(virAddr, virSize, addrASizes);
    executeTick  = _reader->stepInstrExeTick(compDelay); // get current tick before next tick

    if (addrASizes.size() > 1) {
        uint64_t &maxfetCount = getstatPoolCount("max_fetchSplit");
        maxfetCount = max(maxfetCount, addrASizes.size());
        getstatPoolCount("count_fetchSplit")++;
    }
    instr_type = FETCH;
    //// we do not deal with dependency about fetch instruction right now due to read-only manner
}



//////// protobuffer generator

void LOAD_INSTR::genProtoMsg(ProtoOutputStream* strm) {
    ProtoMessage::InstDepRecord dep_pkt;
    dep_pkt.set_seq_num(seqNum);
    dep_pkt.set_type(ProtoMessage::InstDepRecord::RecordType::InstDepRecord_RecordType_LOAD);
    dep_pkt.set_pc(0);
    dep_pkt.set_comp_delay(500);
    for (auto robDepSeqN: robDependency){
        dep_pkt.add_rob_dep(robDepSeqN);
    }
    for (auto regDepSeqN: regDependency){
        dep_pkt.add_reg_dep(regDepSeqN);
    }
    dep_pkt.set_flags (0);
    dep_pkt.set_p_addr(phyAddr);
    dep_pkt.set_size(addrSize);
    dep_pkt.set_v_addr(virAddr);

    getstatPoolCount("count_robDepFromLoadInstr")+=robDependency.size();
    getstatPoolCount("count_regDepFromLoadInstr")+=regDependency.size();

}

void STORE_INSTR::genProtoMsg(ProtoOutputStream* strm) {
    ProtoMessage::InstDepRecord dep_pkt;
    dep_pkt.set_seq_num(seqNum);
    dep_pkt.set_type(ProtoMessage::InstDepRecord::RecordType::InstDepRecord_RecordType_STORE);
    dep_pkt.set_pc(0);
    dep_pkt.set_comp_delay(500);
    for (auto robDepSeqN: robDependency){
        dep_pkt.add_rob_dep(robDepSeqN);
    }
    for (auto regDepSeqN: regDependency){
        dep_pkt.add_reg_dep(regDepSeqN);
    }
    dep_pkt.set_flags (0);
    dep_pkt.set_p_addr(phyAddr);
    dep_pkt.set_size(addrSize);
    dep_pkt.set_v_addr(virAddr);
    strm->write(dep_pkt);

    getstatPoolCount("count_robDepFromStoreInstr")+=robDependency.size();
    getstatPoolCount("count_regDepFromStoreInstr")+=regDependency.size();
}

void COMP_INSTR::genProtoMsg(ProtoOutputStream* strm) {
    ProtoMessage::InstDepRecord dep_pkt;
    dep_pkt.set_seq_num(seqNum);
    dep_pkt.set_type(ProtoMessage::InstDepRecord_RecordType_COMP);
    dep_pkt.set_pc(0);
    dep_pkt.set_comp_delay(500);
    for (auto robDepSeqN: robDependency){
        dep_pkt.add_rob_dep(robDepSeqN);
    }
    for (auto regDepSeqN: regDependency){
        dep_pkt.add_reg_dep(regDepSeqN);
    }
    strm->write(dep_pkt);

    getstatPoolCount("count_robDepFromCompInstr")+=robDependency.size();
    getstatPoolCount("count_regDepFromCompInstr")+=regDependency.size();
}

void FETCH_INSTR::genProtoMsg(ProtoOutputStream* strm) {
    ProtoMessage::Packet inst_fetch_pkt;
    inst_fetch_pkt.set_tick(executeTick);
    inst_fetch_pkt.set_cmd(1); /// 1 means read.
    inst_fetch_pkt.set_pc(0);
    inst_fetch_pkt.set_flags(0);
    inst_fetch_pkt.set_addr(addrASizes[0].addr);
    inst_fetch_pkt.set_size(addrASizes[0].size);
    strm->write(inst_fetch_pkt);
    getstatPoolCount("count_fetchInstr")++;

}