/*	Author:Christopher Chen
 *  Partner(s) Name: 
 *	Lab Section:21
 *	Assignment: Lab #2  Exercise #3
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
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char cntavail = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	
	while(1) {
		// 1) Read 4 LSBs of A
		tmpA = PINA & 0x0F;
		// 2) Perform computation
		cntavail = ((tmpA & 0x08) >> 3 ) +  ((tmpA & 0x04) >> 2 ) + 
		       	((tmpA & 0x02) >> 1 ) +  (tmpA & 0x01);   
		cntavail = 4 - cntavail;
		//if no space available set PC7 = 1
		if(cntavail == 0)
			cntavail = 0x80;
		// 3) Write output
		PORTC = cntavail;	
	}
	return 0;
}

