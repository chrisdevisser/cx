#pragma once
#ifndef CX_ALGORITHM_FILL_H
#define CX_ALGORITHM_FILL_H

#include <assert.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_FILL(T)\
CX_USING(cxFill, T)

#define cxFill(T, first, last, value) CX_CHOOSE(cxFillImpl, T)(first, last, value)
#define cxFillImpl(T)\
void CX_MANGLE(cxFillImpl, T)(T *first, T *last, T value) {\
    assert(first && last);\
    \
    for (; first != last; ++first) {\
        *first = value;\
    }\
}

#endif
