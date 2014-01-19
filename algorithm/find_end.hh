#pragma once
#ifndef CX_ALGORITHM_FINDEND_H
#define CX_ALGORITHM_FINDEND_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_FINDEND(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_FINDEND, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_FINDEND1(T)\
CX_USING(cxFindEnd, T)\
CX_USING(cxFindEndC, T)\
CX_USING(cxFindEndF, T)\
CX_USING(cxFindEndCF, T)

#define CX_USING_ALGORITHM_FINDEND2(T, T2)\
CX_USING(cxFindEndDF, T, T2)\
CX_USING(cxFindEndCDF, T, T2)\
CX_USING(cxFindEnd2, T, T2)\
CX_USING(cxFindEnd2C, T, T2)\
CX_USING(cxFindEnd2CF, T, T2)

#define CX_USING_ALGORITHM_FINDEND3(T, T2, T3)\
CX_USING(cxFindEnd2DF, T, T2, T3)\
CX_USING(cxFindEnd2CDF, T, T2, T3)

#define cxFindEnd(T, first, last, subFirst, subLast) CX_CHOOSE(cxFindEndImpl, T)(first, last, subFirst, subLast)
#define cxFindEndImpl(T)\
T *CX_MANGLE(cxFindEndImpl, T)(T *first, T *last, const T *subFirst, const T *subLast) {\
    assert(first && last && subFirst && subLast);\
    \
    if (subFirst == subLast) {return last;}\
    \
    T *ret = last;\
    for (;;) {\
        T *temp = cxSearch(T, first, last, subFirst, subLast);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEndC(T, first, last, subFirst, subLast) CX_CHOOSE(cxFindEndCImpl, T)(first, last, subFirst, subLast)
#define cxFindEndCImpl(T)\
const T *CX_MANGLE(cxFindEndCImpl, T)(const T *first, const T *last, const T *subFirst, const T *subLast) {\
    assert(first && last && subFirst && subLast);\
    \
    if (subFirst == subLast) {return last;}\
    \
    const T *ret = last;\
    for (;;) {\
        const T *temp = cxSearchC(T, first, last, subFirst, subLast);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEndF(T, first, last, subFirst, subLast, p) CX_CHOOSE(cxFindEndFImpl, T)(first, last, subFirst, subLast, p)
#define cxFindEndFImpl(T)\
T *CX_MANGLE(cxFindEndFImpl, T)(T *first, T *last, const T *subFirst, const T *subLast, bool(*p)(T, T)) {\
    assert(first && last && subFirst && subLast && p);\
    \
    if (subFirst == subLast) {return last;}\
    \
    T *ret = last;\
    for (;;) {\
        T *temp = cxSearchF(T, first, last, subFirst, subLast, p);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEndCF(T, first, last, subFirst, subLast, p) CX_CHOOSE(cxFindEndCFImpl, T)(first, last, subFirst, subLast, p)
#define cxFindEndCFImpl(T)\
const T *CX_MANGLE(cxFindEndCFImpl, T)(const T *first, const T *last, const T *subFirst, const T *subLast, bool(*p)(T, T)) {\
    assert(first && last && subFirst && subLast && p);\
    \
    if (subFirst == subLast) {return last;}\
    \
    const T *ret = last;\
    for (;;) {\
        const T *temp = cxSearchCF(T, first, last, subFirst, subLast, p);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEndDF(T, T2, first, last, subFirst, subLast, p, data) CX_CHOOSE(cxFindEndDFImpl, T, T2)(first, last, subFirst, subLast, p, data)
#define cxFindEndDFImpl(T, T2)\
T *CX_MANGLE(cxFindEndDFImpl, T, T2)(T *first, T *last, const T *subFirst, const T *subLast, bool(*p)(T, T, T2), T2 data) {\
    assert(first && last && subFirst && subLast && p);\
    \
    if (subFirst == subLast) {return last;}\
    \
    T *ret = last;\
    for (;;) {\
        T *temp = cxSearchDF(T, T2, first, last, subFirst, subLast, p, data);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEndCDF(T, T2, first, last, subFirst, subLast, p, data) CX_CHOOSE(cxFindEndCDFImpl, T, T2)(first, last, subFirst, subLast, p, data)
#define cxFindEndCDFImpl(T, T2)\
const T *CX_MANGLE(cxFindEndCDFImpl, T, T2)(const T *first, const T *last, const T *subFirst, const T *subLast, bool(*p)(T, T, T2), T2 data) {\
    assert(first && last && subFirst && subLast && p);\
    \
    if (subFirst == subLast) {return last;}\
    \
    const T *ret = last;\
    for (;;) {\
        const T *temp = cxSearchCDF(T, T2, first, last, subFirst, subLast, p, data);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEnd2(T, T2, first, last, subFirst, subLast) CX_CHOOSE(cxFindEnd2Impl, T, T2)(first, last, subFirst, subLast)
#define cxFindEnd2Impl(T, T2)\
T *CX_MANGLE(cxFindEnd2Impl, T, T2)(T *first, T *last, const T2 *subFirst, const T2 *subLast) {\
    assert(first && last && subFirst && subLast);\
    \
    if (subFirst == subLast) {return last;}\
    \
    T *ret = last;\
    for (;;) {\
        T *temp = cxSearch2(T, T2, first, last, subFirst, subLast);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEnd2C(T, T2, first, last, subFirst, subLast) CX_CHOOSE(cxFindEnd2CImpl, T, T2)(first, last, subFirst, subLast)
#define cxFindEnd2CImpl(T, T2)\
const T *CX_MANGLE(cxFindEnd2CImpl, T, T2)(const T *first, const T *last, const T2 *subFirst, const T2 *subLast) {\
    assert(first && last && subFirst && subLast);\
    \
    if (subFirst == subLast) {return last;}\
    \
    const T *ret = last;\
    for (;;) {\
        const T *temp = cxSearch2C(T, T2, first, last, subFirst, subLast);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEnd2F(T, T2, first, last, subFirst, subLast, p) CX_CHOOSE(cxFindEnd2FImpl, T, T2)(first, last, subFirst, subLast, p)
#define cxFindEnd2FImpl(T, T2)\
T *CX_MANGLE(cxFindEnd2FImpl, T, T2)(T *first, T *last, const T2 *subFirst, const T2 *subLast, bool(*p)(T, T2)) {\
    assert(first && last && subFirst && subLast && p);\
    \
    if (subFirst == subLast) {return last;}\
    \
    T *ret = last;\
    for (;;) {\
        T *temp = cxSearch2F(T, T2, first, last, subFirst, subLast, p);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEnd2CF(T, T2, first, last, subFirst, subLast, p) CX_CHOOSE(cxFindEnd2CFImpl, T, T2)(first, last, subFirst, subLast, p)
#define cxFindEnd2CFImpl(T, T2)\
const T *CX_MANGLE(cxFindEnd2CFImpl, T, T2)(const T *first, const T *last, const T2 *subFirst, const T2 *subLast, bool(*p)(T, T2)) {\
    assert(first && last && subFirst && subLast && p);\
    \
    if (subFirst == subLast) {return last;}\
    \
    const T *ret = last;\
    for (;;) {\
        const T *temp = cxSearch2CF(T, T2, first, last, subFirst, subLast, p);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEnd2DF(T, T2, T3, first, last, subFirst, subLast, p, data) CX_CHOOSE(cxFindEnd2DFImpl, T, T2, T3)(first, last, subFirst, subLast, p, data)
#define cxFindEnd2DFImpl(T, T2, T3)\
T *CX_MANGLE(cxFindEnd2DFImpl, T, T2, T3)(T *first, T *last, const T2 *subFirst, const T2 *subLast, bool(*p)(T, T2, T3), T3 data) {\
    assert(first && last && subFirst && subLast && p);\
    \
    if (subFirst == subLast) {return last;}\
    \
    T *ret = last;\
    for (;;) {\
        T *temp = cxSearch2DF(T, T2, T3, first, last, subFirst, subLast, p, data);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#define cxFindEnd2CDF(T, T2, T3, first, last, subFirst, subLast, p, data) CX_CHOOSE(cxFindEnd2CDFImpl, T, T2, T3)(first, last, subFirst, subLast, p, data)
#define cxFindEnd2CDFImpl(T, T2, T3)\
const T *CX_MANGLE(cxFindEnd2CDFImpl, T, T2, T3)(const T *first, const T *last, const T2 *subFirst, const T2 *subLast, bool(*p)(T, T2, T3), T3 data) {\
    assert(first && last && subFirst && subLast && p);\
    \
    if (subFirst == subLast) {return last;}\
    \
    const T *ret = last;\
    for (;;) {\
        const T *temp = cxSearch2CDF(T, T2, T3, first, last, subFirst, subLast, p, data);\
        \
        if (temp == last) {return ret;}\
        else {\
            ret = temp;\
            first = ret + 1;\
        }\
    }\
    \
    return ret;\
}

#endif
