#ifndef SPI_H_
#define SPI_H_

#include "DATA_TYPES.h"

	
/**** SPI registers ****/ 

#define mySPCR  *((volatile u8*const) 0x2D)
#define myUDR   *((volatile u8*const) 0x2C)
#define mySPSR  *((volatile u8*const) 0x2E)
#define mySPDR  *((volatile u8*const) 0x2F)
/*bits in registers*/ 
#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE  6
#define SPIE 7
///////////////////
#define SPI2X 0
#define WCOL  6
#define SPIF  7 

/***********************/

void spi_init_master(); 
void spi_init_slave();
void spi_send(u8 data); 
char spi_receive(); 

#endif