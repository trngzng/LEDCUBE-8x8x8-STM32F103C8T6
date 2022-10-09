/*
 * random_rain_cube.c
 *
 *  Created on: 11 Jul 2022
 *      Author: phang
 */
#include "random_rain_cube.h"
static uint8_t x,y,z;
uint32_t time_rain = 0;

void RandomRainCube_Handle()
{
	if (HAL_GetTick() - 10 >= 50)
	{
			if (z == 0) z = 7;
			else z--;
			time_rain = HAL_GetTick();
	}

	for (uint8_t n = 0; n < 10; n++)
	{
		if (z == 7)
		{
			x = rand() % 8;
			y = rand() % 8;
		}

		DisplayLed(x, y, z);
	}

}

void RandomRainCube_Set_State()
{
	srand(HAL_GetTick());
	z = 7;
	currentEffect = RANDOM_RAIN_CUBE;
}
