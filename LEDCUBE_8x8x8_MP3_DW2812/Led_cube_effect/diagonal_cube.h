#ifndef _DIAGONAL_CUBE_
#define _DIAGONAL_CUBE_

#include "main.h"
#include "transmit_data.h"
#include "led_cube_handle.h"

typedef enum
{
	SMALLEST,
	MEDIUM,
	LARGE,
	LARGEST,
} size_layer_t;

void DiagonalCube_Handle();
void DiagonalCube_Set_State();

#endif
