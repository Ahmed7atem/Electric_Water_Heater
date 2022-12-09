/*
 * LED.c
 *
 *  Created on: Aug 27, 2022
 *      Author: Khaled
 */
#include "LED.h"
#include "Dio.h"

void LED_vidledInit(void)
{
	Dio_vidconfigChannel(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTC,DIO_PIN2,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTD,DIO_PIN3,DIO_OUTPUT);
}

void LED_vidledOn(led_ledId_t led)
{
	switch(led)
	{
	case LED0:
	{
		Dio_vidwriteChannel(DIO_PORTC,DIO_PIN2,DIO_HIGH);
		break;
	}
	case LED1:
	{
		Dio_vidwriteChannel(DIO_PORTC,DIO_PIN7,DIO_HIGH);
		break;
	}
	case LED2:
	{
		Dio_vidwriteChannel(DIO_PORTD,DIO_PIN3,DIO_HIGH);
		break;
	}
	}
}

void LED_vidledOff(led_ledId_t led)
{
	switch(led)
	{
	case LED0:
	{
		Dio_vidwriteChannel(DIO_PORTC,DIO_PIN2,DIO_LOW);
		break;
	}
	case LED1:
	{
		Dio_vidwriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);
		break;
	}
	case LED2:
	{
		Dio_vidwriteChannel(DIO_PORTD,DIO_PIN3,DIO_LOW);
		break;
	}
	}
}

void LED_vidledToggle(led_ledId_t led)
{
	switch(led)
	{
	case LED0:
	{
		Dio_vidflipChannel(DIO_PORTC,DIO_PIN2);
		break;
	}
	case LED1:
	{
		Dio_vidflipChannel(DIO_PORTC,DIO_PIN7);
		break;
	}
	case LED2:
	{
		Dio_vidflipChannel(DIO_PORTD,DIO_PIN3);
		break;
	}
	}
}
