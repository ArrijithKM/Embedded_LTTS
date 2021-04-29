#ifndef ADC_H_INCLUDED
#define ADC_H_INCLUDED

#include<avr/io.h>
#include<util/delay.h>

void initAdc(void);
uint16_t readAdc(uint16_t channel);

#endif // ADC_H_INCLUDED
