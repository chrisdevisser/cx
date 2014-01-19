#pragma once
#ifndef CX_TEMPLATE_H
#define CX_TEMPLATE_H

#include "boost_pp/facilities/overload.hpp"
#include "compiler_diagnostics.hh"
#include "config.hh"
#include "preprocessor.hh"

#define CX_MANGLE(name, ...) BOOST_PP_OVERLOAD(CX_MANGLE, __VA_ARGS__)(name, __VA_ARGS__)

//create a name with up to N types included
#define CX_MANGLE1(name, T) CX_PP_CONCAT(name, _, T)
#define CX_MANGLE2(name, T, T2) CX_PP_CONCAT(name, _, T, _, T2)
#define CX_MANGLE3(name, T, T2, T3) CX_PP_CONCAT(name, _, T, _, T2, _, T3)
#define CX_MANGLE4(name, T, T2, T3, T4) CX_PP_CONCAT(name, _, T, _, T2, _, T3, _, T4)
#define CX_MANGLE5(name, T, T2, T3, T4, T5) CX_PP_CONCAT(CX_PP_CONCAT(name, _, T, _, T2, _, T3, _, T4, _), T5) //only supports 10

#ifndef CX_NO_STATIC_FUNCTIONS
    #define CX_USING CX_USING_STATIC
#else
    #define CX_USING CX_USING_NO_STATIC
#endif

//define a struct or function with up to N type parameters
#define CX_USING_STATIC(name, ...) \
CX_STATIC CX_PP_CONCAT(name, Impl)(__VA_ARGS__) \
CX_PRAGMA_IGNORE_STR("-Wunused-function")

#define CX_USING_NO_STATIC(name, ...) \
CX_PP_CONCAT(name, Impl)(__VA_ARGS__) \
CX_PRAGMA_IGNORE_STR("-Wunused-function")

#define CX_USING_TYPE(name, ...) CX_PP_CONCAT(name, Impl)(__VA_ARGS__)

//choose a function based on name and up to N types
#define CX_CHOOSE(name, ...) CX_MANGLE(name, __VA_ARGS__)

#endif
