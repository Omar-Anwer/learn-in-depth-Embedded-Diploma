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
unsigned long long factorial(int n)
{
	if(n < 0){
		return 0;
	}

	unsigned long long fac = 1;
	while(n>1)
	{
		fac = fac*n;
		--n;
	}
	return fac;

}

int main(void) {

	int trials = 4;
	int n;

	while(trials--)
	{
		printf("Enter an integer: ");
		flush();
		scanf("%d", &n);
		unsigned long long fac = factorial(n);
		if(fac)
			printf("Factorial = %llu\n", fac);
		else
			printf("Error!!! Factorial of negative number doesn't exist\n");
		flush();
	}

	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
