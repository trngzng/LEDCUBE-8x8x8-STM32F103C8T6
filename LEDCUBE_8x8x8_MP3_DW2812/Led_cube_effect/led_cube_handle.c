#include "led_cube_handle.h"
#include "timer.h"

Cube_Status currentEffect = WAVE_EFFECT;

#define MAX_EFFECT_APP 11

timer_ID_t gcurrent_id = 0;
static uint8_t gappcnt = 0;
static app_t gapp[MAX_EFFECT_APP];

//void (*state_table[])() = {};
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
		WaveCube_Set_State();
		break;
	case WAVE_EFFECT:
		SidewavesEffect_Set_State();
		break;
	case SIDE_WAVES_EFFECT:
		currentEffect = TURN_OFF_ALL_LEDS;
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
		case WAVE_EFFECT:
			WaveCube_Handle();
			break;
		case SIDE_WAVES_EFFECT:
			SidewavesEffect_Handle();
			break;
		default:
			break;
	}
}

static void LED_app_change(uint8_t *cnt){
	if(gappcnt < MAX_EFFECT_APP && gapp[gappcnt+1].loop != 0){
		gappcnt++;
	}
	else{
		gappcnt = 0;
	}
	timer_unregister_callback(gcurrent_id);

	if(gapp[gappcnt].init !=0) gapp[gappcnt].init();
	gcurrent_id = timer_register_callback(gapp[gappcnt].loop, gapp[gappcnt].period, 0, TIMER_MODE_REPEAT);
}

void Effect_app(){
	gapp[0].init = AroundEdgeCube_Set_State;
	gapp[0].loop = AroundEdgeCube_Handle;
	gapp[0].period = 100;

	gapp[1].init = CountDownCube_Set_Sate;
	gapp[1].loop = CountDownCube_Handle;
	gapp[1].period = 1;

	gapp[2].init = DiagonalCube_Set_State;
	gapp[2].loop = DiagonalCube_Handle;
	gapp[2].period = 100;

	gapp[3].init = GrowShrinkCube_Set_State;
	gapp[3].loop = GrowShrinkCube_Handle;
	gapp[3].period = 100;

	gapp[4].init = PlaneCube_Set_State;
	gapp[4].loop = PlaneCube_Handle;
	gapp[4].period = 200;

	gapp[5].init = RandomRainCube_Set_State;
	gapp[5].loop = RandomRainCube_Handle;
	gapp[5].period = 110;

	gapp[6].init = SidewavesEffect_Set_State;
	gapp[6].loop = SidewavesEffect_Handle;
	gapp[6].period = 10;


	gapp[7].init = SpiralCube_Set_State;
	gapp[7].loop = SpiralCube_Handle;
	gapp[7].period = 1;

	gapp[8].init = WaveCube_Set_State;
	gapp[8].loop = WaveCube_Handle;
	gapp[8].period = 50;
//
	if(gapp[gappcnt].init != NULL) gapp[gappcnt].init();
	gcurrent_id = timer_register_callback(gapp[gappcnt].loop, gapp[gappcnt].period, 0, TIMER_MODE_REPEAT);
	timer_register_callback(LED_app_change, 10000, 0, TIMER_MODE_REPEAT);
}
