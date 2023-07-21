//
// Created by tanawin on 21/7/2566.
//

#ifndef TRACEBUILDER_REFVEC_H
#define TRACEBUILDER_REFVEC_H

#include<vector>
#include<memory>

/** this is used to create vector of shared ele from src vector
 *  so we should call it only 1 time.
 * */

namespace traceBuilder {

    template<typename T>
    std::vector<std::shared_ptr<T>> cvtToSharedRef(std::vector<T>& src) {
        std::vector<std::shared_ptr<T>> results;
        for (auto& ele: src) {
            results.push_back(std::shared_ptr<T>(&ele));
        }
        return results;
    }

}

#endif //TRACEBUILDER_REFVEC_H
