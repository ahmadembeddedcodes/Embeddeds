#include "pb.h"
#include "GPIO.h"

void PB_Init(u8 port_name, u8 pin_number)
{
	// set the corresponding pin as an input
	GPIO_U8_PIN_DIR(port_name , pin_number , pin_dir_input);
}

u8 PB_IsPressed(u8 port_name, u8 pin_number )
{
	u8 confidence_level =0 ;
	/* check if the button is still pressed */
	if (GPIO_U8_PIN_READ_SIMPLE(port_name,pin_number) == PRESSED_LEVEL )
	{
		confidence_level ++; // incrementing the counter to make a simple delay to avoid bouncing
		if (confidence_level > 500) // I think it's a good period or delay
		{
			/*check the button again after the delay- to ensure that button is still pressed */
			if (GPIO_U8_PIN_READ_SIMPLE(port_name,pin_number) == PRESSED_LEVEL ) 
			   return PRESSED_LEVEL;  // return that button is safely pressed
			   /* here, I'm sure that the button is pressed*/
		}
		confidence_level =0; //  zeroing the confidence level
	}
	else
	   return RELEASE_LEVEL;
}

