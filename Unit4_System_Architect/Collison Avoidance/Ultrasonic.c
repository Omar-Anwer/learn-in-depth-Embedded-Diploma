/*
 * Ultrasonic.c
 *
 *  Created on: Mar 30, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#include "Ultrasonic.h"

extern int CA_distance;

/* state ptr to function*/
void (*ULTRASONIC_STATE) (void);


STATE_DEFINE(ULTRASONIC_BUSY)
{
  /* State name */
  ULTRASONIC_STATE_ID = ULTRASONIC_BUSY;
  //Ultrasonic_GetDistance();
}

void Ultrasonic_Init(void)
{
  CA_distance = 0;
  printf("Ultrasonic Init\n");
}

int Ultrasonic_GetDistanceRandom(int min, int max)
{
  /* random number from 45 to 55 */
  return (rand() % (max - min + 1) + min);
}

void Ultrasonic_GetDistance(void)
{
  /* random number from 45 to 55 */
  CA_distance =  Ultrasonic_GetDistanceRandom(45, 55);
  printf("Ultrasonic ---> Distance = %d\n", CA_distance);
  checkDistance();
  ULTRASONIC_STATE = STATE(ULTRASONIC_BUSY);
}
