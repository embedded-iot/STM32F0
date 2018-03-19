#include "main.h" 



void Adc_init(void)
{ 
	GPIO_InitTypeDef           GPIO_InitStructure;
	ADC_InitTypeDef            ADC_InitStructure;
	
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ; // bit0 c?a port
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;// ch? d? analog
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;// kh�ng d�ng tr? k�o
  GPIO_Init(GPIOA, &GPIO_InitStructure);// kh?i t?o c?u h�nh cho GPIOC
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
/* ADCs DeInit */
  ADC_DeInit(ADC1);
  /* Initialize ADC structure */
  ADC_StructInit(&ADC_InitStructure);
  /* Configure the ADC1 in continous mode withe a resolutuion equal to 12 bits  */
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;          // d? ph�n gi?n 12 bit
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;               // ch? d? do li�n t?c
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;// ko d�ng trige
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;           // d? li?u d?n v? b�n ph?i
  ADC_InitStructure.ADC_ScanDirection = ADC_ScanDirection_Upward;
  ADC_Init(ADC1, &ADC_InitStructure);
    /* ch?n k�nh do ADC_INT10 , t?c d? l?y m?u 239,5 chu k� th?ch anh.*/
		
  ADC_ChannelConfig(ADC1, ADC_Channel_4, ADC_SampleTime_239_5Cycles);

  /* ADC Calibration */
  ADC_GetCalibrationFactor(ADC1);

  /* Enable ADCperipheral[PerIdx] */
  ADC_Cmd(ADC1, ENABLE);

  /* Wait the ADRDY falg */
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_ADRDY));

  /* cho ph�p chuy?n d?i ADc tr�n k�nh ADC d� ch?n */
  ADC_StartOfConversion(ADC1);
	
}

uint16_t Read_adc(void)
    {
			    uint16_t adc_value=0;
         /* Test EOC flag */
          while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);// ch? bit OEC=1
          /* d0c gi� tri ADC*/
        adc_value =ADC_GetConversionValue(ADC1);
        return adc_value;
    }
