/**
 * @file disp.h
 * @author Arrijith KM (arrijithkm@gmail.com)
 * @brief Header files to declare USART related functions
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef DISP_H_INCLUDED
#define DISP_H_INCLUDED

#include<avr/io.h>
#include<util/delay.h>

void USARTinit(uint16_t );
void USARTwriteChar(char );
void displayTemp(uint16_t );

#endif // DISP_H_INCLUDED
