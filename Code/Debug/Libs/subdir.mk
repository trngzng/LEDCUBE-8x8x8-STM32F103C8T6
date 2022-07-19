################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/around_edge_cube.c \
../Libs/button.c \
../Libs/clear_cube.c \
../Libs/count_down_cube.c \
../Libs/diagonal_cube.c \
../Libs/display_led.c \
../Libs/grow_shrink_cube.c \
../Libs/led_cube_handle.c \
../Libs/light_cube.c \
../Libs/plane_cube.c \
../Libs/propeller.c \
../Libs/random_rain_cube.c \
../Libs/spiral_cube.c \
../Libs/transmit_data.c \
../Libs/uart.c \
../Libs/wave.c 

OBJS += \
./Libs/around_edge_cube.o \
./Libs/button.o \
./Libs/clear_cube.o \
./Libs/count_down_cube.o \
./Libs/diagonal_cube.o \
./Libs/display_led.o \
./Libs/grow_shrink_cube.o \
./Libs/led_cube_handle.o \
./Libs/light_cube.o \
./Libs/plane_cube.o \
./Libs/propeller.o \
./Libs/random_rain_cube.o \
./Libs/spiral_cube.o \
./Libs/transmit_data.o \
./Libs/uart.o \
./Libs/wave.o 

C_DEPS += \
./Libs/around_edge_cube.d \
./Libs/button.d \
./Libs/clear_cube.d \
./Libs/count_down_cube.d \
./Libs/diagonal_cube.d \
./Libs/display_led.d \
./Libs/grow_shrink_cube.d \
./Libs/led_cube_handle.d \
./Libs/light_cube.d \
./Libs/plane_cube.d \
./Libs/propeller.d \
./Libs/random_rain_cube.d \
./Libs/spiral_cube.d \
./Libs/transmit_data.d \
./Libs/uart.d \
./Libs/wave.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/%.o Libs/%.su: ../Libs/%.c Libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/LED CUBE 8x8x8/LED CUBE 8x8x8 STM32F103C8T6/Code/Libs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs

clean-Libs:
	-$(RM) ./Libs/around_edge_cube.d ./Libs/around_edge_cube.o ./Libs/around_edge_cube.su ./Libs/button.d ./Libs/button.o ./Libs/button.su ./Libs/clear_cube.d ./Libs/clear_cube.o ./Libs/clear_cube.su ./Libs/count_down_cube.d ./Libs/count_down_cube.o ./Libs/count_down_cube.su ./Libs/diagonal_cube.d ./Libs/diagonal_cube.o ./Libs/diagonal_cube.su ./Libs/display_led.d ./Libs/display_led.o ./Libs/display_led.su ./Libs/grow_shrink_cube.d ./Libs/grow_shrink_cube.o ./Libs/grow_shrink_cube.su ./Libs/led_cube_handle.d ./Libs/led_cube_handle.o ./Libs/led_cube_handle.su ./Libs/light_cube.d ./Libs/light_cube.o ./Libs/light_cube.su ./Libs/plane_cube.d ./Libs/plane_cube.o ./Libs/plane_cube.su ./Libs/propeller.d ./Libs/propeller.o ./Libs/propeller.su ./Libs/random_rain_cube.d ./Libs/random_rain_cube.o ./Libs/random_rain_cube.su ./Libs/spiral_cube.d ./Libs/spiral_cube.o ./Libs/spiral_cube.su ./Libs/transmit_data.d ./Libs/transmit_data.o ./Libs/transmit_data.su ./Libs/uart.d ./Libs/uart.o ./Libs/uart.su ./Libs/wave.d ./Libs/wave.o ./Libs/wave.su

.PHONY: clean-Libs

