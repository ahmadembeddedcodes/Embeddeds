/*
 * RTC_DS1307.c
 *
 * Created: 22/07/2019 11:08:17 م
 *  Author: Ahmad
 */ 

#include "i2c.h"
#include "RTC_DS1307.h"
/*****************************
DS1307 RTC WORKFLOW 
-------------------
(WRITE/READ) OPERARTIONS : 
1- START CONDTION
2- WRITE THE DS1307 ADDRESS OF (WRITE/READ) TO BE ABLE TO COMMUNICATE
3-NEXT (WRITE/READ) OPERATION, WILL SET THE REGISTER POINTER THAT POINTS TO THE NEXT REGISTER
TO BE (WRITE/READ) IN DS1307, 
NOTE: REGISTER POINTER INCREMENT AUTOMATICALLY 
4- NEXT (WRITE/READ) OPERATION WILL(WRITE/READ)INSIDE THE REGISTER
   THAT YOU POINTED FROM THE LAST STEP 
5- STOP CONDITION 
*****************************/


void RTC_Set_Time(u8 hour_hex, u8 min_hex, u8 second_hex){
	I2C_START_CONDITION();
	I2C_MASTER_SEND(RTC_DS1307_WRITE_ADDRESS);
	I2C_MASTER_SEND(0x00); //point to second register
	I2C_MASTER_SEND(second_hex);         //set register pointer to location 0x00 - second register
	I2C_MASTER_SEND(min_hex);         // set seconds = 55
	I2C_MASTER_SEND(hour_hex);         // set minitues =58 ** note: register pointer increment automaticallyours mode
	I2C_STOP_CONDITION();
}

void RTC_Set_Date(u8 day_hex, u8 month_hex, u8 year_hex){
	I2C_START_CONDITION();
	I2C_MASTER_SEND(RTC_DS1307_WRITE_ADDRESS);
	I2C_MASTER_SEND(0x04);  //set register pointer to location 0x04
	I2C_MASTER_SEND(day_hex);    // set day to 0x22 = 22
	I2C_MASTER_SEND(month_hex);  // set month to 0x07 = 7
	I2C_MASTER_SEND(year_hex);   //set year to 0x19 = 20
	I2C_STOP_CONDITION();
}

void RTC_DS1307_GET_TIME(u8* hours, u8* minutes, u8* seconds){
	I2C_START_CONDITION();
	I2C_MASTER_SEND(RTC_DS1307_WRITE_ADDRESS); // ADDRESS FOR WRITE -  DS1307 RTC CHIP
	I2C_MASTER_SEND(0x00);
	I2C_STOP_CONDITION();
	/**************************/
	I2C_START_CONDITION();
	I2C_MASTER_SEND(RTC_DS1307_READ_ADDRESS); // ADDRESS FOR READ -  DS1307 RTC CHIP
	*seconds= I2C_MASTER_RECIEVE();
	*minutes= I2C_MASTER_RECIEVE();
	*hours= I2C_MASTER_RECIEVE();
	
	I2C_STOP_CONDITION();
}
void RTC_DS1307_GET_DATE(u8* year, u8* month, u8*day){
	I2C_START_CONDITION();
	I2C_MASTER_SEND(0xD0); // ADDRESS FOR WRITE -  DS1307 RTC CHIP
	I2C_MASTER_SEND(0x04);  //set register pointer to 0x04 location -
	I2C_STOP_CONDITION();
	/**************************/
	I2C_START_CONDITION();
	I2C_MASTER_SEND(RTC_DS1307_READ_ADDRESS); // ADDRESS FOR READ -  DS1307 RTC CHIP
	*day= I2C_MASTER_RECIEVE();
	*month= I2C_MASTER_RECIEVE();
	*year= I2C_MASTER_RECIEVE();
	I2C_STOP_CONDITION();
}
