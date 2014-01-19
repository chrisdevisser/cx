#pragma once
#ifndef CX_ALGORITHM_UNIQUECOPY_H
#define CX_ALGORITHM_UNIQUECOPY_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_UNIQUECOPY(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_UNIQUECOPY, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_UNIQUECOPY1(T)\
CX_USING(cxUniqueCopyF)

#define cxUniqueCopyF(T, first, last, out, p) CX_CHOOSE(cxUniqueCopyFImpl, T, T2)(first, last, out, p)
#define cxUniqueCopyFImpl(T)\
T2 *CX_MANGLE(cxUniqueCopyFImpl, T)(T *first, T *last, T *out, bool(*p)(T, T)) {\
    assert(first && last && p);\
    \
    if (first == last) {return out;}\
    \
    *out = *first;\
    while (++first != last) {\
        if (*out != *first) {*(++out) = *first;}\
    }\
    \
    return out;\
}

#endif
