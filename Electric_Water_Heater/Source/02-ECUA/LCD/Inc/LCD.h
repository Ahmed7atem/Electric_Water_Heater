/*
 * LCD.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Khaled
 */

#ifndef SOURCE_02_ECUA_LCD_INC_LCD_H_
#define SOURCE_02_ECUA_LCD_INC_LCD_H_
#include "Std_Types.h"
#include "LCD_Types.h"
#define LCD_MASK	(0x0F)

void LCD_vidInit(void);
void LCD_vidDisplayChar(u8 chr);
void LCD_vidDisplayWord(u8 *word);
void LCD_vidCmd(lcd_Cmd_t cmd);
void LCD_vidRowColumn(u8 row,u8 column);
void LCD_vidDisplayInt(u32 num);
void LCD_vidDisplayFloat(f64 num);

#endif /* SOURCE_02_ECUA_LCD_INC_LCD_H_ */
