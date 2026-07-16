/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// String Char-Case Change
int Anagram()
{
    char string1[] = "listen";
    char string2[] = "silent";

    printf("'%s' and '%s' are %s\n",
           string1, string2,
           is_anagram(string1, string2) ? "Anagrams" : "Not Anagrams");

    return 0;
}
// Find the length of a string.

int get_string_length(char text_string[])
{
    int string_length = 0;

    // Count characters until the null terminator is reached
    while (text_string[string_length] != '\0')
    {
        string_length++;
    }

    return string_length;
}

int lengthOFstring()
{
    char input_string[] = "C Programming";

    // Display the calculated length directly
    printf("Length of the string: %d\n", get_string_length(input_string));

    return 0;
}
// Copy one string to another string.
int one_string_to_another_string()
{
    char sourceString[] = "Hello, World!";
    char destinationString[50]; // Ensure buffer is large enough

    int index = 0;

    // Copy character by character including the null terminator '\0'
    while ((destinationString[index] = sourceString[index]) != '\0')
    {
        index++;
    }

    // Output the result
    printf("Source: %s\n", sourceString);
    printf("Destination: %s\n", destinationString);

    return 0;
}

// Concatenate two strings.

int Concatenate2Strings()
{
    char primaryString[100] = "Hello, ";
    char secondaryString[] = "World!";
    int destinationIndex = strlen(primaryString);
    int sourceIndex = 0;
    while ((primaryString[destinationIndex++] = secondaryString[sourceIndex++]) != '\0') ;
    printf("Concatenated String: %s\n", primaryString);
    return 0;
}

// Compare two strings.
int Compare2Strings()
{
    char firstString[] = "apple";
    char secondString[] = "apricot";
    int index = 0, difference = 0;

    while (firstString[index] == secondString[index] && firstString[index] != '\0')
        index++;

    difference = (unsigned char)firstString[index] - (unsigned char)secondString[index];

    if (!difference)
        printf("The strings are identical.\n");
    else if (difference < 0)
        printf("\"%s\" comes before \"%s\" alphabetically.\n", firstString, secondString);
    else
        printf("\"%s\" comes after \"%s\" alphabetically.\n", firstString, secondString);

    return 0;
}
// Convert lowercase string to uppercase.
int lowercase_to_uppercase()
{
    char inputString[] = "hello, world! 2026";
    int index = 0;

    while (inputString[index])
        inputString[index] = toupper(inputString[index++]);

    printf("Uppercase String: %s\n", inputString);
    return 0;
}

// Convert uppercase string to lowercase.
int lowercase_to_uppercase()
{
    char inputString[] = "HELLO, WORLD! 2026";
    int index = 0;

    while (inputString[index])
    {
        char currentCharacter = inputString[index];
        inputString[index++] = (char)tolower((unsigned char)currentCharacter);
    }

    printf("Lowercase String: %s\n", inputString);
    return 0;
}

// Toggle case of each character of a string.
int toggleCaseToString()
{

    char inputString[] = "Hello, World! 2026";
    int index = 0;

    while (inputString[index])
    {
        inputString[index] = islower(inputString[index]) ? toupper(inputString[index]) : isupper(inputString[index]) ? tolower(inputString[index])
                                                                                                                     : inputString[index];
        index++;
    }
    printf("Toggled String: %s\n", inputString);
    return 0;
}

// Find a total number of alphabets, digits or special character in a string.

int numbersOfAlphabetsDigitsOrSpecialCharacterString()
{
    char inputString[] = "Hello, World! 2026 @ C-Programming.";
    int alphabetCount = 0, digitCount = 0, specialCharacterCount = 0, index = 0;

    while (inputString[index])
    {
        if (isalpha(inputString[index]))
            alphabetCount++;
        else if (isdigit(inputString[index]))
            digitCount++;
        else
            specialCharacterCount++;
        index++;
    }

    printf("Total Alphabets: %d\nTotal Digits: %d\nTotal Special Characters: %d\n",
           alphabetCount, digitCount, specialCharacterCount);

    return 0;
}

// Count the total number of vowels and consonants in a string.
int CountVowelsAndConsonants()
{
    char inputString[] = "Hello, World! 2026";
    int vowelCount = 0, consonantCount = 0, index = 0;

    while (inputString[index])
    {
        char c = tolower(inputString[index++]);
        if (isalpha(c))
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowelCount++;
            else
                consonantCount++;
        }
    }

    printf("Total Vowels: %d\nTotal Consonants: %d\n", vowelCount, consonantCount);
    return 0;
} // Count the total number of words in a string.

int CountWords()
{
    char inputString[] = "   Hello,   World! Welcome to C programming.   ";
    int wordCount = 0, index = 0, inWordState = 0;

    while (inputString[index])
    {
        if (isspace(inputString[index]))
            inWordState = 0;
        else if (!inWordState)
        {
            inWordState = 1;
            wordCount++;
        }
        index++;
    }

    printf("Total number of words: %d\n", wordCount);
    return 0;
}
// Find the reverse of a string.
int ReverseString()
{
    char inputString[] = "Hello, World!";
    int startIndex = 0, endIndex = strlen(inputString) - 1;
    char temporaryCharacter;

    while (startIndex < endIndex)
    {
        temporaryCharacter = inputString[startIndex];
        inputString[startIndex++] = inputString[endIndex];
        inputString[endIndex--] = temporaryCharacter;
    }

    printf("Reversed String: %s\n", inputString);
    return 0;
}

// Check whether a string is a palindrome or not.
int PalindromeCheck()
{
    char inputString[] = "radar";
    int startIndex = 0, endIndex = strlen(inputString) - 1, isPalindrome = 1;

    while (startIndex < endIndex && isPalindrome)
        if (inputString[startIndex++] != inputString[endIndex--])
            isPalindrome = 0;

    printf("\"%s\" is %sa palindrome.\n", inputString, isPalindrome ? "" : "not ");

    return 0;
}
// Reverse order of words in a given string.
void reverseSection(char stringArray[], int startIndex, int endIndex)
{
    char temporaryCharacter;
    while (startIndex < endIndex)
    {
        temporaryCharacter = stringArray[startIndex];
        stringArray[startIndex++] = stringArray[endIndex];
        stringArray[endIndex--] = temporaryCharacter;
    }
}

int ReverseWordOrder()
{
    char inputString[] = "Welcome to C programming";
    int stringLength = strlen(inputString);

    // 1. Reverse the entire string
    reverseSection(inputString, 0, stringLength - 1);

    // 2. Reverse each individual word back
    int wordStartIndex = 0, index = 0;
    while (index <= stringLength)
    {
        if (isspace(inputString[index]) || inputString[index] == '\0')
        {
            reverseSection(inputString, wordStartIndex, index - 1);
            wordStartIndex = index + 1;
        }
        index++;
    }

    printf("Reversed Word Order: %s\n", inputString);
    return 0;
}
// Find the first occurrence of a character in a given string.

// Search all occurrences of a character in a given string.

int SearchCharacterInString()
{
    char inputString[] = "Welcome to C programming in 2026!";
    char targetCharacter = 'o';
    int index = 0, matchCount = 0;

    printf("Searching for all occurrences of '%c'...\n", targetCharacter);

    while (inputString[index])
    {
        if (inputString[index] == targetCharacter)
            printf("Found match #%d at index: %d (Position: %d)\n", ++matchCount, index, index + 1);
        index++;
    }

    if (matchCount)
        printf("\nTotal occurrences found: %d\n", matchCount);
    else
        printf("\nThe character '%c' was not found.\n", targetCharacter);

    return 0;
}

int main(void)
{
    Compare2Strings();
    // Call the functions to demonstrate their functionality

    lowercase_to_uppercase();
    toggleCaseToString();
    numbersOfAlphabetsDigitsOrSpecialCharacterString();
    CountVowelsAndConsonants();
    CountWords();
    ReverseString();
    PalindromeCheck();
    ReverseWordOrder();
    SearchCharacterInString();
    return 0;
}
