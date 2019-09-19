/*
 * i2c.h
 *
 * Created: 20/07/2019 12:24:25 م
 *  Author: Ahmad
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "DATA_TYPES.h"


#define  TWCR_REG   *((volatile u8 * const)0x56)   //CONTROL REGISTER
#define  TWSR_REG   *((volatile u8 * const)0x21)   //STATUS,PRESCALER REGISTER 
#define  TWDR_REG   *((volatile u8 * const)0x23)   //DATA,ADDRESS REGISTER
#define  TWAR_REG   *((volatile u8 * const)0x22)   //SLAVE ADDRESS + OPERATION
#define  TWBR_REG   *((volatile u8 * const)0x20)   //BIT RATE, REGISTER

/*TWCR_REG BITS */ 
#define   TWIE_BIT      0    // responsible for enabling interrupt for i2c
#define   RESERVED_BIT  1    // not used - always read as zero 
#define   TWEN_BIT      2    // enabling i2c module   
#define   TWWC_BIT      3    // write collision flag
#define   TWSTO_BIT     4    // generate stop condition
#define   TWSTA_BIT     5    // generate start condition
#define   TWEA_BIT      6    // generate Acknowledgment signal 
#define   TWINT_BIT     7    // interrupt flag 

/*TWSR_REG BITS*/ 
#define   TWPS0_BIT      0  // CHOOSE PRESCALER
#define   TWPS1_BIT      1  // CHOOSE PRESCALER
#define   RESERVEDx_BIT  2  //not used - always read as zero
#define   TWS3_BIT       3  // indicates the i2c bus status
#define   TWS4_BIT       4  // ~~
#define   TWS5_BIT       5  // ~~
#define   TWS6_BIT       6  // ~~
#define   TWS7_BIT       7  // ~~ 

/*TWAR_REG BITS*/ 
#define   TWGCE_BIT  0  // determine the read or write to slave 
#define   TWA0_BIT   1  // DETERMINE THE SLAVE ADDRESS
#define   TWA1_BIT   2  //~~
#define   TWA2_BIT   3  //~~
#define   TWA3_BIT   4  //~~
#define   TWA4_BIT   5  //~~
#define   TWA5_BIT   6  //~~
#define   TWA6_BIT   7  //~~ 

/*TWDR_REG BITS*/
#define   TWD0_BIT  0
#define   TWD1_BIT  1
#define   TWD2_BIT  2
#define   TWD3_BIT  3
#define   TWD4_BIT  4
#define   TWD5_BIT  5
#define   TWD6_BIT  6
#define   TWD7_BIT  7
/************************************************************************/
/*********STATUS CODES FOR OPERATIONS IN THE STATUS REGISTER ACCORDING TO IT'S MODE***/

//FIRST MODE : Master Transmitter Mode : when microcontroller is sending data to other device on the bus 
#define  START_condition_transmitted           0x08
#define  Repeated_START_condition_transmitted  0x10
#define  SLA_W_transmitted_Ack_received        0x18
#define  SLA_W_transmitted_Nack_received       0x20
#define  Data_byte_transmitted_ACK_received    0x28
#define  Data_byte_transmitted_NACK_received   0x30
#define  SLAVE_FAIL_TO_BE_ADDRESSED            0x38

//SECONF MODE : Master Receiver Mode ; WHen the microcontroller is a master but read data from  another device on the bus 
//repeated  #define  START_condition_transmitted           0x08
//repeated  #define  Repeated_START_condition_transmitted  0x10
#define  SLA_R_transmitted_Ack_received        0x40
#define  SLA_R_transmitted_Nack_received       0x48
#define  Data_byte_received_ACK_received       0x50
#define  Data_byte_received_NACK_received      0x58
//repeated  #define  SLAVE_FAIL_TO_BE_ADDRESSED    0x38

//THIED MODE : Slave Receiver Mode 
    //MSH MOHEM DELWA3TY ELBETA3 DAH :D

/************************************************************************/


enum I2c_Prescaler{
	NO_PRESCALER,    // 00
	DIV_BY_4,        // 01
	DIV_BY_16,       // 10
  	DIV_BY_64        // 11
	};

/************************MASTER operating mode FUNCTIONS *******/
/************************Master Transmitter Mode***************/
void I2C_MASTER_INIT(void); 
void I2C_WAIT_FLAG_TO_BE_SET(void);
u8   I2C_START_CONDITION(void); 
u8   I2C_REPEAT_START(void); 
u8   I2C_CHECK_STATUS_REG(u8 TWSR_STATUS_VALUE); 
void I2C_STOP_CONDITION(); 
u8 I2C_MASTER_SEND(u8 DATA_OR_ADDRESS); 
u8 I2C_MASTER_RECIEVE(void);

void I2C_ACK_SIGNAL(void);
void I2C_NACK_SIGNAL(void);


/************************slave operating mode FUNCTIONS *******/
/************************Master RECEIVER Mode***************/
// SLAVE WILL NOT INITIATE { START OR REPEAT START OR STOP} CONDITIONS,SO WE DIDN'T NEED IT'S FUNCTIONS
void I2C_SLAVE_INIT(u8 SLAVE_ADDRESS);
void I2C_SLAVE_LISTEN_TO_BUS();
void I2C_SLAVE_WAIT_FLAG_TO_BE_SET(void);
u8 I2C_SLAVE_SEND(u8 DATA_BYTE);
u8 I2C_SLAVE_RECIEVE(u8 IsLast);


#endif /* I2C_H_ */