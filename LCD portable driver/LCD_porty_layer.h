/* 
 * File:   LCD_porty_layer.h
 * Author: Ahmad
 *
 * Created on February 14, 2020, 7:49 PM
 */

#ifndef LCD_PORTY_LAYER_H
#define	LCD_PORTY_LAYER_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif


#define LCD_MODE_4
//#define LCD_MODE_8 
#define LCD_DATA_PORT   PORTB
#define ENABLE_PIN       RE1
#define REG_SELECT_PIN   RE2

#ifdef LCD_MODE_8
#define DATA_LINE_D0  RB0
#define DATA_LINE_D1  RB1
#define DATA_LINE_D2  RB2
#define DATA_LINE_D3  RB3
#endif

#define DATA_LINE_D4  RB4
#define DATA_LINE_D5  RB5
#define DATA_LINE_D6  RB6
#define DATA_LINE_D7  RB7
/********************************/
#define ENABLE_PIN_DIR      TRISE1
#define REG_SELECT_PIN_DIR  TRISE2

#ifdef LCD_MODE_8
#define DATA_LINE_D0_DIR   TRISB0
#define DATA_LINE_D1_DIR   TRISB1
#define DATA_LINE_D2_DIR   TRISB2
#define DATA_LINE_D3_DIR   TRISB3
#endif

#define DATA_LINE_D4_DIR  TRISB4
#define DATA_LINE_D5_DIR  TRISB5
#define DATA_LINE_D6_DIR  TRISB6
#define DATA_LINE_D7_DIR  TRISB7





#endif	/* LCD_PORTY_LAYER_H */

