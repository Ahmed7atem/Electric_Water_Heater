/*
 * KEYPAD.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Khaled
 */

#ifndef SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_H_
#define SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_H_
#include "KEYPAD_Types.h"
#include "Std_Types.h"

void KEYPAD_vidInit(void);
kp_row_t KEYPAD_udtGetRow(void);
kp_col_t KEYPAD_udtGetColumn(kp_row_t current_row);
u8 KEYPAD_u8GetKeyPressed(void);


#endif /* SOURCE_02_ECUA_KEYPAD_INC_KEYPAD_H_ */
