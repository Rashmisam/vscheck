/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ASHWIN G
 * @brief          : Main program body

 */
#include<string.h>
#include "stm32f407xx.h"
#include"stm32f407xx_gpio_driver.h"


#define HIGH 1
#define LOW 0
#define BTN_PRESSED LOQ

void delay(void)
{
	for(uint32_t i=0;i<5000000/2;i++);

}

int main(void)
{
	GPIO_Handle_t GpioLed, GpioBtn;


	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	// this is btn gpio configuration

	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_PIN_SET;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioBtn);

	WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
	// IRQ configuration
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0,ENABLE);

    while(1);

}

void EXTI0_IRQHandler(void)
{
	/// delay(); // 200ms.
	GPIO_IRQHandling(GPIO_PIN_NO_0);
	ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
}


//hence proved
//yes