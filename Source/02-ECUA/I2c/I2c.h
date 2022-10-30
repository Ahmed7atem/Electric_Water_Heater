/*
 * I2c.h
 *
 * Created: 10/18/2022 12:00:58 PM
 *  Author: Moumen
 */


#ifndef I2C_H_
#define I2C_H_

/***********************************_Includes_	************************/

#include "I2cCfg.h"
#include "Std_Types.h"
#include "MC_REG.h"
#include "BitMath.h"


/*



#define TWI_MASTER              1
#define TWI_SLAVE               2
#define START_ACK                     0x08		// start has been sent
#define REP_START_ACK                 0x10		// repeated start
#define SLAVE_AD_AND_WR_ACK           0x18		// master transmit [ slave address + write request ] ACK
#define SLAVE_AD_AND_RD_ACK           0x40		// master transmit [ slave address + read  request ] ACK
#define WR_BYTE_ACK                   0x28		// master transmit data ACK
#define WR_BYTE_NACK                  0x30		// master transmit data NACK
#define RD_BYTE_WITH_ACK			  0x50		// master received data with  ACK
#define RD_BYTE_WITH_NACK			  0x58		// master received data with NACK
#define SLAVE_ADD_REC_RD_REQ		  0xA8		// slave address received with write request
#define SLAVE_ADD_REC_WR_REQ          0x60		// slave address received with read  request
#define SLAVE_DATA_REC                0x80		// read  byte request received
#define SLAVE_BYTE_TRANSMITTED        0xC0		// write byte request received
*/



/* TWCR BITS */
#define TWINT_BIT                     7
#define TWSTA_BIT                     5
#define TWSTO_BIT                     4
#define TWEN_BIT                      2

#define I2C_MASTER_MODE               1
#define I2C_SLAVE_MODE                2
#define I2C_STILL_PROCESSING          0

#define START_CONDITION_HAS_BEEN_TRANSMITTED                     0x08
#define REPEATED_START_CONDITION_HAS_BEEN_TRANSMITTED            0x10
#define SLAVE_ADDRESS_W_TRANSMITTED_ACK_REC                      0x18
#define SLAVE_ADDRESS_R_TRANSMITTED_ACK_REC                      0x40
#define BYTE_TRANSMITTED_ACK_REC                                 0x28
#define BYTE_REC_ACK_TRANSMITTED                                 0x50
/************************************************_PROTOTYPES_********************************************/
/*
void M_I2c_Init(void);
void M_I2c_StartCondition(void);
void M_I2c_SendSlaveAddressWrite(u8);
void M_I2c_SendSlaveAddressRead(u8);
void M_I2c_SendByte(u8);
u8   M_I2c_ReadByte(void);
void M_I2c_RepeatedStart(void);
void M_I2c_StopCondition(void);
void M_I2c_Ack(void);
*/

void M_I2C_Void_I2CInit(void);
void M_I2C_Void_I2CStartCondition(void);
void M_I2C_Void_I2CStopCondition(void);
void M_I2C_Void_I2CRepeatedStart(void);
void M_I2C_Void_I2CSendSlaveAddressWrite(u8);
void M_I2C_Void_I2CSendSlaveAddressRead(u8);
void M_I2C_Void_I2CSendByte(u8);
u8   M_I2C_Void_I2CReadByte(void);






#endif /* I2C_H_ */
