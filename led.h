#pragma once

#include "stm32f10x.h"
#include <stdint.h>

typedef enum	{
	led_off	= 0,
	led_on	= 1
} led_state_t;

typedef struct	{
	GPIO_TypeDef* gpio;
	uint16_t pin;
	led_state_t state;
} Led_t;

void Led_Init(Led_t *this, GPIO_TypeDef *gpio, uint16_t pin);
void Led_SetState(Led_t *this, led_state_t newState);
void Led_Tougle(Led_t *this);
