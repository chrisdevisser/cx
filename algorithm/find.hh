#pragma once
#ifndef CX_ALGORITHM_FIND_H
#define CX_ALGORITHM_FIND_H

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_FIND(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_FIND, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_FIND1(T)\
CX_USING(cxFind, T)\
CX_USING(cxFindIf, T)\
CX_USING(cxFindC, T)\
CX_USING(cxFindIfC, T)

#define CX_USING_ALGORITHM_FIND2(T, T2)\
CX_USING(cxFindIfD, T, T2)\
CX_USING(cxFindIfCD, T, T2)

#define cxFind(T, first, last, value) CX_CHOOSE(cxFindImpl, T)(first, last, value)
#define cxFindImpl(T)\
T *CX_MANGLE(cxFindImpl, T)(T *first, T *last, T value) {\
    for (; first != last; ++first) {\
        if (*first == value) {return first;}\
    }\
    \
    return last;\
}

#define cxFindIf(T, first, last, p) CX_CHOOSE(cxFindIfImpl, T)(first, last, p)
#define cxFindIfImpl(T)\
T *CX_MANGLE(cxFindIfImpl, T)(T *first, T *last, bool(*p)(T)) {\
    for (; first != last; ++first) {\
        if (p(*first)) {return first;}\
    }\
    \
    return last;\
}

#define cxFindC(T, first, last, value) CX_CHOOSE(cxFindCImpl, T)(first, last, value)
#define cxFindCImpl(T)\
const T *CX_MANGLE(cxFindCImpl, T)(const T *first, const T *last, T value) {\
    for (; first != last; ++first) {\
        if (*first == value) {return first;}\
    }\
    \
    return last;\
}

#define cxFindIfC(T, first, last, p) CX_CHOOSE(cxFindIfCImpl, T)(first, last, p)
#define cxFindIfCImpl(T)\
const T *CX_MANGLE(cxFindIfCImpl, T)(const T *first, const T *last, bool(*p)(T)) {\
    for (; first != last; ++first) {\
        if (p(*first)) {return first;}\
    }\
    \
    return last;\
}

#define cxFindIfD(T, T2, first, last, p, data) CX_CHOOSE(cxFindIfDImpl, T, T2)(first, last, p, data)
#define cxFindIfDImpl(T, T2)\
T *CX_MANGLE(cxFindIfDImpl, T, T2)(T *first, T *last, bool(*p)(T, T2), T2 data) {\
    for (; first != last; ++first) {\
        if (p(*first, data)) {return first;}\
    }\
    \
    return last;\
}

#define cxFindIfCD(T, T2, first, last, p, data) CX_CHOOSE(cxFindIfCDImpl, T, T2)(first, last, p, data)
#define cxFindIfCDImpl(T, T2)\
const T *CX_MANGLE(cxFindIfCDImpl, T, T2)(const T *first, const T *last, bool(*p)(T, T2), T2 data) {\
    for (; first != last; ++first) {\
        if (p(*first, data)) {return first;}\
    }\
    \
    return last;\
}

#endif
