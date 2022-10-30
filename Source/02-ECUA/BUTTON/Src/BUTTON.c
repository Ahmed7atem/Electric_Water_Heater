/*
 * BUTTON.c
 *
 *  Created on: Aug 27, 2022
 *      Author: Khaled
 */
#include "BUTTON.h"

void BUTTON_vidbuttonInit(void)
{
	Dio_vidconfigChannel(DIO_PORTB,DIO_PIN0,DIO_INPUT);
	Dio_vidconfigChannel(DIO_PORTD,DIO_PIN6,DIO_INPUT);
	Dio_vidconfigChannel(DIO_PORTD,DIO_PIN2,DIO_INPUT);
}

button_butStatus_t BUTTON_udtbuttonStatus(button_buttonId_t button)
{
	switch(button)
	{
	case BUTTON0:
	{
		if (Dio_udtreadChannel(DIO_PORTB,DIO_PIN0) == 1)
		{
			return PRESSED;
		}
		else
		{
			return RELEASED;
		}
	}
	case BUTTON1:
	{
		if (Dio_udtreadChannel(DIO_PORTD,DIO_PIN6) == 1)
		{
			return PRESSED;
		}
		else
		{
			return RELEASED;
		}
	}
	case BUTTON2:
	{
		if (Dio_udtreadChannel(DIO_PORTD,DIO_PIN2)== 1)
		{
			return PRESSED;
		}
		else
		{
			return RELEASED;
		}
	}
	}
	return RELEASED;
}
