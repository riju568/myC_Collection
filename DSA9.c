/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/

#include <stdio.h>
#include <stdbool.h>
/* 
Add two matrices.
Subtract two matrices.
Perform scalar matrix multiplication.
Multiply two matrices.
Check whether two matrices are equal or not.
Sum of the main diagonal elements of a matrix.
Find the sum of minor diagonal elements of a matrix.
Find the sum of each row and column of a matrix.
Interchange diagonals of a matrix.
The upper triangular matrix.
Find a lower triangular matrix.
Sum of the upper triangular matrix.
Find the sum of a lower triangular matrix.
The transpose of a matrix.
Find determinant of a matrix.
Identity matrix in C.
Check the sparse matrix.
Check the symmetric matrix.
*/
#define MAX_ROWS 10
#define MAX_COLS 10

    void printMatrix(const int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, const int matA[MAX_ROWS][MAX_COLS], const int matB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, const int matA[MAX_ROWS][MAX_COLS], const int matB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

void multiplyMatrices(int rowsA, int colsA, int colsB, const int matA[MAX_ROWS][MAX_COLS], const int matB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS])
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

bool isIdentityMatrix(const int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    if (rows != cols)
    {
        return false;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
            {
                return false;
            }
        }
    }

    return true;
}

bool isSparseMatrix(const int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    int zeroCount = 0;
    int total = rows * cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                zeroCount++;
            }
        }
    }

    return zeroCount > (total / 2);
}

bool isSymmetricMatrix(const int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    if (rows != cols)
    {
        return false;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }

    return true;
}

int main(void)
{
    int matrixA[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int matrixB[MAX_ROWS][MAX_COLS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};
    int result[MAX_ROWS][MAX_COLS] = {{0}};

    printf("Matrix Operations Demo\n");
    printf("=====================\n");

    printf("\nMatrix A:\n");
    printMatrix(matrixA, 3, 3);

    printf("\nMatrix B:\n");
    printMatrix(matrixB, 3, 3);

    addMatrices(3, 3, matrixA, matrixB, result);
    printf("\nAddition Result:\n");
    printMatrix(result, 3, 3);

    subtractMatrices(3, 3, matrixA, matrixB, result);
    printf("\nSubtraction Result:\n");
    printMatrix(result, 3, 3);

    int matrixC[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6}};
    int matrixD[MAX_ROWS][MAX_COLS] = {
        {7, 8},
        {9, 10},
        {11, 12}};
    int product[MAX_ROWS][MAX_COLS] = {{0}};

    multiplyMatrices(2, 3, 2, matrixC, matrixD, product);
    printf("\nMultiplication Result:\n");
    printMatrix(product, 2, 2);

    int identity[MAX_ROWS][MAX_COLS] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    printf("\nIdentity check: %s\n", isIdentityMatrix(identity, 3, 3) ? "true" : "false");

    int sparse[MAX_ROWS][MAX_COLS] = {
        {1, 0, 0},
        {0, 0, 2},
        {0, 5, 0}};
    printf("Sparse check: %s\n", isSparseMatrix(sparse, 3, 3) ? "true" : "false");

    int symmetric[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}};
    printf("Symmetric check: %s\n", isSymmetricMatrix(symmetric, 3, 3) ? "true" : "false");

    return 0;
}
