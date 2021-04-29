#include <avr/io.h>
#include <util/delay.h>
#include"led.h"

void peripheral_init(void)
{
    DDRB |= (1<<PB0);
    DDRB |= (1<<PB1);

    DDRD &= ~(1<<PD0);
    PORTD |= (1<<PD0);

    DDRD &= ~(1<<PD1);
    PORTD |= (1<<PD1);
}

void initTimer0(void)
{

    TCCR0B |= (1<<CS02) ; //prescalar 256
    TCNT0 = 0;
    TIMSK0 |= (1<<TOIE0);
    sei();
    tot_overflow = 0;
}

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
void ledState(uint8_t state)
{
    LED_PORT = (state<<LED_PIN);
}
