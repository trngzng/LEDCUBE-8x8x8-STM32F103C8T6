#ifndef _GROW_SHRINK_CUBE_H_
#define _GROW_SHRINK_CUBE_H_

#include "main.h"
#include "led_cube_handle.h"
#include "transmit_data.h"

typedef enum
{
	TWO_X_TWO_CUBE,
	FOUR_X_FOUR_CUBE,
	SIX_X_SIX_CUBE,
	EIGHT_X_EIGHT_CUBE,
} SizeCube_t;

void GrowShrinkCube_Handle();
void GrowShrinkCube_Set_State();

#endif
