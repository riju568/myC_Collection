/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Find the sum of all even or odd numbers in a given range using recursion.
int calculate_range_sum_recursive(int current_number, int upper_bound, bool choose_even)
{
    if (current_number > upper_bound)
    {
        return 0;
    }
    bool is_current_even = (current_number % 2 == 0);
    int term_value = 0;
    if ((choose_even && is_current_even) || (!choose_even && !is_current_even))
    {term_value = current_number;}
    return term_value + calculate_range_sum_recursive(current_number + 1, upper_bound, choose_even);
}

int SumOFNumbersGivenRecursion(void)
{
    int lower_bound, upper_bound, user_choice;
    printf("Enter lower and upper bounds: ");
    if (scanf("%d %d", &lower_bound, &upper_bound) != 2 || lower_bound > upper_bound)
    {
        printf("Error: Invalid input or interval bounds.\n");
        return 1;
    }
    printf("Select option (1 for Sum of Even numbers, 2 for Sum of Odd numbers): ");
    if (scanf("%d", &user_choice) != 1 || (user_choice != 1 && user_choice != 2))
    {
        printf("Error: Invalid selection choice.\n");
        return 1;
    }
    bool choose_even = (user_choice == 1);
    int total_accumulated_sum = calculate_range_sum_recursive(lower_bound, upper_bound, choose_even);
    printf("The sum of the requested numbers between %d and %d is: %d\n",
           lower_bound, upper_bound, total_accumulated_sum);

    return 0;
}

// Find reverse of any number using recursion.
int reverse_number_recursive(int remaining_digits, int accumulated_reversed_value)
{
    if (remaining_digits == 0)
    {
        return accumulated_reversed_value;
    }
    int last_digit = remaining_digits % 10;
    int updated_reversed_value = (accumulated_reversed_value * 10) + last_digit;
    return reverse_number_recursive(remaining_digits / 10, updated_reversed_value);
}

int ReverseNumbersRecursion(void)
{
    int user_input_number;
    printf("Enter an integer to reverse: ");
    if (scanf("%d", &user_input_number) != 1)
    {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }
    int sign_multiplier = (user_input_number < 0) ? -1 : 1;
    int absolute_input_number = user_input_number * sign_multiplier;
    int reversed_absolute_result = reverse_number_recursive(absolute_input_number, 0);
    int final_reversed_number = reversed_absolute_result * sign_multiplier;

    printf("The reversed number is: %d\n", final_reversed_number);

    return 0;
}
// Check whether a number is a palindrome or not using recursion.

int reverse_digits_recursive(int remaining_digits, int accumulated_value)
{
    if (remaining_digits == 0)
    {
        return accumulated_value;
    }
    int last_digit = remaining_digits % 10;
    int updated_accumulated_value = (accumulated_value * 10) + last_digit;
    return reverse_digits_recursive(remaining_digits / 10, updated_accumulated_value);
}
bool is_palindrome(int evaluation_number)
{
    if (evaluation_number < 0)
    {
        return false;
    }
    int reversed_number = reverse_digits_recursive(evaluation_number, 0);
    return (evaluation_number == reversed_number);
}

int CheckNumberPalindromeRecursion(void)
{
    int user_input_number;

    printf("Enter an integer: ");

    if (scanf("%d", &user_input_number) != 1)
    {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }
    if (is_palindrome(user_input_number))
    {
        printf("%d is a palindrome number.\n", user_input_number);
    }
    else
    {
        printf("%d is not a palindrome number.\n", user_input_number);
    }
    return 0;
}

// Find the sum of digits of a given number using recursion.

int SumOfDigitsOfNumberRecursion(void)
{
    int user_input_number;
    printf("Enter an integer: ");
    if (scanf("%d", &user_input_number) != 1)
    {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }
    if (is_palindrome(user_input_number))
    {
        printf("%d is a palindrome number.\n", user_input_number);
    }
    else
    {
        printf("%d is not a palindrome number.\n", user_input_number);
    }
    return 0;
}
// Find factorial of any number using recursion.
unsigned long long calculate_factorial_recursive(int evaluation_number)
{
    if (evaluation_number <= 1)
    {
        return 1;
    }
    return (unsigned long long)evaluation_number * calculate_factorial_recursive(evaluation_number - 1);
}
int FactorialNumbers_Recursion(void)
{
    int user_input_number;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &user_input_number) != 1 || user_input_number < 0)
    {
        printf("Error: Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }
    if (user_input_number > 20)
    {
        printf("Error: Input too large. Factorial calculations above 20 cause integer overflow.\n");
        return 1;
    }
    unsigned long long computational_result = calculate_factorial_recursive(user_input_number);
    printf("The factorial of %d is: %llu\n", user_input_number, computational_result);
    return 0;
}

// Generate nth Fibonacci term using recursion.
unsigned long long calculate_fibonacci_recursive(int term_index)
{
    if (term_index == 0)
    {
        return 0;
    }
    if (term_index == 1)
    {
        return 1;
    }
    return calculate_fibonacci_recursive(term_index - 1) + calculate_fibonacci_recursive(term_index - 2);
}

int nthFibonacci(void)
{
    int user_input_term;
    printf("Enter the Fibonacci term index (n starting from 0): ");
    if (scanf("%d", &user_input_term) != 1 || user_input_term < 0)
    {
        printf("Error: Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }
    if (user_input_term > 45)
    {
        printf("Error: Input too large. Values above 45 cause extreme execution delays.\n");
        return 1;
    }

    unsigned long long structural_result = calculate_fibonacci_recursive(user_input_term);
    printf("The Fibonacci term at index %d is: %llu\n", user_input_term, structural_result);

    return 0;
}

// Find gcd (HCF) of two numbers using recursion.
int calculate_gcd_recursive(int first_number, int second_number)
{
    if (second_number == 0)
    {
        return first_number;
    }
    return calculate_gcd_recursive(second_number, first_number % second_number);
}

int gcd2Recursion(void)
{
    int user_input_first, user_input_second;

    printf("Enter two integers: ");
    if (scanf("%d %d", &user_input_first, &user_input_second) != 2)
    {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }
    if (user_input_first == 0 && user_input_second == 0)
    {
        printf("Error: GCD of 0 and 0 is mathematically undefined.\n");
        return 1;
    }
    int absolute_first = abs(user_input_first);
    int absolute_second = abs(user_input_second);
    int computational_result = calculate_gcd_recursive(absolute_first, absolute_second);
    printf("The GCD (HCF) of %d and %d is: %d\n", user_input_first, user_input_second, computational_result);

    return 0;
}

// Find lcm of two numbers using recursion.
int lcm2Recursion(void)
{
    int user_input_first, user_input_second;
    printf("Enter two integers: ");
    if (scanf("%d %d", &user_input_first, &user_input_second) != 2)
    {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }
    int absolute_first = abs(user_input_first);
    int absolute_second = abs(user_input_second);
    if (absolute_first == 0 || absolute_second == 0)
    {
        printf("The LCM of the given numbers is: 0\n");
        return 0;
    }
    int greatest_common_divisor = calculate_gcd_recursive(absolute_first, absolute_second);
    int lowest_common_multiple = (absolute_first / greatest_common_divisor) * absolute_second;

    printf("The LCM of %d and %d is: %d\n", user_input_first, user_input_second, lowest_common_multiple);

    return 0;
}
// Display all array elements using recursion.
void display_array_recursive(const int data_array[], int current_index, int array_size)
{
    if (current_index >= array_size)
    {
        return;
    }
    printf("%d ", data_array[current_index]);
    display_array_recursive(data_array, current_index + 1, array_size);
}

int DisplayArrayElementsRecursion(void)
{
    int target_array_size;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &target_array_size) != 1 || target_array_size <= 0 || target_array_size > 100)
    {
        printf("Error: Invalid array size. Please enter a value between 1 and 100.\n");
        return 1;
    }
    int storage_array[100];
    printf("Enter %d integers:\n", target_array_size);
    for (int tracking_index = 0; tracking_index < target_array_size; tracking_index++)
    {
        if (scanf("%d", &storage_array[tracking_index]) != 1)
        {
            printf("Error: Invalid numeric input.\n");
            return 1;
        }
    }
    printf("The elements of the array are: ");
    display_array_recursive(storage_array, 0, target_array_size);
    printf("\n");

    return 0;
}
// Find the sum of elements of the array using recursion.
int calculate_array_sum_recursive(const int data_array[], int current_index, int array_size)
{
    if (current_index >= array_size)
    {
        return 0;
    }
    return data_array[current_index] + calculate_array_sum_recursive(data_array, current_index + 1, array_size);
}
int sumsArrayRecursion(void)
{
    int target_array_size;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &target_array_size) != 1 || target_array_size <= 0 || target_array_size > 100)
    {
        printf("Error: Invalid array size. Please enter a value between 1 and 100.\n");
        return 1;
    }
    int storage_array[100];
    printf("Enter %d integers:\n", target_array_size);
    for (int tracking_index = 0; tracking_index < target_array_size; tracking_index++)
    {
        if (scanf("%d", &storage_array[tracking_index]) != 1)
        {
            printf("Error: Invalid numeric input.\n");
            return 1;
        }
    }
    int total_accumulated_sum = calculate_array_sum_recursive(storage_array, 0, target_array_size);
    printf("The sum of elements in the array is: %d\n", total_accumulated_sum);
    return 0;
}
int main(void)
{
    // SumOFNumbersGivenRecursion();
    // ReverseNumbersRecursion();
    // CheckNumberPalindromeRecursion();
    // SumOfDigitsOfNumberRecursion();
    // FactorialNumbers_Recursion();
    // nthFibonacci();
    // gcd2Recursion();
    // lcm2Recursion();
    // DisplayArrayElementsRecursion();
    // sumsArrayRecursion();
    return 0;
}
