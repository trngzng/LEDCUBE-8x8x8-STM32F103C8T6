################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Button/button.c 

OBJS += \
./Button/button.o 

C_DEPS += \
./Button/button.d 


# Each subdirectory must supply rules for building sources it contributes
Button/%.o Button/%.su: ../Button/%.c Button/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/BTL_TKHTN/LEDCUBE_8x8x8_MP3_DW2812/Led_cube_effect" -I"E:/BTL_TKHTN/LEDCUBE_8x8x8_MP3_DW2812/Button" -I"E:/BTL_TKHTN/LEDCUBE_8x8x8_MP3_DW2812/Timer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Button

clean-Button:
	-$(RM) ./Button/button.d ./Button/button.o ./Button/button.su

.PHONY: clean-Button

