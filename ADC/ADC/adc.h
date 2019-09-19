/*
 * adc.h
 *
 * Created: 23/07/2019 01:55:24 م
 *  Author: Ahmad
 */ 

#ifndef ADC_H_
#define ADC_H_

#include "DATA_TYPES.h"

#define ADCSRA_REG  *((volatile u8*const)0x26)
#define ADMUX_REG   *((volatile u8*const)0x27)
#define SFIOR_REG   *((volatile u8*const)0x50)
#define ADCL_REG    *((volatile u8*const)0x24)
#define ADCH_REG    *((volatile u8*const)0x25) 

/*** ADCSRA_REG  BITS****/
#define  ADPS0_BIT  0
#define  ADPS1_BIT  1
#define  ADPS2_BIT  2
#define  ADIE_BIT   3
#define  ADIF_BIT   4
#define  ADATE_BIT  5
#define  ADSC_BIT   6
#define  ADEN_BIT   7 
/****************************/

/* ADMUX_REG  BITS *********/ 
#define  MUX0_BIT   0
#define  MUX1_BIT   1
#define  MUX2_BIT   2
#define  MUX3_BIT   3
#define  MUX4_BIT   4
#define  ADLAR_BIT  5
#define  REFS0_BIT  6
#define  REFS1_BIT  7
/***************************/

/*******DATA TYPES******************************/
//VOLTAGE_REFERENCE 
typedef enum {
	AREF=0,
	AVCC_EXT_CAPACITOR,
	RESEVEDxx,
	INTERNAL_2_56VOLT
	}VrefSource;
//ADC_Channels

typedef enum {
	Disable_=0,
	Enable_
	}ADC_Interrupt_Status;

typedef enum {
  by_2=0,
  by_2_,
  by_4,
  by_8,
  by_16,
  by_32,
  by_64,
  by_128
}ADC_Prescaler;

//ADC_Justification
typedef enum {
	RIGHT=0,
	LEFT
	}ADC_Justification;
	
	
/* here: combinig all settings in one struct*/ 	
 typedef struct {
	//voltage reference 
	 VrefSource   Vref;
	//left or right adjustment
	 ADC_Justification   just; 
	//choose prescaler
	 ADC_Prescaler       prescaler; 
	//interrupt 
	ADC_Interrupt_Status  En_Dis_interrupt_adc; 
	
	}ADC_configuration;


// ADC_conf adc;
// adc ={Vref=AREF,just=LEFT,prescaler= by_16}; 
/****************************************/
void ADC_INIT(); 
u8 ADC_READ(u8 ADC_Chacnnel_number); 

#endif /* ADC_H_ */