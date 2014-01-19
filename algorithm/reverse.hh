#pragma once
#ifndef CX_ALGORITHM_REVERSE_H
#define CX_ALGORITHM_REVERSE_H

#include <assert.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"
#include "swap.hh"

#define CX_USING_ALGORITHM_REVERSE(T)\
CX_USING(cxReverse, T)

#define cxReverse(T, first, last) CX_CHOOSE(cxReverseImpl, T)(first, last)
#define cxReverseImpl(T)\
void CX_MANGLE(cxReverseImpl, T)(T *first, T *last) {\
    assert(first && last);\
    \
    while ((first != last) && (first != --last)) {\
        cxSwap(T, first++, last);\
    }\
}

#endif
