/*
 * LM35.c
 *
 *  Created on: Sep 9, 2022
 *      Author: manue
 */
#include "LM35.h"
#include "ADC.h"

void Lm35_Init(void)
{
	ADC_Init();
}
f64  H_LM35_Void_LM35Read(void)
{
	 f64 Local_U16_AdcValue = ADC_Read(ADC_CHNL0);
	 f64 temp = ((u32)Local_U16_AdcValue * 500) / 1023;
	 return temp;
}

