#include <stdlib.h>
#include <stdio.h>

#define NMAX 256
#define N 10
#define LST_DGT 5
#define EXIT_MATRIX_INPUT_FAILURE 1
#define EXIT_MATRIX_INPUT_SUCCESS 0
#define EXIT_GRTST_NUM_ANTIDGNL_FAILURE 1
#define EXIT_GRTST_NUM_ANTIDGNL_SUCCESS 0

typedef int matrix_t[NMAX][NMAX];


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

int last_digit(int n)
{
    return abs(n % 10);
}

int grtst_num_antidgnl(matrix_t matrix, size_t matrix_size, int *grtst_num_antidgnl)
{
    *grtst_num_antidgnl = 0;
    for (size_t i = 0; i < matrix_size; ++i)
        for (size_t j = matrix_size - i; j < matrix_size; ++j)
            if (last_digit(matrix[i][j]) == LST_DGT)
            {
                if (*grtst_num_antidgnl == 0)
                    *grtst_num_antidgnl = matrix[i][j];
                else if (matrix[i][j] > *grtst_num_antidgnl)
                    *grtst_num_antidgnl = matrix[i][j];
            }
    if (*grtst_num_antidgnl == 0)
        return EXIT_GRTST_NUM_ANTIDGNL_FAILURE;
    
    return EXIT_GRTST_NUM_ANTIDGNL_SUCCESS;        
}

int main(void)
{
    size_t matrix_rows, matrix_columns;
    matrix_t matrix;
    int answer;

    printf("Введите количество строк матрицы: ");
    if (scanf("%zu", &matrix_rows) != 1 || matrix_rows > N || matrix_rows > NMAX || matrix_rows < 1)
        return EXIT_FAILURE;
    
    printf("Введите количество столбцов матрицы: ");
    if (scanf("%zu", &matrix_columns) != 1 || matrix_columns > N || matrix_columns > NMAX || matrix_columns < 1)
        return EXIT_FAILURE;
    
    if (matrix_rows != matrix_columns)
        return EXIT_FAILURE;
    
    if (matrix_t_input(matrix, matrix_rows, matrix_columns))
        return EXIT_FAILURE;
    
    if (grtst_num_antidgnl(matrix, matrix_rows, &answer))
        return EXIT_FAILURE;
        
    printf("%d\n", answer);
    return EXIT_SUCCESS;
}
