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

int get_sum_of_negatives(array_t array, size_t array_len, int *number_of_negatives)
{
    int sum_of_negatives = 0;
    *number_of_negatives = 0;
    for (size_t i = 0; i < array_len; ++i)
        if (array[i] < 0)
        {
            sum_of_negatives += array[i];
            (*number_of_negatives)++;
        }
    return sum_of_negatives;
}

int main(void)
{
    array_t array;
    size_t array_len;
    int sum_of_negatives = 0;
    int number_of_negatives = 0;
    double mean_of_negatives;
    
    printf("Введите длину массива: ");
    if (scanf("%zu", &array_len) != 1 || array_len > N || array_len > NMAX)
        return EXIT_FAILURE;
    
    if (array_t_input(array, array_len) == EXIT_ARRAY_INPUT_FAILURE)
        return EXIT_FAILURE;
    sum_of_negatives = get_sum_of_negatives(array, array_len, &number_of_negatives);
    
    if (number_of_negatives != 0)
    {
        mean_of_negatives = sum_of_negatives / (double)number_of_negatives;
        printf("Среднее арифметическое отрицательных элементов массива: %0.6lf\n", mean_of_negatives);
    }
    else
    {
        printf("Отрицательных элементов в массиве нет.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
