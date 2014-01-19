#pragma once
#ifndef CX_ALGORITHM_ROTATE_H
#define CX_ALGORITHM_ROTATE_H

#include <assert.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"
#include "swap.hh"

#define CX_USING_ALGORITHM_ROTATE(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_ROTATE, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_ROTATE1(T)\
CX_USING(cxRotate, T)

#define cxRotate(T, first, newFirst, last) CX_CHOOSE(cxRotateImpl, T)(first, newFirst, last)
#define cxRotateImpl(T)\
void CX_MANGLE(cxRotateImpl, T)(T *first, T *newFirst, T *last) {\
    assert(first && newFirst && last);\
    \
    T *next = newFirst;\
    \
    while (first != next) {\
        cxSwap(T, first++, next++);\
        \
        if (next == last) {next = newFirst;}\
        else if (first == newFirst) {newFirst = next;}\
    }\
}

#endif
