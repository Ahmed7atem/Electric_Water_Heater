#ifndef SOURCE_01_MCAL_ADC_INC_ADC_H_
#define SOURCE_01_MCAL_ADC_INC_ADC_H_

#include "Std_Types.h"
#include "Bit_Math.h"
#include "ADC_Types.h"
#include "ADC_Reg.h"

#define REF           					((u8)1<<6)
#define AVCC5V_REF    					((u8)1)
#define INTERNAL_REF  					((u8)3)

#define ADC_LEFT_ADJUST_RESULT   		((u8)1<<5)     //ADC left adjust result

#define ADC_ENABLE				 		((u8)1<<7)     //ADC Enable
#define ADC_START_CONVERSION_BIT_NO     ((u8)6)     	//ADC start conversion
#define ADC_INTERRUPT_ENABLE     		((u8)1<<3)     	//ADC interrupt enable
/*					ADC prescaler			*/
/*ADC frequancy must be between 50KHZ and 200KHZ*/
#define ADCPS_2         (1)
#define ADCPS_4         (2)
#define ADCPS_8         (3)
#define ADCPS_16        (4)
#define ADCPS_32        (5)
#define ADCPS_64        (6)
#define ADCPS_128       (7)

#define ADIF_BIT_NO		(4)


#define ADC_STEP		(4.8f)

void ADC_Init(void);
u16 ADC_Read(adc_Channel_t chnlNo);

#endif /* SOURCE_01_MCAL_ADC_INC_ADC_H_ */


