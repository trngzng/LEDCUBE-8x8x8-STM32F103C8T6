/*
 * spiral_cube.c
 *
 *  Created on: 11 Jul 2022
 *      Author: phang
 */
#include "spiral_cube.h"

rollSize_t rollSize = ROLL_BIGGEST;
axis_t axisDirection = Y_AXIS_1;
directRotate_t directRotate = CLOCKWISE;
static uint8_t x = 0, y = 0;
const uint8_t z = 8;
const uint32_t timePerColumn = 60;
uint32_t timeStart = 0;

void SpiralCube_Handle()
{
	switch (directRotate) {
		case COUNTER_CLOCKWISE:
			switch (rollSize)
			{
				case ROLL_BIGGEST:
					RollBiggestCounterClockWise_Handle();
					break;
				case ROLL_BIGGER:
					RollBiggerCounterClockWise_Handle();
					break;
				case ROLL_MEDIUM:
					RollMediumCounterClockWise_Handle();
					break;
				case ROLL_SMALL:
					RollSmallCounterClockWise_Handle();
					break;
				default:
					break;
			}
			break;
		case CLOCKWISE:
			switch (rollSize)
			{
				case ROLL_BIGGEST:
					RollBiggestClockWise_Handle();
					break;
				case ROLL_BIGGER:
					RollBiggerClockWise_Handle();
					break;
				case ROLL_MEDIUM:
					RollMediumClockWise_Handle();
					break;
				case ROLL_SMALL:
					RollSmallClockWise_Handle();
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

void RollBiggestCounterClockWise_Handle()
{
	switch (axisDirection)
	{
		case Y_AXIS_1:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 7) axisDirection = X_AXIS_1;
				else y++;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_1:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x == 7) axisDirection = Y_AXIS_2;
				else x++;
				timeStart = HAL_GetTick();
			}
			break;

		case Y_AXIS_2:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 0) axisDirection = X_AXIS_2;
				else y--;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_2:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x == 1)
				{
					axisDirection = Y_AXIS_1;
					rollSize = ROLL_BIGGER;
				}
				else x--;
				timeStart = HAL_GetTick();
			}
			break;
		default:
			break;
	}
}

void RollBiggerCounterClockWise_Handle()
{
	switch (axisDirection)
	{
		case Y_AXIS_1:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y  == 6) axisDirection = X_AXIS_1;
				else y++;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_1:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x  == 6) axisDirection = Y_AXIS_2;
				else x++;
				timeStart = HAL_GetTick();
			}
			break;

		case Y_AXIS_2:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y  == 1) axisDirection = X_AXIS_2;
				else y--;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_2:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x  == 2)
				{
					axisDirection = Y_AXIS_1;
					rollSize = ROLL_MEDIUM;
				}
				else x--;
				timeStart = HAL_GetTick();
			}
			break;
		default:
			break;
	}
}

void RollMediumCounterClockWise_Handle()
{
	switch (axisDirection) {
		case Y_AXIS_1:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 5) axisDirection = X_AXIS_1;
				else y++;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_1:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x  == 5) axisDirection = Y_AXIS_2;
				else x++;
				timeStart = HAL_GetTick();
			}
			break;

		case Y_AXIS_2:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 2) axisDirection = X_AXIS_2;
				else y--;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_2:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x  == 3)
				{
					axisDirection = Y_AXIS_1;
					rollSize = ROLL_SMALL;
				}
				else x--;
				timeStart = HAL_GetTick();
			}
			break;

		default:
			break;
	}
}

void RollSmallCounterClockWise_Handle()
{
	switch (axisDirection) {
		case Y_AXIS_1:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 4) axisDirection = X_AXIS_1;
				else y++ ;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_1:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x  == 4) axisDirection = Y_AXIS_2;
				else x++;
				timeStart = HAL_GetTick();
			}
			break;

		case Y_AXIS_2:
			if (HAL_GetTick() - timeStart  >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 3)
				{
					directRotate = CLOCKWISE;
					axisDirection = Y_AXIS_1;
					rollSize = ROLL_BIGGEST;
					y = 0;
					x = 7;
				}
				else y--;
				timeStart = HAL_GetTick();
			}
			break;

		default:
			break;
	}
}

void RollBiggestClockWise_Handle()
{
	switch (axisDirection) {
		case Y_AXIS_1:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 7) axisDirection = X_AXIS_1;
				else y++;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_1:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x == 0) axisDirection = Y_AXIS_2;
				else x--;
				timeStart = HAL_GetTick();
			}
			break;

		case Y_AXIS_2:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 0) axisDirection = X_AXIS_2;
				else y--;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_2:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x == 6)
				{
					rollSize = ROLL_BIGGER;
					axisDirection = Y_AXIS_1;
				}
				else x++;
				timeStart = HAL_GetTick();
			}
			break;
		default:
			break;
	}
}

void RollBiggerClockWise_Handle()
{
	switch (axisDirection) {
		case Y_AXIS_1:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 6) axisDirection = X_AXIS_1;
				else y++;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_1:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x == 1) axisDirection = Y_AXIS_2;
				else x--;
				timeStart = HAL_GetTick();
			}
			break;

		case Y_AXIS_2:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 1) axisDirection = X_AXIS_2;
				else y--;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_2:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x == 5)
				{
					axisDirection = Y_AXIS_1;
					rollSize = ROLL_MEDIUM;
				}
				else x++;
				timeStart = HAL_GetTick();
			}
			break;
		default:
			break;
	}
}

void RollMediumClockWise_Handle()
{
	switch (axisDirection) {
		case Y_AXIS_1:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 5) axisDirection = X_AXIS_1;
				else y++;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_1:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x == 2) axisDirection = Y_AXIS_2;
				else x--;
				timeStart = HAL_GetTick();
			}
			break;

		case Y_AXIS_2:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 2) axisDirection = X_AXIS_2;
				else y--;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_2:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x == 4)
				{
					rollSize = ROLL_SMALL;
					axisDirection = Y_AXIS_1;
				}
				else x++;
				timeStart = HAL_GetTick();
			}
			break;
		default:
			break;
	}
}

void RollSmallClockWise_Handle()
{
	switch (axisDirection) {
		case Y_AXIS_1:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 4) axisDirection = X_AXIS_1;
				else y++;
				timeStart = HAL_GetTick();
			}
			break;

		case X_AXIS_1:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (x == 3) axisDirection = Y_AXIS_2;
				else x--;
				timeStart = HAL_GetTick();
			}
			break;

		case Y_AXIS_2:
			if (HAL_GetTick() - timeStart >= timePerColumn)
			{
				DisplayLed(x, y, z);
				if (y == 3)
				{
					clearCube();
					axisDirection = Y_AXIS_1;
					rollSize = ROLL_BIGGEST;
					x = 0;
					y = 0;
					directRotate = COUNTER_CLOCKWISE;
				}
				else y--;
				timeStart = HAL_GetTick();
			}
			break;

		default:
			break;
	}
}

void SpiralCube_Set_State()
{
	clearCube();
	x = 7;
	y = 0;
	rollSize = ROLL_BIGGEST;
	directRotate = CLOCKWISE;
	axisDirection = Y_AXIS_1;
	currentEffect = SPIRAL_CUBE;
}
