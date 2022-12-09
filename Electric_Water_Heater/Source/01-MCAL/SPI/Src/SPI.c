/*
 * SPI.c
 *
 *  Created on: Oct 6, 2022
 *      Author: Khaled
 */
#include "SPI.h"

void SPI_vidMasterInit(void)
{
	/*	configure SPI MOSI Pin as output	*/
	Dio_vidconfigChannel(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);
	/*	configure SPI SS Pin as output	*/
	Dio_vidconfigChannel(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
	/*	configure SPI SCK Pin as output	*/
	Dio_vidconfigChannel(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);
	/*	configure SPI MISO Pin as input	*/
	Dio_vidconfigChannel(DIO_PORTB, DIO_PIN6, DIO_INPUT);
	/*	initialize SPI SS pin with HIGH (No slave selected) */
	Dio_vidwriteChannel(DIO_PORTB, DIO_PIN4, DIO_HIGH);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT);
	/*	enable SPI Module in Master mode	*/
	SET_BIT(SPI_SPCR_REG,SPI_MSTR_BIT);
	/*	set SCK frequency by F_CPU/16	*/
	/*	Set SPI Speed	1MHZ*/
	SPI_SPCR_REG |= SPI_SCK_FREQ_FCPU_DIV_16;
}

void SPI_vidSlaveInit(void)
{
	/*	configure SPI MOSI Pin as input	*/
	Dio_vidconfigChannel(DIO_PORTB, DIO_PIN5, DIO_INPUT);
	/*	configure SPI SS Pin as input	*/
	Dio_vidconfigChannel(DIO_PORTB, DIO_PIN4, DIO_INPUT);
	/*	configure SPI SCK Pin as input	*/
	Dio_vidconfigChannel(DIO_PORTB, DIO_PIN7, DIO_INPUT);
	/*	configure SPI MISO Pin as output	*/
	Dio_vidconfigChannel(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT);
	/*	enable SPI Module in Slave mode	*/
	CLEAR_BIT(SPI_SPCR_REG,SPI_MSTR_BIT);
}

void SPI_MasterWrite(u8 data)
{
	u8 loc_flush_byte;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/
	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT) == 0)
	{
		;
	}
		/*	flush the data register	*/
	loc_flush_byte = SPI_SPDR_REG;
}

u8 SPI_u8MasterRead(void)
{
	u8 loc_dummy_byte=0xFF;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = loc_dummy_byte;
	/*	wait until byte received	*/
	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT) == 0)
	{
		;
	}
		/*	read the data register	*/
	return SPI_SPDR_REG;
}

u8 SPI_u8MasterTranseve(u8 data)
{
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/
	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT) == 0)
	{
		;
	}
	/*	flush the data register	*/
	return SPI_SPDR_REG;
}

u8 SPI_u8SlaveRead(void)
{
	/*	wait until byte received	*/
	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT) == 0)
	{
		;
	}
		/*	read the data register	*/
	return SPI_SPDR_REG;
}

void SPI_vidSlaveWrite(u8 data)
{
	SPI_SPDR_REG = data;
}
