#define  _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 256
#define MAX_WORD_LENGTH 16
#define PUNCTUATION " ,;:-.!?"

#define EXIT_HEAP_ALLOCATION_FAILED NULL
#define EXIT_MAX_STRING_LENGTH_EXCEEDED 1
#define EXIT_MAX_WORD_LENGTH_EXCEEDED 1
#define EXIT_NO_WORDS 1
#define EXIT_NO_RESULT_STR 1

char **my_split(char *str, const char *delim, int *num_tokens) 
{
    char *token;
    char *saveptr;
    char *str_copy = strdup(str);
    if (str_copy == NULL)
    {
        free(str_copy);
        return EXIT_HEAP_ALLOCATION_FAILED;
    }
    char **tokens = NULL;
    
    *num_tokens = 0;
    token = strtok_r(str_copy, delim, &saveptr);
    
    while (token != NULL) 
    {
        tokens = realloc(tokens, (*num_tokens + 1) * sizeof(char*));
        tokens[*num_tokens] = strdup(token);
        if (tokens[*num_tokens] == NULL)
            return EXIT_HEAP_ALLOCATION_FAILED;
        (*num_tokens)++;
        token = strtok_r(NULL, delim, &saveptr);
    }
    
    free(str_copy);
    return tokens;
}

int read_line(char *s, int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n)
            s[i++] = ch;
        else
            return -1;
    s[i] = '\0';
    return i;
}

int check_word_buffer_overflow(char **str_arr, int str_arr_len)
{
    for (int i = 0; i < str_arr_len; ++i)
        if (strlen(str_arr[i]) > MAX_WORD_LENGTH)
            return 1;
    return 0;
}

void free_str_array(char **str_arr, int str_arr_len) 
{
    for (int i = 0; i < str_arr_len; ++i)
        free(str_arr[i]);
    free(str_arr);
}

void form_reversed_str_arr(char **str_arr, int str_arr_len, char *res)
{
    for (int i = str_arr_len - 1; i >= 0; --i)
    {
        strcat(res, str_arr[i]);
        if (i != 0)
            strcat(res, " ");
    }
    return;
}

void delete_first_letter_from_str(char *str, int str_len)
{
    for (int i = 1; i < str_len; i++) 
    {
        if (str[i] == str[0]) 
        {
            for (int j = i; j < str_len; j++)
                str[j] = str[j + 1];
            str_len--;
            i--;
        }
    }
    return;
}

void delete_element(char **arr, int *size, char *element)
{
    for (int i = 0; i < *size; i++) 
    {
        if (strcmp(arr[i], element) == 0) 
        {
            free(arr[i]);
            for (int j = i; j < *size - 1; j++)
                arr[j] = arr[j + 1];
            (*size)--;
            i--;
        }
    }
}

void print_string_array(char **arr, int size) 
{
    for (int i = 0; i < size; i++)
        printf("%s\n", arr[i]);
}

int main(void) 
{
    char str[MAX_STRING_LENGTH];
    int str_len = read_line(str, MAX_STRING_LENGTH);
    if (str_len == -1)
        return EXIT_MAX_STRING_LENGTH_EXCEEDED;
    
    int str_splited_len;
    char **str_splited = my_split(str, PUNCTUATION, &str_splited_len);

    if (str_splited_len == 0)
    {
        free_str_array(str_splited, str_splited_len);
        return EXIT_NO_WORDS;
    }

    if (check_word_buffer_overflow(str_splited, str_splited_len))
    {
        free_str_array(str_splited, str_splited_len);
        return EXIT_MAX_WORD_LENGTH_EXCEEDED;
    }
    
    //int old_str_splited_len = str_splited_len;
    delete_element(str_splited, &str_splited_len, str_splited[str_splited_len - 1]);

    for (int i = 0; i < str_splited_len; ++i)
        delete_first_letter_from_str(str_splited[i], strlen(str_splited[i]));

    char res[MAX_STRING_LENGTH] = "";
    form_reversed_str_arr(str_splited, str_splited_len, res);

    if (strlen(res) > 0)
        printf("Result: %s\n", res);
    else
    {
        free_str_array(str_splited, str_splited_len);
        return EXIT_NO_RESULT_STR;
    }
    
    free_str_array(str_splited, str_splited_len);
    return 0;
}