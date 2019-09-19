/*
 * SPI.c
 *
 * Created: 09/07/2019 06:37:38 م
 * Author : Ahmad
 */ 
#include <stdlib.h>
#include <avr/io.h>
#include "SPI.h"
#include "LCD_2X16.h"

#define gets(s) #s

int main(void)
{
  u8 my_turn =1; 
  u8 my_data; 
  u8 *buffer;
     	
  spi_init_master(); 
  LCD_Init();
  
  PB_Init('a', 0); 
  
  LCD_Print_str("hi yad"); 
    while (1) 
    {
	  	
	  if( ! PB_IsPressed('a',0 ) )
	  {
		//send a data to usb to secon micro 
		spi_send('M');
		 LCD_Print_str("sent");
		 LCD_Clear(); 
		my_turn =0 ;   
	  }
	  
	  else if ( PB_IsPressed('a',0 ) )
	  {
		  //recive data form spi 
		  my_data = spi_receive(); 
		  //clear lcd
		  LCD_Clear(); 
		  //print this message on lcd
		  itoa(my_data,buffer,8);
		  LCD_Print_str(buffer);  
         my_turn =1; 
	  }
	  
	  else {
		  
		  
	  }
	   	
		
    }
}

