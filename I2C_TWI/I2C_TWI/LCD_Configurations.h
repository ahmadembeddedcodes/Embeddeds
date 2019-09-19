#ifndef LCD_CONFIGURATIONS_
#define LCD_CONFIGURATIONS_

/*** LCD CONFIGURATIONS ************************/
#define LCD_DATA_PORT                   PORT_D
#define LCD_DATA_PORT_DIRECTION         DDR_D
#define LCD_CONTROL_PORT                PORT_C
#define LCD_CONTROL_PORT_DIR            DDR_C
#define RS_PIN          2
#define RS_PIN_DIR      1
#define ENABLE_PIN      4
#define R_W_PIN         3
#define LCD_MODE        4

/*PLEASE CONNECT THIS PINS OF LCD TO THE LAST 4 BITS OF THE DATA PORT IN MICROCONTROLLER*/
#define D4    4
#define D5    5
#define D6    6
#define D7    7


#endif