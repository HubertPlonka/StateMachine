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
//state machine


