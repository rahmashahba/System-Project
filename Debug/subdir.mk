################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_prog.c \
../DCMotor_prog.c \
../DIO_prog.c \
../EXTI_prog.c \
../GIE_prog.c \
../H_Bridge_prog.c \
../KPD_prog.c \
../PORT_prog.c \
../main.c 

OBJS += \
./CLCD_prog.o \
./DCMotor_prog.o \
./DIO_prog.o \
./EXTI_prog.o \
./GIE_prog.o \
./H_Bridge_prog.o \
./KPD_prog.o \
./PORT_prog.o \
./main.o 

C_DEPS += \
./CLCD_prog.d \
./DCMotor_prog.d \
./DIO_prog.d \
./EXTI_prog.d \
./GIE_prog.d \
./H_Bridge_prog.d \
./KPD_prog.d \
./PORT_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


