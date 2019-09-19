/*
 * TIMER0.c
 *
 * Created: 7/6/2019 8:58:43 AM
 * Author : Ahmad
 */ 
#define  F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "TIMER0.h"
//#define FREQ 12000000 // crsytal freqeuncy
//#define PRECSALER 8
#define F_OUT 5000 // output frequency
#define OCR0_VALUE ((((F_CPU/2)/clk_1024)/F_OUT)-1)  


 ISR(TIMER0_COMP_vect) // interrupt subroutine
{
   Timer0_Set_Output_Compare_value( (u8)OCR0_VALUE ); //put OCR value
  
}


int main(void)
{

  timer0_config config; 
 //  struct Timer0_Configuration config; 
	config.timer0_mode= FAST_PWM ; 
	config.timer0_prescaler = clk_1024; 
	config.timer0_oc0_pin =  CLEAR_OC0; 

	DDRB |=(1<<PINB3);
	sei(); // enable global interrupts
	Timer0_Init(config);
	                                                      
	
    while (1) 
    {
	
		
    }
}

