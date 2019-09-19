#include "uart_registers.h"
#include "uart_x.h"
#include <avr/io.h>

void usart_init(void){
 /* Set baud rate */
  UBRRL = (unsigned char)UBRR_VALUE;
 UBRRH = (unsigned char)(UBRR_VALUE>>8);

 /* Enable receiver and transmitter */
 UCSRB = (1<<RXEN)|(1<<TXEN);
 /* Set frame format: 8data, 2stop bit */
 UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
  
}
void usart_transmite(u8 data){
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
	
}
void usart_transmit9bit( unsigned int data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Copy 9th bit to TXB8 */
	UCSRB &= ~(1<<TXB8);
	if ( data & 0x0100 )
	UCSRB |= (1<<TXB8);
	/* Put data into buffer, sends the data */
	UDR = data;
}

u8 usart_receive(void){
	
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}

unsigned int usart_Receive9bit( void )
{
	unsigned char status, resh, resl;
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get status and 9th bit, then data */
	/* from buffer */
	status = UCSRA;
	resh = UCSRB;
	resl = UDR;
	/* If error, return -1 */
	if ( status & ((1<<FE)|(1<<DOR)|(1<<PE)) )
	  return -1;
	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;
	return ((resh << 8) | resl);
}


void usart_flush( void )
{
	unsigned char dummy;
	while ( UCSRA & (1<<RXC) ) dummy = UDR;
}

