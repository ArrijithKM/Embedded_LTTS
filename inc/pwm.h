#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED

//#include"adc.h"
#include<avr/io.h>
#include<util/delay.h>

void initTimer1(void);
void pwmGen(uint16_t value);


#endif // PWM_H_INCLUDED
