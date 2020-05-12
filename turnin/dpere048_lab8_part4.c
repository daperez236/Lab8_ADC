/*	Author: dpere048
 *  Partner(s) Name: 
 *	Lab Section:021
 *	Assignment: Lab #8  Exercise #4
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
    /* Insert your solution below */
    while (1) {
	unsigned short x = ADC;
	if(x <= 1024){
		tmpB = 0x00;
	}
	else if(x <= 896){
		tmpB = 0x01;
	}
        else if(x <= 768){
                tmpB = 0x02;
        }
        else if(x <= 640){
                tmpB = 0x04;
        }
        else if(x <= 512){
                tmpB = 0x08;
        }
        else if(x <= 384){
                tmpB = 0x10;
        }
        else if(x <= 256){
                tmpB = 0x20;
        }
        else if(x <= 128){
                tmpB = 0x40;
        }
	else if(x <= 0){
		tmpB = 0x80;
	}
	}
    return 1;
}
