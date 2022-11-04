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

	int t = 2;

	int num;

	while(t--)
	{
		printf("Enter an integers you want to check: ");
		flush();
		scanf("%d", &num);
		printf("%d is ", num);
		flush();
		(num&1) ? printf("Odd\n"): printf("Even\n");
	}


	return EXIT_SUCCESS;
}

void flush(void)
{
	/*fflush(stdin);*/
	fflush(stdout);
}
