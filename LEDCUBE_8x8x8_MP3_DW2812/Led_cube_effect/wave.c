/*
 * wave.c
 *
 *  Created on: Jul 19, 2022
 *      Author: phang
 */
#include "wave.h"

#define PI 3.14

extern float L; // Bước sóng
extern float T; // Chu kỳ
extern float A; // Biên độ
extern float xo; // Tọa độ điểm gốc O
extern float yo;


void WaveCube_Handle()
{
	L = 7; // Bước sóng
	T = 2000; // Chu kỳ
	A = 3.5; // Biên độ
	xo = 3.5; // Tọa độ điểm gốc O
	yo = 3.5;
	for (uint8_t y = 0; y < 8; y++) // Quét Y
	{
	    for (uint8_t x = 0; x < 8; x++) // Quét X
	    {
	        uint32_t t = HAL_GetTick(); // Lấy thời gian
//	        float r = sqrt(pow(x - xo, 2) + pow(y - yo, 2)); // Lấy bán kính, Sqrt là căn bậc 2, Pow(x, y) là x mũ y
	        uint8_t z = (uint8_t)(A*cos(2*PI*t/T - 2*PI*sqrt((x - xo)*(x - xo) + (y - yo)*(y - yo))/L) + 4); // Lấy cao độ z, 3.5 là vị trí cân bằng
	        DisplayLed(x, y, z);
	    }
	}
}

void WaveCube_Set_State()
{
	clearCube();
	currentEffect = WAVE_EFFECT;
	L = 7; // Bước sóng
	T = 1; // Chu kỳ
	A = 3.5; // Biên độ
	xo = 3.5; // Tọa độ điểm gốc O
	yo = 3.5;
}

