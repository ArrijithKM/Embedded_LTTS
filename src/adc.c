/**
 * @file adc.c
 * @author Arrijith KM (arrijithkm@gmail.com)
 * @brief Program to read Potentiometer and perform ADC
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include<util/delay.h>
#include "adc.h"
/**
 * @brief initialise ADC registers
 * 
 */
void initAdc(void)
{
    ADMUX |= (1<<REFS0);
    ADCSRA |= (1<<ADEN) | (1<ADPS0);
}
/**
 * @brief Read values from pot and perform ADC
 * 
 * @param channel 
 * @return uint16_t digital value
 */
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
