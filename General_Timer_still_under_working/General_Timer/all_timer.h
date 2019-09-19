/** trying to write a complete code for all timer types in atmega32 */
/* it's depends on the last driver for TIMER 0 */

//* the _H_ file */

#ifndef ALL_TIMER_H_
#define ALL_TIMER_H_

#include "DATA_TYPES.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


/*****TIMERS_REGISTERS***********/
//timer 0
#define TCCR0_REG   *((volatile u8* const) 0x53)
#define TCNT0_REG   *((volatile u8* const) 0x52)
#define OCR0_REG    *((volatile u8* const) 0x5C)

//timer 2
#define TCCR2_REG   *((volatile u8* const) 0x45)
#define TCNT2_REG   *((volatile u8* const) 0x44)
#define OCR2_REG    *((volatile u8* const) 0x43)
/****************************************************/

//timer 1
//uint16_t var = TCNT1L | TCNTH << 8;
#define TCCR1A_REG   *((volatile u8* const) 0x4F)
#define TCCR1B_REG   *((volatile u8* const) 0x4E)

#define TCNT1H_REG   *((volatile u8* const) 0x4D)
#define TCNT1L_REG   *((volatile u8* const) 0x4C)
#define TCNT1_REG_GET   (u16)(TCNT1L_REG | (TCNT1H_REG << 8))  //this statement is read only 
 //to set the value of TCNT1 REgister
#define TCNT1_REG ((u16)value){\
                    TCNT1L_REG   = (u8)value;\
				     TCNT1H_REG  = (value<<8);\
					 }
					 
					 
#define OCR1AH_REG    *((volatile u8* const) 0x4B)
#define OCR1AL_REG    *((volatile u8* const) 0x4A)
#define OCR1A_REG_GET  (u16)(OCR1AL_REG | (OCR1AH_REG << 8))  //this statement is read only 
 //to set the value of OCR1 REgister
#define OCR1A_REG_SET(value)\
{\
	OCR1AL_REG  = value;\
	OCR1AH_REG  = (u16)(value<<8);\
	}

#define OCR1BH_REG    *((volatile u8* const) 0x49)
#define OCR1BL_REG    *((volatile u8* const) 0x48)
#define OCR1B_REG_GET  (u16)(OCR1BL_REG | (OCR1BH_REG << 8))  //this statement is read only 
 //to set the value of OCR1 REgister
#define OCR1B_REG_SET(value){\
	OCR1BL_REG   = (u8)value;\
	OCR1BH_REG  = (u16)(value>>8);\
	}

#define ICR1H_REG     *((volatile u8* const) 0x47)
#define ICR1L_REG     *((volatile u8* const) 0x46)
 //to set the value of OCR1 REgister
#define ICR1_REG_SET(value) {\
	ICR1L_REG   = value;\
	ICR1H_REG  = (u16)(value>>8);\
	}


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
/*** TCCR1A_REG bits*/
#define WGM10_BIT   0
#define WGM11_BIT   1
#define FOC1B_BIT   2
#define FOC1A_BIT  3
#define COM1B0_BIT  4
#define COM1B1_BIT  5
#define COM1A0_BIT  6
#define COM1A1_BIT   7
/**************************/
/*** TCCR1B_REG bits*/
#define CS10_BIT   0
#define CS11_BIT   1
#define CS12_BIT   2
#define WGM12_BIT  3
#define WGM13_BIT  4
#define NOT_USED  //
#define ICES1_BIT  6
#define ICN1_BIT   7

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


enum Timer_Modes{
	NORMAL,
	PHASE_CORRECT,
	CTC,
	FAST_PWM
};

enum Timer1_Modes{
	NORMAL_1,
	PHASE_CORRECT_8BIT,
	PHASE_CORRECT_9BIT,
	PHASE_CORRECT_10BIT,
	CTC_1,
	FAST_PWM_8BIT,
	FAST_PWM_9BIT,
	FAST_PWM_10BIT,
	PWM_PHASE_CORRECT_FREQ_TOP_ICR1,
	PWM_PHASE_CORRECT_FRQQ_TOP_OCR1A,
	PWM_PHASE_CORRECT_TOP_ICR1,
	PWM_PHASE_CORRECT_TOP_OCR1A,
	CTC_TOP_ICR1, 
	RESERVED_0,
	FAST_PWM_TOP_ICR1,
	FAST_PWM_TOP_OCR1A
};
enum Timer_Prescaler {
	/* warning: Never Change this Values- please ya 3m mtl3bsh fehoooom*/
	No_clock_source=0, // (Timer/Counter stopped).
	clk_0     =0,     //no prescaling
	clk_8     =8,
	clk_64    =64,
	clk_256   =256,
	clk_1024  =1024,
	clk_EXTERNAL_1 =6,  //External clock source on T0 pin. Clock on falling edge.
	clk_EXTERNAL_2 =7,  //External clock source on T0 pin. Clock on rising edge.
};

enum Timer_Compare_Match{
	/*WARNING: THIS VALUE IN NORMAL MODE*/
	NORMAL_PORT_OPERATION,
	TOGGLE_OC,
	CLEAR_OC,
	SET_OC
};

enum Timer_Interrupt_state{
	Timer_Output_Compare_Match_Interrupt_Enable,
	Timer_Overflow_Interrupt_Enable
};



		typedef struct Timer0_Configuration
		{
			//mode
			enum Timer_Modes            timer0_mode;
			//prescaler
			enum Timer_Prescaler        timer0_prescaler;
			//output compare behaveure
			enum Timer_Compare_Match    timer0_oc_pin;
			//interrupt or not
			enum Timer_Interrupt_state  timer0_int;
		 }Timer0_config;  //declare this object to use it directly in main()- instead of declare it in main() one more time. 

		typedef struct Timer1_Configuration
		{
			//mode
			enum Timer1_Modes            timer1_mode;
			//prescaler
			enum Timer_Prescaler        timer1_prescaler;
			//output compare behaveure
			enum Timer_Compare_Match    timer1_oc_pin;
			//interrupt or not
			enum Timer_Interrupt_state  timer1_int;
		}Timer1_config;

		typedef struct Timer2_Configuration
		{
			//mode
			enum Timer_Modes            timer2_mode;
			//prescaler
			enum Timer_Prescaler        timer2_prescaler;
			//output compare behaveure
			enum Timer_Compare_Match    timer2_oc_pin;
			//interrupt or not
			enum Timer_Interrupt_state  timer2_int;
		}Timer2_config;


/****************************************************************************/

u8 Timer0_Init(struct Timer0_Configuration config0_infos );
u8 Timer0_Read_Counter_Value(void);
void Timer0_Set_Output_Compare_value(u8 OCR_Register_value );
/*******************************************************************/

u8 Timer1_Init(struct Timer1_Configuration  config1_infos );
u16 Timer1_Read_Counter_Value(void);
void Timer1_Set_OCR1A(u16 OCR1_Register_value );
void Timer1_Set_OCR1B(u16 OCR1_Register_value );
/*******************************************************************/

u8 Timer2_Init(struct Timer2_Configuration  config_infos );
u8 Timer2_Read_Counter_Value(void);
void Timer2_Set_Output_Compare_value(u8 OCR_Register_value );
/********************************************************************/

#endif
