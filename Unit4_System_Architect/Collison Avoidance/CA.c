/*
 * CA.c
 *
 *  Created on: Dec 19, 2022
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#include "CA.h"

int CA_speed;
int CA_distance;
int CA_distance_threshold = 50;

extern void Ultrasonic_GetDistance(void);
extern void Motor_SetSpeed(int speed);

/* state ptr to function*/
void (*CA_STATE) (void);


void checkDistance(void)
{
  (CA_distance <= CA_distance_threshold) ? (CA_STATE = STATE(CA_WAITING)) : (CA_STATE = STATE(CA_DRIVING));

}

STATE_DEFINE(CA_WAITING)
{
  /* State name */
  CA_STATE_ID = CA_WAITING;
  printf("-----\"WAITING\"-----\n");

  Ultrasonic_GetDistance();
  Motor_SetSpeed(0);
}

STATE_DEFINE(CA_DRIVING)
{
  /* State name */
  CA_STATE_ID = CA_DRIVING;
  printf("-----\"DRIVING\"-----\n");

  Ultrasonic_GetDistance();
  Motor_SetSpeed(30);
}
