//
// Created by tanawin on 17/6/2566.
//

#ifndef TRACEBUILDER_ARRAYITERATOR_H
#define TRACEBUILDER_ARRAYITERATOR_H

#include<cstdlib>

namespace traceBuilder {

    template<typename T>
    class ARRAY_FWD_ITERATOR {
    protected:
        size_t _curIdx;
        T*     _dayta;
    public:
        /** constructor init the curIdx to point to some array*/
        explicit ARRAY_FWD_ITERATOR(size_t curIdx, T* dayta):_curIdx(curIdx), _dayta(dayta){}
        /** for forward iterating*/
        ARRAY_FWD_ITERATOR& operator++() noexcept{
            _curIdx++;
            return *this;
        }
        /** for get data*/
        auto operator*() const noexcept{
            return _dayta[_curIdx];
        }
        /** for check equality of iterator*/
        bool operator!=(const ARRAY_FWD_ITERATOR& rhs) const noexcept{
            return !(_curIdx == rhs._curIdx  && _dayta == rhs._dayta);
        }
    };


}

#endif //TRACEBUILDER_ARRAYITERATOR_H
