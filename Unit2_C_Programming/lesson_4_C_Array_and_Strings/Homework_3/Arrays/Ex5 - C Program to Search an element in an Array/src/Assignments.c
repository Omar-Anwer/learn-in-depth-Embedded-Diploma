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
  if(arr != 0) {
    for (i = 0; i < n; i++){
      scanf("%d", &arr[i]);
    }
  }
  int key;
  printf("Enter the element to be searched: ");
  flush();
  scanf("%d", &key);

  /*Linear Search*/
  int idx = -1;
  for (i = 0; i < n; i++)
  {
    if(arr[i] == key)
    {
      idx = i+1;
      break;
    }
  }
  if(idx != -1){
    printf("Number found at location = %u", idx);
  }
  else{
    printf("Number not found !!");
  }
  flush();





  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
