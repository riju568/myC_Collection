/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/

#include <stdio.h>
#include <string.h>
// Remove Duplicates Items In An Array
int duplicatesItemsInAnArray()
{
    int sampleArray[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(sampleArray) / sizeof(sampleArray[0]), j = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || sampleArray[i] != sampleArray[i - 1])
        {
            sampleArray[j++] = sampleArray[i];
        }
    }
    for (int i = 0; i < j; i++)
        printf("%d ", sampleArray[i]);
    return 0;
}
int checkStringIsPalindromeOrNot()
{
    char str[] = "radar";
    int len = strlen(str), is_palindrome = 1;

    // Loop up to the middle of the string
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            is_palindrome = 0;
            break;
        }
    }
    printf(is_palindrome ? "Palindrome\n" : "Not Palindrome\n");
    return 0;
}

int nameUsingArry (){
    char name[] = "John Doe";
    printf("%s\n", "I AM IDIOT");

    return 0;
}
int convertAllInputStringSimultaneouslyIntoAsterisk()
{
    char passwordPlaceHolder[20];
    printf("Enter password: ");
    scanf("%s", passwordPlaceHolder);
    printf("You entered: %s\n", passwordPlaceHolder);
    char password = passwordPlaceHolder;
    // Loop through the string and replace each character with '*'
    for (int i = 0; passwordPlaceHolder[i] != '\0'; i++)
    {
        passwordPlaceHolder[i] = '*';
    }

    printf("Masked String: %s\n", passwordPlaceHolder);
    return 0;
}

// Read and print elements of the array. – using recursion.
// Recursive function to read array elements
void readArray(int arr[], int i, int n)
{
    if (i < n)
    {
        scanf("%d", &arr[i]);
        readArray(arr, i + 1, n); // Recursive call for next index
    }
}

// Recursive function to print array elements
void printArray(int arr[], int i, int n)
{
    if (i < n)
    {
        printf("%d ", arr[i]);
        printArray(arr, i + 1, n); // Recursive call for next index
    }
}

int wayToReadReadArray()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    readArray(arr, 0, n);

    printf("Array elements are: ");
    printArray(arr, 0, n);

    return 0;
}
// Print all negative elements in an array.
int negativeElementsInAnArray()
{
    int arr[] = {10, -5, 20, -3, -1, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            printf("%d ", arr[i]);
    }

    return 0;
}
// Recursive function to sum array elements
int sumArray(int arr[], int n)
{
    if (n <= 0)
        return 0;                             // Base case
    return arr[n - 1] + sumArray(arr, n - 1); // Recursive step
}
// Call this function.
int wayToCallSumArray()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Sum: %d\n", sumArray(arr, n));
    return 0;
}


// Find a maximum and minimum element in an array. – using recursion.
// Recursive function to find min and max
void findMinMax(int arr[], int n, int *min, int *max)
{
    if (n == 1)
    { // Base case: only one element
        *min = *max = arr[0];
        return;
    }

    // Recursive call for the rest of the array
    findMinMax(arr, n - 1, min, max);

    // Compare current element with min and max found so far
    if (arr[n - 1] < *min)
        *min = arr[n - 1];
    if (arr[n - 1] > *max)
        *max = arr[n - 1];
}

int WayToFindMinMax()
{
    int arr[] = {12, 45, 2, 67, -3, 89, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, n, &min, &max);

    printf("Minimum element: %d\nMaximum element: %d\n", min, max);
    return 0;
}
// Get the second largest element in an array.
#include <stdio.h>

int secondLargestArray()
{
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max1 = arr[0], max2 = -1; // Assumes positive numbers; change -1 to a very low number if negative numbers are possible

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] < max1)
        {
            max2 = arr[i];
        }
    }

    printf("Second largest element: %d\n", max2);
    return 0;
}
// Count the total number of even and odd elements in an array.
int numberEvenOddInArray()
{
    // Descriptive variable names instead of short, cryptic ones
    int sourceArrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7};
    int totalElementsInArray = sizeof(sourceArrayOfNumbers) / sizeof(sourceArrayOfNumbers[0]);

    int totalCountOfEvenNumbers = 0;
    int totalCountOfOddNumbers = 0;

    // Loop through the array using a clear index variable name
    for (int currentArrayIndex = 0; currentArrayIndex < totalElementsInArray; currentArrayIndex++)
    {
        int currentElementValue = sourceArrayOfNumbers[currentArrayIndex];

        // Check if the current number is perfectly divisible by 2
        if (currentElementValue % 2 == 0)
        {
            totalCountOfEvenNumbers++;
        }
        else
        {
            totalCountOfOddNumbers++;
        }
    }

    // Display the final results with clear descriptions
    printf("Total Even Elements: %d\n", totalCountOfEvenNumbers);
    printf("Total Odd Elements: %d\n", totalCountOfOddNumbers);

    return 0;
}

// Count the total number of negative elements in an array.
int negativeInArray()
{
    // Array containing both positive and negative numbers
    int sourceArrayOfNumbers[] = {10, -5, 20, -3, -1, 40, -8};
    int totalElementsInArray = sizeof(sourceArrayOfNumbers) / sizeof(sourceArrayOfNumbers[0]);

    int totalCountOfNegativeNumbers = 0;

    // Loop through the array to evaluate each element
    for (int currentArrayIndex = 0; currentArrayIndex < totalElementsInArray; currentArrayIndex++)
    {
        int currentElementValue = sourceArrayOfNumbers[currentArrayIndex];

        // Check if the current number is less than zero
        if (currentElementValue < 0)
        {
            totalCountOfNegativeNumbers++;
        }
    }

    printf("Total Negative Elements: %d\n", totalCountOfNegativeNumbers);

    return 0;
}

// Copy all elements from an array to another array.
int copyElementsArray2Array()
{
    int sourceArrayOfNumbers[] = {10, 20, 30, 40, 50};
    int totalElementsInArray = sizeof(sourceArrayOfNumbers) / sizeof(sourceArrayOfNumbers[0]);
    int destinationArrayOfNumbers[totalElementsInArray];

    // Loop through the source array and duplicate each element into the destination array
    for (int currentArrayIndex = 0; currentArrayIndex < totalElementsInArray; currentArrayIndex++)
    {
        destinationArrayOfNumbers[currentArrayIndex] = sourceArrayOfNumbers[currentArrayIndex];
    }

    // Display the elements of the destination array to confirm the copy was successful
    printf("Elements in Destination Array: ");
    for (int currentArrayIndex = 0; currentArrayIndex < totalElementsInArray; currentArrayIndex++)
    {
        printf("%d ", destinationArrayOfNumbers[currentArrayIndex]);
    }
    printf("\n");

    return 0;
}

// Insert an element in an array.
int elementsInArray()
{
    int sourceArrayOfNumbers[10] = {10, 20, 30, 40, 50};
    int currentElementsCount = 5; // The actual number of elements currently in use

    int valueToBeInserted = 25;
    int targetInsertionPosition = 3;                        // Position 3 corresponds to index 2 (1-based counting)
    int targetInsertionIndex = targetInsertionPosition - 1; // Convert to 0-based index

    // Shift elements to the right from the end of the array down to the target index
    for (int currentArrayIndex = currentElementsCount; currentArrayIndex > targetInsertionIndex; currentArrayIndex--)
    {
        sourceArrayOfNumbers[currentArrayIndex] = sourceArrayOfNumbers[currentArrayIndex - 1];
    }

    // Insert the new value at the targeted empty index slot
    sourceArrayOfNumbers[targetInsertionIndex] = valueToBeInserted;

    // Increase the active element count since a new number was added
    currentElementsCount++;

    printf("Array elements after insertion: ");
    for (int currentArrayIndex = 0; currentArrayIndex < currentElementsCount; currentArrayIndex++)
    {
        printf("%d ", sourceArrayOfNumbers[currentArrayIndex]);
    }
    printf("\n");

    return 0;
}

// Delete an element from an array at the specified position.
int deleteElementformPositionInArry()
{
    int sourceArrayOfNumbers[] = {10, 20, 25, 30, 40, 50};
    int currentElementsCount = 6;

    int targetDeletionPosition = 3;                       // Position 3 corresponds to index 2 (1-based counting)
    int targetDeletionIndex = targetDeletionPosition - 1; // Convert to 0-based index

    // Shift elements to the left from the target index up to the end of the array
    for (int currentArrayIndex = targetDeletionIndex; currentArrayIndex < currentElementsCount - 1; currentArrayIndex++)
    {
        sourceArrayOfNumbers[currentArrayIndex] = sourceArrayOfNumbers[currentArrayIndex + 1];
    }

    // Decrease the active element count since one number was removed
    currentElementsCount--;

    printf("Array elements after deletion: ");
    for (int currentArrayIndex = 0; currentArrayIndex < currentElementsCount; currentArrayIndex++)
    {
        printf("%d ", sourceArrayOfNumbers[currentArrayIndex]);
    }
    printf("\n");

    return 0;
}
int main(){
    WayToFindMinMax();
    wayToCallSumArray();

    return 0;
}
