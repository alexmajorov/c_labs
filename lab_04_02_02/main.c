#define  _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 256
#define MAX_WORD_LENGTH 16
#define PUNCTUATION " ,;:-.!?"

// ERRORS
#define EXIT_MAX_STRING_LENGTH_EXCEEDED 1
#define EXIT_MAX_WORD_LENGTH_EXCEEDED 2
#define EXIT_HEAP_ALLOCATION_FAILED NULL
#define EXIT_NO_WORDS 3

char *my_strdup(const char *str) 
{
    size_t len = strlen(str) + 1;
    char *new_str = (char *) malloc(len);
    if (new_str == NULL)
        return NULL;
    
    memcpy(new_str, str, len);
    return new_str;
}

char *my_strchr(const char *str, int c) 
{
    char *ptr = (char*) str;
    while (*ptr != '\0') 
    {
        if (*ptr == (char) c)
            return ptr;
        ptr++;
    }
    if (*ptr == (char) c)
        return ptr;
    return NULL;
}


char *my_strtok_r(char *str, const char *delim, char **saveptr) 
{
    char *token;
    
    if (str != NULL)
        *saveptr = str;
    
    token = *saveptr;
    
    if (token == NULL)
        return NULL;
    
    while (*token != '\0' && my_strchr(delim, *token) != NULL)
        token++;
    
    if (*token == '\0') 
    {
        *saveptr = NULL;
        return NULL;
    }
    
    char *end = token + 1;
    while (*end != '\0' && my_strchr(delim, *end) == NULL)
        end++;

    
    if (*end == '\0')
        *saveptr = NULL;
    else 
    {
        *end = '\0';
        *saveptr = end + 1;
    }
    
    return token;
}

char **my_split(char *str, const char *delim, int *num_tokens) 
{
    char *token;
    char *saveptr;
    char *str_copy = my_strdup(str);
    if (str_copy == NULL)
        return EXIT_HEAP_ALLOCATION_FAILED;
    char **tokens = NULL;
    
    *num_tokens = 0;
    token = my_strtok_r(str_copy, delim, &saveptr);
    
    while (token != NULL) 
    {
        tokens = realloc(tokens, (*num_tokens + 1) * sizeof(char*));
        tokens[*num_tokens] = my_strdup(token);
        if (tokens[*num_tokens] == NULL)
            return EXIT_HEAP_ALLOCATION_FAILED;
        (*num_tokens)++;
        token = my_strtok_r(NULL, delim, &saveptr);
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


void print_string_array(char **arr, int size) 
{
    for (int i = 0; i < size; i++)
        printf("%s\n", arr[i]);
}


int my_strcmp(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

int str_in_str_arr(char *str, char **str_arr, int str_arr_len)
{
    for (int i = 0; i < str_arr_len; ++i)
        if (my_strcmp(str, str_arr[i]) == 0)
            return 1;
    return 0;
}

void print_str_arrs_comparision(char **str1, int str1_len, char **str2, int str2_len)
{
    for (int i = 0; i < str1_len; ++i)
    {
        int skip = 0;
        for (int j = 0; j < i; ++j)
            if (my_strcmp(str1[i], str1[j]) == 0)
            {
                skip = 1;
                break;
            }

        if (!skip)
        {
            if (str_in_str_arr(str1[i], str2, str2_len))
                printf("%s yes\n", str1[i]);
            else
                printf("%s no\n", str1[i]);
        }
    }
    return;
}

size_t my_strlen(const char *str) 
{
    const char *s;
    for (s = str; *s; ++s);
    return (s - str);
}

int check_word_buffer_overflow(char **str_arr, int str_arr_len)
{
    for (int i = 0; i < str_arr_len; ++i)
        if (my_strlen(str_arr[i]) > MAX_WORD_LENGTH)
            return 1;
    return 0;
}

void free_str_array(char **str_arr, int str_arr_len) 
{
    int i;
    for (i = 0; i < str_arr_len; ++i) 
        free(str_arr[i]);
    free(str_arr);
}

int main(void) 
{
    //  TODO: max word len, ommiting reoccuring words in str1
    char str1[MAX_STRING_LENGTH];
    int str1_len = read_line(str1, MAX_STRING_LENGTH);
    if (str1_len == -1)
        return EXIT_MAX_STRING_LENGTH_EXCEEDED;
    
    char str2[MAX_STRING_LENGTH];
    int str2_len = read_line(str2, MAX_STRING_LENGTH);
    if (str2_len == -1)
        return EXIT_MAX_STRING_LENGTH_EXCEEDED;

    int str1_splited_len;
    char **str1_splited = my_split(str1, PUNCTUATION, &str1_splited_len);

    int str2_splited_len;
    char **str2_splited = my_split(str2, PUNCTUATION, &str2_splited_len);


    //print_string_array(str1_splited, str1_splited_len);
    //print_string_array(str2_splited, str2_splited_len);

    if (str1_splited_len == 0 || str2_splited_len == 0)
    {
        free_str_array(str1_splited, str1_splited_len);
        free_str_array(str2_splited, str2_splited_len);
        return EXIT_NO_WORDS;
    }


    if (check_word_buffer_overflow(str1_splited, str1_splited_len) || check_word_buffer_overflow(str2_splited, str2_splited_len))
    {
        free_str_array(str1_splited, str1_splited_len);
        free_str_array(str2_splited, str2_splited_len);
        return EXIT_MAX_WORD_LENGTH_EXCEEDED;
    }

    printf("Result: \n");
    print_str_arrs_comparision(str1_splited, str1_splited_len, str2_splited, str2_splited_len);
    free_str_array(str1_splited, str1_splited_len);
    free_str_array(str2_splited, str2_splited_len);
    return 0;
}
