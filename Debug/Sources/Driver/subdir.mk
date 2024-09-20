################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Driver/MKL46Z_Driver_GPIO.c \
../Sources/Driver/MKL46Z_Driver_PORT.c \
../Sources/Driver/MKL46Z_Driver_SIM.c \
../Sources/Driver/MKL46Z_Driver_UART0.c 

OBJS += \
./Sources/Driver/MKL46Z_Driver_GPIO.o \
./Sources/Driver/MKL46Z_Driver_PORT.o \
./Sources/Driver/MKL46Z_Driver_SIM.o \
./Sources/Driver/MKL46Z_Driver_UART0.o 

C_DEPS += \
./Sources/Driver/MKL46Z_Driver_GPIO.d \
./Sources/Driver/MKL46Z_Driver_PORT.d \
./Sources/Driver/MKL46Z_Driver_SIM.d \
./Sources/Driver/MKL46Z_Driver_UART0.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Driver/%.o: ../Sources/Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


