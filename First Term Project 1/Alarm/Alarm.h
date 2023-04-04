/*
 * Alarm.h
 *
 *  Created on: Apr 4, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */

#ifndef _ALARM_H_
#define _ALARM_H_

#include "driver.h"

#define ALARM_ON                (0U)
#define ALARM_OFF               (1U)
#define ONE_SECOND_DELAY        (500000U)
#define ALARM_TIME_PERIOD       (ONE_SECOND_DELAY  * 60)

void Set_Alarm_actuator(int i);
void Alarm_Init(void);
void StartAlarm(void);
void StopAlarm(void);


#endif
