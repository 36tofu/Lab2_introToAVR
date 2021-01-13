/*	Author: lab
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
	DDRB = 0xFF; // Configure port B's 8 pins as outputs
	PORTB = 0x00; // Initialize PORTB output to 0’s
	
	unsigned char temp_input = 0x00; // Init output on PORTB to 0x00

	while(1){
		temp_input = PINA;
		PORTB = temp_input;
	}
	return 1;

    /* Insert your solution below */
    while (1) {

    }
    return 1;
}
