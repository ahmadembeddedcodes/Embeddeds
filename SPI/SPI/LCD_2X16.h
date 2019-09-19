
#ifndef LCD_H_ 
#define LCD_H_

#include <avr/io.h>
#include "DATA_TYPES.h"
#include "GPIO.h"
#include "LCD_Configurations.h"  // configurations from users

/******* LIST OF COMMAND OF LCD *********/ 
#define  CLEAR_SCREEN                           0x01
#define  RETURN_HOME                            0x02
#define  DECREMENT_CURSOR                       0x04
#define  INCREMENT_CURSOR                       0x06
#define  SHIFT_RIGHT                            0X05
#define  SHIFT_LEFT                             0X07 
#define  DISPLAY_OFF_CURSOR_OFF                 0x08
#define  DISPLAY_OFF_CURSOR_ON                  0x0A
#define  DISPLAY_ON_CURSOR_OFF                  0x0C
#define  DISPLAY_ON_CURSOR_BLINKING             0x0E
#define  DISPLAY_ON_CURSOR_BLINKING_2           0x0F
#define  SHIFT_CURSOR_LEFT                      0x10        
#define  SHIFT_CURSOR_RIGHT                     0x14
#define  SHIFT_ENTIRE_DISPLAY_LEFT              0x18
#define  SHIFT_ENTIRE_DISPLAY_RIGHT             0x1C
#define  FORCE_CURSOR_TO_BEGINING_OF_1ST_LINE   0x80
#define  FORCE_CURSOR_TO_BEGINING_OF_2ND_LINE   0xC0
#define  MODE_4   0x28
#define  MODE_8   0x38
/********END OF COMMAND LIST*********************************************/

/*** OTHER HIDDEN LCD CONFIGURATIONS ************************/
#define RS_PIN_DIR      1
#define ENABLE_PIN_DIR  1
#define R_W_PIN_DIR     1
#define PIN_OUTPUT      1
#define PIN_INPUT       0
/****END OF HIDDEN CONFIGURATIONS ********************/

void LCD_Send_Command(u8 CMD); 
void LCD_Init(); 
void LCD_Set_Cursor_Position(u8 Row , u8 column);
void LCD_Print_Char(u8 ch);
void LCD_Print_str(char* str); 
void LCD_Clear(void); 

#endif
