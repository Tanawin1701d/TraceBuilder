//
// Created by tanawin on 7/2/2566.
//

#ifndef TRACEBUILDER_OPERAND_H
#define TRACEBUILDER_OPERAND_H

#include "models/res_model/regMap/regMapper.h"
#include "models/res_model/memMng/MemMng.h"
#include "models/uop_model/metaData/metaType.h"

namespace traceBuilder::model {


#define GET_DATA_FUNCNAME getData
#define GET_DATA_FUNCNAME_STR "getData"
#define GET_META_FUNCNAME getMeta
#define GET_META_FUNCNAME_STR "getMeta"

/// architecture instruction's operand

    enum OPR_TYPE {
        O_REG,
        O_TEMP,
        O_MEM_LD,
        O_MEM_ST,
        O_IMM,
        O_DUMMY
    };

    class OPERAND;
    typedef std::shared_ptr<OPERAND> OPERAND_PTR;
    class OPERAND {
    private:
        OPR_TYPE OT;
        size_t mcArgSIdx; //// macroop operand idx for each side (src or des side)
    public:
        OPERAND(OPR_TYPE OT, size_t _mcArgSIdx) :
                OT(OT),
                mcArgSIdx(_mcArgSIdx) {};

        virtual ~OPERAND() = default;

        OPR_TYPE getOPTYPE() { return OT; };

        [[nodiscard]] size_t getMcSideIdx() const { return mcArgSIdx; }


    };

    /// register operand it is used at src and des operand
    class OPR_REG : public OPERAND {
    private:
        AREGNUM reg;
    public:

        OPR_REG(AREGNUM _reg, size_t _mcArgSIdx) :
                OPERAND(O_REG, _mcArgSIdx),
                reg(_reg){};

        /////// get meta data of the operand that is fundamental of uop
        AREGNUM GET_DATA_FUNCNAME() const {return reg;};
        MREG_META GET_META_FUNCNAME(int subRegIdx) const;


    };

    class OPR_TREG : public OPERAND {
    private:
        TREGNUM regId;
    public:

        explicit OPR_TREG(TREGNUM regId) :
                OPERAND(O_TEMP, 0),
                regId(regId)

        {
            assert(regId != UNUSED_TREG);
        };

        TREGNUM GET_DATA_FUNCNAME() const {return regId;};
        TREG_META GET_META_FUNCNAME() const;
    };

/// memory operand

    class OPR_MEM : public OPERAND {
    private:
        const uint8_t MAX_BYTE_PER_MICROOP = 8;
        MEM_META _meta;

    public:

        OPR_MEM(MEM_META memMeta,
                OPR_TYPE _setOpr,
                size_t _mcArgSIdx) :
                OPERAND(_setOpr, _mcArgSIdx),
                _meta(memMeta){
            assert(MAX_BYTE_PER_MICROOP > 0);
            ///// caculate expect uop that should handle this instr
        };

        MEM_META GET_DATA_FUNCNAME() const {return _meta;}
        MEM_META GET_META_FUNCNAME(ADDR startByte, ADDR stopByte) const;
        void setPhyAddr(ADDR phyAddr){_meta.p_area.addr = phyAddr;}
        void setVirAddr(ADDR virAddr){_meta.v_area.addr = virAddr;}
    };

/// immediate operand
    class OPR_IMM : public OPERAND {
        // imm operand
    private:
        IMM imm;
    public:
        OPR_IMM(IMM _imm, size_t _mcArgSIdx) :
                OPERAND(O_IMM, _mcArgSIdx),
                imm(_imm)
             {};

        IMM GET_DATA_FUNCNAME() const {return imm;};
        IMM_META GET_META_FUNCNAME() const;
    };

    ////////////////////////////////////////////////////////////////////////////////////////
    ///////// pybind declaration
    namespace py = pybind11;
    void BIND_OPERAND(py::module& m);

}
#endif //TRACEBUILDER_OPERAND_H
