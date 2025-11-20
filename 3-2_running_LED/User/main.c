#include "stm32f10x.h"  // Device header
#include "delay.h"
int main(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//turn on clock
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//pull-push輸出推挽輸出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	//GPIO_SetBits(GPIOA, GPIO_Pin_0);
	//GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
	while(1){
		GPIO_Write(GPIOA, ~0x0001);//換為二進制的不同位bit set, 一個bit代表一個pin腳
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0002);
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0004);
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0008);
		Delay_ms(500);
		
	}
	
}