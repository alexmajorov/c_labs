#define  _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 256
#define MAX_WORD_LENGTH 16
#define PUNCTUATION " \t\n\v\f\r"

#define EXIT_HEAP_ALLOCATION_FAILED NULL
#define EXIT_MAX_STRING_LENGTH_EXCEEDED 1
#define EXIT_INVALID_DATE 1

void trim(char *str) 
{
    while (isspace(*str))
        str++;
    
    if (*str == '\0')
        return;
    
    char *end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) 
        end--;

    *(end + 1) = '\0';
}

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

int is_day_valid(char *day)
{
    int num = atoi(day);
    if (num > 0 && num < 32) 
        return 1;
    else
        return 0;
}

int is_month_valid(char *month)
{
    if (strcmp(month, "january") == 0 || strcmp(month, "february") == 0 ||
        strcmp(month, "march") == 0 || strcmp(month, "april") == 0 ||
        strcmp(month, "may") == 0 || strcmp(month, "june") == 0 ||
        strcmp(month, "july") == 0 || strcmp(month, "august") == 0 ||
        strcmp(month, "september") == 0 || strcmp(month, "october") == 0 ||
        strcmp(month, "november") == 0 || strcmp(month, "december") == 0)
        return 1;
    else
        return 0;
}

int is_year_valid(char *year)
{
    int num = atoi(year);   
    if (strlen(year) == 4 && num > 0 && num < 10000) 
        return 1;
    else  
        return 0;
}

void lower_string(char *s)
{
    while (*s != '\0') 
    {
        *s = tolower(*s);
        s++;
    }
    return;
}

int is_date_valid(char *day, char *month, char *year)
{
    lower_string(month);
    if (is_day_valid(day) && is_month_valid(month) && is_year_valid(year))
    {
        if ((strcmp(month, "april") == 0 || strcmp(month, "june") == 0 || strcmp(month, "september") == 0 || strcmp(month, "november") == 0) && atoi(day) > 30)
            return 0;

        if (strcmp(month, "february") == 0)
        {
            if ((atoi(year) % 400 == 0 || (atoi(year) % 100 != 0 && atoi(year) % 4 == 0)) && atoi(day) > 29)
                return 0;
            if (!(atoi(year) % 400 == 0 || (atoi(year) % 100 != 0 && atoi(year) % 4 == 0)) && atoi(day) > 28)
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

void free_str_array(char **str_arr, int str_arr_len) 
{
    for (int i = 0; i < str_arr_len; ++i)
        free(str_arr[i]);
    free(str_arr);
}

int main(void) 
{
    char str[MAX_STRING_LENGTH];
    int str_len = read_line(str, MAX_STRING_LENGTH);
    if (str_len == -1)
        return EXIT_MAX_STRING_LENGTH_EXCEEDED;
    
    trim(str);
    int str_splited_len;
    char **str_splited = my_split(str, PUNCTUATION, &str_splited_len);

    if (str_splited_len == 3)
    {
        if (is_date_valid(str_splited[0], str_splited[1], str_splited[2]))
            printf("YES\n");
        else
            printf("NO\n");
    }
    else
        printf("NO\n");
        
    free_str_array(str_splited, str_splited_len);
    return 0;
}
