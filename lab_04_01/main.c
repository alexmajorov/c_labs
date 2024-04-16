#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_string.h"

#define NUMBER_OF_TESTS 10
#define STR_LEN 80

int main(void)
{
    int failed = 0;
    const char in_s1[NUMBER_OF_TESTS][STR_LEN] = { "to be, or not to be, that ", \
        "is the question:", \
        "whether", \
        "'tis nobler\0in the mind to suffer", \
        " ", \
        "the slings and\narrows of outrageous fortune,", \
        " or to take arms against", \
        "a sea of troubles and by", \
        "opposing end them.", \
        "" };
    const char in_s2[NUMBER_OF_TESTS][STR_LEN] = { "and", \
        "the", \
        "a sea", \
        "w", \
        "opposing end them.", \
        " nobler in the ", \
        "ws of outr", \
        "iwudgvliwaevb", \
        " ", 
        "" };
    int in_c[NUMBER_OF_TESTS] = { '\0', '\n', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    
    for (size_t i = 0; i < NUMBER_OF_TESTS; i++)
        for (size_t j = 0; j < NUMBER_OF_TESTS; j++)
            if (my_strpbrk(in_s1[i], in_s2[j]) != strpbrk(in_s1[i], in_s2[j]))
                failed++;
 
    for (size_t i = 0; i < NUMBER_OF_TESTS; i++)
        for (size_t j = 0; j < NUMBER_OF_TESTS; j++)
            if (my_strspn(in_s1[i], in_s2[j]) != strspn(in_s1[i], in_s2[j]))
                failed++;
            
    for (size_t i = 0; i < NUMBER_OF_TESTS; i++)
        for (size_t j = 0; j < NUMBER_OF_TESTS; j++)
            if (my_strcspn(in_s1[i], in_s2[j]) != strcspn(in_s1[i], in_s2[j]))
                failed++;
            
    for (size_t i = 0; i < NUMBER_OF_TESTS; i++)
        for (size_t j = 0; j < NUMBER_OF_TESTS; j++)
            if (my_strcspn(in_s1[i], in_s2[j]) != strcspn(in_s1[i], in_s2[j]))
                failed++;
            
    for (size_t i = 0; i < NUMBER_OF_TESTS; i++)
        for (size_t j = 0; j < NUMBER_OF_TESTS; j++)
            if (my_strchr(in_s1[i], in_c[j]) != strchr(in_s1[i], in_c[j]))
                failed++;
            
    for (size_t i = 0; i < NUMBER_OF_TESTS; i++)
        for (size_t j = 0; j < NUMBER_OF_TESTS; j++)
            if (my_strrchr(in_s1[i], in_c[j]) != strrchr(in_s1[i], in_c[j]))
                failed++;
            
    printf("Result: %d\n", failed);
    
    return EXIT_SUCCESS;
}
