################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/02-ECUA/SSD/Src/SSD.c 

OBJS += \
./Source/02-ECUA/SSD/Src/SSD.o 

C_DEPS += \
./Source/02-ECUA/SSD/Src/SSD.d 


# Each subdirectory must supply rules for building sources it contributes
Source/02-ECUA/SSD/Src/%.o: ../Source/02-ECUA/SSD/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\00-Lib" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\I2c" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\I2c" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\ADC\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\Dio\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\EEPROM\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\Exint\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\Gint\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\SPI\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\UART\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\BUTTON\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\BUZZER\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\KEYPAD\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\LCD\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\LED\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\LM35\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\RELAY\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\SSD\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\OS\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


