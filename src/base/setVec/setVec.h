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

namespace traceBuilder{

/**
 * Brief setVec
 * setVec is light-weight data structure which design for ask the existence data in set
 * with ability to sweep the structure in O(n).
 * but for now remove and sorting is not support yet
 * to support setVec type T must inherit setVecIndexer
 */


    template<typename T, std::function<size_t(T&)>& indexer, int MAXSIZE>
    class setVec{
    protected:
        static constexpr size_t bitSetSize = (MAXSIZE + AMT_BIT_UINT64 - 1) / sizeof(uint64_t);
        uint64_t _bitSet[bitSetSize]{};
        T        _data[MAXSIZE];
        size_t   _eleCount{};
        ////// for get idx in bitSet array first return element is index second is bit in element
        std::pair<size_t, size_t> getBitSetId(size_t idx);
        void rangeCheck(size_t arrIdx, size_t bitIdx);
    public:
        /**asking method*/
        bool isThere(const T& ele);
        bool isInRange(const T& ele);
        /**get method*/

        /**set method*/
        void push(const T& ele, bool overWrite);


    };


    template<typename T,std::function<size_t(T&)>& indexer,  int MAXSIZE>
    std::pair<size_t, size_t> setVec<T, indexer, MAXSIZE>::getBitSetId(size_t idx) {
        size_t arrIdx = idx / AMT_BIT_UINT64;
        size_t bitIdx = idx % AMT_BIT_UINT64;

        return {arrIdx, bitIdx};
    }

    template<typename T, std::function<size_t(T&)>& indexer, int MAXSIZE>
    void setVec<T, indexer, MAXSIZE>::rangeCheck(size_t arrIdx, size_t bitIdx) {
        assert(arrIdx < bitSetSize);
        assert(bitIdx < AMT_BIT_UINT64);
    }


    template<typename T, std::function<size_t(T&)>& indexer, int MAXSIZE>
    bool setVec<T, indexer, MAXSIZE>::isThere(const T &ele) {
        size_t idx =  indexer(ele);
        auto [arrIdx, bitIdx] = getBitSetId(idx);
        rangeCheck(arrIdx, bitIdx);
        return _bitSet[arrIdx] & ( ((uint64_t) 1) << bitIdx);
    }


    template<typename T, std::function<size_t(T&)>& indexer, int MAXSIZE>
    bool setVec<T, indexer, MAXSIZE>::isInRange(const T &ele) {
        size_t idx = indexer(ele);
        auto [arrIdx, bitIdx] = getBitSetId(idx);
        return arrIdx < bitSetSize && bitIdx < AMT_BIT_UINT64;
    }

    template<typename T, std::function<size_t(T&)>& indexer, int MAXSIZE>
    void setVec<T, indexer, MAXSIZE>::push(const T &ele, bool overWrite) {
        size_t idx = indexer(ele);
        auto [arrIdx, bitIdx] = getBitSetId(idx);
        rangeCheck(arrIdx, bitIdx);
        if ( (!isThere(ele)) || overWrite){
            _bitSet[arrIdx] |= (((uint64_t)1) << bitIdx);
            _data[_eleCount++] = ele;
        }
    }

}


#endif //TRACEBUILDER_SETVEC_H
