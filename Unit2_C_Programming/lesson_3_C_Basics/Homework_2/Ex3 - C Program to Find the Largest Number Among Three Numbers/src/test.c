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

	int n = 3;
	float num;
	float max;

	printf("Enter three numbers: ");
	flush();
	scanf("%f", &max);
	while(--n)
	{
		scanf("%f", &num);

		if(num > max){
			max = num;
		}

	}

	printf("Largest number = %f", max);

	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
