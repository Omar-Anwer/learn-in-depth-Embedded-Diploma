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

  len--;
  int i;
  for(i = 0; 2*i < len; ++i)
  {
    char tmp = str[i];
    str[i] = str[len - i];
    str[len - i] = tmp;
  }

  printf("Reverse string is: %s", str);



  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
