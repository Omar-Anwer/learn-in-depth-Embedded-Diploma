/*
 * FIFO.h
 *
 *  Created on: Mar 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef FIFO_H_
#define FIFO_H_


typedef int FIFO_ItemType;

typedef struct{
    unsigned int length;
    unsigned int count;
    FIFO_ItemType* base;
    FIFO_ItemType* tail;
    FIFO_ItemType* head;
}FIFO_t;

typedef enum{
  FIFO_no_error,
  FIFO_isEmpty,
  FIFO_isFull,
  FIFO_null
}FIFO_Status_e;

FIFO_Status_e FIFO_Init(FIFO_t* const fifo, FIFO_ItemType* const buffer, const unsigned int length);

FIFO_Status_e FIFO_IsFull(FIFO_t* const fifo);

FIFO_Status_e FIFO_Enqueue(FIFO_t* const fifo, const FIFO_ItemType item);

FIFO_Status_e FIFO_Dequeue(FIFO_t* const fifo, FIFO_ItemType* const item);

#endif /* FIFO_H_ */
