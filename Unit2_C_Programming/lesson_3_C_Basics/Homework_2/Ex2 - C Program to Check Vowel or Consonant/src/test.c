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
	char letter;
	while(trials--)
	{
		printf("Enter an alphabet: ");
		flush();
		scanf("%c", &letter);
		printf("%c is a ", letter);
		flush();
		switch(letter)
		{
			case 'A':
			case 'a':
			case 'E':
			case 'e':
			case 'I':
			case 'i':
			case 'O':
			case 'o':
			case 'U':
			case 'u':
				printf("vowel.\n");
				break;

			default:
				printf("constant.\n");
				break;
		}
	}
	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
