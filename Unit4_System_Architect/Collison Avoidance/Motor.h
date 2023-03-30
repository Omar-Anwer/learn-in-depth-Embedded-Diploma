/*
 * Motor.h
 *
 *  Created on: Mar 30, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef MOTOR_H_
#define MOTOR_H_


#include "state.h"

//define states
enum{
  MOTOR_IDLE,
  MOTOR_BUSY
}MOTOR_STATE_ID;

STATE_DEFINE(MOTOR_IDLE);
STATE_DEFINE(MOTOR_BUSY);

void Motor_Init(void);
void Motor_SetSpeed(int speed);


//State pointer to functions
extern void (*MOTOR_STATE) (void);


#endif /* MOTOR_H_ */
