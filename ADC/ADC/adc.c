/*
 * adc.c
 *
 * Created: 23/07/2019 01:55:35 م
 *  Author: Ahmad
 */ 


#include "adc.h" // registers and bits and functions 
#include "adc_config.h"  // Configuration file  
#include "DATA_TYPES.h"
#include <avr/io.h>
/*ADC_configuration ADC_conf;*/



void ADC_INIT(){               


  	
	  //enable adc  
	 ADCSRA_REG |=(1<<ADEN_BIT); 
/************************************************************************/	
		//SET voltage reference 
	ADMUX_REG |=    ((ADC_conf.Vref << 6) & 0xC0 );  
	  
/************************************************************************/	
	//set prescaller-conversion speed    
	ADCSRA_REG |=   (ADC_conf.prescaler & 0x03);
/************************************************************************/	       
	//set left/RIGHT adjustment   
	ADMUX_REG |=    (ADC_conf.just  << ADLAR_BIT);  
	 //ADC_conf.just = 0 or 1
/************************************************************************/	 	   
	//enable/disable interrupt if want 
    ADCSRA_REG |=    (ADC_conf.En_Dis_interrupt_adc << ADIE_BIT );   
	//ADC_conf.En_Dis_interrupt_adc	 = 0 or 1				   
}                              


u8 ADC_READ(u8 ADC_Chacnnel_number){
 u16 ADC_10_Bit =0 ; 
 u8 ADClow=0;
// u8 ADChigh=0;
 // set desired channel 
  ADMUX_REG |= (ADC_Chacnnel_number & (0x07));
  
 //start conversion 
 ADCSRA_REG |=(1<<ADSC_BIT); 
 
 //wait a flag - till conversion is complete 
 while (!(ADCSRA_REG &(1<<ADIF_BIT))); 
 
 
 //return your data low,high
/* you must read low register first, but if you want to read 8 bit, 
 you can read high register only and neglect the low register
 you should to know, when you reading the low byte, 
 the high byte never changed - to keep data safe*/
 
 ADClow= ADCL_REG;
 //ADChigh= ADCH_REG ; 
 

 ADC_10_Bit |=((8<<ADCH_REG) | ADClow);  // THIS FOR LEFT JUSTIFICATION
 
  //start new conversion
  ADCSRA_REG |=(1<<ADSC_BIT);
  
  
 return ADC_10_Bit ; 

}