//// Single Microcontroller - 1 main console; 2 controllers; LCD; 2 accelerometers
//// This is the function that executes the main game
//
//#define		start_button1	BIT6
//#define		start_button2	BIT7
//
//
//#include <msp430.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include "lcdLib.h"
//#include "adcMsp.h"
//#include "main_console_menu.h"
//
//void main(void) {
//
//	// Stop WDT initialize lcd, adc and pins
//		WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
//		adc_init();
//		lcdInit();
//		P1DIR |= BIT6;				// LED + Buzzer
//		P1OUT &= ~BIT6;
//		P2DIR &= ~(start_button1 + start_button2);
//
//		int n, j;
//
//	// Setup Timers
//		TA0CTL = TASSEL_1 + MC_1;		// Using ACLK = 12kHz in count up mode
//		TA0CCTL1 = OUTMOD_7;			// TACCR1 = set/reset
//		TA0CCR0	= 24000;				// Period of 24/12 = 2sec/ period (each round will be 2 seconds) - will change for better implementation
//		TA0CCR1 = 0;					// duty cycle (we want a 100% duty cycle
//
//	// Main Loop
//
//		if((P2IN & start_button1) && (P2IN & start_button2) == 0xC0 );
//		{
//
//				P1OUT &= ~BIT6;
//
//		    	for(n=1; n<17; n++)
//		    	{
//		    		lcdClear();
//
//		    		for(j=0; j<n; j++)
//		    		{
//
//		    			int i = rand() % 6;
//
//		    			switch(i)
//		    			{
//		    				case 0:
//								lcdClear();
//		    					lcdSetText("Left", 0, 0);
//								while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
//								{
//									TA0CCR1 += 1;
//									if(( (buffer_1_avg('x1') == left() ) && (buffer_2_avg('x2') != left()) ) || (buffer_1_avg('x1') != left() ) && (buffer_2_avg('x2') == left()))
//									{
//										P1OUT |= BIT6;
//										j=n;
//										n=18;
//									}
//									else if ((buffer_1_avg('x1') == left()) && (buffer_2_avg('x2') == left()))
//										break;
//								}
//
//		    				case 1:
//								lcdClear();
//		    					lcdSetText("Right", 0, 0);
//		    					while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
//								{
//									TA0CCR1 += 1;
//									if(( (buffer_1_avg('x1') == right() ) && (buffer_2_avg('x2') != right()) ) || (buffer_1_avg('x1') != right() ) && (buffer_2_avg('x2') == right()))
//									{
//										P1OUT |= BIT6;
//										j=n;
//										n=18;
//									}
//									else if ((buffer_1_avg('x1') == right()) && (buffer_2_avg('x2') == right()))
//										break;
//								}
//
//		    				case 2:
//								lcdClear();
//		    					lcdSetText("Forward", 0, 0);
//		    					while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
//								{
//									TA0CCR1 += 1;
//									if(( (buffer_1_avg('y1') == forward() ) && (buffer_2_avg('y2') != forward()) ) || (buffer_1_avg('y1') != forward() ) && (buffer_2_avg('y2') == forward()))
//									{
//										P1OUT |= BIT6;
//										j=n;
//										n=18;
//									}
//									else if ((buffer_1_avg('y1') == forward()) && (buffer_2_avg('y2') == forward()))
//										break;
//								}
//
//		    				case 3:
//								lcdClear();
//		    					lcdSetText("Back", 0, 0);
//		    					while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
//								{
//									TA0CCR1 += 1;
//									if(( (buffer_1_avg('y1') == back() ) && (buffer_2_avg('y2') != back()) ) || (buffer_1_avg('y1') != back() ) && (buffer_2_avg('y2') == back()))
//									{
//										P1OUT |= BIT6;
//										j=n;
//										n=18;
//									}
//									else if ((buffer_1_avg('y1') == back()) && (buffer_2_avg('y2') == back()))
//										break;
//								}
//
//		    				case 4:
//								lcdClear();
//		    					lcdSetText("Up", 0, 0);
//		    					while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
//								{
//									TA0CCR1 += 1;
//									if(( (buffer_1_avg('z1') == up() ) && (buffer_2_avg('z2') != up()) ) || (buffer_1_avg('z1') != up() ) && (buffer_2_avg('z2') == up()))
//									{
//										P1OUT |= BIT6;
//										j=n;
//										n=18;
//									}
//									else if ((buffer_1_avg('z1') == up()) && (buffer_2_avg('z2') == up()))
//										break;
//								}
//
//		    				case 5:
//								lcdClear();
//		    					lcdSetText("Down", 0, 0);
//		    					while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
//								{
//									TA0CCR1 += 1;
//									if( ((buffer_1_avg('z1') == down() ) && (buffer_2_avg('z2') != down()) ) || ((buffer_1_avg('z1') != down() ) && (buffer_2_avg('z2') == down())) )
//									{
//										P1OUT |= BIT6;
//										j=n;
//										n=18;
//									}
//									else if ((buffer_1_avg('z1') == down()) && (buffer_2_avg('z2') == down()))
//										break;
//								}
//		    			}
//		    		}
//		    	}
//		}
//
//}
