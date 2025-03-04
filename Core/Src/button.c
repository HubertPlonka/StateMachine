/*
 * button.c
 *
 *  Created on: Feb 17, 2025
 *      Author: hubel
 */

#include "main.h"
#include "button.h"

//button init
void ButtonInitKey(TButton* Key, GPIO_TypeDef* GpioPort, uint16_t GpioPin, uint32_t TimerDebounce)
{
	Key->State = IDLE;

	Key->GpioPort = GpioPort;
	Key->GpioPin = GpioPin;
	Key->TimerDebounce = TimerDebounce;
}
//time setting func
//register callbacks
//states routine
void ButtonIdleRoutine(TButton* Key)
{
	if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(Key->GpioPort, Key->GpioPin))
	{
		Key->State = DEBOUNCE;
		Key->LastTick = HAL_GetTick();
	}
}
void ButtonDebounceRoutine(TButton* Key)
{
	if(HAL_GetTick() - Key->LastTick > Key->TimerDebounce)
	{

	}
}
void ButtonPressedRoutine(TButton* Key)
{

}
//state machine
void ButtonTask(TButton* Key)
{
	switch(Key->State)
	{
	case IDLE:
		//do IDLE
		ButtonIdleRoutine(Key);
		break;
	case DEBOUNCE:
		//do debounce
		ButtonDebounceRoutine(Key);
		break;
	case PRESSED:
		//do pressed
		ButtonPressedRoutine(Key);
		break;
	}
}

