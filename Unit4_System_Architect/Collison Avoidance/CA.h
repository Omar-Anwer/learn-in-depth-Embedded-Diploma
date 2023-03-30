/*
 * CA.h
 *
 *  Created on: Dec 19, 2022
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef CA_H_
#define CA_H_

#include "state.h"

//define states
enum{
  CA_WAITING,
  CA_DRIVING
}CA_STATE_ID;

STATE_DEFINE(CA_WAITING);
STATE_DEFINE(CA_DRIVING);

//State pointer to functions
extern void (*CA_STATE) (void);

void checkDistance(void);

#endif /* CA_H_ */
