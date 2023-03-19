/*
 ============================================================================
 Name        : Assignments.c
 Author      : Omar Anwer
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush(void);



int main(void){

  int arr[15];
  int *ptr = arr;
  int n;
  printf("Input the number of elements to store in the array (max 15) :");
  flush();
  scanf("%d", &n);

  int i;
  for(i = 0; i < n; ++i){
    printf("element - %d: ", i+1);
    flush();
    scanf("%d", (ptr+i));
  }

  printf("The elements of array in reverse order are : \n");
  flush();
  for(i = n-1; i >= 0; --i){
    printf("element - %d: %d\n", i+1, *(ptr+i));
    flush();
  }

  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
