/*
 * SSD.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Khaled
 */

#include "SSD.h"
#include "Dio.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include <util/delay.h>

void SSD_vidssdInit(void)
{
	Dio_vidconfigChannel(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);

	Dio_vidconfigChannel(DIO_PORTA,DIO_PIN4,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);
}
void SSD_viddispNum(u8 num)
{
	u8 loc_firstDigit =  (num/10)<<4;
	u8 loc_secondDigit = (num%10)<<4;

	/* Enable SSD1 */
	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN1,DIO_HIGH);
	/* Disable SSD2 */
	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN2,DIO_LOW);
	/* Write first digit */
	Dio_vidwriteChannelGroup(DIO_PORTA,loc_secondDigit,SSD_MASK);

	vTaskDelay(10);

	/* Enable SSD2 */
	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN2,DIO_HIGH);
	/* Disable SSD1 */
	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN1,DIO_LOW);
	/* Write second digit */
	Dio_vidwriteChannelGroup(DIO_PORTA,loc_firstDigit,SSD_MASK);

	vTaskDelay(10);
}

void SSD_vidDisableSSD(void)
{
	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN2,DIO_LOW);
	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN1,DIO_LOW);
}

void SSD_vidDelayDisplay(u8 num,u16 delay)
{
	u16 counter;
	u16 real_delay = delay*0.049;
	for (counter = 0; counter < real_delay;counter++)
	{
		SSD_viddispNum(num);
	}
}
