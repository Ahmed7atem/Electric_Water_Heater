/*
 * BitMath.h
 *
 * Created: 9/22/2022 7:20:21 PM
 *  Author: Moumen
 */


#ifndef BITMATH_H_
#define BITMATH_H_

#define Set_Bit(reg,bit)    (reg |=(1<<bit))
#define Clear_Bit(reg,bit)  (reg &= ~(1<<bit))
#define Toggle_Bit(reg,bit) (reg ^= (1<<bit))
#define Get_Bit(reg,bit)    ((reg>>bit) & 1)



#endif /* BITMATH_H_ */
