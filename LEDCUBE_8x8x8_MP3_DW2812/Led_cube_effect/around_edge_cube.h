#ifndef _AROUND_EDGE_H_
#define _AROUND_EDGE_H_

#include "main.h"
#include "led_cube_handle.h"
#include "transmit_data.h"

typedef enum
{
	TOP_N_BOTTOM_CUBE,
	MIDDLE_CUBE
} position_cube;

void AroundEdgeCube_Handle();
void AroundEdgeCube_Set_State();

#endif
