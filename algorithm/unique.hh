#pragma once
#ifndef CX_ALGORITHM_UNIQUE_H
#define CX_ALGORITHM_UNIQUE_H

#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_UNIQUE(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_UNIQUE, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_UNIQUE1(T)\
CX_USING(cxUnique, T)\
CX_USING(cxUniqueF, T)

#define cxUnique(T, first, last) CX_CHOOSE(cxUniqueImpl, T)(first, last)
#define cxUniqueImpl(T)\
T *CX_MANGLE(cxUniqueImpl, T)(T *first, T *last) {\
    assert(first && last);\
    \
    if (first == last) {return last;}\
    \
    T *ret = first;\
    while (++first != last) {\
        if (memcmp(ret, first, sizeof(T)) != 0) {*(++ret) = *first;}\
    }\
    \
    return ++ret;\
}

#define cxUniqueF(T, first, last, p) CX_CHOOSE(cxUniqueFImpl, T)(first, last, p)
#define cxUniqueFImpl(T)\
T *CX_MANGLE(cxUniqueFImpl, T)(T *first, T *last, bool(*p)(T, T)) {\
    assert(first && last && p);\
    \
    if (first == last) {return last;}\
    \
    T *ret = first;\
    while (++first != last) {\
        if (!p(*ret, *first)) {*(++ret) = *first;}\
    }\
    \
    return ++ret;\
}

#endif

