#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Find the highest frequency character in a string.
int highestFrequencyCharacter()
{
    char inputString[] = "welcome to c programming in 2026!";
    int frequencyCount[256] = {0}, maxFreq = 0, i = 0;
    char maxChar = '\0';
    while (inputString[i])
        frequencyCount[(unsigned char)inputString[i++]]++;
    for (i = 0; i < 256; i++)
    {
        if (i != ' ' && frequencyCount[i] > maxFreq)
        {
            maxFreq = frequencyCount[i];
            maxChar = (char)i;
        }
    }

    if (maxFreq > 0)
        printf("The highest frequency character is '%c' appearing %d times.\n", maxChar, maxFreq);
    else
        printf("No valid characters found.\n");
    return 0;
}
// Find the lowest frequency character in a string.

int findLowestFrequencyCharacter(const char *inputString)
{
    if (!inputString || !*inputString)
        return -1; // Handle NULL or empty string

    int freq[256] = {0}, len = strlen(inputString), minFreq = len + 1;
    char minChar = '\0';

    for (int i = 0; i < len; i++)
        freq[(unsigned char)inputString[i]]++;

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0 && !isspace(i) && freq[i] < minFreq)
        {
            minFreq = freq[i];
            minChar = (char)i;
        }
    }

    if (minChar)
        printf("The lowest frequency character is '%c' appearing %d time(s).\n", minChar, minFreq);
    else
        printf("No valid characters found.\n");

    return 0;
}

// Count the frequency of each character in a string.
int countCharacterFrequencies(const char *inputString)
{
    if (!inputString || !*inputString)
        return -1;
    int freq[256] = {0};
    for (int i = 0; inputString[i] != '\0'; i++)
        freq[(unsigned char)inputString[i]]++;

    printf("Character Frequencies:\n");
    for (int i = 0; inputString[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)inputString[i];
        if (freq[c] > 0)
        {
            printf("'%c' : %d time(s)\n", c, freq[c]);
            freq[c] = 0;
        }
    }

    return 0;
}
// Remove the last occurrence of a character from a string.
void removeLastOccurrence(char *str, char target)
{
    int lastIdx = -1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == target)
            lastIdx = i;
    }

    if (lastIdx != -1)
    {
        // Shift characters left to overwrite the target
        for (int i = lastIdx; str[i] != '\0'; i++)
        {
            str[i] = str[i + 1];
        }
    }
}

int RemoveLastCharacter()
{
    char myString[] = "pie";
    removeLastOccurrence(myString, 'p');
    printf("Result: %s\n", myString);
    return 0;
}

void removeAll(char str[], char target)
{
    int write = 0;
    for (int read = 0; str[read] != '\0'; read++)
    {
        if (str[read] != target)
        {
            str[write++] = str[read];
        }
    }
    str[write] = '\0';
}

int RemoveAllOccurrences()
{
    char inputString[] = "pie";
    removeAll(inputString, 'p');
    printf("Resulting String: %s\n", inputString);
    return 0;
}

// Delete all occurrences of a character from a string.

int DeleteAllOccurrences()
{
    char inputString[] = "pie";
    removeAll(inputString, 'p');
    printf("Resulting String: %s\n", inputString);
    return 0;
}
// Remove all repeated characters from a given string.
void deduplicate(char str[])
{

    int seen[256] = {0};
    int write = 0;
    for (int read = 0; str[read] != '\0'; read++)
    {
        unsigned char c = (unsigned char)str[read];

        // Check if the flag is 0 (not seen)
        if (!seen[c])
        {
            seen[c] = 1;
            str[write++] = str[read];
        }
    }
    str[write] = '\0';
}

int RemoveRepeatedCharacters()
{
    char inputString[] = "programming in 2026";
    deduplicate(inputString);
    printf("Resulting String: %s\n", inputString);
    return 0;
}

// Replace the first occurrence of a character with another in a string.

// Returns 1 if replacement occurred, 0 otherwise
int replaceFirst(char str[], char target, char replacement)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == target)
        {
            str[i] = replacement;
            return 1;
        }
    }
    return 0;
}

int ReplaceFirstOccurrence()
{
    char inputString[] = "pie";
    if (replaceFirst(inputString, 'p', 'x'))
        printf("Resulting String: %s\n", inputString);
    else
        printf("Character not found.\n");
    return 0;
}

// Replace the last occurrence of a character with another in a string.

int replaceLast(char str[], char target, char replacement)
{
    int lastFoundIndex = -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == target)
        {
            lastFoundIndex = i;
        }
    }

    if (lastFoundIndex != -1)
    {
        str[lastFoundIndex] = replacement;
    }

    return lastFoundIndex;
}

int ReplaceLastOccurrence()
{
    char inputString[] = "pie";
    if (replaceLast(inputString, 'p', 'x') != -1)
        printf("Resulting String: %s\n", inputString);
    else
        printf("Character not found.\n");

    return 0;
}

// Put all occurrences of a character with another in a string.

void replaceAll(char str[], char target, char replacement)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == target)
        {
            str[i] = replacement;
        }
    }
}

int ReplaceAllOccurrences()
{
    char inputString[] = "pie";
    replaceAll(inputString, 'p', 'x');
    printf("Resulting String: %s\n", inputString);
    return 0;
}

int FindWord()
{
    char inputString[] = "Welcome to C programming in 2026!";
    char targetWord[] = "programming";

    // strstr returns a pointer to the first occurrence
    char *ptr = strstr(inputString, targetWord);

    if (ptr != NULL)
    {
        // Calculate the index by subtracting the pointer to the start
        int foundIndex = ptr - inputString;
        printf("The word \"%s\" was first found at index: %d\n", targetWord, foundIndex);
    }
    else
    {
        printf("The word \"%s\" was not found.\n", targetWord);
    }

    return 0;
}

int main()
{
    // Call the functions to demonstrate their functionality
    highestFrequencyCharacter();
    findLowestFrequencyCharacter("welcome to c programming in 2026!");
    countCharacterFrequencies("welcome to c programming in 2026!");
    RemoveLastCharacter();
    RemoveAllOccurrences();
    DeleteAllOccurrences();
    RemoveRepeatedCharacters();
    ReplaceFirstOccurrence();
    ReplaceLastOccurrence();
    ReplaceAllOccurrences();
    FindWord();
    return 0;
}
