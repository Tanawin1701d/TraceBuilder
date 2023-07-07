//
// Created by tanawin on 3/7/2566.
//

#ifndef TRACEBUILDER_METABASE_H
#define TRACEBUILDER_METABASE_H
#include"base/iterator/arrayIterator.h"
#include "models/res_model/regMap/regMapper.h"
#include "models/res_model/memMng/MemMng.h"
#include "config/fixed_param.h"

/*
 * META_TYPE is used to store meta data for each micro operation
 *
 */

namespace traceBuilder::model {


    enum META_CLASS{
        /** src class*/
        META_SRC_REG,
        META_SRC_TEMP,
        META_SRC_MEM,
        META_SRC_IMM,
        /** des class*/
        META_DES_REG,
        META_DES_TEMP,
        META_DES_MEM,
        /*
         * ADD MORE META DATA HERE
         */
        META_NUM

    };

    class RT_INSTR;

    /**
     * group that contain this type
     * */
    class META_GRP_BASE{
    public:
        template<typename TC>
        /** to convert down*/
        TC* castDown(){
            return reinterpret_cast<TC*>(this);
        }
    };

    template<typename T>
    class META_GRP : public META_GRP_BASE{
    protected:
        T*     _metaEle;
        size_t _maxSize;
        size_t _size;
    public:
        typedef ARRAY_FWD_ITERATOR<T> META_ITER;
        explicit META_GRP(size_t maxSize = MAX_SIZE_METADATA):
        _metaEle(_metaEle),
        _maxSize(maxSize),
        _size(0){}

        ~META_GRP(){delete _metaEle;}

        /** model assistor*/
        void addMeta(T newDayta) {
            assert(_size < _maxSize);
            _metaEle[_size++] = newDayta;
        };

        /** iteration*/
        META_ITER begin() { return META_ITER(0, _metaEle); }
        META_ITER end() { return META_ITER(_size, _metaEle); }
        T&        operator[] (size_t idx) const {
            assert(idx < _size);
            return _metaEle[idx]; }
        bool      empty(){return !_size;}


    };




}




#endif //TRACEBUILDER_METABASE_H