/*
 * Extint.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Khaled
 */

#ifndef SOURCE_01_MCAL_EXINT_INC_EXTINT_H_
#define SOURCE_01_MCAL_EXINT_INC_EXTINT_H_
#include "Extint_Types.h"
#include "Extint_reg.h"

void EXTINT_vidEnableExtInterrupt(extint_interrupt_t interrupt,extint_edge_t edge);

#endif /* SOURCE_01_MCAL_EXINT_INC_EXTINT_H_ */
