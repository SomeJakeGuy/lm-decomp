#ifndef LM_MACROS_H
#define LM_MACROS_H

#include <dolphin/macros.h>


#define dummy_float_data() \
    static f32 dummy_float_data[6] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};

#define ARRAY_COUNT(arr) (int)(sizeof(arr) / sizeof(arr[0]))

#define READU32_BE(ptr, offset)                                                \
	(((u32)ptr[offset] << 24) | ((u32)ptr[offset + 1] << 16)                   \
	 | ((u32)ptr[offset + 2] << 8) | (u32)ptr[offset + 3]);

#define FLAG_ON(V, F)    (((V) & (F)) == 0)
#define FLAG_OFF(V, F)   (((V) & (F)) != 0)

#define ALIGN_PREV(u, align) (u & (~(align - 1)))
#define ALIGN_NEXT(u, align) ((u + (align - 1)) & (~(align - 1)))
#define IS_ALIGNED(X, N)     (((X) & ((N) - 1)) == 0)
#define IS_NOT_ALIGNED(X, N) (((X) & ((N) - 1)) != 0)

#ifdef __cplusplus
#define BEGIN_SCOPE_EXTERN_C extern "C" {
#else
#define BEGIN_SCOPE_EXTERN_C
#endif

#ifdef __cplusplus
#define END_SCOPE_EXTERN_C }
#else
#define END_SCOPE_EXTERN_C
#endif

#define STACK_PAD_VAR(n) do { int pad[n]; } while (0); (void)0;

#endif
