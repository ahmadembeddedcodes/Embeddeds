/*
 * adc_config.h
 *
 * Created: 28/07/2019 12:56:08 م
 *  Author: Ahmad
 */ 

/* this file used to set your desired configuration _ without any complicated steps of configurations */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#include "adc.h"

/** important note: set your desired channel pin as input - Billah 3lik ya 5ekh ma tensa **/ 

/* here for user changing -- Note: you can choose options from file {adc.h} */ 
#define VoltageReference    AVCC_EXT_CAPACITOR
#define Justification       LEFT
#define PrescalerAdc        by_16
#define AdcInterruptEn      Disable_ 
/*************end of user area **************************/ 



/*****PLEASE DON'T PLAY HERE- 3SHAN 5ATRI*************************************/
ADC_configuration ADC_conf; // create a variable to set all adc settings 
void ADC_SET_CONFIG(void);  //perform the configurations

#endif /* ADC_CONFIG_H_ */