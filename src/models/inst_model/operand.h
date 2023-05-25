//
// Created by tanawin on 7/2/2566.
//

#ifndef TRACEBUILDER_OPERAND_H
#define TRACEBUILDER_OPERAND_H

#include "core/resMng/regMap/regMapper.h"
#include "core/resMng/memMng/MemMng.h"

typedef  unsigned long long IMM;


/// architecture instruction's operand

enum OPR_TYPE {
    O_REG,
    O_MEM_LD,
    O_MEM_ST,
    O_IMM,
    O_DUMMY
};

class OPERAND{
private:
    OPR_TYPE OT;
    size_t   mcArgSIdx; //// macroop operand idx for each side (src or des side)
public:
    OPERAND(OPR_TYPE _OT, size_t _mcArgSIdx);
    virtual ~OPERAND() = default;
    OPR_TYPE getOPTYPE() {return OT;};
    size_t   getMcSideIdx() {return mcArgSIdx;}
};

class OPR_TREG : public OPERAND{
private:
    REGNUM regId;
public:
    OPR_TREG();
    REGNUM getRegId() const;
    REGNUM getMeta() const;
};

/// register operand it is used at src and des operand
class OPR_REG : public OPERAND{
private:
    REGNUM regId;
public:
    OPR_REG(REGNUM _regId, size_t _mcArgSIdx);
    REGNUM getRegId() const;
    /////// get meta data of the operand that is fundamental of uop
    REGNUM getMeta() const;
};


/// memory operand
class OPR_MEM : public OPERAND{
private:
    const uint8_t MAX_BYTE_PER_MICROOP = 8;
    REGNUM baseRegId;
    REGNUM indexRegId;
    int    scaleFactor;
    IMM    displacement;
    ADDR   size;
    int    memopNum;
    ADDR   phyAddr;
    ////// for some memory operand expect to divided into multiple uop (multiple meta data)
    ///////// so now we call it as "SHARED OPERAND TRACKING"
    int    expect_ruop_count; //// expect related micro-op count
    int    current_ruop_count; //// current expect related used count
    ADDR   nextPhyAddr; ///// next physical addr for microop and size
    ///////////////////////////////////////////////////////////////////
public:
    OPR_MEM(REGNUM _baseRegId,
            REGNUM _indexRegId,
            int    _scaleFactor,
            IMM    _displacement,
            ADDR    _size,
            int    _memopNum,
            OPR_TYPE _setOpr,
            size_t _mcArgSIdx);

    REGNUM getBaseRegId() const;

    REGNUM getIndexRegId() const;

    int getScaleFactor() const;

    IMM getDisplacement() const;

    ADDR getSize() const;

    void setPhyAddr(ADDR phyAddr);

    int getMemopNum() const;

    ADDR getPhyAddr() const;
    /////// get meta data of the operand that is fundamental of uop
    ADAS getMeta();

    void resetSharedOperandTracker();

};
/// load operand
class OPR_MEM_LD : public OPR_MEM{
public:
    // load operand
    OPR_MEM_LD(REGNUM _baseRegId,
               REGNUM _indexRegId,
               int    _scaleFactor,
               IMM    _displacement,
               ADDR    _size,
               int    _memopNum,
               size_t _mcArgSIdx);
};
/// store operand
class OPR_MEM_ST : public OPR_MEM{
public:
    // store operand
    OPR_MEM_ST(REGNUM _baseRegId,
               REGNUM _indexRegId,
               int    _scaleFactor,
               IMM    _displacement,
               ADDR    _size,
               int    _memopNum,
               size_t _mcArgSIdx);
};
/// immediate operand
class OPR_IMM : public OPERAND{
    // imm operand
private:
    IMM imm;
public:
    OPR_IMM(IMM _imm, size_t _mcArgSIdx);

    IMM getImm() const;

    IMM getValue() const;
};


#endif //TRACEBUILDER_OPERAND_H
