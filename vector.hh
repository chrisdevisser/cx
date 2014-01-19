#ifndef CX_VECTOR_H
#define CX_VECTOR_H

#include <assert.h>
#include <stdlib.h>

#include "algorithm/copy.hh"
#include "algorithm/fill_n.hh"
#include "compiler_diagnostics.hh"
#include "template.hh"
#include "type_utils.hh"

#define CX_USING_ONLY_VECTOR(T)\
CX_USING_TYPE(cxVector, T)\
CX_USING(cxVectorBegin, T)\
CX_USING(cxVectorEnd, T)\
CX_USING(cxVectorResize, T)\
CX_USING(cxVectorInit, T)\
CX_USING(cxVectorDestroy, T)\
CX_USING(cxVectorClear, T)\
CX_USING(cxVectorAssignCount, T)\
CX_USING(cxVectorAssignRange, T)\
CX_USING(cxVectorAssignVec, T)\
CX_USING(cxVectorPushBack, T)

#define CX_USING_VECTOR(T) \
CX_PRAGMA_PUSH \
CX_PRAGMA_IGNORE_STR("-Wmissing-braces") \
CX_USING(cxCopy, T) \
CX_USING(cxFillN, T) \
CX_USING_ONLY_VECTOR(T) \
CX_PRAGMA_POP

#define cxVector(T) CX_CHOOSE(cxVectorImpl, T)
#define cxVectorImpl(T)\
typedef struct CX_MANGLE(cxVectorImpl, T) {\
    T *arr;\
    size_t size;\
} CX_MANGLE(cxVectorImpl, T); CX_STATIC cxVector(T) CX_MANGLE(cxVectorDefault, T) = {NULL, 0};

#define cxVectorDefault(T) CX_CHOOSE(cxVectorDefault, T)

#define cxVectorBegin(T, v) CX_CHOOSE(cxVectorBeginImpl, T)(v)
#define cxVectorBeginImpl(T)\
T *CX_MANGLE(cxVectorBeginImpl, T)(cxVector(T) *v) {\
    assert(v);\
    return v->arr;\
}

#define cxVectorEnd(T, v) CX_CHOOSE(cxVectorEndImpl, T)(v)
#define cxVectorEndImpl(T)\
T *CX_MANGLE(cxVectorEndImpl, T)(cxVector(T) *v) {\
    return v ? v->arr + v->size : NULL;\
}

#define cxVectorInit(T, v) CX_CHOOSE(cxVectorInitImpl, T)(v)
#define cxVectorInitImpl(T)\
void CX_MANGLE(cxVectorInitImpl, T)(cxVector(T) *v) {\
    if (!v) {return;}\
    \
    *v = cxVectorDefault(T);\
}

#define cxVectorInitSize(T, v, n) CX_CHOOSE(cxVectorInitSizeImpl, T)(v, n)
#define cxVectorInitSizeImpl(T)\
void CX_MANGLE

#define cxVectorDestroy(T, v) CX_CHOOSE(cxVectorDestroyImpl, T)(v)
#define cxVectorDestroyImpl(T)\
void CX_MANGLE(cxVectorDestroyImpl, T)(cxVector(T) *v) {\
    if (!v) {return;}\
    \
    free(v->arr);\
    v->arr = NULL;\
    v->size = 0;\
}

#define cxVectorAssignCount(T, v, count, value) CX_CHOOSE(cxVectorAssignCountImpl, T)(v, count, value)
#define cxVectorAssignCountImpl(T)\
void CX_MANGLE(cxVectorAssignCountImpl, T)(cxVector(T) *v, size_t count, T value) {\
    if (!v) {return;}\
    \
    cxVectorResize(T, v, count);\
    cxFillN(T, v->arr, count, value);\
}

#define cxVectorAssignRange(T, v, first, last) CX_CHOOSE(cxVectorAssignRangeImpl, T)(v, first, last)
#define cxVectorAssignRangeImpl(T)\
void CX_MANGLE(cxVectorAssignRangeImpl, T)(cxVector(T) *v, T *first, T *last) {\
    if (!v) {return;}\
    \
    cxVectorResize(T, v, last - first);\
    cxCopy(T, first, last, v->arr);\
}

#define cxVectorAssignList(T, v, ...)\
do {\
    T cxLocal_arr[] = {__VA_ARGS__};\
    cxVectorAssignRange(T, v, CX_BEGIN(cxLocal_arr), CX_END(cxLocal_arr));\
} while(0)

#define cxVectorAssignVec(T, v, other) CX_CHOOSE(cxVectorAssignVecImpl, T)(v, other)
#define cxVectorAssignVecImpl(T)\
void CX_MANGLE(cxVectorAssignVecImpl, T)(cxVector(T) *v, cxVector(T) *other) {\
    if (!v || !other) {return;}\
    v->size = other->size;\
    \
    if (!other->arr) {return;}\
    cxVectorAssignRange(T, v, cxVectorBegin(T, other), cxVectorEnd(T, other));\
}

#define cxVectorClear(T, v) CX_CHOOSE(cxVectorClearImpl, T)(v)
#define cxVectorClearImpl(T)\
void CX_MANGLE(cxVectorClearImpl, T)(cxVector(T) *v) {\
    if (!v) {return;}\
    cxVectorInit(T, v);\
}

#define cxVectorResize(T, v, newSize) CX_CHOOSE(cxVectorResizeImpl, T)(v, newSize)
#define cxVectorResizeImpl(T)\
void CX_MANGLE(cxVectorResizeImpl, T)(cxVector(T) *v, size_t newSize) {\
    if (!v) {return;}\
    \
    if (v->arr) {\
        v->arr = realloc(v->arr, newSize * sizeof(T));\
    } else {\
        v->arr = malloc(newSize * sizeof(T));\
    }\
    \
    assert(v->arr);\
    \
    if (newSize > v->size) {\
        cxFillN(T, v->arr + v->size, newSize - v->size, (T){0});\
    }\
    \
    v->size = newSize;\
}

#define cxVectorPushBack(T, v, t) CX_CHOOSE(cxVectorPushBackImpl, T)(v, t)
#define cxVectorPushBackImpl(T)\
void CX_MANGLE(cxVectorPushBackImpl, T)(cxVector(T) *v, T t) {\
    if (!v) {return;}\
    \
    cxVectorResize(T, v, v->size + 1);\
    v->arr[v->size - 1] = t;\
}

CX_PRAGMA_POP

#endif
