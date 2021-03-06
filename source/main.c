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
	unsigned short LIMIT = 1024;
	unsigned char tmpA = 0x00;
    /* Insert your solution below */
    while (1) {
	unsigned short x = ADC;
	if(x <= LIMIT){
		tmpA = 0x00;
	}
	else if(x <= LIMIT*.875){
		tmpA = 0x01;
	}
        else if(x <= LIMIT*.75){
                tmpA = 0x02;
        }
        else if(x <= LIMIT*.625){
                tmpA = 0x04;
        }
        else if(x <= LIMIT*.5){
                tmpA = 0x08;
        }
        else if(x <= LIMIT*.375){
                tmpA = 0x10;
        }
        else if(x <= LIMIT*.25){
                tmpA = 0x20;
        }
        else if(x <= LIMIT*.125){
                tmpA = 0x40;
        }
	else if(x <= 0){
		tmpA= 0x80;
	}
	PORTB = tmpA;
	}
    return 1;
}
