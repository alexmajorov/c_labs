#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int sec;
    printf("Введите количество секунд: ");
    scanf("%i", &sec);
    int hour = sec / 3600;
    sec %= 3600; 
    int min = sec / 60; 
    sec %= 60;
    printf("%i : %i : %i\n", hour, min, sec);
    return EXIT_SUCCESS;
}
