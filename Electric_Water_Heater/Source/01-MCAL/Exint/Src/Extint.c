/*
 * Extint.c
 *
 *  Created on: Sep 6, 2022
 *      Author: Khaled
 */
#include "Extint.h"
#include "Bit_Math.h"

void EXTINT_vidEnableExtInterrupt(extint_interrupt_t interrupt,extint_edge_t edge)
{
	switch (interrupt)
	{
	case EXT_INT0:
	{
		switch (edge)
		{
		case RISING_EDGE:
		{
			SET_BIT(EXTINT_MCUCR_REG,1);
			SET_BIT(EXTINT_MCUCR_REG,0);
			break;
		}
		case FALLING_EDGE:
		{
			SET_BIT(EXTINT_MCUCR_REG,1);
			CLEAR_BIT(EXTINT_MCUCR_REG,0);
			break;
		}
		case LOW_VALUE:
		{
			CLEAR_BIT(EXTINT_MCUCR_REG,1);
			CLEAR_BIT(EXTINT_MCUCR_REG,0);
			break;
		}
		case BOTH_EDGES:
		{
			CLEAR_BIT(EXTINT_MCUCR_REG,1);
			SET_BIT(EXTINT_MCUCR_REG,0);
			break;
		}
		}
		SET_BIT(EXTINT_GICR_REG,6);
		break;
	}
	case EXT_INT1:
	{
		switch (edge)
		{
		case RISING_EDGE:
		{
			SET_BIT(EXTINT_MCUCR_REG,1);
			SET_BIT(EXTINT_MCUCR_REG,0);
			break;
		}
		case FALLING_EDGE:
		{
			SET_BIT(EXTINT_MCUCR_REG,1);
			CLEAR_BIT(EXTINT_MCUCR_REG,0);
			break;
		}
		case LOW_VALUE:
		{
			CLEAR_BIT(EXTINT_MCUCR_REG,0);
			CLEAR_BIT(EXTINT_MCUCR_REG,1);
			break;
		}
		case BOTH_EDGES:
		{
			CLEAR_BIT(EXTINT_MCUCR_REG,1);
			SET_BIT(EXTINT_MCUCR_REG,0);
			break;
		}
		}
		SET_BIT(EXTINT_GICR_REG,7);
		break;
	}
	case EXT_INT2:
	{
		switch(edge)
		{
		case RISING_EDGE:
		{
			SET_BIT(EXTINT_MCUCSR_REG,6);
			break;
		}
		case FALLING_EDGE:
		{
			CLEAR_BIT(EXTINT_MCUCSR_REG,6);
			break;
		}
		case BOTH_EDGES:
		{
			break;
		}
		case LOW_VALUE:
		{
			break;
		}
		}
		SET_BIT(EXTINT_GICR_REG,5);
		break;
	}
	}
}
