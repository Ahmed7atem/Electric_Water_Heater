################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Source/OS/src/subdir.mk
-include Source/03-App/subdir.mk
-include Source/02-ECUA/SSD/Src/subdir.mk
-include Source/02-ECUA/RELAY/Src/subdir.mk
-include Source/02-ECUA/LM35/Src/subdir.mk
-include Source/02-ECUA/LED/Src/subdir.mk
-include Source/02-ECUA/LCD/Src/subdir.mk
-include Source/02-ECUA/KEYPAD/Src/subdir.mk
-include Source/02-ECUA/I2c/subdir.mk
-include Source/02-ECUA/BUZZER/Src/subdir.mk
-include Source/02-ECUA/BUTTON/Src/subdir.mk
-include Source/01-MCAL/UART/Src/subdir.mk
-include Source/01-MCAL/SPI/Src/subdir.mk
-include Source/01-MCAL/Gint/Src/subdir.mk
-include Source/01-MCAL/Exint/Src/subdir.mk
-include Source/01-MCAL/EEPROM/Src/subdir.mk
-include Source/01-MCAL/Dio/Src/subdir.mk
-include Source/01-MCAL/ADC/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Electric_Water_Heater.lss \

FLASH_IMAGE += \
Electric_Water_Heater.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Electric_Water_Heater.elf secondary-outputs

# Tool invocations
Electric_Water_Heater.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Electric_Water_Heater.map -mmcu=atmega32 -o "Electric_Water_Heater.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Electric_Water_Heater.lss: Electric_Water_Heater.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Electric_Water_Heater.elf  >"Electric_Water_Heater.lss"
	@echo 'Finished building: $@'
	@echo ' '

Electric_Water_Heater.hex: Electric_Water_Heater.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Electric_Water_Heater.elf  "Electric_Water_Heater.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Electric_Water_Heater.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Electric_Water_Heater.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Electric_Water_Heater.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
