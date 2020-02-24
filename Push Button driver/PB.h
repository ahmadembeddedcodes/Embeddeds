/* 
 * File:   PB.h
 * Author: Ahmad
 *
 * Created on February 14, 2020, 10:52 PM
 */

#ifndef PB_H
#define	PB_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif




#define LOW  0
#define HIGH 1
#define PRESSED_LEVEL  LOW 
#define RELEASED_LEVEL HIGH
#define numberOfButtons 1
char ButtonPressed(int buttonNumber, unsigned char pinOfButton, unsigned char portBit, int confidenceLevel);

char bit_is_low(unsigned char portx, unsigned char pinx);

 
#endif	/* PB_H */

