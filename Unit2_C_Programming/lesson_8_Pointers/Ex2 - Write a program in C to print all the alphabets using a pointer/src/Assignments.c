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

  char letter = 'A';
  char* ptr = &letter;

  int i;
  for(i = 0; i < 26; ++i)
  {
    printf("%c ", *ptr);
    (*ptr)++;
  }

  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
