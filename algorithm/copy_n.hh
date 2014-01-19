#pragma once
#ifndef CX_ALGORITHM_COPYN_H
#define CX_ALGORITHM_COPYN_H

#include <assert.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_COPYN(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_COPYN, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_COPYN1(T)\
CX_USING(cxCopyN, T)

#define CX_USING_ALGORITHM_COPYN2(T, T2)\
CX_USING(cxCopyN2, T, T2)

#define cxCopyN(T, first, count, out) CX_CHOOSE(cxCopyNImpl, T)(first, count, out)
#define cxCopyNImpl(T)\
T *CX_MANGLE(cxCopyNImpl, T)(T *first, size_t count, T *out) {\
    assert(first && out);\
    \
    if (count <= 0) {return out;}\
    \
    for (size_t i = 0; i < count; ++i) {\
        *out++ = *first++;\
    }\
    \
    return out;\
}

#define cxCopyN2(T, T2, first, count, out) CX_CHOOSE(cxCopyN2Impl, T, T2)(first, count, out)
#define cxCopyN2Impl(T, T2)\
T2 *CX_MANGLE(cxCopyN2Impl, T, T2)(T *first, size_t count, T2 *out) {\
    assert(first && out);\
    \
    if (count <= 0) {return out;}\
    \
    for (size_t i = 0; i < count; ++i) {\
        *out++ = *first++;\
    }\
    \
    return out;\
}

#endif

