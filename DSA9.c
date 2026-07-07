#include <stdio.h>

// Common matrix sizes
#define N 3 // Matrix dimension (square)
#define R 3 // Number of rows
#define C 3 // Number of columns

int get_trace(int mat[N][N])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += mat[i][i];
    }
    return sum;
}

int SummationOfDiagonals() // function to call inside main function to display output in console
{
    int mat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printf("Trace: %d\n", get_trace(mat)); // Output will be 15 (1 + 5 + 9)
    return 0;
}

// Find the sum of minor diagonal elements of a matrix.
int minor_sum(int mat[N][N])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += mat[i][N - 1 - i];
    }
    return sum;
}

int SummationOfMirrorDiagonals()
{
    int mat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printf("Minor Diagonal Sum: %d\n", minor_sum(mat)); // Output: 15 (3 + 5 + 7)
    return 0;
}

// Find the sum of each row and column of a matrix.
void print_sums(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        int r_sum = 0;
        for (int j = 0; j < C; j++)
        {
            r_sum += mat[i][j];
        }
        printf("Row %d sum = %d\n", i + 1, r_sum);
    }

    printf("\n");

    for (int j = 0; j < C; j++)
    {
        int c_sum = 0;
        for (int i = 0; i < R; i++)
        {
            c_sum += mat[i][j];
        }
        printf("Col %d sum = %d\n", j + 1, c_sum);
    }
}

int summationEachRow_Column() // function to call inside main function to display output in console
{
    int mat[R][C] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    print_sums(mat);
    return 0;
}

// Single swap_diagonals implementation used by various demos.
void swap_diagonals(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        if (i != N - 1 - i)
        {
            int tmp = mat[i][i];
            mat[i][i] = mat[i][N - 1 - i];
            mat[i][N - 1 - i] = tmp;
        }
    }
}

// Single print_matrix implementation used by various demos.
void print_matrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int InterchangeDiagonals() // function to call inside main function to display output in console
{
    int mat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printf("Original Matrix:\n");
    print_matrix(mat);

    swap_diagonals(mat);

    printf("\nMatrix after interchanging diagonals:\n");
    print_matrix(mat);

    return 0;
}

int upperTriangularMatrix() // function to call inside main function to display output in console
{
    int mat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printf("Original Matrix:\n");
    print_matrix(mat);

    swap_diagonals(mat);

    printf("\nMatrix after swapping diagonals:\n");
    print_matrix(mat);

    return 0;
}

int lowerTriangularMatrix() // function to call inside main function to display output in console
{
    int mat[N][N] = {
        {1, 0, 0},
        {4, 5, 0},
        {7, 8, 9}};

    printf("Original Lower Triangular Matrix:\n");
    print_matrix(mat);
    swap_diagonals(mat);
    printf("\nMatrix after swapping diagonals:\n");
    print_matrix(mat);

    return 0;
}

int main(void)
{
    lowerTriangularMatrix();
    InterchangeDiagonals();
    SummationOfDiagonals();
    summationEachRow_Column();
    upperTriangularMatrix();

    return 0;
}
