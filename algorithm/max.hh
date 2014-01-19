#pragma once
#ifndef CX_ALGORITHM_MAX_H
#define CX_ALGORITHM_MAX_H

#include <assert.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_MAX(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_MAX, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_MAX1(T)\
CX_USING(cxMax, T)

#define cxMax(T, a, b) CX_CHOOSE(cxMaxImpl, T)(a, b)
#define cxMaxImpl(T)\
T CX_MANGLE(cxMaxImpl, T)(T a, T b) {\
    return a > b ? a : b;\
}

#endif

