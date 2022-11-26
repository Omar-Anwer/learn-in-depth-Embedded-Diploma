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

int main(void) {

	int trials = 2;
	unsigned int n;

	while(trials--)
	{
		printf("Enter an integer: ");
		flush();
		scanf("%d", &n);

		unsigned long sum = n*(n+1)>>1;
		printf("Sum = %llu\n", sum);
		flush();
	}

	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
