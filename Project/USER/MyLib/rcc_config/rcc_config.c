#include "stm32f0xx.h"
#include "rcc_config.h"

#ifdef _8Mhz_ex_crystal
void RCC_use_ext_crystal(void)
{
    //pls check stm32f110xx clock diagram for more details information
    RCC_PLLCmd(DISABLE);//disable PLL before setting up
   
   RCC_HSEConfig(RCC_HSE_ON);//use external crystal 
    while(!RCC_WaitForHSEStartUp()){RCC_WaitForHSEStartUp();}//wait until hse ready
   
    // use HSE as PLL clock source, so we have PLL_CLK= HSE* PLL_MULL=8*6=48Mhz () max
   RCC_PLLConfig(RCC_PLLSource_PREDIV1,RCC_PLLMul_6);
   RCC_PLLCmd(ENABLE);//enable PLL clk source
   
    // use PLL clock source as system clock source
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
}
#endif


