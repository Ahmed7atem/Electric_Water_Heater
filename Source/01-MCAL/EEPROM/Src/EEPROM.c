/*
 * EEPROM.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Khaled
 */
#include "EEPROM.h"
/*
 * Eeprom.c
 *
 * Created: 10/18/2022 2:29:15 PM
 *  Author: Moumen
 */
#include <util/delay.h>
#include "EEPROM.h"
#include "I2c.h"


/*
void H_Eeprom_Init(void)
{
	M_I2c_Init();
	_delay_ms(1000); //because the MC is fast
}
void H_Eeprom_Write(u8 Local_u8_Data,u8 Local_u8_PageAddress,u8 Local_u8_ByteAddress)
{
	M_I2c_StartCondition();
	M_I2c_SendSlaveAddressWrite(0x50 | Local_u8_PageAddress);
	M_I2c_SendByte(Local_u8_ByteAddress);
	M_I2c_SendByte(Local_u8_Data);
	M_I2c_StopCondition();
}


u8   H_Eeprom_Read(u8 Local_u8_PageAddress,u8 Local_u8_ByteAddress)
{
	u8 Local_u8_Data = 0;

	M_I2c_StartCondition();

	M_I2c_SendSlaveAddressWrite(0x50 | Local_u8_PageAddress);

	M_I2c_SendByte(Local_u8_ByteAddress);

	M_I2c_RepeatedStart();
	M_I2c_SendSlaveAddressRead(0x50 | Local_u8_PageAddress);
	Local_u8_Data = M_I2c_ReadByte();
	M_I2c_StopCondition();
	return Local_u8_Data;
} */
/*
void H_Eeprom_Init(void)
{
	M_I2c_Init();
	_delay_ms(2000);
}
void H_Eeprom_Write(u8 Local_u8_Data,u8 Local_u8_PageAddress,u8 Local_u8_ByteAddress)
{
	M_I2c_StartCondition();
	M_I2c_SendSlaveAddressWrite(0x50 | Local_u8_PageAddress);
	M_I2c_SendByte(Local_u8_ByteAddress);
	M_I2c_SendByte(Local_u8_Data);
	M_I2c_StopCondition();
}
u8   H_Eeprom_Read(u8 Local_u8_PageAddress,u8 Local_u8_ByteAddress)
{
	u8 Local_u8_Data = 0;
	M_I2c_StartCondition();

	M_I2c_SendSlaveAddressWrite(0x50 | Local_u8_PageAddress);

	M_I2c_SendByte(Local_u8_ByteAddress);
	M_I2c_RepeatedStart();
	M_I2c_SendSlaveAddressRead(0x50 | Local_u8_PageAddress);
	Local_u8_Data = M_I2c_ReadByte();
	M_I2c_StopCondition();
	return Local_u8_Data;
}*/


void H_AT24C16A_Void_EEPROMInit(void)
{
	M_I2C_Void_I2CInit();
	_delay_ms(1000);
}
void H_AT24C16A_Void_EEPROMWrite(u8 Copy_U8_Page,u8 Copy_U8_Byte,u8 Copy_U8_Data)
{
	M_I2C_Void_I2CStartCondition();

	M_I2C_Void_I2CSendSlaveAddressWrite(0x50 | Copy_U8_Page);
	M_I2C_Void_I2CSendByte(Copy_U8_Byte);
	M_I2C_Void_I2CSendByte(Copy_U8_Data);
	M_I2C_Void_I2CStopCondition();
	_delay_ms(500);
}
u8   H_AT24C16A_Void_EEPROMRead(u8 Copy_U8_Page,u8 Copy_U8_Byte)
{
	u8 Local_U8_Reading = 0;
	M_I2C_Void_I2CStartCondition();

	M_I2C_Void_I2CSendSlaveAddressWrite(0x50 | Copy_U8_Page);

	M_I2C_Void_I2CSendByte(Copy_U8_Byte);
	M_I2C_Void_I2CRepeatedStart();
	M_I2C_Void_I2CSendSlaveAddressRead(0x50 | Copy_U8_Page);
	Local_U8_Reading = M_I2C_Void_I2CReadByte();
	M_I2C_Void_I2CStopCondition();
	_delay_ms(500);
	return Local_U8_Reading;
}



