#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double xa, ya;
    double xb, yb;
    double xc, yc;
    double side1, side2, side3;
    double perimeter;
    printf("Введите координаты первой вершины треугольника: ");
    scanf("%lf %lf", &xa, &ya);
    printf("Введите координаты второй вершины треугольника: ");
    scanf("%lf %lf", &xb, &yb);
    printf("Введите координаты третьей вершины треугольника: ");
    scanf("%lf %lf", &xc, &yc);
    side1 = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    side2 = sqrt((xc - xa) * (xc - xa) + (yc - ya) * (yc - ya));
    side3 = sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb));
    perimeter = side1 + side2 + side3;
    printf("Периметр заданного треугольника: ");
    printf("%0.6lf\n", perimeter);
    return EXIT_SUCCESS;
}
 
