/*
 * SSD.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Khaled
 */

#ifndef SOURCE_02_ECUA_SSD_INC_SSD_H_
#define SOURCE_02_ECUA_SSD_INC_SSD_H_
#include "Std_Types.h"
#define SSD_MASK	(0x0F)
void SSD_vidssdInit(void);
void SSD_viddispNum(u8);
void SSD_vidDelayDisplay(u8 num,u16 delay);
void SSD_vidDisableSSD(void);

#endif /* SOURCE_02_ECUA_SSD_INC_SSD_H_ */
