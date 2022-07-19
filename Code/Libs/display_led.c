/*
 * display_led.c
 *
 *  Created on: 11 Jul 2022
 *      Author: phang
 */
#include "display_led.h"

uint8_t ICcolumn[8], IClayer;
uint8_t WhichByte, WhichBit, WhichColumn;
uint8_t dataOut[9];
extern SPI_HandleTypeDef hspi1;

void DisplayLed(uint8_t x, uint8_t y, uint8_t  z)
{
	WhichByte = (((z << 6)+(y << 3) + x) >> 3);
	WhichBit = ((z << 6) + (y << 3) + x) - (WhichByte << 3);
	WhichColumn = WhichByte - (z*8);
	if (z == 8) IClayer = 0xff;
	else IClayer = 0x01 <<  z;
	ICcolumn[WhichColumn] = 0x01 << WhichBit;
	dataOut[0] = IClayer;
	for (uint8_t i = 1; i < 9; i++)
	{
		dataOut[i] = ICcolumn[i-1];
	}
	HAL_GPIO_WritePin(LATCH_PIN_GPIO_Port, LATCH_PIN_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1,dataOut, 9, 100);
	HAL_GPIO_WritePin(LATCH_PIN_GPIO_Port, LATCH_PIN_Pin, GPIO_PIN_SET);
	IClayer = 0;
	ICcolumn[WhichColumn] = 0;
}

