#pragma once
#ifndef CX_UTILITY_H
#define CX_UTILITY_H

#include "template.hh"

#define cxPair(T, T2) CX_CHOOSE(cxPairImpl, T, T2)
#define cxPairImpl(T, T2)\
typedef struct CX_MANGLE(cxPairImpl, T, T2) {\
    T first;\
    T2 second;\
} CX_MANGLE(cxPairImpl, T, T2);

#endif
