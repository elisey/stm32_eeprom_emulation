#include "stm32f10x.h"
#include "eeprom_emul.h"
#include "led.h"

extern void EE_Test();


int main(void)
{
	EE_Test();
	//Тест успешен. Зеленый светодиод
	Led_t greenLed;
	Led_Init(&greenLed, GPIOC, GPIO_Pin_9);
	Led_SetState(&greenLed, led_on);

	while(1)
	{

	}
}

void assert_failed(uint8_t* file, uint32_t line)
{
	//Тест неуспешен
	Led_t blueLed;
	Led_Init(&blueLed, GPIOC, GPIO_Pin_8);
	Led_SetState(&blueLed, led_on);
	while(1);
}
