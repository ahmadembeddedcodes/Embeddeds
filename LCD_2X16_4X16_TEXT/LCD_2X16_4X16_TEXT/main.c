/*
 * LCD_2X16_4X16_TEXT.c
 *
 * Created: 07/07/2019 10:05:39 م
 * Author : Ahmad
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "delay.h"
#include "LCD_2X16.h"

int main(void)
{
   LCD_Init();
   
	while (1) 
    {
       LCD_Print_str("ya rab");
	   delay_ms(500);
	   LCD_Clear(); 
	   delay_ms(500); 	
    }
}

