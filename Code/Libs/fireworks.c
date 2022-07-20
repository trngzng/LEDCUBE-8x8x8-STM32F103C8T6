/*
 * fireworks.c
 *
 *  Created on: 20 Jul 2022
 *      Author: phang
 */

#include "fireworks.h"

#define PI 3.14

float G = 18, B = 1.05, v_max = 15;
int n = 40;
float vx[40], vy[40], vz[40];
extern uint8_t xo, yo;
uint8_t zo;
bool state = false;
uint32_t time_ref = 0;

void FireworksEffect_Handle()
{
	RandomO();
	uint32_t t = HAL_GetTick() - time_ref;
	if (!state)
	{
		float z = t*15;
		DisplayLed(xo, yo, (uint8_t)z); // Vẽ pháo hoa đang phóng
		HAL_Delay(0);
		if (z >= zo)
		{
			RandomParticle(); // Tạo ra các phần tử random
			time_ref = HAL_GetTick(); // Đổi thời gian bắt đầu
			state = true; // Chuyển trạng thái sang trạng thái nổ
			}
		}
	else
	{
		bool reset = true; // Kiểm tra xem có reset hay ko
		float t_const = 1 - exp(-B*HAL_GetTick()); // Hằng số thời gian là như nhau
		for (int i = 0; i < n; i++) {
			uint8_t x = (uint8_t)(xo + (vx[i] / B) * t_const);
			uint8_t y = (uint8_t)(yo + (vy[i] / B) * t_const);
			uint8_t z = (uint8_t)(zo + (vy[i] / B + G / (B * B)) * t_const - G * HAL_GetTick() / B);
		if (z >= 0) reset = false; // Chưa reset vì còn điểm trên 0
		if ((x >= 0) && (x <= 7) && (y >= 0) && (y <= 7) && (z >= 0) && (z <= 7)) DisplayLed(x, y, z);
		HAL_Delay(0);
	}
	if (reset)
	{ // Được reset
	RandomO(); // Tạo điểm phóng random
	time_ref = HAL_GetTick(); // Đổi thời gian bắt đầu
	state = false; // Chuyển trạng thái sang trạng thái phóng
	}
	}
}

void RandomO()
{
	srand(HAL_GetTick());
	xo = rand() % 4 + 2;
	yo = rand() % 4 + 2;
	zo = rand() % 2 + 5;
}

void RandomParticle()
{

	for (int i = 0; i < n; i ++)
	{
		srand(HAL_GetTick());
		float v = (float)rand() / v_max;
		float pol = (float)rand() / (PI / 2); // Góc cực
		float azi = (float)rand()/(2 * PI); // Góc phương vị((float)rand()/(float)(RAND_MAX)) * a
		vx[i] = v*cos(pol)*cos(azi);
		vy[i] = v*cos(pol)*sin(azi);
		vz[i] = v*sin(pol);
	}
}

void FireworksEffect_Set_State()
{
	clearCube();
	currentEffect = FIREWORKS_EFFECT;
	G = 18;
	B = 1.05;
	v_max = 15;
	n = 40;
}
