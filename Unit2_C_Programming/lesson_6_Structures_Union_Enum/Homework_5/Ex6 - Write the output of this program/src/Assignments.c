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

union job
{
    char name[32];
    float salary;
    int worker_no;
}u;

struct job1
{
    char name[32];
    float salary;
    int worker_no;
}s;


int main(void){

  printf("size of union = %u\n", sizeof(u));
  printf("size of structure = %u\n", sizeof(s));


  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
