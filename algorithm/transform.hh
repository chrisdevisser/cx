#pragma once
#ifndef CX_ALGORITHM_TRANSFORM_H
#define CX_ALGORITHM_TRANSFORM_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_TRANSFORM(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_TRANSFORM, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_TRANSFORM1(T)\
CX_USING(cxTransform, T)\
CX_USING(cxTransformDual, T)

#define cxTransform(T, first, last, out, f) CX_CHOOSE(cxTransformImpl, T)(first, last, out, f)
#define cxTransformImpl(T)\
T *CX_MANGLE(cxTransformImpl, T)(T *first, T *last, T *out, T(*f)(T)) {\
    assert(first && last && out && f);\
    \
    while (first != last) {\
        *out++ = f(*first++);\
    }\
    \
    return out;\
}

#define cxTransformDual(T, first, last, first2, out, f) CX_CHOOSE(cxTransformDualImpl, T)(first, last, first2, out, f)
#define cxTransformDualImpl(T)\
T *CX_MANGLE(cxTransformDualImpl, T)(T *first, T *last, T *first2, T *out, T(*f)(T, T)) {\
    assert(first && last && out && f);\
    \
    while (first != last) {\
        *out++ = f(*first++, *first2++);\
    }\
    \
    return out;\
}

#endif
