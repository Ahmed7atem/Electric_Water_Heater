/*
 * SPI.h
 *
 *  Created on: Oct 6, 2022
 *      Author: Khaled
 */

#ifndef SOURCE_01_MCAL_SPI_INC_SPI_H_
#define SOURCE_01_MCAL_SPI_INC_SPI_H_

#include "SPI_Reg.h"
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Dio.h"

#define SPI_SPE_BIT			(6)
#define SPI_MSTR_BIT		(4)
#define SPI_CPOL_BIT		(3)
#define SPI_SPIF_BIT		(7)

#define SPI_SCK_FREQ_FCPU_DIV_4			(0<<0)
#define SPI_SCK_FREQ_FCPU_DIV_16		(1<<0)
#define SPI_SCK_FREQ_FCPU_DIV_64		(2<<0)
#define SPI_SCK_FREQ_FCPU_DIV_128		(3<<0)

void SPI_vidMasterInit(void);
void SPI_vidSlaveInit(void);
void SPI_MasterWrite(u8 data);
u8 SPI_u8MasterRead(void);
u8 SPI_u8MasterTranseve(u8 data);

u8 SPI_u8SlaveRead(void);
void SPI_vidSlaveWrite(u8 data);

#endif /* SOURCE_01_MCAL_SPI_INC_SPI_H_ */
