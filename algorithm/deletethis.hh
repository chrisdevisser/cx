#pragma once
#ifndef CX_ALGORITHM__H
#define CX_ALGORITHM__H

#include <assert.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

#define CX_USING_ALGORITHM_(...) BOOST_PP_OVERLOAD(CX_USING_ALGORITHM_, __VA_ARGS__)(__VA_ARGS__)

#define CX_USING_ALGORITHM_1(T)\
CX_USING(cx)

#define CX_USING_ALGORITHM_2(T, T2)\
CX_USING(cx)

#endif
