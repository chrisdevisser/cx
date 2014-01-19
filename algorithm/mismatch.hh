#pragma once
#ifndef CX_ALGORITHM_MISMATCH_H
#define CX_ALGORITHM_MISMATCH_H

#include <assert.h>
#include <stdbool.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"
#include "../type_utils.hh"
#include "../utility.hh"

#define CX_USING_ALGORITHM_MISMATCH(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_MISMATCH, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_MISMATCH1(T)\
CX_USING(cxMismatch, T)\
CX_USING(cxMismatchC, T)\
CX_USING(cxMismatchF, T)\
CX_USING(cxMismatchCF, T)

#define CX_USING_ALGORITHM_MISMATCH2(T, T2)\
CX_USING(cxMismatchDF, T, T2)\
CX_USING(cxMismatchCDF, T, T2)\
CX_USING(cxMismatch2, T, T2)\
CX_USING(cxMismatch2C, T, T2)\
CX_USING(cxMismatch2F, T, T2)\
CX_USING(cxMismatch2CF, T, T2)

#define CX_USING_ALGORITHM_MISMATCH3(T, T2, T3)\
CX_USING(cxMismatch2DF, T, T2, T3)\
CX_USING(cxMismatch2CDF, T, T2, T3)

#define cxMismatch(T, first, last, first2) CX_CHOOSE(cxMismatchImpl, T)(first, last, first2)
#define cxMismatchImpl(T)\
cxPair(CX_PTR(T), CX_PTR(T)) CX_MANGLE(cxMismatchImpl, T)(T *first, T *last, T *first2) {\
    assert(first && last && first2);\
    \
    while (first != last && *first == *first2) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_PTR(T), CX_PTR(T))){first, first2};\
}

#define cxMismatchC(T, first, last, first2) CX_CHOOSE(cxMismatchCImpl, T)(first, last, first2)
#define cxMismatchCImpl(T)\
cxPair(CX_CPTR(T), CX_CPTR(T)) CX_MANGLE(cxMismatchCImpl, T)(const T *first, const T *last, const T *first2) {\
    assert(first && last && first2);\
    \
    while (first != last && *first == *first2) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_CPTR(T), CX_CPTR(T))){first, first2};\
}

#define cxMismatchF(T, first, last, first2, p) CX_CHOOSE(cxMismatchFImpl, T)(first, last, first2, p)
#define cxMismatchFImpl(T)\
cxPair(CX_PTR(T), CX_PTR(T)) CX_MANGLE(cxMismatchFImpl, T)(T *first, T *last, T *first2, bool(*p)(T, T)) {\
    assert(first && last && first2 && p);\
    \
    while (first != last && p(*first, *first2)) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_PTR(T), CX_PTR(T))){first, first2};\
}

#define cxMismatchCF(T, first, last, first2, p) CX_CHOOSE(cxMismatchCFImpl, T)(first, last, first2, p)
#define cxMismatchCFImpl(T)\
cxPair(CX_CPTR(T), CX_CPTR(T)) CX_MANGLE(cxMismatchCFImpl, T)(const T *first, const T *last, const T *first2, bool(*p)(T, T)) {\
    assert(first && last && first2 && p);\
    \
    while (first != last && p(*first, *first2)) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_CPTR(T), CX_CPTR(T))){first, first2};\
}

#define cxMismatchDF(T, T2, first, last, first2, p, data) CX_CHOOSE(cxMismatchDFImpl, T, T2)(first, last, first2, p, data)
#define cxMismatchDFImpl(T, T2)\
cxPair(CX_PTR(T), CX_PTR(T)) CX_MANGLE(cxMismatchDFImpl, T, T2)(T *first, T *last, T *first2, bool(*p)(T, T, T2), T2 data) {\
    assert(first && last && first2 && p);\
    \
    while (first != last && p(*first, *first2, data)) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_PTR(T), CX_PTR(T))){first, first2};\
}

#define cxMismatchCDF(T, T2, first, last, first2, p, data) CX_CHOOSE(cxMismatchCDFImpl, T, T2)(first, last, first2, p, data)
#define cxMismatchCDFImpl(T, T2)\
cxPair(CX_CPTR(T), CX_CPTR(T)) CX_MANGLE(cxMismatchCDFImpl, T, T2)(const T *first, const T *last, const T *first2, bool(*p)(T, T, T2), T2 data) {\
    assert(first && last && first2 && p);\
    \
    while (first != last && p(*first, *first2, data)) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_CPTR(T), CX_CPTR(T))){first, first2};\
}

#define cxMismatch2(T, T2, first, last, first2) CX_CHOOSE(cxMismatch2Impl, T, T2)(first, last, first2)
#define cxMismatch2Impl(T, T2)\
cxPair(CX_PTR(T), CX_PTR(T2)) CX_MANGLE(cxMismatch2Impl, T, T2)(T *first, T *last, T2 *first2) {\
    assert(first && last && first2);\
    \
    while (first != last && *first == *first2) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_PTR(T), CX_PTR(T2))){first, first2};\
}

#define cxMismatch2C(T, T2, first, last, first2) CX_CHOOSE(cxMismatch2CImpl, T, T2)(first, last, first2)
#define cxMismatch2CImpl(T, T2)\
cxPair(CX_CPTR(T), CX_CPTR(T2)) CX_MANGLE(cxMismatch2CImpl, T, T2)(const T *first, const T *last, const T2 *first2) {\
    assert(first && last && first2);\
    \
    while (first != last && *first == *first2) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_CPTR(T), CX_CPTR(T2))){first, first2};\
}

#define cxMismatch2F(T, T2, first, last, first2, p) CX_CHOOSE(cxMismatch2FImpl, T, T2)(first, last, first2, p)
#define cxMismatch2FImpl(T, T2)\
cxPair(CX_PTR(T), CX_PTR(T2)) CX_MANGLE(cxMismatch2FImpl, T, T2)(T *first, T *last, T2 *first2, bool(*p)(T, T2)) {\
    assert(first && last && first2 && p);\
    \
    while (first != last && p(*first, *first2)) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_PTR(T), CX_PTR(T2))){first, first2};\
}

#define cxMismatch2CF(T, T2, first, last, first2, p) CX_CHOOSE(cxMismatch2CFImpl, T, T2)(first, last, first2, p)
#define cxMismatch2CFImpl(T, T2)\
cxPair(CX_CPTR(T), CX_CPTR(T2)) CX_MANGLE(cxMismatch2CFImpl, T, T2)(const T *first, const T *last, const T2 *first2, bool(*p)(T, T2)) {\
    assert(first && last && first2 && p);\
    \
    while (first != last && p(*first, *first2)) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_CPTR(T), CX_CPTR(T2))){first, first2};\
}

#define cxMismatch2DF(T, T2, T3, first, last, first2, p, data) CX_CHOOSE(cxMismatch2DFImpl, T, T2, T3)(first, last, first2, p, data)
#define cxMismatch2DFImpl(T, T2, T3)\
cxPair(CX_PTR(T), CX_PTR(T2)) CX_MANGLE(cxMismatch2DFImpl, T, T2, T3)(T *first, T *last, T2 *first2, bool(*p)(T, T2, T3), T3 data) {\
    assert(first && last && first2 && p);\
    \
    while (first != last && p(*first, *first2, data)) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_PTR(T), CX_PTR(T2))){first, first2};\
}

#define cxMismatch2CDF(T, T2, T3, first, last, first2, p, data) CX_CHOOSE(cxMismatch2CDFImpl, T, T2, T3)(first, last, first2, p, data)
#define cxMismatch2CDFImpl(T, T2, T3)\
cxPair(CX_CPTR(T), CX_CPTR(T2)) CX_MANGLE(cxMismatch2CDFImpl, T, T2, T3)(const T *first, const T *last, const T2 *first2, bool(*p)(T, T2, T3), T3 data) {\
    assert(first && last && first2 && p);\
    \
    while (first != last && p(*first, *first2, data)) {\
        ++first, ++first2;\
    }\
    \
    return (cxPair(CX_CPTR(T), CX_CPTR(T2))){first, first2};\
}

#endif
