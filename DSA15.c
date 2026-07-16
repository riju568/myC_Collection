/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Check whether a number is prime, Armstrong or perfect number using functions
bool is_prime(int number);
bool is_armstrong(int number);
bool is_perfect(int number);

int CheckPrimeArmstrongPerfectFunctions()
{
    int user_number;

    printf("Enter a positive integer: ");
    if (scanf("%d", &user_number) != 1 || user_number < 0)
    {
        printf("Invalid input. Please enter a valid positive integer.\n");
        return 1;
    }

    printf("\nResults for %d:\n", user_number);
    printf("-------------------------\n");
    if (is_prime(user_number))
    {
        printf("- It is a Prime number.\n");
    }
    else
    {
        printf("- It is NOT a Prime number.\n");
    }
    if (is_armstrong(user_number))
    {
        printf("- It is an Armstrong number.\n");
    }
    else
    {
        printf("- It is NOT an Armstrong number.\n");
    }
    if (is_perfect(user_number))
    {
        printf("- It is a Perfect number.\n");
    }
    else
    {
        printf("- It is NOT a Perfect number.\n");
    }

    return 0;
}
bool is_prime(int number)
{
    if (number <= 1)
    {
        return false;
    }
    if (number == 2)
    {
        return true;
    }
    if (number % 2 == 0)
    {
        return false;
    }
    int boundary = (int)sqrt(number);
    for (int i = 3; i <= boundary; i += 2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

/**
 * Checks if a number is an Armstrong number.
 * Works universally for any number of digits (e.g., 153, 1634).
 */
bool is_armstrong(int number)
{
    if (number < 0)
    {
        return false;
    }

    int temporary_hold = number;
    int number_of_digits = 0;
    int sum_of_powers = 0;

    // Count the number of digits
    int count_temp = number;
    if (count_temp == 0)
    {
        number_of_digits = 1;
    }
    else
    {
        while (count_temp > 0)
        {
            number_of_digits++;
            count_temp /= 10;
        }
    }

    // Calculate sum of digits raised to the power of number_of_digits
    temporary_hold = number;
    while (temporary_hold > 0)
    {
        int remainder = temporary_hold % 10;

        // Safe casting and precise powering without precision loss issues
        sum_of_powers += (int)round(pow(remainder, number_of_digits));
        temporary_hold /= 10;
    }

    return (sum_of_powers == number);
}
bool is_perfect(int number)
{
    if (number <= 1)
    {
        return false;
    }

    int sum_of_proper_divisors = 1;
    int boundary = (int)sqrt(number);

    for (int i = 2; i <= boundary; i++)
    {
        if (number % i == 0)
        {
            sum_of_proper_divisors += i;
            if (i != (number / i))
            {
                sum_of_proper_divisors += (number / i);
            }
        }
    }

    return (sum_of_proper_divisors == number);
}

// Find all prime numbers between the given interval using functions.
int PrimeNumbersBetweenFunctions(void)
{
    int lower_bound, upper_bound;
    printf("Enter lower and upper bounds: ");
    if (scanf("%d %d", &lower_bound, &upper_bound) != 2 || lower_bound > upper_bound)
    {
        printf("Error: Invalid input or interval.\n");
        return 1;
    }
    printf("Prime numbers between %d and %d are: ", lower_bound, upper_bound);
    for (int current_number = lower_bound; current_number <= upper_bound; current_number++)
    {
        if (is_prime(current_number))
        {
            printf("%d ", current_number);
        }
    }
    printf("\n");
    return 0;
}

// Print all strong numbers between the given interval using functions.
int get_factorial(int digit)
{
    int factorial_result = 1;
    for (int multiplier = 1; multiplier <= digit; multiplier++)
    {
        factorial_result *= multiplier;
    }
    return factorial_result;
}
bool is_strong_number(int evaluation_number)
{
    int temporary_holder = evaluation_number;
    int factorial_sum = 0;
    while (temporary_holder > 0)
    {
        int current_digit = temporary_holder % 10;
        factorial_sum += get_factorial(current_digit);
        temporary_holder /= 10;
    }

    return (factorial_sum == evaluation_number && evaluation_number > 0);
}
int PrintAllStrongNumbersBetweenInterval(void)
{
    int lower_bound, upper_bound;
    printf("Enter lower and upper bounds: ");
    if (scanf("%d %d", &lower_bound, &upper_bound) != 2 || lower_bound > upper_bound)
    {
        printf("Error: Invalid input or interval.\n");
        return 1;
    }
    printf("Strong numbers between %d and %d are: ", lower_bound, upper_bound);
    for (int current_number = lower_bound; current_number <= upper_bound; current_number++)
    {
        if (is_strong_number(current_number))
        {
            printf("%d ", current_number);
        }
    }
    printf("\n");
    return 0;
}

// Armstrong numbers between the given interval using functions.
int calculate_power(int base, int exponent)
{
    int power_result = 1;
    for (int counter = 0; counter < exponent; counter++)
    {
        power_result *= base;
    }
    return power_result;
}
int count_digits(int evaluation_number)
{
    int digit_count = 0;
    while (evaluation_number != 0)
    {
        digit_count++;
        evaluation_number /= 10;
    }
    return digit_count;
}
bool is_armstrong_number(int evaluation_number)
{
    if (evaluation_number < 0)
        return false;
    int total_digits = count_digits(evaluation_number);
    int temporary_holder = evaluation_number;
    int power_sum = 0;

    while (temporary_holder > 0)
    {
        int current_digit = temporary_holder % 10;
        power_sum += calculate_power(current_digit, total_digits);
        temporary_holder /= 10;
    }
    return (power_sum == evaluation_number);
}

int PrintAllArmstrongNumbersBetweenInterval(void)
{
    int lower_bound, upper_bound;
    printf("Enter lower and upper bounds: ");
    if (scanf("%d %d", &lower_bound, &upper_bound) != 2 || lower_bound > upper_bound)
    {
        printf("Error: Invalid input or interval.\n");
        return 1;
    }
    printf("Armstrong numbers between %d and %d are: ", lower_bound, upper_bound);
    for (int current_number = lower_bound; current_number <= upper_bound; current_number++)
    {
        if (is_armstrong_number(current_number))
        {
            printf("%d ", current_number);
        }
    }
    printf("\n");
    return 0;
}

// Print all perfect numbers between the given interval using functions.
bool is_perfect_number(int evaluation_number)
{
    if (evaluation_number < 2)
        return false;
    int divisor_sum = 1;
    for (int divisor = 2; divisor * divisor <= evaluation_number; divisor++)
    {
        if (evaluation_number % divisor == 0)
        {
            divisor_sum += divisor;
            if (divisor != evaluation_number / divisor)
            {
                divisor_sum += evaluation_number / divisor;
            }
        }
    }

    return (divisor_sum == evaluation_number);
}

int PrintAllPerfectNumbersBetweenInterval(void)
{
    int lower_bound, upper_bound;
    printf("Enter lower and upper bounds: ");
    if (scanf("%d %d", &lower_bound, &upper_bound) != 2 || lower_bound > upper_bound)
    {
        printf("Error: Invalid input or interval.\n");
        return 1;
    }
    printf("Perfect numbers between %d and %d are: ", lower_bound, upper_bound);
    for (int current_number = lower_bound; current_number <= upper_bound; current_number++)
    {
        if (is_perfect_number(current_number))
        {
            printf("%d ", current_number);
        }
    }
    printf("\n");
    return 0;
}

// Find the power of any number using recursion.
double calculate_power_recursive(double base_value, int exponent_value)
{
    if (exponent_value == 0)
        return 1.0;
    if (exponent_value < 0)
    {
        return 1.0 / calculate_power_recursive(base_value, -exponent_value);
    }
    return base_value * calculate_power_recursive(base_value, exponent_value - 1);
}

int PrintPowerOfAnyNumberUsingRecursion(void)
{
    double input_base;
    int input_exponent;
    printf("Enter base and exponent: ");
    if (scanf("%lf %d", &input_base, &input_exponent) != 2)
    {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }
    if (input_base == 0.0 && input_exponent < 0)
    {
        printf("Error: Division by zero (0 cannot be raised to a negative power).\n");
        return 1;
    }
    double computational_result = calculate_power_recursive(input_base, input_exponent);
    printf("%.2lf raised to the power of %d is: %.6lf\n", input_base, input_exponent, computational_result);
    return 0;
}

// Print all natural numbers between 1 to n using recursion.
void print_natural_numbers_recursive(int current_number, int target_limit)
{
    if (current_number > target_limit)
    {
        return;
    }
    printf("%d ", current_number);
    print_natural_numbers_recursive(current_number + 1, target_limit);
}
int PrintAllNaturalNumbersBetween1ToNUsingRecursion(void)
{
    int user_input_limit;
    const int starting_natural_number = 1;

    printf("Enter the upper limit (n): ");
    if (scanf("%d", &user_input_limit) != 1 || user_input_limit < starting_natural_number)
    {
        printf("Error: Invalid input. Please enter a natural number greater than or equal to 1.\n");
        return 1;
    }
    printf("Natural numbers from 1 to %d are: ", user_input_limit);
    print_natural_numbers_recursive(starting_natural_number, user_input_limit);
    printf("\n");
    return 0;
}
// Print all even or odd numbers in a given range using recursion.
void print_range_numbers_recursive(int current_number, int upper_bound, bool choose_even)
{
    if (current_number > upper_bound)
    {
        return;
    }
    bool is_current_even = (current_number % 2 == 0);
    if ((choose_even && is_current_even) || (!choose_even && !is_current_even))
    {
        printf("%d ", current_number);
    }
    print_range_numbers_recursive(current_number + 1, upper_bound, choose_even);
}

int PrintEvenOrOddNumbersRecursion(void)
{
    int lower_bound, upper_bound, user_choice;
    printf("Enter lower and upper bounds: ");
    if (scanf("%d %d", &lower_bound, &upper_bound) != 2 || lower_bound > upper_bound)
    {
        printf("Error: Invalid input or interval bounds.\n");
        return 1;
    }
    printf("Select option (1 for Even numbers, 2 for Odd numbers): ");
    if (scanf("%d", &user_choice) != 1 || (user_choice != 1 && user_choice != 2))
    {
        printf("Error: Invalid selection choice.\n");
        return 1;
    }
    bool choose_even = (user_choice == 1);
    printf("The requested numbers between %d and %d are: ", lower_bound, upper_bound);
    print_range_numbers_recursive(lower_bound, upper_bound, choose_even);
    printf("\n");
    return 0;
}
//  Sum of all natural numbers between 1 to n using recursion.
int calculate_natural_sum_recursive(int target_limit)
{
    if (target_limit == 1)
    {
        return 1;
    }
    return target_limit + calculate_natural_sum_recursive(target_limit - 1);
}

int SumNaturalNumbers1tonUsingRecursion(void)
{
    int user_input_limit;
    const int minimum_natural_number = 1;

    printf("Enter the upper limit (n): ");
    // Security check: Validate integer conversion and prevent infinite execution or stack overflows
    if (scanf("%d", &user_input_limit) != 1 || user_input_limit < minimum_natural_number)
    {
        printf("Error: Invalid input. Please enter a natural number greater than or equal to 1.\n");
        return 1;
    }

    int total_sum = calculate_natural_sum_recursive(user_input_limit);
    printf("The sum of natural numbers from 1 to %d is: %d\n", user_input_limit, total_sum);

    return 0;
}
int main(void)
{
    // CheckPrimeArmstrongPerfectFunctions();
    // PrimeNumbersBetweenFunctions();
    // PrintAllStrongNumbersBetweenInterval();
    // PrintAllArmstrongNumbersBetweenInterval();
    // PrintAllPerfectNumbersBetweenInterval();
    // PrintPowerOfAnyNumberUsingRecursion();
    // PrintAllNaturalNumbersBetween1ToNUsingRecursion();
    // PrintEvenOrOddNumbersRecursion();
    // SumNaturalNumbers1tonUsingRecursion();
    return 0;
}
