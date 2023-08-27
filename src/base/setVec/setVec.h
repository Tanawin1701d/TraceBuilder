//
// Created by tanawin on 16/6/2566.
//

#ifndef TRACEBUILDER_SETVEC_H
#define TRACEBUILDER_SETVEC_H

#include<cstdlib>
#include <cstdint>
#include <climits>
#include <utility>
#include <cassert>
#include <functional>

#include "config/fixed_param.h"
#include "base/iterator/arrayIterator.h"

namespace traceBuilder {

/**
 * Brief setVec
 * setVec is light-weight data structure which design for ask the existence data in set
 * with ability to sweep the structure in O(n).
 * but for now removing and sorting is not support yet
 * to support setVec type T must inherit setVecIndexer
 */


    template<typename T, int MAXSIZE>
    class SETVEC {
    protected:
        static constexpr size_t bitSetSize = (MAXSIZE + AMT_BIT_UINT64 - 1) / sizeof(uint64_t);
        typedef std::function<size_t(T &)>* INDEXER_PTR;
        uint64_t _bitSet[bitSetSize]{};
        T        _data  [MAXSIZE];
        size_t   _eleCount{};
        INDEXER_PTR _indexer;



        ////// for get idx in bitSet array first return element is index second is bit in element
        std::pair<size_t, size_t> getBitSetId(size_t idx) {
            size_t arrIdx = idx / AMT_BIT_UINT64;
            size_t bitIdx = idx % AMT_BIT_UINT64;
            return {arrIdx, bitIdx};
        }

        void rangeCheck(size_t arrIdx, size_t bitIdx) {
            assert(arrIdx < bitSetSize);
            assert(bitIdx < AMT_BIT_UINT64);
        }
        /** iterator to get element in set by regardless order ### using ARRAY_FWD_ITERATOR*/

    public:
        /** constructor aim to initialize indexer*/
        explicit SETVEC(INDEXER_PTR indexer): _indexer(indexer){}

        /**asking method*/
        bool isThereIdx(const size_t idx){
            auto [arrIdx, bitIdx] = getBitSetId(idx);
            rangeCheck(arrIdx, bitIdx);
            return _bitSet[arrIdx] & (((uint64_t) 1) << bitIdx);
        }
        bool isThere(const T &ele) {
            size_t idx = indexer(ele);
            return isThereIdx(idx);
        }
        bool isInRangeIdx(const size_t idx){
            auto [arrIdx, bitIdx] = getBitSetId(idx);
            return arrIdx < bitSetSize && bitIdx < AMT_BIT_UINT64;
        }
        bool isInRange(const T &ele) {
            size_t idx = indexer(ele);
            return isInRangeIdx(idx);

        }
        /**get method*/
        size_t size() const noexcept{
            return _eleCount;
        }
        ARRAY_FWD_ITERATOR<T> begin(){
            return ARRAY_FWD_ITERATOR<T>(0, _data);
        }
        ARRAY_FWD_ITERATOR<T> end(){
            return ARRAY_FWD_ITERATOR<T>(_eleCount, _data);
        }
        /**set method*/
        void pushIdx(const T& ele, const size_t idx, bool overWrite){
            auto [arrIdx, bitIdx] = getBitSetId(idx);
            rangeCheck(arrIdx, bitIdx);
            if ((!isThereIdx(idx)) || overWrite) {
                _bitSet[arrIdx] |= (((uint64_t) 1) << bitIdx);
                _data[_eleCount++] = ele;
            }
        }
        void push(const T& ele, bool overWrite) {
            size_t idx = indexer(ele);
            pushIdx(ele,idx, overWrite);

        }
    };
}


#endif //TRACEBUILDER_SETVEC_H
