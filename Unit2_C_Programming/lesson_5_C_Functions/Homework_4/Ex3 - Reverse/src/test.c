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


void reverse()
{
	char c;
	scanf("%c", &c);
	if(c != '\n')
	{
		reverse();
		printf("%c", c);
	}

}
int main(void)
{
	printf("Enter a sentence: ");
	flush();
	reverse();

	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
