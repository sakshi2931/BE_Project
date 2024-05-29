#include <stm32f407xx.h>

int main(void)
{
 SCB->CCR |= SCB_CCR_STKALIGN_Msk; //Enable double word stack alignment

 RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOEEN; //Enable Port D & Port E Clock

//Set PD0-PD7 as GPIO Output Pins (push-pull)
 GPIOD->MODER |= (GPIO_MODER_MODE0_0) | (GPIO_MODER_MODE1_0) | (GPIO_MODER_MODE2_0) | (GPIO_MODER_MODE3_0) | 
         (GPIO_MODER_MODE4_0) | (GPIO_MODER_MODE5_0) | (GPIO_MODER_MODE6_0) | (GPIO_MODER_MODE7_0);

 GPIOD->OTYPER |= 0; //Port D GPIO type (push-pull)
 GPIOD->OSPEEDR |= 0; //Port D GPIO speed (slow)
 GPIOD->PUPDR = 0; //No pull up, no pull down


 //Set PE0-PE7 as GPIO Input Pins (push-pull)
 GPIOE->MODER &= ~((GPIO_MODER_MODER0) | (GPIO_MODER_MODER1) | (GPIO_MODER_MODER2) | (GPIO_MODER_MODER3) | 
         (GPIO_MODER_MODER4) | (GPIO_MODER_MODER5) | (GPIO_MODER_MODER6) | (GPIO_MODER_MODE7));
 GPIOE->OTYPER |= 0; //Port E GPIO type (push-pull)
 GPIOE->OSPEEDR |= 0;
 GPIOE->PUPDR |= (GPIO_PUPDR_PUPDR0_0) | (GPIO_PUPDR_PUPDR1_0) | (GPIO_PUPDR_PUPDR2_0) | (GPIO_PUPDR_PUPDR3_0) | //pull up
          (GPIO_PUPDR_PUPDR4_0) | (GPIO_PUPDR_PUPDR5_0) | (GPIO_PUPDR_PUPDR6_0) | (GPIO_PUPDR_PUPDR7_0);


 while(1)
 {
  if(!(GPIOE->IDR & (1<<0)))
  {
  GPIOD->BSRR = (1<<7);
  }
  else
   GPIOD->BSRR = (1<<7)<<16;

  if(!(GPIOE->IDR & (1<<1)))
  {
  GPIOD->BSRR = (1<<6);
  }
  else
   GPIOD->BSRR = (1<<6)<<16;

  if(!(GPIOE->IDR & (1<<2)))
  {
  GPIOD->BSRR = (1<<5);
  }
  else
   GPIOD->BSRR = (1<<5)<<16;

  if(!(GPIOE->IDR & (1<<3)))
  {
  GPIOD->BSRR = (1<<4);
  }
  else
   GPIOD->BSRR = (1<<4)<<16;

  if(!(GPIOE->IDR & (1<<4)))
  {
  GPIOD->BSRR = (1<<3);
  }
  else
   GPIOD->BSRR = (1<<3)<<16;

  if(!(GPIOE->IDR & (1<<5)))
  {
  GPIOD->BSRR = (1<<2);
  }
  else
   GPIOD->BSRR = (1<<2)<<16;

  if(!(GPIOE->IDR & (1<<6)))
  {
  GPIOD->BSRR = (1<<1);
  }
  else
   GPIOD->BSRR = (1<<1)<<16;

  if(!(GPIOE->IDR & (1<<7)))
  {
  GPIOD->BSRR = (1<<0);
  }
  else
   GPIOD->BSRR = (1<<0)<<16;
 };
}
