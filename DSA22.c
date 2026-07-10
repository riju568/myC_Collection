#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


// Linear Search
int executeLinearSearch(int targetArray[], int totalElements, int searchTarget)
{
    for (int currentIndex = 0; currentIndex < totalElements; currentIndex++)
    {
        if (targetArray[currentIndex] == searchTarget)
        {
            return currentIndex;
        }
    }
    return -1; /* Target not found */
}

int executeIterativeBinarySearch(int sortedArray[], int totalElements, int searchTarget)
{
    int leftBoundaryIndex = 0;
    int rightBoundaryIndex = totalElements - 1;

    while (leftBoundaryIndex <= rightBoundaryIndex)
    {
        int middleIndex = leftBoundaryIndex + (rightBoundaryIndex - leftBoundaryIndex) / 2;

        if (sortedArray[middleIndex] == searchTarget)
        {
            return middleIndex;
        }
        if (sortedArray[middleIndex] < searchTarget)
        {
            leftBoundaryIndex = middleIndex + 1;
        }
        else
        {
            rightBoundaryIndex = middleIndex - 1;
        }
    }
    return -1;
}

int executeRecursiveBinarySearch(int sortedArray[], int leftBoundaryIndex, int rightBoundaryIndex, int searchTarget)
{
    if (leftBoundaryIndex <= rightBoundaryIndex)
    {
        int middleIndex = leftBoundaryIndex + (rightBoundaryIndex - leftBoundaryIndex) / 2;

        if (sortedArray[middleIndex] == searchTarget)
        {
            return middleIndex;
        }
        if (sortedArray[middleIndex] < searchTarget)
        {
            return executeRecursiveBinarySearch(sortedArray, middleIndex + 1, rightBoundaryIndex, searchTarget);
        }
        return executeRecursiveBinarySearch(sortedArray, leftBoundaryIndex, middleIndex - 1, searchTarget);
    }
    return -1;
}

/* Star Pattern Printing (Pyramid) */
void printStarPatternPyramid(int totalRowsRequired)
{
    for (int currentRow = 1; currentRow <= totalRowsRequired; currentRow++)
    {
        for (int spaceCount = 1; spaceCount <= totalRowsRequired - currentRow; spaceCount++)
        {
            printf(" ");
        }
        for (int starCount = 1; starCount <= (2 * currentRow - 1); starCount++)
        {
            printf("*");
        }
        printf("\n");
    }
}

/* Print numbers from 1 to n without using a semicolon */
void printSequenceWithoutSemicolon(int maximumLimit)
{
    int currentValue = 1;
    while (currentValue <= maximumLimit && printf("%d ", currentValue) && currentValue++)
    {
    }
    printf("\n");
}

/*  Sum of two numbers without using any operator (meaning without arithmetic +, - etc) */
int calculateSumWithoutArithmetic(int firstValue, int secondValue)
{
    int carryValueHolder;
    while (secondValue != 0)
    {
        carryValueHolder = firstValue & secondValue;
        firstValue = firstValue ^ secondValue;
        secondValue = carryValueHolder << 1;
    }
    return firstValue;
}

/* 4. How to show memory representation of C variables */
void displayMemoryRepresentation(void *variablePointer, size_t sizeOfVariableInBytes)
{
    unsigned char *bytePointer = (unsigned char *)variablePointer;
    printf("Memory Bytes (Hex): ");
    for (size_t byteIndex = 0; byteIndex < sizeOfVariableInBytes; byteIndex++)
    {
        printf("%02X ", bytePointer[byteIndex]);
    }
    printf("\n");
}

/* 5. Condition to print "HelloWorld" */
void executeHelloWorldPuzzle(void)
{
    if (!printf("Hello"))
    {
        printf("Fail");
    }
    else
    {
        printf("World\n");
    }
}

/* 6. Modify/add only one character and print '*' exactly 20 times */
void executeTwentyStarsPuzzle(void)
{
    int maximumIterations = 20;
    for (int loopCounter = 0; -loopCounter < maximumIterations; loopCounter--)
    {
        printf("*");
    }
    printf("\n");
}

/* Sum the digits of a given number in a single statement */
int sumDigitsInSingleStatement(int targetNumber)
{
    return (targetNumber == 0) ? 0 : (targetNumber % 10) + sumDigitsInSingleStatement(targetNumber / 10);
}

int main(void)
{
    printf("SEARCHING ALGORITHMS\n\n");

    int sortedDataset[] = {12, 24, 35, 47, 59, 61, 78, 84, 93, 105};
    int totalElementsInDataset = sizeof(sortedDataset) / sizeof(sortedDataset[0]);
    int searchTargetValue = 78;

    printf("Dataset: ");
    for (int printIndex = 0; printIndex < totalElementsInDataset; printIndex++)
    {
        printf("%d ", sortedDataset[printIndex]);
    }
    printf("\nSearching for Target: %d\n\n", searchTargetValue);

    int linearResultIndex = executeLinearSearch(sortedDataset, totalElementsInDataset, searchTargetValue);
    printf("[Linear Search] Found at index: %d\n", linearResultIndex);

    int iterativeBinaryResultIndex = executeIterativeBinarySearch(sortedDataset, totalElementsInDataset, searchTargetValue);
    printf("[Iterative Binary Search] Found at index: %d\n", iterativeBinaryResultIndex);

    int recursiveBinaryResultIndex = executeRecursiveBinarySearch(sortedDataset, 0, totalElementsInDataset - 1, searchTargetValue);
    printf("[Recursive Binary Search] Found at index: %d\n\n", recursiveBinaryResultIndex);

    printf(" PUZZLE QUESTIONS\n\n");

    printf("Star Pattern Printing (5 Rows):\n");
    printStarPatternPyramid(5);
    printf("\n");

    printf("Print 1 to 10 without semicolon:\n");
    printSequenceWithoutSemicolon(10);
    printf("\n");

    int numberOne = 15, numberTwo = 27;
    printf("Sum of %d and %d without arithmetic operators: %d\n\n",
           numberOne, numberTwo, calculateSumWithoutArithmetic(numberOne, numberTwo));

    float sampleFloatVariable = 3.14159f;
    printf("Memory representation of float (Value: %f):\n", sampleFloatVariable);
    displayMemoryRepresentation(&sampleFloatVariable, sizeof(sampleFloatVariable));
    printf("\n");

    printf("Condition to print \"HelloWorld\":\nResult: ");
    executeHelloWorldPuzzle();
    printf("\n");

    printf("Print '*' 20 times by modifying one character in buggy loop:\nResult: ");
    executeTwentyStarsPuzzle();
    printf("\n");

    int longNumber = 84592;
    printf("Sum of digits in a single statement (Number: %d):\nResult: %d\n\n",
           longNumber, sumDigitsInSingleStatement(longNumber));

    return 0;
}
