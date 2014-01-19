#pragma once
#ifndef CX_ALGORITHM_UPPERBOUND_H
#define CX_ALGORITHM_UPPERBOUND_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_UPPERBOUND(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_UPPERBOUND, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_UPPERBOUND1(T)\
CX_USING(cxUpperBound, T)\
CX_USING(cxUpperBoundF, T)

#define CX_USING_ALGORITHM_UPPERBOUND2(T)\
CX_USING(cxUpperBoundDF, T, T2)

#define cxUpperBound(T, first, last, value) CX_CHOOSE(cxUpperBoundImpl, T)(first, last, value)
#define cxUpperBoundImpl(T)\
T *CX_MANGLE(cxUpperBoundImpl, T)(T *first, T *last, T value) {\
    assert(first && last);\
    \
    T *it;\
    ptrdiff_t count = last - first;\
    ptrdiff_t step;\
    \
    while (count > 0) {\
        it = first;\
        step = count / 2;\
        it += step;\
        \
        if (value >= *it) {\
            first = ++it;\
            count -= step + 1;\
        } else {count = step;}\
    }\
    \
    return first;\
}

#define cxUpperBoundF(T, first, last, value, p) CX_CHOOSE(cxUpperBoundFImpl, T)(first, last, value, p)
#define cxUpperBoundFImpl(T)\
T *CX_MANGLE(cxUpperBoundFImpl, T)(T *first, T *last, T value, bool(*p)(T, T)) {\
    assert(first && last && p);\
    \
    T *it;\
    ptrdiff_t count = last - first;\
    ptrdiff_t step;\
    \
    while (count > 0) {\
        it = first;\
        step = count / 2;\
        it += step;\
        \
        if (!p(value, *it)) {\
            first = ++it;\
            count -= step + 1;\
        } else {count = step;}\
    }\
    \
    return first;\
}

#define cxUpperBoundDF(T, T2, first, last, value, p, data) CX_CHOOSE(cxUpperBoundDFImpl, T, T2)(first, last, value, p, data)
#define cxUpperBoundDFImpl(T, T2)\
T *CX_MANGLE(cxUpperBoundDFImpl, T, T2)(T *first, T *last, T value, bool(*p)(T, T, T2), T2 data) {\
    assert(first && last && p);\
    \
    T *it;\
    ptrdiff_t count = last - first;\
    ptrdiff_t step;\
    \
    while (count > 0) {\
        it = first;\
        step = count / 2;\
        it += step;\
        \
        if (!p(value, *it, data)) {\
            first = ++it;\
            count -= step + 1;\
        } else {count = step;}\
    }\
    \
    return first;\
}

#endif

