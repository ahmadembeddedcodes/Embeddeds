

#include "SPI.h"
#include "GPIO.h"

void spi_init_master(){
	
	//set mosi pin o/p
	GPIO_U8_PIN_DIR('b',5,1); 
	//set miso pin i/p 
	GPIO_U8_PIN_DIR('b',6,0); 
	//set clk pin o/p 
	GPIO_U8_PIN_DIR('b',7,1); 
	//set ss pin o/p 
	GPIO_U8_PIN_DIR('b',4,1); 
	
  //enable spi - set as master - set prescaller /16 	
   mySPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0); 
	
	
	
}

void spi_init_slave(){
	//set mosi pin o/p
	GPIO_U8_PIN_DIR('b',5,1);
	//set miso pin i/p
	GPIO_U8_PIN_DIR('b',6,0);
	//set clk pin o/p
	GPIO_U8_PIN_DIR('b',7,1);
	//set ss pin o/p
	GPIO_U8_PIN_DIR('b',4,1);
	
	
	mySPCR &= ~(1<<MSTR); //set as SLAVE
	mySPCR |= (1<<SPE)|(1<<SPR0); //enable spi -  - set prescaller /16
	
}

void spi_send(u8 data)
{
  /* Start transmission */
  mySPDR = data;
  /* Wait for transmission complete */
  while(!(mySPSR & (1<<SPIF))); 
	
}

char spi_receive(){
	
	/* Wait for reception complete */
	while(!(mySPSR & (1<<SPIF)))
	;
	/* Return data register */
	return mySPDR;
}