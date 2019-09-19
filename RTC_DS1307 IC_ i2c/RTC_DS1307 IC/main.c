/*
 * RTC_DS1307 IC.c
 *
 * Created: 23/07/2019 12:00:57 ص
 * Author : Ahmad
 */ 

#include <avr/io.h>
#include "RTC_DS1307.h" 

int main(void)
{
   I2C_MASTER_INIT(); 
   
   RTC_Set_Time(0x10,0x50,0x00); // time: 10:50:00
   RTC_Set_Date(0x06,0x06,0x95); // date: 06:06:1995
   
   
	 while (1) 
    {
    }
}

