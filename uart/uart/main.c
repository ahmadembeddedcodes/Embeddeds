/*
 * uart.c
 *
 * Created: 10/07/2019 05:33:12 م
 * Author : Ahmad
 */ 
#define F_CPU 8000000UL

#include "uart_x.h"
#include "GPIO.h"
#include <util/delay.h>

int main(void)
{
 
 GPIO_U8_PIN_DIR('d',0,0);
 
 GPIO_U8_PIN_DIR('d',1,1);
 
//DDRD=0xff;
 /* Set frame format: 8data, 2 stop bit */
   usart_init();
   *DDR_A=0xff;
   *PORT_A=0x00;  
   usart_flush(); 
    unsigned int x ; 
    while (1) 
    {
	
		x= usart_Receive9bit();
		 if (x==5)
		   GPIO_U8_PORT_WRITE('a',0xff);
		 else 
		  GPIO_U8_PORT_WRITE('a',0x00);    
		 
	}

}

