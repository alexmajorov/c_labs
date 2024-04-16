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

int check_squareness(int n)
{
    int temp = 0;
    for (int i = 1; i <= n; i += 2)
    {
        if (n == temp)
            return 1;
        temp += i;
    }
    return (n == temp);
}

void delete_squares(array_t array, size_t *array_len)
{
    size_t new_array_len = 0;
    for (size_t i = 0; i < *array_len; ++i)
        if (!check_squareness(array[i]))
        {
            array[new_array_len] = array[i];
            new_array_len++;
        }
    *array_len = new_array_len;
}

int main(void)
{
    array_t array;
    size_t array_len;
    
    printf("Введите длину массива: ");
    if (scanf("%zu", &array_len) != 1 || array_len > N || array_len > NMAX || array_len < 1)
        return EXIT_FAILURE;
    
    if (array_t_input(array, array_len))
        return EXIT_FAILURE;
    
    delete_squares(array, &array_len);
    if (array_len)
        array_t_output(array, array_len);
    else
    {
        printf("Массив пуст.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
