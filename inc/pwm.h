/**
 * @file pwm.h
 * @author Arrijith KM (arrijithkm@gmail.com)
 * @brief Header files to declare pwm related functions
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED


#include<avr/io.h>
#include<util/delay.h>

void initTimer1(void);
void pwmGen(uint16_t value);


#endif // PWM_H_INCLUDED
