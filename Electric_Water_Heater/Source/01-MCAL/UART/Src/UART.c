/*
 * UART.c
 *
 *  Created on: Oct 3, 2022
 *      Author: Khaled
 */
#include "UART.h"

void USART_Init(u32 baud)
{
	u32 loc_UBBR_val = ((F_OSC/(16*baud))-1);
	/* Set baud rate */
	UART_UBRRH_REG = loc_UBBR_val>>8;
	UART_UBRRL_REG = loc_UBBR_val;
	/* Enable receiver and transmitter */
	UART_UCSRB_REG = (1<<UART_RXEN_BIT)|(1<<UART_TXEN_BIT);
	/* Set frame format: 8data, 2stop bit */
	UART_UCSRC_REG = (1<<UART_URSEL_BIT)|(1<<UART_USBS_BIT)|(3<<UART_UCSZ0_BIT);
}
void USART_TransmitChr(u8 data)
{
	while(CHECK_BIT(UART_UCSRA_REG,UART_UDRE_BIT) == 0)
	{
		;
	}
	UART_UDR_REG = data;
}
void USART_TransmitStr(u8 *str)
{
	while (*str != '\0')
	{
		USART_TransmitChr(*str);
		str++;
	}
}
u8 USART_Recieve_Block(void)
{
	while (CHECK_BIT(UART_UCSRA_REG,UART_RXC_BIT) == 0)
	{
		;
	}
	return UART_UDR_REG;
}
u8 USART_Recieve_NonBlock(void)
{
	if (CHECK_BIT(UART_UCSRA_REG,UART_RXC_BIT) == 1)
	{
		return UART_UDR_REG;
	}
	else
	{
		return 0;
	}
}
void USART_RecieveInterruptEnable(void)
{
	SET_BIT(UART_UCSRB_REG,UART_RXC_INT_BIT);
}
