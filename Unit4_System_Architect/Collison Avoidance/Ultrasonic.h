/*
 * Ultrasonic.h
 *
 *  Created on: Mar 30, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "state.h"

//define states
enum{
  ULTRASONIC_BUSY,
}ULTRASONIC_STATE_ID;


STATE_DEFINE(ULTRASONIC_BUSY);

//State pointer to functions
extern void (*ULTRASONIC_STATE) (void);

 void Ultrasonic_Init(void);
 void Ultrasonic_GetDistance(void);





#endif /* ULTRASONIC_H_ */
