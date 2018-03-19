#include "main.h"


extern unsigned char setup;

void Setup_Config(void)
	{
	   GPIO_InitTypeDef           GPIO_InitStructure;
	
     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
		
     GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7| GPIO_Pin_6;
     GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
     GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
     GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
     GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
     GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
     GPIO_Init(GPIOA, &GPIO_InitStructure);
	}
	
void quet_phim(void)
	{
     if ((GPIO_ReadInputDataBit(UP, GPIO_Pin_7)) == RESET)
			 {
					delay_ms(1000);
				  if ((GPIO_ReadInputDataBit(UP, GPIO_Pin_7)) == RESET)
						{
				       delay_ms(1000);
							 if ((GPIO_ReadInputDataBit(UP, GPIO_Pin_7)) == RESET) setup=1;
							
						}
			 }
     
		if ((GPIO_ReadInputDataBit(DOW, GPIO_Pin_7)) == RESET)
			 {
					delay_ms(1000);
				  if ((GPIO_ReadInputDataBit(DOW, GPIO_Pin_7)) == RESET)
						{
				       delay_ms(1000);
							 if ((GPIO_ReadInputDataBit(DOW, GPIO_Pin_7)) == RESET) setup=2;
							
						}
			 }	 
  }
	
void setup1 (void)
  {
		int i=0,j;
		unsigned int dem;
		delay_ms(1000);
		delay_ms(1000);
		dem=*(uint16_t*)Address1;
    while(i<500)
			{   
					if(j++<80) dec4(dem/1000,(dem%1000)/100,(dem%100)/10,dem%10);	
					else      tat_led();
					if(j==160) j=0;		
					if ((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)) == RESET)
			       {											 
     						delay_ms(150);
								if ((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)) == RESET) 
									{
										i=0;
										dem=dem+1;
									}
						 }
					if ((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)) == RESET)
			       {											 
     						 delay_ms(150);
								if ((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)) == RESET)
									 {
										 i=0;
										 dem=dem-1;
									 }
						 }
           delay_ms(1);						 
           i++;							
			  }
			setup=0;
			write_data_flash(Address1, dem);

  }	
	
void setup2 (void)
	{
	  int i=0,j;
		unsigned int dem;
		delay_ms(1000);
		delay_ms(1000);
		dem=*(uint16_t*)Address2;
    while(i<500)
			{   
					if(j++<80) dec4(dem/1000,(dem%1000)/100,(dem%100)/10,dem%10);	
					else      tat_led();
					if(j==160) j=0;		
					if ((GPIO_ReadInputDataBit(UP, GPIO_Pin_7)) == RESET)
			       {											 
     						delay_ms(150);
								if ((GPIO_ReadInputDataBit(UP, GPIO_Pin_7)) == RESET) 
									{
										i=0;
										dem=dem+1;
									}
						 }
					if ((GPIO_ReadInputDataBit(DOW, GPIO_Pin_7)) == RESET)
			       {											 
     						 delay_ms(150);
								if ((GPIO_ReadInputDataBit(DOW,GPIO_Pin_7)) == RESET)
									 {
										 i=0;
										 dem=dem-1;
									 }
						 }
           delay_ms(1);						 
           i++;							
			  }
			setup=0;
			write_data_flash(Address2, dem);
	}
	
void write_data_flash(uint32_t address, uint16_t data)
	{
     FLASH_Unlock(); 
     FLASH_ClearFlag(FLASH_FLAG_EOP|FLASH_FLAG_PGERR|FLASH_FLAG_WRPERR);
     FLASH_ErasePage(address);
     FLASH_ProgramHalfWord(address,data);
     FLASH_Lock();
	}		