/*
 ============================================================================
 Name        : main.c
 Author      : Omar Anwer
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "Student_Database.h"



#define DPRINTF(...)  {fflush(stdout); \
    fflush(stdin); \
    printf(__VA_ARGS__); \
    fflush(stdout); \
    fflush(stdin);}

int main(void)
{
  char txt[40];
  while(1)
  {
    DPRINTF("\n ======================\n");
    DPRINTF("Choose one of the following options\n");
    DPRINTF("1 - Add a student\n");
    DPRINTF("2 - Delete a student\n");
    DPRINTF("3 - View all students\n");
    DPRINTF("4 - Delete all students\n");
    DPRINTF("5 - Get number of students\n");
    DPRINTF("6 - Get a student info\n");
    DPRINTF("7 - Get nth student info\n");
    DPRINTF("Enter option number: ");
    gets(txt);
    DPRINTF("\n ======================\n");

    switch(atoi(txt))
    {
      case 1:
        AddStudent();
        break;
      case 2:
        DeleteStudent();
        break;
      case 3:
        ViewStudents();
        break;
      case 4:
        DeleteAll();
        break;
      case 5:
        NumStudents();
        break;
      case 6:
        GetStudent();
        break;
      case 7:
        GetNthStudent();
        break;
      default:
        DPRINTF("Wrong option!\n");
        break;
    }
  }

  return 0;
}
