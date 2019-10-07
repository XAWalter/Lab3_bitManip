/*	Author: xwalt001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char amtOnes = 0x00;    

    /* Insert your solution below */
    while (1) {
        tmpA = PINA;
        tmpB = PINB;
	amtOnes = 0;
	unsigned char i = 0;
	
	for(i = 0; i < 8; i++){
	    amtOnes = amtOnes + ((tmpA >> i) & 0x01);
	}

	for(i = 0; i < 8; i++){
	    amtOnes = amtOnes + ((tmpB >> i) & 0x01);
	}

        PORTC = amtOnes;
	 
    }
    return 1;
}
