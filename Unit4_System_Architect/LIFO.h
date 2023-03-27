/*
 * LIFO.h
 *
 *  Created on: Mar 25, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef LIFO_H_
#define LIFO_H_

typedef int LIFO_ItemType;

typedef struct
{
    unsigned int length;
    unsigned int count;
    LIFO_ItemType* base;
    LIFO_ItemType* top;

}LIFO_t;

typedef enum
{
  LIFO_no_error,
  LIFO_isEmpty,
  LIFO_isFull,
  LIFO_null

}LIFO_Status_e;


LIFO_Status_e LIFO_Init(LIFO_t* lifo, LIFO_ItemType* buffer, unsigned int length);

LIFO_Status_e LIFO_Add(LIFO_t* lifo, LIFO_ItemType item);

LIFO_Status_e LIFO_Get(LIFO_t* lifo, LIFO_ItemType* item);


#endif /* LIFO_H_ */
