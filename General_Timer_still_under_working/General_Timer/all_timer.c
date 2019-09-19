
#include "all_timer.h"
#include "DATA_TYPES.h"

u8 Timer0_Init(struct Timer0_Configuration config0_infos ){
	
	/*****set el-mode	for the timer */
	switch(config0_infos.timer0_mode)
	{
		case PHASE_CORRECT:
		TCCR0_REG |= (1<<WGM00_BIT);
		break ;
		
		case CTC:
		TCCR0_REG |= (1<<WGM01_BIT);
		break ;
		
		case FAST_PWM :
		TCCR0_REG |= (1<<WGM00_BIT) | (1<<WGM01_BIT);
		break ;
		
		default :   /*must be the Normal Mode here*/
		TCCR0_REG &= ~(1<<WGM00_BIT) | (1<<WGM01_BIT);
		break;
	}
	
	/** prescaller**/
	switch(config0_infos.timer0_prescaler)
	{
		// No prescaller
		case clk_0 :
		TCCR0_REG |= (1<<CS00_BIT);
		break;
		
		case clk_8 :
		TCCR0_REG |= (1<<CS01_BIT);
		break;
		
		case clk_64 :
		TCCR0_REG |= (1<<CS00_BIT) | (1<<CS01_BIT);
		break;
		
		case clk_256 :
		TCCR0_REG |= (1<<CS02_BIT);
		break;
		
		case clk_1024 :
		TCCR0_REG |= (1<<CS00_BIT) | (1<<CS02_BIT);
		break;
		
		case clk_EXTERNAL_1 :
		TCCR0_REG |= (1<<CS01_BIT) | (1<<CS02_BIT);
		break;
		
		case clk_EXTERNAL_2 :
		TCCR0_REG |= (1<<CS00_BIT) | (1<<CS01_BIT)|(1<<CS02_BIT);
		break;
		
		default:
		// No_clock_source
		TCCR0_REG &= ~(1<<CS00_BIT)|(1<<CS01_BIT)|(1<<CS02_BIT);
		break;
	}
	
	/** check if there is interrupt has to be enabled or not */
	switch(config0_infos.timer0_int)
	{
		case Timer_Output_Compare_Match_Interrupt_Enable:
		TIMSK_REG |=(1<<OCIE0_BIT);
		break;
		
		case Timer_Overflow_Interrupt_Enable:
		TIMSK_REG |=(1<<TOIE0_BIT);
		break;
		
		default: // Timer interrupt is off by default
		TIMSK_REG &=~(1<<TOIE0_BIT)|(1<<OCIE0_BIT);
		break;
	}
	/*** set the o/p compare status **/
	
	//** choose the OC0 pin according to it's mode as datasheet says :D */

	//1- Compare Output Mode, non-PWM Mode
	if (config0_infos.timer0_mode== NORMAL)
	{
		switch(config0_infos.timer0_oc_pin)
		{
			case TOGGLE_OC:
			TCCR0_REG |=(1<<COM00_BIT);
			break;
			
			case CLEAR_OC:
			TCCR0_REG |=(1<<COM01_BIT);
			break;
			
			case SET_OC:
			TCCR0_REG |=(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
			
			default: // must be => NORMAL_PORT_OPERATION[NORMAL]
			TCCR0_REG &=~(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
		}
	}
	//2- Compare Output Mode, Fast PWM Mode
	else if (config0_infos.timer0_mode==FAST_PWM )
	{
		switch(config0_infos.timer0_oc_pin)
		{
			case CLEAR_OC:   // none- inverting mode
			TCCR0_REG |=(1<<COM01_BIT);
			break;
			
			case SET_OC:    // inverting mode
			TCCR0_REG |=(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
			
			default: // must be => NORMAL_PORT_OPERATION[NORMAL]
			TCCR0_REG &=~(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
		}
	}
	//3- Compare Output Mode, PHASE CORRECT
	else
	{
		switch(config0_infos.timer0_oc_pin)
		{
			case CLEAR_OC:   // none- inverting mode
			TCCR0_REG |=(1<<COM01_BIT);
			break;
			
			case SET_OC:    // inverting mode
			TCCR0_REG |=(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
			
			default: // must be => NORMAL_PORT_OPERATION[NORMAL]
			TCCR0_REG &=~(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
		}
	}//end of if() statement

	return NO_ERROR ;

}
u8 Timer0_Read_Counter_Value(void){
	
	return TCNT0_REG ;
}
void Timer0_Set_Output_Compare_value(u8 OCR0_Register_value ){
	
	OCR0_REG = OCR0_Register_value;
	
}

/**********************************************************************/
u8 Timer2_Init(struct Timer2_Configuration config2_infos ){
	
	/*****set el-mode	for the timer */
	switch(config2_infos.timer2_mode)
	{
		case PHASE_CORRECT :
		TCCR0_REG |= (1<<WGM00_BIT);
		break ;
		
		case CTC :
		TCCR0_REG |= (1<<WGM01_BIT);
		break ;
		
		case FAST_PWM :
		TCCR0_REG |= (1<<WGM00_BIT) | (1<<WGM01_BIT);
		break ;
		
		default :   /*must be the Normal Mode here*/
		TCCR0_REG &= ~(1<<WGM00_BIT) | (1<<WGM01_BIT);
		break;
	}
	
	/** prescaller**/
	switch(config2_infos.timer2_prescaler)
	{
		// No prescaller
		case clk_0 :
		TCCR0_REG |= (1<<CS00_BIT);
		break;
		
		case clk_8 :
		TCCR0_REG |= (1<<CS01_BIT);
		break;
		
		case clk_64 :
		TCCR0_REG |= (1<<CS00_BIT) | (1<<CS01_BIT);
		break;
		
		case clk_256 :
		TCCR0_REG |= (1<<CS02_BIT);
		break;
		
		case clk_1024 :
		TCCR0_REG |= (1<<CS00_BIT) | (1<<CS02_BIT);
		break;
		
		case clk_EXTERNAL_1 :
		TCCR0_REG |= (1<<CS01_BIT) | (1<<CS02_BIT);
		break;
		
		case clk_EXTERNAL_2 :
		TCCR0_REG |= (1<<CS00_BIT) | (1<<CS01_BIT)|(1<<CS02_BIT);
		break;
		
		default:
		// No_clock_source
		TCCR0_REG &= ~(1<<CS00_BIT)|(1<<CS01_BIT)|(1<<CS02_BIT);
		break;
	}
	
	/** check if there is interrupt has to be enabled or not */
	switch(config2_infos.timer2_int)
	{
		case Timer_Output_Compare_Match_Interrupt_Enable:
		TIMSK_REG |=(1<<OCIE0_BIT);
		break;
		
		case Timer_Overflow_Interrupt_Enable:
		TIMSK_REG |=(1<<TOIE0_BIT);
		break;
		
		default: // Timer interrupt is off by default
		TIMSK_REG &=~(1<<TOIE0_BIT)|(1<<OCIE0_BIT);
		break;
	}
	/*** set the o/p compare status **/
	
	//** choose the OC0 pin according to it's mode as datasheet says :D */

	//1- Compare Output Mode, non-PWM Mode
	if (config2_infos.timer2_mode==NORMAL)
	{
		switch(config2_infos.timer2_oc_pin)
		{
			case TOGGLE_OC:
			TCCR0_REG |=(1<<COM00_BIT);
			break;
			
			case CLEAR_OC:
			TCCR0_REG |=(1<<COM01_BIT);
			break;
			
			case SET_OC:
			TCCR0_REG |=(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
			
			default: // must be => NORMAL_PORT_OPERATION[NORMAL]
			TCCR0_REG &=~(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
		}
	}
	//2- Compare Output Mode, Fast PWM Mode
	else if (config2_infos.timer2_mode==FAST_PWM )
	{
		switch(config2_infos.timer2_oc_pin)
		{
			case CLEAR_OC:   // none- inverting mode
			TCCR0_REG |=(1<<COM01_BIT);
			break;
			
			case SET_OC:    // inverting mode
			TCCR0_REG |=(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
			
			default: // must be => NORMAL_PORT_OPERATION[NORMAL]
			TCCR0_REG &=~(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
		}
	}
	//3- Compare Output Mode, PHASE CORRECT
	else
	{
		switch(config2_infos.timer2_oc_pin)
		{
			case CLEAR_OC:   // none- inverting mode
			TCCR0_REG |=(1<<COM01_BIT);
			break;
			
			case SET_OC:    // inverting mode
			TCCR0_REG |=(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
			
			default: // must be => NORMAL_PORT_OPERATION[NORMAL]
			TCCR0_REG &=~(1<<COM00_BIT)|(1<<COM01_BIT);
			break;
		}
	}//end of if() statement

	return NO_ERROR ;

}
u8 Timer2_Read_Counter_Value(void){
	
	return TCNT2_REG ;// should be defined
}
void Timer2_Set_Output_Compare_value(u8 OCR2_Register_value ){
	
	OCR2_REG = OCR2_Register_value;
	
}

/*******************************************************/
/************TIMER 1 ***********************************/
/*******************************************************/

u8 Timer1_Init(struct Timer1_Configuration config1_infos ){
	
	/*****set el-mode	for the timer */
	/* to choose the mode please choose it according to the mode number in the datasheet*/ 
	
	//take first 2 bit [WGM10,11] AND put it in TCCR1A register
		TCCR1A_REG = (TCCR1A_REG | (config1_infos.timer1_mode&0x03));
		// take bit 3,4 bit [WGM10,11] AND put it in TCCR1A register 
		TCCR1B_REG = (TCCR1B_REG | (config1_infos.timer1_mode&0x06));
		
	
	
	/** prescaller**/
	switch(config1_infos.timer1_prescaler)
	{
		// No prescaller
		case clk_0 :
		TCCR1B_REG |= (1<<CS10_BIT);
		break;
		
		case clk_8 :
		TCCR1B_REG |= (1<<CS11_BIT);
		break;
		
		case clk_64 :
		TCCR1B_REG |= (1<<CS10_BIT) | (1<<CS11_BIT);
		break;
		
		case clk_256 :
		TCCR1B_REG |= (1<<CS12_BIT);
		break;
		
		case clk_1024 :
		TCCR1B_REG |= (1<<CS10_BIT) | (1<<CS12_BIT);
		break;
		
		case clk_EXTERNAL_1 :
		TCCR1B_REG |= (1<<CS11_BIT) | (1<<CS12_BIT);
		break;
		
		case clk_EXTERNAL_2 :
		TCCR1B_REG |= (1<<CS10_BIT) | (1<<CS11_BIT)|(1<<CS12_BIT);
		break;
		
		default:
		// No_clock_source
		TCCR1B_REG &= ~(1<<CS10_BIT)|(1<<CS11_BIT)|(1<<CS12_BIT);
		break;
	}
	
	/** check if there is interrupt has to be enabled or not */
	switch(config1_infos.timer1_int)
	{
		case Timer_Output_Compare_Match_Interrupt_Enable:
		TIMSK_REG |=(1<<OCIE1A_BIT)|(1<<OCIE1B_BIT);
		break;
		
		case Timer_Overflow_Interrupt_Enable:
		TIMSK_REG |=(1<<TOIE1_BIT);
		break;
		
		default: // Timer interrupt is off by default
		TIMSK_REG &=~(1<<TOIE1_BIT)|(1<<OCIE1A_BIT)|(1<<OCIE1B_BIT);
		break;
	}
	/*** set the o/p compare status **/
	
	//** choose the OC0 pin according to it's mode as datasheet says :D */

	//1- Compare Output Mode, non-PWM Mode
	if (config1_infos.timer1_mode==NORMAL_1)
	{
		switch(config1_infos.timer1_oc_pin)
		{
			case TOGGLE_OC:
			TCCR1B_REG |=(1<<COM1B0_BIT);
			TCCR1A_REG |=(1<<COM1A0_BIT);
			break;
			
			case CLEAR_OC:
			TCCR1B_REG |=(1<<COM1B1_BIT);
			TCCR1A_REG |=(1<<COM1A1_BIT);
			break;
			
			case SET_OC:
			TCCR1B_REG |=(1<<COM1B0_BIT)|(1<<COM1B1_BIT);
			TCCR1B_REG |=(1<<COM1A0_BIT)|(1<<COM1A1_BIT);
			break;
			
			default: // must be => NORMAL_PORT_OPERATION[NORMAL]
			TCCR1B_REG &=~(1<<COM1B0_BIT)|(1<<COM1B1_BIT);
			TCCR1B_REG &=~(1<<COM1A0_BIT)|(1<<COM1A1_BIT);
			break;
		}
	}
	//2- Compare Output Mode, Fast PWM Mode
	else if (config1_infos.timer1_mode==FAST_PWM_8BIT )
	{
		switch(config1_infos.timer1_oc_pin)
		{
		
		case TOGGLE_OC:
		TCCR1B_REG |=(1<<COM1B0_BIT);
		TCCR1A_REG |=(1<<COM1A0_BIT);
		break;
		
		case CLEAR_OC:
		TCCR1B_REG |=(1<<COM1B1_BIT);
		TCCR1A_REG |=(1<<COM1A1_BIT);
		break;
		
		case SET_OC:
		TCCR1B_REG |=(1<<COM1B0_BIT)|(1<<COM1B1_BIT);
		TCCR1B_REG |=(1<<COM1A0_BIT)|(1<<COM1A1_BIT);
		break;
		
		default: // must be => NORMAL_PORT_OPERATION[NORMAL]
		TCCR1B_REG &=~(1<<COM1B0_BIT)|(1<<COM1B1_BIT);
		TCCR1B_REG &=~(1<<COM1A0_BIT)|(1<<COM1A1_BIT);
		break;		}
	}
	//3- Compare Output Mode, PHASE CORRECT
	else
	{
		switch(config1_infos.timer1_oc_pin)
		{
					case TOGGLE_OC:
					TCCR1B_REG |=(1<<COM1B0_BIT);
					TCCR1A_REG |=(1<<COM1A0_BIT);
					break;
					
					case CLEAR_OC:
					TCCR1B_REG |=(1<<COM1B1_BIT);
					TCCR1A_REG |=(1<<COM1A1_BIT);
					break;
					
					case SET_OC:
					TCCR1B_REG |=(1<<COM1B0_BIT)|(1<<COM1B1_BIT);
					TCCR1B_REG |=(1<<COM1A0_BIT)|(1<<COM1A1_BIT);
					break;
					
					default: // must be => NORMAL_PORT_OPERATION[NORMAL]
					TCCR1B_REG &=~(1<<COM1B0_BIT)|(1<<COM1B1_BIT);
					TCCR1B_REG &=~(1<<COM1A0_BIT)|(1<<COM1A1_BIT);
					break;
		}
	}//end of if() statement
	
	return NO_ERROR ;

}
u16 Timer1_Read_Counter_Value(void){
	
	return TCNT1_REG_GET ;
}
void Timer1_Set_OCR1A(u16 OCR1_Register_value ){
	
  OCR1A_REG_SET(OCR1_Register_value);
	
}
void Timer1_Set_OCR1B(u16 OCR1_Register_value ){
	
  OCR1B_REG_SET(OCR1_Register_value);
	
}
