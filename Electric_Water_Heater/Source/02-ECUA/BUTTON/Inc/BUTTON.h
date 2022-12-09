/*
 * BUTTON.h
 *
 *  Created on: Aug 27, 2022
 *      Author: Khaled
 */

#ifndef SOURCE_02_ECUA_BUTTON_INC_BUTTON_H_
#define SOURCE_02_ECUA_BUTTON_INC_BUTTON_H_

#include "BUTTON_Types.h"
#include "Dio.h"

void BUTTON_vidbuttonInit(void);
button_butStatus_t BUTTON_udtbuttonStatus(button_buttonId_t button);

#endif /* SOURCE_02_ECUA_BUTTON_INC_BUTTON_H_ */
