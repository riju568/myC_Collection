/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/
#include <stdio.h>
#include <ctype.h>

// String Char-Case Change
void toggle_string_case(char text_string[])
{
    for (int index = 0; text_string[index] != '\0'; index++)
    {
        char current_char = text_string[index];
        text_string[index] = isupper(current_char) ? tolower(current_char) : toupper(current_char);
    }
}

int StringCaseChange()
{
    char input_string[] = "C Programming 2026";
    toggle_string_case(input_string);
    printf("Toggled:   %s\n", input_string);
    return 0;
}
// A String is Palindrome or Not
int is_palindrome(char text_string[])
{
    int string_length = 0;

    // Custom low-overhead string length calculation
    while (text_string[string_length] != '\0')
        string_length++;

    // Check characters from both ends moving inward
    for (int left = 0, right = string_length - 1; left < right; left++, right--)
    {
        if (text_string[left] != text_string[right])
            return 0; // Not a palindrome
    }
    return 1; // Is a palindrome
}

int PalindromeCheck()
{
    char input_string[] = "radar";

    // Shortened output using a ternary operator
    printf("Result: %s\n", is_palindrome(input_string) ? "Palindrome" : "Not Palindrome");

    return 0;
}

int is_anagram(char first_string[], char second_string[])
{
    int char_frequency[256] = {0}; // Tracks count of all ASCII characters
    int index = 0;

    // Count frequencies of the first string and subtract for the second string
    while (first_string[index] != '\0' && second_string[index] != '\0')
    {
        char_frequency[(unsigned char)first_string[index]]++;
        char_frequency[(unsigned char)second_string[index]]--;
        index++;
    }

    // If strings are of different lengths, one won't be at '\0'
    if (first_string[index] != '\0' || second_string[index] != '\0')
        return 0;

    // Check if all character frequencies perfectly balanced out to zero
    for (int i = 0; i < 256; i++)
        if (char_frequency[i] != 0)
            return 0;

    return 1;
}

int Anagram()
{
    char string_one[] = "listen";
    char string_two[] = "silent";

    printf("Result: %s\n", is_anagram(string_one, string_two) ? "Anagram" : "Not Anagram");

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

int main(void)
{
    PalindromeCheck();
    StringCaseChange();
    Anagram();
    lengthOFstring();
    return 0;
}
