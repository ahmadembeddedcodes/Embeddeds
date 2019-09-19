#ifndef UART_X_H_
#define UART_X_H_

#include <avr/io.h>
#include "DATA_TYPES.h"

#ifndef F_CPU
#define F_CPU  8000000UL
#endif

#define BAUD_RATE  9600
#define UBRR_VALUE F_CPU/16/BAUD_RATE-1
//#define UBRR_VALUE  (unsigned char)((F_CPU/(16*BAUD_RATE))-1)

void usart_init(void); 
void usart_transmite(u8 data);
void usart_transmit9bit( unsigned int data );  
u8 usart_receive(void); 

unsigned int usart_Receive9bit( void );
void usart_flush( void );


#endif /* UART_X_H_ */