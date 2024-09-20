################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/App/App_on_off_leds_by_commands.c 

OBJS += \
./Sources/App/App_on_off_leds_by_commands.o 

C_DEPS += \
./Sources/App/App_on_off_leds_by_commands.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/App/%.o: ../Sources/App/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


