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

typedef struct{
    float real;
    float imag;
}Complex;

Complex addComplex(const Complex* a, const Complex* b){
  Complex z;
  z.real = a->real + b->real;
  z.imag = a->imag + b->imag;
  return (z);
}
void printComplex(const Complex* z){
  printf("sum  = %.2f+%.2fj ", z->real, z->imag);
  flush();
}

int main(void){
  Complex z1, z2, z3;

  printf("for 1st complex number: \n");
  flush();
  printf("Enter real and imaginary respectively: ");
  flush();
  scanf("%f%f", &z1.real, &z1.imag);

  printf("for 2nd complex number: \n");
  flush();
  printf("Enter real and imaginary respectively: ");
  flush();
  scanf("%f%f", &z2.real, &z2.imag);

  z3 = addComplex(&z1, &z2);
  printComplex(&z3);



  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
