#include <stdlib.h>
#include <stdio.h>

#define NMAX 1024
#define N 10
#define EXIT_ARRAY_INPUT_SUCCESS 0
#define EXIT_ARRAY_OVERFLOW_ERROR 100

typedef int array_t[NMAX];

int array_t_infinite_input(array_t array, size_t *array_len)
{
    *array_len = 0;
    printf("Введите элемент массива: ");
    while (scanf("%d", &array[*array_len]))
    {
        (*array_len)++;
        if (*array_len > N)
        {
            (*array_len)--;
            return EXIT_ARRAY_OVERFLOW_ERROR;
        }
        printf("Введите элемент массива: ");
    }
    return EXIT_ARRAY_INPUT_SUCCESS;
}

void array_t_output(array_t arr, size_t array_len)
{
    for (size_t i = 0; i < array_len; ++i)
        printf("Элемент массива: %d\n", arr[i]);
    return;
}

void insertion_sort(array_t array, size_t array_len)
{
    int j = 0;
    for (size_t i = 1; i < array_len; ++i)
    {
        int current_element = array[i];
        j = i - 1;
        while ((j >= 0) && (current_element < array[j]))
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = current_element;
    }
    return;
}


int main(void)
{
    array_t array;
    size_t array_len = 0;
    int main_exit_key = EXIT_SUCCESS;
    if (array_t_infinite_input(array, &array_len) == EXIT_ARRAY_OVERFLOW_ERROR)
        main_exit_key = EXIT_ARRAY_OVERFLOW_ERROR;
    
    if (array_len == 0)
        return EXIT_FAILURE;
    
    insertion_sort(array, array_len);
    array_t_output(array, array_len);
    return main_exit_key;
}

