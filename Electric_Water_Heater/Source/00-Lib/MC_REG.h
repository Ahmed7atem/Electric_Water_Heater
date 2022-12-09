/*
 * MC_REG.h
 *
 * Created: 9/23/2022 9:05:12 AM
 *  Author: Moumen
 */


#ifndef MC_REG_H_
#define MC_REG_H_

/**********************************DIO_REGISTERS**********************************/

#define PORT_A	(*((volatile u8*)0x3B))
#define DDR_A	(*((volatile u8*)0x3A))
#define PIN_A	(*((volatile u8*)0x39))

#define PORT_B	(*((volatile u8*)0x38))
#define DDR_B	(*((volatile u8*)0x37))
#define PIN_B	(*((volatile u8*)0x36))

#define PORT_C	(*((volatile u8*)0x35))
#define DDR_C	(*((volatile u8*)0x34))
#define PIN_C	(*((volatile u8*)0x33))

#define PORT_D	(*((volatile u8*)0x32))
#define DDR_D	(*((volatile u8*)0x31))
#define PIN_D	(*((volatile u8*)0x30))


/**********************************_EXT_INT_REGISTERS**********************************/

#define MCUCR	(*((volatile u8*)0x55))
#define	GICR	(*((volatile u8*)0x5B))

/**********************************_STATUS_ENABLE_REGISTERS**********************************/

#define SREG	(*((volatile u8*)0x5F))


/**********************************_ADC_REGISTERS**********************************/

#define ADMUX	(*((volatile u8*)0x27))
#define	ADCSRA	(*((volatile u8*)0x26))
#define	ADCL	(*((volatile u8*)0x24))
#define	ADCH	(*((volatile u8*)0x25))
#define ADC_VALUE (*((volatile u16*)0x24)) // de 7araka say3a bast5dmha 3shan a read the entine 10 bits starting from the adcL reg since after it is the ADCH reg and keda keda the initial value of adch is 0 hence mesh hyfr2 law aret el 16 bits kolohm

/**********************************_TIMER0_REGISTERS**********************************/

#define TCNT0	(*((volatile u8*)0x52))
#define	TCCR0	(*((volatile u8*)0x53))
#define	TIMSK	(*((volatile u8*)0x59))
#define OCR0	(*((volatile u8*)0x5C))

/**********************************_TIMER0_REGISTERS**********************************/

#define TCNT1	(*((volatile u16*)0x4C))
#define	TCCR1A	(*((volatile u8*)0x4F))
#define	TCCR1B	(*((volatile u8*)0x4E))
#define OCR1A	(*((volatile u16*)0x4A))
#define OCR1B	(*((volatile u16*)0x48))
#define	ICR1	(*((volatile u16*)0x46))

/**********************************_WDT_REGISTERS**********************************/

#define WDTCR	(*((volatile u8*)0x41))


/**********************************_UART_REGISTERS**********************************/
#define UDR		(*((volatile u8*)0x2C))
#define UCSRA	(*((volatile u8*)0x2B))
#define UCSRB	(*((volatile u8*)0x2A))
#define UCSRC	(*((volatile u8*)0x40))
#define UBRRL	(*((volatile u8*)0x29))
#define UBRRH	(*((volatile u8*)0x40 ))
/********************************************************_SPI_REGISTERS_**********************************/
#define SPCR          *(volatile u8*)0x2D
#define SPDR          *(volatile u8*)0x2F
#define SPSR          *(volatile u8*)0x2E
/********************************************************_I2C_REGISTERS_**********************************/
#define TWBR          *(volatile u8*)0x20
#define TWAR          *(volatile u8*)0x22
#define TWCR          *(volatile u8*)0x56
#define TWDR          *(volatile u8*)0x23
#define TWSR          *(volatile u8*)0x21



#define TWAR_REG                *(volatile u8*)0x22
#define TWBR_REG                *(volatile u8*)0x20
#define TWCR_REG                *(volatile u8*)0x56
#define TWDR_REG                *(volatile u8*)0x23
#define TWSR_REG                *(volatile u8*)0x21


#endif /* MC_REG_H_ */
