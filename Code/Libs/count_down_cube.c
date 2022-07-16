#include "count_down_cube.h"

digit_t w_number = DIGIT_NINE;
uint8_t layer_countdown = 0, column_countdown[8] = {};
static int direction = 1;
static uint32_t time_start_countdown = 0;
const uint32_t time_do_countdown = 70;
const uint32_t time_per_countdown = 0;
static int i = 0;

void CountDownCube_Handle()
{
	switch (w_number)
	{
		case DIGIT_NINE:
			if (HAL_GetTick() - time_start_countdown >= time_do_countdown)
			{
				if (direction == 1 && (i < 8))  i++;
				if (i > 7) direction = 0;
				if (direction == 0 && (i > 0))  i--;
				if (i == 0)
				{
					direction = 1;
					w_number = DIGIT_EIGHT;
				}
				time_start_countdown = HAL_GetTick();
			}

			DigitNine(i);
		break;

		case DIGIT_EIGHT:
			if (HAL_GetTick() - time_start_countdown >= time_do_countdown)
			{

				if (direction == 1 && (i < 8))  i++;
				if (i > 7) direction = 0;
				if (direction == 0 && (i > 0))  i--;
				if (i == 0)
				{
					direction = 1;
					w_number = DIGIT_SEVEN;
				}
				time_start_countdown = HAL_GetTick();
			}

			DigitEight(i);
		break;

		case DIGIT_SEVEN:
			if (HAL_GetTick() - time_start_countdown >= time_do_countdown)
			{

				if (direction == 1 && (i < 8))  i++;
				if (i > 7) direction = 0;
				if (direction == 0 && (i > 0))  i--;
				if (i == 0)
				{
					direction = 1;
					w_number = DIGIT_SIX;
				}
				time_start_countdown = HAL_GetTick();
			}

			DigitSeven(i);

			break;

		case DIGIT_SIX:
			if (HAL_GetTick() - time_start_countdown >= time_do_countdown)
			{

				if (direction == 1 && (i < 8))  i++;
				if (i > 7) direction = 0;
				if (direction == 0 && (i > 0))  i--;
				if (i == 0)
				{
					direction = 1;
					w_number = DIGIT_FIVE;
				}
				time_start_countdown = HAL_GetTick();
			}

			DigitSix(i);

			break;

		case DIGIT_FIVE:
			if (HAL_GetTick() - time_start_countdown >= time_do_countdown)
			{

				if (direction == 1 && (i < 8))  i++;
				if (i > 7) direction = 0;
				if (direction == 0 && (i > 0))  i--;
				if (i == 0)
				{
					direction = 1;
					w_number = DIGIT_FOUR;
				}
				time_start_countdown = HAL_GetTick();
			}

			DigitFive(i);
			break;

		case DIGIT_FOUR:
			if (HAL_GetTick() - time_start_countdown >= time_do_countdown)
			{

				if (direction == 1 && (i < 8))  i++;
				if (i > 7) direction = 0;
				if (direction == 0 && (i > 0))  i--;
				if (i == 0)
				{
					direction = 1;
					w_number = DIGIT_THREE;
				}
				time_start_countdown = HAL_GetTick();
			}

			DigitFour(i);
			break;

		case DIGIT_THREE:
			if (HAL_GetTick() - time_start_countdown >= time_do_countdown)
			{

				if (direction == 1 && (i < 8))  i++;
				if (i > 7) direction = 0;
				if (direction == 0 && (i > 0))  i--;
				if (i == 0)
				{
					direction = 1;
					w_number = DIGIT_TWO;
				}
				time_start_countdown = HAL_GetTick();
			}

			DigitThree(i);
			break;

		case DIGIT_TWO:
			if (HAL_GetTick() - time_start_countdown >= time_do_countdown)
			{

				if (direction == 1 && (i < 8))  i++;
				if (i > 7) direction = 0;
				if (direction == 0 && (i > 0))  i--;
				if (i == 0)
				{
					direction = 1;
					w_number = DIGIT_ONE;
				}
				time_start_countdown = HAL_GetTick();
			}

			DigitTwo(i);
			break;

		case DIGIT_ONE:
			if (HAL_GetTick() - time_start_countdown >= time_do_countdown)
			{

				if (direction == 1 && (i < 8))  i++;
				if (i > 7) direction = 0;
				if (direction == 0 && (i > 0))  i--;
				if (i == 0)
				{
					direction = 1;
					w_number = DIGIT_ZERO;
				}
				time_start_countdown = HAL_GetTick();
			}

			DigitOne(i);
			break;

		case DIGIT_ZERO:
			if (HAL_GetTick() - time_start_countdown >= time_do_countdown)
			{

				if (direction == 1 && (i < 8))  i++;
				if (i > 7) direction = 0;
				if (direction == 0 && (i > 0))  i--;
				if (i == 0)
				{
					direction = 1;
					w_number = DIGIT_NINE;
				}
				time_start_countdown = HAL_GetTick();
			}

			DigitZero(i);
			break;

		default:
			break;
	}
}

void CountDownCube_Set_Sate()
{
	currentEffect = COUNT_DOWN_CUBE;
	w_number = DIGIT_NINE;
	direction = 1;
	for (int j = 0; j < 8; j++)
	{
		column_countdown[j] = 0;
	}
}

void DigitNine(int i)
{
	column_countdown[i] = 0x7e;
	TransmitData(column_countdown, 0x81);

	column_countdown[i] = 0xc3;
	TransmitData(column_countdown, 0x60);

	column_countdown[i] = 0x03;
	TransmitData(column_countdown, 0x0c);

	column_countdown[i] = 0xff;
	TransmitData(column_countdown, 0x02);

	column_countdown[i] = 0x7f;
	TransmitData(column_countdown, 0x10);

	column_countdown[i] = 0;
}

void DigitEight(int i)
{
	column_countdown[i] = 0xc3;
	TransmitData(column_countdown, 0x66);

	column_countdown[i] = 0x7e;
	TransmitData(column_countdown, 0x99);

	column_countdown[i] = 0;
}

void DigitSeven(int i)
{
	column_countdown[i] = 0xff;
	TransmitData(column_countdown, 0xc0);

	for (int j = 0; j < 6; j++)
	{
		column_countdown[i] = 0x03 << j;
		TransmitData(column_countdown, 0x20 >> j);
	}

	column_countdown[i] = 0;
}

void DigitSix(int i)
{
	column_countdown[i] = 0xff;
	TransmitData(column_countdown, 0x42);

	column_countdown[i] = 0xc3;
	TransmitData(column_countdown, 0x0c);

	column_countdown[i] = 0x7f;
	TransmitData(column_countdown, 0x80);

	column_countdown[i] = 0xc0;
	TransmitData(column_countdown, 0x20);

	column_countdown[i] = 0xfe;
	TransmitData(column_countdown, 0x10);

	column_countdown[i] = 0x7e;
	TransmitData(column_countdown, 0x01);

	column_countdown[i] = 0;
}

void DigitFive(int i)
{

	column_countdown[i] = 0xff;
	TransmitData(column_countdown,0xc0);

	column_countdown[i] = 0xc0;
	TransmitData(column_countdown,0x20);

	column_countdown[i] = 0xfe;
	TransmitData(column_countdown,0x10);

	column_countdown[i] = 0x03;
	TransmitData(column_countdown,0x0c);

	column_countdown[i] = 0x83;
	TransmitData(column_countdown,0x02);

	column_countdown[i] = 0x7e;
	TransmitData(column_countdown,0x01);

	column_countdown[i] = 0;
}

void DigitFour(int i)
{
	column_countdown[i] = 0x06;
	TransmitData(column_countdown, 0xf3);

	column_countdown[i] = 0xff;
	TransmitData(column_countdown, 0x0c);

	for (int j = 0; j < 4; j++)
	{
	column_countdown[i] = 0x08 << j;
	layer_countdown = 0x80 >> j;
	TransmitData(column_countdown, layer_countdown);
	}

	column_countdown[i] = 0;
}

void DigitThree(int i)
{
	column_countdown[i] = 0x7e;
	TransmitData(column_countdown, 0x81);

	column_countdown[i] = 0xe7;
	TransmitData(column_countdown, 0x42);

	column_countdown[i] = 0xc3;
	TransmitData(column_countdown, 0x24);

	column_countdown[i] = 0x06;
	TransmitData(column_countdown, 0x18);

	column_countdown[i] = 0;
}

void DigitTwo(int i)
{
	column_countdown[i] = 0x7e;
	TransmitData(column_countdown, 0x80);

	column_countdown[i] = 0xc3;
	TransmitData(column_countdown, 0x40);

	column_countdown[i] = 0x83;
	TransmitData(column_countdown, 0x20);

	column_countdown[i] = 0x0e;
	TransmitData(column_countdown, 0x10);

	column_countdown[i] = 0x1c;
	TransmitData(column_countdown, 0x08);

	column_countdown[i] = 0x70;
	TransmitData(column_countdown, 0x04);

	column_countdown[i] = 0xff;
	TransmitData(column_countdown, 0x03);

	column_countdown[i] = 0;
}

void DigitOne(int i)
{
	column_countdown[i] = 0xff;
	TransmitData(column_countdown, 0x01);

	column_countdown[i] = 0x98;
	TransmitData(column_countdown, 0x08);

	column_countdown[i] = 0xd8;
	TransmitData(column_countdown, 0x10);

	column_countdown[i] = 0x78;
	TransmitData(column_countdown, 0x20);

	column_countdown[i] = 0x38;
	TransmitData(column_countdown, 0x40);

	column_countdown[i] = 0x18;
	TransmitData(column_countdown, 0x86);

	column_countdown[i] = 0;
}

void DigitZero(int i)
{
	column_countdown[i] = 0x3c;
	TransmitData(column_countdown, 0x81);

	column_countdown[i] = 0x66;
	TransmitData(column_countdown, 0x42);

	column_countdown[i] = 0xc3;
	TransmitData(column_countdown, 0x3c);

	column_countdown[i] = 0;
}
