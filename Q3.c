#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    NUM_SUCCESS = 0,
    NUM_ERR_NULL_PTR = -1,
    NUM_ERR_OUT_OF_MEMORY = -2,
    NUM_ERR_DIM_MISMATCH = -3
} NumError;

typedef struct {
    size_t size;
    double* data;
} FloatVector;

void float_vector_destroy(FloatVector* vec) {
    if (vec != NULL) {
        if (vec->data != NULL) {
            free(vec->data);
            vec->data = NULL;
        }
        vec->size = 0;
    }
}

NumError float_vector_create(FloatVector* vec, size_t size) {
    if (vec == NULL) return NUM_ERR_NULL_PTR;

    vec->size = size;
    vec->data = (double*)calloc(size, sizeof(double));
    
    if (vec->data == NULL) {
        float_vector_destroy(vec);
        return NUM_ERR_OUT_OF_MEMORY;
    }
    
    return NUM_SUCCESS;
}

NumError vector_fma_compute(const FloatVector* A, const FloatVector* B, FloatVector* C) {
    if (!A || !B || !C || !A->data || !B->data || !C->data) return NUM_ERR_NULL_PTR;
    
    if (A->size != B->size || A->size != C->size) return NUM_ERR_DIM_MISMATCH;
    
    for (size_t i = 0; i < A->size; ++i) {
        C->data[i] = fma(A->data[i], B->data[i], C->data[i]);
    }
    
    return NUM_SUCCESS;
}

NumError vector_kahan_sum(const FloatVector* vec, double* result) {
    if (!vec || !vec->data || !result) return NUM_ERR_NULL_PTR;
    
    double sum = 0.0;
    double compensation = 0.0;
    
    for (size_t i = 0; i < vec->size; ++i) {
        double y = vec->data[i] - compensation;
        double t = sum + y;
        compensation = (t - sum) - y;
        sum = t;
    }
    
    *result = sum;
    return NUM_SUCCESS;
}
