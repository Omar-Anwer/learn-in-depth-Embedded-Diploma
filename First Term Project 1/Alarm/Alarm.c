/*
 * Alarm.c
 *
 *  Created on: Apr 4, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#include "Alarm.h"

void Alarm_Init(void)
{
  StopAlarm();
}

void Set_Alarm_actuator(int i)
{
  if (i == 1)
  {
    SET_BIT(GPIOA_ODR,13);
  }
  else if (i == 0)
  {
    RESET_BIT(GPIOA_ODR,13);
  }
}

void StartAlarm(void)
{
  Set_Alarm_actuator(ALARM_ON);
}

void StopAlarm(void)
{
  Set_Alarm_actuator(ALARM_OFF);
}
