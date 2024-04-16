#include <stdlib.h>
#include <stdio.h>

#define NMAX 1024
#define N 10
#define EXIT_ARRAY_INPUT_FAILURE 1
#define EXIT_ARRAY_INPUT_SUCCESS 0
typedef int array_t[NMAX];

int array_t_ptr_input(int *first_arr_el_ptr, int *last_arr_el_ptr)
{
    while (first_arr_el_ptr < last_arr_el_ptr)
    {
        printf("Введите элемент массива: ");
        if (scanf("%d", first_arr_el_ptr) != 1)
            return EXIT_ARRAY_INPUT_FAILURE;
        first_arr_el_ptr++;
    }
    return EXIT_ARRAY_INPUT_SUCCESS;
}

int arr_max_sum(int *ptr_begin, int *ptr_end)
{
    int maximum = *ptr_begin + *ptr_end;
    while (ptr_begin <= ptr_end)
    {
        if (*ptr_begin + *ptr_end > maximum)
            maximum = *ptr_begin + *ptr_end;
        ptr_begin++;
        ptr_end--;
    }
    return maximum;
}

int main(void)
{
    array_t array;
    size_t array_len;
    
    printf("Введите длину массива: ");
    if (scanf("%zu", &array_len) != 1 || array_len > N || array_len > NMAX)
        return EXIT_FAILURE;
    
    int *first_arr_el_ptr = array;
    int *last_arr_el_ptr = first_arr_el_ptr + array_len;
    
    if (array_t_ptr_input(first_arr_el_ptr, last_arr_el_ptr))
        return EXIT_FAILURE;
    
    printf("%d", arr_max_sum(first_arr_el_ptr, last_arr_el_ptr - 1));
    return EXIT_SUCCESS;
}
