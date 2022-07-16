#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "main.h"

typedef struct
{
	uint8_t Btn_current;
	uint8_t Btn_last;
	uint8_t Btn_filter;
	uint8_t Is_debouncing;
	uint8_t Is_press_timeout;
	uint32_t Time_debounce;
	uint32_t Time_start_press;
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
} Btn_Typedef;

void Btn_Handle(Btn_Typedef *BtnX);
void Btn_Init(Btn_Typedef *BtnX, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif
