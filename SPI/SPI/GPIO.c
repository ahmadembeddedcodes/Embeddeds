
#include "GPIO.h"
#include "DATA_TYPES.h"
																		
volatile unsigned char* GPIO_PORT[]= {PORT_A ,PORT_B ,PORT_C,PORT_D };
volatile unsigned char* GPIO_DIR[]= {DDR_A,DDR_B,DDR_C,DDR_D};
volatile unsigned char* GPIO_PIN[]= {PIN_A,PIN_B,PIN_C,PIN_D};

u8 GET_PORT_INDX( u8 port_name)
{
	u8 index;
	switch(port_name)
	{

		case 'A' :
		case 'a' : index=0; break;
		
		case 'B' :
		case 'b' : index=1; break;

		case 'C' :
		case 'c' : index=2; break;

		case 'D' :
		case 'd' : index=3; break;
		          
	}

	return index;
}

u8 GPIO_U8_PORT_DIR(u8 port_name , u8 port_direction)
{
	*GPIO_DIR[GET_PORT_INDX(port_name)] = port_direction ;
	
	return NO_ERROR;
}

u8 GPIO_U8_PORT_READ_DIR(u8 port_name , u8 *pt_value)
{
	*pt_value = *GPIO_DIR[GET_PORT_INDX(port_name)]  ;
	
	return NO_ERROR;
}

u8 GPIO_U8_PORT_WRITE(u8 port_name , u8 port_value)
{
	*GPIO_PORT[GET_PORT_INDX(port_name)]=port_value ;
	
	return NO_ERROR;
}


u8 GPIO_U8_PORT_READ(u8 port_name, u8* pt_value)
{
	
	*pt_value =  *GPIO_PIN[GET_PORT_INDX(port_name)];
	
	return NO_ERROR;

}


u8 GPIO_U8_PIN_WRITE(u8 port_name, u8 pin_number, u8 pin_value)
{
	u8 API_Status ;

	if(pin_number > no_of_pins_on_port - 1)
	{
		API_Status = ERROR_HAPPEN;
	}

	else {

		switch(pin_value)
		{
			case 1 :  * GPIO_PORT[GET_PORT_INDX(port_name)] |= (1<<pin_number); break;

			case 0 :  * GPIO_PORT[GET_PORT_INDX(port_name)] &=~(1<<pin_number); break;

			default : API_Status = ERROR_HAPPEN;  break ;
		}

		API_Status = NO_ERROR;

	}
	return API_Status ;
}

u8 GPIO_U8_PIN_DIR(u8 port_name , u8 pin_number , u8 pin_value)
{
	u8 API_Status;

	if (pin_number > no_of_pins_on_port-1)
	{
		API_Status = ERROR_HAPPEN;
		return API_Status;
	}
	else{
		
		switch(pin_value)
		{
			case 1 :  *GPIO_DIR[GET_PORT_INDX(port_name)] |= (1<<pin_number); break;
			
			case 0 :  *GPIO_DIR[GET_PORT_INDX(port_name)] &=~(1<<pin_number); break;

			default : API_Status= ERROR_HAPPEN; break;
		}

		API_Status= NO_ERROR;
	}
	return API_Status ;

}

u8 GPIO_U8_PIN_READ(u8 port_name,u8 pin_number, u8* pt_value)
{
	u8 API_Status;

	if (pin_number > no_of_pins_on_port-1)
	{
		API_Status = ERROR_HAPPEN;
		return API_Status;
	}

	else {
		
		*pt_value = *GPIO_PIN[GET_PORT_INDX(port_name)];
		API_Status = NO_ERROR;
	}

	return  API_Status ;

}

u8 GPIO_U8_PIN_READ_DIR(u8 port_name , u8 pin_number , u8 *pt_value)
{
	u8 API_Status;

	if (pin_number > no_of_pins_on_port-1)
	{
		API_Status = ERROR_HAPPEN;
		return API_Status;
	}
	else{
		
		*pt_value = *GPIO_DIR[GET_PORT_INDX(port_name)];
		API_Status = NO_ERROR;
	}
	return API_Status ;

}
u8 GPIO_U8_PIN_READ_SIMPLE(u8 port_name,u8 pin_number)
{
	// read the pin state
	return	*GPIO_PIN[GET_PORT_INDX(port_name)] ;
	
	//return the state
}