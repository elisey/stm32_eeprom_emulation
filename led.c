#include "led.h"

void Led_Init(Led_t *this, GPIO_TypeDef *gpio, uint16_t pin)
{
	assert_param(IS_GPIO_ALL_PERIPH(gpio));
	assert_param(IS_GET_GPIO_PIN(pin));

	this->gpio = gpio;
	this->pin = pin;
	this->state = led_off;

	if (gpio == GPIOA)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	else if (gpio == GPIOB)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	else if (gpio == GPIOC)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	else if (gpio == GPIOD)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	else if (gpio == GPIOE)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	else if (gpio == GPIOF)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
	else if (gpio == GPIOG)
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);

	GPIO_InitTypeDef sGpio;
	sGpio.GPIO_Mode = GPIO_Mode_Out_PP;
	sGpio.GPIO_Pin = pin;
	sGpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(gpio, &sGpio);

	Led_SetState(this, led_off);
}
void Led_SetState(Led_t *this, led_state_t newState)
{
	if (newState == led_on)	{
		this->gpio->BSRR = this->pin;
	}
	else	{
		this->gpio->BRR = this->pin;
	}
	this->state = newState;
}
void Led_Tougle(Led_t *this)
{
	if (this->state == led_on)	{
		this->gpio->BRR = this->pin;
	}
	else	{
		this->gpio->BSRR = this->pin;
	}
	this->state = !this->state;
}
