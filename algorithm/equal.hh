#pragma once
#ifndef CX_ALGORITHM_EQUAL_H
#define CX_ALGORITHM_EQUAL_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_EQUAL(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_EQUAL, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_EQUAL1(T)\
CX_USING(cxEqual, T)\
CX_USING(cxEqualF, T)

#define CX_USING_ALGORITHM_EQUAL2(T, T2)\
CX_USING(cxEqualDF, T, T2)\
CX_USING(cxEqual2, T, T2)\
CX_USING(cxEqual2F, T, T2)

#define CX_USING_ALGORITHM_EQUAL3(T, T2, T3)\
CX_USING(cxEqual2DF, T, T2, T3)

#define cxEqual(T, first, last, first2) CX_CHOOSE(cxEqualImpl, T)(first, last, first2)
#define cxEqualImpl(T)\
bool CX_MANGLE(cxEqualImpl, T)(const T *first, const T *last, const T *first2) {\
    assert(first && last && first2);\
    \
    for (; first != last; ++first, ++first2) {\
        if (!(*first == *first2)) {return false;}\
    }\
    \
    return true;\
}

#define cxEqualF(T, first, last, first2, p) CX_CHOOSE(cxEqualFImpl, T)(first, last, first2, p)
#define cxEqualFImpl(T)\
bool CX_MANGLE(cxEqualFImpl, T)(const T *first, const T *last, const T *first2, bool(*p)(T, T)) {\
    assert(first && last && first2 && p);\
    \
    for (; first != last; ++first, ++first2) {\
        if (!p(*first, *first2)) {return false;}\
    }\
    \
    return true;\
}

#define cxEqualDF(T, T2, first, last, first2, p, data) CX_CHOOSE(cxEqualDFImpl, T, T2)(first, last, first2, p, data)
#define cxEqualDFImpl(T, T2)\
bool CX_MANGLE(cxEqualDFImpl, T, T2)(const T *first, const T *last, const T *first2, bool(*p)(T, T, T2), T2 data) {\
    assert(first && last && first2 && p);\
    \
    for (; first != last; ++first, ++first2) {\
        if (!p(*first, *first2, data)) {return false;}\
    }\
    \
    return true;\
}

#define cxEqual2(T, T2, first, last, first2) CX_CHOOSE(cxEqual2Impl, T, T2)(first, last, first2)
#define cxEqual2Impl(T, T2)\
bool CX_MANGLE(cxEqual2Impl, T, T2)(const T *first, const T *last, const T2 *first2) {\
    assert(first && last && first2);\
    \
    for (; first != last; ++first, ++first2) {\
        if (!(*first == *first2)) {return false;}\
    }\
    \
    return true;\
}

#define cxEqual2F(T, T2, first, last, first2, p) CX_CHOOSE(cxEqual2FImpl, T, T2)(first, last, first2, p)
#define cxEqual2FImpl(T, T2)\
bool CX_MANGLE(cxEqual2FImpl, T, T2)(const T *first, const T *last, const T2 *first2, bool(*p)(T, T2)) {\
    assert(first && last && first2 && p);\
    \
    for (; first != last; ++first, ++first2) {\
        if (!p(*first, *first2)) {return false;}\
    }\
    \
    return true;\
}

#define cxEqual2DF(T, T2, T3, first, last, first2, p, data) CX_CHOOSE(cxEqual2DFImpl, T, T2, T3)(first, last, first2, p, data)
#define cxEqual2DFImpl(T, T2, T3)\
bool CX_MANGLE(cxEqual2DFImpl, T, T2, T3)(const T *first, const T *last, const T2 *first2, bool(*p)(T, T2, T3), T3 data) {\
    assert(first && last && first2 && p);\
    \
    for (; first != last; ++first, ++first2) {\
        if (!p(*first, *first2, data)) {return false;}\
    }\
    \
    return true;\
}

#endif
