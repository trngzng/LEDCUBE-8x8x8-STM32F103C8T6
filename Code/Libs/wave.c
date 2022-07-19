/*
 * wave.c
 *
 *  Created on: Jul 19, 2022
 *      Author: phang
 */
#include "wave.h"

#define PI 3.14

const float L = 7; // Bước sóng
const float T = 1; // Chu kỳ
const float A = 3.5; // Biên độ
const float xo = 3.5; // Tọa độ điểm gốc O
const float yo = 3.5;

void WaveCube_Handle()
{

	        uint32_t t = HAL_GetTick(); // Lấy thời gian
	for (uint8_t y = 0; y < 8; y++) // Quét Y
	{
	    for (uint8_t x = 0; x < 8; x++) // Quét X
	    {
//	        float r = sqrt(pow(x - xo, 2) + pow(y - yo, 2)); // Lấy bán kính, Sqrt là căn bậc 2, Pow(x, y) là x mũ y
	        uint8_t z = (uint8_t)(A*cos(2*PI*t/T - 2*PI*sqrt((x - xo)*(x - xo) + (y - yo)*(y - yo))/L) + 3.5); // Lấy cao độ z, 3.5 là vị trí cân bằng
	        DisplayLed(x, y, z);
	    }
	}
}

void WaveCube_Set_State()
{
	clearCube();
	currentEffect = WAVE_EFFECT;
}

