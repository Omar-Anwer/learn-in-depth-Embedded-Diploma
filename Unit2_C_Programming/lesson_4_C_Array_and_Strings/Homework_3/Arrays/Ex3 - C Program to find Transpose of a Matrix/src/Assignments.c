/*
 ============================================================================
 Name        : Assignments.c
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

  unsigned int rows;
  unsigned int cols;

  printf("Enter rows and columns of matrix:");
  flush();
  scanf("%u%u", &rows, &cols);


  unsigned int r;
  unsigned int c;
  /* Create 2D Matrix*/
  int** mat = (int**)malloc(cols * sizeof(int));
  for (r = 0; r < rows; r++){
    mat[r] = (int *) malloc(rows * sizeof(int));
  }

  /* input 2D Matrix*/
  printf("Enter elements of matrix:\n");
  flush();
  for (r = 0; r < rows; r++){
    for (c = 0; c < cols; c++){
      printf("Enter element a%u%u: ", r, c);
      flush();
      scanf("%d", &mat[r][c]);
    }
  }
  flush();

  printf("Entered matrix:\n");
  flush();

  /* print 2D Matrix*/
  for (r = 0; r < rows; r++){
    for (c = 0; c < cols; c++){
      printf("%d ", mat[r][c]);
    }
    printf("\n");
  }

  /* transpose 2D Matrix*/
  int** trans = (int**)malloc(rows * sizeof(int));
  for (c = 0; c < cols; c++){
    trans[c] = (int *) malloc(cols * sizeof(int));
  }

  for (r = 0; r < rows; r++){
    for (c = 0; c < cols; c++){
      trans[c][r] = mat[r][c];
    }
  }

  printf("Transpose of matrix:\n");
  for (r = 0; r < cols; r++){
    for (c = 0; c < rows; c++){
      printf("%d ", trans[r][c]);
    }
    printf("\n");
  }

  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
