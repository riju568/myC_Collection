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
int sum_upper_triangular(int mat[N][N])
{
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        // j starts at i to only target elements on and above the diagonal
        for (int j = i; j < N; j++)
        {
            sum += mat[i][j];
        }
    }

    return sum;
}

int Summation_UpperTriangularMatrix() // function to call inside main function to display output in console
{
    int mat[N][N] = {
        {1, 2, 3},
        {0, 5, 6},
        {0, 0, 9}};

    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    int total_sum = sum_upper_triangular(mat);
    printf("\nSum of upper triangular elements: %d\n", total_sum);

    return 0;
}

int sum_lower_triangular(int mat[N][N])
{
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        // j only runs up to i, targeting elements on and below the diagonal
        for (int j = 0; j <= i; j++)
        {
            sum += mat[i][j];
        }
    }

    return sum;
}

int Summation_LowerTriangularMatrix() // function to call inside main function to display output in console // function to call inside main function to display output in console
{
    // A Lower Triangular Matrix (elements above the main diagonal are 0)
    int mat[N][N] = {
        {1, 0, 0},
        {4, 5, 0},
        {7, 8, 9}};

    printf("Lower Triangular Matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    int total_sum = sum_lower_triangular(mat);
    printf("\nSum of lower triangular elements: %d\n", total_sum);

    return 0;
}
int transpose_matrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        // j starts at i + 1 to only swap elements above the diagonal
        // with their counterparts below the diagonal
        for (int j = i + 1; j < N; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    return 0;
}

/* print_matrix already defined earlier as 'void print_matrix'. */

int transpose_Matrix() // function to call inside main function to display output in console
{
    int mat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printf("Original Matrix:\n");
    print_matrix(mat);

    transpose_matrix(mat);

    printf("\nTransposed Matrix:\n");
    print_matrix(mat);

    return 0;
}

// Find determinant of a matrix.

#define N 3 // Fixed size for a 3x3 matrix

int calculate_determinant(int mat[N][N])
{
    int det;

    // Applying the 3x3 determinant formula
    int term1 = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);
    int term2 = mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]);
    int term3 = mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

    // Remember the sign pattern: + , - , +
    det = term1 - term2 + term3;

    return det;
}

int determinantMatrix() // function to call inside main function to display output in console
{
    // Example Matrix
    int mat[N][N] = {
        {6, 1, 1},
        {4, -2, 5},
        {2, 8, 7}};

    printf("Matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    int result = calculate_determinant(mat);
    printf("\nDeterminant of the matrix: %d\n", result);

    return 0;
}

int create_identity_matrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                mat[i][j] = 1; // Diagonal element
            }
            else
            {
                mat[i][j] = 0; // Off-diagonal element
            }
        }
    }
    return 0;
}

/* print_matrix already defined earlier as 'void print_matrix'. */

int Identity_Matrix() // function to call inside main function to display output in console
{
    int mat[N][N];

    create_identity_matrix(mat);

    printf("Identity Matrix of size %dx%d:\n", N, N);
    print_matrix(mat);

    return 0;
}

int main(void)
{
    Summation_UpperTriangularMatrix();
    Summation_LowerTriangularMatrix();
    transpose_Matrix();
    determinantMatrix();
    Identity_Matrix();
    lowerTriangularMatrix();
    InterchangeDiagonals();
    SummationOfDiagonals();
    summationEachRow_Column();
    upperTriangularMatrix();

    return 0;
}
