#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    double g;
    printf("Введите x: ");
    if (scanf("%lf", &x) != 1 || x < 0.0)
        return EXIT_FAILURE;
    int i = 1;
    double roots_sum = 0.0;
    while (x >= 0.0)
    {
        roots_sum += sqrt(i + x);
        i++;
        printf("Введите x: ");
        if (scanf("%lf", &x) != 1)
            return EXIT_FAILURE;
    }
    g = roots_sum / (i - 1);
    printf("g(x) = %0.6lf\n", g);
    return EXIT_SUCCESS;
}
