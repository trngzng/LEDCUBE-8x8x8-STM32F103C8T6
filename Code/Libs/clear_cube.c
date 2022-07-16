#include "clear_cube.h"
#include "main.h"
#include "transmit_data.h"

void clearCube()
{
	uint8_t column[8], layer;
	layer = 0x00;
	for (int i = 0; i < 8; i ++)
	{
		column[i] = 0x00;
	}
	TransmitData(column, layer);
}
