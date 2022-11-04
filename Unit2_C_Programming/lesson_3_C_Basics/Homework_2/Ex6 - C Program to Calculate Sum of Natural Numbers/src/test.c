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
	int n;

	while(trials--)
	{
		printf("Enter an integer: ");
		flush();
		scanf("%d", &n);

		long sum = (n+1)*(n>>1);
		printf("Sum = %lld\n", sum);
		flush();
	}

	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
