//
// Created by tanawin on 7/2/2566.
//

#ifndef TRACEBUILDER_OPERAND_H
#define TRACEBUILDER_OPERAND_H

#include "models/res_model/regMap/regMapper.h"
#include "models/res_model/memMng/MemMng.h"
#include "models/uop_model/metaData/metaType.h"

namespace traceBuilder::model {




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

    /// register operand it is used at src and des operand
    class OPR_REG : public OPERAND {
    private:
        REGNUM regId;
    public:
        OPR_REG(REGNUM _regId, size_t _mcArgSIdx);

        REGNUM getRegId() const;

        /////// get meta data of the operand that is fundamental of uop
        REGNUM getMeta() const;

        ///// sub reg idx
        //////////// for precise support vector instruction micro-model
        REGNUM getMeta(int subRegIdx);
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




/// memory operand

    class OPR_MEM : public OPERAND {
    private:
        const uint8_t MAX_BYTE_PER_MICROOP = 8;
        MEM_META _meta;

    public:
        OPR_MEM(MEM_META memMeta,
                OPR_TYPE _setOpr,
                size_t _mcArgSIdx);

        MEM_META getMeta(ADDR startByte, ADDR stopByte) const;
        MEM_META getMeta() const {return _meta;}

        void setPhyAddr(ADDR phyAddr){_meta.p_area.addr = phyAddr;}
        void setVirAddr(ADDR virAddr){_meta.v_area.addr = virAddr;}

    };

/// load operand
    class OPR_MEM_LD : public OPR_MEM {
    public:
        // load operand
        OPR_MEM_LD(MEM_META memMeta,
                   size_t _mcArgSIdx
                   );
    };

/// store operand
    class OPR_MEM_ST : public OPR_MEM {
    public:
        // store operand
        OPR_MEM_ST(MEM_META memMeta,
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

        IMM getMeta() const {return imm;};
    };

}
#endif //TRACEBUILDER_OPERAND_H
