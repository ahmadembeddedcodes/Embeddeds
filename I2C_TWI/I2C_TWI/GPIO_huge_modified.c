
#include "GPIO_huge_modified.h"
#include "DATA_TYPES.h"
																		

void GPIO_U8_PORT_DIR(u8* port_name , u8 port_direction)
{
	
	if (port_direction == 0xff)
		*port_name = u8_Direction_output; 
	else 
	    *port_name = u8_Direction_input;   
		
}

u8 GPIO_U8_PORT_READ_DIR(u8* port_name)
{
	return * port_name; 
	
}

void GPIO_U8_PORT_WRITE(u8* port_name , u8 port_value)
{
	
	*port_name = port_value ;
}


u8 GPIO_U8_PORT_READ(u8* port_name)
{
	
  return *port_name; 

}


void GPIO_U8_PIN_WRITE(u8* port_name, u8 pin_number, u8 pin_value)
{
	switch(pin_value)
	{
		case 1 :
		          *port_name |=(1<<pin_number); 
		    break; 
		default:
                  *port_name &=~(1<<pin_number);		
		    break; 
	}
}

void GPIO_U8_PIN_DIR(u8* port_name , u8 pin_number , u8 pin_value)
{
   	switch(pin_value)
   	{
	   	case 1 :
	     	*port_name |=(1<<pin_number);
	   	break;
		   
	   	default:
	   	    *port_name &=~(1<<pin_number);
	    	break;
   	}
 	
}

uint8 GPIO_U8_PIN_READ(u8* port_name,u8 pin_number)
{
	if( (*port_name & (1<<pin_number)) == 1 )
	   return 1; 
	else
	   return 0;    
}

uint8 GPIO_U8_PIN_READ_DIR(u8* port_name , u8 pin_number )
{
		
		if( (*port_name & (1<<pin_number)) == 1 )
		   return 1;
		else
		   return 0;
}