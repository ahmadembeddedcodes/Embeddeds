/*
 * I2C_TWI.c
 *
 * Created: 20/07/2019 12:23:34 م
 * Author : Ahmad
 */ 


#include <avr/io.h>
#include "i2c.h"
#include "LCD_2X16.h"
#include "delay.h"


int main(void)
{
   LCD_Init();
      
	 I2C_MASTER_INIT();
	 RTC_Set_Time(0x05,0x55,0x00); //time:  05:55:00
	 RTC_Set_Date(0x06,0x06,0x95); //date:  06:06:95
	 
	 u8 s,m,h;
	 
	while (1) 
    {
	  RTC_DS1307_GET_TIME(&h,&m,&s); 
	/* you must convert this integer values to char first */ 
	/* ana zehgt*/
			
	  LCD_Print_Char(h);
	  LCD_Print_Char(':');
	  LCD_Print_Char(m);
	  LCD_Print_Char(':');
	  LCD_Print_Char(s);
	  
	  LCD_Clear();
	  
    }
}

