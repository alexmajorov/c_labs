#include <stdlib.h>
#include <stdio.h>

#define NMAX 256
#define N 10
#define EXIT_MATRIX_INPUT_FAILURE 1
#define EXIT_MATRIX_INPUT_SUCCESS 0
#define EXIT_ARRAY_CREATION_SUCCESS 0
#define EXIT_ARRAY_CREATION_FAILURE 1

typedef int matrix_t[NMAX][NMAX];
typedef int array_t[NMAX];

int sign(int n)
{
    return (n > 0) - (n < 0);
}

int matrix_t_input(matrix_t matrix, size_t matrix_rows, size_t matrix_columns)
{
    for (size_t i = 0; i < matrix_rows; ++i)
        for (size_t j = 0; j < matrix_columns; ++j)
        {
            printf("Введите элемент матрицы: ");
            if (scanf("%d", &matrix[i][j]) != 1)
                return EXIT_MATRIX_INPUT_FAILURE;
        }
    return EXIT_MATRIX_INPUT_SUCCESS;
}

void array_t_output(array_t arr, size_t array_len)
{
    for (size_t i = 0; i < array_len; ++i)
        printf("Элемент массива: %d\n", arr[i]);
    return;
}

void array_t_fill(array_t array, size_t array_len, int number)
{
    for (size_t i = 0; i < array_len; ++i)
        array[i] = number;
    return;
}


int create_my_array(array_t array, size_t array_len, matrix_t matrix, size_t matrix_rows, size_t matrix_columns)
{
    if (array_len != matrix_columns || matrix_rows > N || matrix_rows > NMAX || matrix_rows < 1 || \
        matrix_columns > N || matrix_columns > NMAX || matrix_columns < 1)
        return EXIT_ARRAY_CREATION_FAILURE;
    
    int flag;
    int prev_sign;
    if (matrix_rows == 1)
    {
        array_t_fill(array, array_len, 0);
        return EXIT_ARRAY_CREATION_SUCCESS;
    }
    
    for (size_t j = 0; j < matrix_columns; ++j)
    {
        prev_sign = sign(matrix[0][j]);
        flag = 0;
        for (size_t i = 1; i < matrix_rows; ++i)
            if ((prev_sign != -sign(matrix[i][j]) || sign(matrix[i][j]) == 0 || prev_sign == 0))
            {
                array[j] = 0;
                flag = 1;
                break;
            }
            else
                prev_sign = -prev_sign;
        if (!flag)
            array[j] = 1;
    }    
    
    return EXIT_ARRAY_CREATION_SUCCESS;
}


int main(void)
{
    size_t matrix_rows, matrix_columns;
    size_t array_len;
    array_t array;
    matrix_t matrix;
    
    printf("Введите количество строк матрицы: ");
    if (scanf("%zu", &matrix_rows) != 1 || matrix_rows > N || matrix_rows > NMAX || matrix_rows < 1)
        return EXIT_FAILURE;
    
    printf("Введите количество столбцов матрицы: ");
    if (scanf("%zu", &matrix_columns) != 1 || matrix_columns > N || matrix_columns > NMAX || matrix_columns < 1)
        return EXIT_FAILURE;
    
    array_len = matrix_columns;
    if (matrix_t_input(matrix, matrix_rows, matrix_columns))
        return EXIT_FAILURE;
    
    if (create_my_array(array, array_len, matrix, matrix_rows, matrix_columns))
        return EXIT_FAILURE;
    
    array_t_output(array, array_len);
    
    return EXIT_SUCCESS;
}
