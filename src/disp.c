#include"disp.h"
void USARTinit(uint16_t ubbr)
{

    UBRR0L = ubbr;
    UBRR0H = (ubbr>>8)&0x00ff;

    //UCSR0C = (1<<UMSEL00) | (1<<UCSZ01) | (1<<UCSZ00);
    UCSR0C = (1<<UMSEL00) | (1<<UCSZ01) | (1<<UCSZ00);

    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) | (1<<TXCIE0);
}

char USARTreadChar()
{
    while(!(UCSR0A & (1<<RXC0)))
    {
        //DO NOTHING
    }
    return UDR0;

}

void USARTwriteChar(char data)
{
    while(!(UCSR0A & (1<<UDRE0)))
    {

    }
        //DO nothing
    UDR0 = data;
    //UDR0 = '\n';
}

void displayTemp(uint16_t value)
{
    if(value>0 && value<=200)
        {
            //OCR1A = 205;
            USARTwriteChar(20);            //20% duty cycle
            _delay_ms(100);
        }
        else if(value>=210 && value<=500)
        {
            //OCR1A = 410;            //40% duty cycle
            USARTwriteChar(25);

            _delay_ms(100);
        }
        else if(value>=510 && value<=700)
        {
            //OCR1A = 717;            //70% duty cycle
            USARTwriteChar(29);
            _delay_ms(100);
        }
        else if(value>=710 && value<=1024)
        {
            //OCR1A = 973;            //95% duty cycle
            USARTwriteChar(33);
            _delay_ms(100);
        }
}
