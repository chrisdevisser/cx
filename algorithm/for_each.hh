#pragma once
#ifndef CX_ALGORITHM_FOREACH_H
#define CX_ALGORITHM_FOREACH_H

#include <assert.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_FOREACH(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_FOREACH, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_FOREACH1(T)\
CX_USING(cxForEach, T)\
CX_USING(cxForEachP, T)

#define CX_USING_ALGORITHM_FOREACH2(T, T2)\
CX_USING(cxForEachD, T, T2)\
CX_USING(cxForEachDP, T, T2)

#define cxForEach(T, first, last, f) CX_CHOOSE(cxForEachImpl, T)(first, last, f)
#define cxForEachImpl(T)\
void CX_MANGLE(cxForEachImpl, T)(const T *first, const T *last, void(*f)(T)) {\
    assert(first && last && f);\
    \
    for (; first != last; ++first) {\
        f(*first);\
    }\
}

#define cxForEachD(T, T2, first, last, f, data) CX_CHOOSE(cxForEachDImpl, T, T2)(first, last, f, data)
#define cxForEachDImpl(T, T2)\
void CX_MANGLE(cxForEachDImpl, T, T2)(const T *first, const T *last, void(*f)(T, T2), T2 data) {\
    assert(first && last && f);\
    \
    for (; first != last; ++first) {\
        f(*first, data);\
    }\
}

#define cxForEachP(T, first, last, f) CX_CHOOSE(cxForEachPImpl, T)(first, last, f)
#define cxForEachPImpl(T)\
void CX_MANGLE(cxForEachPImpl, T)(T *first, T *last, void(*f)(T *)) {\
    assert(first && last && f);\
    \
    for (; first != last; ++first) {\
        f(first);\
    }\
}

#define cxForEachDP(T, T2, first, last, f, data) CX_CHOOSE(cxForEachDPImpl, T, T2)(first, last, f, data)
#define cxForEachDPImpl(T, T2)\
void CX_MANGLE(cxForEachDPImpl, T, T2)(T *first, T *last, void(*f)(T *, T2), T2 data) {\
    assert(first && last && f);\
    \
    for (; first != last; ++first) {\
        f(first, data);\
    }\
}

#endif
