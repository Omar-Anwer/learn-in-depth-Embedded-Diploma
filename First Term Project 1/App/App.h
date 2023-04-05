/*
 * App.h
 *
 *  Created on: Apr 5, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef APP_H_
#define APP_H_

#include "state.h"
#include "driver.h"

#define ONE_SECOND_DELAY        (534000U)
#define ALARM_TIME_PERIOD       (ONE_SECOND_DELAY  * 60)


/* State pointer to functions */
extern void (*PRESSURE_DETECTION_STATE) ();

STATE_DEFINE(PRESSURE_DETECTION);

#endif /* APP_H_ */
