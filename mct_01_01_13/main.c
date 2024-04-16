#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define EXIT_G_CALCULATION_SUCCESS 0
#define EXIT_G_CALCULATION_FAILURE 1

// Подпрограмма, считающая значение g = sqrt(sqrt(sqrt(x1) + x2) + ...)
int get_g_value(double *g)
{
	double x;
	*g = 0.0;
	while (scanf("%lf", &x) == 1)
	{
		if (x + (*g) < 0.0)
			return EXIT_G_CALCULATION_FAILURE;
		(*g) = sqrt(x + (*g));
	}
    return EXIT_G_CALCULATION_SUCCESS;
}

int main(void)
{
    double g = 0.0;
    int MAIN_EXIT_KEY;
    MAIN_EXIT_KEY = get_g_value(&g);
    if (!MAIN_EXIT_KEY)
		printf("g = %0.6lf\n", g);
	else
		printf("Calculation error\n");
    return MAIN_EXIT_KEY;
}
