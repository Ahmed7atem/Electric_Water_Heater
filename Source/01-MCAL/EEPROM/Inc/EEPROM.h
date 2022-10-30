/*
 * Eeprom.h
 *
 * Created: 10/18/2022 2:29:32 PM
 *  Author: Moumen
 */


#ifndef EEPROM_H_
#define EEPROM_H_

/*************************************************_INCLUDES_********************************************/

#include "I2c.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/**************************************************_MACROS_*********************************************/

/************************************************_PROTOTYPES_********************************************/
/*void H_Eeprom_Init(void);
void H_Eeprom_Write(u8,u8,u8);
u8   H_Eeprom_Read(u8,u8);
*/
void H_AT24C16A_Void_EEPROMInit(void);
void H_AT24C16A_Void_EEPROMWrite(u8,u8,u8);
u8   H_AT24C16A_Void_EEPROMRead(u8,u8);


#endif /* EEPROM_H_ */
