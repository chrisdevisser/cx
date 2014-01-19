#pragma once
#ifndef CX_ALGORITHM_COUNT_H
#define CX_ALGORITHM_COUNT_H

#include <assert.h>
#include <stddef.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_COUNT(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_COUNT, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_COUNT1(T)\
CX_USING(cxCount, T)\
CX_USING(cxCountIf, T)

#define CX_USING_ALGORITHM_COUNT2(T, T2)\
CX_USING(cxCountIfD, T, T2)

#define cxCount(T, first, last, value) CX_CHOOSE(cxCountImpl, T)(first, last, value)
#define cxCountImpl(T)\
ptrdiff_t CX_MANGLE(cxCountImpl, T)(const T *first, const T *last, T value) {\
    assert(first && last);\
    \
    ptrdiff_t ret = 0;\
    for (; first != last; ++first) {\
        if (*first == value) {++ret;}\
    }\
    \
    return ret;\
}

#define cxCountIf(T, first, last, p) CX_CHOOSE(cxCountIfImpl, T)(first, last, p)
#define cxCountIfImpl(T)\
ptrdiff_t CX_MANGLE(cxCountIfImpl, T)(const T *first, const T *last, bool(*p)(T)) {\
    assert(first && last && p);\
    \
    ptrdiff_t ret = 0;\
    for (; first != last; ++first) {\
        if (p(*first)) {++ret;}\
    }\
    \
    return ret;\
}

#define cxCountIfD(T, T2, first, last, p, data) CX_CHOOSE(cxCountIfDImpl, T, T2)(first, last, p, data)
#define cxCountIfDImpl(T, T2)\
ptrdiff_t CX_MANGLE(cxCountIfDImpl, T, T2)(const T *first, const T *last, bool(*p)(T, T2), T2 data) {\
    assert(first && last && p);\
    \
    ptrdiff_t ret = 0;\
    for (; first != last; ++first) {\
        if (p(*first, data)) {++ret;}\
    }\
    \
    return ret;\
}

#endif

