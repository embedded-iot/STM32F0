#include "main.h" 


/*
*
 * -----------------CONFIG TIM3 PWM CH1------------------- *
*/
void TIM_PWM_Configuration(void)
{ 
	GPIO_InitTypeDef           GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
  TIM_OCInitTypeDef          TIM_OCInitStructure;
	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
    
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
  GPIO_Init(GPIOA, &GPIO_InitStructure); 
  
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_1);
 
   
  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Prescaler = 2;  
  TIM_TimeBaseStructure.TIM_Period = 411;   // 65535
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
 
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; 
  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OCInitStructure.TIM_Pulse = 0;
  //TIM_OCStructInit(&TIM_OCInitStructure);
  
  TIM_OC1Init(TIM3, &TIM_OCInitStructure);  
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
  
//  TIM_OC2Init(TIM3, &TIM_OCInitStructure);
//  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
// 
//  TIM_OC3Init(TIM3, &TIM_OCInitStructure);
//  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
  
  //TIM_OC4Init(TIM1, &TIM_OCInitStructure);
  //TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);
 
  TIM_ARRPreloadConfig(TIM3, ENABLE);
 
  /* TIM1 enable counter */
  TIM_Cmd(TIM3, ENABLE);
  TIM_CtrlPWMOutputs(TIM3, ENABLE);
}


