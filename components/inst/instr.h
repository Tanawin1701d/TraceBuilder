//
// Created by tanawin on 28/12/2565.
//

#ifndef TRACEBUILDER_INSTR_H
#define TRACEBUILDER_INSTR_H
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>
#include "../../tracers/statPool.h"
#include<boost/algorithm/string.hpp>
#include <google/protobuf/message.h>
#include "../regMap/regMapper.h"
#include "../memMap/MemMng.h"
#include "../../ioHelp/strHelp.h"
#include "../../ioHelp/protoHelp/inst_dep_record.pb.h"
#include "../../ioHelp/protoHelp/inst.pb.h"
#include "../../ioHelp/protoHelp/packet.pb.h"
#include "../../ioHelp/protoHelp/protoio.hh"
#include "../../ioHelp/pinIoSh/pinIo.h"


class ETRACER; // pintool reader
class COMP_INSTR;
class STORE_INSTR;

typedef uint64_t TICK;


enum INSTR_TYPE{
    COMP = 0,
    LOAD = 1,
    STORE= 2,
    FETCH = 3//,
    //DUMMY
};

class INSTR{
protected:
    uint64_t seqNum; // sequence  number
    uint64_t instrMdId; // instruction model id
    unordered_set<uint64_t> robDependency;
    unordered_set<uint64_t> regDependency;

public:
    explicit INSTR(ETRACER *_reader, uint64_t instrMdId, bool needGenSeqN);
    uint64_t getInstrMdId() const;


public:
    virtual ~INSTR()= default;
    INSTR_TYPE     instr_type;
    uint64_t getSeqNum() const;
#ifndef debug
    virtual void genProtoMsg(ProtoOutputStream* strm) = 0;
#else
    virtual string genAscLine() ;
#endif
};

// we assume that newly instruction coming need only 1 slot in rob

class MEM_INSTR: public INSTR{
protected:
    const int   LS_Idx       = 0;
    const int   addr_Idx     = 1;
    const int   memop_Idx    = 2;
    const string unusedReg   = "-1";
    ADDR        phyAddr{};
    ADDR        virAddr{}; // effective address
    int         addrSize{};
    int         memop{};

public:
    MEM_INSTR(ETRACER *_reader,
              const RT_OBJ& tracedData,
              const int lsIdx, /// index to point to operand in mem instr
              bool robModeDepIsLoad,
              uint64_t _instrMdId);
    //robModeDepIsLoad to define that current isntruction is load or store
    virtual ~MEM_INSTR() {};
    bool isOverLapAddr(ADDR _newAddr, int _newSize) const;
    virtual bool isEffective(ADDR _addr, int _size, int _newIsLoS) = 0; // is new incoming is load or store
};

class LOAD_INSTR : public MEM_INSTR{
public:
    bool isEffective(ADDR _newAddr, int _newSize, int _newIsLoS) override;
    LOAD_INSTR(      ETRACER* _reader,
               const RT_OBJ&  _tracedData,
               int      _lsIdx, /// index to point to operand in mem instr
                     uint64_t _instrMdId);

    #ifndef debug
    void genProtoMsg(ProtoOutputStream* strm) override;
    #else
    string genAscLine() override;
    #endif
};

class STORE_INSTR : public MEM_INSTR{
protected:

public:
    bool isEffective(ADDR _newAddr, int _newSize, int _newIsLoS) override;
    STORE_INSTR(      ETRACER* _reader,
                      const RT_OBJ&  _tracedData,
                      int      _lsIdx, /// index to point to operand in mem instr
                      uint64_t _instrMdId);
    #ifndef debug
        void genProtoMsg(ProtoOutputStream* strm) override;
    #else
        string genAscLine() override;
    #endif

};

class COMP_INSTR : public INSTR{

public:
    COMP_INSTR(ETRACER* _reader, uint64_t _instrMdId);
    #ifndef debug
        void genProtoMsg(ProtoOutputStream* strm) override;
    #else
        string genAscLine() override;
    #endif


};

class FETCH_INSTR : public INSTR{
protected:
    const int   F_Idx        = 0;
    const int   F_MdIdx      = 1;

    const TICK  compDelay    = 500;
    ADDR                virAddr;
    int                 virSize;
    // address and size
    vector<ADAS>        addrASizes;
    TICK        executeTick;

public:
    explicit FETCH_INSTR(ETRACER* _reader, const RT_OBJ& traced);
    #ifndef debug
        void genProtoMsg(ProtoOutputStream* strm) override;
    #else
        string genAscLine() override;
    #endif
};

#endif //TRACEBUILDER_INSTR_H
