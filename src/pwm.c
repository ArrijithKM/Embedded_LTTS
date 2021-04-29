#include"pwm.h"

void initTimer1(void)
{
    TCCR1A |= (1<<COM1A1) | (1<<WGM10) | (1<<WGM11);
    TCCR1B |= (1<<WGM12) | (1<<CS11) | (1<<CS10) ;// 64 prescalar


}
void pwmGen(uint16_t value)
{
    if(value>0 && value<=200)
        {
            OCR1A = 205;            //20% duty cycle
            //_delay_ms(100);
        }
        else if(value>=210 && value<=500)
        {
            OCR1A = 410;            //40% duty cycle
           // _delay_ms(100);
        }
        else if(value>=510 && value<=700)
        {
            OCR1A = 717;            //70% duty cycle
            //_delay_ms(100);
        }
        else if(value>=710 && value<=1024)
        {
            OCR1A = 973;            //95% duty cycle
            //_delay_ms(100);
        }
}
