/**
 * @file led.h
 * @author Arrijith KM (arrijithkm@gmail.com)
 * @brief Header files to declare LED related functions and defining some macros
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

void peripheral_init(void);
int ledSwitch(void);
void ledState(uint8_t state);
void initTimer0(void);
void ledToggle(void);

volatile uint16_t tot_overflow;

#define LED_ON (0x01)
#define LED_OFF (0x00)
#define LED_PORT (PORTB)
#define LED_PIN (PORTB0)
#define F_CPU 16000000UL

#endif // LED_H_INCLUDED
