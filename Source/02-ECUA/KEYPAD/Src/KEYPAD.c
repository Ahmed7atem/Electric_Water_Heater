/*
 * KEYPAD.c
 *
 *  Created on: Sep 2, 2022
 *      Author: Khaled
 */
#include "KEYPAD.h"
#include "Dio.h"

u8 Keypad_Layout[4][4]= {
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
	    {'*','0','#','D'}
};

void KEYPAD_vidInit(void)
{
	/* Configure Rows Pins as input */
	Dio_vidconfigChannel(DIO_PORTD,DIO_PIN6,DIO_INPUT);
	Dio_vidconfigChannel(DIO_PORTD,DIO_PIN3,DIO_INPUT);
	Dio_vidconfigChannel(DIO_PORTC,DIO_PIN2,DIO_INPUT);
	Dio_vidconfigChannel(DIO_PORTC,DIO_PIN3,DIO_INPUT);


	/* Configure Columns pins as output */
	Dio_vidconfigChannel(DIO_PORTC,DIO_PIN4,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTC,DIO_PIN5,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTC,DIO_PIN6,DIO_OUTPUT);
	Dio_vidconfigChannel(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);


	/* Initialize output Columns as High */
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN4,DIO_HIGH);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN5,DIO_HIGH);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN6,DIO_HIGH);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN7,DIO_HIGH);
}

kp_row_t KEYPAD_udtGetRow(void)
{
	kp_row_t loc_row = KP_NOROW;

	if (Dio_udtreadChannel(DIO_PORTD,DIO_PIN6) == DIO_HIGH)
	{
		loc_row = KP_ROW0;
	}
	else if (Dio_udtreadChannel(DIO_PORTD,DIO_PIN3) == DIO_HIGH)
	{
		loc_row = KP_ROW1;
	}
	else if (Dio_udtreadChannel(DIO_PORTC,DIO_PIN2) == DIO_HIGH)
	{
		loc_row = KP_ROW2;
	}
	else if (Dio_udtreadChannel(DIO_PORTC,DIO_PIN3) == DIO_HIGH)
	{
		loc_row = KP_ROW3;
	}
	return loc_row;
}

kp_col_t KEYPAD_udtGetColumn(kp_row_t current_row)
{
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN4,DIO_HIGH);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN5,DIO_LOW);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN6,DIO_LOW);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);


	if (KEYPAD_udtGetRow() == current_row)
	{
		return KP_COLUMN0;
	}

	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN4,DIO_LOW);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN5,DIO_HIGH);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN6,DIO_LOW);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);


	if (KEYPAD_udtGetRow() == current_row)
	{
		return KP_COLUMN1;
	}

	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN4,DIO_LOW);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN5,DIO_LOW);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN6,DIO_HIGH);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);


	if (KEYPAD_udtGetRow() == current_row)
	{
		return KP_COLUMN2;
	}

	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN4,DIO_LOW);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN5,DIO_LOW);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN6,DIO_LOW);
	Dio_vidwriteChannel(DIO_PORTC,DIO_PIN7,DIO_HIGH);


	if (KEYPAD_udtGetRow() == current_row)
	{
		return KP_COLUMN3;
	}
	return KP_NOCOLUMN;
}

boolean KEYPAD_udtIsPressed()
{
	if (
			(Dio_udtreadChannel(DIO_PORTD,DIO_PIN6) == DIO_HIGH) ||
			(Dio_udtreadChannel(DIO_PORTD,DIO_PIN3) == DIO_HIGH) ||
			(Dio_udtreadChannel(DIO_PORTC,DIO_PIN2) == DIO_HIGH) ||
			(Dio_udtreadChannel(DIO_PORTC,DIO_PIN3) == DIO_HIGH)
		)

	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

u8 KEYPAD_u8GetKeyPressed(void)
{
	kp_row_t loc_row = KP_NOROW;
	kp_col_t loc_column = KP_NOCOLUMN;
	u8 loc_button = 0xFF;

	KEYPAD_vidInit();

	if (KEYPAD_udtIsPressed() == TRUE)
	{
		loc_row = KEYPAD_udtGetRow();
		loc_column = KEYPAD_udtGetColumn(loc_row);
		loc_button = Keypad_Layout[loc_row][loc_column];
	}
	return loc_button;
}
