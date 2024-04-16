#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-9

int main(void)
{
    double r1, r2, r3;
    double r;
    printf("Введите сопротивление первого резистра: ");
    scanf("%lf", &r1);
    printf("Введите сопротивление второго резистра: ");
    scanf("%lf", &r2);
    printf("Введите сопротивление третьего резистра: ");
    scanf("%lf", &r3);
    if ((r1 < EPS) || (r2 < EPS) || (r3 < EPS))
    {
        r = 0.0;
    }
    else
    {
        r = 1.0 / (1.0 / r1 + 1.0 / r2 + 1.0 / r3);
    }
    printf("Сопротивление всего соединения: ");
    printf("%0.6lf\n", r);
    return EXIT_SUCCESS;
}
 
 
