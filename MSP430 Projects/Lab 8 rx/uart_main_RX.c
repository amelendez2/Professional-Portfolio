#include <msp430g2553.h>
#include "uart_msp.h"	// include the appropriate uart library header file
#define	LED_1	BIT0
#define	LED_2	BIT6





void main(void)
{
	WDTCTL = WDTHOLD + WDTPW; // Stop Watchdog timer
	P1DIR |= BIT0;// Configure LED pins as outputs
	P1OUT &= BIT0;// Turn off LEDs

	clock_init(); // Set clock frequency to 1 MHz
	serial_init_inter(); // Initialize UART module

	IFG2 &= ~(UCA0RXIFG); // clear the Receive interrupt flag
	IE2 |= UCA0RXIE; // Enable UART interrupt
	__bis_SR_register(GIE); // Enable global interrupts

	while(1){}//create an infinite loop that does nothing (or goes into low power mode
}


#pragma vector = USCIAB0RX_VECTOR
__interrupt void RX_Function(void)
{
	char c;
	
	while(!(IFG2 & UCA0RXIFG)); //Make the CPU wait here until the receive...
        //...interrupt flag goes high...
	c = serial_charRX(); // Store received character

	switch(c){//use an if-else if-else chain OR switch-case statment to test the... //...received character c.

	case 'x':
			P1OUT |= LED_1 + LED_2;//if c is an 'x' then turn on both LEDs..
			break;
	case 'y':
			P1OUT |= LED_1;//if c is an 'y' then turn on ONLY the green LED
			P1OUT &= ~LED_2;
			break;

	case 'z':  //if c is a 'z' then turn on ONLY the red LED
			 P1OUT |= LED_1;
			 P1OUT &= ~LED_2;
			 break;

	default: P1OUT &= ~(LED_1 + LED_2);		  //otherwise turn off both LEDs

			}



}





