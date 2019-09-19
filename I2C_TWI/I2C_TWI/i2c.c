/*
 * i2c.c
 *
 * Created: 20/07/2019 12:24:55 م
 *  Author: Ahmad
 */ 

#include "i2c.h"
#include "DATA_TYPES.h"

/******************************************************************************************/
/* note:  I2C Is fully depend on interrupt, so you need to check the i2c interrupt flag before any step, 
            and you must clear the flag in software */  

/*note2: ACK and NACK  signals are transmitted automatically _ but you can send it manually either*/ 
/*******************************************************************************************/



void I2C_MASTER_INIT(void){
	//set prescaler // NO PRESCALER
	TWSR_REG &=~(1<<TWPS0_BIT) | (1<<TWPS1_BIT);  
	//set bit rate
	TWBR_REG =2 ;  
	//enable i2c
	TWCR_REG |=(1<<TWEN_BIT); 
}

void I2C_WAIT_FLAG_TO_BE_SET(void){
/* YOU MUST WAIT THIS FLAG BEFORE ANY OPERATION TO ENSURE THAT THE CURRENT OPERATION IS FINISHED 
   AND BUS READY TO NEW OPERTION*/ 
	while (!(TWCR_REG & (1<<TWINT_BIT)));
}

u8 I2C_START_CONDITION(void){
/********************************************************
       TWINT TWEA  TWSTA TWSTO TWWC  TWEN   –   TWIE
Value:  1     X      1     0     X     1    0    X
********************************************************/
	/* TWEN  must be set to enable the Two-wire Serial Interface,
	   TWSTA must be written to one to transmit a START condition,
	   TWINT must be written to one to clear the TWINT Flag*/
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWSTA_BIT) | (1<<TWEN_BIT);
	
	I2C_WAIT_FLAG_TO_BE_SET();  //to see whether the START condition transmitted completely?
	
	/*checking the status register is done when i2c bus has multiple masters*/ 
	if( I2C_CHECK_STATUS_REG(START_condition_transmitted) )
	   return NO_ERROR;
	else
	   return ERROR_HAPPEN;
}

/* REPEAT START IS IDENTICAL TO START CONDITION BUT TO MAKE IT LOGICAL 
 I HADE MADE ANOTHER FUNCTION CARRYING DIFFERENT NAME TO MAKE IT SENSE
 Also it is a good practice to future upgrade-up-ability*/  
 
u8 I2C_REPEAT_START(void){
	/* TWEN  must be set to enable the Two-wire Serial Interface,
	   TWSTA must be written to one to transmit a START condition,
	   TWINT must be written to one to clear the TWINT Flag*/
	
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWSTA_BIT) | (1<<TWEN_BIT);
	I2C_WAIT_FLAG_TO_BE_SET();
   
    if( I2C_CHECK_STATUS_REG(Repeated_START_condition_transmitted) )	
	   return NO_ERROR;
	else
	   return ERROR_HAPPEN;
}


u8 I2C_CHECK_STATUS_REG(u8 TWSR_STATUS_VALUE){
	/* you must mask the 2 MSB (bits) in TWSR register */  
	if ((TWSR_REG & 0xF8) != TWSR_STATUS_VALUE)
	  return ERROR_HAPPEN; 
	else
	  return NO_ERROR;    
}

void I2C_STOP_CONDITION(){
	
TWCR_REG = (1<<TWINT_BIT)|(1<<TWEN_BIT)|(1<<TWSTO_BIT); 
	
}


u8 I2C_MASTER_SEND(u8 DATA_OR_ADDRESS){
	
	/*Load DATA into TWDR Register.*/
	TWDR_REG = DATA_OR_ADDRESS;
	
	/* Clear  TWINT bit in TWCR to start transmission  of data*/
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT); //o start sending the byte.
	
	I2C_WAIT_FLAG_TO_BE_SET();
	
	if (I2C_CHECK_STATUS_REG(SLA_W_transmitted_Ack_received) == NO_ERROR )
     	return NO_ERROR;
	else
    	return ERROR_HAPPEN;
}

u8 I2C_MASTER_RECIEVE(void){
/* to call this function you must be sure that you have been sent SLA+R to the slave */ 

	u8 my_data=0;   // to save incoming data

	/* Clear  TWINT bit in TWCR to start transmission  of data*/
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT);
	
	
	I2C_WAIT_FLAG_TO_BE_SET();
	my_data = TWDR_REG; 
	
	if( I2C_CHECK_STATUS_REG(Data_byte_received_NACK_received) == NO_ERROR )
   	   { I2C_ACK_SIGNAL(); 
		 return my_data; 
	   }
    else
	   return ERROR_HAPPEN;		  
	 
/* this function return your data if your operation are done correctly - or return 0 if the data not received */ 
}

void I2C_ACK_SIGNAL(void){
	TWCR_REG |=(1<< TWEA_BIT); 	
}

void I2C_NACK_SIGNAL(void){	
	TWCR_REG &=~(1<< TWEA_BIT); 
}



/************************slave operating mode FUNCTIONS *******/

void I2C_SLAVE_INIT(u8 SLAVE_ADDRESS){
/* AS a slave device you will not specify prescaler or bit rate ! it's a master business not slave*/	
	//Set the slave address
	TWAR_REG = SLAVE_ADDRESS;
    //Enable the TWI module
    TWCR_REG |=(1<<TWEN_BIT);
    //Set the TWEN, TWINT, and TWEA bits of TWCR to one
   TWCR_REG |=(1<<TWEN_BIT)|(1<<TWINT_BIT)|(1<<TWEA_BIT);
	
}

void I2C_SLAVE_LISTEN_TO_BUS(){
/*slave device should listen to the bus  to detect when it is addressed by a master device.*/
//Then the TWI module detects  its own address on the bus, 
I2C_SLAVE_WAIT_FLAG_TO_BE_SET(); //wait to be addressed from master
TWCR_REG |=(1<<TWINT_BIT); //(clear the flag)-sets the TWINT flag in the  TWCR register to one	  
I2C_ACK_SIGNAL();
}


void I2C_SLAVE_WAIT_FLAG_TO_BE_SET(void){
/* YOU MUST WAIT THIS FLAG BEFORE ANY OPERATION TO ENSURE THAT THE CURRENT OPERATION IS FINISHED 
   AND BUS READY TO NEW OPERTION*/ 
	while (!(TWCR_REG & (1<<TWINT_BIT)));
}


u8 I2C_SLAVE_SEND(u8 DATA_BYTE){
	
	/*Load DATA into TWDR Register.*/
	TWDR_REG = DATA_BYTE;
	
	/* Clear  TWINT bit in TWCR to start transmission  of data*/
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<<TWEA_BIT); //o start sending the byte.
	
	I2C_SLAVE_WAIT_FLAG_TO_BE_SET();

}

/*

u8 I2C_SLAVE_RECIEVE(void){
//to call this function you must be sure that you have been sent SLA+R to the slave

	//start receiving  a byte.
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<<TWEA_BIT); 
	//Poll the TWINT flag
	I2C_SLAVE_WAIT_FLAG_TO_BE_SET();
	 
	return TWDR_REG; 
}
*/

u8 I2C_SLAVE_RECIEVE(u8 IsLast){
/* (IsLast == 0)  => I will read multiple bytes, 
   so i must enabling Ack bit to able to receive  multiple bytes from masters     

(IsLast == 0)  => i will read only one byte- no need to enable ack bit */ 

if (IsLast == 0) //multiple read
   	 TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<<TWEA_BIT);
else  // read onlEY one byte 
     TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT);    	  
	
I2C_SLAVE_WAIT_FLAG_TO_BE_SET(); 

	return TWDR_REG; 
}

