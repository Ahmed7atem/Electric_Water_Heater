/*
 * I2c.c
 *
 * Created: 10/18/2022 12:00:47 PM
 *  Author: Moumen
 */
#include "I2c.h"


/*

void M_I2c_Init(void)
{

	#if I2CMODE == I2C_MASTER
	TWBR =12; // TO MAKE FSCL = 400 KH
	#elif I2CMODE == I2C_SLAVE
	//TWAR = ((SlAVE_ADDRESS << 1) | GENERAL_CALL); // to make slave address = 1 and disable the general call
	TWAR = 0b00000010; //to select slave address = 1 , and disable gen call
	#endif


	Set_Bit(TWCR,2); // ENABLE I2C CIRCUIT


}



void M_I2c_StartCondition(void)
{
	Set_Bit(TWCR,5);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	while ((TWSR & 0xF8) != START_ACK);
}
void M_I2c_SendSlaveAddressWrite(u8 Local_u8_Address)
{

	TWDR = (Local_u8_Address << 1);
	Clear_Bit(TWCR,5);

	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);

	H_Led_On(LED1);
	while ((TWSR & 0xF8) != SLAVE_AD_AND_WR_ACK);
	H_Led_On(LED0);
}
void M_I2c_SendSlaveAddressRead(u8 Local_u8_Address)
{
	TWDR = ((Local_u8_Address << 1) | 1);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	while ((TWSR & 0xF8) != SLAVE_AD_AND_RD_ACK);
}
void M_I2c_SendByte(u8 Local_u8_Data)
{
	TWDR = Local_u8_Data;
	Clear_Bit(TWCR,5);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	while ((TWSR & 0xF8) != WR_BYTE_ACK);
}
u8   M_I2c_ReadByte(void)
{

	Clear_Bit(TWCR,5);
	Clear_Bit(TWCR,4);
	Set_Bit(TWCR,6);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	while ((TWSR & 0xF8) != RD_BYTE_WITH_ACK);
	return TWDR;
}
void M_I2c_RepeatedStart(void)
{
	Set_Bit(TWCR,5);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	while ((TWSR & 0xF8) != REP_START_ACK);
}
void M_I2c_StopCondition(void)
{
	Set_Bit(TWCR,4);
	Set_Bit(TWCR,7);                   // to clear the flag
	//while (Get_Bit(TWCR,7) == 0);
}
void M_I2c_Ack(void)
{
	Set_Bit(TWCR,6);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
}

*/


/*
void M_I2c_Init(void)
{
	#if   TWI_MODE   ==   TWI_MASTER
	TWBR = 12;                      // to select fscl = 400 khz
	#elif TWI_MODE   ==   TWI_SLAVE
	TWAR = 0b00000010;             // to select the slave add. = 1 , and disable general call rec.
	#endif
	Set_Bit(TWCR,2);                // to enable TWI circuit
}
void M_I2c_StartCondition(void)
{
	Set_Bit(TWCR,5);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	while ((TWSR & 0xF8) != START_ACK);
}
void M_I2c_SendSlaveAddressWrite(u8 Local_u8_Address)
{
	TWDR = (Local_u8_Address << 1);
	Clear_Bit(TWCR,5);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	H_Led_On(0);
	while ((TWSR & 0xF8) != SLAVE_AD_AND_WR_ACK);
	H_Led_On(1);
}
void M_I2c_SendSlaveAddressRead(u8 Local_u8_Address)
{
	TWDR = ((Local_u8_Address << 1) | 1);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	while ((TWSR & 0xF8) != SLAVE_AD_AND_RD_ACK);
}
void M_I2c_SendByte(u8 Local_u8_Data)
{
	TWDR = Local_u8_Data;
	Clear_Bit(TWCR,5);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	while ((TWSR & 0xF8) != WR_BYTE_ACK);
}
u8   M_I2c_ReadByte(void)
{
	Clear_Bit(TWCR,5);
	Clear_Bit(TWCR,4);
	Set_Bit(TWCR,6);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	while ((TWSR & 0xF8) != RD_BYTE_WITH_ACK);
	return TWDR;
}
void M_I2c_RepeatedStart(void)
{
	Set_Bit(TWCR,5);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
	while ((TWSR & 0xF8) != REP_START_ACK);
}
void M_I2c_StopCondition(void)
{
	Set_Bit(TWCR,4);
	Set_Bit(TWCR,7);                   // to clear the flag
	//while (GetBit(TWCR,7) == 0);
}
void M_I2c_Ack(void)
{
	Set_Bit(TWCR,6);
	Set_Bit(TWCR,7);                   // to clear the flag
	while (Get_Bit(TWCR,7) == 0);
}
*/


#define TWAR_REG                *(volatile u8*)0x22
#define TWBR_REG                *(volatile u8*)0x20
#define TWCR_REG                *(volatile u8*)0x56
#define TWDR_REG                *(volatile u8*)0x23
#define TWSR_REG                *(volatile u8*)0x21

void M_I2C_Void_I2CInit(void)
{
	#if   I2C_MODE   ==   I2C_MASTER_MODE
	/* TO SELECT F_SCL -> 400 KHZ */
	TWBR_REG = 12;
	#elif I2C_MODE   ==   I2C_SLAVE_MODE
	TWAR_REG = (SLAVE_ADDRESS << 1 ) | GENERAL_CALL_RESPONSE ;
	#endif
	/* TO ENABLE I2C CIRCUIT */
	Set_Bit(TWCR_REG,TWEN_BIT);
}
void M_I2C_Void_I2CStartCondition(void)
{
	Set_Bit(TWCR_REG,TWSTA_BIT);  /* TO MAKE A START CONDITION */
	Set_Bit(TWCR_REG,TWINT_BIT);  /* TO CLEAR THE FLAG */
	while(Get_Bit(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
	while((TWSR_REG & 0xF8) != START_CONDITION_HAS_BEEN_TRANSMITTED);
}
void M_I2C_Void_I2CStopCondition(void)
{
	Set_Bit(TWCR_REG,TWSTO_BIT);  /* TO MAKE A STOP CONDITION */
	Set_Bit(TWCR_REG,TWINT_BIT);  /* TO CLEAR THE FLAG */
	//while(GET_BIT(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
}
void M_I2C_Void_I2CRepeatedStart(void)
{
	Set_Bit(TWCR_REG,TWSTA_BIT);  /* TO CLEAR STA BIT ACCORDING TO TABLE */
	Set_Bit(TWCR_REG,TWINT_BIT);  /* TO CLEAR THE FLAG */
	while(Get_Bit(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
	while((TWSR_REG & 0xF8) != REPEATED_START_CONDITION_HAS_BEEN_TRANSMITTED);
}
void M_I2C_Void_I2CSendSlaveAddressWrite(u8 Copy_U8_Address)
{
	TWDR_REG = Copy_U8_Address << 1;

	Set_Bit(TWCR_REG,TWINT_BIT);  /* TO CLEAR THE FLAG */
	while(Get_Bit(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);

	//while((TWSR_REG*  & 0xF8) != SLAVE_ADDRESS_W_TRANSMITTED_ACK_REC);

}
void M_I2C_Void_I2CSendSlaveAddressRead(u8 Copy_U8_Address)
{
	TWDR_REG = (Copy_U8_Address << 1) | 1;

	Set_Bit(TWCR_REG,TWINT_BIT);  /* TO CLEAR THE FLAG */
	while(Get_Bit(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
	//while((TWSR_REG & 0xF8) != SLAVE_ADDRESS_R_TRANSMITTED_ACK_REC);

}
#include "Led.h"
void M_I2C_Void_I2CSendByte(u8 Copy_U8_Data)
{
	TWDR_REG = Copy_U8_Data;
	Clear_Bit(TWCR_REG,TWSTA_BIT);  /* TO CLEAR STA BIT ACCORDING TO TABLE */
	Set_Bit(TWCR_REG,TWINT_BIT);  /* TO CLEAR THE FLAG */
	while(Get_Bit(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
	while((TWSR_REG & 0xF8) != BYTE_TRANSMITTED_ACK_REC);
}
u8   M_I2C_Void_I2CReadByte(void)
{
	u8 Local_U8_Data = TWDR_REG;
	Clear_Bit(TWCR_REG,TWSTA_BIT);  /* TO CLEAR STA BIT ACCORDING TO TABLE */
	Set_Bit(TWCR_REG,6);
	Clear_Bit(TWCR_REG,TWSTO_BIT);  /* TO CLEAR STO BIT ACCORDING TO TABLE */
	Set_Bit(TWCR_REG,TWINT_BIT);  /* TO CLEAR THE FLAG */
	while(Get_Bit(TWCR_REG,TWINT_BIT) == I2C_STILL_PROCESSING);
	while((TWSR_REG & 0xF8) != BYTE_REC_ACK_TRANSMITTED);
	return Local_U8_Data;
}
