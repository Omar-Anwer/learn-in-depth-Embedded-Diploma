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
long Add (int num1, int num2)
{
	return (num1 + num2);
}
int main(void) {

	int ROWS = 6;
	int COLS = 26;
	int i;
	int j;
	for(i = 0; i <= ROWS; ++i)
	{	if(i == 1){
		printf("C Programming\n");
		continue;
	}
	if(i == 3){
		/*code here*/
		char c;
		printf("Enter a character: ");
		flush();
		scanf("%c", &c);
		printf("ASCII value of %c = %d", c, c);
		flush();
		printf("\n");
		continue;
	}

	for(j = 0; j <= COLS; ++j)
	{
		if( (i == 0) && (j >= 10 && j<=23))
		{
			if(j == 10){
				printf("Console-output");
			}
			continue;
		}
		else{
			printf("#");
		}
	}
	if(i < 4){
		printf("\n");
	}
	}
	printf("\n");

	return EXIT_SUCCESS;
}

void flush(void)
{
	/*fflush(stdin);*/
	fflush(stdout);
}
