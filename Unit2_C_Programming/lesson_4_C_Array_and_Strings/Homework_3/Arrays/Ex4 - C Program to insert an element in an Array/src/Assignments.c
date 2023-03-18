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

  int n;
  printf("Enter no of elements: ");
  flush();
  scanf("%d", &n);

  /* Create dynamically an array*/
  int* arr = (int*)malloc(n * sizeof(int));
  int i;
  if(arr != 0)
  {
    for (i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }
  }
  int num;
  printf("Enter the element to be inserted: ");
  flush();
  scanf("%d", &num);

  int idx;
  printf("Enter the location: ");
  flush();
  scanf("%d", &idx);

  /*Extend the array by one element*/
  n = n + 1;
  int* arr2 = (int*)realloc(arr, n * sizeof(int));
  if(arr2 != 0)
  {
    for (i = n-1; i >= idx; i--)
    {
      arr2[i] = arr2[i-1];
    }
    *(arr2 + idx-1) = num;
  }

  for (i = 0; i < n; i++)
  {
    printf("%d ", arr2[i]);
  }












  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
