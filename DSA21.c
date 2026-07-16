/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// UTILITY FUNCTIONS
void swapElements(int *firstElementPointer, int *secondElementPointer)
{
    int temporaryStorage = *firstElementPointer;
    *firstElementPointer = *secondElementPointer;
    *secondElementPointer = temporaryStorage;
}

void printArrayElements(const char *sortName, int targetArray[], int totalElements)
{
    printf("[%s]:\n", sortName);
    for (int currentIndex = 0; currentIndex < totalElements; currentIndex++)
    {
        printf("%d ", targetArray[currentIndex]);
    }
    printf("\n\n");
}

// BUBBLE SORT
void executeBubbleSort(int targetArray[], int arrayLength)
{
    for (int outerPass = 0; outerPass < arrayLength - 1; outerPass++)
    {
        for (int innerCompareIndex = 0; innerCompareIndex < arrayLength - outerPass - 1; innerCompareIndex++)
        {
            if (targetArray[innerCompareIndex] > targetArray[innerCompareIndex + 1])
            {
                swapElements(&targetArray[innerCompareIndex], &targetArray[innerCompareIndex + 1]);
            }
        }
    }
}

// SELECTION SORT
void executeSelectionSort(int targetArray[], int arrayLength)
{
    for (int currentStepIndex = 0; currentStepIndex < arrayLength - 1; currentStepIndex++)
    {
        int minimumValueIndex = currentStepIndex;
        for (int searchIndex = currentStepIndex + 1; searchIndex < arrayLength; searchIndex++)
        {
            if (targetArray[searchIndex] < targetArray[minimumValueIndex])
            {
                minimumValueIndex = searchIndex;
            }
        }
        swapElements(&targetArray[minimumValueIndex], &targetArray[currentStepIndex]);
    }
}

// INSERTION SORT
void executeInsertionSort(int targetArray[], int arrayLength)
{
    for (int stepIndex = 1; stepIndex < arrayLength; stepIndex++)
    {
        int keyElementToInsert = targetArray[stepIndex];
        int previousElementIndex = stepIndex - 1;

        while (previousElementIndex >= 0 && targetArray[previousElementIndex] > keyElementToInsert)
        {
            targetArray[previousElementIndex + 1] = targetArray[previousElementIndex];
            previousElementIndex--;
        }
        targetArray[previousElementIndex + 1] = keyElementToInsert;
    }
}

// SHELL SORT
void executeShellSort(int targetArray[], int arrayLength)
{
    for (int currentGapSize = arrayLength / 2; currentGapSize > 0; currentGapSize /= 2)
    {
        for (int currentIndex = currentGapSize; currentIndex < arrayLength; currentIndex++)
        {
            int temporaryElement = targetArray[currentIndex];
            int shiftIndex;

            for (shiftIndex = currentIndex;
                 shiftIndex >= currentGapSize && targetArray[shiftIndex - currentGapSize] > temporaryElement;
                 shiftIndex -= currentGapSize)
            {
                targetArray[shiftIndex] = targetArray[shiftIndex - currentGapSize];
            }
            targetArray[shiftIndex] = temporaryElement;
        }
    }
}

// MERGE SORT
void mergeSubArrays(int targetArray[], int leftBoundaryIndex, int middlePointIndex, int rightBoundaryIndex)
{
    int leftPartitionSize = middlePointIndex - leftBoundaryIndex + 1;
    int rightPartitionSize = rightBoundaryIndex - middlePointIndex;

    int *leftTemporaryArray = malloc(leftPartitionSize * sizeof(int));
    int *rightTemporaryArray = malloc(rightPartitionSize * sizeof(int));

    for (int copyLeftIndex = 0; copyLeftIndex < leftPartitionSize; copyLeftIndex++)
    {
        leftTemporaryArray[copyLeftIndex] = targetArray[leftBoundaryIndex + copyLeftIndex];
    }
    for (int copyRightIndex = 0; copyRightIndex < rightPartitionSize; copyRightIndex++)
    {
        rightTemporaryArray[copyRightIndex] = targetArray[middlePointIndex + 1 + copyRightIndex];
    }

    int trackingLeftIndex = 0;
    int trackingRightIndex = 0;
    int mergedArrayIndex = leftBoundaryIndex;

    while (trackingLeftIndex < leftPartitionSize && trackingRightIndex < rightPartitionSize)
    {
        if (leftTemporaryArray[trackingLeftIndex] <= rightTemporaryArray[trackingRightIndex])
        {
            targetArray[mergedArrayIndex] = leftTemporaryArray[trackingLeftIndex];
            trackingLeftIndex++;
        }
        else
        {
            targetArray[mergedArrayIndex] = rightTemporaryArray[trackingRightIndex];
            trackingRightIndex++;
        }
        mergedArrayIndex++;
    }

    while (trackingLeftIndex < leftPartitionSize)
    {
        targetArray[mergedArrayIndex] = leftTemporaryArray[trackingLeftIndex];
        trackingLeftIndex++;
        mergedArrayIndex++;
    }

    while (trackingRightIndex < rightPartitionSize)
    {
        targetArray[mergedArrayIndex] = rightTemporaryArray[trackingRightIndex];
        trackingRightIndex++;
        mergedArrayIndex++;
    }

    free(leftTemporaryArray);
    free(rightTemporaryArray);
}

void executeMergeSort(int targetArray[], int leftBoundaryIndex, int rightBoundaryIndex)
{
    if (leftBoundaryIndex < rightBoundaryIndex)
    {
        int middlePointIndex = leftBoundaryIndex + (rightBoundaryIndex - leftBoundaryIndex) / 2;
        executeMergeSort(targetArray, leftBoundaryIndex, middlePointIndex);
        executeMergeSort(targetArray, middlePointIndex + 1, rightBoundaryIndex);
        mergeSubArrays(targetArray, leftBoundaryIndex, middlePointIndex, rightBoundaryIndex);
    }
}

// 6. HEAP SORT

void organizeHeapShape(int targetArray[], int arrayLength, int rootNodeIndex)
{
    int largestValueIndex = rootNodeIndex;
    int leftChildNodeIndex = 2 * rootNodeIndex + 1;
    int rightChildNodeIndex = 2 * rootNodeIndex + 2;

    if (leftChildNodeIndex < arrayLength && targetArray[leftChildNodeIndex] > targetArray[largestValueIndex])
    {
        largestValueIndex = leftChildNodeIndex;
    }

    if (rightChildNodeIndex < arrayLength && targetArray[rightChildNodeIndex] > targetArray[largestValueIndex])
    {
        largestValueIndex = rightChildNodeIndex;
    }

    if (largestValueIndex != rootNodeIndex)
    {
        swapElements(&targetArray[rootNodeIndex], &targetArray[largestValueIndex]);
        organizeHeapShape(targetArray, arrayLength, largestValueIndex);
    }
}

void executeHeapSort(int targetArray[], int arrayLength)
{
    for (int initialStructureNode = arrayLength / 2 - 1; initialStructureNode >= 0; initialStructureNode--)
    {
        organizeHeapShape(targetArray, arrayLength, initialStructureNode);
    }
    for (int extractionNodeIndex = arrayLength - 1; extractionNodeIndex > 0; extractionNodeIndex--)
    {
        swapElements(&targetArray[0], &targetArray[extractionNodeIndex]);
        organizeHeapShape(targetArray, extractionNodeIndex, 0);
    }
}

// 7. RADIX SORT

int findMaximumValue(int targetArray[], int arrayLength)
{
    int absoluteMaximum = targetArray[0];
    for (int searchIndex = 1; searchIndex < arrayLength; searchIndex++)
    {
        if (targetArray[searchIndex] > absoluteMaximum)
        {
            absoluteMaximum = targetArray[searchIndex];
        }
    }
    return absoluteMaximum;
}

void countingSortForRadix(int targetArray[], int arrayLength, int currentPlaceValue)
{
    int *temporaryOutputArray = malloc(arrayLength * sizeof(int));
    int digitFrequencyCount[10] = {0};

    for (int frequencyIndex = 0; frequencyIndex < arrayLength; frequencyIndex++)
    {
        int isolatedDigit = (targetArray[frequencyIndex] / currentPlaceValue) % 10;
        digitFrequencyCount[isolatedDigit]++;
    }

    for (int cumulativeIndex = 1; cumulativeIndex < 10; cumulativeIndex++)
    {
        digitFrequencyCount[cumulativeIndex] += digitFrequencyCount[cumulativeIndex - 1];
    }

    for (int reversePlacementIndex = arrayLength - 1; reversePlacementIndex >= 0; reversePlacementIndex--)
    {
        int isolatedDigit = (targetArray[reversePlacementIndex] / currentPlaceValue) % 10;
        temporaryOutputArray[digitFrequencyCount[isolatedDigit] - 1] = targetArray[reversePlacementIndex];
        digitFrequencyCount[isolatedDigit]--;
    }

    for (int finalCopyIndex = 0; finalCopyIndex < arrayLength; finalCopyIndex++)
    {
        targetArray[finalCopyIndex] = temporaryOutputArray[finalCopyIndex];
    }

    free(temporaryOutputArray);
}

void executeRadixSort(int targetArray[], int arrayLength)
{
    int maximumElementInArray = findMaximumValue(targetArray, arrayLength);
    for (int processingPlaceValue = 1; maximumElementInArray / processingPlaceValue > 0; processingPlaceValue *= 10)
    {
        countingSortForRadix(targetArray, arrayLength, processingPlaceValue);
    }
}

int main(void)
{
    int originalBaseDataset[] = {88, 14, 39, 72, 55, 23, 91, 19, 66, 8, 41, 105};
    int totalElementsInDataset = sizeof(originalBaseDataset) / sizeof(originalBaseDataset[0]);


    int *activeWorkingArray = malloc(totalElementsInDataset * sizeof(int));

    printf("=== SORTING ALGORITHMS DISPLAY ===\n\n");
    printArrayElements("Original Unsorted Dataset", originalBaseDataset, totalElementsInDataset);

    /*  Bubble Sort */
    memcpy(activeWorkingArray, originalBaseDataset, totalElementsInDataset * sizeof(int));
    executeBubbleSort(activeWorkingArray, totalElementsInDataset);
    printArrayElements("Bubble Sort Result", activeWorkingArray, totalElementsInDataset);

    /*  Selection Sort */
    memcpy(activeWorkingArray, originalBaseDataset, totalElementsInDataset * sizeof(int));
    executeSelectionSort(activeWorkingArray, totalElementsInDataset);
    printArrayElements("Selection Sort Result", activeWorkingArray, totalElementsInDataset);

    /* Insertion Sort */
    memcpy(activeWorkingArray, originalBaseDataset, totalElementsInDataset * sizeof(int));
    executeInsertionSort(activeWorkingArray, totalElementsInDataset);
    printArrayElements("Insertion Sort Result", activeWorkingArray, totalElementsInDataset);

    /* Shell Sort */
    memcpy(activeWorkingArray, originalBaseDataset, totalElementsInDataset * sizeof(int));
    executeShellSort(activeWorkingArray, totalElementsInDataset);
    printArrayElements("Shell Sort Result", activeWorkingArray, totalElementsInDataset);

    /* Merge Sort */
    memcpy(activeWorkingArray, originalBaseDataset, totalElementsInDataset * sizeof(int));
    executeMergeSort(activeWorkingArray, 0, totalElementsInDataset - 1);
    printArrayElements("Merge Sort Result", activeWorkingArray, totalElementsInDataset);

    /* Heap Sort */
    memcpy(activeWorkingArray, originalBaseDataset, totalElementsInDataset * sizeof(int));
    executeHeapSort(activeWorkingArray, totalElementsInDataset);
    printArrayElements("Heap Sort Result", activeWorkingArray, totalElementsInDataset);

    /* Radix Sort */
    memcpy(activeWorkingArray, originalBaseDataset, totalElementsInDataset * sizeof(int));
    executeRadixSort(activeWorkingArray, totalElementsInDataset);
    printArrayElements("Radix Sort Result", activeWorkingArray, totalElementsInDataset);

    free(activeWorkingArray);

    return 0;
}
