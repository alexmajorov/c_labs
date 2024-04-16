#include <stdlib.h>
#include <stdio.h>

#define NMAX 256
#define N 10
#define EXIT_MATRIX_INPUT_FAILURE 1
#define EXIT_MATRIX_INPUT_SUCCESS 0
#define EXIT_ARRAY_COPY_FAILURE 1
#define EXIT_ARRAY_COPY_SUCCESS 0
#define EXIT_MATRIX_INSERTION_SUCCESS 0
#define EXIT_MATRIX_INSERTION_FAILURE 1
#define EXIT_MATRIX_MY_INSERTION_SUCCESS 0
#define EXIT_MATRIX_MY_INSERTION_FAILURE 1

typedef int matrix_t[NMAX][NMAX];
typedef int array_t[NMAX];

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

int array_t_copy(array_t from, size_t from_len, array_t to, size_t to_len)
{
    if (from_len != to_len)
        return EXIT_ARRAY_COPY_FAILURE;
    for (size_t i = 0; i < to_len; ++i)
        to[i] = from[i];
    return EXIT_ARRAY_COPY_SUCCESS;    
}


int sum_of_digits(int n)
{
    int temp = n;
    int remainder;
    int sum = 0;
    
    while (temp != 0)
    {
        remainder = temp % 10;
        sum += remainder;
        temp /= 10;
    }
    return sum;
}

int matrix_t_my_insert(matrix_t matrix, size_t *matrix_rows, size_t matrix_columns)
{
    array_t my_array;
    size_t my_array_len = matrix_columns;
    for (size_t i = 0; i < my_array_len; ++i)
        my_array[i] = -1;
    
    int count = 0;
    int flag;
    for (size_t i = 0; i < *matrix_rows; ++i)
    {
        flag = 0;
        for (size_t j = 0; j < matrix_columns; ++j)
            if (sum_of_digits(matrix[i][j]) % 2 != 0)
                flag++;
        if (flag > 1)
            count++;
    }
    for (int i = *matrix_rows + count - 1, j = *matrix_rows - 1; j >= 0; j--, i--)
    {
        flag = 0;
        for (size_t q = 0; q < matrix_columns; ++q)
            if (sum_of_digits(matrix[j][q]) % 2 != 0)
                flag++;
        if (flag > 1)
        {
            if (array_t_copy(matrix[j], matrix_columns, matrix[i], matrix_columns))
                return EXIT_MATRIX_MY_INSERTION_FAILURE;
            --i;
            if (array_t_copy(my_array, matrix_columns, matrix[i], matrix_columns))
                return EXIT_MATRIX_MY_INSERTION_FAILURE;
        }
        else if (array_t_copy(matrix[j], matrix_columns, matrix[i], matrix_columns))
            return EXIT_MATRIX_MY_INSERTION_FAILURE;
    }
    (*matrix_rows) += count;
    return EXIT_MATRIX_MY_INSERTION_SUCCESS;
}

int main(void)
{
    size_t matrix_rows, matrix_columns;
    matrix_t matrix;
    
    printf("Введите количество строк матрицы: ");
    if (scanf("%zu", &matrix_rows) != 1 || matrix_rows > N || matrix_rows > NMAX || matrix_rows < 1)
        return EXIT_FAILURE;
    
    printf("Введите количество столбцов матрицы: ");
    if (scanf("%zu", &matrix_columns) != 1 || matrix_columns > N || matrix_columns > NMAX || matrix_columns < 1)
        return EXIT_FAILURE;
    
    if (matrix_t_input(matrix, matrix_rows, matrix_columns))
        return EXIT_FAILURE;
    
    if (matrix_t_my_insert(matrix, &matrix_rows, matrix_columns))
        return EXIT_FAILURE;
    
    matrix_t_output(matrix, matrix_rows, matrix_columns);
    
    return EXIT_SUCCESS;
}
