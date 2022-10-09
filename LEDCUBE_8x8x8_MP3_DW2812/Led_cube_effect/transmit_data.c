#include "transmit_data.h"

extern SPI_HandleTypeDef hspi1;

void TransmitData(uint8_t column_data[], uint8_t layer_data) //ok
{

	uint8_t dataOut[9];
	dataOut[0] = layer_data;
	for (int i = 1; i < 9; i++)
	{
		dataOut[i] = column_data[i-1];
	}
	HAL_GPIO_WritePin(LATCH_PIN_GPIO_Port, LATCH_PIN_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1,dataOut, 9, 100);
	HAL_GPIO_WritePin(LATCH_PIN_GPIO_Port, LATCH_PIN_Pin, GPIO_PIN_SET);
}
