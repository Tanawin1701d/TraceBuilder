//
// Created by tanawin on 7/2/2566.
//

#include "operand.h"

namespace traceBuilder::model {

    MREG_META OPR_REG::GET_META_FUNCNAME(int subRegIdx) const {
        return archRegToMReg(reg, subRegIdx);
    }

    TREG_META OPR_TREG::GET_META_FUNCNAME() const {
        return regId;
    }

    MEM_META OPR_MEM::GET_META_FUNCNAME(ADDR startByte, ADDR stopByte) const {
        assert(startByte >= 0 && ((stopByte - startByte) <= MAX_BYTE_PER_MICROOP));
        assert(stopByte >= startByte);
        MEM_META temp = _meta;

        ADDR neededSize = stopByte - startByte;
        ADDR neededStart = temp.v_area.addr + startByte;
        ADDR neededStop  = neededStart      + neededSize;

        ADDR oprStart    = temp.v_area.addr;
        ADDR oprStop     = temp.v_area.addr + temp.size;

        bool isOverlap = (neededStart >= oprStart && neededStart < oprStop) || (oprStart >= neededStart && oprStart < neededStop);

        if (temp.suppressed || !isOverlap || (neededSize == 0)){
            temp.suppressed = true;
            return temp;
        }

        ADDR actualStart = std::max(neededStart, oprStart);
        ADDR actualStop  = std::min(neededStop, oprStop);
        ADDR actualSize  = actualStop - actualStart;
        ADDR offset      = actualStart - oprStart; /// alway actual start > opStart

        temp.v_area.addr += offset;
        temp.p_area.addr += offset;
        temp.size         = actualSize;
        temp.p_area.size  = actualSize;
        temp.v_area.size  = actualSize;


        return temp;
    }


    IMM_META OPR_IMM::GET_META_FUNCNAME() const {
        return imm;
    }


    void BIND_OPERAND(py::module& m){
        /** bind operand type*/

        py::enum_<OPR_TYPE>(m, "OPR_TYPE")
        .value("O_REG"   , OPR_TYPE::O_REG)
        .value("O_TEMP"  , OPR_TYPE::O_TEMP)
        .value("O_MEM_LD", OPR_TYPE::O_MEM_LD)
        .value("O_MEM_ST", OPR_TYPE::O_MEM_ST)
        .value("O_IMM"   , OPR_TYPE::O_IMM)
        .value("O_DUMMY" , OPR_TYPE::O_DUMMY)
        .export_values();


        /** bind operand base*/
        py::class_<OPERAND, std::shared_ptr<OPERAND>>(m, "OPERAND")
                .def(py::init<OPR_TYPE, size_t>(),
                        py::arg("oprType"),
                        py::arg("idxInPool"),
                        "initialize opr")
                .def("getOPR_TYPE", &OPERAND::getOPTYPE)
                .def("getMcSideIdx", &OPERAND::getMcSideIdx);
        /** bind operand reg*/
        py::class_<OPR_REG, OPERAND, std::shared_ptr<OPR_REG>>(m, "OPR_REG")
                .def(py::init<AREGNUM>(),
                        py::arg("archReg"),
                        "reg Opr initializer")
                .def(GET_DATA_FUNCNAME_STR, &OPR_REG::GET_DATA_FUNCNAME);
        /** bind operand treg*/
        py::class_<OPR_TREG, OPERAND, std::shared_ptr<OPR_TREG>>(m, "OPR_TREG")
                .def(py::init<TREGNUM>(),
                     py::arg("tregId"),
                     "treg id initializer"
                     )
                 .def(GET_DATA_FUNCNAME_STR, &OPR_TREG::GET_DATA_FUNCNAME);
        /** bind operand mem*/
        py::class_<OPR_MEM, OPERAND, std::shared_ptr<OPR_MEM>>(m, "OPR_MEM")
                .def(py::init<MEM_META, OPR_TYPE, size_t>(),
                        py::arg("memMeta"),
                        py::arg("oprType"),
                        py::arg("idxInPool"),
                        "mem Opr initializer"
                     )
                 .def(GET_DATA_FUNCNAME_STR, &OPR_MEM::GET_DATA_FUNCNAME);
        /** bind operand imm*/
        py::class_<OPR_IMM, OPERAND,std::shared_ptr<OPR_IMM>>(m, "OPR_IMM")
                .def(py::init<>(),
                        "imm Opr initializer dummy"
                        )
                .def(GET_DATA_FUNCNAME_STR, &OPR_IMM::GET_DATA_FUNCNAME);

    }

}