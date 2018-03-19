

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

uint32_t Adc_Value=0, Adc_Value_Old=0;
int i;
unsigned char value=0;
unsigned char setup;
float Duty=0.0, Duty_old=6.0; 
int a;

/* Private function prototypes -----------------------------------------------*/
void GPIO_config(void);

/* Private functions ---------------------------------------------------------*/


int main(void)
{   
	  SystemInit();
	  RCC_use_ext_crystal();
    delay_init(48);
    TIM_PWM_Configuration(); 
	  GPIO_Configuration();
	  Adc_init();   
	  //initIWDG(3,0xfff);
	  Setup_Config();
	
    TIM3->CCR1 = 6.0 * 411 / 100;     /* 20% Duty cycle */
   //TIM3->CCR3 = 90 * 65535 / 100;    /* 90% Duty cycle */
	 //write_data_flash( Address1, 6789);
	 //write_data_flash( Address2, 0000);
	
    while (1)
      {  
//         if((GPIO_ReadInputDataBit(GPIOB, Mode)) == RESET)  
//					 {
//    				  Adc_Value = Read_adc();
//						  delay_ms(7);
//              quet_phim();
//              if(setup==0) 
//							 {
//								 for(i=0;i<50;i++)
//							      { 
//								       dec4(Adc_Value/1000,(Adc_Value%1000)/100,(Adc_Value%100)/10,Adc_Value%10);
//											//IWDG_Feed();
//									  }
//							 }
//						  if(setup==1) setup1();
//						  if(setup==2) setup2();
//						}
//					 else  dec4(4,5,6,7);
				   
				
			
				Adc_Value = 0;
        for(i=0;i<10;i++)
				{  				
				    Adc_Value = Adc_Value + Read_adc();
				    delay_ms(200);
				}
				Adc_Value = Adc_Value/10;
				
				if(Adc_Value>3000) TIM3->CCR1 = 0;
				else
				{   
				    Duty = 12-(Adc_Value * 12 / 4096);
					  a=Duty*10;
					  Duty=(float)a/10.0;
					  while(Duty > Duty_old)
						{
			        Duty_old = Duty_old + 0.01; 
							TIM3->CCR1 = Duty_old*411 / 100; 
							 delay_ms(1000);
							 //delay_ms(1000);
						}
            while(Duty < Duty_old)
						{  
							 Duty_old = Duty_old - 0.1;
			         TIM3->CCR1 = Duty_old*411 / 100; 
							 //delay_ms(1000);
							 delay_ms(1000);
						}		
            Duty_old = Duty;						
			}
	
//	Duty=6.0;
//	for(i=0;i<50;i++)
//	{
//	    Duty=Duty+0.1;
//		  TIM3->CCR1 = Duty*411 / 100;
//		  delay_ms(7);
//		delay_ms(1000);
//		delay_ms(1000);
//		delay_ms(1000);
//	}
//	
//	TIM3->CCR1 = 0;
//	
//	//		delay_ms(1000);
//		delay_ms(1000);
//		delay_ms(1000);
//	//		delay_ms(1000);
//		delay_ms(1000);
//		delay_ms(1000);
	
      }
}


#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{ 

  while (1)
  {
  }
}
#endif

