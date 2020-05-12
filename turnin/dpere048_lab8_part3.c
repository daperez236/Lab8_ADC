/*	Author: dpere048
 *  Partner(s) Name: 
 *	Lab Section:021
 *	Assignment: Lab #8  Exercise #3
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
	unsigned char tmpA = 0x00;
	unsigned short half = 500;
    /* Insert your solution below */
    while (1) {
	unsigned short x = ADC;
	if(x > half){
		half = x;
	}
	if(x >= half/2){
		tmpA = 0x00;
	}
	else{
		tmpA = 0x01;
	}
	}
    return 1;
}
