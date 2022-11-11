/*
 ============================================================================
 Name        : test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void flush(void);

unsigned long long int factorial(unsigned int n)
{
	if(n == 0)
		return 1;
	return n * factorial(n-1);
}

int main(void)
{
	unsigned int n;
	printf("Enter a positive integer: ");
	flush();
	scanf("%u", &n);
	printf("factorial of %u = %lu", n, factorial(n) );
	flush();
	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
