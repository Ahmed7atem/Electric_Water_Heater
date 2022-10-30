/*
 * EXTINT_Types.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Khaled
 */

#ifndef SOURCE_01_MCAL_EXINT_INC_EXTINT_TYPES_H_
#define SOURCE_01_MCAL_EXINT_INC_EXTINT_TYPES_H_

typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2
}extint_interrupt_t;

typedef enum
{
	RISING_EDGE,
	FALLING_EDGE,
	LOW_VALUE,
	BOTH_EDGES

}extint_edge_t;

#endif /* SOURCE_01_MCAL_EXINT_INC_EXTINT_TYPES_H_ */
