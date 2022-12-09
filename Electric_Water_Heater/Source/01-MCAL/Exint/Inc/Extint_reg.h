/*
 * Extint_reg.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Khaled
 */

#ifndef SOURCE_01_MCAL_EXINT_INC_EXTINT_REG_H_
#define SOURCE_01_MCAL_EXINT_INC_EXTINT_REG_H_
#include "Std_Types.h"

#define EXTINT_MCUCR_REG		(*(u8*)0x55)
#define EXTINT_MCUCSR_REG		(*(u8*)0x54)
#define EXTINT_GICR_REG			(*(u8*)0x5B)

#endif /* SOURCE_01_MCAL_EXINT_INC_EXTINT_REG_H_ */
