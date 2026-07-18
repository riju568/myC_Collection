#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#if defined(_MSC_VER) || defined(__MINGW32__)
    #include <malloc.h>
    #define CROSS_ALIGNED_ALLOC(alignment, size) _aligned_malloc((size), (alignment))
    #define CROSS_ALIGNED_FREE(ptr) _aligned_free(ptr)
#else
    #define CROSS_ALIGNED_ALLOC(alignment, size) cross_posix_alloc((alignment), (size))
    #define CROSS_ALIGNED_FREE(ptr) free(ptr)
    
    static inline void* cross_posix_alloc(size_t alignment, size_t size) {
        void* ptr = NULL;
        size_t min_align = sizeof(void*);
        if (alignment < min_align) alignment = min_align;
        
        if (posix_memalign(&ptr, alignment, size) != 0) return NULL;
        return ptr;
    }
#endif

typedef enum {
    VEC_SUCCESS = 0,
    VEC_ERR_NULL_PTR = -1,
    VEC_ERR_OUT_OF_MEMORY = -2,
    VEC_ERR_INVALID_ALIGNMENT = -3,
    VEC_ERR_SIZE_MISMATCH = -4
} VecError;

typedef struct {
    size_t size;
    size_t alignment;
    double* data;
} CrossAlignedVector;

void cross_aligned_vector_destroy(CrossAlignedVector* vec) {
    if (vec != NULL) {
        if (vec->data != NULL) {
            CROSS_ALIGNED_FREE(vec->data);
            vec->data = NULL;
        }
        vec->size = 0;
        vec->alignment = 0;
    }
}

VecError cross_aligned_vector_create(CrossAlignedVector* vec, size_t size, size_t alignment) {
    if (vec == NULL) return VEC_ERR_NULL_PTR;

    if ((alignment == 0) || (alignment & (alignment - 1)) != 0) {
        return VEC_ERR_INVALID_ALIGNMENT;
    }

    vec->size = size;
    vec->alignment = alignment;

    size_t byte_size = size * sizeof(double);
    size_t padded_size = (byte_size + alignment - 1) & ~(alignment - 1);

    vec->data = (double*)CROSS_ALIGNED_ALLOC(alignment, padded_size);
    
    if (vec->data == NULL) {
        cross_aligned_vector_destroy(vec);
        return VEC_ERR_OUT_OF_MEMORY;
    }
    
    return VEC_SUCCESS;
}
