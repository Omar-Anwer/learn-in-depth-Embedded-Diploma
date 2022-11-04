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
	char ch;

	while(trials--)
	{
		printf("Enter a character: ");
		flush();
		scanf("%c", &ch);
		if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			printf("%c is an alphabet\n", ch);
		}
		else
		{
			printf("%c is not an alphabet\n", ch);
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
