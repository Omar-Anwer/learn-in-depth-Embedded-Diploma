/*
 * LIFO.c
 *
 *  Created on: Mar 25, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#include "LIFO.h"

LIFO_Status_e LIFO_Init(LIFO_t* lifo, LIFO_ItemType* buffer, unsigned int length)
{
  if(buffer == 0){
    return LIFO_null;
  }
  else
  {
    lifo->base =  (LIFO_ItemType *) buffer;
    lifo->top = (LIFO_ItemType *) buffer;
    lifo->length = length;
    lifo->count = 0;

    return LIFO_no_error;
  }

}

LIFO_Status_e LIFO_Add(LIFO_t* lifo, LIFO_ItemType item)
{
  /* Check if LIFO is valid */
  if(lifo->base == 0 || lifo->top == 0){
    return LIFO_null;
  }

  /* Check if LIFO is full */
  if(lifo->count == lifo->length)
  {
    return LIFO_isFull;
  }
  else
  {
    *(lifo->top) = item;
    lifo->top++;
    lifo->count++;

    return LIFO_no_error;
  }




}

LIFO_Status_e LIFO_Get(LIFO_t* lifo, LIFO_ItemType* item)
{

  /* Check if LIFO is valid */
  if( (!lifo->base) || (!lifo->top) )
  {
    return LIFO_null;
  }

  /*check if LIFO is empty*/
  if(lifo->count == 0)
  {
    return LIFO_isEmpty;
  }
  else
  {
    lifo->top--;
    *item = *(lifo->top);
    lifo->count--;

    return LIFO_no_error;
  }

}
