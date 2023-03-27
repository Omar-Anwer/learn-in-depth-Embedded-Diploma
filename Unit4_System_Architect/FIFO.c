/*
 * FIFO.c
 *
 *  Created on: Mar 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */

#include "FIFO.h"

FIFO_Status_e FIFO_Init(FIFO_t* const fifo, FIFO_ItemType* const buffer, const unsigned int length)
{
  if(buffer == 0)
  {
    return FIFO_null;
  }
  else
  {
    fifo->count = 0;
    fifo->length = length;
    fifo->base = buffer;
    fifo->tail = buffer;
    fifo->head = buffer;

    return FIFO_no_error;
  }

}

FIFO_Status_e FIFO_IsFull(FIFO_t* const fifo)
{
  if( (!fifo->base) || (!fifo->tail) || (!fifo->head) )
  {

    return FIFO_null;
  }

  if(fifo->count == fifo->length)
  {
    return FIFO_isFull;
  }
  else
  {
    return FIFO_no_error;
  }

}

FIFO_Status_e FIFO_Enqueue(FIFO_t* const fifo, const FIFO_ItemType item)
{
  /* Check if FIFO is valid */
  if( (!fifo->base) || (!fifo->head) || (!fifo->tail) )
  {
    return FIFO_null;
  }

  /* Check if FIFO is full */
  if(FIFO_IsFull(fifo) == FIFO_isFull)
  {
    return FIFO_isFull;
  }
  else
  {
    *(fifo->head) = item;
    fifo->count++;

    /* Circular FIFO */
    if(fifo->head == (fifo->base + (fifo->length * sizeof(FIFO_ItemType) ) ) )
    {
      fifo->head = fifo->base;
    }
    else
    {
      fifo->head++;
    }

    return FIFO_no_error;
  }
}

FIFO_Status_e FIFO_Dequeue(FIFO_t* const fifo, FIFO_ItemType* const item)
{

  /* Check if FIFO is valid */
  if( (!fifo->base) || (!fifo->head) || (!fifo->tail) )
  {

    return FIFO_null;
  }
  /* Check if FIFO is empty */
  if(fifo->count == 0)
  {
    return FIFO_isEmpty;
  }
  else
  {
    *item = *(fifo->tail);
    fifo->count--;

    if(fifo->tail == (fifo->base + (fifo->length * sizeof(FIFO_ItemType) ) ))
    {
      fifo->tail = fifo->base;
    }
    else
    {
      fifo->tail++;
    }
    return FIFO_no_error;

  }
}

void FIFO_Print(FIFO_t* const fifo)
{
  if(fifo->count == 0)
  {
    printf("FIFO is full! \n");
  }
  else
  {
    printf("\n===== FIFO contents =====\n");
    FIFO_ItemType* item = fifo->tail;
    int i;
    for(i = 0; i < fifo->count; i++)
    {
      printf("FIFO element: %d \n", *item);
      item++;
    }
    printf("=========================\n");
  }
}
