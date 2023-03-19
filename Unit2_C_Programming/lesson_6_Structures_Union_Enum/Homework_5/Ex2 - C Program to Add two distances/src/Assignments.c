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

typedef struct
{
    unsigned int feets;
    float inches;
}Distance;

int main(void){

  Distance d1, d2, d3;
  printf("Enter information for 1st distance: \n");
  flush();
  printf("Enter feets: ");
  flush();
  scanf("%u", &d1.feets);
  printf("Enter inches: ");
  flush();
  scanf("%f", &d1.inches);

  printf("Displaying information for 2nd distance: \n");
  flush();
  printf("Enter feets: ");
  flush();
  scanf("%u", &d2.feets);
  printf("Enter inches: ");
  flush();
  scanf("%f", &d2.inches);

  float total_inches = d1.inches + d2.inches;
  unsigned int extra_feets = total_inches/12;
  d3.feets = d1.feets + d2.feets + extra_feets;
  d3.inches = total_inches - extra_feets*12;

  printf("sum of distances = %u'%.2f\" ", d3.feets, d3.inches);
  flush();


  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
