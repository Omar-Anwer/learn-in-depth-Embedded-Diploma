/*
 * stack.c
 *
 *  Created on: Mar 25, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */

#include "stack.h"


void initializeStack(Stack* s){
  s->top = -1;
}

inline int StackisEmpty(Stack* s)
{
  return (s->top == -1);
}

inline int StackisFull(Stack* s)
{
  return (s->top == STACK_MAX_SIZE - 1);
}

int push(Stack* s, StackItemType_t val)
{
  if(!StackisFull(s))
  {
    s->top++;
    s->stack[s->top] = val;
    return (1);
  }
  else
  {
    printf("Stack is full!");
    return (0);
  }
}

StackItemType_t pop(Stack* s)
{
  if(!StackisEmpty(s))
  {
    StackItemType_t tmp = s->stack[s->top];
    s->top--;
    return (tmp);
  }
  else
  {
    printf("Stack is empty!");
    return (0);
  }
}

void printStack(Stack* s)
{
  int i;
  for(i = s->top; i >= 0; --i)
  {
    printf("%d\n", s->stack[i]);
  }
}
