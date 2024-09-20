################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/HAL/MKL46Z_HAL_GPIO.c \
../Sources/HAL/MKL46Z_HAL_PORT.c \
../Sources/HAL/MKL46Z_HAL_SIM.c \
../Sources/HAL/MKL46Z_HAL_UART0.c 

OBJS += \
./Sources/HAL/MKL46Z_HAL_GPIO.o \
./Sources/HAL/MKL46Z_HAL_PORT.o \
./Sources/HAL/MKL46Z_HAL_SIM.o \
./Sources/HAL/MKL46Z_HAL_UART0.o 

C_DEPS += \
./Sources/HAL/MKL46Z_HAL_GPIO.d \
./Sources/HAL/MKL46Z_HAL_PORT.d \
./Sources/HAL/MKL46Z_HAL_SIM.d \
./Sources/HAL/MKL46Z_HAL_UART0.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/HAL/%.o: ../Sources/HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


