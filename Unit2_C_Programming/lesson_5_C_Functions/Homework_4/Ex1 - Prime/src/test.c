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

char isPrime(unsigned int n)
{
	if(n == 2)
		return 1;
	if(n < 2 || !(n&1))
		return 0;
	unsigned int i;
	for(i = 3; i*i <= n; i+=2)
	{
		if(n % i == 0)
			return 0;
	}
	return 1;
}
void printPrime(unsigned int start, unsigned int end)
{
	int i;
	for(i = start; i <= end; ++i)
	{
		if( isPrime(i) )
			printf("%u ", i);
	}
	printf("\n");
}
int main(void)
{
	unsigned int start, end;
	printf("Enter two numbers(intervals): ");
	flush();
	scanf("%u%u", &start, &end);
	printf("Prime numbers between %u and %u are: ", start, end);
	printPrime(start, end);
	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
