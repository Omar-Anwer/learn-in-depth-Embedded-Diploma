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

#define STUDENT_NUMBER  (2)
typedef struct{
    char name[100];
    unsigned int roll;
    float marks;
}Student;

int main(void){
  Student students[STUDENT_NUMBER];
  printf("Enter information of students: \n");flush();
  unsigned int i;
  for(i = 0; i < STUDENT_NUMBER; ++i){
    printf("For roll number %u: \n", i+1); flush();
    students[i].roll = i+1;
    printf("Enter name: ");flush();
    gets(students[i].name);
    printf("Enter marks: ");flush();
    scanf("%f", &students[i].marks);
  }

  printf("Displaying information of students: \n");
  flush();
  for(i = 0; i < STUDENT_NUMBER; ++i){
    printf("Information for roll number : %u\n", students[i].roll);flush();
    printf("Name: %s\n", students[i].name);flush();
    printf("Marks: %.2f\n", students[i].marks);flush();
  }

  return 0;
}


void flush(void){
  fflush(stdin);
  fflush(stdout);
}
