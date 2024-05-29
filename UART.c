#include "stm32f4xx.h"
#include "usart.h"
#include <stdio.h>

void Delay(unsigned int t);

int main(void)
{
 
  USART_Configuration();
	
 //while(1)
 //{
  /* Output a message on Hyperterminal using printf function */
  printf("\r\nLogsun Systems, Pune\r\n");
  Delay(10000);
  
  
 //}
}

void Delay(unsigned int t)
{
 unsigned int i,j;
 for(i=0;i<t;i++)
 for(j=0;j<2000;j++);
}
