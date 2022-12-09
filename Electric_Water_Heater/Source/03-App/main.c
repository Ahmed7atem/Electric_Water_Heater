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

#define MIN_TEMP (35)
#define MAX_TEMP (75)

xTaskHandle setTempControlDecrease=NULL;
xTaskHandle setTempControlIncrease=NULL;
xTaskHandle displayTask=NULL;
xTaskHandle tempControlTask=NULL;
xTaskHandle sensorTask=NULL;
xTimerHandle modeControlTimer=NULL;
int setTemp=60;
int mode = 0;
int avgTemp = 0;

void Main_decreaseSetTempTask()
{
	while (1)
		{

			if (BUTTON_udtbuttonStatus(BUTTON1)==PRESSED)
			{
				if (mode==0)
				{
					vTaskDelay(250);
					mode=1;
					xTimerReset(modeControlTimer,0);
				}
				else if (mode==1)
				{
					vTaskDelay(250);
					if (setTemp>MIN_TEMP)
					{
						setTemp=setTemp-5;
						// H_AT24C16A_Void_EEPROMWrite(num,5,145);
					}
					xTimerReset(modeControlTimer,0);
				}
			}
			vTaskDelay(100);
		}
}
void Main_increaseSetTempTask()
{
	while (1)
	{
		if (BUTTON_udtbuttonStatus(BUTTON0)==PRESSED)
		{
			if (mode==0)
			{
				vTaskDelay(250);
				mode=1;
				xTimerReset(modeControlTimer,0);
			}
			else if (mode==1)
			{
				vTaskDelay(250);
				if (setTemp<MAX_TEMP)
				{
					setTemp=setTemp+5;
					// H_AT24C16A_Void_EEPROMWrite(num,5,145);
				}
				xTimerReset(modeControlTimer,0);
			}
		}
		vTaskDelay(100);
	}
}
void Main_displayModeTask()
{
		while (1)
		{
			if (mode == 1)
			{
				SSD_vidDelayDisplay(setTemp,1000);
				SSD_vidDisableSSD();
				vTaskDelay(1000);
			}
			else if (mode==0)
			{
				SSD_viddispNum(avgTemp);
			}
		}
}

void Main_heaterCoolerControlTask()
{
	while (1)
	{
		if (avgTemp<(setTemp-5))
		{
			RELAY_vidrelayOn();
			LED_vidledOn(LED0);
			LED_vidledOff(LED1);
			vTaskDelay(1000);
			LED_vidledOff(LED0);
		}
		else if (avgTemp>(setTemp+5))
		{
			RELAY_vidrelayOff();
			LED_vidledOff(LED0);
			LED_vidledOn(LED1);
		}
		vTaskDelay(1000);
	}
}
int Main_tempSensorTask(void)
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


	setTempControlDecrease=xTaskCreate(Main_decreaseSetTempTask,"task1",85,NULL,2,setTempControlDecrease);
	setTempControlIncrease=xTaskCreate(Main_increaseSetTempTask,"task2",85,NULL,2,setTempControlIncrease);
	displayTask=xTaskCreate(Main_displayModeTask,"task3",85,NULL,4,displayTask);
	tempControlTask=xTaskCreate(Main_heaterCoolerControlTask,"task4",85,NULL,1,tempControlTask);
	sensorTask=xTaskCreate(Main_tempSensorTask,"task5",85,NULL,5,sensorTask);
	modeControlTimer = xTimerCreate("Timer",5000,pdFALSE,( void * ) 1,vTimerCallback);
	xTimerStart(modeControlTimer,0);


	vTaskStartScheduler();
}

