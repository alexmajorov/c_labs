#include <stdlib.h>
#include <stdio.h>

#define NMAX 256
#define N 10
#define EXIT_MATRIX_INPUT_FAILURE 1
#define EXIT_MATRIX_INPUT_SUCCESS 0

typedef int matrix_t[NMAX][NMAX];

void matrix_t_fill_boustrophedon(matrix_t matrix, size_t matrix_rows, size_t matrix_columns)
{
    int value = 1;
    for (int j = matrix_columns - 1; j >= 0; --j)
    {
        if ((matrix_columns - j) % 2 == 1)
            for (int i = matrix_rows - 1; i >= 0; --i)
            {
                matrix[i][j] = value;
                value++;
            }
        else
            for (size_t i = 0; i < matrix_rows; ++i)
            {
                matrix[i][j] = value;
                value++;
            }
    }
    return;
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
    
    matrix_t_fill_boustrophedon(matrix, matrix_rows, matrix_columns);
    
    matrix_t_output(matrix, matrix_rows, matrix_columns);
    return EXIT_SUCCESS;
}
