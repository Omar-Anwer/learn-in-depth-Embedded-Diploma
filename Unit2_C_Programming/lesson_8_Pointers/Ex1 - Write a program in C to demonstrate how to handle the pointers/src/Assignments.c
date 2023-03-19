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

  int m = 29;
  printf("Address of m: 0x%x\n", &m);
  printf("Value of m: %d\n\n", m);

  int* ab = &m;
  printf("Now ab is assigned with the address of m.\n");
  flush();

  printf("Address of pointer ab: 0x%x\n", ab);
  printf("Content of pointer ab: %d\n\n", *ab);

  *ab = 34;
  printf("The value of m assigned to 34 now.\n");

  printf("Address of pointer ab: 0x%x\n", ab);
  printf("Content of pointer ab: %d\n", *ab);

  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
