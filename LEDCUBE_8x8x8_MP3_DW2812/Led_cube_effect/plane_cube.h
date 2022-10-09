#ifndef _PLANE_CUBE_H_
#define _PLANE_CUBE_H_

#include "led_cube_handle.h"
#include "transmit_data.h"

typedef enum{
	OX,
	OY,
	OZ
} Plane_way_t;

void PlaneCube_Handle();
void PlaneCube_Set_State();

#endif
