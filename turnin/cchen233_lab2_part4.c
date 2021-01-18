/*	Author:Christopher Chen
 *  Partner(s) Name: 
 *	Lab Section:21
 *	Assignment: Lab #2  Exercise #4
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s
	unsigned char totalWeight = 0x00; // Temporary variable to hold the total weight
	
	while(1) {
		// 1) Find total weight
		totalWeight = PINA + PINB + PINC;
		// 2) Check if weight exceeds 140kgs
		if(totalWeight > 140)
			totalWeight = totalWeight | 0x01;
		else
			totalWeight = totalWeight & 0xFE;
		// 3) Check if A / C difference exceeds 80kgs
		if((PINA - PINC > 80) || (PINC - PINA > 80))
			totalWeight = totalWeight | 0x02;
		else
			totalWeight = totalWeight & 0xFD;
			
				
		// 3) Write output
		PORTD = totalWeight;
	}
	return 0;
}

