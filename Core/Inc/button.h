/*
 * button.h
 *
 *  Created on: Feb 17, 2025
 *      Author: hubel
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

//states for state machine
typedef enum
{
	IDLE = 0,
	DEBOUNCE,
	PRESSED
} BUTTON_STATE;
//struct for button
typedef struct
{
	BUTTON_STATE State;
	GPIO_TypeDef* GpioPort;
	uint16_t GpioPin;
	uint32_t TimerDebounce; //fixed
	uint32_t LastTick;
	void(*ButtonPressed)(void);
} TButton;
//public functions
void ButtonInitKey(TButton* Key, GPIO_TypeDef* GpioPort, uint16_t GpioPin, uint32_t TimerDebounce);

#endif /* INC_BUTTON_H_ */
