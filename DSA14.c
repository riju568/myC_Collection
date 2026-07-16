/*
This code base own and maintained by Tanmoy Samnata using standardization C23 (ISO/IEC 9899:2024)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Remove the last occurrence of a word in a given string.
void remove_last_occurrence_of_word(char *input_string_buffer, const char *word_to_remove)
{
    int input_string_length = strlen(input_string_buffer);
    int word_to_remove_length = strlen(word_to_remove);
    if (word_to_remove_length == 0 || input_string_length < word_to_remove_length)
    {
        return;
    }
    int last_occurrence_index = -1;
    for (int current_search_index = input_string_length - word_to_remove_length; current_search_index >= 0; current_search_index--)
    {
        int is_match = 1;
        for (int character_comparison_index = 0; character_comparison_index < word_to_remove_length; character_comparison_index++)
        {
            if (input_string_buffer[current_search_index + character_comparison_index] != word_to_remove[character_comparison_index])
            {
                is_match = 0;
                break;
            }
        }

        if (is_match)
        {
            int is_left_boundary_valid = (current_search_index == 0) || (input_string_buffer[current_search_index - 1] == ' ');
            int is_right_boundary_valid = (current_search_index + word_to_remove_length == input_string_length) || (input_string_buffer[current_search_index + word_to_remove_length] == ' ');
            if (is_left_boundary_valid && is_right_boundary_valid)
            {
                last_occurrence_index = current_search_index;
                break;
            }
        }
    }
    if (last_occurrence_index != -1)
    {
        int characters_to_remove_count = word_to_remove_length;
        int modification_start_index = last_occurrence_index;
        if (last_occurrence_index > 0 && input_string_buffer[last_occurrence_index - 1] == ' ')
        {
            modification_start_index--;
            characters_to_remove_count++;
        }

        else if (last_occurrence_index + word_to_remove_length < input_string_length && input_string_buffer[last_occurrence_index + word_to_remove_length] == ' ')
        {
            characters_to_remove_count++;
        }
        for (int shift_index = modification_start_index; shift_index + characters_to_remove_count <= input_string_length; shift_index++)
        {
            input_string_buffer[shift_index] = input_string_buffer[shift_index + characters_to_remove_count];
        }
    }
}

int Remove_last_occurrence_of_word_in_a_given_string()
{
    char sample_text_buffer[200] = "apple banana orange apple grape apple banana";
    const char *target_word_to_remove = "apple";
    printf("Original String: '%s'\n", sample_text_buffer);
    printf("Word to remove: '%s'\n", target_word_to_remove);
    remove_last_occurrence_of_word(sample_text_buffer, target_word_to_remove);
    printf("Modified String: '%s'\n", sample_text_buffer);

    return 0;
}
void remove_all_occurrences_of_word_from_string(char *input_string_character_buffer, const char *target_word_to_be_removed)
{
    int target_word_to_be_removed_length = strlen(target_word_to_be_removed);
    if (target_word_to_be_removed_length == 0)
    {
        return;
    }

    int current_evaluation_buffer_index = 0;
    while (input_string_character_buffer[current_evaluation_buffer_index] != '\0')
    {
        int total_input_string_length = strlen(input_string_character_buffer);
        if (total_input_string_length - current_evaluation_buffer_index < target_word_to_be_removed_length)
        {
            break;
        }

        int is_substring_matching_perfectly = 1;

        // Step 1: Compare the sequence of characters starting at the current evaluation index
        for (int character_comparison_offset_index = 0;
             character_comparison_offset_index < target_word_to_be_removed_length;
             character_comparison_offset_index++)
        {

            if (input_string_character_buffer[current_evaluation_buffer_index + character_comparison_offset_index] !=
                target_word_to_be_removed[character_comparison_offset_index])
            {
                is_substring_matching_perfectly = 0;
                break;
            }
        }

        // Step 2: Validate boundaries to ensure it is an isolated word, not part of a larger token
        if (is_substring_matching_perfectly)
        {
            int is_left_side_boundary_valid = (current_evaluation_buffer_index == 0) || (input_string_character_buffer[current_evaluation_buffer_index - 1] == ' ');
            int is_right_side_boundary_valid = (current_evaluation_buffer_index + target_word_to_be_removed_length == total_input_string_length) || (input_string_character_buffer[current_evaluation_buffer_index + target_word_to_be_removed_length] == ' ');
            if (is_left_side_boundary_valid && is_right_side_boundary_valid)
            {
                int total_characters_to_be_removed_count = target_word_to_be_removed_length;
                int modification_starting_buffer_index = current_evaluation_buffer_index;

                // Adjust space: If it's not the first word, include the preceding space in the removal window
                if (current_evaluation_buffer_index > 0 &&
                    input_string_character_buffer[current_evaluation_buffer_index - 1] == ' ')
                {
                    modification_starting_buffer_index--;
                    total_characters_to_be_removed_count++;
                }
                // Adjust space: If it is the first word but followed by a space, include the trailing space
                else if (current_evaluation_buffer_index + target_word_to_be_removed_length < total_input_string_length &&
                         input_string_character_buffer[current_evaluation_buffer_index + target_word_to_be_removed_length] == ' ')
                {
                    total_characters_to_be_removed_count++;
                }

                // Step 3: Shift all subsequent characters leftward to overwrite the matched word
                for (int shift_operation_buffer_index = modification_starting_buffer_index;
                     shift_operation_buffer_index + total_characters_to_be_removed_count <= total_input_string_length;
                     shift_operation_buffer_index++)
                {

                    input_string_character_buffer[shift_operation_buffer_index] =
                        input_string_character_buffer[shift_operation_buffer_index + total_characters_to_be_removed_count];
                }

                // Adjust the evaluation pointer backward to compensate for the removed segment space
                current_evaluation_buffer_index = modification_starting_buffer_index;
                continue;
            }
        }

        // Move to the next character index if no removal occurred at this position
        current_evaluation_buffer_index++;
    }
}

int Remove_All_occurrence_of_word_in_a_given_string()
{

    char demonstration_sample_text_buffer[256] = "apple banana apple orange apple grape apple";
    const char *target_word_to_find_and_delete = "apple";
    printf("--- Global Removal Execution ---\n");
    printf("Original String : '%s'\n", demonstration_sample_text_buffer);
    printf("Target Word     : '%s'\n", target_word_to_find_and_delete);
    remove_all_occurrences_of_word_from_string(demonstration_sample_text_buffer, target_word_to_find_and_delete);
    printf("Modified String : '%s'\n", demonstration_sample_text_buffer);
    printf("--------------------------------\n");
    return 0;
}

// A Trim leading white space characters from a given string.
void trim_leading_whitespace_characters_from_string(char *input_string_character_buffer)
{
    // Safety check
    if (input_string_character_buffer == NULL || input_string_character_buffer[0] == '\0')
    {
        return;
    }

    int total_input_string_length = strlen(input_string_character_buffer);
    int total_leading_whitespace_count = 0;

    // 1: Count how many consecutive whitespace characters exist at the start of the string
    while (input_string_character_buffer[total_leading_whitespace_count] != '\0' && isspace((unsigned char)input_string_character_buffer[total_leading_whitespace_count]))
    {
        total_leading_whitespace_count++;
    }

    // 2: If leading whitespaces were found, shift the remaining text to the front
    if (total_leading_whitespace_count > 0)
    {
        for (int shift_operation_buffer_index = 0;
             shift_operation_buffer_index <= total_input_string_length - total_leading_whitespace_count;
             shift_operation_buffer_index++)
        {

            input_string_character_buffer[shift_operation_buffer_index] = input_string_character_buffer[shift_operation_buffer_index + total_leading_whitespace_count];
        }
    }
}

int TrimWhiteSpaceString()
{
    // Demonstration string containing leading spaces and tabs
    char demonstration_sample_text_buffer[256] = "   \t  hello universe runnable c code";
    printf("--- Leading Trim Execution ---\n");
    printf("Original String : '%s'\n", demonstration_sample_text_buffer);
    trim_leading_whitespace_characters_from_string(demonstration_sample_text_buffer);
    printf("Modified String : '%s'\n", demonstration_sample_text_buffer);
    printf("------------------------------\n");

    return 0;
}

// Trim both leading and trailing white space characters from a given string.
void trim_leading_and_trailing_whitespace_characters_from_string(char *input_string_character_buffer)
{
    // Safety check
    if (input_string_character_buffer == NULL || input_string_character_buffer[0] == '\0')
    {
        return;
    }
    int total_input_string_length = strlen(input_string_character_buffer);

    // --- 1: Trim Trailing Whitespace ---
    int trailing_evaluation_index = total_input_string_length - 1;
    while (trailing_evaluation_index >= 0 && isspace((unsigned char)input_string_character_buffer[trailing_evaluation_index]))
    {
        input_string_character_buffer[trailing_evaluation_index] = '\0';
        trailing_evaluation_index--;
    }
    int updated_input_string_length = strlen(input_string_character_buffer);
    int total_leading_whitespace_count = 0;
    while (input_string_character_buffer[total_leading_whitespace_count] != '\0' && isspace((unsigned char)input_string_character_buffer[total_leading_whitespace_count]))
    {
        total_leading_whitespace_count++;
    }
    if (total_leading_whitespace_count > 0)
    {
        for (int shift_operation_buffer_index = 0;
             shift_operation_buffer_index <= updated_input_string_length - total_leading_whitespace_count;
             shift_operation_buffer_index++)
        {
            input_string_character_buffer[shift_operation_buffer_index] = input_string_character_buffer[shift_operation_buffer_index + total_leading_whitespace_count];
        }
    }
}

int Trim2WhiteSpaceString()
{
    char demonstration_sample_text_buffer[256] = "   \t  hello universe runnable c code    \n  ";
    printf("--- Full Trim Execution ---\n");
    printf("Original String : '%s'\n", demonstration_sample_text_buffer);
    trim_leading_and_trailing_whitespace_characters_from_string(demonstration_sample_text_buffer);
    printf("Modified String : '%s'\n", demonstration_sample_text_buffer);
    printf("---------------------------\n");
    return 0;
}
void remove_all_extra_blank_spaces_from_string(char *input_string_character_buffer)
{
    // Safety check
    if (input_string_character_buffer == NULL || input_string_character_buffer[0] == '\0')
    {
        return;
    }

    int total_input_string_length = strlen(input_string_character_buffer);
    int read_pointer_buffer_index = 0;
    int write_pointer_buffer_index = 0;
    int is_currently_tracking_a_whitespace_sequence = 0;

    // 1: Skip any leading whitespace characters completely
    while (input_string_character_buffer[read_pointer_buffer_index] != '\0' && isspace((unsigned char)input_string_character_buffer[read_pointer_buffer_index]))
    {
        read_pointer_buffer_index++;
    }

    // 2: Traverse the string to compress internal multi-spaces
    while (input_string_character_buffer[read_pointer_buffer_index] != '\0')
    {
        char current_evaluation_character = input_string_character_buffer[read_pointer_buffer_index];
        if (isspace((unsigned char)current_evaluation_character))
        {
            if (!is_currently_tracking_a_whitespace_sequence)
            {
                input_string_character_buffer[write_pointer_buffer_index] = ' ';
                write_pointer_buffer_index++;
                is_currently_tracking_a_whitespace_sequence = 1;
            }
        }
        else
        {
            input_string_character_buffer[write_pointer_buffer_index] = current_evaluation_character;
            write_pointer_buffer_index++;
            is_currently_tracking_a_whitespace_sequence = 0;
        }
        read_pointer_buffer_index++;
    }

    // 3: Clean up any single trailing space left behind by the loop logic
    if (write_pointer_buffer_index > 0 && input_string_character_buffer[write_pointer_buffer_index - 1] == ' ')
    {
        write_pointer_buffer_index--;
    }
    input_string_character_buffer[write_pointer_buffer_index] = '\0';
}

int RemoveBlankSpaces()
{
    char demonstration_sample_text_buffer[256] = "   hello      universe    runnable    c    code      ";
    printf("--- Multi-Space Compaction Execution ---\n");
    printf("Original String : '%s'\n", demonstration_sample_text_buffer);
    remove_all_extra_blank_spaces_from_string(demonstration_sample_text_buffer);
    printf("Modified String : '%s'\n", demonstration_sample_text_buffer);
    printf("----------------------------------------\n");
    return 0;
}
double calculate_cube_of_given_floating_point_number(double base_input_number_to_cube)
{
    double calculated_cube_result_value = base_input_number_to_cube * base_input_number_to_cube * base_input_number_to_cube;
    return calculated_cube_result_value;
}

int RemoveBlankSpacesFromGivenString()
{
    double first_sample_input_number = 5.0;
    double second_sample_input_number = -3.0;
    double third_sample_input_number = 2.5;
    double first_calculated_output_result = calculate_cube_of_given_floating_point_number(first_sample_input_number);
    double second_calculated_output_result = calculate_cube_of_given_floating_point_number(second_sample_input_number);
    double third_calculated_output_result = calculate_cube_of_given_floating_point_number(third_sample_input_number);
    printf("--- Cube Calculation Execution --- \n");
    printf("The cube of %.2f is: %.2f\n", first_sample_input_number, first_calculated_output_result);
    printf("The cube of %.2f is: %.2f\n", second_sample_input_number, second_calculated_output_result);
    printf("The cube of %.2f is: %.2f\n", third_sample_input_number, third_calculated_output_result);
    printf("----------------------------------\n");
    return 0;
}

// Find diameter, circumference and area of a circle using functions.
#define MATHEMATICAL_CONSTANT_PI 3.14159265358979323846
double calculate_diameter_of_circle_from_radius(double circle_radius_input_value)
{
    double calculated_diameter_result = 2.0 * circle_radius_input_value;
    return calculated_diameter_result;
}
double calculate_circumference_of_circle_from_radius(double circle_radius_input_value)
{
    double calculated_circumference_result = 2.0 * MATHEMATICAL_CONSTANT_PI * circle_radius_input_value;
    return calculated_circumference_result;
}
double calculate_area_of_circle_from_radius(double circle_radius_input_value)
{
    double calculated_area_result = MATHEMATICAL_CONSTANT_PI * circle_radius_input_value * circle_radius_input_value;
    return calculated_area_result;
}
int CubeNumberUsingFunction()
{
    double sample_circle_radius_dimension = 7.5;
    double final_calculated_circle_diameter = calculate_diameter_of_circle_from_radius(sample_circle_radius_dimension);
    double final_calculated_circle_circumference = calculate_circumference_of_circle_from_radius(sample_circle_radius_dimension);
    double final_calculated_circle_area = calculate_area_of_circle_from_radius(sample_circle_radius_dimension);
    printf("--- Circle Geometry Calculation Execution ---\n");
    printf("Input Radius   : %.4f units\n", sample_circle_radius_dimension);
    printf("---------------------------------------------\n");
    printf("Calculated Diameter      : %.4f units\n", final_calculated_circle_diameter);
    printf("Calculated Circumference : %.4f units\n", final_calculated_circle_circumference);
    printf("Calculated Surface Area  : %.4f square units\n", final_calculated_circle_area);
    printf("---------------------------------------------\n");

    return 0;
}

// Check whether a number is even or odd using functions.
int check_if_given_integer_is_even(int integer_number_to_be_evaluated)
{
    if (integer_number_to_be_evaluated % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int CheckEvenOrOdd()
{
    int first_sample_input_integer = 42;
    int second_sample_input_integer = -17;
    int third_sample_input_integer = 0;

    printf("--- Even or Odd Verification Execution ---\\n");
    if (check_if_given_integer_is_even(first_sample_input_integer))
    {
        printf("The number %d is EVEN.\\n", first_sample_input_integer);
    }
    else
    {
        printf("The number %d is ODD.\\n", first_sample_input_integer);
    }
    if (check_if_given_integer_is_even(second_sample_input_integer))
    {
        printf("The number %d is EVEN.\\n", second_sample_input_integer);
    }
    else
    {
        printf("The number %d is ODD.\\n", second_sample_input_integer);
    }
    if (check_if_given_integer_is_even(third_sample_input_integer))
    {
        printf("The number %d is EVEN.\\n", third_sample_input_integer);
    }
    else
    {
        printf("The number %d is ODD.\\n", third_sample_input_integer);
    }

    printf("-----------------------------------------\\n");

    return 0;
}

int main()
{
    CubeNumberUsingFunction();
    RemoveBlankSpaces();
    RemoveBlankSpacesFromGivenString();
    Remove_last_occurrence_of_word_in_a_given_string();
    Remove_All_occurrence_of_word_in_a_given_string();
    TrimWhiteSpaceString();
    Trim2WhiteSpaceString();
    CheckEvenOrOdd();
    return 0;
}
