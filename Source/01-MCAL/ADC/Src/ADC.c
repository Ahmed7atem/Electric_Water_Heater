///*


#include "ADC.h"

void ADC_Init(void)
{
	/* 	Vref = AVCC	*/
	ADC_ADMUX_REG|=(AVCC5V_REF<<6);
	/*	Enable ADC, Prescaler = /128	*/
	ADC_ADCSRA_REG=(ADC_ENABLE)|(ADCPS_128);
}

u16 ADC_Read(adc_Channel_t chnlNo)
{
	u16 result;
	/*	Select Channel	*/
	ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|(chnlNo);
	/*	Start ADC Conversion	*/
	SET_BIT(ADC_ADCSRA_REG,ADC_START_CONVERSION_BIT_NO);
	/*	Wait Until ADC Conversion Finished	*/
	while(CHECK_BIT(ADC_ADCSRA_REG,ADIF_BIT_NO) != 1)
	{
		/*	Do Nothing	*/
	}
	/*	Clear Interrupt Flag To Be Ready For Another Conversion	*/
	SET_BIT(ADC_ADCSRA_REG,ADIF_BIT_NO);
	/*	Read ADC Result	*/
	result=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));
	return result;
}
