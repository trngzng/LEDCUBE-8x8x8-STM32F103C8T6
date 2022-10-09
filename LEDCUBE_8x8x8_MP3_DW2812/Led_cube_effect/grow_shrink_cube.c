#include "grow_shrink_cube.h"

SizeCube_t size_cube;
const uint32_t time_todo2 = 200;
static uint32_t time_start = 0;
uint8_t column_growshrink[4][8];
uint8_t layer_growshrink[4];

void GrowShrinkCube_Handle() //ok
{
	uint8_t temp[8];
	column_growshrink[0][0] = column_growshrink[0][1] = column_growshrink[0][2] = column_growshrink[0][3] = column_growshrink[0][4] = column_growshrink[0][5] = column_growshrink[0][6] = column_growshrink[0][7] = 0xff;
	column_growshrink[1][1] = column_growshrink[1][2] = column_growshrink[1][3] = column_growshrink[1][4] = column_growshrink[1][5] = column_growshrink[1][6] = 0x7e;
    column_growshrink[2][2] = column_growshrink[2][3] = column_growshrink[2][4] = column_growshrink[2][5] = 0x3c;
    column_growshrink[3][3] = column_growshrink[3][4] = 0x18;

    layer_growshrink[0] = 0xff;
    layer_growshrink[1] = 0x7e;
    layer_growshrink[2] = 0x3c;
    layer_growshrink[3] = 0x18;

	switch (size_cube)
	{
		case TWO_X_TWO_CUBE:
			if (HAL_GetTick() - time_start >= time_todo2)
			{
				for (int j = 0; j < 8; j++)
				{
					temp[j] = column_growshrink[3][j];
					TransmitData(temp, layer_growshrink[3]);
				}
				time_start = HAL_GetTick();
				size_cube = FOUR_X_FOUR_CUBE;
			}
			break;
		case FOUR_X_FOUR_CUBE:
			if (HAL_GetTick() - time_start >= time_todo2)
			{
				for (int j = 0; j < 8; j++)
				{
					temp[j] = column_growshrink[2][j];
					TransmitData(temp, layer_growshrink[2]);
				}
				time_start = HAL_GetTick();
				size_cube = SIX_X_SIX_CUBE;
			}
			break;
		case SIX_X_SIX_CUBE:
			if (HAL_GetTick() - time_start >= time_todo2)
			{
				for (int j = 0; j < 8; j++)
				{
					temp[j] = column_growshrink[1][j];
					TransmitData(temp, layer_growshrink[1]);
				}
				time_start = HAL_GetTick();
				size_cube = EIGHT_X_EIGHT_CUBE;
			}
			break;
		case EIGHT_X_EIGHT_CUBE:
			if (HAL_GetTick() - time_start >= time_todo2)
			{
				for (int j = 0; j < 8; j++)
				{
					temp[j] = column_growshrink[0][j];
					TransmitData(temp, layer_growshrink[0]);
				}
				time_start = HAL_GetTick();
				size_cube = TWO_X_TWO_CUBE;
			}
			break;
		default:
			break;
	}
}

void GrowShrinkCube_Set_State()
{
	currentEffect = GROW_SHRINK_CUBE;
	for (int i = 0; i < 4; i++)
	{
		layer_growshrink[i] = 0;
		for (int j = 0; j < 8; j++)
		{
			column_growshrink[i][j] = 0;
		}
	}
	size_cube = EIGHT_X_EIGHT_CUBE;
}
