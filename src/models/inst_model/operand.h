//
// Created by tanawin on 7/2/2566.
//

#ifndef TRACEBUILDER_OPERAND_H
#define TRACEBUILDER_OPERAND_H

#include "models/res_model/regMap/regMapper.h"
#include "models/res_model/memMng/MemMng.h"

namespace traceBuilder::model {

    typedef unsigned long long IMM;


/// architecture instruction's operand

    enum OPR_TYPE {
        O_REG,
        O_TEMP,
        O_MEM_LD,
        O_MEM_ST,
        O_IMM,
        O_DUMMY
    };

    class OPERAND {
    private:
        OPR_TYPE OT;
        size_t mcArgSIdx; //// macroop operand idx for each side (src or des side)
    public:
        OPERAND(OPR_TYPE OT, size_t _mcArgSIdx);

        virtual ~OPERAND() = default;

        OPR_TYPE getOPTYPE() { return OT; };

        size_t getMcSideIdx() const { return mcArgSIdx; }
    };

    class OPR_TREG : public OPERAND {
    private:
        REGNUM regId;
    public:
        OPR_TREG();

        explicit OPR_TREG(int regId);

        REGNUM getRegId() const;

        REGNUM getMeta() const;
    };

/// register operand it is used at src and des operand
    class OPR_REG : public OPERAND {
    private:
        REGNUM regId;
    public:
        OPR_REG(REGNUM _regId, size_t _mcArgSIdx);

        REGNUM getRegId() const;

        /////// get meta data of the operand that is fundamental of uop
        REGNUM getMeta() const;
    };


/// memory operand
    struct MEM_OPR_META{
        REGNUM baseRegId;
        REGNUM indexRegId;
        int scaleFactor;
        IMM displacement;
        ADDR size;
    };

    class OPR_MEM : public OPERAND {
    private:
        const uint8_t MAX_BYTE_PER_MICROOP = 8;

        MEM_OPR_META _meta;
        ADDR _phyAddr{};
        ADDR _virAddr{};
        ////// for some memory operand expect to divided into multiple uop (multiple meta data)
        ///////// so now we call it as "SHARED OPERAND TRACKING"
        [[maybe_unused]] int expect_ruop_count; //// expect related micro-op count
        [[maybe_unused]] int current_ruop_count; //// current expect related used count
        ADDR _nextVirAddr{}; ///// next physical addr for microop and size
        ///////////////////////////////////////////////////////////////////
    public:
        OPR_MEM(MEM_OPR_META memMeta,
                OPR_TYPE _setOpr,
                size_t _mcArgSIdx);

        void setVirAddr(ADDR virAddr);
        ADDR getVirAddr() const {return _virAddr;};
        ADDR getEndVirAddr() const {return _virAddr + _meta.size;}

        void setPhyAddr(ADDR phyAddr);

        ADDR getPhyAddr() const {return _phyAddr;};

        ADDR getCurUopSize() const {return std::min((ADDR) MAX_BYTE_PER_MICROOP,getEndVirAddr() - _nextVirAddr);}


        /////// get meta data of the operand that is fundamental of uop

        ADAS getMeta_phyArea();
        ADAS getMeta_virArea();

        MEM_OPR_META getMeta_Static(){return _meta;}

        void resetSharedOperandTracker();

    };

/// load operand
    class OPR_MEM_LD : public OPR_MEM {
    public:
        // load operand
        OPR_MEM_LD(MEM_OPR_META memMeta,
                   size_t _mcArgSIdx
                   );
    };

/// store operand
    class OPR_MEM_ST : public OPR_MEM {
    public:
        // store operand
        OPR_MEM_ST(MEM_OPR_META memMeta,
                   size_t       _mcArgSIdx);
    };

/// immediate operand
    class OPR_IMM : public OPERAND {
        // imm operand
    private:
        IMM imm;
    public:
        OPR_IMM(IMM _imm, size_t _mcArgSIdx);

        IMM getImm() const;

        IMM getValue() const;
    };

}
#endif //TRACEBUILDER_OPERAND_H
