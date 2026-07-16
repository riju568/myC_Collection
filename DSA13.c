/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/
#include <stdio.h>
#include <string.h>

// Find the last occurrence of a word in a given string.
const char *findLastOccurrence(const char *str, const char *target)
{
    const char *lastMatch = NULL;
    const char *current = str;
    size_t targetLen = strlen(target);

    // Search for every occurrence and update lastMatch
    while ((current = strstr(current, target)) != NULL)
    {
        lastMatch = current;
        current++;
    }
    return lastMatch;
}

int FindLastOccurrence()
{
    char inputString[] = "can you can a can as a canner can can a can?";
    char targetWord[] = "can";
    const char *result = findLastOccurrence(inputString, targetWord);

    if (result != NULL)
    {
        printf("Last index: %ld\n", result - inputString);
    }
    else
    {
        printf("Word not found.\n");
    }
    return 0;
}

// Search all occurrences of a word in a given string.
int countOccurrences(const char *str, const char *target)
{
    int count = 0;
    const char *ptr = str;
    size_t len = strlen(target);

    while ((ptr = strstr(ptr, target)) != NULL)
    {
        count++;
        ptr += len;
    }
    return count;
}

// Count occurrences of a word in a given string.
int countOccurrences(char str[], char target[])
{
    int count = 0;
    int targetLen = strlen(target);

    for (int i = 0; str[i] != '\0'; i++)
    {
        // Only start checking if the first character matches
        if (str[i] == target[0])
        {
            if (strncmp(&str[i], target, targetLen) == 0)
            {
                count++;
                i += (targetLen - 1);
            }
        }
    }
    return count;
}

// Remove the first occurrence of a word from the string.

int RemoveFirstOccurrence()
{
    char inputString[] = "The blue sky and the blue car.";
    char wordToRemove[] = "blue ";
    int stringIndex = 0;
    int foundIndex = -1;
    int wordLength = 0;
    while (wordToRemove[wordLength] != '\0')
    {
        wordLength++;
    }
    while (inputString[stringIndex] != '\0')
    {
        if (inputString[stringIndex] == wordToRemove[0])
        {
            int wordIndex = 0;
            int tempStringIndex = stringIndex;

            while (wordToRemove[wordIndex] != '\0' && inputString[tempStringIndex] != '\0')
            {
                if (inputString[tempStringIndex] != wordToRemove[wordIndex])
                {
                    break;
                }
                tempStringIndex++;
                wordIndex++;
            }

            if (wordToRemove[wordIndex] == '\0')
            {
                foundIndex = stringIndex;
                break;
            }
        }
        stringIndex++;
    }
    if (foundIndex != -1)
    {
        int shiftIndex = foundIndex;
        while (inputString[shiftIndex + wordLength] != '\0')
        {
            inputString[shiftIndex] = inputString[shiftIndex + wordLength];
            shiftIndex++;
        }
        inputString[shiftIndex] = '\0';
        printf("Word removed successfully.\n");
    }
    else
    {
        printf("The word was not found in the string.\n");
    }
    printf("Resulting String: \"%s\"\n", inputString);

    return 0;
}

#include <stdio.h>

int main()
{
    char inputString[] = "The blue sky and the blue car.";
    char wordToRemove[] = "blue "; // Including the space to avoid double spaces after removal

    int stringIndex = 0;
    int lastFoundIndex = -1;
    int wordLength = 0;

    // 1. Calculate the length of the word to remove
    while (wordToRemove[wordLength] != '\0')
    {
        wordLength++;
    }

    // 2. Scan the string to find the index of the LAST occurrence
    while (inputString[stringIndex] != '\0')
    {
        if (inputString[stringIndex] == wordToRemove[0])
        {
            int wordIndex = 0;
            int tempStringIndex = stringIndex;

            while (wordToRemove[wordIndex] != '\0' && inputString[tempStringIndex] != '\0')
            {
                if (inputString[tempStringIndex] != wordToRemove[wordIndex])
                {
                    break;
                }
                tempStringIndex++;
                wordIndex++;
            }

            if (wordToRemove[wordIndex] == '\0')
            {
                lastFoundIndex = stringIndex; // Keep updating to track the latest match
            }
        }
        stringIndex++;
    }

    // 3. If the word was found, shift characters left to delete it
    if (lastFoundIndex != -1)
    {
        int shiftIndex = lastFoundIndex;

        while (inputString[shiftIndex + wordLength] != '\0')
        {
            inputString[shiftIndex] = inputString[shiftIndex + wordLength];
            shiftIndex++;
        }
        // Properly terminate the shortened string
        inputString[shiftIndex] = '\0';

        printf("Last occurrence removed successfully.\n");
    }
    else
    {
        printf("The word was not found in the string.\n");
    }

    // Output the final result
    printf("Resulting String: \"%s\"\n", inputString);

    return 0;
}



// Remove the last occurrence of a word in a given string.

int RemoveLastOccurrence()
{
    char inputString[] = "The blue sky and the blue car.";
    char wordToRemove[] = "blue "; // Including the space to avoid double spaces after removal

    int stringIndex = 0;
    int lastFoundIndex = -1;
    int wordLength = 0;
    while (wordToRemove[wordLength] != '\0')
    {
        wordLength++;
    }
    while (inputString[stringIndex] != '\0')
    {
        if (inputString[stringIndex] == wordToRemove[0])
        {
            int wordIndex = 0;
            int tempStringIndex = stringIndex;

            while (wordToRemove[wordIndex] != '\0' && inputString[tempStringIndex] != '\0')
            {
                if (inputString[tempStringIndex] != wordToRemove[wordIndex])
                {
                    break;
                }
                tempStringIndex++;
                wordIndex++;
            }

            if (wordToRemove[wordIndex] == '\0')
            {
                lastFoundIndex = stringIndex; 
            }
        }
        stringIndex++;
    }
    if (lastFoundIndex != -1)
    {
        int shiftIndex = lastFoundIndex;

        while (inputString[shiftIndex + wordLength] != '\0')
        {
            inputString[shiftIndex] = inputString[shiftIndex + wordLength];
            shiftIndex++;
        }
        inputString[shiftIndex] = '\0';

        printf("Last occurrence removed successfully.\n");
    }
    else
    {
        printf("The word was not found in the string.\n");
    }

    printf("Resulting String: \"%s\"\n", inputString);

    return 0;
}
int main(void)
{
    // Call the functions to demonstrate their functionality
    RemoveFirstOccurrence();
    printf("Total occurrences: %d\n", countOccurrences("can you can a can as a canner can can a can?", "can"));
    printf("Total occurrences (alternative method): %d\n", countOccurrences("can you can a can as a canner can can a can?", "can"));
    RemoveLastOccurrence();
    return 0;
}
