
//PROGRAM: FLASH LED CONTINEOUSLY AFTER SWITCH PRESS
//PROGRAM: LED FLASH ON SWITCH PRESS AND TURN OFF WHEN SWITCH RELEASE-CHECK THE PROGRAM

#include <stm32f10x_lib.h>
#include "STM32_Init.h"

unsigned int i,j;

#define LED_PORT GPIOB			//declare port b
#define LED_PIN 14			//declare port b pin 14
#define SWITCH_PORT GPIOC		//declare port c
#define SWITCH_PIN 15			//declare port b pin 15

void delay(unsigned int k)	//function definition for delay
{
	for(j=0;j<k;j++)
	{for(i=0;i<5000;i++);
	}
}

int main(void)
{
	//stm32_Init();			//initialization
	RCC->APB2ENR |=0x0018;		//enabling port b and c
	GPIOB->CRH=0x03000000;		//selecting port mode and type
	GPIOC->CRH=0x80000000;		//selecting port mode and type
	GPIOC->ODR=0x10000000;		//make odr pin high for selcting it as pull down. pin should be same as i/p pin
		
while(1)
			{
				if(!((SWITCH_PORT->IDR)&(1<<SWITCH_PIN)))		//checking switch press condition
					{
						
						LED_PORT->ODR |= (1<<LED_PIN);			//LED on
						delay(50);
					
				while(1)
				{
						LED_PORT->ODR ^= (1<<LED_PIN);			//toggling LED
						delay(50);
				}//while end
					}//if end
			}//while end
}//main end
