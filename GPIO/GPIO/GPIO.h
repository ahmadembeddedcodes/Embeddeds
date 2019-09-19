#ifndef GPIO_H_
#define GPIO_H_

#include "DATA_TYPES.h"

#define PORT_A  ((volatile unsigned char *const) 0x3B)
#define DDR_A   ((volatile unsigned char *const) 0x3A)
#define PIN_A   ((volatile unsigned char *const) 0x39)
#define PORT_B  ((volatile unsigned char *const) 0x38)
#define DDR_B   ((volatile unsigned char *const) 0x37)
#define PIN_B   ((volatile unsigned char *const) 0x36)
#define PORT_C  ((volatile unsigned char *const) 0x35)
#define DDR_C   ((volatile unsigned char *const) 0x34)
#define PIN_C   ((volatile unsigned char *const) 0x33)
#define PORT_D  ((volatile unsigned char *const) 0x32)
#define DDR_D   ((volatile unsigned char *const) 0x31)
#define PIN_D   ((volatile unsigned char *const) 0x30)

#define u8_Direction_input 0x00
#define u8_Direction_output 0xFF
//choose the default intialization for GPIO
#define Init_direction_default u8_Direction_input
#define no_of_pins_on_port  8



u8 GET_PORT_INDX( u8 port_name);
u8 GPIO_U8_PORT_DIR(u8 port_name , u8 port_direction);
u8 GPIO_U8_PORT_WRITE(u8 port_name , u8 port_value) ;
u8 GPIO_U8_PORT_READ(u8 port_name, u8* pt_value);
u8 GPIO_U8_PORT_READ_DIR(u8 port_name , u8 *pt_value);
u8 GPIO_U8_PIN_WRITE(u8 port_name, u8 pin_number, u8 pin_value);
u8 GPIO_U8_PIN_DIR(u8 port_name , u8 pin_number , u8 pin_value);
u8 GPIO_U8_PIN_READ(u8 port_name,u8 pin_number, u8* pt_value);
u8 GPIO_U8_PIN_READ_DIR(u8 port_name , u8 pin_number , u8 *pt_value);

#endif