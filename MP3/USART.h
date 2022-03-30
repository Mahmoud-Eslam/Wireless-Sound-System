/*
 * USART.h
 *
 *  Created on: Nov 27, 2021
 *      Author: mahmoud
 */

#ifndef HAL_USART_USART_H_
#define HAL_USART_USART_H_
typedef signed char s8;
typedef unsigned char u8;

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/delay.h>
#define BaudRate 9600

#ifndef DoubleSpeed
#define MyUBRR ((F_CPU/(BaudRate*16UL))-1)
#else
#define MyUBRR ((F_CPU/(BaudRate*8UL))-1)
#endif

void UART_INIT();
void UART_TransmitChar(s8 data);
s8 UART_Recieve();
void UART_TransmitString(s8 * data);

#endif /* HAL_USART_USART_H_ */
