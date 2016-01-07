#include <msp430g2553.h>// include the appropriate uart library header file
#include  "uart_msp.h"

#define		start_button1	BIT0
#define		start_button2	BIT1

char x1,y1,z1,x2,y2,z2;
void main(void) {
	WDTCTL = WDTHOLD + WDTPW; // Stop Watchdog timer
	P2DIR &= ~(start_button1 + start_button2);

	clock_init(); // Set clock frequency to 1 MHz
	serial_init(); // Initialize UART module

		while(1){

			serial_charTX('y');

		}
}
