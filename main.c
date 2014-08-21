#include "stm32f10x.h"
#include "eeprom.h"
#include "led.h"

uint16_t VarValue = 0;
uint16_t VirtAddVarTab[NumbOfVar] = {1, 2, 3};

int main(void)
{
	uint16_t result;

	FLASH_Unlock();
	result = EE_Init();
	assert_param(result == FLASH_COMPLETE);

	result = EE_WriteVariable(1, 0x33);
	assert_param(result == FLASH_COMPLETE);
	result = EE_WriteVariable(1, 0x34);
	assert_param(result == FLASH_COMPLETE);
	result = EE_WriteVariable(2, 0x43);
	assert_param(result == FLASH_COMPLETE);
	result = EE_WriteVariable(2, 0x44);
	assert_param(result == FLASH_COMPLETE);
	result = EE_WriteVariable(3, 0x53);
	assert_param(result == FLASH_COMPLETE);
	result = EE_WriteVariable(3, 0x54);
	assert_param(result == FLASH_COMPLETE);

	uint16_t readData;
	result = EE_ReadVariable(1, &readData);
	assert_param(result == 0);	//variable was found
	assert_param(readData == 0x34);

	result = EE_ReadVariable(2, &readData);
	assert_param(result == 0);
	assert_param(readData == 0x44);

	result = EE_ReadVariable(3, &readData);
	assert_param(result == 0);
	assert_param(readData == 0x54);

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
