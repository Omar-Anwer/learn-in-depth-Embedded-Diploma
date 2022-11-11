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

#define COLS	2
#define ROWS	2

void inputMatrix(float mat[ROWS][COLS])
{
	int r;
	int c;
	for(r = 0; r < ROWS; ++r)
	{
		for(c = 0; c < COLS; ++c)
		{
			printf("Enter a%d%d: ", (r+1), (c+1));
			flush();
			scanf("%f", &mat[r][c]);

		}
	}
}

void printMatrix(float mat[ROWS][COLS])
{
	int r;
	int c;
	for(r = 0; r < ROWS; ++r)
	{
		for(c = 0; c < COLS; ++c)
		{
			printf("%1.2f ", mat[r][c]);
			flush();
		}
		printf("\n");
	}
	printf("\n");
}

void sumOfMatrix(float result[ROWS][COLS], float mat1[ROWS][COLS], float mat2[ROWS][COLS])
{
	int r;
	int c;
	for(r = 0; r < ROWS; ++r)
	{
		for(c = 0; c < COLS; ++c)
		{
			result[r][c] = mat1[r][c] + mat2[r][c];
		}
	}
}

int main(void) {

	float mat1[ROWS][COLS];
	float mat2[ROWS][COLS];
	float result[ROWS][COLS];

	printf("Enter the elements of 1st matrix\n");
	flush();
	inputMatrix(mat1);

	printf("Enter the elements of 2nd matrix\n");
	flush();
	inputMatrix(mat2);

	printf("Sum Of Matrix\n");
	flush();
	sumOfMatrix(result, mat1, mat2);

	printMatrix(result);

	return EXIT_SUCCESS;
}

void flush(void)
{
	fflush(stdin);
	fflush(stdout);
}
