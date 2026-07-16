/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stddef.h> 

// Stricmp() Function (Case In-Sensitive Compare)
int customCaseInsensitiveCompare(const char *stringOne, const char *stringTwo)
{
    while (*stringOne && (tolower((unsigned char)*stringOne) == tolower((unsigned char)*stringTwo)))
    {
        stringOne++;
        stringTwo++;
    }
    return tolower((unsigned char)*stringOne) - tolower((unsigned char)*stringTwo);
}

// Strncat() Function (String Concatenate)
int StrncatFunctionStringConcatenate()
{
    char destinationStringBufferToHoldAccumulatedText[50] = "Hello, my name is ";
    const char *sourceStringContainingTextToAppend = "Alexander the Great";
    size_t maximumNumberOfCharactersToAppend = 9;

    printf("Before concatenation: \"%s\"\n", destinationStringBufferToHoldAccumulatedText);
    strncat(destinationStringBufferToHoldAccumulatedText, sourceStringContainingTextToAppend, maximumNumberOfCharactersToAppend);
    printf("After concatenation:  \"%s\"\n\n", destinationStringBufferToHoldAccumulatedText);
    return 0;
}

// Strstr() Function (Sub-String)
int StrstrFunctionSubString()
{
    const char *primaryTargetTextToSearchWithin = "Learning C programming is highly rewarding.";
    const char *substringTextPatternToLookFor = "programming";
    const char *memoryLocationOfFoundSubstring; // Changed to const char* to match strstr output on constant text

    memoryLocationOfFoundSubstring = strstr(primaryTargetTextToSearchWithin, substringTextPatternToLookFor);
    if (memoryLocationOfFoundSubstring != NULL)
    {
        printf("Substring found!\n");
        printf("String starting from the match: \"%s\"\n", memoryLocationOfFoundSubstring);
        ptrdiff_t exactIndexPosition = memoryLocationOfFoundSubstring - primaryTargetTextToSearchWithin;
        printf("The substring starts at index position: %td\n\n", exactIndexPosition);
    }
    else
    {
        printf("The substring \"%s\" was not found.\n\n", substringTextPatternToLookFor);
    }

    return 0;
}

// Strlwr() Function (To Lower-Case)
char *convertStringToEntirelyLowerCase(char *targetStringToBeConverted)
{
    char *temporaryStringPointerTracker = targetStringToBeConverted;

    while (*temporaryStringPointerTracker)
    {
        *temporaryStringPointerTracker = (char)tolower((unsigned char)*temporaryStringPointerTracker);
        temporaryStringPointerTracker++;
    }

    return targetStringToBeConverted;
}

int StrlwrFunctionLowerCase()
{
    char userSuppliedInputTextBuffer[] = "C Programming IS Universally AWESOME 123!";
    printf("Original String: \"%s\"\n", userSuppliedInputTextBuffer);
    convertStringToEntirelyLowerCase(userSuppliedInputTextBuffer);
    printf("Lowercase Result: \"%s\"\n\n", userSuppliedInputTextBuffer);
    return 0;
}

// Strupr() Function (To Upper-Case)
char *customCrossPlatformStringReverse(char *targetStringToBeReversed)
{
    if (!targetStringToBeReversed)
        return NULL;

    char *startPointerTracker = targetStringToBeReversed;
    char *endPointerTracker = targetStringToBeReversed + strlen(targetStringToBeReversed) - 1;
    char temporaryCharacterHolder;

    while (startPointerTracker < endPointerTracker)
    {
        temporaryCharacterHolder = *startPointerTracker;
        *startPointerTracker = *endPointerTracker;
        *endPointerTracker = temporaryCharacterHolder;
        startPointerTracker++;
        endPointerTracker--;
    }
    return targetStringToBeReversed;
}
//  Strncmp() Function (Compare N Characters)
void StrncmpCompareLimitedCharacters()
{
    const char *firstComparisonInputString = "BufferOverflowRisk";
    const char *secondComparisonInputString = "BufferSafetyCheck";
    size_t maximumNumberOfCharactersToCompare = 6; // Compares "Buffer"

    int comparisonResultValue = strncmp(firstComparisonInputString, secondComparisonInputString, maximumNumberOfCharactersToCompare);
    printf("1. Strncmp Result (First %zu chars): %d (0 means matching)\n", maximumNumberOfCharactersToCompare, comparisonResultValue);
}


// Strncpy() Function (Copy N Characters)
void StrncpyCopyLimitedCharacters()
{
    const char *sourceStringTextToExtractFrom = "OpenAI_GPT_Architecture";
    char destinationDataBufferPayload[20] = {0}; // Initialize to all zeros
    size_t absoluteCountOfCharactersToCopy = 6;  // Copies "OpenAI"

    // Copies exactly N characters. Warning: Does not automatically append \0 if source is longer than N!
    strncpy(destinationDataBufferPayload, sourceStringTextToExtractFrom, absoluteCountOfCharactersToCopy);
    destinationDataBufferPayload[absoluteCountOfCharactersToCopy] = '\0'; // Manual safety termination

    printf("2. Strncpy Result: \"%s\"\n", destinationDataBufferPayload);
}


// Strrev() Execution Block

void StrrevStringReverseExecution()
{
    char modifiableStringTextBufferValue[] = "EmanruasotatO"; // Must be mutable array
    printf("3. Strrev Before: \"%s\"\n", modifiableStringTextBufferValue);
    customCrossPlatformStringReverse(modifiableStringTextBufferValue);
    printf("   Strrev After:  \"%s\"\n", modifiableStringTextBufferValue);
}


// 5. Strlen() Function (String Length)

void StrlenStringLengthMeasurement()
{
    const char *descriptiveInputTargetTextString = "CrossPlatformSystemDevelopment";
    size_t totalCountedLengthOfTargetString = strlen(descriptiveInputTargetTextString);

    printf("4. Strlen Result: The text contains %zu valid characters.\n", totalCountedLengthOfTargetString);
}

// Strcat() Function (String Concatenate)
void StrcatStringConcatenationBuffer()
{
    char primaryBaseDestinationBufferText[60] = "Supercalifragilistic"; // Buffer must be large enough
    const char *secondarySourceStringTextToAppend = "expialidocious";

    strcat(primaryBaseDestinationBufferText, secondarySourceStringTextToAppend);
    printf("5. Strcat Result: \"%s\"\n", primaryBaseDestinationBufferText);
}

//  Strcmp() Function (String Compare)
void StrcmpFullStringComparison()
{
    const char *firstLexicographicalCompareString = "DeltaV";
    const char *secondLexicographicalCompareString = "DeltaV";

    int evaluationResultOutcomeValue = strcmp(firstLexicographicalCompareString, secondLexicographicalCompareString);
    printf("6. Strcmp Result: %d (0 means perfectly identical)\n", evaluationResultOutcomeValue);
}
// Strcpy() Function (Copy Full String)
void StrcpyFullStringDuplication()
{
    const char *originalImmutableSourceText = "SystemRootDirectory";
    char dynamicTargetDestinationOutputBuffer[40];

    strcpy(dynamicTargetDestinationOutputBuffer, originalImmutableSourceText);
    printf("7. Strcpy Result: \"%s\"\n", dynamicTargetDestinationOutputBuffer);
}

int main(void)
{
    // Testing the custom case-insensitive compare function
    const char *testStringA = "APPLE";
    const char *testStringB = "apple";
    int compareResult = customCaseInsensitiveCompare(testStringA, testStringB);
    printf("Stricmp Result (%s vs %s): %d (0 means identical)\n\n", testStringA, testStringB, compareResult);

    // Testing the rest of your string operational blocks
    StrncatFunctionStringConcatenate();
    StrstrFunctionSubString();
    StrlwrFunctionLowerCase();
    StrncmpCompareLimitedCharacters();
    StrncpyCopyLimitedCharacters();
    StrrevStringReverseExecution();
    StrlenStringLengthMeasurement();
    StrcatStringConcatenationBuffer();
    StrcmpFullStringComparison();
    StrcpyFullStringDuplication();

    return 0;
}
