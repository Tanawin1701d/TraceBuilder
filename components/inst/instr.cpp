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

string INSTR::genAscLine() {
    return "undectectable instruction invokes this class";
}

////MEM


MEM_INSTR::MEM_INSTR(ETRACER *_reader,
                     string rawData,
                     bool robModeDepIsLoad,
                     uint64_t _instrMdId
) : INSTR(_reader, _instrMdId) {
    ///////// split raw data to vector
    vector<string> splitedInstr;
    splitNstrip(std::move(rawData), splitedInstr);
    //////// assert check that receive instr is corect
    assert((  robModeDepIsLoad  && (splitedInstr [LS_Idx] == "L")) ||
           ((!robModeDepIsLoad) && (splitedInstr [LS_Idx] == "S")) );
    assert(!splitedInstr[addr_Idx ].empty());
    assert(!splitedInstr[memop_Idx].empty());
    ///////////////////////////////////////////////////////
    /// initialize variable and get instruction model
    memop = decStr2int(splitedInstr[memop_Idx]);
    INSTR_MODEL* instrModel = _reader->instrModelMng->getInstrModel(_instrMdId);
    auto srcRegAndEffSize = instrModel->getSrcRegLS(robModeDepIsLoad, memop);
    effAddr = ETRACER::memMapper(hexStr2uint(splitedInstr[addr_Idx]));
    effAddrSize = srcRegAndEffSize.second;
    /////////////////////////////////////////////////////////
    /// deal with rob dependency
    _reader->instrWindow.assignMemDepHelp(robDependency, effAddr, effAddrSize, false);
    /// dela with reg dependency
    for (auto srcRegNum: srcRegAndEffSize.first)
        _reader->instrWindow.assignRegDepHelp(regDependency, srcRegNum);
    /////////////////////////////////////////////////////////

}


bool
MEM_INSTR::isOverLapAddr(ADDR _newAddr, int _newSize) const {
    assert( (_newAddr + (uintptr_t)_newSize) > _newAddr); /// to Prevent overflow and size is 0
    ADDR _effLastAddr = effAddr + (uintptr_t)effAddrSize;
    ADDR _newLastAddr = _newAddr + (uintptr_t)_newSize;

    return ( ( _newAddr    >= effAddr ) && ( _newAddr <  _effLastAddr)) ||
           ( ( effAddr     >= _newAddr ) && ( effAddr <  _newLastAddr));

}

////LOAD
bool
LOAD_INSTR::isEffective(ADDR _newAddr, int _newSize, int _newIsLoS) {
    //if (_newIsLoS) return false; // load after load prevention
    return isOverLapAddr(_newAddr, _newSize);

}

LOAD_INSTR::LOAD_INSTR(ETRACER *_reader, string rawData, uint64_t _instrMdId)
    :MEM_INSTR(_reader,
               std::move(rawData),
               true,
               _instrMdId){

    instr_type = INSTR_TYPE::LOAD;

}

string LOAD_INSTR::genAscLine() {
    /////# seq_num,[pc],[weight,]type,[p_addr,size,flags,]comp_delay:[rob_dep]:[reg_dep]
    string instrstr = to_string(seqNum) + ",0,1,LOAD," +
                      to_string(effAddr) + "," + to_string(effAddrSize) +
                      ",0,500:";

    for (auto robDepSeqN: robDependency){
        instrstr += "," + to_string(robDepSeqN);
    }
    instrstr+= ":";
    for (auto regDepSeqN: regDependency){
        instrstr += "," + to_string(regDepSeqN);
    }

    getstatPoolCount("count_robDepFromLoadInstr")+=robDependency.size();
    getstatPoolCount("count_regDepFromLoadInstr")+=regDependency.size();

    return instrstr;
}


////STORE
bool
STORE_INSTR::isEffective(ADDR _newAddr, int _newSize, int _newIsLoS) {
    return isOverLapAddr(_newAddr, _newSize);
}

STORE_INSTR::STORE_INSTR(ETRACER *_reader, string rawData, uint64_t _instrMdId):
MEM_INSTR(_reader,
          std::move(rawData),
          false,
          _instrMdId){
    if (_reader->newCInstr) {
        robDependency.insert(_reader->newCInstr->getSeqNum());
    }else{
        // cout << "[warning] seq: " << seqNum << " has no compute instruction\n";
    }
    instr_type = INSTR_TYPE::STORE;

}

string
STORE_INSTR::genAscLine() {
    /////# seq_num,[pc],[weight,]type,[p_addr,size,flags,]comp_delay:[rob_dep]:[reg_dep]
    string instrstr = to_string(seqNum) + ",0,1,STORE," +
                      to_string(effAddr) + "," + to_string(effAddrSize) +
                      ",0,500:";

    for (auto robDepSeqN: robDependency){
        instrstr += "," + to_string(robDepSeqN);
    }
    instrstr+= ":";
    for (auto regDepSeqN: regDependency){
        instrstr += "," + to_string(regDepSeqN);
    }

    getstatPoolCount("count_robDepFromStoreInstr")+=robDependency.size();
    getstatPoolCount("count_regDepFromStoreInstr")+=regDependency.size();

    return instrstr;
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

string
COMP_INSTR::genAscLine() {
    //// output format
    ///// seq_num,[pc],[weight,]type,[p_addr,size,flags,]comp_delay:[rob_dep]:[reg_dep]
    string instrstr = to_string(seqNum) + ",0,1,COMP,500:";

    for (auto robDepSeqN: robDependency){
        instrstr += "," + to_string(robDepSeqN);
    }
    instrstr+= ":";
    for (auto regDepSeqN: regDependency){
        instrstr += "," + to_string(regDepSeqN);
    }

    getstatPoolCount("count_robDepFromCompInstr")+=robDependency.size();
    getstatPoolCount("count_regDepFromCompInstr")+=regDependency.size();

    return instrstr;
}

/////FETCH

FETCH_INSTR::FETCH_INSTR(ETRACER* _reader, const string& _raw):
INSTR(_reader, -1, false)
{
    assert(!_raw.empty());
    vector<string> splitedInstr;
    splitNstrip(_raw, splitedInstr);

    assert(splitedInstr.size() == 2);
    assert( splitedInstr [F_Idx  ] == "F" );
    assert(!splitedInstr [F_MdIdx].empty());

    instrMdId = decStr2uint(splitedInstr[F_MdIdx]);
    INSTR_MODEL* instrModel = _reader->instrModelMng->getInstrModel(instrMdId);

    startEffAddr = instrModel->getInstrAddr();
    startEffSize = instrModel->getInstrSize();

    addrASizes   = ETRACER::memMapAndSplit(startEffAddr, startEffSize);
    executeTick  = _reader->stepInstrExeTick(compDelay); // get current tick before next tick
    
    if (addrASizes.size() > 1) {
        uint64_t &maxfetCount = getstatPoolCount("max_fetchSplit");
        maxfetCount = max(maxfetCount, addrASizes.size());
        getstatPoolCount("count_fetchSplit")++;
    }
    instr_type = FETCH;
    //// we do not deal with dependency about fetch instruction right now due to read-only manner
}

string
FETCH_INSTR::genAscLine() {
    //cmd,addr, size, tick
    string printStr;
    int adsI = 0;
    for (; (adsI+1) < addrASizes.size(); adsI++){
        printStr += "r, " + to_string(addrASizes[adsI].effAddr)+
                    ", "  + to_string(addrASizes[adsI].effSize)+
                    ", "  + to_string(executeTick) +
                    "\n";
    }
    if (adsI < addrASizes.size()){
        printStr += "r, " + to_string(addrASizes[adsI].effAddr)+
                    ", "  + to_string(addrASizes[adsI].effSize)+
                    ", "  + to_string(executeTick);
    }

    getstatPoolCount("count_fetchInstr")++;

    return printStr;
}