#pragma once
#ifndef CX_ALGORITHM_ANYOF_H
#define CX_ALGORITHM_ANYOF_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_ANYOF(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_ANYOF, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_ANYOF1(T)\
CX_USING(cxAnyOf, T)

#define CX_USING_ALGORITHM_ANYOF2(T, T2)\
CX_USING(cxAnyOfD, T, T2)

#define cxAnyOf(T, first, last, p) CX_CHOOSE(cxAnyOfImpl, T)(first, last, p)
#define cxAnyOfImpl(T)\
bool CX_MANGLE(cxAnyOfImpl, T)(const T *first, const T *last, bool(*p)(T)) {\
    assert(first && last && p);\
    \
    for (; first != last; ++first) {\
        if (p(*first)) {return true;}\
    }\
    \
    return false;\
}

#define cxAnyOfD(T, T2, first, last, p, data) CX_CHOOSE(cxAnyOfDImpl, T, T2)(first, last, p, data)
#define cxAnyOfDImpl(T, T2)\
bool CX_MANGLE(cxAnyOfDImpl, T, T2)(const T *first, const T *last, bool(*p)(T, T2), T2 data) {\
    assert(first && last && p);\
    \
    for (; first != last; ++first) {\
        if (p(*first, data)) {return true;}\
    }\
    \
    return false;\
}

#endif
