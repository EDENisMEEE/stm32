#include "stm32f10x.h"
#include <stdbool.h>
// Device header
void LED_init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_1|GPIO_Pin_2);
}

void LED_SET(uint16_t pin, bool Cond){
	if(Cond == false){
		GPIO_ResetBits(GPIOA, pin);
	}else if(Cond == true){
		GPIO_SetBits(GPIOA, pin);
	}
}

void LED_turn(uint16_t pin){
	if(GPIO_ReadOutputDataBit(GPIOA, pin) == 0){
		GPIO_SetBits(GPIOA, pin);
	}else{
		GPIO_ResetBits(GPIOA, pin);
	}
	
}

