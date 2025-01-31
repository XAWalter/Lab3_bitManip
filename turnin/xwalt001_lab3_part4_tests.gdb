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
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    /* Insert your solution below */
    while (1) {
	//read from input
	tmpA = PINA;

	//tmp B = b7b6b5b40000 | 0000a7a6a5a4 = b7b6b5b4a7a6a5a4	
	tmpB = ( tmpB & 0xF0 ) | ( tmpA >> 4 );

	//tmpC = 0000c3c2c1c0 | a3a2a1a00000 = a3a2a1a0c3c2c1c0
	tmpC = ( tmpC & 0x0F ) | ( tmpA << 4 );

	PORTB = tmpB;
	PORTC = tmpC;
    }
    return 1;
}
