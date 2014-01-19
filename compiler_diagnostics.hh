#ifndef CX_COMPILERDIAGNOSTICS_H
#define CX_COMPILERDIAGNOSTICS_H

#define CX_PRAGMA(x) _Pragma(#x)

#ifdef __GNUC__
    #define CX_PRAGMA_PUSH CX_PRAGMA(GCC diagnostic push)
    #define CX_PRAGMA_POP CX_PRAGMA(GCC diagnostic pop)
    #define CX_PRAGMA_IGNORE_STR(x) CX_PRAGMA(GCC diagnostic ignored x)
    #define CX_PRAGMA_IGNORE_NUM(x)
#endif

#ifdef _MSC_VER
    #define CX_PRAGMA_PUSH CX_PRAGMA(warning(push))
    #define CX_PRAGMA_POP CX_PRAGMA(warning(pop))
    #define CX_PRAGMA_IGNORE_STR(x)
    #define CX_PRAGMA_IGNORE_NUM(x) CX_PRAGMA(warning(disable: x))
#endif

#ifdef __clang__
    #define CX_PRAGMA_PUSH CX_PRAGMA(clang diagnostic push)
    #define CX_PRAGMA_POP CX_PRAGMA(clang diagnostic pop)
    #define CX_PRAGMA_IGNORE_STR(x) CX_PRAGMA(clang diagnostic ignored x)
    #define CX_PRAGMA_IGNORE_NUM(x)
#endif

#endif
