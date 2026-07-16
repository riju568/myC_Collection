/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/


#include <stdio.h>

int checkLeapYear()
{
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    // Leap year logic in one line
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        printf("%d is a leap year.\n", year);
    else
        printf("%d is not a leap year.\n", year);

    return 0;
}

/*
Ternary Operator: The structure (condition) ? (value_if_true) : (value_if_false) for multi-line if-else block.
*/
int greatestOfThreeNumbersUsingTernaryOperators()
{
    double n1, n2, n3, max;
    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &n1, &n2, &n3);

    max = (n1 > n2) ? ((n1 > n3) ? n1 : n3) : ((n2 > n3) ? n2 : n3);

    printf("%.2f is the greatest number.\n", max);
    return 0;
}

int checkPositiveOrNegative()
{
    double number;

    printf("Enter a number: ");
    if (scanf("%lf", &number) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (number > 0.0)
    {
        printf("%.2f is positive.\n", number);
    }
    if (number < 0.0)
    {
        printf("%.2f is negative.\n", number);
    }
    else
    {
        printf("The number is zero (neither positive nor negative).\n");
    }

    return 0;
}
int checkPositiveOrNegativeUsingTernaryOperators()
{
    double n;
    printf("Enter a number: ");
    scanf("%lf", &n);

    // Using nested ternary operators
    printf("%.2f is %s.\n", n, (n > 0) ? "positive" : (n < 0) ? "negative"
                                                              : "zero");

    return 0;
}
int checkingCharacterIsAnAlphabetOrNot()
{
    char c;
    printf("Enter character: ");
    scanf("%c", &c);

    // One-line check using ternary operator using manual ASCII code
    printf("'%c' is %s an alphabet.\n", c,
           (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? "" : "not");

    return 0;
}
int UppercaseLowercaseSpecialCharacteraaaaOrDigit()
{
    char c;
    printf("Enter character: ");
    scanf("%c", &c);

    printf("'%c' is %s.\n", c,
           (c >= 'A' && c <= 'Z') ? "Uppercase" : (c >= 'a' && c <= 'z') ? "Lowercase"
                                              : (c >= '0' && c <= '9')   ? "a Digit"
                                                                         : "a Special Character");

    return 0;
}

int positiveOrNegative()
{
    double n;
    printf("Enter a number: ");
    scanf("%lf", &n);
    printf("The number is %s.\n", (n > 0) ? "POSITIVE" : (n < 0) ? "NEGATIVE"
                                                                 : "ZERO");
    return 0;
}
int checkNumberIsEvenOrOdd()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    // True:False
    printf("The number is %s.\n", (n % 2 == 0) ? "EVEN" : "ODD");
    return 0;
}
int greatestAmongThreeNumbers()
{
    double a, b, c;
    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    printf("The greatest number is: %.2lf\n", max);
    return 0;
}

int checkLeapYearUsingTernaryOperators()
{
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    printf("%d is %sa leap year.\n", year, ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) ? " " : "not ");
    return 0;
}

int dateIsCorrectOrNot()
{
    int d, m, y, max_d = 31;
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &d, &m, &y);

    // 1. Basic validation for year, month, and day
    if (y < 1 || m < 1 || m > 12 || d < 1)
    {
        printf("Invalid Date\n");
        return 0;
    }

    // 2. Adjust maximum days for April, June, September, November
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        max_d = 30;
    }
    // 3. Adjust maximum days for February
    else if (m == 2)
    {
        max_d = ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
    }

    // 4. Final check
    printf("%s Date\n", (d <= max_d) ? "Valid" : "Invalid");
    return 0;
}

int votingEligibilityChecker()
{
    int usersAge;
    char name[50];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter your age: ");
    scanf("%d", &usersAge);
    printf("%sYou are %d and %s to vote.\n", name, usersAge, (usersAge >= 18) ? "Eligible" : "Not eligible");

    return 0;
}

int maximumBetweenTwoNumbers()
{
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);

    printf("The maximum number is: %lf\n", (a > b) ? a : b);
    return 0;
}

// Universal macro to find max of two values
#define MAXB2(a, b) ((a) > (b) ? (a) : (b))

int maximumBetweenTheThreeNumbers()
{
    int a = 12, b = 45, c = 23;

    // Nesting the macro to find the max of three numbers
    int MAXB3 = MAXB2(a, MAXB2(b, c));

    printf("The maximum is: %d\n", MAXB3);
    return 0;
}
// Check whether a number is negative, positive or zero.
int CheckNegativePositiveZero()
{
    double numberToCheck;
    printf("Enter a number: ");
    if (scanf("%lf", &numberToCheck) == 1)
        printf(numberToCheck > 0 ? "Positive\n" : (numberToCheck < 0 ? "Negative\n" : "Zero\n"));

    return 0;
}
int divisibleBy5And11OrNot()
{
    int numberToCheck;
    printf("Enter any number: ");
    scanf("%d", &numberToCheck);

    // Using 55 (5 * 11) is mathematically equivalent and more efficient
    if (numberToCheck % 55 == 0)
    {
        printf("%d is divisible by 5 and 11.\n", numberToCheck);
    }
    else
    {
        printf("%d is NOT divisible by 5 and 11.\n", numberToCheck);
    }

    return 0;
}
int evenOrOdd()
{
    int evenOrNot;
    printf("Enter a number: ");
    scanf("%d", &evenOrNot);
    (evenOrNot % 2 == 0) ? printf("%d is even.\n", evenOrNot) : printf("%d is odd.\n", evenOrNot);
    return 0;
}
int leapYearOrNot()
{
    int yearToCheck;
    printf("Enter a year: ");
    scanf("%d", &yearToCheck);

    if ((yearToCheck % 4 == 0 && yearToCheck % 100 != 0) || (yearToCheck % 400 == 0))
    {
        printf("%d is a leap year.\n", yearToCheck);
    }
    else
    {
        printf("%d is NOT a leap year.\n", yearToCheck);
    }

    return 0;
}
int alphabetOrNot()
{
    char characterToCheck;
    printf("Enter any character: ");
    scanf("%c", &characterToCheck);

    if ((characterToCheck >= 'a' && characterToCheck <= 'z') || (characterToCheck >= 'A' && characterToCheck <= 'Z'))
    {
        printf("'%c' is an alphabet.\n", characterToCheck);
    }
    else
    {
        printf("'%c' is NOT an alphabet.\n", characterToCheck);
    }

    return 0;
}

int numberOfWeekDays()
{
    int dayNumber;
    // Array of day names (1-indexed mapping)
    const char *days[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    printf("Enter week number (1-7): ");
    if (scanf("%d", &dayNumber) == 1 && dayNumber >= 1 && dayNumber <= 7)
    {
        printf("%s\n", days[dayNumber]);
    }
    else
    {
        printf("Invalid input! Please enter a number between 1 and 7.\n");
    }

    return 0;
}
int numberOfDaysInAMonth()
{
    int month;
    // Array where index 1 = Jan, 2 = Feb, etc. (0 is a placeholder)
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter month number (1-12): ");
    if (scanf("%d", &month) != 1 || month < 1 || month > 12)
    {
        return printf("Invalid month!\n"), 1;
    }
    month == 2 ? printf("28 or 29 days\n") : printf("%d days\n", days[month]);

    return 0;
}
// • Count the total number of notes in a given amount.

int notesIGvenAmount()
{
    int month;
    // Array where index 1 = Jan, 2 = Feb, etc. (0 is a placeholder)
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter month number (1-12): ");
    if (scanf("%d", &month) != 1 || month < 1 || month > 12)
    {
        return printf("Invalid month!\n"), 1;
    }
    month == 2 ? printf("28 or 29 days\n") : printf("%d days\n", days[month]);

    return 0;
}
int equilateralIsoscelesOrScaleneTriangle()
{

    float a, b, c;

    printf("Enter three sides of the triangle: ");
    if (scanf("%f %f %f", &a, &b, &c) != 3 || !(a + b > c && a + c > b && b + c > a))
    {
        printf("Invalid Triangle\n");
        return 1;
    }

    if (a == b && b == c)
        printf("Equilateral Triangle\n");
    else if (a == b || b == c || a == c)
        printf("Isosceles Triangle\n");
    else
        printf("Scalene Triangle\n");
    return 0;
}
int allRootsOfAQuadraticEquation()
{
    float a, b, c, d, r1, r2, i = 0, s = 0;
    printf("Enter a, b, c: ");
    if (scanf("%f %f %f", &a, &b, &c) != 3 || a == 0)
        return 1;

    d = b * b - 4 * a * c;
    float v = d < 0 ? -d : d;

    // Inline Babylonian square root approximation
    if (v > 0)
    {
        s = v;
        for (int k = 0; k < 20; k++)
            s = (s + v / s) / 2;
    }

    r1 = -b / (2 * a);
    r2 = s / (2 * a);

    if (d > 0)
        printf("Roots: %.2f and %.2f\n", r1 + r2, r1 - r2);
    if (d == 0)
        printf("Root: %.2f\n", r1);
    if (d < 0)
        printf("Roots: %.2f + %.2fi and %.2f - %.2fi\n", r1, r2, r1, r2);

    return 0;
}
int profitOrLoss()
{
    float cp, sp;
    printf("Enter CP and SP: ");
    if (scanf("%f %f", &cp, &sp) != 2)
        return 1;

    if (sp == cp)
        printf("No Profit No Loss\n");
    else
        printf("%s = %.2f\n", (sp > cp) ? "Profit" : "Loss", (sp > cp) ? (sp - cp) : (cp - sp));

    return 0;
}

int main()
{
    checkLeapYear();
    // alphabetOrNot();
    return 0;
}
