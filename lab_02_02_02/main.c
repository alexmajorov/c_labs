#include <stdlib.h>
#include <stdio.h>

#define NMAX 1024
#define N 10
#define EXIT_ARRAY_INPUT_FAILURE 1
#define EXIT_ARRAY_INPUT_SUCCESS 0
typedef int array_t[NMAX];

int array_t_input(array_t array, size_t array_len)
{
    for (size_t i = 0; i < array_len; ++i)
    {
        printf("Введите элемент массива: ");
        if (scanf("%d", &array[i]) != 1)
            return EXIT_ARRAY_INPUT_FAILURE;
    }
    return EXIT_ARRAY_INPUT_SUCCESS;
}

void array_t_output(array_t arr, size_t array_len)
{
    for (size_t i = 0; i < array_len; ++i)
        printf("Элемент массива: %d\n", arr[i]);
    return;
}

int first_digit(int n)
{
    while (n >= 10 || n <= -10)
        n /= 10;
    return abs(n);
}
 
int last_digit(int n)
{
    return abs(n % 10);
}
    
void create_my_array(array_t old_array, size_t old_array_len, array_t new_array, size_t *new_array_len)
{
    *new_array_len = 0;
    for (size_t i = 0; i < old_array_len; ++i)
        if (last_digit(old_array[i]) == first_digit(old_array[i]))
        {
            new_array[*new_array_len] = old_array[i];
            (*new_array_len)++;
        }
    return;
}


int main(void)
{
    array_t old_array, new_array;
    size_t old_array_len, new_array_len;
    
    printf("Введите длину массива: ");
    if (scanf("%zu", &old_array_len) != 1 || old_array_len > N || old_array_len > NMAX || old_array_len < 1)
        return EXIT_FAILURE;
    
    if (array_t_input(old_array, old_array_len))
        return EXIT_FAILURE;
    
    create_my_array(old_array, old_array_len, new_array, &new_array_len);
    
    if (new_array_len)
        array_t_output(new_array, new_array_len);
    else
    {
        printf("Элементов, начинающихся и заканчивающихся на одну цифру, нет.\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
