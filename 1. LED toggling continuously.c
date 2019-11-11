				
//---PROGRAM: FLASH LED CONTINEOUSLY---
					
#include <stm32f10x_lib.h>
#include "STM32_Init.h"
int i,j;

#define LED_PORT GPIOA		//defining GPIO port B
#define LED_PIN 7			//defining GPIO port B pin 14

void delay(int k)
{
	for(j=0;j<k;j++)
	{	
		for(i=0;i<5000;i++);
	}
}


int main(void)
{
	RCC->APB2ENR |=0x0004;			//enabling port B
	
 while(1)
	{
		LED_PORT->ODR ^= (1<<LED_PIN);	// toggling on/off LED
		delay(50);
	}
}
