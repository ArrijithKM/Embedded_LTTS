#ifndef DISP_H_INCLUDED
#define DISP_H_INCLUDED

#include<avr/io.h>
#include<util/delay.h>

void USARTinit(uint16_t );
char USARTreadChar();
void USARTwriteChar(char );
void displayTemp(uint16_t );

#endif // DISP_H_INCLUDED
