/*
 * uart_registers.h
 *
 * Created: 10/07/2019 06:00:25 م
 *  Author: Ahmad
 */ 


#ifndef UART_REGISTERS_H_
#define UART_REGISTERS_H_
#include <avr/io.h>

#define myUBRRL    *((volatile u8*const)0x29)
#define myUBRRH    *((volatile u8*const)0x40)
#define myUCSRA    *((volatile u8*const)0x2B)
#define myUCSRB    *((volatile u8*const)0x2A)
#define myUCSRC    *((volatile u8*const)0x40)
#define myUDR      *((volatile u8*const)0x2C)

////UCSRA//////////// 
#define  MPCM    0
#define  U2X     1
#define  PE      2
#define  DOR     3
#define  FE      4
#define  UDRE    5
#define  TXC     6
#define  RXC     7
/////UCSRB///////////////////
#define  TXB8    0
#define  RXB8    1
#define  UCSZ2   2
#define  TXEN    3
#define  RXEN    4
#define  UDRIE   5
#define  TXCIE   6
#define  RXCIE   7
//////UCSRC/////////////////
#define  UCPOL   0
#define  UCSZ0   1
#define  UCSZ1   2
#define  USBS    3
#define  UPM0    4
#define  UPM1    5
#define  UMSEL   6
#define  URSEL   7


#endif /* UART_REGISTERS_H_ */