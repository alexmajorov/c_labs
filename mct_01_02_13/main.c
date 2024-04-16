#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NMAX 1024
#define EXIT_ARRAY_INPUT_SUCCESS 0
#define EXIT_ARRAY_INPUT_FAILURE 1

int prime_check(int n)
{
	if (n % 2 == 0 && n != 2)
		return 1;
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return 1;
	}
	return 0;
}

int array_input(int array[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (scanf("%d", &array[i]) != 0)
    		return 1;
	}
	return 0;
}


void array_output(int array[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", array[i]);
	{
	return;
}


int main(void)
{
    int n;
    int array[NMAX];
    int MAIN_EXIT_KEY;
    printf("Input n: ");
    if (scanf("%d", &n) != 0 || n <= 0)
    	return EXIT_FAILURE;
    MAIN_EXIT_KEY = array_input(array, n);
    if (MAIN_EXIT_KEY == 1)
    	return MAIN_EXIT_KEY;
    	
    array_output(array, n);
	return MAIN_EXIT_KEY;
}
