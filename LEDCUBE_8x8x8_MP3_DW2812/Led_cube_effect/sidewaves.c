/*
 * slidewaves.c
 *
 *  Created on: 20 Jul 2022
 *      Author: phang
 */

#include "sidewaves.h"

#define PI 3.14

const float To = 8000;
const float ro = 1000;
float L; // Bước sóng
float T; // Chu kỳ
float A; // Biên độ
float xo; // Tọa độ điểm gốc O
float yo;
float r;

void SidewavesEffect_Handle()
{
	L = 7; // Bước sóng
	T = 1000; // Chu kỳ
	A = 3.5; // Biên độ
	uint32_t t = HAL_GetTick(); // Lấy thời gian
	xo = ro*cos(2*PI*t/To) + 3.5; // Cho điểm O quay
	yo = ro*sin(2*PI*t/To) + 3.5;
	for (uint8_t y = 0; y < 8; y++) // Quét Y
	{
	    for (uint8_t x = 0; x < 8; x++) // Quét X
	    {
//	        r = sqrt(pow(x - xo, 2) + pow(y - yo, 2)); // Lấy bán kính, Sqrt là căn bậc 2, Pow(x, y) là x mũ y
	        uint8_t z = (uint8_t)(A*cos(2*PI*t/T - 2*PI*sqrt(pow(x - xo, 2) + pow(y - yo, 2))/L) + 4); // Lấy cao độ z, 3.5 là vị trí cân bằng
	        DisplayLed(x, y, z);
	    }
	}
}

void SidewavesEffect_Set_State()
{
	L = 7; // Bước sóng
	T = 1; // Chu kỳ
	A = 3.5; // Biên độ
	currentEffect = SIDE_WAVES_EFFECT;
	clearCube();
}

