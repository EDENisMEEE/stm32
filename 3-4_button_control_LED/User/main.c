#include <stdbool.h>
#include "stm32f10x.h"  // Device header
#include "delay.h"
#include "LED.h"
#include "Key.h"
uint8_t KeyNum;
int main(void){
	LED_init();
	Key_Init();
	while(1){
		KeyNum = Key_GetNum();
		if (KeyNum == 1){
			LED_turn(GPIO_Pin_1);
		}
		if(KeyNum == 2){
			LED_turn(GPIO_Pin_2);
		}
		
	}
	
}
