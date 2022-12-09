/*
 * BUZZER.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Khaled
 */

#include "BUZZER.h"

void BUZZER_vidbuzzerInit(void)
{
	Dio_vidconfigChannel(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);
}

void BUZZER_vidbuzzerOn(void)
{
	Dio_vidwriteChannel(DIO_PORTA,DIO_PIN3,DIO_HIGH);
}

void BUZZER_vidbuzzerOff(void)
{
	Dio_vidwriteChannel(DIO_PORTA,DIO_PIN3,DIO_LOW);
}

void BUZZER_vidbuzzerToggle(void)
{
	Dio_vidflipChannel(DIO_PORTA,DIO_PIN3);
}
