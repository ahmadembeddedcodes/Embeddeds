/*
 * ADC.c
 *
 * Created: 23/07/2019 01:54:56 م
 * Author : Ahmad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include "adc.h"







int main(void)
{
	
	
	
	
	//set the adc pin as input - mtnsaaash ! 
DDRA = 0x00; 

DDRC =0xff; 
DDRD =0xff;
PORTC=PORTD=0X00; 

ADC_INIT();
      
    while (1) 
    {
		PORTC= ADC_READ(5); 
		
		 
    }
}

