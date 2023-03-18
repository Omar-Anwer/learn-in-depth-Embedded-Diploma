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

  char str[100];

  printf("Enter a string: ");
  flush();
  gets(str);

  size_t len = 0;
  while(str[len] != '\0')
  {
    ++len;
  }


  printf("Length of string: %u", len);



  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
