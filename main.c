/*
 */
#include"adc.h"
#include"led.h"
#include"pwm.h"
#include"disp.h"

int main(void)
{

    // Insert code
    peripheral_init();
    initAdc();
    initTimer0();
    initTimer1();
    USARTinit(103);

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

    return 0;
}
