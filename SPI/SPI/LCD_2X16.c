#include "LCD_2X16.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "delay.h"
#include "GPIO.h"

/* send a command to lcd*/ 
void LCD_Send_Command(u8 CMD){
	//RS,R/W must be 0 to enable commands

	GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, R_W_PIN, 0);
	GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, RS_PIN,  0);
	
	if (LCD_MODE == 8)
	{
		//*LCD_DATA_PORT = CMD ; 
		GPIO_U8_PORT_WRITE(LCD_DATA_PORT , CMD);
		
		GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 1);
	    delay_ms(1);
		GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 0);
		delay_ms(2); 
	}
	
	else
	{
	 /* SEND FIRST NIBBLE - HIGH NIBBLE */ 	
		GPIO_U8_PORT_WRITE(LCD_DATA_PORT , (CMD&0xf0) );
		
		//HIGH-TO-LOW_ SIGNAL
       GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 1);
       delay_ms(1);
       GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 0);
       delay_ms(2);
      

	/*SEND SECOND NIBBLE - LOW NIBBLE */	
		GPIO_U8_PORT_WRITE(LCD_DATA_PORT , (CMD<<4) );
		
		//HIGH-TO-LOW_ SIGNAL
      GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 1);
      delay_ms(1);
      GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 0);
      delay_ms(2);

	}

}

/*initialize the lcd*/
void LCD_Init(){
	
  delay_ms(15);  
 
  
  if (LCD_MODE ==8)
  {
    GPIO_U8_PORT_DIR( LCD_DATA_PORT , u8_Direction_output);   
   
   //set control pins as output 
    GPIO_U8_PIN_DIR(LCD_CONTROL_PORT , RS_PIN,1 );
    GPIO_U8_PIN_DIR(LCD_CONTROL_PORT , ENABLE_PIN,1 );
	GPIO_U8_PIN_DIR(LCD_CONTROL_PORT , R_W_PIN,1 );	
	   
    }
  
  else   // mode must be 4 bit mode
  {
	 //  LCD_DATA_PORT_DIRECTION |= (1<<PIN);
	   GPIO_U8_PIN_DIR(LCD_DATA_PORT , D4,1 );
	   GPIO_U8_PIN_DIR(LCD_DATA_PORT , D5,1 );
	   GPIO_U8_PIN_DIR(LCD_DATA_PORT , D6,1 );
	   GPIO_U8_PIN_DIR(LCD_DATA_PORT , D7,1 );
	   
	   //set control pins as output
	   GPIO_U8_PIN_DIR(LCD_CONTROL_PORT , RS_PIN,1 );	
	   GPIO_U8_PIN_DIR(LCD_CONTROL_PORT , ENABLE_PIN,1 );	
	   GPIO_U8_PIN_DIR(LCD_CONTROL_PORT , R_W_PIN,1 );		  
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
   GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, RS_PIN, 1);
   GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, R_W_PIN, 0);
  
  if (LCD_MODE ==8){
	  
	   GPIO_U8_PORT_WRITE(LCD_DATA_PORT , ch) ; 
	  //HIGH-TO-LOW_ SIGNAL	  
	  GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 1);
	  delay_ms(1);
	  GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 0);
	  delay_ms(2);
	  
  }
  else { 
	    GPIO_U8_PORT_WRITE(LCD_DATA_PORT , (ch&0xf0)) ;

 	  //HIGH-TO-LOW_ SIGNAL
		GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 1);
		delay_ms(1);
		GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 0);
		delay_ms(2);	
		
	
       GPIO_U8_PORT_WRITE(LCD_DATA_PORT , (ch<<4)) ;
	//HIGH-TO-LOW_ SIGNAL
	 GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 1);
	 delay_ms(1);
	 GPIO_U8_PIN_WRITE(LCD_CONTROL_PORT, ENABLE_PIN, 0);
	 delay_ms(2);
	 
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