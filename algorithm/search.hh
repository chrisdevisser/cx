#pragma once
#ifndef CX_ALGORITHM_SEARCH_H
#define CX_ALGORITHM_SEARCH_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_SEARCH(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_SEARCH, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_SEARCH1(T)\
CX_USING(cxSearch, T)\
CX_USING(cxSearchC, T)\
CX_USING(cxSearchF, T)\
CX_USING(cxSearchCF, T)

#define CX_USING_ALGORITHM_SEARCH2(T, T2)\
CX_USING(cxSearchDF, T, T2)\
CX_USING(cxSearchCDF, T, T2)\
CX_USING(cxSearch2, T, T2)\
CX_USING(cxSearch2C, T, T2)\
CX_USING(cxSearch2CF, T, T2)

#define CX_USING_ALGORITHM_SEARCH3(T, T2, T3)\
CX_USING(cxSearch2DF, T, T2, T3)\
CX_USING(cxSearch2CDF, T, T2, T3)

#define cxSearch(T, first, last, subFirst, subLast) CX_CHOOSE(cxSearchImpl, T)(first, last, subFirst, subLast)
#define cxSearchImpl(T)\
T *CX_MANGLE(cxSearchImpl, T)(T *first, T *last, const T *subFirst, const T *subLast) {\
    assert(first && last && subFirst && subLast);\
    \
    for (;; ++first) {\
        T *it = first;\
        \
        for (const T *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (*it != *subIt) {break;}\
        }\
    }\
}

#define cxSearchC(T, first, last, subFirst, subLast) CX_CHOOSE(cxSearchCImpl, T)(first, last, subFirst, subLast)
#define cxSearchCImpl(T)\
const T *CX_MANGLE(cxSearchCImpl, T)(const T *first, const T *last, const T *subFirst, const T *subLast) {\
    assert(first && last && subFirst && subLast);\
    \
    for (;; ++first) {\
        const T *it = first;\
        \
        for (const T *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (*it != *subIt) {break;}\
        }\
    }\
}

#define cxSearchF(T, first, last, subFirst, subLast, p) CX_CHOOSE(cxSearchFImpl, T)(first, last, subFirst, subLast, p)
#define cxSearchFImpl(T)\
T *CX_MANGLE(cxSearchFImpl, T)(T *first, T *last, const T *subFirst, const T *subLast, bool(*p)(T, T)) {\
    assert(first && last && subFirst && subLast && p);\
    \
    for (;; ++first) {\
        T *it = first;\
        \
        for (const T *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (!p(*it, *subIt)) {break;}\
        }\
    }\
}

#define cxSearchCF(T, first, last, subFirst, subLast, p) CX_CHOOSE(cxSearchCFImpl, T)(first, last, subFirst, subLast, p)
#define cxSearchCFImpl(T)\
const T *CX_MANGLE(cxSearchCFImpl, T)(const T *first, const T *last, const T *subFirst, const T *subLast, bool(*p)(T, T)) {\
    assert(first && last && subFirst && subLast && p);\
    \
    for (;; ++first) {\
        const T *it = first;\
        \
        for (const T *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (!p(*it, *subIt)) {break;}\
        }\
    }\
}

#define cxSearchDF(T, T2, first, last, subFirst, subLast, p, data) CX_CHOOSE(cxSearchDFImpl, T, T2)(first, last, subFirst, subLast, p, data)
#define cxSearchDFImpl(T, T2)\
T *CX_MANGLE(cxSearchDFImpl, T, T2)(T *first, T *last, const T *subFirst, const T *subLast, bool(*p)(T, T, T2), T2 data) {\
    assert(first && last && subFirst && subLast && p);\
    \
    for (;; ++first) {\
        T *it = first;\
        \
        for (const T *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (!p(*it, *subIt, data)) {break;}\
        }\
    }\
}

#define cxSearchCDF(T, T2, first, last, subFirst, subLast, p, data) CX_CHOOSE(cxSearchCDFImpl, T, T2)(first, last, subFirst, subLast, p, data)
#define cxSearchCDFImpl(T, T2)\
const T *CX_MANGLE(cxSearchCDFImpl, T, T2)(const T *first, const T *last, const T *subFirst, const T *subLast, bool(*p)(T, T, T2), T2 data) {\
    assert(first && last && subFirst && subLast && p);\
    \
    for (;; ++first) {\
        const T *it = first;\
        \
        for (const T *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (!p(*it, *subIt, data)) {break;}\
        }\
    }\
}

#define cxSearch2(T, T2, first, last, subFirst, subLast) CX_CHOOSE(cxSearch2Impl, T, T2)(first, last, subFirst, subLast)
#define cxSearch2Impl(T, T2)\
T *CX_MANGLE(cxSearch2Impl, T, T2)(T *first, T *last, const T2 *subFirst, const T2 *subLast) {\
    assert(first && last && subFirst && subLast);\
    \
    for (;; ++first) {\
        T *it = first;\
        \
        for (const T2 *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (*it != *subIt) {break;}\
        }\
    }\
}

#define cxSearch2C(T, T2, first, last, subFirst, subLast) CX_CHOOSE(cxSearch2CImpl, T, T2)(first, last, subFirst, subLast)
#define cxSearch2CImpl(T, T2)\
const T *CX_MANGLE(cxSearch2CImpl, T, T2)(const T *first, const T *last, const T2 *subFirst, const T2 *subLast) {\
    assert(first && last && subFirst && subLast);\
    \
    for (;; ++first) {\
        const T *it = first;\
        \
        for (const T2 *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (*it != *subIt) {break;}\
        }\
    }\
}

#define cxSearch2F(T, T2, first, last, subFirst, subLast, p) CX_CHOOSE(cxSearch2FImpl, T, T2)(first, last, subFirst, subLast, p)
#define cxSearch2FImpl(T, T2)\
T *CX_MANGLE(cxSearch2FImpl, T, T2)(T *first, T *last, const T2 *subFirst, const T2 *subLast, bool(*p)(T, T2)) {\
    assert(first && last && subFirst && subLast && p);\
    \
    for (;; ++first) {\
        T *it = first;\
        \
        for (const T2 *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (!p(*it, *subIt)) {break;}\
        }\
    }\
}

#define cxSearch2CF(T, T2, first, last, subFirst, subLast, p) CX_CHOOSE(cxSearch2CFImpl, T, T2)(first, last, subFirst, subLast, p)
#define cxSearch2CFImpl(T, T2)\
const T *CX_MANGLE(cxSearch2CFImpl, T, T2)(const T *first, const T *last, const T2 *subFirst, const T2 *subLast, bool(*p)(T, T2)) {\
    assert(first && last && subFirst && subLast && p);\
    \
    for (;; ++first) {\
        const T *it = first;\
        \
        for (const T2 *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (!p(*it, *subIt)) {break;}\
        }\
    }\
}

#define cxSearch2DF(T, T2, T3, first, last, subFirst, subLast, p, data) CX_CHOOSE(cxSearch2DFImpl, T, T2, T3)(first, last, subFirst, subLast, p, data)
#define cxSearch2DFImpl(T, T2, T3)\
T *CX_MANGLE(cxSearch2DFImpl, T, T2, T3)(T *first, T *last, const T2 *subFirst, const T2 *subLast, bool(*p)(T, T2, T3), T3 data) {\
    assert(first && last && subFirst && subLast && p);\
    \
    for (;; ++first) {\
        T *it = first;\
        \
        for (const T2 *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (!p(*it, *subIt, data)) {break;}\
        }\
    }\
}

#define cxSearch2CDF(T, T2, T3, first, last, subFirst, subLast, p, data) CX_CHOOSE(cxSearch2CDFImpl, T, T2, T3)(first, last, subFirst, subLast, p, data)
#define cxSearch2CDFImpl(T, T2, T3)\
const T *CX_MANGLE(cxSearch2CDFImpl, T, T2, T3)(const T *first, const T *last, const T2 *subFirst, const T2 *subLast, bool(*p)(T, T2, T3), T3 data) {\
    assert(first && last && subFirst && subLast && p);\
    \
    for (;; ++first) {\
        const T *it = first;\
        \
        for (const T2 *subIt = subFirst;; ++it, ++subIt) {\
            if (subIt == subLast) {return first;}\
            if (it == last) {return last;}\
            if (!p(*it, *subIt, data)) {break;}\
        }\
    }\
}


#endif
