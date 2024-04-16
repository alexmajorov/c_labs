#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t left_shift(uint32_t a, int n)
{
    return (a << n) | (a >> (32 - n));
}

int main(void)
{
    uint32_t a;
    int n;
    printf("Введите беззнаковое четырехбайтное число: ");
    if (scanf("%"SCNu32"", &a) != 1)
    {
        printf("Error: неверное значение\n");
        return EXIT_FAILURE;
    }
    printf("Введите число, на которое необходимо совершить сдвиг влево: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Error: неверное значение\n");
        return EXIT_FAILURE;
    }
    a = left_shift(a, n);
    printf("Result: ");
    for (int i = 31; i >= 0; --i)
    {
        printf("%"PRIu32"", ((a >> i) & 1));
    }
    printf("\n");
    return EXIT_SUCCESS;
}
