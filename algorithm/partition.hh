#pragma once
#ifndef CX_ALGORITHM_PARTITION_H
#define CX_ALGORITHM_PARTITION_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_PARTITION(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_PARTITION, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_PARTITION1(T)\
CX_USING(cxPartition, T)

#define cxPartition(T, first, last, p) CX_CHOOSE(cxPartitionImpl, T)(first, last, p)
#define cxPartitionImpl(T)\
T *CX_MANGLE(cxPartitionImpl, T)(T *first, T *last, bool(*p)(T)) {\
    assert(first && last && p);\
    \
    for (;;) {\
        while ((first != last) && p(*first)) {++first;}\
        if (first == last--) {break;}\
        \
        while ((first != last) && !p(*last)) {--last;}\
        if (first == last) {break;}\
        \
        cxSwap(T, T, first++, last);\
    }\
    \
    return first;\
}

#endif

