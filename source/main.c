/*	Author: dpere048
 *  Partner(s) Name: 
 *	Lab Section:021
 *	Assignment: Lab #8  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();
    /* Insert your solution below */
    while (1) {
	unsigned short x = ADC;
	unsigned char LEDS = (char)x;
	PORTB = LEDS;
	unsigned char LEDS2 = (char)(x >> 8);
	PORTD = LEDS2;
	}
    return 1;
}
