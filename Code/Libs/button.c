#include "button.h"



__weak void Btn_press_Callback(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{

}

__weak void Btn_press_short_Callback(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{

}

__weak void Btn_release_Callback(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{

}

__weak void Btn_press_timeout_Callback(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{

}

void Btn_Handle(Btn_Typedef *BtnX)
{
//*****************Loc nhieu******************//
	uint8_t status = HAL_GPIO_ReadPin(BtnX->GPIOx, BtnX->GPIO_Pin);
	if (status != BtnX->Btn_filter)
	{
		BtnX->Btn_filter = status;
		BtnX->Is_debouncing = 1;
		BtnX->Time_debounce = HAL_GetTick();
	}

//*****************Xac nhan tin hieu******************//
	if (BtnX->Is_debouncing && (HAL_GetTick()-BtnX->Time_debounce >= 15))
	{
		BtnX->Btn_current = BtnX->Btn_filter;
		BtnX->Is_debouncing = 0;
	}

//*****************Nhan nha******************//
	if (BtnX->Btn_current != BtnX->Btn_last)
	{
		if (BtnX->Btn_current == 0)
		{
			BtnX->Is_press_timeout = 1;
			Btn_press_Callback(BtnX->GPIOx,BtnX->GPIO_Pin);
			BtnX->Time_start_press = HAL_GetTick();
		} else
		{
			if (HAL_GetTick() - BtnX->Time_start_press <= 1000)
			{
				Btn_press_short_Callback(BtnX->GPIOx,BtnX->GPIO_Pin);
			}
			Btn_release_Callback(BtnX->GPIOx,BtnX->GPIO_Pin);
			BtnX->Is_press_timeout = 0;
		}
		BtnX->Btn_last = BtnX->Btn_current;
	}
	//*****************Nhan giu******************//
	if (BtnX->Is_press_timeout && (HAL_GetTick() - BtnX->Time_start_press >= 2000))
	{
		Btn_press_timeout_Callback(BtnX->GPIOx,BtnX->GPIO_Pin);
		BtnX->Is_press_timeout = 0;
	}
}

void Btn_Init(Btn_Typedef *BtnX, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	BtnX->GPIOx = GPIOx;
	BtnX->GPIO_Pin = GPIO_Pin;

}
