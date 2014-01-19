#pragma once
#ifndef CX_ALGORITHM_NONEOF_H
#define CX_ALGORITHM_NONEOF_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_NONEOF(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_NONEOF, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_NONEOF1(T)\
CX_USING(cxNoneOf, T)

#define CX_USING_ALGORITHM_NONEOF2(T, T2)\
CX_USING(cxNoneOfD, T, T2)

#define cxNoneOf(T, first, last, p) CX_CHOOSE(cxNoneOfImpl, T)(first, last, p)
#define cxNoneOfImpl(T)\
bool CX_MANGLE(cxNoneOfImpl, T)(const T *first, const T *last, bool(*p)(T)) {\
    assert(first && last && p);\
    \
    for (; first != last; ++first) {\
        if (p(*first)) {return false;}\
    }\
    \
    return true;\
}

#define cxNoneOfD(T, T2, first, last, p, data) CX_CHOOSE(cxNoneOfDImpl, T, T2)(first, last, p, data)
#define cxNoneOfDImpl(T, T2)\
bool CX_MANGLE(cxNoneOfDImpl, T, T2)(const T *first, const T *last, bool(*p)(T, T2), T2 data) {\
    assert(first && last && p);\
    \
    for (; first != last; ++first) {\
        if (p(*first, data)) {return false;}\
    }\
    \
    return true;\
}

#endif
