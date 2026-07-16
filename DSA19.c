/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/

#include <stdio.h>

// Access two-dimensional array using pointers.
int twoDimensionalArrayPointers(void)
{
    int total_rows = 2;
    int total_columns = 3;
    int two_dimensional_array[2][3] = {{10, 20, 30}, {40, 50, 60}};

    for (int row_index = 0; row_index < total_rows; row_index++)
    {
        for (int column_index = 0; column_index < total_columns; column_index++)
        {
            // Using pointer arithmetic to fetch value
            int element_value = *(*(two_dimensional_array + row_index) + column_index);
            printf("%d ", element_value);
        }
        printf("\n");
    }
    return 0;
}

// Add two matrix using pointers.
void add_matrices(const int *first_matrix, const int *second_matrix, int *result_matrix, int total_rows, int total_columns)
{
    for (int row_index = 0; row_index < total_rows; row_index++)
    {
        for (int column_index = 0; column_index < total_columns; column_index++)
        {
            int memory_offset = (row_index * total_columns) + column_index;
            *(result_matrix + memory_offset) = *(first_matrix + memory_offset) + *(second_matrix + memory_offset);
        }
    }
}

// Multiply two matrix using pointers.
void multiply_matrices(const int *first_matrix, const int *second_matrix, int *result_matrix, int rows_first, int columns_first, int columns_second)
{
    for (int row_index = 0; row_index < rows_first; row_index++)
    {
        for (int column_index = 0; column_index < columns_second; column_index++)
        {
            int *result_element_pointer = result_matrix + (row_index * columns_second) + column_index;
            *result_element_pointer = 0; // Initialize element

            for (int inner_index = 0; inner_index < columns_first; inner_index++)
            {
                int first_matrix_element = *(first_matrix + (row_index * columns_first) + inner_index);
                int second_matrix_element = *(second_matrix + (inner_index * columns_second) + column_index);

                *result_element_pointer += first_matrix_element * second_matrix_element;
            }
        }
    }
}

// Find the length of the string using pointers.
int get_string_length(const char *input_string_pointer)
{
    const char *current_character_pointer = input_string_pointer;
    while (*current_character_pointer != '\0')
    {
        current_character_pointer++;
    }
    return current_character_pointer - input_string_pointer;
}

// In short How to Copy one string to another using pointer.
void copy_string(char *destination_pointer, const char *source_pointer)
{
    while ((*destination_pointer++ = *source_pointer++))
        ;
}

// Concatenate two strings using pointers.
void concatenate_strings(char *destination_pointer, const char *source_pointer)
{
    while (*destination_pointer != '\0')
    {
        destination_pointer++;
    }
    while ((*destination_pointer++ = *source_pointer++))
        ;
}

// Compare two strings using pointers.
int compare_strings(const char *first_string_pointer, const char *second_string_pointer)
{
    while (*first_string_pointer && (*first_string_pointer == *second_string_pointer))
    {
        first_string_pointer++;
        second_string_pointer++;
    }
    return *(const unsigned char *)first_string_pointer - *(const unsigned char *)second_string_pointer;
}

// Find the reverse of a string using pointers. (Restored Missing Logic)
void reverse_string(char *string_pointer)
{
    char *start_pointer = string_pointer;
    char *end_pointer = string_pointer;

    while (*end_pointer != '\0')
    {
        end_pointer++;
    }
    end_pointer--; // Step back to the last actual character before '\0'

    while (start_pointer < end_pointer)
    {
        char temporary_character = *start_pointer;
        *start_pointer = *end_pointer;
        *end_pointer = temporary_character;
        start_pointer++;
        end_pointer--;
    }
}

// Sort array using pointers. (Restored Missing Logic)
void bubble_sort_array(int *array_pointer, int array_size)
{
    for (int pass_index = 0; pass_index < array_size - 1; pass_index++)
    {
        for (int element_index = 0; element_index < array_size - pass_index - 1; element_index++)
        {
            int *current_element_pointer = array_pointer + element_index;
            int *next_element_pointer = array_pointer + element_index + 1;

            if (*current_element_pointer > *next_element_pointer)
            {
                int temporary_value = *current_element_pointer;
                *current_element_pointer = *next_element_pointer;
                *next_element_pointer = temporary_value;
            }
        }
    }
}

// Return multiple values from a function using pointers.
void calculate_minimum_and_maximum(const int *array_pointer, int array_size, int *returned_minimum, int *returned_maximum)
{
    if (array_size <= 0)
        return;

    *returned_minimum = *array_pointer;
    *returned_maximum = *array_pointer;

    for (int element_index = 1; element_index < array_size; element_index++)
    {
        int current_value = *(array_pointer + element_index);

        if (current_value < *returned_minimum)
        {
            *returned_minimum = current_value;
        }
        if (current_value > *returned_maximum)
        {
            *returned_maximum = current_value;
        }
    }
}
int main(void)
{
    printf("1. Accessing 2D Array via Pointers\n");
    twoDimensionalArrayPointers();
    printf("\n");

    printf("2. Add Two Matrices Using Pointers\n");
    int matrix_a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrix_b[2][3] = {{10, 20, 30}, {40, 50, 60}};
    int addition_result[2][3];
    add_matrices((int *)matrix_a, (int *)matrix_b, (int *)addition_result, 2, 3);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", addition_result[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("3. Multiply Two Matrices Using Pointers \n");
    int mult_matrix_a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int mult_matrix_b[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int multiplication_result[2][2];
    multiply_matrices((int *)mult_matrix_a, (int *)mult_matrix_b, (int *)multiplication_result, 2, 3, 2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", multiplication_result[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("4. Find Length of String Using Pointers\n");
    const char *sample_string = "CrossPlatformC";
    printf("Length of '%s' is: %d\n\n", sample_string, get_string_length(sample_string));

    printf("5. Copy One String to Another Using Pointer\n");
    char copy_destination[50];
    copy_string(copy_destination, "Hello Pointer World");
    printf("Copied String: %s\n\n", copy_destination);

    printf("6. Concatenate Two Strings Using Pointers\n");
    char concat_destination[50] = "Base String ";
    concatenate_strings(concat_destination, "Extension");
    printf("Concatenated String: %s\n\n", concat_destination);

    printf("7. Compare Two Strings Using Pointers\n");
    const char *str1 = "Apple";
    const char *str2 = "Banana";
    int comparison_result = compare_strings(str1, str2);
    if (comparison_result < 0)
        printf("'%s' comes before '%s'\n\n", str1, str2);
    else if (comparison_result > 0)
        printf("'%s' comes after '%s'\n\n", str1, str2);
    else
        printf("Strings are structurally identical\n\n");

    printf("8. Find the Reverse of a String Using Pointers\n");
    char reverse_target[] = "FlexiblePointers";
    printf("Original: %s\n", reverse_target);
    reverse_string(reverse_target);
    printf("Reversed: %s\n\n", reverse_target);

    printf("9. Sort Array Using Pointers\n");
    int unsorted_array[6] = {77, 12, 5, 90, 22, 43};
    printf("Original Array: ");
    for (int i = 0; i < 6; i++)
        printf("%d ", unsorted_array[i]);
    printf("\n");
    bubble_sort_array(unsorted_array, 6);
    printf("Sorted Array:   ");
    for (int i = 0; i < 6; i++)
        printf("%d ", unsorted_array[i]);
    printf("\n\n");

    printf("10. Return Multiple Values from Function Using Pointers\n");
    int dataset[5] = {23, 5, 89, 2, 42};
    int minimum_value;
    int maximum_value;
    calculate_minimum_and_maximum(dataset, 5, &minimum_value, &maximum_value);
    printf("Dataset: {23, 5, 89, 2, 42}\n");
    printf("Min calculated: %d, Max calculated: %d\n", minimum_value, maximum_value);

    return 0;
}
