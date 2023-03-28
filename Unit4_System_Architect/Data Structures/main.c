/*
 ============================================================================
 Name        : Data.c
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

#include "LIFO.h"
#include "FIFO.h"
#include "Linked_List.h"

#define LIFO_BUFFER_MAX_SIZE   (5)
#define FIFO_BUFFER_MAX_SIZE   (5)

LIFO_ItemType LIFO_Buffer[LIFO_BUFFER_MAX_SIZE];
FIFO_ItemType FIFO_Buffer[FIFO_BUFFER_MAX_SIZE];


int main(void)
{
  
  List list;

  List_Init(&list);

  List_pushBack(&list, 5);
  List_Print(&list);
  List_pushBack(&list, 4);
  printf("pushed back: %d\n", 4);
  List_Print(&list);
  List_pushFront(&list, 1);
  printf("pushed front: %d\n", 1);
  List_Print(&list);

  Node_ItemType tmp;
  List_popFront(&list, &tmp);
  printf("poped front: %d\n", tmp);
  List_Print(&list);


  List_popBack(&list, &tmp);
  printf("poped back: %d\n", tmp);
  List_Print(&list);


  LIFO_t Uart_LIFO;
  LIFO_Init(&Uart_LIFO, LIFO_Buffer, LIFO_BUFFER_MAX_SIZE);

  int i;
  for(i = 0; i < LIFO_BUFFER_MAX_SIZE; ++i)
  {
    if( LIFO_Add(&Uart_LIFO, i) == LIFO_no_error){
      printf("UART LIFO added : %d\n", i);
    }
  }

  printf("\n===== LIFO contents =====\n");
  LIFO_ItemType tmp;
  for(i = 0; i < LIFO_BUFFER_MAX_SIZE; ++i)
  {
    if (LIFO_Get(&Uart_LIFO, &tmp) == LIFO_no_error){
      printf("UART LIFO removed %d\n", tmp);
    }
  }

  /********************************************************************/
  printf("\n");

  FIFO_t Uart_FIFO;
  FIFO_Init(&Uart_FIFO, FIFO_Buffer, FIFO_BUFFER_MAX_SIZE);

  int i;
  for(i = 0; i < FIFO_BUFFER_MAX_SIZE; ++i)
  {
    if( FIFO_Enqueue(&Uart_FIFO, i) == FIFO_no_error){
      printf("UART FIFO enqueued : %d\n", i);
    }
  }

  FIFO_Print(&Uart_FIFO);

  FIFO_ItemType tmp2;
  if( FIFO_Dequeue(&Uart_FIFO, &tmp2) == FIFO_no_error){
    printf("UART FIFO dequeued : %d\n", tmp2);
  }

  if( FIFO_Dequeue(&Uart_FIFO, &tmp2) == FIFO_no_error){
    printf("UART FIFO dequeued : %d\n", tmp2);
  }
  FIFO_Print(&Uart_FIFO);

  return 0;
}
