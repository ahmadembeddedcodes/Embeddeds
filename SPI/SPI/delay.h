#ifndef DELAY_H_
#define DELAY_H_

#include "DATA_TYPES.h"



#ifdef F_CPU
#define clock   F_CPU
#else
#define clock 1000000UL
#endif

#define Error_Extra_Cycles 20
u32 DelayCount;

#define delay_ms(x)\
	for( DelayCount = ((clock/1000)*x/Error_Extra_Cycles); DelayCount >0; DelayCount--)\
	\
	{ __asm("NOP"); }
	
	
#endif