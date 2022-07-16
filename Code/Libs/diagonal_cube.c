#include "diagonal_cube.h"

size_layer_t size_layer;
static uint8_t layer_diagonal, column_diagonal[8];
static uint32_t time_start = 0;
const uint32_t time_todo_diagonal = 150;

void DiagonalCube_Handle()
{

	switch (size_layer)
	{
		case SMALLEST:
			if (HAL_GetTick() - time_start >= time_todo_diagonal)
			{
				layer_diagonal = 0x18;
				for (int i = 3; i < 5; i++)
				{
					column_diagonal[i] = 0x18;
				}
				TransmitData(column_diagonal, layer_diagonal);
				for (int i = 0; i < 8; i++)
				{
					column_diagonal[i] = 0;
				}
				size_layer = MEDIUM;
				time_start = HAL_GetTick();
			}
			break;
		case MEDIUM:
			if (HAL_GetTick() - time_start >= time_todo_diagonal)
			{
				layer_diagonal = 0x24;
				for (int i = 2; i < 6; i++)
				{
					column_diagonal[i] = 0x3c;
				}
				TransmitData(column_diagonal, layer_diagonal);
				for (int i = 0; i < 8; i++)
				{
					column_diagonal[i] = 0;
				}
				size_layer = LARGE;
				time_start = HAL_GetTick();
			}
			break;
		case LARGE:
			if (HAL_GetTick() - time_start >= time_todo_diagonal)
			{
				layer_diagonal = 0x42;
				for (int i = 1; i < 7; i++)
				{
					column_diagonal[i] = 0x7e;
				}
				TransmitData(column_diagonal, layer_diagonal);
				for (int i = 0; i < 8; i++)
				{
					column_diagonal[i] = 0;
				}
				size_layer = LARGEST;
				time_start = HAL_GetTick();
			}
			break;
		case LARGEST:
			if (HAL_GetTick() - time_start >= time_todo_diagonal)
			{
				layer_diagonal= 0x81;
				for (int i = 0; i < 8; i++)
				{
					column_diagonal[i] = 0xff;
				}
				TransmitData(column_diagonal, layer_diagonal);
				for (int i = 0; i < 8; i++)
				{
					column_diagonal[i] = 0;
				}
				size_layer = SMALLEST;
				time_start = HAL_GetTick();
			}
			break;
		default:
			break;
	}
}

void DiagonalCube_Set_State()
{
	currentEffect = DIAGONAL_CUBE;
	for (int j = 0; j < 8; j++)
	{
		column_diagonal[j] = 0;
	}
	layer_diagonal = 0;
	size_layer = LARGEST;
}
