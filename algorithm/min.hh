#pragma once
#ifndef CX_ALGORITHM_MIN_H
#define CX_ALGORITHM_MIN_H

#include <assert.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_MIN(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_MIN, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_MIN1(T)\
CX_USING(cxMin, T)

#define cxMin(T, a, b) CX_CHOOSE(cxMinImpl, T)(a, b)
#define cxMinImpl(T)\
T CX_MANGLE(cxMinImpl, T)(T a, T b) {\
    return a < b ? a : b;\
}

#endif

