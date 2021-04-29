/**
 * @file adc.h
 * @author Arrijith KM (arrijithkm@gmail.com)
 * @brief Header files to declare ADC related functions
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ADC_H_INCLUDED
#define ADC_H_INCLUDED

#include<avr/io.h>
#include<util/delay.h>

void initAdc(void);
uint16_t readAdc(uint16_t channel);

#endif // ADC_H_INCLUDED
