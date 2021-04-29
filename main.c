/**
 * @file main.c
 * @author Arrijith KM (arrijithkm@gmail.com)
 * @brief Project to turn ON car heater automatically if a person is detected inside car
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/* including the defined libraries*/

#include"adc.h"
#include"led.h"
#include"pwm.h"
#include"disp.h"

/**
 * @brief Main program for the application where it calls every function based on the need
 * 
 * @return int 
 */
int main(void)
{
    peripheral_init();  /* initialise every peripherals */
    initAdc();          /* initialise the ADC to get PWM */ 
    initTimer0();       /* initialise 8 bit timer for interrupts */
    initTimer1();       /* initialise 16 bit timer to generate PWM wave */
    USARTinit(103);     /* calling UART funtion with UBRR value as 103 */

    uint16_t temp;

    while(1)
    {
        if(ledSwitch())
        {
            ledState(LED_ON);
            temp = readAdc(8);
            _delay_ms(100);
            pwmGen(temp);
            displayTemp(temp);
        }
        else{
            ledState(LED_OFF);
            _delay_ms(100);
        }
    }

    return 0;           /* return 0 if programs ends successfully */
}
