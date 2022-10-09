#include "plane_cube.h"

Plane_way_t way_state;
const uint32_t time_todo1 = 100;
static uint8_t way;
static uint32_t timer = 0;
uint8_t layer_plane;
static uint8_t column_plane[8] = {};
static int i = 0;

void PlaneCube_Handle(){
	switch(way_state){
	case OX:
	{
		layer_plane = 0xff;
		if (HAL_GetTick() - timer >= time_todo1)
		{
			if (way)
			{
				column_plane[i] = 0xff;
				TransmitData(column_plane, layer_plane);
				if (column_plane[7] == 0xff) way = 0;
				else i++;
				for (int j = 0; j < 8; j++)
				{
					column_plane[j] = 0;
				}

			} else
			{
				column_plane[i] = 0xff;
				TransmitData(column_plane, layer_plane);
				if (column_plane[0] == 0xff)
					{
						way = 1;
						i = 0;
						way_state = OY;
					}
				else i--;
				for (int j = 0; j < 8; j++)
				{
					column_plane[j] = 0;
				}
			}
			timer = HAL_GetTick();
		}

	}
		break;
	case OY:
	{
		layer_plane = 0xff;
		if (column_plane[0] == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				column_plane[j] = 1;
			}
			TransmitData(column_plane, layer_plane);
			timer = HAL_GetTick();
		}
		if (HAL_GetTick() - timer >= time_todo1)
		{
			if (way)
			{
				for (int j = 0; j < 8; j++)
				{
					column_plane[j] <<= 1;
				}
				TransmitData(column_plane, layer_plane);
				if (column_plane[0] == 0x80) way = 0;
			} else
			{
				for (int j = 0; j < 8; j++)
				{
					column_plane[j] >>= 1;
				}
				TransmitData(column_plane, layer_plane);
				if (column_plane[0] == 0x00)
				{
					for (int j = 0; j < 8; j++)
					{
						column_plane[j] = 0xff;
					}
					layer_plane = 0;
					way = 1;
					way_state = OZ;
				}
			}
			timer = HAL_GetTick();
		}
	}
		break;
	case OZ:
	{
		if(layer_plane == 0)
		{
			layer_plane = 1;
			TransmitData(column_plane, layer_plane);
			timer = HAL_GetTick();
		}
		if(HAL_GetTick() - timer >= time_todo1)
		{
			if(way)
			{
				layer_plane <<= 1;
				TransmitData(column_plane, layer_plane);
				if(layer_plane == 0x80) way = 0;
			} else
			{
				layer_plane >>= 1;
				TransmitData(column_plane, layer_plane);
				if(layer_plane == 0x01)
				{
					for (int j = 0; j < 8; j++)
					{
						column_plane[j] = 0;
					}
					i = 0;
					way = 1;
					way_state = OX;
					layer_plane = 0;
				}
			}
			timer = HAL_GetTick();
		}
	}
		break;
	default:
		break;
	}
}

void PlaneCube_Set_State(){
	currentEffect = SWEEP_ALL_LEDS;
	for (int j = 0; j < 8; j++)
	{
		column_plane[j] = 0;
	}
	i = 0;
	way = 1;
	layer_plane = 0;
	way_state = OX;
}
