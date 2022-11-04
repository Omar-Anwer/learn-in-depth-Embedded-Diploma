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

	int trials = 3;
	float num;



	while(trials--)
	{
		printf("Enter a number: ");
		flush();
		scanf("%f", &num);
		if(num > 0)
		{
			printf("%f is positive\n", num);
		}
		else if(num < 0)
		{
			printf("%f is negative\n", num);
		}
		else
		{
			printf("you entered zero\n");
		}
		flush();
	}



	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
