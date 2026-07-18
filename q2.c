/*
2. Explicit Memory Alignment
Arrays have to be aligned on byte addresses compatible to the architecture, which also fit the structure of the CPU’s SIMD registers in order to perform loads to optimum speed (e.g., for AVX2 arrays must be aligned on 32-bytes, for AVX-512 on 64-bytes, just to take a couple examples). The standard malloc does not offer sufficient alignment guaranteed. Instead of the default malloc compute functions employ posixmemalign() and in C11 the functions alignedalloc() in order to allocate big enough aligned arrays for aligned access along cache lines.
*/
#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>

typedef enum {
    VEC_SUCCESS = 0,
    VEC_ERR_NULL_PTR = -1,
    VEC_ERR_OUT_OF_MEMORY = -2,
    VEC_ERR_SIZE_MISMATCH = -3,
    VEC_ERR_INVALID_ALIGNMENT = -4
} VecError;

typedef struct {
    size_t size;
    size_t alignment;
    double* data;
} AlignedVector;

void aligned_vector_destroy(AlignedVector* vec) {
    if (vec != NULL) {
        if (vec->data != NULL) {
            free(vec->data);
            vec->data = NULL; 
        }
        vec->size = 0;
        vec->alignment = 0;
    }
}

VecError aligned_vector_create(AlignedVector* vec, size_t size, size_t alignment) {
    if (vec == NULL) return VEC_ERR_NULL_PTR;

    if ((alignment == 0) || (alignment & (alignment - 1)) != 0) {
        return VEC_ERR_INVALID_ALIGNMENT;
    }

    vec->size = size;
    vec->alignment = alignment;

    size_t byte_size = size * sizeof(double);
    size_t padded_size = (byte_size + alignment - 1) & ~(alignment - 1);

    vec->data = (double*)aligned_alloc(alignment, padded_size);
    
    if (vec->data == NULL) {
        aligned_vector_destroy(vec);
        return VEC_ERR_OUT_OF_MEMORY;
    }
    
    return VEC_SUCCESS;
}

VecError vector_add_avx2(const AlignedVector* A, const AlignedVector* B, AlignedVector* C) {
    if (!A || !B || !C || !A->data || !B->data || !C->data) return VEC_ERR_NULL_PTR;

    if (A->size != B->size || A->size != C->size) return VEC_ERR_SIZE_MISMATCH;

    if (A->alignment < 32 || B->alignment < 32 || C->alignment < 32) {
        return VEC_ERR_INVALID_ALIGNMENT;
    }

    size_t i = 0;
    
    for (; i + 3 < A->size; i += 4) {
        __m256d vec_a = _mm256_load_pd(&A->data[i]);
        __m256d vec_b = _mm256_load_pd(&B->data[i]);
        
        __m256d vec_c = _mm256_add_pd(vec_a, vec_b);
        
        _mm256_store_pd(&C->data[i], vec_c);
    }

    for (; i < A->size; ++i) {
        C->data[i] = A->data[i] + B->data[i];
    }

    return VEC_SUCCESS;
}
