#pragma once
#ifndef CX_ALGORITHM_SWAP_H
#define CX_ALGORITHM_SWAP_H

#include <assert.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_SWAP(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_SWAP, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_SWAP1(T)\
CX_USING(cxSwap, T)

#define CX_USING_ALGORITHM_SWAP2(T, T2)\
CX_USING(cxSwap2, T, T2)

#define cxSwap(T, a, b) CX_CHOOSE(cxSwapImpl, T)(a, b)
#define cxSwapImpl(T)\
void CX_MANGLE(cxSwapImpl, T)(T *a, T *b) {\
    T temp = *a;\
    *a = *b;\
    *b = temp;\
}

#define cxSwap2(T, T2, a, b) CX_CHOOSE(cxSwap2Impl, T, T2)(a, b)
#define cxSwap2Impl(T, T2)\
void CX_MANGLE(cxSwap2Impl, T, T2)(T *a, T2 *b) {\
    T temp = *a;\
    *a = *b;\
    *b = temp;\
}

#endif
