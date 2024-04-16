#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9 

double series_sum(double x, double e)
{
    double term = 1.0;
    double s = 1.0;
    int i = 3;
    while (fabs(term) >= e)
    {
        term = -term * i / (i - 2) * x;
        s += term;
        i++;
    }
    return s;
}

int main(void)
{
    double x;
    double e;
    double f, s;
    double absolute_error, relative_error;
    printf("Введите x: ");
    if (scanf("%lf", &x) != 1 || fabs(x) - 1.0 >= EPS)
        return EXIT_FAILURE;
    printf("Введите e: ");
    if (scanf("%lf", &e) != 1 || e <= EPS || e - 1.0 > EPS)
        return EXIT_FAILURE;
    f = 1.0 / (1.0 + x) / (1.0 + x) / (1.0 + x);
    s = series_sum(x, e);
    absolute_error = fabs(f - s);
    relative_error = fabs(f - s) / fabs(f);
    printf("s(x) = %0.6lf\n", s);
    printf("f(x) = %0.6lf\n", f);
    printf("Абсолютная погрешность = %0.6lf\n", absolute_error);
    printf("Относительная погрешность = %0.6lf\n", relative_error);
    return EXIT_SUCCESS;
}
