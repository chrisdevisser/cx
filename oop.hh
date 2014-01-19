#ifndef CX_OOP_H
#define CX_OOP_H

#include <stddef.h>

#include "boost_pp/facilities/overload.hpp"
#include "preprocessor.hh"

#define CX_DERIVES_FROM(...) BOOST_PP_OVERLOAD(CX_DERIVES_FROM, __VA_ARGS__)(__VA_ARGS__)

#define CX_DERIVES_FROM1(b) struct b super
#define CX_DERIVES_FROM2(b, b2) struct b CX_PP_CONCAT(cxSuper, _, b);  struct b2 CX_PP_CONCAT(cxSuper, _, b2)
#define CX_DERIVES_FROM3(b, b2, b3) CX_DERIVES_FROM2(b, b2); struct b3 CX_PP_CONCAT(cxSuper, _, b3)
#define CX_DERIVES_FROM4(b, b2, b3, b4) CX_DERIVES_FROM3(b, b2, b3); struct b4 CX_PP_CONCAT(cxSuper, _, b4)
#define CX_DERIVES_FROM5(b, b2, b3, b4, b5) CX_DERIVES_FROM4(b, b2, b3, b4); struct b5 CX_PP_CONCAT(cxSuper, _, b5)
#define CX_DERIVES_FROM6(b, b2, b3, b4, b5, b6) CX_DERIVES_FROM5(b, b2, b3, b4,b5); struct b6 CX_PP_CONCAT(cxSuper, _, b6)
#define CX_DERIVES_FROM7(b, b2, b3, b4, b5, b6, b7) CX_DERIVES_FROM6(b, b2, b3,b4, b5, b6); struct b7 CX_PP_CONCAT(cxSuper, _, b7)
#define CX_DERIVES_FROM8(b, b2, b3, b4, b5, b6, b7, b8) CX_DERIVES_FROM7(b, b2,b3, b4, b5, b6, b7); struct b8 CX_PP_CONCAT(cxSuper, _, b8)
#define CX_DERIVES_FROM9(b, b2, b3, b4, b5, b6, b7, b8, b9) CX_DERIVES_FROM8(b,b2, b3, b4, b5, b6, b7, b8); struct b9 CX_PP_CONCAT(cxSuper, _, b9)
#define CX_DERIVES_FROM10(b, b2, b3, b4, b5, b6, b7, b8, b9, b10) CX_DERIVES_FROM9(b, b2, b3, b4, b5, b6, b7, b8, b9); struct b10 CX_PP_CONCAT(cxSuper, _, b10)

#define CX_TO_BASE(derivedPtr, base) (struct base *)(derivedPtr)
#define CX_TO_MULTI_BASE(derivedPtr, base)  (struct base *)((char *)(derivedPtr) + ((char *)(&(derivedPtr)->CX_PP_CONCAT(cxSuper_, base)) - (char *)(derivedPtr)))

#define CX_TO_DERIVED(basePtr, derived) (struct derived *)(basePtr)

#define CX_SUPER super
#define CX_BASE(base) CX_PP_CONCAT(cxSuper_, base)

#endif
