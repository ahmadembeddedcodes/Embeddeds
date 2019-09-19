/*
 * RTC_DS1307.h
 *
 * Created: 22/07/2019 11:09:01 م
 *  Author: Ahmad
 */ 


#ifndef RTC_DS1307_H_
#define RTC_DS1307_H_

#define RTC_DS1307_WRITE_ADDRESS 0xD0
#define RTC_DS1307_READ_ADDRESS  0xD1
#define RTC_DS1307_CONTROL_REGISTER 0x07


void RTC_Set_Time(u8 hour_hex, u8 min_hex, u8 second_hex);
void RTC_Set_Date(u8 day_hex, u8 month_hex, u8 year_hex);
void RTC_DS1307_GET_TIME(u8* seconds, u8* minutes, u8*hours);
void RTC_DS1307_GET_DATE(u8* year, u8* month, u8*day); 



#endif /* RTC_DS1307_H_ */