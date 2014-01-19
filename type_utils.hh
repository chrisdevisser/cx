#pragma once

#ifndef CX_TYPEUTILS_H
#define CX_TYPEUTILS_H

#include "preprocessor.hh"

#define CX_DEFAULT(T) (T){0}

#define CX_PTR(T) CX_PP_CONCAT(cx, T, Ptr)
#define CX_CPTR(T) CX_PP_CONCAT(cxConst, T, Ptr)

#define CX_PTR_TYPEDEF(T) typedef T *CX_PTR(T)
#define CX_CPTR_TYPEDEF(T) typedef const T *CX_CPTR(T)

#endif
