/*
 * Dio.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Khaled
 */

#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"
#include "Dio_Types.h"
#include "Dio_reg.h"

void Dio_vidconfigChannel(dio_port_t port,dio_pin_t pin,dio_dir_t dir);
void Dio_vidwriteChannel(dio_port_t port,dio_pin_t pin,dio_level_t);
void Dio_vidwriteChannelGroup(dio_port_t port,u8 data,u8 mask);
void Dio_vidflipChannel(dio_port_t port,dio_pin_t pin);
dio_level_t Dio_udtreadChannel(dio_port_t port,dio_pin_t pin);

#endif /* DIO_H_ */
