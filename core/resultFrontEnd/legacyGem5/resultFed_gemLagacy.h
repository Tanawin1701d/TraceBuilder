//
// Created by tanawin on 2/3/2566.
//

#ifndef TRACEBUILDER_RESULTFED_GEMLAGACY_H
#define TRACEBUILDER_RESULTFED_GEMLAGACY_H

#include "../resultFed.h"

class RESULT_FRONT_END_GEM_LAGACY : public RESULT_FRONT_END{

protected:

    void onGetUopsResult(std::vector<UOP_BASE*>& results);

public:
    RESULT

};

#endif //TRACEBUILDER_RESULTFED_GEMLAGACY_H
