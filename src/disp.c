/**
 * @file disp.c
 * @author Arrijith KM (arrijithkm@gmail.com)
 * @brief Program to display temperature
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include"disp.h"
/**
 * @brief Initialise USART communication to print in serial monitor
 * 
 * @param ubrr 
 */
void USARTinit(uint16_t ubrr)
{

    UBRR0L = ubrr;
    UBRR0H = (ubrr>>8)&0x00ff;
    UCSR0C = (1<<UMSEL00) | (1<<UCSZ01) | (1<<UCSZ00);
    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) | (1<<TXCIE0);
}
/**
 * @brief funtion to print values in Serial Monitor
 * 
 * @param data 
 */
void USARTwriteChar(char data)
{
    while(!(UCSR0A & (1<<UDRE0)))
    {
        //DO nothing
    }
    UDR0 = data;
}
/**
 * @brief Program to display repective temperature values
 * 
 * @param value 
 */
void displayTemp(uint16_t value)
{
    if(value>0 && value<=200)
        {
            USARTwriteChar(20);                     // 20 degrees celsius 
            _delay_ms(100);
        }
        else if(value>=210 && value<=500)
        {           
            USARTwriteChar(25);                     // 25 degrees celsius 
            _delay_ms(100);
        }
        else if(value>=510 && value<=700)
        {
            USARTwriteChar(29);                     // 29 degrees celsius 
            _delay_ms(100);
        }
        else if(value>=710 && value<=1024)
        {
            USARTwriteChar(33);                     // 33 degrees celsius 
            _delay_ms(100);
        }
}
