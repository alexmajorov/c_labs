#include <stdio.h>
#include <stdlib.h>

void factorization(int number)
{
    for (int i = 2; i * i <= number; ++i) 
    {
        while (number % i == 0) 
        {
            printf("%i ", i);
            number /= i;
        }
    }
    if (number != 1)
        printf("%i", number);
    printf("\n");
}

int main(void)
{
    int number;
    printf("Введите натуральное число: ");
    if (scanf("%i", &number) != 1 || number <= 0) 
        return EXIT_FAILURE;
    factorization(number);
    return EXIT_SUCCESS;
}
