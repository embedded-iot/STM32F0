#include "main.h" 


/*
*
 * -----------------Config GPIO------------------- *
*/
void GPIO_Configuration(void)
{  
  GPIO_InitTypeDef           GPIO_InitStructure;
	
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
 
 /* Configure PA1 PA2 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8| GPIO_Pin_9| GPIO_Pin_10| GPIO_Pin_11| GPIO_Pin_12| GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4| GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
}

/*
*
 * -----------------LED 7 THANH------------------- *
*/
void dec(uint8_t data)
{
   switch(data)
	   {
	      case 0:
		            GPIO_ResetBits(GPIOA, GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
			          GPIO_SetBits(GPIOA,GPIO_Pin_9);  /* USER CODE END WHILE */
		            break;
	      case 1:
		            GPIO_ResetBits(GPIOA,GPIO_Pin_10|GPIO_Pin_15);
			          GPIO_SetBits(GPIOA,GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14);
		            break;
	      case 2:
		            GPIO_ResetBits(GPIOA, GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_15);
			          GPIO_SetBits(GPIOA,GPIO_Pin_10|GPIO_Pin_14); 
		            break;
	      case 3:
		            GPIO_ResetBits(GPIOA, GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_15);
		    	      GPIO_SetBits(GPIOA,GPIO_Pin_14|GPIO_Pin_12); 
		            break;
	      case 4:
			          GPIO_ResetBits(GPIOA, GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_14|GPIO_Pin_15);
		            GPIO_SetBits(GPIOA, GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13); 
		            break;
	      case 5:
			          GPIO_ResetBits(GPIOA, GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14);
			          GPIO_SetBits(GPIOA, GPIO_Pin_12|GPIO_Pin_15); 
		            break;
	      case 6:
			          GPIO_ResetBits(GPIOA, GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14);
			          GPIO_SetBits(GPIOA, GPIO_Pin_15);
		            break;
	      case 7:
		            GPIO_ResetBits(GPIOA, GPIO_Pin_10|GPIO_Pin_13|GPIO_Pin_15);
			          GPIO_SetBits(GPIOA,GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_14); 
		            break;
	      case 8:
			          GPIO_ResetBits(GPIOA,GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15); 
		            break;
	      case 9:	
		            GPIO_ResetBits(GPIOA,GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15); 
			          GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		            break;
	      default:
		            GPIO_SetBits(GPIOA,GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
			          GPIO_ResetBits(GPIOA,GPIO_Pin_9);
		            break;
	  }
	
}	


/*
*
 * -----------------DK LED7------------------ *
*/
void dec4(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
	{	
		dec(a);
		GPIO_SetBits(GPIOB, GPIO_Pin_5);		
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		GPIO_ResetBits(GPIOB, GPIO_Pin_4|GPIO_Pin_3);	
		delay_ms(6);
		dec(b);
		GPIO_SetBits(GPIOB, GPIO_Pin_4);		
		GPIO_ResetBits(GPIOB, GPIO_Pin_3|GPIO_Pin_5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);	
		delay_ms(6);
		dec(c);
		GPIO_SetBits(GPIOB, GPIO_Pin_3);		
		GPIO_ResetBits(GPIOB, GPIO_Pin_4|GPIO_Pin_5);	
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);	
		delay_ms(6);	
		dec(d);
		GPIO_SetBits(GPIOA, GPIO_Pin_8);		
		GPIO_ResetBits(GPIOB, GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_3);
		delay_ms(6);		
	}
	
void tat_led (void)
 {
    GPIO_ResetBits(GPIOB, GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5);
	  GPIO_ResetBits(GPIOA, GPIO_Pin_8);
    delay_ms(1);	 
 }
