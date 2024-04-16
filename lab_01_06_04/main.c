#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9

int point_check(double xq, double yq, double xr, double yr, double xp, double yp)
{   
    double qp = sqrt((xq - xp) * (xq - xp) + (yq - yp) * (yq - yp));
    double rp = sqrt((xr - xp) * (xr - xp) + (yr - yp) * (yr - yp));
    double qr = sqrt((xq - xr) * (xq - xr) + (yq - yr) * (yq - yr));
    return fabs(qp + rp - qr) < EPS;
}

int main(void)
{
    double xq, yq;
    double xr, yr;
    double xp, yp;
    
    printf("Введите координаты первой точки отрезка: ");
    if (scanf("%lf %lf", &xq, &yq) != 2) 
        return EXIT_FAILURE;
    
    printf("Введите координаты второй точки отрезка: ");
    if (scanf("%lf %lf", &xr, &yr) != 2 || (fabs(xq - xr) < EPS && fabs(yq - yr) < EPS)) 
        return EXIT_FAILURE;
    
    printf("Введите координаты произвольной точки: ");
    if (scanf("%lf %lf", &xp, &yp) != 2) 
        return EXIT_FAILURE;
    
    printf("%i\n", point_check(xq, yq, xr, yr, xp, yp));
    
    return EXIT_SUCCESS;
}
