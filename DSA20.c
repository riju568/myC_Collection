#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#define F_OK 0
#define access _access
#else
#include <unistd.h>
#include <dirent.h>
#endif

#define MAX_LINE 1024
#define MAX_WORD 100

typedef struct WordNode
{
    char word[MAX_WORD];
    int count;
    struct WordNode *next;
} WordNode;

// Find the occurrence of a word
void find_word_occurrence(const char *filepath, const char *target_word)
{
    FILE *file = fopen(filepath, "r");
    if (!file)
    {
        perror("[1] Error opening file");
        return;
    }

    char line[MAX_LINE];
    int line_num = 1;
    printf("[1] '%s' found on lines: ", target_word);

    int found_any = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, target_word))
        {
            printf("%d ", line_num);
            found_any = 1;
        }
        line_num++;
    }
    if (!found_any)
        printf("None");
    printf("\n");
    fclose(file);
}

// Count occurrences of a specific word
void count_word_occurrence(const char *filepath, const char *target_word)
{
    FILE *file = fopen(filepath, "r");
    if (!file)
        return;

    char line[MAX_LINE];
    int count = 0;
    size_t word_len = strlen(target_word);

    while (fgets(line, sizeof(line), file))
    {
        char *pos = line;
        while ((pos = strstr(pos, target_word)) != NULL)
        {
            count++;
            pos += word_len;
        }
    }
    printf("[2] The word '%s' appears %d times.\n", target_word, count);
    fclose(file);
}

// Count occurrences of all words (Frequency)
void count_all_words(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    if (!file)
        return;

    WordNode *head = NULL;
    char line[MAX_LINE];
    int unique_words = 0;

    while (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, " \t\n\r.,!?;:");
        while (token != NULL)
        {
            // Convert to lowercase for uniform counting
            char lower_word[MAX_WORD];
            strncpy(lower_word, token, MAX_WORD - 1);
            lower_word[MAX_WORD - 1] = '\0';
            for (int i = 0; lower_word[i]; i++)
            {
                lower_word[i] = tolower((unsigned char)lower_word[i]);
            }
            WordNode *current = head;
            int found = 0;
            while (current != NULL)
            {
                if (strcmp(current->word, lower_word) == 0)
                {
                    current->count++;
                    found = 1;
                    break;
                }
                current = current->next;
            }

            // Add new word if not found
            if (!found)
            {
                WordNode *new_node = (WordNode *)malloc(sizeof(WordNode));
                if (new_node)
                {
                    strncpy(new_node->word, lower_word, MAX_WORD - 1);
                    new_node->word[MAX_WORD - 1] = '\0';
                    new_node->count = 1;
                    new_node->next = head;
                    head = new_node;
                    unique_words++;
                }
            }
            token = strtok(NULL, " \t\n\r.,!?;:");
        }
    }
    printf("[3] Total unique words found: %d\n", unique_words);
    WordNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    fclose(file);
}

//  Find and replace a word
void find_and_replace_word(const char *filepath, const char *old_word, const char *new_word)
{
    FILE *file = fopen(filepath, "r");
    FILE *temp_file = fopen("temp_replace.txt", "w");
    if (!file || !temp_file)
        return;

    char line[MAX_LINE];
    size_t old_len = strlen(old_word);

    while (fgets(line, sizeof(line), file))
    {
        char *pos = line;
        char *match;
        // Read and replace dynamically on the line buffer
        while ((match = strstr(pos, old_word)) != NULL)
        {
            *match = '\0'; // Split the string
            fprintf(temp_file, "%s%s", pos, new_word);
            pos = match + old_len;
        }
        fprintf(temp_file, "%s", pos);
    }

    fclose(file);
    fclose(temp_file);
    remove(filepath);
    rename("temp_replace.txt", filepath);
    printf("[4] Replaced '%s' with '%s'.\n", old_word, new_word);
}

// Replace a specific line
void replace_specific_line(const char *filepath, int target_line, const char *new_text)
{
    FILE *file = fopen(filepath, "r");
    FILE *temp_file = fopen("temp_line_replace.txt", "w");
    if (!file || !temp_file)
        return;

    char line[MAX_LINE];
    int current_line = 1;

    while (fgets(line, sizeof(line), file))
    {
        if (current_line == target_line)
        {
            fprintf(temp_file, "%s\n", new_text);
        }
        else
        {
            fprintf(temp_file, "%s", line);
        }
        current_line++;
    }

    fclose(file);
    fclose(temp_file);
    remove(filepath);
    rename("temp_line_replace.txt", filepath);
    printf("[5] Replaced line %d.\n", target_line);
}

// Print source code of the same program
void print_source_code()
{
    printf("[6] Printing source code header:\n");
    FILE *file = fopen(__FILE__, "r");
    if (!file)
        return;

    char line[MAX_LINE];
    int lines_to_print = 10;

    while (fgets(line, sizeof(line), file) && lines_to_print > 0)
    {
        printf("%s", line);
        lines_to_print--;
    }
    printf("... (truncated)\n");
    fclose(file);
}

// Convert uppercase to lowercase and vice versa
void toggle_case_in_file(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    FILE *temp_file = fopen("temp_case.txt", "w");
    if (!file || !temp_file)
        return;

    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (islower(ch))
        {
            fputc(toupper(ch), temp_file);
        }
        else if (isupper(ch))
        {
            fputc(tolower(ch), temp_file);
        }
        else
        {
            fputc(ch, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);
    remove(filepath);
    rename("temp_case.txt", filepath);
    printf("[7] Toggled character casing in %s.\n", filepath);
}

// Find properties using stat() function
void find_file_properties(const char *filepath)
{
    struct stat file_stats;
    if (stat(filepath, &file_stats) == 0)
    {
        printf("[8] Properties for %s:\n", filepath);
        printf("    - Size: %ld bytes\n", (long)file_stats.st_size);
        printf("    - Last modified time: %ld\n", (long)file_stats.st_mtime);
    }
    else
    {
        perror("[8] stat() error");
    }
}

// Check if file or directory exists
void check_existence(const char *path)
{
    if (access(path, F_OK) == 0)
    {
        printf("[9] Path '%s' exists: True\n", path);
    }
    else
    {
        printf("[9] Path '%s' exists: False\n", path);
    }
}

// Rename a file using rename() function
void rename_target_file(const char *old_name, const char *new_name)
{
    if (rename(old_name, new_name) == 0)
    {
        printf("[10] Renamed '%s' to '%s'.\n", old_name, new_name);
    }
    else
    {
        perror("[10] rename() error");
    }
}

// List all files and sub-directories recursively
void list_files_recursively(const char *base_path, int indent_level)
{
    if (indent_level == 0)
    {
        printf("[11] Listing contents of directory: %s\n", base_path);
    }

#ifdef _WIN32

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    char search_path[1024];
    snprintf(search_path, sizeof(search_path), "%s\\*", base_path);
    hFind = FindFirstFile(search_path, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE)
        return;

    do
    {
        if (strcmp(findFileData.cFileName, ".") == 0 || strcmp(findFileData.cFileName, "..") == 0)
        {
            continue;
        }

        for (int i = 0; i < indent_level; i++)
            printf("    ");

        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            printf("[D] %s\\\n", findFileData.cFileName);
            char next_path[1024];
            snprintf(next_path, sizeof(next_path), "%s\\%s", base_path, findFileData.cFileName);
            list_files_recursively(next_path, indent_level + 1);
        }
        else
        {
            printf("[F] %s\n", findFileData.cFileName);
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);

#else
    /* --- POSIX IMPLEMENTATION --- */
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(base_path)))
        return;

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        for (int i = 0; i < indent_level; i++)
            printf("    ");

        if (entry->d_type == DT_DIR)
        {
            printf("[D] %s/\n", entry->d_name);
            char next_path[1024];
            snprintf(next_path, sizeof(next_path), "%s/%s", base_path, entry->d_name);
            list_files_recursively(next_path, indent_level + 1);
        }
        else
        {
            printf("[F] %s\n", entry->d_name);
        }
    }
    closedir(dir);
#endif
}

// HELPER: Setup a dummy environment
void setup_dummy_environment(const char *filepath)
{
    FILE *file = fopen(filepath, "w");
    if (file)
    {
        fprintf(file, "Hello world, welcome to the test.\n");
        fprintf(file, "This file is used to test word counts.\n");
        fprintf(file, "Will it find the word test?\n");
        fprintf(file, "Let's check line replacements.\n");
        fclose(file);
    }
}


int main()
{
    const char *test_file = "sample_test_c_file.txt";
    const char *renamed_file = "renamed_test_c_file.txt";
    const char *test_directory = ".";

    printf("--- Starting File Operations (C Implementation) ---\n\n");

    setup_dummy_environment(test_file);
    find_word_occurrence(test_file, "test");
    count_word_occurrence(test_file, "test");
    count_all_words(test_file);
    find_and_replace_word(test_file, "Hello", "Greetings");
    replace_specific_line(test_file, 4, "This is the newly replaced line 4.");
    print_source_code();
    toggle_case_in_file(test_file);
    find_file_properties(test_file);
    check_existence(test_file);
    rename_target_file(test_file, renamed_file);
    list_files_recursively(test_directory, 0);
    remove(renamed_file);
    printf("\n--- Operations Completed ---\n");

    return 0;
}
