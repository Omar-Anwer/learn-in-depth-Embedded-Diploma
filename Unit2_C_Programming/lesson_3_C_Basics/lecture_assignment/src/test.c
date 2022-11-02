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

	unsigned int len = 9;
	int i;
	int j;
	for(i = 0; i <= len; ++i)
	{
		for(j = i; j <= len; ++j)
		{
			printf("%d", j);
		}
		printf("\n");
	}
	printf("\n");

	return EXIT_SUCCESS;
}

void flush(void)
{
	/*fflush(stdin);*/
	fflush(stdout);
}
