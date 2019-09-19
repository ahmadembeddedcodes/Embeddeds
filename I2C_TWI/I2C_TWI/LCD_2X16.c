#include "LCD_2X16.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "delay.h"
#include "GPIO_huge_modified.h"

/* send a command to lcd*/ 
void LCD_Send_Command(u8 CMD){
	//RS,R/W must be 0 to enable commands
	
	*LCD_CONTROL_PORT &=~(1<<R_W_PIN);
	*LCD_CONTROL_PORT &=~(1<<RS_PIN);
	
	if (LCD_MODE == 8)
	{
		*LCD_DATA_PORT = CMD ; 
		//HIGH-TO-LOW_ SIGNAL
		*LCD_CONTROL_PORT |=(1<<ENABLE_PIN);
		delay_ms(1); 
		*LCD_CONTROL_PORT &=~(1<<ENABLE_PIN);
		delay_ms(2); 
	}
	
	else
	{
	 /* SEND FIRST NIBBLE - HIGH NIBBLE */ 	
		*LCD_DATA_PORT = (CMD&0xf0) ; // High Nibble 
		//HIGH-TO-LOW_ SIGNAL
		*LCD_CONTROL_PORT |=(1<<ENABLE_PIN);
		delay_ms(1);
		*LCD_CONTROL_PORT &=~(1<<ENABLE_PIN);
		delay_ms(100);
		
	/*SEND SECOND NIBBLE - LOW NIBBLE */	
		*LCD_DATA_PORT = (CMD<<4) ; // LOW Nibble 
		//HIGH-TO-LOW_ SIGNAL
		*LCD_CONTROL_PORT |=(1<<ENABLE_PIN);
		delay_ms(1);
		*LCD_CONTROL_PORT &=~(1<<ENABLE_PIN);
		delay_ms(1);
	}

}

/*initialize the lcd*/
void LCD_Init(){
	
  delay_ms(5);  
 
  
  if (LCD_MODE ==8)
  {
   *LCD_DATA_PORT_DIRECTION = 0xFF; 
   
   //set control pins as output 
   *LCD_CONTROL_PORT_DIR |=(1<<RS_PIN); 
   *LCD_CONTROL_PORT_DIR |=(1<<ENABLE_PIN); 
   *LCD_CONTROL_PORT_DIR |=(1<<R_W_PIN); 	
  }
  
  else   // mode must be 4 bit mode
  {
	 //  LCD_DATA_PORT_DIRECTION |= (1<<PIN);
	   *LCD_DATA_PORT_DIRECTION |=(1<<D4);
	   *LCD_DATA_PORT_DIRECTION |=(1<<D5);
	   *LCD_DATA_PORT_DIRECTION |=(1<<D6);
	   *LCD_DATA_PORT_DIRECTION |=(1<<D7);
	   
	   //set control pins as output
	   *LCD_CONTROL_PORT_DIR |=(1<<RS_PIN);
	   *LCD_CONTROL_PORT_DIR |=(1<<ENABLE_PIN);
	   *LCD_CONTROL_PORT_DIR |=(1<<R_W_PIN);	  
  }

   //check the mode 
	if(LCD_MODE==8)
	{   //0x38-0x0E-0x01 
	
		LCD_Send_Command(MODE_8);
		LCD_Send_Command(DISPLAY_ON_CURSOR_BLINKING);
		LCD_Send_Command(CLEAR_SCREEN);
	}
	else{	
 		
		LCD_Send_Command(0x33); 
		LCD_Send_Command(0x32);  
		LCD_Send_Command(MODE_4);   
		LCD_Send_Command(DISPLAY_ON_CURSOR_BLINKING);   
		LCD_Send_Command(CLEAR_SCREEN);
		_delay_ms(2);  
		LCD_Send_Command(RETURN_HOME);    
		LCD_Send_Command(INCREMENT_CURSOR);  
	   }
	  
}

/*send one charachter to lcd */ 
void LCD_Print_Char(u8 ch){
  //you must make RS as high voltage and R/W is low volt
  *LCD_CONTROL_PORT |=(1<<RS_PIN);
  *LCD_CONTROL_PORT &=~(1<<R_W_PIN);
  
  
  if (LCD_MODE ==8){
	  
	   *LCD_DATA_PORT = ch; //8 bit mode
	  //HIGH-TO-LOW_ SIGNAL
	  *LCD_CONTROL_PORT |=(1<<ENABLE_PIN);
	  delay_ms(1);
	  *LCD_CONTROL_PORT &=~(1<<ENABLE_PIN);
	  delay_ms(2);  
	  
  }
  else {
	  *LCD_DATA_PORT = (ch & 0xf0); 
	  	  //HIGH-TO-LOW_ SIGNAL
	  	  *LCD_CONTROL_PORT |=(1<<ENABLE_PIN);
	  	  delay_ms(1);
	  	  *LCD_CONTROL_PORT &=~(1<<ENABLE_PIN);
	  	  delay_ms(1);
		
	*LCD_DATA_PORT = (ch <<4);
	//HIGH-TO-LOW_ SIGNAL
	*LCD_CONTROL_PORT |=(1<<ENABLE_PIN);
	delay_ms(1);
	*LCD_CONTROL_PORT &=~(1<<ENABLE_PIN);
	delay_ms(1);		
  }
 
}

/*send a srting */
void LCD_Print_str(char * str){
	u8 counter=0; 
	
	while(str[counter] !='\0')
	     {
			  LCD_Print_Char(str[counter]);
			  counter++;
		 }
}

void LCD_Clear(void){
	
	LCD_Send_Command(CLEAR_SCREEN);
	_delay_ms(2);
}

void LCD_Set_Cursor_Position(u8 Row , u8 column){
	
	
}