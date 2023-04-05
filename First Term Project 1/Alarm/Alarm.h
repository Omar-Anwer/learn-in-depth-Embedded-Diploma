/*
 * Alarm.h
 *
 *  Created on: Apr 4, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */

#ifndef ALARM_H_
#define ALARM_H_

#include "state.h"
#include "driver.h"

void Alarm_Init(void);
void StartAlarm(void);
void StopAlarm(void);

/* State pointer to functions */
extern void (*ALARM_STATE) ();

STATE_DEFINE(ALARM_OFF);
STATE_DEFINE(ALARM_ON);
STATE_DEFINE(ALARM_WAITING);



#endif
