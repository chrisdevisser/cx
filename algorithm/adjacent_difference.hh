#pragma once
#ifndef CX_ALGORITHM_ADJACENTDIFFERENCE_H
#define CX_ALGORITHM_ADJACENTDIFFERENCE_H

#include <assert.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"
#include "../type_utils.hh"

#define CX_USING_ALGORITHM_ADJACENTDIFFERENCE(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_ADJACENTDIFFERENCE, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_ADJACENTDIFFERENCE2(T, T2)\
CX_USING(cxAdjacentDifference2F, T, T2)

#define cxAdjacentDifference2F(T, T2, first, last, out, f) CX_CHOOSE(cxAdjacentDifference2FImpl, T, T2)(first, last, out, f)
#define cxAdjacentDifference2FImpl(T, T2)\
T2 *CX_MANGLE(cxAdjacentDifference2FImpl, T, T2)(T *first, T *last, T2 *out, T2(*f)(T, T)) {\
    assert(first && last && out && f);\
    \
    if (first == last) {return out;}\
    \
    T acc = *first;\
    *out = f(acc, CX_DEFAULT(T));\
    while (++first != last) {\
        T val = *first;\
        *++out = f(val, acc);\
        acc = val;\
    }\
    \
    return out;\
}

#endif

