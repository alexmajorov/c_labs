#include <stdlib.h>
#include <stdio.h>

#define NMAX 256
#define N 10
#define EXIT_MATRIX_INPUT_FAILURE 1
#define EXIT_MATRIX_INPUT_SUCCESS 0
#define EXIT_ARRAY_APPEND_SUCCESS 0
#define EXIT_ARRAY_APPEND_FAILURE 1
#define EXIT_MY_ARRAY_CREATION_FAILURE 1
#define EXIT_MY_ARRAY_CREATION_SUCCESS 0

typedef int matrix_t[NMAX][NMAX];
typedef int array_t[NMAX];

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

void matrix_t_output(matrix_t matrix, size_t matrix_rows, size_t matrix_columns)
{
    for (size_t i = 0; i < matrix_rows; ++i)
    {
        for (size_t j = 0; j < matrix_columns; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return;
}

int prime_check(int n, int i)
{
    if (n <= 1)
        return 0;
    if (n == i)
        return 1;
    if (n % i == 0)
        return 0;
    i++;
    return prime_check(n, i);
}


int array_t_append(array_t array, size_t *array_len, int value)
{
    if ((*array_len) + 1 > NMAX)
        return EXIT_ARRAY_APPEND_FAILURE;
    (*array_len)++;
    array[*array_len - 1] = value;
    return EXIT_ARRAY_APPEND_SUCCESS;
}

int create_my_array(array_t array, size_t *array_len, matrix_t matrix, size_t matrix_rows, size_t matrix_columns)
{
    for (size_t i = 0; i < matrix_rows; ++i)
        for (size_t j = 0; j < matrix_columns; ++j)
            if (prime_check(matrix[i][j], 2) == 1)
                if (array_t_append(array, array_len, matrix[i][j]))
                    return EXIT_MY_ARRAY_CREATION_FAILURE;
    return EXIT_MY_ARRAY_CREATION_SUCCESS;
}

void create_new_matrix(array_t array, matrix_t matrix, size_t matrix_rows, size_t matrix_columns)
{
    size_t array_i = 0;
    for (size_t i = 0; i < matrix_rows; ++i)
        for (size_t j = 0; j < matrix_columns; ++j)
            if (prime_check(matrix[i][j], 2) == 1)
            {
                matrix[i][j] = array[array_i];
                array_i++;
            }   
    return;
}

void array_t_reverse(array_t array, size_t array_len)
{
    size_t start = 0;
    size_t end = array_len - 1;
    int temp;
    while (start < end)
    {
        temp = array[start];  
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
    return;
} 

int main(void)
{
    size_t matrix_rows, matrix_columns;
    size_t array_len = 0;
    array_t array;
    matrix_t matrix;
    
    printf("Введите количество строк матрицы: ");
    if (scanf("%zu", &matrix_rows) != 1 || matrix_rows > N || matrix_rows > NMAX || matrix_rows < 1)
        return EXIT_FAILURE;
    
    printf("Введите количество столбцов матрицы: ");
    if (scanf("%zu", &matrix_columns) != 1 || matrix_columns > N || matrix_columns > NMAX || matrix_columns < 1)
        return EXIT_FAILURE;
    
    if (matrix_t_input(matrix, matrix_rows, matrix_columns))
        return EXIT_FAILURE;

    if (create_my_array(array, &array_len, matrix, matrix_rows, matrix_columns))
        return EXIT_FAILURE;

    if (array_len == 0)
        return EXIT_FAILURE;

    array_t_reverse(array, array_len);
    create_new_matrix(array, matrix, matrix_rows, matrix_columns);
    matrix_t_output(matrix, matrix_rows, matrix_columns);
    return EXIT_SUCCESS;
}
