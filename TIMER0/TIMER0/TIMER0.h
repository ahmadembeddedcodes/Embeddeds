#ifndef TIMER0_H_
#define TIMER0_H_

#include "DATA_TYPES.h"

#ifndef F_CPU
#define F_CPU 1000000UL
#endif


/*****TIMER0_REGISTERS***********/
#define TCCR0_REG   *((volatile u8* const) 0x53)
#define TCNT0_REG   *((volatile u8* const) 0x52)
#define OCR0_REG    *((volatile u8* const) 0x5C)

/*******TIMERS REGS**********/
#define TIFR_REG    *((volatile u8* const) 0x58)
#define TIMSK_REG   *((volatile u8* const) 0x59)
 
/*** TCCR0_REG bits*/ 
#define CS00_BIT   0 
#define CS01_BIT   1 
#define CS02_BIT   2
#define WGM01_BIT  3 
#define COM00_BIT  4
#define COM01_BIT  5
#define WGM00_BIT  6
#define FOC0_BIT   7
/**************************/

/*** TIMSK_REG bits*/
#define TOIE0_BIT   0
#define OCIE0_BIT   1
#define TOIE1_BIT   2
#define OCIE1B_BIT  3
#define OCIE1A_BIT  4
#define TICIE1_BIT  5
#define TOIE2_BIT  6
#define OCIE2_BIT   7
/**************************/

/*** TIFR_REG bits*/
#define TOV0_BIT   0
#define OCF0_BIT   1
#define TOV1_BIT   2
#define OCF1B_BIT  3
#define OCF1A_BIT  4
#define ICF1_BIT   5
#define TOV2_BIT   6
#define OCF2_BIT   7
/**************************/


enum Timer0_Modes{
	NORMAL,
	PHASE_CORRECT,
	CTC,
	FAST_PWM
	};
	
enum Timer0_Prescaler {
/* warning: Never Change this Values*/ 	
   No_clock_source=0, // (Timer/Counter stopped). 
   clk_0     =0,     //no prescaling 
   clk_8     =8, 
   clk_64    =64,
   clk_256   =256,
   clk_1024  =1024,
   clk_EXTERNAL_1 =6,  //External clock source on T0 pin. Clock on falling edge.
   clk_EXTERNAL_2 =7,  //External clock source on T0 pin. Clock on rising edge.          
}; 

enum Timer0_Compare_Match{
	/*WARNING: THIS VALUE IN NORMAL MODE*/
	NORMAL_PORT_OPERATION, 
	TOGGLE_OC0,
	CLEAR_OC0,
	SET_OC0
	};
	
enum Timer0_Interrupt_state{
	Timer0_Output_Compare_Match_Interrupt_Enable,
	Timer0_Overflow_Interrupt_Enable
	};	
	
typedef struct Timer0_Configuration
{
	//mode 
	enum Timer0_Modes            timer0_mode; 
	//prescaler
	enum Timer0_Prescaler        timer0_prescaler;
	//output compare behaveure  
	enum Timer0_Compare_Match    timer0_oc0_pin; 
	//interrupt or not 
	enum Timer0_Interrupt_state  timer0_int; 
}timer0_config;


u8 Timer0_Init(struct Timer0_Configuration config_infos );
u8 Timer0_Read_Counter_Value(void);  
void Timer0_Set_Output_Compare_value(u8 OCR0_Register_value ); 
	

#endif
