/*
 * Student_Database.c
 *
 *  Created on: Mar 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>
#include <string.h>

#define DPRINTF(...)  {fflush(stdout); \
    fflush(stdin); \
    printf(__VA_ARGS__); \
    fflush(stdout); \
    fflush(stdin);}
typedef struct
{
    unsigned int ID;
    char name[40];
    float height;

}Sdata;

typedef struct SStudent SStudent;

struct SStudent
{
    Sdata student;
    SStudent* pNextStudent;
};



SStudent* gpFirstStudent = NULL;

void AddStudent(void)
{
  SStudent* pNewStudent = (SStudent*)malloc(sizeof(SStudent));
  if(gpFirstStudent == NULL)
  {
    gpFirstStudent = pNewStudent;
  }
  else
  {
    SStudent* pLastStudent = gpFirstStudent;
    while(pLastStudent->pNextStudent)
    {
      pLastStudent = pLastStudent->pNextStudent;
    }
    pLastStudent->pNextStudent = pNewStudent;
  }

  /* Fill new record*/
  char txt[40];
  DPRINTF("Enter the student ID: ");
  gets(txt);
  pNewStudent->student.ID = atoi(txt);

  DPRINTF("\nEnter student full name: ");
  gets(pNewStudent->student.name);

  DPRINTF("\nEnter the student height: ");
  gets(txt);
  pNewStudent->student.height = atof(txt);

  pNewStudent->pNextStudent = NULL;
}

int DeleteStudent(void)
{
  char txt[40];
  unsigned int ID;
  DPRINTF("\n Enter the student ID to be deleted: ");
  gets(txt);
  ID = atoi(txt);

  if(gpFirstStudent)
  {
    SStudent* pPreviousStudent = NULL;
    SStudent* pSelectedStudent = gpFirstStudent;
    while(pSelectedStudent)
    {
      if(pSelectedStudent->student.ID == ID)
      {
        if(pPreviousStudent)
        {
          pPreviousStudent->pNextStudent = pSelectedStudent->pNextStudent;
        }
        else
        {
          gpFirstStudent = pSelectedStudent->pNextStudent;
        }
        free(pSelectedStudent);
        return 1;
      }
      pPreviousStudent = pSelectedStudent;
      pSelectedStudent = pSelectedStudent->pNextStudent;
    }

  }
  DPRINTF("\nCan't find the student id!!\n");
  return 0;
}

void ViewStudents(void)
{
  SStudent* pCurrentStudent = gpFirstStudent;
  unsigned int cnt = 0;
  if(gpFirstStudent == NULL)
  {
    DPRINTF("Empty list!!\n");
  }
  else
  {
    while(pCurrentStudent)
    {
      DPRINTF("record number %u\n", cnt+1);
      DPRINTF("ID:  %d\n", pCurrentStudent->student.ID);
      DPRINTF("name:  %s\n", pCurrentStudent->student.name);
      DPRINTF("height:  %f\n", pCurrentStudent->student.height);
      pCurrentStudent = pCurrentStudent->pNextStudent;
      cnt++;
    }
  }
}

void DeleteAll(void)
{
  SStudent* pCurrentStudent = gpFirstStudent;
  if(gpFirstStudent == NULL)
  {
    DPRINTF("Empty list!!\n");
  }
  else
  {
    while(pCurrentStudent)
    {
      SStudent* pTempStudent = pCurrentStudent;
      pCurrentStudent = pCurrentStudent->pNextStudent;
      free(pTempStudent);
    }
    gpFirstStudent = NULL;
  }
}

unsigned int NumStudents(void)
{
  unsigned int num = 0;
  SStudent* pCurrentStudent = gpFirstStudent;
  while(pCurrentStudent)
  {
    pCurrentStudent = pCurrentStudent->pNextStudent;
    num++;
  }
  DPRINTF("Number of students = %u\n", num);
  return num;
}

void GetStudent(void)
{
  char txt[40];
  unsigned int ID;
  DPRINTF("\n Enter the student ID to display his/her info: ");
  gets(txt);
  ID = atoi(txt);

  unsigned int cnt = 0;
  unsigned int isFound = 0;
  SStudent* pCurrentStudent = gpFirstStudent;
  while(pCurrentStudent)
  {
    if(pCurrentStudent->student.ID == ID)
    {
      isFound = 1;
      break;
    }
    pCurrentStudent = pCurrentStudent->pNextStudent;
  }
  if(isFound)
  {
    DPRINTF("record number %u\n", cnt + 1);
    DPRINTF("ID:  %d\n", pCurrentStudent->student.ID);
    DPRINTF("name:  %s\n", pCurrentStudent->student.name);
    DPRINTF("height:  %f\n", pCurrentStudent->student.height);
  }
  else
  {
    DPRINTF("No student was found!!\n");
  }
}

void GetNthStudent(void)
{
  char txt[40];
    unsigned int n;
    DPRINTF("\n Enter the nth student to display his/her info: ");
    gets(txt);
    n = atoi(txt);

  unsigned int isFound = 0;
  int i = 1;
  SStudent* pCurrentStudent = gpFirstStudent;
  while(pCurrentStudent){
    if(i == n){
      isFound = 1;
      break;
    }
    pCurrentStudent = pCurrentStudent->pNextStudent;
    i++;
  }

  if(isFound)
   {
     DPRINTF("record number %u\n", i);
     DPRINTF("ID:  %d\n", pCurrentStudent->student.ID);
     DPRINTF("name:  %s\n", pCurrentStudent->student.name);
     DPRINTF("height:  %f\n", pCurrentStudent->student.height);
   }
   else
   {
     DPRINTF("No student was found!!\n");
   }


}
