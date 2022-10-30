/*
 * LED.h
 *
 *  Created on: Aug 27, 2022
 *      Author: Khaled
 */

#ifndef SOURCE_02_ECUA_LED_INC_LED_H_
#define SOURCE_02_ECUA_LED_INC_LED_H_

#include "LED_Types.h"

void LED_vidledInit(void);
void LED_vidledOn(led_ledId_t led);
void LED_vidledOff(led_ledId_t led);
void LED_vidledToggle(led_ledId_t led);

#endif /* SOURCE_02_ECUA_LED_INC_LED_H_ */
