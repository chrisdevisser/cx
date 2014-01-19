#pragma once
#ifndef CX_ALGORITHM_COPY_H
#define CX_ALGORITHM_COPY_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_COPY(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_COPY, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_COPY1(T)\
CX_USING(cxCopy, T)\
CX_USING(cxCopyIf, T)\

#define CX_USING_ALGORITHM_COPY2(T, T2)\
CX_USING(cxCopyIfD, T, T2)\
CX_USING(cxCopy2, T, T2)\
CX_USING(cxCopyIf2, T, T2)\

#define CX_USING_ALGORITHM_COPY3(T, T2, T3)\
CX_USING(cxCopyIf2D, T, T2, T3)\

#define cxCopy(T, first, last, out) CX_CHOOSE(cxCopyImpl, T)(first, last, out)
#define cxCopyImpl(T)\
T *CX_MANGLE(cxCopyImpl, T)(const T *first, const T *last, T *out) {\
    assert(first && last && out);\
    \
    while (first != last) {\
        *out++ = *first++;\
    }\
    \
    return out;\
}

#define cxCopyIf(T, first, last, out, p) CX_CHOOSE(cxCopyIfImpl, T)(first, last, out, p)
#define cxCopyIfImpl(T)\
T *CX_MANGLE(cxCopyIfImpl, T)(const T *first, const T *last, T *out, bool(*p)(T)) {\
    assert(first && last && out && p);\
    \
    while (first != last) {\
        if (p(*first)) {*out++ = *first;}\
        ++first;\
    }\
    \
    return out;\
}

#define cxCopyIfD(T, T2, first, last, out, p, data) CX_CHOOSE(cxCopyIfDImpl, T, T2)(first, last, out, p, data)
#define cxCopyIfDImpl(T, T2)\
T *CX_MANGLE(cxCopyIfDImpl, T, T2)(const T *first, const T *last, T *out, bool(*p)(T, T2), T2 data) {\
    assert(first && last && out && p);\
    \
    while (first != last) {\
        if (p(*first, data)) {*out++ = *first;}\
        ++first;\
    }\
    \
    return out;\
}

#define cxCopy2(T, T2, first, last, out) CX_CHOOSE(cxCopy2Impl, T, T2)(first, last, out)
#define cxCopy2Impl(T, T2)\
T2 *CX_MANGLE(cxCopy2Impl, T, T2)(const T *first, const T *last, T2 *out) {\
    assert(first && last && out);\
    \
    while (first != last) {\
        *out++ = *first++;\
    }\
    \
    return out;\
}

#define cxCopyIf2(T, T2, first, last, out, p) CX_CHOOSE(cxCopyIf2Impl, T, T2)(first, last, out, p)
#define cxCopyIf2Impl(T, T2)\
T2 *CX_MANGLE(cxCopyIf2Impl, T, T2)(const T *first, const T *last, T2 *out, bool(*p)(T)) {\
    assert(first && last && out && p);\
    \
    while (first != last) {\
        if (p(*first)) {*out++ = *first;}\
        ++first;\
    }\
    \
    return out;\
}

#define cxCopyIf2D(T, T2, T3, first, last, out, p, data) CX_CHOOSE(cxCopyIf2DImpl, T, T2, T3)(first, last, out, p, data)
#define cxCopyIf2DImpl(T, T2, T3)\
T2 *CX_MANGLE(cxCopyIf2DImpl, T, T2, T3)(const T *first, const T *last, T2 *out, bool(*p)(T, T3), T3 data) {\
    assert(first && last && out && p);\
    \
    while (first != last) {\
        if (p(*first, data)) {*out++ = *first;}\
        ++first;\
    }\
    \
    return out;\
}

#endif
