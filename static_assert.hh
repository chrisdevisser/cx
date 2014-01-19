#ifndef CX_STATICASSERT_H
#define CX_STATICASSERT_H

#include "boost_pp/facilities/overload.hpp"
#include "preprocessor.hh"

#define CX_STATIC_ASSERT1(condition) typedef char CX_PP_CONCAT(Static_Assertion_Failed_Line_, __LINE__)[!!(condition) * 2 -1]
#define CX_STATIC_ASSERT2(condition, extra) typedef char CX_PP_CONCAT(Static_Assertion_Failed_Line_, __LINE__, _, extra)[!!(condition) * 2 -1]

#define CX_STATIC_ASSERT(...) BOOST_OVERLOAD(CX_STATIC_ASSERT, __VA_ARGS__)(__VA_ARGS__)

#endif
