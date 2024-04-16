#include <stdlib.h>
#include "my_string.h"

char *my_strpbrk(const char *s1, const char *s2)
{
    size_t s1_i = 0, s2_i = 0;
    while (s1[s1_i])
    {
        while (s2[s2_i])
        {
            if (s1[s1_i] == s2[s2_i])
                return (char *) &s1[s1_i];
            s2_i++;
        }
        s1_i++;
        s2_i = 0;
    }
    return NULL;
}

size_t my_strspn(const char *s1, const char *s2)
{
    const char *s = s1;
    const char *c;

    while (*s1)
    {
        for (c = s2; *c; ++c)
            if (*s1 == *c)
                break;
        if (*c == '\0')
            break;
        s1++;
    }
    return s1 - s;
}

size_t my_strcspn(const char *s1, const char *s2)
{
    const char *p = s1, *spanp;
    char c, sc;

    while (1) 
    {
        c = *p++;
        spanp = s2;
        do 
        {
            sc = *spanp++;
            if (sc == c)
                return (p - 1 - s1);
        } 
        while (sc != 0);
    }
}

char *my_strchr(const char *s, int c)
{
    do 
    {
        if (*s == c)
            return (char *)s;
    }
    while (*s++);
    return 0;
}

char *my_strrchr(const char *s, int c)
{
    char *rc = 0;
    do 
    {
        if (*s == c)
            rc = (char*) s;
    }
    while (*s++);
    return rc;
} 
