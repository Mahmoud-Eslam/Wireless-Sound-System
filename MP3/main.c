/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Elbekoo
 */

#include "USART.h"
#include <avr/delay.h>

void playnext();
void playprevious();
void incerasevolume();
void decreasevolume();
void ToggleLamp();

int main() {
	//LED FOR INDICATION
	DDRB |= (1<<0);
	PORTB |= (1<<0);
	//relay for Lamp
	DDRA |= (1 << 2);
	PORTA |= (1 << 2);
	//relay for mp3
	DDRA |= (1 << 0) | (1 << 1);
	decreasevolume(); //decrease volume
	decreasevolume();
	_delay_ms(500);

	//initialize uart for wireless control
	//define uart pins
	DDRD &= ~(1 << 0); //RX
	DDRD |= (1 << 1); //TX
	PORTD &= ~(1 << 0); //RX
	PORTD &= ~(1 << 1); //TX
	UART_INIT();
	_delay_ms(100);

	while (1) {
		s8 recieved_char = UART_Recieve();
		if (recieved_char == '1') {
			playnext();
		} else if (recieved_char == '2') {
			playprevious();
		} else if (recieved_char == '3') {
			incerasevolume();
		} else if (recieved_char == '4') {
			decreasevolume();
		} else if (recieved_char == '5') {
			ToggleLamp();
		}
	}
	return 0;
}
void playnext() {
	PORTA |= (1 << 0);
	_delay_ms(100);
	PORTA &= ~(1 << 0);
	_delay_ms(1000);
}
void playprevious() {
	PORTA |= (1 << 1);
	_delay_ms(100);
	PORTA &= ~(1 << 1);
	_delay_ms(1000);
}
void incerasevolume() {
	PORTA |= (1 << 0);
	_delay_ms(2000);
	PORTA &= ~(1 << 0);
	_delay_ms(1000);
}
void decreasevolume() {
	PORTA |= (1 << 1);
	_delay_ms(2000);
	PORTA &= ~(1 << 1);
	_delay_ms(1000);
}
void ToggleLamp() {
	PORTA ^= (1 << 2);
}
