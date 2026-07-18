#include <stdio.h>
#include <stdlib.h>

typedef enum {
    MAT_SUCCESS = 0,
    MAT_ERR_NULL_PTR = -1,
    MAT_ERR_OUT_OF_MEMORY = -2,
    MAT_ERR_DIM_MISMATCH = -3
} MatError;

typedef struct {
    size_t rows;
    size_t cols;
    double* data; 
} Matrix;

void matrix_destroy(Matrix* mat) {
    if (mat != NULL) {
        if (mat->data != NULL) {
            free(mat->data);
            mat->data = NULL; // Prevent dangling pointer
        }
        mat->rows = 0;
        mat->cols = 0;
    }
}
MatError matrix_create(Matrix* mat, size_t rows, size_t cols) {
    if (mat == NULL) return MAT_ERR_NULL_PTR;

    mat->rows = rows;
    mat->cols = cols;
    
    // Allocate contiguous block to prevent fragmentation and aid CPU prefetching
    mat->data = (double*)calloc(rows * cols, sizeof(double));
    if (mat->data == NULL) {
        matrix_destroy(mat); // Cleanup on failure
        return MAT_ERR_OUT_OF_MEMORY;
    }
    
    return MAT_SUCCESS;
}

MatError matrix_multiply_optimized(const Matrix* A, const Matrix* B, Matrix* C) {
    // 1. "Exception" Handling: Validate inputs (Null pointer checks)
    if (A == NULL || B == NULL || C == NULL) return MAT_ERR_NULL_PTR;
    if (A->data == NULL || B->data == NULL || C->data == NULL) return MAT_ERR_NULL_PTR;

    // 2. Memory Safety: Validate bounds/dimensions for math operation
    if (A->cols != B->rows || C->rows != A->rows || C->cols != B->cols) {
        return MAT_ERR_DIM_MISMATCH;
    }
    size_t N = A->rows;
    size_t K = A->cols;
    size_t M = B->cols;
    for (size_t i = 0; i < N; ++i) {
        for (size_t k = 0; k < K; ++k) {
            double a_ik = A->data[i * K + k]; // Read once per inner loop
            for (size_t j = 0; j < M; ++j) {
                // Both C and B are accessed sequentially in memory (cache friendly)
                C->data[i * M + j] += a_ik * B->data[k * M + j];
            }
        }
    }

    return MAT_SUCCESS;
}
