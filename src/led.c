/**
 * @file led.c
 * @author Arrijith KM (arrijithkm@gmail.com)
 * @brief Program to make LED ON if person is inside the car
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include <util/delay.h>
#include"led.h"
/**
 * @brief initialising every periperals
 * 
 */
void peripheral_init(void)
{
    DDRB |= (1<<PB0);               /* Set Pin B0 for LED */
    DDRB |= (1<<PB1);               /* Set Pin B1 for PWM */

    DDRD &= ~(1<<PD0);              /* Clearing D0 PIN for button switch 1 */
    PORTD |= (1<<PD0);              /* Set Pin D0 for button switch 1 */

    DDRD &= ~(1<<PD1);              /* Clearing D1 PIN for button switch 2 */
    PORTD |= (1<<PD1);              /* Set Pin D1 for button switch 2 */
}
/**
 * @brief initialise 8 bit timer for interrupt
 * 
 */
void initTimer0(void)
{

    TCCR0B |= (1<<CS02) ; //prescalar 256
    TCNT0 = 0;
    TIMSK0 |= (1<<TOIE0);
    sei();
    tot_overflow = 0;
}
/**
 * @brief Construct a new ISR object to control overflow
 * 
 */
ISR(TIMER0_OVF_vect)
{
    tot_overflow++;
}

/*void ledToggle(void)
{
    if(tot_overflow>=12)
    {
        if(TCNT0 >= 53)
        {
            LED_PORT = (1<<LED_PIN);
            TCNT0 = 0;
            tot_overflow = 0;
        }
    }
}*/
/**
 * @brief Program to make sure both switches are ON
 * 
 * @return 1 if both switches are ON
 */
int ledSwitch(void)
{
    if((!(PIND&(1<<PD0))) && (!(PIND&(1<<PD1))))
    {
        return 1;
    }
    else{
        return 0;
    }
}
/**
 * @brief Function to change LED ON or OFF
 * 
 * @param state 
 */
void ledState(uint8_t state)
{
    LED_PORT = (state<<LED_PIN);
}
