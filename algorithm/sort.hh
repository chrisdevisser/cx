#pragma once
#ifndef CX_ALGORITHM_SORT_H
#define CX_ALGORITHM_SORT_H

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"
#include "rotate.hh"
#include "upper_bound.hh"

#define CX_USING_ALGORITHM_SORT(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_SORT, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_SORT1(T)\
CX_USING(cxSort, T)\
CX_USING(cxSortF, T)

#define CX_USING_ALGORITHM_SORT2(T, T2)\
CX_USING(cxSortDF, T, T2)

#define cxSortQsortFunction(T, a, b) CX_CHOOSE(cxSortQsortFunctionImpl, T)(a, b)
#define cxSortQsortFunctionImpl(T)\
int CX_MANGLE(cxSortQsortFunctionImpl, T)(const void *a, const void *b) {\
    return *(T *)a - *(T *)b;\
}

#define cxSort(T, first, last) CX_CHOOSE(cxSortImpl, T)(first, last)
#define cxSortImpl(T)\
void CX_MANGLE(cxSortImpl, T)(T *first, T *last) {\
    assert(first && last);\
    \
    qsort(first, last - first, sizeof *first, CX_CHOOSE(cxSortQsortFunctionImpl, T));\
}

#define cxSortF(T, first, last, p) CX_CHOOSE(cxSortFImpl, T)(first, last, p)
#define cxSortFImpl(T)\
void CX_MANGLE(cxSortFImpl, T)(T *first, T *last, bool(*p)(T, T)) {\
    assert(first && last && p);\
    \
    for (T *it = first; it != last; ++it) {\
        cxRotate(T, cxUpperBoundF(T, first, it, *it, p), it, it+1);\
    }\
}

#define cxSortDF(T, T2, first, last, p, data) CX_CHOOSE(cxSortDFImpl, T, T2)(first, last, p, data)
#define cxSortDFImpl(T, T2)\
void CX_MANGLE(cxSortDFImpl, T, T2)(T *first, T *last, bool(*p)(T, T, T2), T2) {\
    assert(first && last && p);\
    \
    for (T *it = first; it != last; ++it) {\
        cxRotate(T, cxUpperBoundDF(T, T2, first, it, *it, p, data), it, it+1);\
    }\
}

#endif

