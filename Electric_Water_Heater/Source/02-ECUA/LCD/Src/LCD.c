/*
 * LCD.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Khaled
 */
#include "LCD.h"
#include "Dio.h"
#include <util/delay.h>
#include <stdio.h>

static void LCD_vidEnablePulse(void)
{
	/* Send Enable Pulse */
	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN3,DIO_HIGH);
	_delay_us(1);
	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN3,DIO_LOW);
	_delay_ms(2);
}

void LCD_vidInit(void)
{
	/* Configure control pins as output */
	Dio_vidconfigChannel(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);

	/* Configure data pins as output */
	Dio_vidconfigChannel(DIO_PORTA,DIO_PIN4,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);

	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN2,DIO_LOW);

	_delay_ms(15);
	LCD_vidCmd(0x03);
	_delay_ms(5);
	LCD_vidCmd(0x03);
	_delay_us(100);
	LCD_vidCmd(0x03);
	LCD_vidCmd(0x02);
	LCD_vidCmd(LCD_4BIT_MODE);

	u8 customChar[] = {
	  0b01110,
	  0b01010,
	  0b11111,
	  0b11111,
	  0b10001,
	  0b11111,
	  0b10101,
	  0b11011
	};

	u8 counter;

	for (counter = 0; counter<8;counter++)
	{

		LCD_vidCmd(LCD_CGRAM_START_ADDRESS + counter);
		LCD_vidDisplayChar(customChar[counter]);
	}
	LCD_vidRowColumn(0,0);
}

void LCD_vidDisplayChar(u8 chr)
{
	u8 loc_MSB = (chr & ~LCD_MASK);
	u8 loc_LSB = (chr << 4);

	/* RS = 1 */
	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN1,DIO_HIGH);
	/* Write MSB to LCD */
	Dio_vidwriteChannelGroup(DIO_PORTA,loc_MSB,LCD_MASK);
	/* Send Enable Pulse */
	LCD_vidEnablePulse();


	/* Write LSB to LCD */
	Dio_vidwriteChannelGroup(DIO_PORTA,loc_LSB,LCD_MASK);
	/* Send Enable Pulse */
	LCD_vidEnablePulse();
}

void LCD_vidDisplayWord(u8 *word)
{
	while (*word != '\0')
	{
		LCD_vidDisplayChar(*word);
		word++;
	}
}

void LCD_vidCmd(lcd_Cmd_t cmd)
{
	u8 loc_MSB = (cmd & ~LCD_MASK);
	u8 loc_LSB = (cmd << 4);

	Dio_vidwriteChannel(DIO_PORTB,DIO_PIN1,DIO_LOW);

	/* Write MSB to LCD */
	Dio_vidwriteChannelGroup(DIO_PORTA,loc_MSB,LCD_MASK);
	/* Send Enable Pulse */
	LCD_vidEnablePulse();


	/* Write LSB to LCD */
	Dio_vidwriteChannelGroup(DIO_PORTA,loc_LSB,LCD_MASK);
	/* Send Enable Pulse */
	LCD_vidEnablePulse();
}

void LCD_vidRowColumn(u8 row,u8 column)
{
	switch (row)
	{
	case 0:
	{
		LCD_vidCmd(0x80 + column);
		break;
	}
	case 1:
	{
		LCD_vidCmd(0xC0 + column);
		break;
	}
	}
}

void LCD_vidDisplayInt(u32 num)
{
	u8 buffer[10];
	sprintf(buffer,"%d",num);
	LCD_vidDisplayWord(buffer);
}

void LCD_vidDisplayFloat(f64 num)
{
	f64 buffer[10];
	sprintf(buffer,"%f",num);
	LCD_vidDisplayWord(buffer);
}
