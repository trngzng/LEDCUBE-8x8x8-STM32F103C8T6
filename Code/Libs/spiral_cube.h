/*
 * spiral_cube.h
 *
 *  Created on: 11 Jul 2022
 *      Author: phang
 */

#ifndef SPIRAL_CUBE_H_
#define SPIRAL_CUBE_H_

#include "led_cube_handle.h"
#include "display_led.h"

typedef enum
{
	ROLL_BIGGEST,
	ROLL_BIGGER,
	ROLL_MEDIUM,
	ROLL_SMALL
} rollSize_t;

typedef enum
{
	CLOCKWISE,
	COUNTER_CLOCKWISE
} directRotate_t;

typedef enum
{
	Y_AXIS_1,
	X_AXIS_1,
	Y_AXIS_2,
	X_AXIS_2,
} axis_t;



void SpiralCube_Handle();
void SpiralCube_Set_State();
void RollBiggestCounterClockWise_Handle();
void RollBiggerCounterClockWise_Handle();
void RollMediumCounterClockWise_Handle();
void RollSmallCounterClockWise_Handle();
void RollBiggestClockWise_Handle();
void RollBiggerClockWise_Handle();
void RollMediumClockWise_Handle();
void RollSmallClockWise_Handle();

#endif /* SPIRAL_CUBE_H_ */
