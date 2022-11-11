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

	int n;
	printf("Enter the numbers of data: ");
	flush();
	scanf("%u", &n);

	float num;
	float avg = 0.0;

	int i;
	for(i = 1; i <= n; ++i)
	{
		printf("%d. Enter number: ", i);
		flush();
		scanf("%f", &num);
		avg = (1 - 1.0/i)*avg + num/i;
	}
	printf("Average = %f", avg);

	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
