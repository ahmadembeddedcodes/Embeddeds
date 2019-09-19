/*
 * Button.c
 *
 * Created: 7/5/2019 1:34:36 PM
 * Author : Ahmad
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "GPIO.h"
#include "pb.h"

int main(void)
{
  
   PB_Init('a',PIN0);   //(OR)==>  GPIO_U8_PIN_DIR('a',0,pin_dir_input); 
   GPIO_U8_PIN_DIR('a',1,pin_dir_output); 
   GPIO_U8_PIN_WRITE('a',1,0); 
	
	while (1) 
    {
		
		if (   ! GPIO_U8_PIN_READ_SIMPLE('a',0)     /*! PB_IsPressed('a',0)*/)
		  {
			  GPIO_U8_PIN_WRITE('a',1,1); 
			  _delay_ms(300); 
			  GPIO_U8_PIN_WRITE('a',1,0);
			  _delay_ms(300);
		  }
		  

// 		  while(! PB_IsPressed('a',0))
// 		    GPIO_U8_PIN_WRITE('a',1,1); 
// 	   
// 		 GPIO_U8_PIN_WRITE('a',1,0); 
    }
}

