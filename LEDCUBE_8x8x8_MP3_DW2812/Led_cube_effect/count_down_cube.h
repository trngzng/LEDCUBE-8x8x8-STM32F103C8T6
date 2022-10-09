#ifndef _COUNT_DOWN_CUBE_H_
#define _COUNT_DOWN_CUBE_H_

#include "main.h"
#include "transmit_data.h"
#include "led_cube_handle.h"

typedef enum
{
	DIGIT_ZERO,
	DIGIT_ONE,
	DIGIT_TWO,
	DIGIT_THREE,
	DIGIT_FOUR,
	DIGIT_FIVE,
	DIGIT_SIX,
	DIGIT_SEVEN,
	DIGIT_EIGHT,
	DIGIT_NINE

} digit_t;

void CountDownCube_Handle();
void CountDownCube_Set_Sate();
void DigitNine(int i);
void DigitEight(int i);
void DigitSeven(int i);
void DigitSix(int i);
void DigitFive(int i1);
void DigitFour(int i);
void DigitThree(int i);
void DigitTwo(int i);
void DigitOne(int i);
void DigitZero(int i);

#endif
