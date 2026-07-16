/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/


#include <stdio.h>

#define ALLOCATED_ROW_CAPACITY 3
#define ALLOCATED_COLUMN_CAPACITY 3

// Check whether two matrices are equal or not.

int matricesEqualOrNot()
{
    enum { LOCAL_ROWS = 3, LOCAL_COLS = 3 };

    int mat1[LOCAL_ROWS][LOCAL_COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[LOCAL_ROWS][LOCAL_COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int isEqual = 1;

    for (int i = 0; i < LOCAL_ROWS && isEqual; i++)
    {
        for (int j = 0; j < LOCAL_COLS; j++)
        {
            if (mat1[i][j] != mat2[i][j])
            {
                isEqual = 0;
                break;
            }
        }
    }
    printf(isEqual ? "The matrices are equal.\n" : "The matrices are not equal.\n");
    return 0;
}

// Sum of the main diagonal elements of a matrix.
int summationDiagonalsMatrix()
{
    const int MATRIX_SIZE = 3;
    int matrix[3][3] = {{5, 2, 3}, {4, 1, 6}, {7, 8, 9}};
    int diagonalSum = 0;

    // Shortened single loop execution
    for (int i = 0; i < MATRIX_SIZE; i++)
        diagonalSum += matrix[i][i];

    printf("Sum of main diagonal elements: %d\n", diagonalSum);
    return 0;
}
// Find the sum of minor diagonal elements of a matrix.
int summationOfMinorDiagonals()
{
    const int MATRIX_SIZE = 3;
    int matrix[3][3] = {{5, 2, 3}, {4, 1, 6}, {7, 8, 9}};
    int minorDiagonalSum = 0;

    // A single loop tracks the row 'i' and calculates the column index directly
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        minorDiagonalSum += matrix[i][MATRIX_SIZE - 1 - i];
    }
    printf("Sum of minor diagonal elements: %d\n", minorDiagonalSum);
    return 0;
}




// Find the sum of each row and column of a matrix.
// Encapsulating data layout inside a descriptive structure
typedef struct {
    int gridData[ALLOCATED_ROW_CAPACITY][ALLOCATED_COLUMN_CAPACITY];
    int activeRowCount;
    int activeColumnCount;
} TwoDimensionalMatrixContainer;

void calculateMatrixRowTotals(const TwoDimensionalMatrixContainer *matrixInstance);
void calculateMatrixColumnTotals(const TwoDimensionalMatrixContainer *matrixInstance);

int summationRowColumnMatrixMain() {
    // Declarative instantiation of the Matrix Object
    TwoDimensionalMatrixContainer customMatrixObject = {
        .gridData = {
            {5, 5, 5},
            {10, 10, 10},
            {15, 15, 15}
        },
        .activeRowCount = 3,
        .activeColumnCount = 3
    };

    calculateMatrixRowTotals(&customMatrixObject);
    printf("\n");
    calculateMatrixColumnTotals(&customMatrixObject);

    return 0;
}

void calculateMatrixRowTotals(const TwoDimensionalMatrixContainer *matrixInstance) {
    for (int rowIndex = 0; rowIndex < matrixInstance->activeRowCount; rowIndex++) {
        int temporaryRowSum = 0;

        for (int columnIndex = 0; columnIndex < matrixInstance->activeColumnCount; columnIndex++) {
            temporaryRowSum += matrixInstance->gridData[rowIndex][columnIndex];
        }

        printf("Sum calculation for Matrix Row %d results in: %d\n", rowIndex + 1, temporaryRowSum);
    }
}

void calculateMatrixColumnTotals(const TwoDimensionalMatrixContainer *matrixInstance) {
    for (int columnIndex = 0; columnIndex < matrixInstance->activeColumnCount; columnIndex++) {
        int temporaryColumnSum = 0;

        for (int rowIndex = 0; rowIndex < matrixInstance->activeRowCount; rowIndex++) {
            temporaryColumnSum += matrixInstance->gridData[rowIndex][columnIndex];
        }

        printf("Sum calculation for Matrix Column %d results in: %d\n", columnIndex + 1, temporaryColumnSum);
    }
}


#define SQUARE_MATRIX_DIMENSION 4
// Function declaration for interchanging matrix diagonals
void interchangePrimaryAndSecondaryDiagonals(
    int targetMatrix[SQUARE_MATRIX_DIMENSION][SQUARE_MATRIX_DIMENSION], 
    int currentMatrixSize
);
// Function declaration to print the matrix structure cleanly
void displaySquareMatrixContents(
    int targetMatrix[SQUARE_MATRIX_DIMENSION][SQUARE_MATRIX_DIMENSION], 
    int currentMatrixSize
);
int InterchangeDiagonalsMain() {
    // Declarative setup of a 4x4 square grid matrix
    int userConfiguredMatrix[SQUARE_MATRIX_DIMENSION][SQUARE_MATRIX_DIMENSION] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };
    printf("--- Original Matrix Grid Structure ---\n");
    displaySquareMatrixContents(userConfiguredMatrix, SQUARE_MATRIX_DIMENSION);
    printf("--------------------------------------\n\n");
    // Perform the matrix diagonal swapping operation
    interchangePrimaryAndSecondaryDiagonals(userConfiguredMatrix, SQUARE_MATRIX_DIMENSION);
    printf("--- Modified Matrix Grid Structure ---\n");
    displaySquareMatrixContents(userConfiguredMatrix, SQUARE_MATRIX_DIMENSION);
    printf("--------------------------------------\n");
    return 0;
}
// Interchanges the primary and secondary diagonal elements of the grid
void interchangePrimaryAndSecondaryDiagonals(
    int targetMatrix[SQUARE_MATRIX_DIMENSION][SQUARE_MATRIX_DIMENSION], 
    int currentMatrixSize
) {
    for (int currentRowIndex = 0; currentRowIndex < currentMatrixSize; currentRowIndex++) {     
        // Find indices for both diagonals in the current row
        int primaryDiagonalColumnIndex = currentRowIndex;
        int secondaryDiagonalColumnIndex = currentMatrixSize - 1 - currentRowIndex;
        // Perform a classic swap using a descriptive temporary placeholder variable
        int temporaryDataHolder = targetMatrix[currentRowIndex][primaryDiagonalColumnIndex];
        targetMatrix[currentRowIndex][primaryDiagonalColumnIndex] = 
            targetMatrix[currentRowIndex][secondaryDiagonalColumnIndex];
        targetMatrix[currentRowIndex][secondaryDiagonalColumnIndex] = temporaryDataHolder;
    }
}

// Formats and displays the matrix elements sequentially
void displaySquareMatrixContents(
    int targetMatrix[SQUARE_MATRIX_DIMENSION][SQUARE_MATRIX_DIMENSION], 
    int currentMatrixSize
) {
    for (int currentRowIndex = 0; currentRowIndex < currentMatrixSize; currentRowIndex++) {
        for (int currentColumnIndex = 0; currentColumnIndex < currentMatrixSize; currentColumnIndex++) {
            printf("%d\t", targetMatrix[currentRowIndex][currentColumnIndex]);
        }
        printf("\n");
    }
}



//  Find the sum of minor diagonal elements of a matrix.

#define MATRIX_SIZE_DIMENSION 4

// Function prototype
void printCalculatedUpperTriangularMatrix(int outputMatrix[MATRIX_SIZE_DIMENSION][MATRIX_SIZE_DIMENSION]);

// Main entry point
int  sumOfMinorDiagonalMain() {
    int genericInputMatrix[MATRIX_SIZE_DIMENSION][MATRIX_SIZE_DIMENSION] = {
        {2,  4,  6,  8},
        {1,  3,  5,  7},
        {9,  2,  4,  6},
        {3,  5,  7,  9}
    };

    int targetedUpperTriangularMatrix[MATRIX_SIZE_DIMENSION][MATRIX_SIZE_DIMENSION] = {0}; 

    // Logic remains the same: Optimized loop
    for (int rowIndex = 0; rowIndex < MATRIX_SIZE_DIMENSION; rowIndex++) {
        for (int columnIndex = rowIndex; columnIndex < MATRIX_SIZE_DIMENSION; columnIndex++) {
            targetedUpperTriangularMatrix[rowIndex][columnIndex] = genericInputMatrix[rowIndex][columnIndex];
        }
    }

    printf("--- Form 1: Optimized Boundary Execution ---\n");
    printCalculatedUpperTriangularMatrix(targetedUpperTriangularMatrix);

    return 0;
}

void printCalculatedUpperTriangularMatrix(int outputMatrix[MATRIX_SIZE_DIMENSION][MATRIX_SIZE_DIMENSION]) {
    for (int rowIndex = 0; rowIndex < MATRIX_SIZE_DIMENSION; rowIndex++) {
        for (int columnIndex = 0; columnIndex < MATRIX_SIZE_DIMENSION; columnIndex++) {
            printf("%d\t", outputMatrix[rowIndex][columnIndex]);
        }
        printf("\n");
    }
}


int main(void) {
    matricesEqualOrNot();
    summationDiagonalsMatrix();
    summationOfMinorDiagonals();
    summationRowColumnMatrixMain();
    InterchangeDiagonalsMain();
    sumOfMinorDiagonalMain();
    return 0;
}
