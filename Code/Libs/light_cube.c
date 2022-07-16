#include "light_cube.h"

void lightCube()
{
	uint8_t column[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
	for (int i = 0;  i < 8; i++)
	{
		TransmitData(column, 0x80 >> i);
	}
}
