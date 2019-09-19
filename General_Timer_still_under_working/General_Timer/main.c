/*
 * General_Timer.c
 *
 * Created: 7/7/2019 8:41:52 AM
 * Author : Ahmad
 */ 
#define F_CPU  8000000UL 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "all_timer.h"

#define F_OUT 50000 // output frequency
#define OCR0_VALUE ((((F_CPU/2)/clk_1024)/F_OUT)-1)


ISR(TIMER1_COMPA_vect) // interrupt subroutine
{
  OCR1A =  (u16) OCR0_VALUE ; 	
	//Timer1_Set_OCR1A( (u16)OCR0_VALUE ); //put OCR value 	
}   


int main(void)
{
/*
//   struct Timer0_Configuration config;
//  //  struct Timer0_Configuration config;
//  config.timer0_mode= FAST_PWM ;
//  config.timer0_prescaler = clk_1024;
//  config.timer0_oc_pin =CLEAR_OC;
//  //config.timer0_int= Timer_Output_Compare_Match_Interrupt_Enable;
// 
//  DDRB |=(1<<PINB3);
//  sei(); // enable global interrupts
//  
//  Timer0_Init(config);
*/

/***************************************/
  struct Timer1_Configuration config;
  //  struct Timer0_Configuration config;
  config.timer1_mode= FAST_PWM_TOP_OCR1A ;
  config.timer1_prescaler = clk_1024;
  config.timer1_oc_pin = CLEAR_OC;
  //config.timer1_int= Timer_Output_Compare_Match_Interrupt_Enable;

  //DDRB |=(1<<PINB3);

  DDRD |=(1<<PIND5);
  sei(); // enable global interrupts
  
  Timer1_Init(config); 
 
 /****************************************/ 
	while (1) 
    {
		
		/* Timer1_Set_OCR1A(511+x);*/
	}
}

