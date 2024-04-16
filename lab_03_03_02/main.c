#include <stdlib.h>
#include <stdio.h>

#define NMAX 256
#define N 10
#define EXIT_MATRIX_INPUT_FAILURE 1
#define EXIT_MATRIX_INPUT_SUCCESS 0
#define EXIT_ARRAY_CREATION_SUCCESS 0
#define EXIT_ARRAY_CREATION_FAILURE 1
#define EXIT_ARRAY_COPY_SUCCESS 0
#define EXIT_ARRAY_COPY_FAILURE 1
#define EXIT_MATRIX_PRODUCT_SORT_SUCCESS 0
#define EXIT_MATRIX_PRODUCT_SORT_FAILURE 1

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

int array_t_copy(array_t to, size_t to_len, array_t from, size_t from_len)
{
    if (from_len > to_len)
        return EXIT_ARRAY_COPY_FAILURE;
    for (size_t i = 0; i < from_len; ++i)
        to[i] = from[i];

    return EXIT_ARRAY_COPY_SUCCESS;
}

int array_t_product_comparator(array_t array1, size_t array1_len, array_t array2, size_t array2_len)
{
    int product1 = 1;
    int product2 = 1;
    for (size_t i = 0; i < array1_len; ++i)
        product1 *= array1[i];
    for (size_t i = 0; i < array2_len; ++i)
        product2 *= array2[i];
    if (product1 > product2)
        return 1;
    else if (product1 < product2)
        return -1;
    return 0;
}

int matrix_t_product_sort(matrix_t matrix, size_t matrix_rows, size_t matrix_columns)
{
    array_t buffer;
    size_t buffer_len = matrix_columns;
    for (size_t i = 0; i < matrix_rows - 1; ++i)
    {
        size_t jmax = i;
        for (size_t j = i + 1; j < matrix_rows; ++j)
            if (array_t_product_comparator(matrix[j], matrix_columns, matrix[jmax], matrix_columns) == -1)
                jmax = j;
        if (array_t_copy(buffer, buffer_len, matrix[jmax], matrix_columns))
            return EXIT_MATRIX_PRODUCT_SORT_FAILURE;
        for (size_t k = jmax; k > i; --k)
            if (array_t_copy(matrix[k], matrix_columns, matrix[k - 1], matrix_columns))
                return EXIT_MATRIX_PRODUCT_SORT_FAILURE;
        if (array_t_copy(matrix[i], matrix_columns, buffer, buffer_len))
            return EXIT_MATRIX_PRODUCT_SORT_FAILURE;
    }
    return EXIT_MATRIX_PRODUCT_SORT_SUCCESS;
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
    
    if (matrix_t_product_sort(matrix, matrix_rows, matrix_columns))
        return EXIT_FAILURE;
    
    matrix_t_output(matrix, matrix_rows, matrix_columns);
    
    return EXIT_SUCCESS;
}
