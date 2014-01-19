#pragma once
#ifndef CX_ALGORITHM_FILLN_H
#define CX_ALGORITHM_FILLN_H

#include <assert.h>
#include <stddef.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_FILLN(T)\
CX_USING(cxFillN, T)

#define cxFillN(T, first, count, value) CX_CHOOSE(cxFillNImpl, T)(first, count, value)
#define cxFillNImpl(T)\
T *CX_MANGLE(cxFillNImpl, T)(T *first, size_t count, T value) {\
    assert(first);\
    \
    for (size_t i = 0; i < count; ++i) {\
        *first++ = value;\
    }\
    \
    return first;\
}

#endif
