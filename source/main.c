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
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpC = 0x00;
    /* Insert your solution below */
    while (1) {
        tmpA = PINA;
        

	if(tmpA <= 4){
	    tmpC = (tmpC | 0x40);
	}

	
	switch (tmpA){

	case 0:
	    tmpC = (tmpC & 0xC0);
	case 1:
	case 2:
            tmpC = (tmpC & 0x10);
	case 3:
	case 4:
            tmpC = (tmpC & 0x18);
        case 5: 
        case 6:
            tmpC = (tmpC & 0x18);
	     
 
    }
    return 1;
}
