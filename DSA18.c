/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/

#include <stdio.h>
#include <stddef.h>

#define ARRAY_MAXIMUM_CAPACITY_LIMIT 5


// Add Two Numbers Using Pointers
void addTwoNumbersUsingPointers(const int *firstAddendPointer, const int *secondAddendPointer, int *summationResultPointer)
{
    *summationResultPointer = *firstAddendPointer + *secondAddendPointer;
}


// Swap Two Numbers Using Pointers
void swapTwoIntegerValuesUsingPointers(int *firstIntegerSwappingTarget, int *secondIntegerSwappingTarget)
{
    int temporaryValueHolder = *firstIntegerSwappingTarget;
    *firstIntegerSwappingTarget = *secondIntegerSwappingTarget;
    *secondIntegerSwappingTarget = temporaryValueHolder;
}


// Input and Print Array Elements Using a Pointer
void printArrayElementsUsingPointer(const int *arrayBaseAddressPointer, size_t totalElementsInArray)
{
    const int *arrayIterationPointer = arrayBaseAddressPointer;
    for (size_t indexCounter = 0; indexCounter < totalElementsInArray; indexCounter++)
    {
        // Accessing value by dereferencing the shifted pointer
        printf("%d ", *(arrayIterationPointer + indexCounter));
    }
    printf("\n");
}


// Copy One Array to Another Using Pointers
void copyArrayToAnotherUsingPointers(const int *sourceArrayBaseAddress, int *destinationArrayBaseAddress, size_t totalElementsToCopy)
{
    const int *sourceIterationPointer = sourceArrayBaseAddress;
    int *destinationIterationPointer = destinationArrayBaseAddress;

    for (size_t indexCounter = 0; indexCounter < totalElementsToCopy; indexCounter++)
    {
        *destinationIterationPointer = *sourceIterationPointer;
        sourceIterationPointer++;
        destinationIterationPointer++;
    }
}


// Swap Two Arrays Using Pointers (Swapping Element Contents)
void swapTwoArrayContentsUsingPointers(int *firstArrayBaseAddress, int *secondArrayBaseAddress, size_t arrayElementsCount)
{
    int *firstArrayIterationPointer = firstArrayBaseAddress;
    int *secondArrayIterationPointer = secondArrayBaseAddress;

    for (size_t indexCounter = 0; indexCounter < arrayElementsCount; indexCounter++)
    {
        int temporaryValueHolder = *firstArrayIterationPointer;
        *firstArrayIterationPointer = *secondArrayIterationPointer;
        *secondArrayIterationPointer = temporaryValueHolder;

        firstArrayIterationPointer++;
        secondArrayIterationPointer++;
    }
}


// Reverse an Array Using Pointers
void reverseArrayInPlaceUsingPointers(int *arrayBaseAddressPointer, size_t totalElementsInArray)
{
    int *leftSideTrackingPointer = arrayBaseAddressPointer;
    int *rightSideTrackingPointer = arrayBaseAddressPointer + totalElementsInArray - 1;

    while (leftSideTrackingPointer < rightSideTrackingPointer)
    {
        int temporaryValueHolder = *leftSideTrackingPointer;
        *leftSideTrackingPointer = *rightSideTrackingPointer;
        *rightSideTrackingPointer = temporaryValueHolder;

        leftSideTrackingPointer++;
        rightSideTrackingPointer--;
    }
}


//  Search an Element in an Array Using Pointers
int *searchElementInArrayUsingPointers(const int *arrayBaseAddressPointer, size_t totalElementsInArray, int targetingSearchValue)
{
    const int *arrayIterationPointer = arrayBaseAddressPointer;

    for (size_t indexCounter = 0; indexCounter < totalElementsInArray; indexCounter++)
    {
        if (*arrayIterationPointer == targetingSearchValue)
        {
            return (int *)arrayIterationPointer;
        }
        arrayIterationPointer++;
    }
    return NULL; 
}


// Main Execution Driver

int main(void)
{
    printf("--- POINTER AND ARRAY OPERATIONS DEMO ---\n\n");

    // 1 & 2: Math and Swapping scalars
    int primaryNumericValue = 45;
    int secondaryNumericValue = 15;
    int arithmeticSummationOutput = 0;

    addTwoNumbersUsingPointers(&primaryNumericValue, &secondaryNumericValue, &arithmeticSummationOutput);
    printf("1. Addition Result: %d + %d = %d\n", primaryNumericValue, secondaryNumericValue, arithmeticSummationOutput);

    swapTwoIntegerValuesUsingPointers(&primaryNumericValue, &secondaryNumericValue);
    printf("2. Swap Scalars Result: Primary is now %d, Secondary is now %d\n\n", primaryNumericValue, secondaryNumericValue);

    // 3: Array Mock Input & Display
    int primaryDataStorageArray[ARRAY_MAXIMUM_CAPACITY_LIMIT] = {10, 20, 30, 40, 50};
    printf("3. Print Array via Pointer: ");
    printArrayElementsUsingPointer(primaryDataStorageArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);

    // 4: Copy Array
    int secondaryTargetDuplicateArray[ARRAY_MAXIMUM_CAPACITY_LIMIT] = {0};
    copyArrayToAnotherUsingPointers(primaryDataStorageArray, secondaryTargetDuplicateArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);
    printf("4. Copied Array Result:     ");
    printArrayElementsUsingPointer(secondaryTargetDuplicateArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);

    // 5: Swap Arrays
    int tertiaryAlternativeDataArray[ARRAY_MAXIMUM_CAPACITY_LIMIT] = {99, 88, 77, 66, 55};
    printf("\n5. Before Array Swap:\n");
    printf("   Array A: ");
    printArrayElementsUsingPointer(primaryDataStorageArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);
    printf("   Array B: ");
    printArrayElementsUsingPointer(tertiaryAlternativeDataArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);

    swapTwoArrayContentsUsingPointers(primaryDataStorageArray, tertiaryAlternativeDataArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);

    printf("   After Array Swap:\n");
    printf("   Array A: ");
    printArrayElementsUsingPointer(primaryDataStorageArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);
    printf("   Array B: ");
    printArrayElementsUsingPointer(tertiaryAlternativeDataArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);

    // 6: Reverse Array
    printf("\n6. Before Reversing Array B: ");
    printArrayElementsUsingPointer(tertiaryAlternativeDataArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);
    reverseArrayInPlaceUsingPointers(tertiaryAlternativeDataArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);
    printf("   After Reversing Array B:  ");
    printArrayElementsUsingPointer(tertiaryAlternativeDataArray, ARRAY_MAXIMUM_CAPACITY_LIMIT);

    // 7: Search Array
    int itemToLocateWithinArray = 40;
    printf("\n7. Searching for value (%d) in Array B...\n", itemToLocateWithinArray);
    int *memoryAddressResultOfSearch = searchElementInArrayUsingPointers(tertiaryAlternativeDataArray, ARRAY_MAXIMUM_CAPACITY_LIMIT, itemToLocateWithinArray);

    if (memoryAddressResultOfSearch != NULL)
    {
        ptrdiff_t numericalIndexLocationOffset = memoryAddressResultOfSearch - tertiaryAlternativeDataArray;
        printf("   Found value %d at array index position: %td\n", *memoryAddressResultOfSearch, numericalIndexLocationOffset);
    }
    else
    {
        printf("   Value %d was not found in the target array.\n", itemToLocateWithinArray);
    }

    return 0;
}
