
#include "TIMER0.h"
#include "DATA_TYPES.h"


u8 Timer0_Init(struct Timer0_Configuration config_infos ){
	
  /*****set el-mode	for the timer */
  switch(config_infos.timer0_mode)
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
   switch(config_infos.timer0_prescaler)
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
  switch(config_infos.timer0_int)
  {
	  case Timer0_Output_Compare_Match_Interrupt_Enable: 
	      TIMSK_REG |=(1<<OCIE0_BIT);
	     break; 
		 
	  case Timer0_Overflow_Interrupt_Enable:
	      TIMSK_REG |=(1<<TOIE0_BIT);
	  break;
	  
	  default: // Timer interrupt is off by default 
	     TIMSK_REG &=~(1<<TOIE0_BIT)|(1<<OCIE0_BIT);
	     break; 	 
  }
  /*** set the o/p compare status **/ 	
 
//** choose the OC0 pin according to it's mode as datasheet says :D */ 

//1- Compare Output Mode, non-PWM Mode
 if (config_infos.timer0_mode==NORMAL) 
  {
	switch(config_infos.timer0_oc0_pin) 
   {
	 case TOGGLE_OC0: 
	    TCCR0_REG |=(1<<COM00_BIT);
	     break; 
		 
	case CLEAR_OC0:
	    TCCR0_REG |=(1<<COM01_BIT);
	     break;
		 
	case SET_OC0:
	     TCCR0_REG |=(1<<COM00_BIT)|(1<<COM01_BIT);
	     break;
		 
	default: // must be => NORMAL_PORT_OPERATION[NORMAL]
	     TCCR0_REG &=~(1<<COM00_BIT)|(1<<COM01_BIT);
	     break; 	  
   }  
  }
//2- Compare Output Mode, Fast PWM Mode
else if (config_infos.timer0_mode==FAST_PWM )
{
	switch(config_infos.timer0_oc0_pin)
	{
		case CLEAR_OC0:   // none- inverting mode 
		TCCR0_REG |=(1<<COM01_BIT);
		break;
		
		case SET_OC0:    // inverting mode 
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
		switch(config_infos.timer0_oc0_pin)
		{
			case CLEAR_OC0:   // none- inverting mode
			TCCR0_REG |=(1<<COM01_BIT);
			break;
		
			case SET_OC0:    // inverting mode
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
