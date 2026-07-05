#include <stdio.h>
#include <string.h>

int reverseANumber()
{
    int num, reversedNumber = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Loop combines extracting, appending, and updating nummber
    for (; num != 0; num /= 10)
    {
        reversedNumber = reversedNumber * 10 + (num % 10);
    }

    printf("Reversed Number = %d\n", reversedNumber);
    return 0;
}

int armstrongNumberOrNot()
{
    int inputNumber, original, result = 0, remainder;

    printf("Enter a 3-digit integer: ");
    scanf("%d", &inputNumber);

    // Loop copies num to 'original', extracts digits, and cubes them
    for (original = inputNumber; original != 0; original /= 10)
    {
        remainder = original % 10;
        result += remainder * remainder * remainder;
    }
    printf("%d is %san Armstrong number.\n", inputNumber, (result == inputNumber) ? "" : "not ");

    return 0;
}
int sumOfNaturalNumbers()
{
    int number_n, theSummation;

    printf("Enter a positive integer: ");
    scanf("%d", &number_n);

    // Constant time formula to calculate sum of 1 to n
    theSummation = number_n * (number_n + 1) / 2;

    printf("Sum of first %d natural numbers = %d\n", number_n, theSummation);
    return 0;
}
int fibonacciSeries()
{
    int numberOfTerms = 10; // Number of terms to print
    long long firstNumber = 0, secondNumber = 1, nextNumber;

    printf("Fibonacci Series: ");

    for (int i = 0; i < numberOfTerms; i++)
    {
        printf("%lld ", firstNumber);            // 1. Current number
        nextNumber = firstNumber + secondNumber; // 2. Next number
        firstNumber = secondNumber;              // 3. Move second into first
        secondNumber = nextNumber;               // 4. Move next into second
    }

    printf("\n");
    return 0;
}
int LCMOf2Numbers()
{
    int num1 = 12, num2 = 18;
    int a = num1, b = num2; // Copy values to calculate GCD without losing original numbers

    // Euclidean algorithm to find GCD
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    // 'a' holds the GCD. Find out LCM using: (num1 * num2) / GCD
    int lcm = (num1 * num2) / a;

    printf("LCM: %d\n", lcm);
    return 0;
}
int genericRootOfNumber()
{
    int num = 12345; // default number: 1+2+3+4+5 = 15 -> 1+5 = 6
    printf("Enter a number: ");
    scanf("%d", &num);
    // Mathematical shortcut to find the generic root instantly
    int generic_root = 1 + ((num - 1) % 9);

    printf("Generic Root: %d\n", generic_root);
    return 0;
}
// A Calendar Taking A Calendar Taking Input From User Using Loop
int calendarUsingLoop()
{
    int days, startDay = 0;
    char dayChar;

    // 1. User input
    printf("Enter total days in month: ");
    scanf("%d", &days);
    printf("Enter starting day letter (S=Sun, M=Mon, T=Tue, W=Wed, t=Thu, F=Fri, s=Sat): ");
    scanf(" %c", &dayChar); // Note the space before %c to clear the input buffer

    // 2. Map the character to a starting day column number
    if (dayChar == 'M')
        startDay = 1;
    else if (dayChar == 'T')
        startDay = 2;
    else if (dayChar == 'W')
        startDay = 3;
    else if (dayChar == 't')
        startDay = 4;
    else if (dayChar == 'F')
        startDay = 5;
    else if (dayChar == 's')
        startDay = 6;

    // 3. Header
    printf("\nSun Mon Tue Wed Thu Fri Sat\n");

    // 4. Print initial spacing and dates in a single unified calculation loop
    for (int i = 0; i < startDay; i++)
    {
        printf("    ");
    }

    for (int day = 1; day <= days; day++)
    {
        printf("%3d ", day);

        // Break to a new line at the end of every Saturday row
        if ((day + startDay) % 7 == 0)
        {
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}

int temperatureConversion()
{
    int choice;
    float temp; // To help calculation.

    printf("Temperature Converter\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\nEnter your choice (1 or 2): ");
    scanf("%d", &choice);
    // Temperature conversion
    printf(choice == 1 ? "%.2f C = %.2f F\n" : "%.2f F = %.2f C\n", temp, choice == 1 ? (temp * 9.0 / 5.0) + 32.0 : (temp - 32.0) * 5.0 / 9.0);

    return 0;
}

// Count Number of Digits of an Integer
int numberOfDigits()
{
    int integerValue, original, reversedIntegerValue = 0;
    printf("Enter an integer: ");
    scanf("%d", &integerValue);

    for (original = integerValue; integerValue > 0; integerValue /= 10)
        reversedIntegerValue = reversedIntegerValue * 10 + integerValue % 10;

    printf("%d is %s a palindrome.\n", original, (original == reversedIntegerValue) ? "" : "not");
    return 0;
}
// Find A Generic Root Of Number
// Function to calculate the generic (digital) root of a number
int getGenericRoot(int num)
{
    // If the number is 0, its generic root is 0
    if (num == 0)
    {
        return 0;
    }

    // A number's digital root is its remainder when divided by 9.
    // If the remainder is 0 and the number isn't 0, the generic root is 9.
    if (num % 9 == 0)
    {
        return 9;
    }
    else
    {
        return num % 9; // Otherwise, the generic root is simply the remainder
    }
    // put inside main method.
    // int number = 12345; //

    // // Call the function and store the result
    // int root = getGenericRoot(number);
    // printf("The generic root of %d is: %d\n", number, root);
}

int main()
{
    // int number = 12345; // Initialize a sample integer number

    // // Call the function and store the result
    // int root = getGenericRoot(number);
    // printf("The generic root of %d is: %d\n", number, root);

    return 0;
}

//  A Calendar Taking Input From User
int calendarTakingInput()
{
    int days, start;
    printf("Enter days in month & start day (0=Sun-6=Sat): ");
    scanf("%d %d", &days, &start);

    printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Loop combines spaces and days handled together
    for (int i = 0; i < start + days; i++)
    {
        if (i < start)
            printf("     ");
        else
            printf("%5d", i - start + 1);

        if ((i + 1) % 7 == 0)
            printf("\n");
    }
    return 0;
}
// Find A Grade Of Given Marks or (Find a Grade of Given Marks Using Switch Case)


int gradeOfMarks()
{
    // #include <stdio.h> // Find A Grade Of Given Marks or (Find a Grade of Given Marks Using Switch  Case)
    int marks;
    char grade;
    printf("Enter marks (0-100): ");
    scanf("%d", &marks);

    // Validate input
    if (marks < 0 || marks > 100)
    {
        printf("Invalid marks! Please enter a value between 0 and 100.\n");
        return 1;
    }

    // Divide by 10 to get the tens digit for the switch case

    switch (marks / 10)
    {
    case 10:
    case 9:
        grade = 'A';
        break;
    case 8:
        grade = 'B';
        break;
    case 7:
        grade = 'C';
        break;
    case 6:
        grade = 'D';
        break;
    default:
        grade = 'F';
        break;
    }
    printf("Grade: %c\n", grade);

    return 0;
}
// Find Radius, Circumference and Volume of Cylinde
int Radius, circumferenceAndVolumeOfCylinde()
{
    const float PI = 3.14159;
    float diameter, height, radius, circumference, volume;
    printf("Enter the diameter of the cylinder: ");
    scanf("%f", &diameter);
    printf("Enter the height of the cylinder: ");
    scanf("%f", &height);
    radius = diameter / 2.0;
    circumference = 2 * PI * radius;
    volume = PI * radius * radius * height;
    printf("\n--- Cylinder Results ---\nRadius:        %.2f\nCircumference: %.2f\nVolume:        %.2f\n", radius, circumference, volume);
    return 0;
}

// Remove All Vowels From A String
int removeAllVowels()
{
    char s[100], *p = s, *w = s;
    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);

    while (*p)
    {
        char *v = "aeiouAEIOU";
        while (*v && *v != *p)
            v++;
        if (!*v)
            *w++ = *p;
        p++;
    }
    *w = '\0';

    printf("Result: %s", s);
    return 0;
}

int main()
{
    circumferenceAndVolumeOfCylinde();
     return 0;
}
