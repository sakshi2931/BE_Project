#include <stm32f407xx.h>
void Delay(uint32_t nCount);

int main(void)
{
 SCB->CCR |= SCB_CCR_STKALIGN_Msk; //Enable double word stack alignment
	
 RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOEEN; //Enable Port D & Port E Clock
	
//Set PD0-PD7 as GPIO O/P Pins (push-pull)
 GPIOD->MODER |= (GPIO_MODER_MODE0_0) | (GPIO_MODER_MODE1_0) | (GPIO_MODER_MODE2_0) | (GPIO_MODER_MODE3_0) | 
         (GPIO_MODER_MODE4_0) | (GPIO_MODER_MODE5_0) | (GPIO_MODER_MODE6_0) | (GPIO_MODER_MODE7_0);
	
 GPIOD->OTYPER |= 0; //Port D GPIO type (push-pull)
 GPIOD->OSPEEDR |= 0; //Port D GPIO speed (slow)

 #define LOOP_COUNT 0x1FFFFF
	
 while(1)
 {
  GPIOD->BSRR = (1<<0); //Set PD0
  Delay(LOOP_COUNT);
  GPIOD->BSRR = (1<<0)<<16; //Reset PD0
  
  GPIOD->BSRR = (1<<1);
  Delay(LOOP_COUNT);
  GPIOD->BSRR = (1<<1)<<16;
  
  GPIOD->BSRR = (1<<2);
  Delay(LOOP_COUNT);
  GPIOD->BSRR = (1<<2)<<16;
  
  GPIOD->BSRR = (1<<3);
  Delay(LOOP_COUNT);
  GPIOD->BSRR = (1<<3)<<16;
  
  GPIOD->BSRR = (1<<4);
  Delay(LOOP_COUNT);
  GPIOD->BSRR = (1<<4)<<16;
  
  GPIOD->BSRR = (1<<5);
  Delay(LOOP_COUNT);
  GPIOD->BSRR = (1<<5)<<16;
  
  GPIOD->BSRR = (1<<6);
  Delay(LOOP_COUNT);
  GPIOD->BSRR = (1<<6)<<16;
  
  GPIOD->BSRR = (1<<7);
  Delay(LOOP_COUNT);
  GPIOD->BSRR = (1<<7)<<16;
 };
}

void Delay(uint32_t nCOunt)
{
 while(nCOunt--)
 {
  __NOP();
 }
}
