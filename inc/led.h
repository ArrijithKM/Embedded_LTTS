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
