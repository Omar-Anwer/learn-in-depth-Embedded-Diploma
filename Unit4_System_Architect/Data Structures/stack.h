/*
 * stack.h
 *
 *  Created on: Mar 25, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>

#define STACK_MAX_SIZE  (5)

typedef int StackItemType_t;

typedef struct
{
    int top;
    StackItemType_t stack[STACK_MAX_SIZE];

}Stack;


void initializeStack(Stack* s);

int StackisEmpty(Stack* s);

int StackisFull(Stack* s);

int push(Stack* s, StackItemType_t val);

StackItemType_t pop(Stack* s);

void printStack(Stack* s);

#endif /* STACK_H_ */
