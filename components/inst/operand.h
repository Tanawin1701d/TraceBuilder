//
// Created by tanawin on 7/2/2566.
//

#ifndef TRACEBUILDER_OPERAND_H
#define TRACEBUILDER_OPERAND_H

#include "../regMap/regMapper.h"

typedef  unsigned long long IMM;


/// architecture instruction's operand
class OPERAND{

};


/// register operand it is used at src and des operand
class REG_OPERAND : public OPERAND{
private:
    REGNUM regId;
public:
    REG_OPERAND(REGNUM _regId);
    REGNUM getRegId() const;
};


/// memory operand
class MEM_OPERAND : public OPERAND{
private:
    REGNUM baseRegId;
    REGNUM indexRegId;
    int    scaleFactor;
    IMM    displacement;
    void genEffAddr();

public:
    MEM_OPERAND(REGNUM _baseRegId,
                REGNUM _indexRegId,
                int    _scaleFactor,
                IMM    _displacement);

    REGNUM getBaseRegId() const;

    REGNUM getIndexRegId() const;

    int getScaleFactor() const;

    IMM getDisplacement() const;
};
/// load operand
class LD_OPERAND : public MEM_OPERAND{
public:
    // load operand
    LD_OPERAND(REGNUM _baseRegId,
               REGNUM _indexRegId,
               int    _scaleFactor,
               IMM    _displacement);
};
/// store operand
class ST_OPERAND : public MEM_OPERAND{
public:
    // store operand
    ST_OPERAND(REGNUM _baseRegId,
               REGNUM _indexRegId,
               int    _scaleFactor,
               IMM    _displacement);
};
/// immediate operand
class IMM_OPERAND : public OPERAND{
    // imm operand
private:
    IMM imm;
public:
    IMM_OPERAND(IMM _imm);

    IMM getImm() const;
};


#endif //TRACEBUILDER_OPERAND_H
