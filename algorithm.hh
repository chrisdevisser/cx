//Huge credit for implementations goes to cppreference.com.

#pragma once
#ifndef CX_ALGORITHM_H
#define CX_ALGORITHM_H

//KEY
//2: 2 separate types instead of assuming same
//3: 3 separate types instead of assuming same
//C: Constant
//D: Data
//F: Function
//P: Pointer

//TODO

//Change == to memcmp
//Add versions for same T (e.g. cxSwap(T, T) => cxSwap(T))
//Modifying ForEach
//3 Mismatch
//3 Equal
//1 FindEnd
//3 FindFirstOf
//1 AdjacentFind
//1 Search
//1 SearchN
//1 Transform, any return type
//1 Unique
//1 UniqueCopy
//1 IsSorted
//1 IsSortedUntil
//1 Sort (and a better sort: qsort)
//*2 PartialSort
//*2 PartialSortCopy
//*2 StableSort
//1 UpperBound
//1 MaxElement
//1 MinElement

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "boost_pp/facilities/overload.hpp"

#include "compiler_diagnostics.hh"
#include "config.hh"
#include "preprocessor.hh"
#include "template.hh"
#include "type_utils.hh"
#include "utility.hh"

#include "algorithm/all_of.hh"
#include "algorithm/any_of.hh"
#include "algorithm/none_of.hh"
#include "algorithm/for_each.hh"
#include "algorithm/count.hh"
#include "algorithm/mismatch.hh"
#include "algorithm/equal.hh"
#include "algorithm/find.hh"
#include "algorithm/find_end.hh"
#include "algorithm/search.hh"
#include "algorithm/copy.hh"
#include "algorithm/copy_n.hh"
#include "algorithm/fill.hh"
#include "algorithm/fill_n.hh"
#include "algorithm/transform.hh"
#include "algorithm/swap.hh"
#include "algorithm/reverse.hh"
#include "algorithm/rotate.hh"
#include "algorithm/upper_bound.hh"
#include "algorithm/random_shuffle.hh"
#include "algorithm/sort.hh"
#include "algorithm/max.hh"
#include "algorithm/min.hh"
#include "algorithm/partition.hh"
#include "algorithm/adjacent_difference.hh"
#include "algorithm/unique.hh"

#define CX_ARRAY_LENGTH(arr) (sizeof (arr) / sizeof *(arr))
#define CX_BEGIN(arr) (arr)
#define CX_END(arr) ((arr) + CX_ARRAY_LENGTH(arr))

#define CX_USING_ONLY_ALGORITHM(...) BOOST_PP_OVERLOAD(CX_USING_ONLY_ALGORITHM, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ONLY_ALGORITHM1(T)\
CX_PRAGMA_PUSH \
CX_PRAGMA_IGNORE_STR("-Wfloat-equal") \
CX_USING_ALGORITHM_ALLOF(T) \
CX_USING_ALGORITHM_ANYOF(T) \
CX_USING_ALGORITHM_NONEOF(T) \
CX_USING_ALGORITHM_FOREACH(T) \
CX_USING_ALGORITHM_COUNT(T) \
CX_USING_ALGORITHM_MISMATCH(T) \
CX_USING_ALGORITHM_EQUAL(T) \
CX_USING_ALGORITHM_FIND(T) \
CX_USING_ALGORITHM_SEARCH(T) \
CX_USING_ALGORITHM_FINDEND(T) \
CX_USING_ALGORITHM_COPY(T) \
CX_USING_ALGORITHM_COPYN(T) \
CX_USING_ALGORITHM_FILL(T) \
CX_USING_ALGORITHM_FILLN(T) \
CX_USING_ALGORITHM_TRANSFORM(T) \
CX_USING_ALGORITHM_SWAP(T) \
CX_USING_ALGORITHM_REVERSE(T) \
CX_USING_ALGORITHM_ROTATE(T) \
CX_USING_ALGORITHM_UPPERBOUND(T) \
CX_USING_ALGORITHM_RANDOMSHUFFLE(T) \
CX_USING_ALGORITHM_SORT(T) \
CX_USING_ALGORITHM_MAX(T) \
CX_USING_ALGORITHM_MIN(T) \
CX_USING_ALGORITHM_PARTITION(T) \
CX_USING_ALGORITHM_UNIQUE(T) \
CX_PRAGMA_POP

#define CX_USING_ONLY_ALGORITHM2(T, T2)\
CX_PRAGMA_PUSH \
CX_PRAGMA_IGNORE_STR("-Wfloat-equal") \
CX_USING_ALGORITHM_ALLOF(T, T2) \
CX_USING_ALGORITHM_ANYOF(T, T2) \
CX_USING_ALGORITHM_NONEOF(T, T2) \
CX_USING_ALGORITHM_FOREACH(T, T2) \
CX_USING_ALGORITHM_COUNT(T, T2) \
CX_USING_ALGORITHM_MISMATCH(T, T2) \
CX_USING_ALGORITHM_EQUAL(T, T2) \
CX_USING_ALGORITHM_FIND(T, T2) \
CX_USING_ALGORITHM_SEARCH(T, T2) \
CX_USING_ALGORITHM_FINDEND(T, T2) \
CX_USING_ALGORITHM_COPY(T, T2) \
CX_USING_ALGORITHM_COPYN(T, T2) \
CX_USING_ALGORITHM_UPPERBOUND(T, T2) \
CX_USING_ALGORITHM_SORT(T, T2) \
CX_USING_ALGORITHM_SWAP(T, T2) \
CX_USING_ALGORITHM_ADJACENTDIFFERENCE(T, T2) \
CX_PRAGMA_POP

#define CX_USING_ONLY_ALGORITHM3(T, T2, T3)\
CX_PRAGMA_PUSH \
CX_PRAGMA_IGNORE_STR("-Wfloat-equal") \
CX_USING_ALGORITHM_MISMATCH(T, T2, T3) \
CX_USING_ALGORITHM_EQUAL(T, T2, T3) \
CX_USING_ALGORITHM_SEARCH(T, T2, T3) \
CX_USING_ALGORITHM_FINDEND(T, T2, T3) \
CX_USING_ALGORITHM_COPY(T, T2, T3) \
CX_PRAGMA_POP

#define CX_USING_ALGORITHM(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM1(T)\
CX_PTR_TYPEDEF(T); \
CX_CPTR_TYPEDEF(T); \
CX_USING_TYPE(cxPair, CX_PTR(T), CX_PTR(T)) \
CX_USING_TYPE(cxPair, CX_CPTR(T), CX_CPTR(T)) \
CX_USING(cxSortQsortFunction, T) \
CX_USING_ONLY_ALGORITHM(T)

#define CX_USING_ALGORITHM2(T, T2)\
CX_USING_ALGORITHM1(T) \
CX_PTR_TYPEDEF(T2); \
CX_CPTR_TYPEDEF(T2); \
CX_USING_TYPE(cxPair, CX_PTR(T), CX_PTR(T2)) \
CX_USING_TYPE(cxPair, CX_CPTR(T), CX_CPTR(T2)) \
CX_USING_ONLY_ALGORITHM(T, T2)

#define CX_USING_ALGORITHM3(T, T2, T3)\
CX_USING_ALGORITHM2(T, T2) \
CX_USING_ONLY_ALGORITHM(T, T2, T3)

#define cxFindFirstOf(T, T2, first, last, subFirst, subLast) CX_CHOOSE(cxFindFirstOfImpl, T, T2)(first, last, subFirst, subLast)
#define cxFindFirstOfImpl(T, T2)\
T *CX_MANGLE(cxFindFirstOfImpl, T, T2)(T *first, T *last, T2 *subFirst, T2 *subLast) {\
    for (; first != last; ++first) {\
        for (T2 *subIt = subFirst; subIt != subLast; ++subIt) {\
            if (*first == *subIt) {return first;}\
        }\
    }\
    \
    return last;\
}

#define cxAdjacentFind(T, first, last) CX_CHOOSE(cxAdjacentFindImpl, T)(first, last)
#define cxAdjacentFindImpl(T)\
T *CX_MANGLE(cxAdjacentFindImpl, T)(T *first, T *last) {\
    if (first == last) {return last;}\
    \
    for (T *next = first + 1; next != last; ++next, ++first) {\
        if (*first == *next) {return first;}\
    }\
}

#define cxSearchN(T, first, last, count, value) CX_CHOOSE(cxSearchNImpl, T)(first, last, count, value)
#define cxSearchNImpl(T)\
T *CX_MANGLE(cxSearchNImpl, T)(T *first, T *last, size_t count, T value) {\
    for (; first != last; ++first) {\
        if (*first != value) {continue;}\
        \
        T *candidate = first;\
        size_t soFar = 0;\
        \
        for (;;) {\
            if (++soFar == count) {return candidate;}\
            if (++first == last) {return last;}\
            if (*first != value) {break;}\
        }\
    }\
}

#define cxCopyBackward(T, T2, first, last, outLast) CX_CHOOSE(cxCopyBackwardImpl, T, T2)(first, last, outLast)
#define cxCopyBackwardImpl(T, T2)\
T2 *CX_MANGLE(cxCopyBackwardImpl, T, T2)(T *first, T *last, T2 *outLast) {\
    for (; first != last;) {\
        *(--outLast) = *(--last);\
    }\
}

#define cxGenerate(T, first, last, g) CX_CHOOSE(cxGenerateImpl, T)(first, last, g)
#define cxGenerateImpl(T)\
void CX_MANGLE(cxGenerateImpl, T)(T *first, T *last, T(*g)()) {\
    for (; first != last; ++first) {\
        *first = g();\
    }\
}

#define cxGenerateN(T, first, count, g) CX_CHOOSE(cxGenerateNImpl, T)(first, count, g)
#define cxGenerateNImpl(T)\
T *CX_MANGLE(cxGenerateNImpl, T)(T *first, size_t count, T(*g)()) {\
    for (size_t i = 0; i < count; ++i) {\
        *first = g();\
    }\
    \
    return first;\
}

#define cxRemove(T, first, last, value) CX_CHOOSE(cxRemoveImpl, T)(first, last, value)
#define cxRemoveImpl(T)\
T *CX_MANGLE(cxRemoveImpl, T)(T *first, T *last, T value) {\
    first = cxFind(T, first, last, value);\
    \
    if (first == last) {return first;}\
    \
    for (T *it = first; ++it != last;) {\
        if (*it != value) {*first++ = *it;}\
    }\
    \
    return first;\
}

#define cxRemoveIf(T, first, last, p) CX_CHOOSE(cxRemoveIfImpl, T)(first, last, p)
#define cxRemoveIfImpl(T)\
T *CX_MANGLE(cxRemoveIfImpl, T)(T *first, T *last, bool(*p)(T)) {\
    first = cxFindIf(T, first, last, p);\
    \
    if (first == last) {return first;}\
    \
    for (T *it = first; ++it != last;) {\
        if (!p(*it)) {*first++ = *it;}\
    }\
    \
    return first;\
}

#define cxRemoveCopy(T, T2, first, last, out, value) CX_CHOOSE(cxRemoveCopyImpl, T, T2)(first, last, out, value)
#define cxRemoveCopyImpl(T, T2)\
T2 *CX_MANGLE(cxRemoveCopyImpl, T, T2)(T *first, T *last, T2 *out, T value) {\
    for (; first != last; ++first) {\
        if (*first != value) {\
            *out++ = *first;\
        }\
    }\
    \
    return out;\
}

#define cxRemoveCopyIf(T, T2, first, last, out, p) CX_CHOOSE(cxRemoveCopyIfImpl, T, T2)(first, last, out, p)
#define cxRemoveCopyIfImpl(T, T2)\
T2 *CX_MANGLE(cxRemoveCopyIfImpl, T, T2)(T *first, T *last, T2 *out, bool(*p)(T)) {\
    for (; first != last; ++first) {\
        if (!p(*first)) {\
            *out++ = *first;\
        }\
    }\
    \
    return out;\
}

#define cxReplace(T, first, last, old, new) CX_CHOOSE(cxReplaceImpl, T)(first, last, old, new)
#define cxReplaceImpl(T)\
void CX_MANGLE(cxReplaceImpl, T)(T *first, T *last, T old, T new) {\
    for (; first != last; ++first) {\
        if (*first == old) {*first = new;}\
    }\
}

#define cxReplaceIf(T, first, last, p, new) CX_CHOOSE(cxReplaceIfImpl, T)(first, last, p, new)
#define cxReplaceIfImpl(T)\
void CX_MANGLE(cxReplaceIfImpl, T)(T *first, T *last, bool(*p)(T), T new) {\
    for (; first != last; ++first) {\
        if (p(*first)) {*first = new;}\
    }\
}

#define cxReplaceCopy(T, T2, first, last, out, old, new) CX_CHOOSE(cxReplaceCopyImpl, T, T2)(first, last, out, old, new)
#define cxReplaceCopyImpl(T, T2)\
T2 *CX_MANGLE(cxReplaceCopyImpl, T, T2)(T *first, T *last, T2 *out, T old, T new) {\
    for (; first != last; ++first) {\
        *out++ = (*first == old) ? new : *first;\
    }\
    \
    return out;\
}

#define cxReplaceCopyIf(T, T2, first, last, out, p, new) CX_CHOOSE(cxReplaceCopyIfImpl, T, T2)(first, last, out, p, new)
#define cxReplaceCopyIfImpl(T, T2)\
T2 *CX_MANGLE(cxReplaceCopyIfImpl, T, T2)(T *first, T *last, T2 *out, bool(*p)(T), T new) {\
    for (; first != last; ++first) {\
        *out++ = p(*first) ? new : *first;\
    }\
    \
    return out;\
}

#define cxSwapRanges(T, T2, first, last, first2) CX_CHOOSE(cxSwapRangesImpl, T, T2)(first, last, first2)
#define cxSwapRangesImpl(T, T2)\
T2 *CX_MANGLE(cxSwapRangesImpl, T, T2)(T *first, T *last, T2 *first2) {\
    for (; first != last; ++first) {\
        cxSwap(T, T2, first, first2++);\
    }\
    \
    return out;\
}

#define cxReverseCopy(T, T2, first, last, out) CX_CHOOSE(cxReverseCopyImpl, T, T2)(first, last, out)
#define cxReverseCopyImpl(T, T2)\
T2 *CX_MANGLE(cxReverseCopyImpl, T, T2)(T *first, T *last, T2 *out) {\
    while (first != last) {\
        *(out++) = *(--last);\
    }\
    \
    return out;\
}

#define cxRotateCopy(T, T2, first, newFirst, last, out) CX_CHOOSE(cxRotateCopyImpl, T, T2)(first, newFirst, last, out)
#define cxRotateCopyImpl(T, T2)\
T2 *CX_MANGLE(cxRotateCopyImpl, T, T2)(T *first, T *newFirst, T *last, T2 *out) {\
    out = cxCopy(T, T2, newFirst, last, out);\
    return cxCopy(T, T2, first, newFirst, out);\
}

#define cxIsPartitioned(T, first, last, p) CX_CHOOSE(cxIsPartitionedImpl, T)(first, last, p)
#define cxIsPartitionedImpl(T)\
bool CX_MANGLE(cxIsPartitionedImpl, T)(T *first, T *last, bool(*p)(T)) {\
    for (; first != last; ++first) {\
        if (!p(*first)) {break;}\
    }\
    \
    for (; first != last; ++first) {\
        if (p(*first)) {return false;}\
    }\
    \
    return true;\
}

#define cxPartitionCopy(T, T2, T3, T2Ptr, T3Ptr, first, last, outTrue, outFalse, p) CX_CHOOSE(cxPartitionCopyImpl, T, T2, T3, T2Ptr, T3Ptr)(first, last, outTrue, outFalse, p)
#define cxPartitionCopyImpl(T, T2, T3, T2Ptr, T3Ptr)\
cxPair(T2Ptr, T3Ptr) CX_MANGLE(cxPartitionCopyImpl, T, T2, T3, T2Ptr, T3Ptr)(T *first, T *last, T2 *outTrue, T3 *outFalse, bool(*p)(T)) {\
    for (; first != last; ++first) {\
        if (p(*first)) {*outTrue++ = *first;}\
        else {*outFalse++ = *first;}\
    }\
    \
    return (cxPair(T2Ptr, T3Ptr)){outTrue, outFalse};\
}

#define cxStablePartition(T, first, last, p) CX_CHOOSE(cxStablePartitionImpl, T)(first, last, p)
#define cxStablePartitionImpl(T)\
T *CX_MANGLE(cxStablePartitionImpl, T)(T *first, T *last, bool(*p)(T)) {\
    for (T *it = first;;) {\
        while ((first != last) && p(*first)) {++first;}\
        if (first == last) {break;}\
        \
        if (it <= first) {it = first + 1;}\
        while ((it != last) && !p(*it)) {++it;}\
        if (it == last) {break;}\
        \
        cxSwap(T, T, first++, it++);\
    }\
    \
    return first;\
}

#define cxPartitionPoint(T, first, last, p) CX_CHOOSE(cxPartitionPointImpl, T)(first, last, p)
#define cxPartitionPointImpl(T)\
T *CX_MANGLE(cxPartitionPointImpl, T)(T *first, T *last, bool(*p)(T)) {\
    while ((first != last) && p(*first)) {++first;}\
    return first;\
}

#define cxIsSorted(T, first, last) CX_CHOOSE(cxIsSortedImpl, T)(first, last)
#define cxIsSortedImpl(T)\
bool CX_MANGLE(cxIsSortedImpl, T)(T *first, T *last) {\
    return cxIsSortedUntil(T, first, last) == last;\
}

#define cxIsSortedUntil(T, first, last) CX_CHOOSE(cxIsSortedUntilImpl, T)(first, last)
#define cxIsSortedUntilImpl(T)\
T *CX_MANGLE(cxIsSortedImpl, T)(T *first, T *last) {\
    if (first == last) {return last;}\
    \
    for (T *it = first; ++it != last;) {\
        if (*it < *first) {return it;}\
        first = it;\
    }\
    \
    return last;\
}

#define cxPartialSort(T, first, middle, last) CX_CHOOSE(cxPartialSortImpl, T)(first, middle, last)
#define cxPartialSortImpl(T)\
void CX_MANGLE(cxPartialSortImpl, T)(T *first, T *middle, T *last) {\

#define cxMaxElement(T, first, last) CX_CHOOSE(cxMaxElementImpl, T)(first, last)
#define cxMaxElementImpl(T)\
T *CX_MANGLE(cxMaxElementImpl, T)(T *first, T *last) {\
    if (first == last) {return last;}\
    \
    T *ret = first++;\
    for (; first != last; ++first) {\
        if (*ret < *first) {ret = first;}\
    }\
    \
    return ret;\
}

#define cxMinElement(T, first, last) CX_CHOOSE(cxMinElementImpl, T)(first, last)
#define cxMinElementImpl(T)\
T *CX_MANGLE(cxMinElementImpl, T)(T *first, T *last) {\
    if (first == last) {return last;}\
    \
    T *ret = first++;\
    for (; first != last; ++first) {\
        if (*first < *ret) {ret = first;}\
    }\
    \
    return ret;\
}

#endif
