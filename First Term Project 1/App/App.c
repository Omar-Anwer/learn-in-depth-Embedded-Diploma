/*
 * App.c
 *
 *  Created on: Apr 5, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */

#include "App.h"
#include "Alarm.h"
#include "Pressure_Sensor.h"

volatile int g_pressureVal = 0U;
const int pressure_Threshold = 20U; /* 20 bar*/


/* state ptr to function*/
void (*PRESSURE_DETECTION_STATE) (void);

/* define states */
enum
{
  PRESSURE_DETECTION,
}PRESSURE_DETECTION_STATE_ID;

STATE_DEFINE(PRESSURE_DETECTION)
{
  PRESSURE_DETECTION_STATE_ID = PRESSURE_DETECTION;

  if(g_pressureVal > pressure_Threshold)
  {
      StartAlarm();
      Delay(ALARM_TIME_PERIOD);
      StopAlarm();
  }
  else
  {
    /**/
  }

}
