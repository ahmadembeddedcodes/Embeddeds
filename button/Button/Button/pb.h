
#ifndef PB_H_
#define PB_H_

#include "DATA_TYPES.h"

#define RELEASE_LEVEL (1)
#define PRESSED_LEVEL (0)

void PB_Init(u8 port_name, u8 pin_number);
u8 PB_IsPressed(u8 port_name, u8 pin_number ) ;

#endif 







































