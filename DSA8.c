#include <stdio.h>
#include <stdbool.h>


//Find the sum of each row and column of a matrix.
#define MATRIX_ROWS 3
#define MATRIX_COLUMNS 3

// Function declarations
void calculateAndPrintRowSums(int matrix[MATRIX_ROWS][MATRIX_COLUMNS]);
void calculateAndPrintColumnSums(int matrix[MATRIX_ROWS][MATRIX_COLUMNS]);
void displayMatrix(int matrix[MATRIX_ROWS][MATRIX_COLUMNS]);

int sumOfEachRowAndColumn() {
    // Initializing a sample 3x3 matrix
    int sampleMatrix[MATRIX_ROWS][MATRIX_COLUMNS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("--- Input Matrix ---\n");
    displayMatrix(sampleMatrix);
    printf("--------------------\n\n");

    calculateAndPrintRowSums(sampleMatrix);
    printf("\n");
    calculateAndPrintColumnSums(sampleMatrix);

    return 0;
}

// Calculates and prints the sum for each row
void calculateAndPrintRowSums(int matrix[MATRIX_ROWS][MATRIX_COLUMNS]) {
    for (int rowIndex = 0; rowIndex < MATRIX_ROWS; rowIndex++) {
        int rowRunningTotal = 0;

        for (int columnIndex = 0; columnIndex < MATRIX_COLUMNS; columnIndex++) {
            rowRunningTotal += matrix[rowIndex][columnIndex];
        }

        printf("The total sum for Row %d is: %d\n", rowIndex + 1, rowRunningTotal);
    }
}

// Calculates and prints the sum for each column
void calculateAndPrintColumnSums(int matrix[MATRIX_ROWS][MATRIX_COLUMNS]) {
    for (int columnIndex = 0; columnIndex < MATRIX_COLUMNS; columnIndex++) {
        int columnRunningTotal = 0;

        for (int rowIndex = 0; rowIndex < MATRIX_ROWS; rowIndex++) {
            columnRunningTotal += matrix[rowIndex][columnIndex];
        }

        printf("The total sum for Column %d is: %d\n", columnIndex + 1, columnRunningTotal);
    }
}

// Helper function to print the matrix structure
void displayMatrix(int matrix[MATRIX_ROWS][MATRIX_COLUMNS]) {
    for (int rowIndex = 0; rowIndex < MATRIX_ROWS; rowIndex++) {
        for (int columnIndex = 0; columnIndex < MATRIX_COLUMNS; columnIndex++) {
            printf("%d\t", matrix[rowIndex][columnIndex]);
        }
        printf("\n");
    }
}
//  Subtract two matrices.
#define TARGET_MATRIX_ROWS 3
#define TARGET_MATRIX_COLUMNS 3

// Function declarations
void subtractMatrices(
    int firstInputMatrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS], 
    int secondInputMatrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS], 
    int outputDifferenceMatrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS]
);

void displayMatrixGrid(int matrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS]);

int subtractTwoMatrices() {
    // Declarative setup of the first source matrix (Matrix A)
    int firstUserMatrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    // Declarative setup of the second source matrix (Matrix B)
    int secondUserMatrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS] = {
        {1,  2,  3},
        {4,  5,  6},
        {7,  8,  9}
    };

    // Allocated space for the resulting difference matrix (Matrix C)
    int resultingDifferenceMatrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS];

    // Execute the subtraction routine
    subtractMatrices(firstUserMatrix, secondUserMatrix, resultingDifferenceMatrix);

    printf("--- Matrix A ---\n");
    displayMatrixGrid(firstUserMatrix);
    
    printf("\n--- Matrix B ---\n");
    displayMatrixGrid(secondUserMatrix);
    
    printf("\n--- Resulting Matrix (A - B) ---\n");
    displayMatrixGrid(resultingDifferenceMatrix);

    return 0;
}

// Per-element matrix subtraction logic
void subtractMatrices(
    int firstInputMatrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS], 
    int secondInputMatrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS], 
    int outputDifferenceMatrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS]
) {
    for (int currentRowIndex = 0; currentRowIndex < TARGET_MATRIX_ROWS; currentRowIndex++) {
        for (int currentColumnIndex = 0; currentColumnIndex < TARGET_MATRIX_COLUMNS; currentColumnIndex++) {
            
            // Subtract elements sharing identical matching coordinates
            outputDifferenceMatrix[currentRowIndex][currentColumnIndex] = 
                firstInputMatrix[currentRowIndex][currentColumnIndex] - 
                secondInputMatrix[currentRowIndex][currentColumnIndex];
                
        }
    }
}

// Clean sequential data stream presentation
void displayMatrixGrid(int matrix[TARGET_MATRIX_ROWS][TARGET_MATRIX_COLUMNS]) {
    for (int currentRowIndex = 0; currentRowIndex < TARGET_MATRIX_ROWS; currentRowIndex++) {
        for (int currentColumnIndex = 0; currentColumnIndex < TARGET_MATRIX_COLUMNS; currentColumnIndex++) {
            printf("%d\t", matrix[currentRowIndex][currentColumnIndex]);
        }
        printf("\n");
    }
}

// Perform scalar matrix multiplication.
// Declarative function signatures for dynamic tracking
void performDynamicScalarMultiplication(
    int activeRows,
    int activeColumns,
    int workingMatrix[][4],
    int scalarFactorValue,
    int outputResultMatrix[][4]
);

void printDynamicMatrixLayout(
    int activeRows,
    int activeColumns,
    int matrixInstance[][4]
);

int ScalarMatrixMultiplication() {
    // Explicitly defining dynamic dimension sizes
    const int configuredRowsTotal = 2;
    const int configuredColumnsTotal = 4;

    // A 2x4 layout structure example
    int sourceUserMatrix[2][4] = {
        {1, 3, 5, 7},
        {2, 4, 6, 8}
    };

    int numericScalingFactor = 10;
    int productDestinationMatrix[2][4];

    // Compute transformation
    performDynamicScalarMultiplication(
        configuredRowsTotal, 
        configuredColumnsTotal, 
        sourceUserMatrix, 
        numericScalingFactor, 
        productDestinationMatrix
    );

    printf("Initial Data Stream:\n");
    printDynamicMatrixLayout(configuredRowsTotal, configuredColumnsTotal, sourceUserMatrix);
    
    printf("\nMultiplication Factor Appended: %d\n\n", numericScalingFactor);
    
    printf("Computed Data Stream Result:\n");
    printDynamicMatrixLayout(configuredRowsTotal, configuredColumnsTotal, productDestinationMatrix);

    return 0;
}

// Multiplies the matrix elements without using hardcoded boundaries
void performDynamicScalarMultiplication(
    int activeRows, 
    int activeColumns, 
    int workingMatrix[][4], 
    int scalarFactorValue, 
    int outputResultMatrix[][4]
) {
    for (int trackingRowIndex = 0; trackingRowIndex < activeRows; trackingRowIndex++) {
        for (int trackingColumnIndex = 0; trackingColumnIndex < activeColumns; trackingColumnIndex++) {
            
            outputResultMatrix[trackingRowIndex][trackingColumnIndex] = 
                workingMatrix[trackingRowIndex][trackingColumnIndex] * scalarFactorValue;
                
        }
    }
}

// Iterates across dynamic dimensions for visualization
void printDynamicMatrixLayout(
    int activeRows, 
    int activeColumns, 
    int matrixInstance[][4]
) {
    for (int trackingRowIndex = 0; trackingRowIndex < activeRows; trackingRowIndex++) {
        for (int trackingColumnIndex = 0; trackingColumnIndex < activeColumns; trackingColumnIndex++) {
            printf("%d\t", matrixInstance[trackingRowIndex][trackingColumnIndex]);
        }
        printf("\n");
    }
}




// Multiply two matrices.
#define FIRST_MATRIX_ROWS_LIMIT 3
#define SHARED_DIMENSION_LIMIT 2
#define SECOND_MATRIX_COLUMNS_LIMIT 3

// Function declarations
void executeMatrixMultiplication(
    int firstInputMatrix[FIRST_MATRIX_ROWS_LIMIT][SHARED_DIMENSION_LIMIT],
    int secondInputMatrix[SHARED_DIMENSION_LIMIT][SECOND_MATRIX_COLUMNS_LIMIT],
    int outputProductMatrix[FIRST_MATRIX_ROWS_LIMIT][SECOND_MATRIX_COLUMNS_LIMIT]
);

void printArbitraryMatrixStructure(int totalRows, int totalColumns, int *matrixPointer);

int MultiplyTwoMatrices() {
    // Matrix A: 3 rows by 2 columns
    int firstUserMatrix[FIRST_MATRIX_ROWS_LIMIT][SHARED_DIMENSION_LIMIT] = {
        {1, 4},
        {2, 5},
        {3, 6}
    };

    // Matrix B: 2 rows by 3 columns
    int secondUserMatrix[SHARED_DIMENSION_LIMIT][SECOND_MATRIX_COLUMNS_LIMIT] = {
        {7, 8, 9},
        {1, 2, 3}
    };

    // Result Matrix C: 3 rows by 3 columns
    int resultingProductMatrix[FIRST_MATRIX_ROWS_LIMIT][SECOND_MATRIX_COLUMNS_LIMIT];

    // Execute the matrix multiplication algorithm
    executeMatrixMultiplication(firstUserMatrix, secondUserMatrix, resultingProductMatrix);

    printf("--- Matrix A (3x2) ---\n");
    printArbitraryMatrixStructure(FIRST_MATRIX_ROWS_LIMIT, SHARED_DIMENSION_LIMIT, (int *)firstUserMatrix);
    
    printf("\n--- Matrix B (2x3) ---\n");
    printArbitraryMatrixStructure(SHARED_DIMENSION_LIMIT, SECOND_MATRIX_COLUMNS_LIMIT, (int *)secondUserMatrix);
    
    printf("\n--- Resulting Product Matrix C (3x3) ---\n");
    printArbitraryMatrixStructure(FIRST_MATRIX_ROWS_LIMIT, SECOND_MATRIX_COLUMNS_LIMIT, (int *)resultingProductMatrix);

    return 0;
}

// Multiplies Matrix A and Matrix B into Output Matrix
void executeMatrixMultiplication(
    int firstInputMatrix[FIRST_MATRIX_ROWS_LIMIT][SHARED_DIMENSION_LIMIT],
    int secondInputMatrix[SHARED_DIMENSION_LIMIT][SECOND_MATRIX_COLUMNS_LIMIT],
    int outputProductMatrix[FIRST_MATRIX_ROWS_LIMIT][SECOND_MATRIX_COLUMNS_LIMIT]
) {
    for (int trackingRowIndexA = 0; trackingRowIndexA < FIRST_MATRIX_ROWS_LIMIT; trackingRowIndexA++) {
        for (int trackingColumnIndexB = 0; trackingColumnIndexB < SECOND_MATRIX_COLUMNS_LIMIT; trackingColumnIndexB++) {
            
            // Initialize the container element to zero before accumulating products
            int currentCellRunningSum = 0;

            // Iterate through the shared inner dimension 
            for (int sharedKDimensionIndex = 0; sharedKDimensionIndex < SHARED_DIMENSION_LIMIT; sharedKDimensionIndex++) {
                currentCellRunningSum += firstInputMatrix[trackingRowIndexA][sharedKDimensionIndex] * secondInputMatrix[sharedKDimensionIndex][trackingColumnIndexB];
            }

            outputProductMatrix[trackingRowIndexA][trackingColumnIndexB] = currentCellRunningSum;
        }
    }
}

// Universal display method using variable parameters
void printArbitraryMatrixStructure(int totalRows, int totalColumns, int *matrixPointer) {
    for (int currentRowCounter = 0; currentRowCounter < totalRows; currentRowCounter++) {
        for (int currentColumnCounter = 0; currentColumnCounter < totalColumns; currentColumnCounter++) {
            int value = matrixPointer[currentRowCounter * totalColumns + currentColumnCounter];
            printf("%d\t", value);
        }
        printf("\n");
    }
}





// Check whether two matrices are equal or not.
#define CONFIGURED_ROWS_LIMIT 3
#define CONFIGURED_COLUMNS_LIMIT 3

// Declarative custom definitions replacing stdbool functionality
#define FALSE_VALUE_REPRESENTATION 0
#define TRUE_VALUE_REPRESENTATION 1

// Function declarations returning an integer as a boolean flag status
int checkMatrixEquality(
    int firstInputMatrix[CONFIGURED_ROWS_LIMIT][CONFIGURED_COLUMNS_LIMIT], 
    int secondInputMatrix[CONFIGURED_ROWS_LIMIT][CONFIGURED_COLUMNS_LIMIT]
);

int matricesEqualOrNot() {
    // Declarative setup of Matrix Instance A
    int userMatrixDatasetA[CONFIGURED_ROWS_LIMIT][CONFIGURED_COLUMNS_LIMIT] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    // Declarative setup of Matrix Instance B (Identical to A)
    int userMatrixDatasetB[CONFIGURED_ROWS_LIMIT][CONFIGURED_COLUMNS_LIMIT] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    // Declarative setup of Matrix Instance C (Different element at last index)
    int userMatrixDatasetC[CONFIGURED_ROWS_LIMIT][CONFIGURED_COLUMNS_LIMIT] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 95}
    };

    printf("--- Evaluating Matrix A and Matrix B ---\n");
    if (checkMatrixEquality(userMatrixDatasetA, userMatrixDatasetB) == TRUE_VALUE_REPRESENTATION) {
        printf("Result: Matrix A and Matrix B are perfectly equal.\n\n");
    } else {
        printf("Result: Matrix A and Matrix B are NOT equal.\n\n");
    }

    printf("--- Evaluating Matrix A and Matrix C ---\n");
    if (checkMatrixEquality(userMatrixDatasetA, userMatrixDatasetC) == TRUE_VALUE_REPRESENTATION) {
        printf("Result: Matrix A and Matrix C are perfectly equal.\n");
    } else {
        printf("Result: Matrix A and Matrix C are NOT equal.\n");
    }

    return 0;
}

// Function that returns an integer (1 or 0) indicating equality status
int checkMatrixEquality(
    int firstInputMatrix[CONFIGURED_ROWS_LIMIT][CONFIGURED_COLUMNS_LIMIT], 
    int secondInputMatrix[CONFIGURED_ROWS_LIMIT][CONFIGURED_COLUMNS_LIMIT]
) {
    // Initialize flag state using the custom macro representation
    int complianceIdentityStatusFlag = TRUE_VALUE_REPRESENTATION;

    for (int currentRowIndex = 0; currentRowIndex < CONFIGURED_ROWS_LIMIT; currentRowIndex++) {
        for (int currentColumnIndex = 0; currentColumnIndex < CONFIGURED_COLUMNS_LIMIT; currentColumnIndex++) {
            
            // Compare items sharing matching coordinates
            if (firstInputMatrix[currentRowIndex][currentColumnIndex] != secondInputMatrix[currentRowIndex][currentColumnIndex]) {
                complianceIdentityStatusFlag = FALSE_VALUE_REPRESENTATION;
                break; // Break out of the inner column tracking loop
            }
            
        }
        if (complianceIdentityStatusFlag == FALSE_VALUE_REPRESENTATION) {
            break; // Break out of the outer row tracking loop
        }
    }

    return complianceIdentityStatusFlag;
}



int main(void) {
    matricesEqualOrNot();
    summationDiagonalsMatrix();
    summationOfMinorDiagonals();
    matricesEqualOrNot();
    sumOfEachRowAndColumn();
    subtractTwoMatrices();
    MultiplyTwoMatrices();
    ScalarMatrixMultiplication();
    return 0;
}
