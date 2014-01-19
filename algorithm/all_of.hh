#pragma once
#ifndef CX_ALGORITHM_ALLOF_H
#define CX_ALGORITHM_ALLOF_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_ALLOF(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_ALLOF, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_ALLOF1(T)\
CX_USING(cxAllOf, T)

#define CX_USING_ALGORITHM_ALLOF2(T, T2)\
CX_USING(cxAllOfD, T, T2)

#define cxAllOf(T, first, last, p) CX_CHOOSE(cxAllOfImpl, T)(first, last, p)
#define cxAllOfImpl(T)\
bool CX_MANGLE(cxAllOfImpl, T)(const T *first, const T *last, bool(*p)(T)) {\
    assert(first && last && p);\
    \
    for (; first != last; ++first) {\
        if (!p(*first)) {return false;}\
    }\
    \
    return true;\
}

#define cxAllOfD(T, T2, first, last, p, data) CX_CHOOSE(cxAllOfDImpl, T, T2)(first, last, p, data)
#define cxAllOfDImpl(T, T2)\
bool CX_MANGLE(cxAllOfDImpl, T, T2)(const T *first, const T *last, bool(*p)(T, T2), T2 data) {\
    assert(first && last && p);\
    \
    for (; first != last; ++first) {\
        if (!p(*first, data)) {return false;}\
    }\
    \
    return true;\
}

#endif
