/* 
 * File:   lcd.h
 * Author: Ahmad
 *
 * Created on February 14, 2020, 5:23 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#include "LCD_porty_layer.h"
#include <pic18f452.h>
// Function Declarations for Generic Functions.c
#define LCD_PORT LCD_DATA_PORT
// Define Pins
#define LCD_E    			ENABLE_PIN          // Enable pin for LCD
#define LCD_RS	 			REG_SELECT_PIN      // RS pin for LCD
#define LCD_Data_Bus_D4		DATA_LINE_D4		// Data bus bit 4
#define LCD_Data_Bus_D5		DATA_LINE_D5		// Data bus bit 5
#define LCD_Data_Bus_D6		DATA_LINE_D6		// Data bus bit 6
#define LCD_Data_Bus_D7		DATA_LINE_D7		// Data bus bit 7

// Define Pins direction registrers
#define LCD_E_Dir     			ENABLE_PIN_DIR
#define LCD_RS_Dir   	 		REG_SELECT_PIN_DIR
#define LCD_Data_Bus_Dir_D4   	DATA_LINE_D4_DIR
#define LCD_Data_Bus_Dir_D5     DATA_LINE_D5_DIR
#define LCD_Data_Bus_Dir_D6  	DATA_LINE_D6_DIR
#define LCD_Data_Bus_Dir_D7 	DATA_LINE_D7_DIR
// Constants
#define E_Delay       500  


// Function Declarations
void WriteCommandToLCD(unsigned char);
void WriteDataToLCD(char);
void InitLCD(void);
void WriteStringToLCD(const char*);
void ClearLCDScreen(void);
void DisplayTimeToLCD(unsigned char*) ;
void DisplayDateOnLCD( unsigned char*);

#endif	/* LCD_H */

