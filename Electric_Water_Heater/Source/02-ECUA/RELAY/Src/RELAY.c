/*
 * RELAY.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Khaled
 */
#include "RELAY.h"

void RELAY_vidrelayInit(void)
{
	Dio_vidconfigChannel(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
}

void RELAY_vidrelayOn(void)
{
	Dio_vidwriteChannel(DIO_PORTA,DIO_PIN2,DIO_HIGH);
}

void RELAY_vidrelayOff(void)
{
	Dio_vidwriteChannel(DIO_PORTA,DIO_PIN2,DIO_LOW);
}
