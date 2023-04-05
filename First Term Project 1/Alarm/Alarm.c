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


/* state ptr to function*/
void (*ALARM_STATE) (void);

/* define states */
enum
{
  ALARM_OFF,
  ALARM_ON,
  ALARM_WAITING
}ALARM_STATE_ID;

STATE_DEFINE(ALARM_WAITING)
{
  ALARM_STATE_ID = ALARM_WAITING;
}

STATE_DEFINE(ALARM_ON)
{
  ALARM_STATE_ID = ALARM_ON;
  Set_Alarm_actuator(ALARM_ON);
  ALARM_STATE = STATE(ALARM_WAITING);
}

STATE_DEFINE(ALARM_OFF)
{
  ALARM_STATE_ID = ALARM_OFF;
  Set_Alarm_actuator(ALARM_OFF);
  ALARM_STATE = STATE(ALARM_WAITING);
}

void Alarm_Init(void)
{
  Set_Alarm_actuator(ALARM_OFF);
}


void StartAlarm(void)
{
  ALARM_STATE = STATE(ALARM_ON);
  ALARM_STATE();
}

void StopAlarm(void)
{
  ALARM_STATE = STATE(ALARM_OFF);
  ALARM_STATE();
}
