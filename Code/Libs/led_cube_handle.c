#include "led_cube_handle.h"

Cube_Status currentEffect = SPIRAL_CUBE;

void Btn_press_Callback(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	switch(currentEffect){
	case TURN_OFF_ALL_LEDS:
		currentEffect = TURN_ON_ALL_LEDS;
		break;
	case TURN_ON_ALL_LEDS:
		PlaneCube_Set_State();
		break;
	case SWEEP_ALL_LEDS:
		GrowShrinkCube_Set_State();
		break;
	case GROW_SHRINK_CUBE:
		DiagonalCube_Set_State();
		break;
	case DIAGONAL_CUBE:
		AroundEdgeCube_Set_State();
		break;
	case AROUND_EDGE_CUBE:
		CountDownCube_Set_Sate();
		break;
	case COUNT_DOWN_CUBE:
		RandomRainCube_Set_State();
		break;
	case RANDOM_RAIN_CUBE:
		SpiralCube_Set_State();
		break;
	case SPIRAL_CUBE:
		currentEffect = TURN_OFF_ALL_LEDS;
		break;
		break;
	default:
		break;
	}
}

void Led_cube_Handle(Cube_Status cube_state)
{
	switch (cube_state) {
		case TURN_OFF_ALL_LEDS:
			clearCube();
			break;
		case TURN_ON_ALL_LEDS:
			lightCube();
			break;
		case SWEEP_ALL_LEDS:
			PlaneCube_Handle();
			break;
		case GROW_SHRINK_CUBE:
			GrowShrinkCube_Handle();
			break;
		case DIAGONAL_CUBE:
			DiagonalCube_Handle();
			break;
		case AROUND_EDGE_CUBE:
			AroundEdgeCube_Handle();
			break;
		case COUNT_DOWN_CUBE:
			CountDownCube_Handle();
			break;
		case RANDOM_RAIN_CUBE:
			RandomRainCube_Handle(10);
			break;
		case SPIRAL_CUBE:
			SpiralCube_Handle();
			break;
		default:
			break;
	}
}
