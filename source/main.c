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
	DDRB = 0x01; PORTB = 0xFE;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned short tmpIB = 0x0000;
	unsigned char tmpOB = 0x00;
	unsigned short tmpD = 0x0000;
	unsigned short weight = 0x0000;
    /* Insert your solution below */
    while (1) {
	//assign inputs to variables	
        tmpIB = ( PINB & 0x01);
	tmpD = PIND;
	
	//add inputs to get total weight
	weight = tmpIB + tmpD;

	if( weight >= 70 ){
	    tmpOB = ( tmpOB & 0xF9) | 0x02;
	}
	else if ( weight > 5 ){
	    tmpOB = ( tmpOB & 0xF9) | 0x04;
	}
	else{
	    tmpOB = ( tmpOB & 0xF9) | 0x00;
	}
	
	PORTB = tmpOB;
    
    }
    return 1;
}
