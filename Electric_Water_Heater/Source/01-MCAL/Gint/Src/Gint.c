/*
 * Gint.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Khaled
 */
#include "Gint.h"
#include "Bit_Math.h"

void GINT_vidEnableAllInterrupt(void)
{
	SET_BIT(GINT_SREG_REG,7);
}
void GINT_vidDisableAllInterrupt(void)
{
	CLEAR_BIT(GINT_SREG_REG,7);
}


