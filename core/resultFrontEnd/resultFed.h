//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_RESULTFED_H
#define TRACEBUILDER_RESULTFED_H

#include <vector>
#include "../../components/uop/uop_base.h"

class RESULT_FRONT_END{

protected:
    ////////// please remind that this UOP_BASE pointer will be deleted later
    ///////////////// (when uop window discard it, uop will be deleted)
    virtual void onGetResult(std::vector<UOP_BASE*>& results) = 0;

};


#endif //TRACEBUILDER_RESULTFED_H
