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

  printf("Enter a character to find frequency: ");
  flush();
  char c;
  scanf("%c", &c);

  unsigned int cnt = 0;
  int i = 0;
  while(str[i] != '\0')
  {
    if(str[i] == c)
    {
      ++cnt;
    }
    ++i;
  }
  printf("frequency of %c = %u", c, cnt);










  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
