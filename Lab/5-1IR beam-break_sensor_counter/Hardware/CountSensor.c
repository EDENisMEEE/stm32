#include "stm32f10x.h" // Device header
uint16_t CountSensor_Count;
//Interrupt:GPIO->AFIO->EXTI->NVIC
void CountSensor_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPU;//recommanded in manual(上拉輸入)
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Initstructure);
	//config AFIO
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);//Selects the GPIO pin used as EXTI Line.p(AFIO)
	//config EXTI
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line14;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//because the GPIO pin is set to Mode_IPU
	EXTI_Init(&EXTI_InitStructure);
	//兩位搶占，兩位響應
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	//There is only one interrupt in this project, choose whatever number you want
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
}
uint16_t CountSensor_Count_Get(void){
	return CountSensor_Count;
}
void EXTI15_10_IRQHandler (void){
	if(EXTI_GetITStatus(EXTI_Line14) == SET){
		//清除中斷標誌位，避免程式卡在中斷
		CountSensor_Count++;
		EXTI_ClearITPendingBit(EXTI_Line14);
	};
}
