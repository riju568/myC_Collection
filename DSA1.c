
#include <stdio.h>
#include <math.h>


int basicArithmeticOperations()
{
    int tom;
    int Tom;
    int error;
    int a1 = 23;
    float b1 = 8.5;
    char c = 'u';
    int d = 343;
    int e = 45 + 30;
    printf("The value of a is %d\n", a1);
    printf("The value of b1+b1 is %f\n", b1 + b1);
    printf("The addition of a and b is %f\n", a1 + b1);
    printf("The division of a and b is %f\n", a1 - b1);
    printf("The Multiplication of a and b is %f\n", a1 * b1);
    printf("The sum of a and b is %d\n", e);
    return 0;
}

int AreaOfCircle()
{
    // Rule Area = PI * r * r  [miter square]
    const float PI = 3.41;
    float radiusOfCircle;
    float areaOfCircle = PI * radiusOfCircle * radiusOfCircle;
    printf("Enter the radius of circle in meter");
    scanf("%f", &radiusOfCircle);
    printf("Area of circle is %f Meter Square", areaOfCircle);

    return 0;
}

int circumferenceOfCircle()
{
    // algorithm:
    const float PI = 3.41;
    float radiusOfCircle;
    printf("Enter the radius of circle in meter\n");
    scanf("%f", &radiusOfCircle);
    float circumference = 2 * PI * radiusOfCircle;
    printf("The circumference of Circle is %f meter\n", circumference);
    //
    return 0;
}

int areaOfRectangle()
{
    // area of rectangle
    int length = 3, breadth = 8;
    int area = length * breadth;
    printf("The area of this rectangle is %d", area);
    return 0;
}
int areaOfRectangleFromUserGivenValue()
{
    // area of rectangle from user given value
    int length, breadth;
    printf("What is the length of the rectangle\n");
    scanf("%d", &length);
    printf("What is the breadth of the rectangle\n");
    scanf("%d", &breadth);
    int area = length * breadth;
    printf("The area of this rectangle is %d", area);
    return 0;
}
int circumferenceOfRectangleFromUserGivenValue()
{
    // area of rectangle from user given value
    double length, breadth;
    printf("What is the length of the rectangle\n");
    scanf("%lf", &length);
    printf("What is the breadth of the rectangle\n");
    scanf("%lf", &breadth);
    double circumference = 2 * (length + breadth);
    printf("The circumference of this rectangle is %lf", circumference);
    return 0;
}
/*
In C programming, a character variable holds ASCII value (an integer number
between 0 and 127) rather than that character itself. This integer value is the
ASCII code of the character.

For example, the ASCII value of 'A' is 65.

What this means is that, if you assign 'A' to a character variable, 65 is stored
in the variable rather than 'A' itself.

Now, let's see how we can print the ASCII value of characters in C programming.



*/
int _ASCIIcodeRendering()
{
    char c1;
    printf("Enter a character \n  ");
    scanf("%c", &c1);
    // %d displays the integer value of a character
    // %c displays the actual character
    printf("The ASCII code of character is %d\n", c1);

    return 0;
}
int AreaOFTriangle()
{
    // Rule area = (Height * Base)
    /*
    Algorithm
  Program Start
  Declare Variables
  Input values
  calculate area of triangle
  print area of triangle
  Program End
  */
    float area, Height, Base;
    printf("Enter Height of Triangle\n");
    scanf("%f", &Height);
    printf("Enter Base of Triangle\n");
    scanf("%f", &Base);
    area = (Height * Base) / 2; // According to flow of the program
    printf("Area of Triangle is %f", area);
    return 0;
}
int areaOfTriangleUsingFunction()
{
    /*
    C Program To Find Area of Triangle Using Function
  Algorithm
  Program Start
  Declare Variables
  Input values
  Calling Function to find area of triangle
  calculate area of triangle
  print area of triangle
  Program End
  Program

    */
}
int divisibilityTestByModulusOperator()
{

    printf("5 when divided by 2 leaves a remainder of %d \n",
           5 % 2); // Output :     5 when divided by 2 leaves a remainder of 1
    printf("-5 when divided by 2 leaves a remainder of %d \n",
           -5 % 2); // Output :     -5 when divided by 2 leaves a remainder of -1
    printf("5 when divided by -2 leaves a remainder of %d \n",
           5 % -2); // output :     -5 when divided by -2 leaves a remainder of 1

    return 0;
}
int mistakesInCProgramming()
{
    // int a2, b2, z2;
    // z2 = a2 + b2;
    // a2 + b2 = z2; //not allowed
    // No operator assumed to be present
    // printf("The value of 4 * 5 is %d \n", (4)(5)); // Wil not return 20 /wrong
    // ! printf("The value of 4 * 5 is %d \n", (4) * (5)); // output: The value of
    // 4 * 5 is 20

    // There are no exponentiation in c

    // printf("The value of 4 ^ 5 is %d \n", 4 ^ 5); // output: The value of 4 ^ 5
    // is 1
    printf(
        "The value of 4 to te power 5 is %d \n",
        pow(4, 5)); // note: include '<math.h>' or provide a declaration of 'pow'
    return 0;
}
// Power of a Number Using the while Loop
int aPowerOfn()
{
    int base, exp;
    long double result = 1.0;
    printf("Enter a base number: ");
    scanf("%d", &base);
    printf("Enter an exponent: ");
    scanf("%d", &exp);

    while (exp != 0)
    {
        result *= base;
        --exp;
    }
    printf("Answer = %.0Lf", result);
    return 0;
}

int powFunction()
{
    // using pow Function we need <math.h>
    double base, exp, result;
    printf("Enter a base number: ");
    scanf("%lf", &base);
    printf("Enter an exponent: ");
    scanf("%lf", &exp);

    // calculates the power
    result = pow(base, exp);
    printf("%.1lf^%.1lf = %.2lf", base, exp,
           result); // pow(base, exp) Allows return Flotaing point number
    return 0;
}
int simpleInterest()
{
    int principal = 100, rate = 4, years = 1;

    double simpleInterest = (double)(principal * rate * years) / 100;
    printf("Simple interest of %lf", simpleInterest);
    return 0;
}
/*// // volume of this cylinder
// // int radius = 3;
// // float pi = 3.14;
// int height = 23;
// printf("the volume of this cylinder is %f\n", pi * radius * radius *
// height);

// // Celsius to fahrenheit
// float celsius = 3, fahrenheit;
// fahrenheit = (celsius * 9 / 5) + 32;
// printf("The value of this celsius temperature temperature %f", fahrenheit);
*/
int typeConversion() { return 0; }
int personNameInAbbreviated()
{
    /*
    Let us use character arrays fname, mname and lname to store the first name, middle name and last name of a person. The program given below first accepts the full name, i. e., values of fname, mname and lname using a scanf function. Then the name is printed in the desired abbreviated form using a printf function. The initial letters of fname and mname are printed using fname [0]and mname[0], respectively. The program is given below.*/

    char fname[20], mname[20], lname[20]; /* person’s name */

    /* accept full name */

    printf("Enter full name (first middle last)");

    scanf("%s %s %s", fname, mname, lname);

    /* print abbreviated name */

    printf("Abbreviated name: ");

    printf("%c. %c. %s\n", fname[0], mname[0], lname);

    return 0;
}
int grossSalary()
{

    // HRA = Housing Revenue Allowance
    // DA = Dearness Allowance is a cost of living adjustment that the Government pays to public sector employees and pensioners.
    //
    // ta

    /*
    Gross Salary = Basic Salary + Other Allowance
    */
    float basic, da_percent, hra_percent, da, hra, gross_salary;

    // Asking for input
    printf("Enter the basic pay: ");
    scanf("%f", &basic);
    printf("Enter the DA percentage: ");
    scanf("%f", &da_percent);
    printf("Enter the HRA percentage: ");
    scanf("%f", &hra_percent);

    // Calculating D.A and H.R.A
    da = (basic * da_percent) / 100;
    hra = (basic * hra_percent) / 100;

    // Calculating gross salary
    gross_salary = basic + da + hra;

    // Displaying output
    printf("Gross salary of the employee is: %.2f", gross_salary);
    return 0;
}
int percentageOf5Subjects()
{
    double eng, phy, chem, math, comp;
    double FM, total, average, percentage;
    printf("Enter Full Marks in total: :- \n");
    scanf("%lf", &FM);

    printf("Enter marks in English subject: :- \n");
    scanf("%lf", &eng);
    printf("Enter marks in physics subject: :- \n");
    scanf("%lf", &phy);
    printf("Enter marks in chemistry subject: :- \n");
    scanf("%lf", &chem);
    printf("Enter marks in Mathematics subject: :- \n");
    scanf("%lf", &math);
    printf("Enter marks in computer subject: :- \n");
    scanf("%lf", &comp);
    total = (eng + phy + chem + math + comp);
    average = (total / 5);
    percentage = (total / FM) * 100;

    printf("Total marks = %.2f\n", total);
    printf("Total marks = %.2f\n", average);
    printf("Percentage =%.2f\n", percentage);

    return 0;
}

int sizeoFDataTypes()
{
    printf("Size of Int Data Types in C = %2d bytes \n", sizeof(short int));
    printf("Size of Long Int Data Types in C = %2d bytes \n", sizeof(long int));
    printf("Size of Float Data Types in C = %2d bytes \n", sizeof(float));
    printf("Size of Double Data Types in C = %2d bytes \n", sizeof(double));
    printf("Size of Long Double Data Types in C = %2d bytes \n", sizeof(long double));
    printf("Size of Char Data Types in C = %2d bytes \n", sizeof(char));
    return 0;
}

// Error in output

int nToThePowerUsingPOWFunction()
{
    // #include <math.h>  to use pow( number, power);
    int number, a3, b3, c3;
    printf("Enter the number\n");
    scanf("%d", &number);
    a3 = pow(number, 1);
    b3 = pow(number, 2);
    c3 = pow(number, 3);
    printf("%d , %d , %d", a3, b3, c3);

    return 0;
}
int nToThePower()
{
    int number;
    printf("Enter the number\n");
    scanf("%d", &number);
    printf("%d , %d , %d", number, number * number, number * number * number);

    return 0;
}

int factorialOfGivenNumber() // what is the logic behind this?
{
    /*
    Factorial of a positive integer (number) is the sum of multiplication of all the integers smaller than that positive integer. For example, factorial of 5 is 5 * 4 * 3 * 2 * 1 which equals to 120.
    */
    int i, fact = 1, number;
    printf("Enter a number: ");
    scanf("%d", &number);
    for (i = 1; i <= number; i++)
    {
        fact = fact * i;
    }
    printf("Factorial of %d is: %d", number, fact);
    return 0;
}

int main()
{
    nToThePower();
    // nToThePowerUsingPOWFunction ();
    return 0;
}
