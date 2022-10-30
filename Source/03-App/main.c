/********************************
 * main.c
 *
 *  Created on: Aug 23, 2022
 * 	Author: Khaled
 *********************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Gint.h"
#include "Extint.h"
#include "LED.h"
#include "BUTTON.h"
#include "BUZZER.h"
#include "RELAY.h"
#include "SSD.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "UART.h"
#include "ADC.h"
#include "LM35.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "FreeRTOSConfig.h"
#include "timers.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "EEPROM.h"
#include "LM35.h"
#include "I2c.h"


xTaskHandle task1handler=NULL;
xTaskHandle task2handler=NULL;
xTaskHandle task3handler=NULL;
xTaskHandle task4handler=NULL;
xTaskHandle task5handler=NULL;
xTimerHandle timer1handler=NULL;
int num=60;
int mode = 0;
int avgTemp = 0;

void task1()
{
	while (1)
		{

			if (BUTTON_udtbuttonStatus(BUTTON1)==PRESSED)
			{
				if (mode==0)
				{
					vTaskDelay(250);
					mode=1;
					xTimerReset(timer1handler,0);
				}
				else if (mode==1)
				{
					vTaskDelay(250);
					if (num>25)
					{
						num=num-5;
						// H_AT24C16A_Void_EEPROMWrite(num,5,145);
					}
					xTimerReset(timer1handler,0);
				}
			}
			vTaskDelay(100);
		}
}
void task2()
{
	while (1)
	{
		if (BUTTON_udtbuttonStatus(BUTTON0)==PRESSED)
		{
			if (mode==0)
			{
				vTaskDelay(250);
				mode=1;
				xTimerReset(timer1handler,0);
			}
			else if (mode==1)
			{
				vTaskDelay(250);
				if (num<75)
				{
					num=num+5;
					// H_AT24C16A_Void_EEPROMWrite(num,5,145);
				}
				xTimerReset(timer1handler,0);
			}
		}
		vTaskDelay(100);
	}
}
void task3()
{
		while (1)
		{
			if (mode == 1)
			{
				SSD_vidDelayDisplay(num,1000);
				SSD_vidDisableSSD();
				vTaskDelay(1000);
			}
			else if (mode==0)
			{
				SSD_viddispNum(avgTemp);
			}
		}
}

void task4()
{
	while (1)
	{
		if (avgTemp<(num-5))
		{
			RELAY_vidrelayOn();
			LED_vidledOn(LED0);
			LED_vidledOff(LED1);
			vTaskDelay(1000);
			LED_vidledOff(LED0);
		}
		else if (avgTemp>(num+5))
		{
			RELAY_vidrelayOff();
			LED_vidledOff(LED0);
			LED_vidledOn(LED1);
		}
		vTaskDelay(1000);
	}
}
int task5(void)
{
	u16 temp;
	u8 tempArr[10] = {};

	while (1)
	{
		temp = 0;
		for (u8 i = 0;i < 10;i++)
		{
			tempArr[i] = H_LM35_Void_LM35Read();
			temp = temp + tempArr[i];
			vTaskDelay(100);
		}
		avgTemp = temp/10;
		temp=0;
	}

}


 void vTimerCallback( xTimerHandle xTimer )
 {
	 mode=0;
 }



int main(void)
{
	// H_AT24C16A_Void_EEPROMInit();
	// M_I2C_Void_I2CInit();
	RELAY_vidrelayInit();
	SSD_vidssdInit();
	LED_vidledInit();
	BUTTON_vidbuttonInit();
	ADC_Init();
	// num = H_AT24C16A_Void_EEPROMRead(5,145);


	task1handler=xTaskCreate(task1,"task1",85,NULL,2,task1handler);
	task2handler=xTaskCreate(task2,"task2",85,NULL,2,task2handler);
	task3handler=xTaskCreate(task3,"task3",85,NULL,4,task3handler);
	task4handler=xTaskCreate(task4,"task4",85,NULL,1,task4handler);
	task5handler=xTaskCreate(task5,"task5",85,NULL,5,task5handler);
	timer1handler = xTimerCreate("Timer",5000,pdFALSE,( void * ) 1,vTimerCallback);
	xTimerStart(timer1handler,0);


	vTaskStartScheduler();
}


/*
u8 loc_uartReturn = 0;
ISR(USART_RXC_vect)
{
	loc_uartReturn = UART_UDR_REG;
	if (loc_uartReturn == 'a')
	{
		LED_vidledToggle(LED0);
	}
	else if (loc_uartReturn == 'b')
	{
		LED_vidledToggle(LED1);
	}
}

int main(void)
{
	u8 key;
	KEYPAD_vidInit();
	LCD_vidInit();
	LCD_vidCmd(LCD_CLEAR);
	while (1)
	{
		key = KEYPAD_u8GetKeyPressed();
		_delay_ms(150);
		if (key != 0xFF)
		{
			LCD_vidDisplayChar(key);
		}
	}
	return 0;
} */
