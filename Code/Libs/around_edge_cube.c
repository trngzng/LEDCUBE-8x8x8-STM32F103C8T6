#include "around_edge_cube.h"

uint8_t layer_around_edge, column_around_edge[8];
position_cube position_layer;

void AroundEdgeCube_Handle()
{
	for (int i = 0; i < 8; i++)
	{
		column_around_edge[i] = 0;
	}
	layer_around_edge = 0;
	switch (position_layer) {
		case TOP_N_BOTTOM_CUBE:
			layer_around_edge = 0x81;
			column_around_edge[0] = column_around_edge[7] = 0xff;
			for (int i = 1; i < 7; i++)
			{
				column_around_edge[i] = 0x81;
			}
			TransmitData(column_around_edge, layer_around_edge);
			position_layer = MIDDLE_CUBE;
			break;
		case MIDDLE_CUBE:
			layer_around_edge = 0x7e;
			column_around_edge[0] = column_around_edge[7] = 0x81;
			for (int i = 1; i < 7; i++)
			{
				column_around_edge[i] = 0;
			}
			TransmitData(column_around_edge, layer_around_edge);
			position_layer = TOP_N_BOTTOM_CUBE;
			break;
		default:
			break;
	}
}

void AroundEdgeCube_Set_State()
{
	currentEffect = AROUND_EDGE_CUBE;
	layer_around_edge = 0;
	for (int i = 0; i < 8; i++)
	{
		column_around_edge[i] = 0;
	}
}
