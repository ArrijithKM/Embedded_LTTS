#include <avr/io.h>
#include<util/delay.h>
#include "adc.h"
void initAdc(void)
{
    ADMUX |= (1<<REFS0);
    ADCSRA |= (1<<ADEN) | (1<ADPS0);
}

uint16_t readAdc(uint16_t channel)
{
    ADMUX &= 0xF8;
    channel = channel&0b00000111;
    ADMUX |= channel;
    ADCSRA |= (1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|(1<<ADIF);
    return(ADC);
}
