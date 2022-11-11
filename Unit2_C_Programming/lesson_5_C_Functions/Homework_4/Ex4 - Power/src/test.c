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

long long int power(int base, unsigned int pow)
{
	if(pow == 0)
		return 1;
	return base * power(base, pow-1);
}

int main(void)
{
	int base;
	printf("Enter base number: ");
	flush();
	scanf("%d", &base);


	unsigned int pow;
	printf("Enter power number(positive integer) : ");
	flush();
	scanf("%u", &pow);

	printf("%d^%u = %lld", base, pow, power(base, pow));
	flush();
	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
