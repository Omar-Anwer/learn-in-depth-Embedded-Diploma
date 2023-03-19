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

  printf("Input a string: ");
  flush();
  char str[100];
  gets(str);

  unsigned int len = strlen(str) - 1;

  int i = 0;
  while(i < len)
  {
    char tmp = *(str + i);
    *(str + i) = *(str + len - i);
    *(str + len - i) = tmp;
    i++;
  }

  printf("Reverse of the string is: %s", str);

  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
