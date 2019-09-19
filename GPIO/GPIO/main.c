
#define F_CPU 8000000UL

#include "GPIO.h"
#include <util/delay.h>



/*
// u8 GPIO_U8_PORT_DIR(u8 port_name , u8 port_direction);
// u8 GPIO_U8_PORT_WRITE(u8 port_name , u8 port_value) ;
// u8 GPIO_U8_PORT_READ(u8 port_name, u8* pt_value);
// u8 GPIO_U8_PORT_READ_DIR(u8 port_name , u8 *pt_value);
// u8 GPIO_U8_PIN_WRITE(u8 port_name, u8 pin_number, u8 pin_value);
// u8 GPIO_U8_PIN_DIR(u8 port_name , u8 pin_number , u8 pin_value);
// u8 GPIO_U8_PIN_READ(u8 port_name,u8 pin_number, u8* pt_value);
// u8 GPIO_U8_PIN_READ_DIR(u8 port_name , u8 pin_number , u8 *pt_value);
//  
*/



int main(void)
{
	
   GPIO_U8_PORT_DIR('A', u8_Direction_output);
    while (1) 
    {   
		GPIO_U8_PORT_WRITE('a', u8_Direction_output) ;
		_delay_ms(300);
		
       GPIO_U8_PORT_WRITE('a' , u8_Direction_input) ;
       _delay_ms(300);

    }
}


