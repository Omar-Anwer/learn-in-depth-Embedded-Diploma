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

#define PI              (3.141592653589793)
#define circleArea(r)   (PI * (r) * (r))
void flush(void);


int main(void){


  printf("Enter the radius: ");
  flush();

  float r;
  scanf("%f", &r);

  printf("Area = %.2f", circleArea(r));


  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
