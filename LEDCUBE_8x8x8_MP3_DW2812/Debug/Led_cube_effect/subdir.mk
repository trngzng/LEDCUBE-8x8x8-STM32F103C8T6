################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Led_cube_effect/around_edge_cube.c \
../Led_cube_effect/clear_cube.c \
../Led_cube_effect/count_down_cube.c \
../Led_cube_effect/diagonal_cube.c \
../Led_cube_effect/display_led.c \
../Led_cube_effect/fireworks.c \
../Led_cube_effect/grow_shrink_cube.c \
../Led_cube_effect/led_cube_handle.c \
../Led_cube_effect/light_cube.c \
../Led_cube_effect/plane_cube.c \
../Led_cube_effect/random_rain_cube.c \
../Led_cube_effect/sidewaves.c \
../Led_cube_effect/spiral_cube.c \
../Led_cube_effect/transmit_data.c \
../Led_cube_effect/wave.c 

OBJS += \
./Led_cube_effect/around_edge_cube.o \
./Led_cube_effect/clear_cube.o \
./Led_cube_effect/count_down_cube.o \
./Led_cube_effect/diagonal_cube.o \
./Led_cube_effect/display_led.o \
./Led_cube_effect/fireworks.o \
./Led_cube_effect/grow_shrink_cube.o \
./Led_cube_effect/led_cube_handle.o \
./Led_cube_effect/light_cube.o \
./Led_cube_effect/plane_cube.o \
./Led_cube_effect/random_rain_cube.o \
./Led_cube_effect/sidewaves.o \
./Led_cube_effect/spiral_cube.o \
./Led_cube_effect/transmit_data.o \
./Led_cube_effect/wave.o 

C_DEPS += \
./Led_cube_effect/around_edge_cube.d \
./Led_cube_effect/clear_cube.d \
./Led_cube_effect/count_down_cube.d \
./Led_cube_effect/diagonal_cube.d \
./Led_cube_effect/display_led.d \
./Led_cube_effect/fireworks.d \
./Led_cube_effect/grow_shrink_cube.d \
./Led_cube_effect/led_cube_handle.d \
./Led_cube_effect/light_cube.d \
./Led_cube_effect/plane_cube.d \
./Led_cube_effect/random_rain_cube.d \
./Led_cube_effect/sidewaves.d \
./Led_cube_effect/spiral_cube.d \
./Led_cube_effect/transmit_data.d \
./Led_cube_effect/wave.d 


# Each subdirectory must supply rules for building sources it contributes
Led_cube_effect/%.o Led_cube_effect/%.su: ../Led_cube_effect/%.c Led_cube_effect/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/BTL_TKHTN/LEDCUBE_8x8x8_MP3_DW2812/Led_cube_effect" -I"E:/BTL_TKHTN/LEDCUBE_8x8x8_MP3_DW2812/Button" -I"E:/BTL_TKHTN/LEDCUBE_8x8x8_MP3_DW2812/Timer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Led_cube_effect

clean-Led_cube_effect:
	-$(RM) ./Led_cube_effect/around_edge_cube.d ./Led_cube_effect/around_edge_cube.o ./Led_cube_effect/around_edge_cube.su ./Led_cube_effect/clear_cube.d ./Led_cube_effect/clear_cube.o ./Led_cube_effect/clear_cube.su ./Led_cube_effect/count_down_cube.d ./Led_cube_effect/count_down_cube.o ./Led_cube_effect/count_down_cube.su ./Led_cube_effect/diagonal_cube.d ./Led_cube_effect/diagonal_cube.o ./Led_cube_effect/diagonal_cube.su ./Led_cube_effect/display_led.d ./Led_cube_effect/display_led.o ./Led_cube_effect/display_led.su ./Led_cube_effect/fireworks.d ./Led_cube_effect/fireworks.o ./Led_cube_effect/fireworks.su ./Led_cube_effect/grow_shrink_cube.d ./Led_cube_effect/grow_shrink_cube.o ./Led_cube_effect/grow_shrink_cube.su ./Led_cube_effect/led_cube_handle.d ./Led_cube_effect/led_cube_handle.o ./Led_cube_effect/led_cube_handle.su ./Led_cube_effect/light_cube.d ./Led_cube_effect/light_cube.o ./Led_cube_effect/light_cube.su ./Led_cube_effect/plane_cube.d ./Led_cube_effect/plane_cube.o ./Led_cube_effect/plane_cube.su ./Led_cube_effect/random_rain_cube.d ./Led_cube_effect/random_rain_cube.o ./Led_cube_effect/random_rain_cube.su ./Led_cube_effect/sidewaves.d ./Led_cube_effect/sidewaves.o ./Led_cube_effect/sidewaves.su ./Led_cube_effect/spiral_cube.d ./Led_cube_effect/spiral_cube.o ./Led_cube_effect/spiral_cube.su ./Led_cube_effect/transmit_data.d ./Led_cube_effect/transmit_data.o ./Led_cube_effect/transmit_data.su ./Led_cube_effect/wave.d ./Led_cube_effect/wave.o ./Led_cube_effect/wave.su

.PHONY: clean-Led_cube_effect

