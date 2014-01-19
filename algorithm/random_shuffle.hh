#pragma once
#ifndef CX_ALGORITHM_RANDOMSHUFFLE_H
#define CX_ALGORITHM_RANDOMSHUFFLE_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"
#include "random.hh"
#include "swap.hh"

#define CX_USING_ALGORITHM_RANDOMSHUFFLE(T)\
CX_USING(cxRandomShuffle, T)

#define cxRandomShuffle(T, first, last) CX_CHOOSE(cxRandomShuffleImpl, T)(first, last)
#define cxRandomShuffleImpl(T)\
void CX_MANGLE(cxRandomShuffleImpl, T)(T *first, T *last) {\
    assert(first && last);\
    \
    for (ptrdiff_t i = last - first - 1; i > 0; --i) {\
        cxSwap(T, &first[i], &first[cxRandIn(0, i)]);\
    }\
}

#endif

