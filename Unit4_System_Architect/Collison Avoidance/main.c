/*
 * main.c
 *
 *  Created on: Dec 19, 2022
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#include "Ultrasonic.h"
#include "Motor.h"
#include "CA.h"


void setup()
{
  Ultrasonic_Init();
  Motor_Init();

  // init states in block
  CA_STATE = STATE(CA_WAITING);
  MOTOR_STATE = STATE(MOTOR_IDLE);
  ULTRASONIC_STATE = STATE(ULTRASONIC_BUSY);

}

int main(void)
{
  setup();

  while(1)
  {
    CA_STATE();
    ULTRASONIC_STATE();
    MOTOR_STATE();

    /* some delay*/
    volatile int delayTime;
    for(delayTime = 0; delayTime < 1000000; delayTime++);

  }
  return 0;
}
