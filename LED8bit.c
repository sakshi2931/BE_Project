#include <stm32f407xx.h>

#define RS 1<<0
#define RW 1<<1
#define EN 1<<2

void LCDInit(void);
void LCD_data(char data);
void LCD_cmd(char cmd);
void LCD_display(int row, const char *str);
void delay(uint32_t time);

int main(void)
{
 RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN| RCC_AHB1ENR_GPIOCEN; //Enable Clock to Port A and Port B
	
	
 GPIOA->MODER |= (GPIO_MODER_MODE0_0)| (GPIO_MODER_MODE1_0)| (GPIO_MODER_MODE2_0)| (GPIO_MODER_MODE3_0)| //Port A Pins 0 to 7 as Output
         (GPIO_MODER_MODE4_0)| (GPIO_MODER_MODE5_0)| (GPIO_MODER_MODE6_0)| (GPIO_MODER_MODE7_0); //LCD Data Pins
 GPIOA->OTYPER=0;
 GPIOA->OSPEEDR=0;
	
	
 GPIOC->MODER |= (GPIO_MODER_MODE0_0)| (GPIO_MODER_MODE1_0)| (GPIO_MODER_MODE2_0)| (GPIO_MODER_MODE3_0)| //Port B Pins 0 to 7 as Output
         (GPIO_MODER_MODE4_0)| (GPIO_MODER_MODE5_0)| (GPIO_MODER_MODE6_0)| (GPIO_MODER_MODE7_0); //LCD Cmd Pins
 GPIOC->OTYPER=0;
 GPIOC->OSPEEDR=0;
	
	
 LCDInit();
	
 LCD_display(1," LOGSUN SYSTEMS ");
 LCD_display(2," PUNE ");
 while(1);
}


void LCDInit(void)
{
 LCD_cmd(0x38);
 delay(5);
 LCD_cmd(0x0C);
 delay(5);
 LCD_cmd(0x01);
 delay(5);
 LCD_cmd(0x06);
 delay(5);
 LCD_cmd(0x80);
 delay(5);
}

void LCD_cmd(char cmd)
{
 GPIOA->ODR = (cmd);
 GPIOC->BSRR |= (RS)<<16;
 GPIOC->BSRR |= (RW)<<16;
 GPIOC->BSRR |= (EN);
 delay(5);
 GPIOC->BSRR |= (EN)<<16;
}

void LCD_data(char data)
{
 GPIOA->ODR = (data);
 GPIOC->BSRR |= (RS);
 GPIOC->BSRR |= (RW)<<16;
 GPIOC->BSRR |= (EN);
 delay(5);
 GPIOC->BSRR |= (EN)<<16;
}

void LCD_display(int row, const char *str)
{
 int k;
 if(row == 1)
  LCD_cmd(0x80);
 else
  LCD_cmd(0xC0);
	
 for(k=0;k<16;k++)
 {
  if(str[k]!=0)
   LCD_data(str[k]);
  else break;
 }
 while(k<16)
 {
  LCD_data(' ');
  k++;
 }
}

void delay(uint32_t time)
{
 for(uint32_t i=0;i<time*1000;i++);
}
