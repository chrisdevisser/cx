#pragma once
#ifndef CX_PREPROCESSOR_H
#define CX_PREPROCESSOR_H

#include "boost_pp/facilities/overload.hpp"

#define CX_PP_CONCAT(a, ...) BOOST_PP_OVERLOAD(CX_PP_CONCAT, , __VA_ARGS__)(a, __VA_ARGS__)

#define CX_PP_CONCAT2(a, b) a##b
#define CX_PP_CONCAT3(a, b, c) a##b##c
#define CX_PP_CONCAT4(a, b, c, d) a##b##c##d
#define CX_PP_CONCAT5(a, b, c, d, e) a##b##c##d##e
#define CX_PP_CONCAT6(a, b, c, d, e, f) a##b##c##d##e##f
#define CX_PP_CONCAT7(a, b, c, d, e, f, g) a##b##c##d##e##f##g
#define CX_PP_CONCAT8(a, b, c, d, e, f, g, h) a##b##c##d##e##f##g##h
#define CX_PP_CONCAT9(a, b, c, d, e, f, g, h, i) a##b##c##d##e##f##g##h##i
#define CX_PP_CONCAT10(a, b, c, d, e, f, g, h, i, j) a##b##c##d##e##f##g##h##i##j

#define CX_PP_STRINGIZE2(x) #x
#define CX_PP_STRINGIZE(x) CX_PP_STRINGIZE2(x)

#endif
