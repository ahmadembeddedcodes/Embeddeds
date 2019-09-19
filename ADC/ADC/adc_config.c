/*
 * adc_config.c
 *
 * Created: 28/07/2019 02:44:39 م
 *  Author: Ahmad
 */ 
#include "adc_config.h"
#include "adc.h"



void ADC_SET_CONFIG(void){
ADC_conf.Vref= VoltageReference ;
ADC_conf.prescaler=PrescalerAdc;
ADC_conf.just=Justification;
ADC_conf.En_Dis_interrupt_adc= AdcInterruptEn ; 		
}

