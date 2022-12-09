################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/OS/src/croutine.c \
../Source/OS/src/heap_1.c \
../Source/OS/src/list.c \
../Source/OS/src/port.c \
../Source/OS/src/queue.c \
../Source/OS/src/tasks.c \
../Source/OS/src/timers.c 

OBJS += \
./Source/OS/src/croutine.o \
./Source/OS/src/heap_1.o \
./Source/OS/src/list.o \
./Source/OS/src/port.o \
./Source/OS/src/queue.o \
./Source/OS/src/tasks.o \
./Source/OS/src/timers.o 

C_DEPS += \
./Source/OS/src/croutine.d \
./Source/OS/src/heap_1.d \
./Source/OS/src/list.d \
./Source/OS/src/port.d \
./Source/OS/src/queue.d \
./Source/OS/src/tasks.d \
./Source/OS/src/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Source/OS/src/%.o: ../Source/OS/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\00-Lib" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\I2c" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\I2c" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\ADC\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\Dio\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\EEPROM\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\Exint\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\Gint\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\SPI\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\01-MCAL\UART\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\BUTTON\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\BUZZER\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\KEYPAD\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\LCD\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\LED\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\LM35\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\RELAY\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\02-ECUA\SSD\Inc" -I"C:\Users\Khaled\workspace\Electric_Water_Heater\Source\OS\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


