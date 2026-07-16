/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/

#include <stdio.h>
// Merge two arrays to the third array.
int twoArray2NewArray()
{
    int numbers[] = {4, 5, 9, 4, 7, 5, 2, 8, 2};
    int total_elements = sizeof(numbers) / sizeof(numbers[0]);
    printf("Unique elements in the array: ");

    for (int i = 0; i < total_elements; i++)
    {
        int match_count = 0;
        for (int j = 0; j < total_elements; j++)
        {
            if (numbers[i] == numbers[j])
            {
                match_count++;
            }
        }

        // If the element appeared exactly once, it is unique
        if (match_count == 1)
        {
            printf("%d ", numbers[i]);
        }
    }
}

// Search an element in an array
int elementsOfArray()
{
    // Linear Search in an arry.
    int numbers[] = {12, 45, 7, 93, 21, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]); // Calculates array length
    int target = 93;                                 // The element we want to find
    int foundIndex = -1;                             // -1 means not found

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] == target)
        {
            foundIndex = i; // Store the index where it was found
            break;          // Exit loop early since we found it
        }
    }

    if (foundIndex != -1)
    {
        printf("Element %d found at index %d.\n", target, foundIndex);
    }
    else
    {
        printf("Element %d not found.\n", target);
    }

    return 0;
}

// Sort array elements in ascending or descending order.
int arrayElementsInAscendingOrDescendingOrder()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort Algorithm
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Change '>' to '<' for Descending order
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
// Left rotate an array.
int leftRotateArray()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Save the first element and shift everything left in one loop
    int first = arr[0], i = 0;
    for (; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = first; // Place first element at the end

    // Print result
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}

//  Right rotate an array.
// Function to reverse a specific segment of the array
void reverseSegment(int arrayToRotate[], int startIndex, int endIndex)
{
    while (startIndex < endIndex)
    {
        int temporaryStorage = arrayToRotate[startIndex];
        arrayToRotate[startIndex] = arrayToRotate[endIndex];
        arrayToRotate[endIndex] = temporaryStorage;

        startIndex++;
        endIndex--;
    }
}

// Function to perform right rotation
void performRightRotation(int arrayToRotate[], int totalElements, int rotationSteps)
{
    // Optimization: if rotationSteps > totalElements, use modulus
    rotationSteps = rotationSteps % totalElements;

    // 1. Reverse the entire array
    reverseSegment(arrayToRotate, 0, totalElements - 1);

    // 2. Reverse the first 'rotationSteps' elements
    reverseSegment(arrayToRotate, 0, rotationSteps - 1);

    // 3. Reverse the remaining elements
    reverseSegment(arrayToRotate, rotationSteps, totalElements - 1);
}

int rightRotateOfArryCall()
{
    int dataPoints[] = {10, 20, 30, 40, 50};
    int numberOfElements = 5;
    int shiftCount = 2;

    performRightRotation(dataPoints, numberOfElements, shiftCount);

    for (int i = 0; i < numberOfElements; i++)
    {
        printf("%d ", dataPoints[i]);
    }
    return 0;
}
// Add two matrices.
int additionOf2Matrices()
{
    // Defining dimensions
    int rows = 2;
    int columns = 3;

    // Initialize two 2D arrays (matrices)
    int matrixA[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    int matrixB[2][3] = {
        {7, 8, 9},
        {10, 11, 12}};

    // Matrix to store the result of the addition
    int sumMatrix[2][3];

    // Nested loops to traverse every row and every column
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {

            // Perform element-wise addition
            sumMatrix[rowIndex][columnIndex] = matrixA[rowIndex][columnIndex] + matrixB[rowIndex][columnIndex];
        }
    }

    // Displaying the result
    printf("The sum of the two matrices is:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            printf("%d ", sumMatrix[rowIndex][columnIndex]);
        }
        printf("\n"); // Move to next line after printing a row
    }

    return 0;
}

// Subtract two matrices.

int subtract2Matrices()
{
    // Defining dimensions
    int rows = 2;
    int columns = 3;

    // Initialize two 2D arrays (matrices)
    int matrixA[2][3] = {
        {10, 20, 30},
        {40, 50, 60}};

    int matrixB[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    // Matrix to store the result of the subtraction
    int diffMatrix[2][3];

    // Nested loops to traverse every row and every column
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {

            // Perform element-wise subtraction
            diffMatrix[rowIndex][columnIndex] = matrixA[rowIndex][columnIndex] - matrixB[rowIndex][columnIndex];
        }
    }

    // Displaying the result
    printf("The difference of the two matrices is:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            printf("%d ", diffMatrix[rowIndex][columnIndex]);
        }
        printf("\n"); // Move to next line after printing a row
    }

    return 0;
}

// Perform scalar matrix multiplication.
int scalarMatrixMultiplication()
{
    int rows = 2;
    int columns = 3;
    int scalarValue = 5; // The constant to multiply by

    int matrixA[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    int resultMatrix[2][3];

    // Nested loops to traverse every element
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {

            // Multiply the current element by the scalar
            resultMatrix[rowIndex][columnIndex] = matrixA[rowIndex][columnIndex] * scalarValue;
        }
    }

    // Displaying the result
    printf("The matrix after multiplying by scalar %d is:\n", scalarValue);
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            printf("%d ", resultMatrix[rowIndex][columnIndex]);
        }
        printf("\n");
    }

    return 0;
}

int main()
{
    rightRotateOfArryCall();

    return 0;
}
