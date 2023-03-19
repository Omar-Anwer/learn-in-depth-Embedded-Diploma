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
    char name[100];
    unsigned int roll;
    float marks;

}Student;

int main(void){

  Student s1;

  printf("Enter student information: \n");
  fflush(stdout);
  printf("Enter name: ");
  flush();
  gets(s1.name);
  printf("Enter roll: ");
  flush();
  scanf("%u", &s1.roll);
  printf("Enter marks: ");
  flush();
  scanf("%f", &s1.marks);

  printf("Displaying information: \n");
  flush();
  printf("Name: %s\n", s1.name);
  flush();
  printf("Roll: %u\n", s1.roll);
  flush();
  printf("Marks: %.2f\n", s1.marks);
  flush();

  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
