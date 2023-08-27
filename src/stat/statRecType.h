//
// Created by tanawin on 17/4/2566.
//

#ifndef TRACEBUILDER_STATRECTYPE_H
#define TRACEBUILDER_STATRECTYPE_H

#include<iostream>

namespace traceBuilder::stat {

    enum STAT_TYPE {
        STAT_T_EMPTY,
        STAT_T_UINT64,
        STAT_T_STR
    };

    class STAT_REC_TYPE {
    public:
        virtual std::string printReport() = 0;

    };


    class STAT_REC_TYPE_UINT : public STAT_REC_TYPE {
    private:
        //////// value
        int64_t value;
        ////////////////////////////////////////////
    public:
        STAT_REC_TYPE_UINT();

        int64_t& getRef() { return value; };

        int64_t getVal() { return value; };

        std::string printReport() override;

    };

    class STAT_REC_TYPE_STR : public STAT_REC_TYPE {
    private:
        //////// value
        std::string value;
        ////////////////////////////////////////////
    public:
        STAT_REC_TYPE_STR();

        std::string &getRef() { return value; };

        std::string getVal() { return value; };

        std::string printReport();

    };

/// TODO//////////////////////////////// if you want to add any recode type code it below
}


#endif //TRACEBUILDER_STATRECTYPE_H
