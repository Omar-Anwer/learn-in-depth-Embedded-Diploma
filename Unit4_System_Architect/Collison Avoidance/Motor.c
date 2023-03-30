/*
 * Motor.c
 *
 *  Created on: Mar 30, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */

#include "Motor.h"

extern int CA_speed;

/* state ptr to function*/
void (*MOTOR_STATE) (void);


void Motor_Init(void)
{
  CA_speed = 0;
  printf("Motor Init\n");

}

void Motor_SetSpeed(int speed)
{
  CA_speed = speed;
  MOTOR_STATE = STATE(MOTOR_BUSY);
}

STATE_DEFINE(MOTOR_IDLE)
{
  /* State name */
  MOTOR_STATE_ID = MOTOR_IDLE;
  printf("Motor Idle  ---> Speed = %d\n", CA_speed);

}

STATE_DEFINE(MOTOR_BUSY)
{
  /* State name */
  MOTOR_STATE_ID = MOTOR_BUSY;
  printf("Motor Busy  ---> Speed = %d\n", CA_speed);
  //MOTOR_STATE = STATE(MOTOR_IDLE);
}
