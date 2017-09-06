################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Buttons.c \
../Sources/Events.c \
../Sources/FIFO.c \
../Sources/LEDs.c \
../Sources/UART.c \
../Sources/main.c \
../Sources/packet.c 

OBJS += \
./Sources/Buttons.o \
./Sources/Events.o \
./Sources/FIFO.o \
./Sources/LEDs.o \
./Sources/UART.o \
./Sources/main.o \
./Sources/packet.o 

C_DEPS += \
./Sources/Buttons.d \
./Sources/Events.d \
./Sources/FIFO.d \
./Sources/LEDs.d \
./Sources/UART.d \
./Sources/main.d \
./Sources/packet.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/macro/Desktop/Old28-8KDSLAB/Lab1 - Final Version/Static_Code/PDD" -I"C:/Users/macro/Desktop/Old28-8KDSLAB/Lab1 - Final Version/Static_Code/IO_Map" -I"C:/Users/macro/Desktop/Old28-8KDSLAB/Lab1 - Final Version/Sources" -I"C:/Users/macro/Desktop/Old28-8KDSLAB/Lab1 - Final Version/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


