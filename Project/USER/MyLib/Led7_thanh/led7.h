#ifndef __LED7_H
#define __LED7_H


#include "stdint.h"


void GPIO_Configuration(void);
void dec(uint8_t data);
void dec4(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
void tat_led (void);

#endif


