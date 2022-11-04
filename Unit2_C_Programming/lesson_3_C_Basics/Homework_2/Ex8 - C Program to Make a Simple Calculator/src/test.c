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

	int trials = 1;
	float a;
	float b;
	char op;

	while(trials--)
	{
		printf("Enter operator either + or - or * or /: ");
		flush();
		scanf("%c", &op);
		printf("Enter two operands: ");
		flush();
		scanf("%f%f", &a, &b);

		double result;

		switch(op)
		{
			case '+':
					result = a + b;
					break;
			case '-':
					result = a - b;
					break;
			case '*':
					result = a * b;
					break;
			case '/':
					result = a / b;
					break;
		}
		printf("%.2f %c %.2f = %.1lf\n", a, op, b, result);
		flush();
	}

	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
