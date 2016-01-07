// Single Microcontroller - 1 main console; 2 controllers; LCD; 2 accelerometers
// This is the function that executes the main game

//#define		start_button1	BIT6
//#define		start_button2	BIT7


#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>
#include "lcdLib.h"
#include "adcMsp.h"
#include "main_console_menu.h"

void main(void) {

	// Stop WDT initialize lcd, adc and pins
		WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
		adc_init();
		lcdInit();
		P2DIR &= ~0x40;				// Controller start button to start game
		P2SEL = 0x40;
		int n, j;					// n = level, j = round per level


	// Setup Timers
		TA0CTL = TASSEL_1 + MC_1;		// Using ACLK = 12kHz in count up mode
		TA0CCTL1 = OUTMOD_7;			// TACCR1 = set/reset
		TA0CCR0	= 18000;				// Period of 18/12 = 1.5sec/ period (each round will be 1.5 seconds) - will change for better implementation
		TA0CCR1 = 0;					// duty cycle (we want a 100% duty cycle)
										// Additionally to implement a faster game, change the speed at which duty cycle increments i.e *2

	// Main Loop

		lcdSetText("Press Start",0,0);
while(1){
		if( (P2IN & 0x40) == 0x40 )
		{

				P2OUT &= ~BIT6;

		    	for(n=1; n<17; n++)
		    	{
		    		lcdClear();

		    		for(j=0; j<n; j++)
		    		{

		    			int random = rand() % 6;

		    			switch(random)
		    			{
		    				case 0:
								lcdClear();
		    					lcdSetText("Front", 0, 0);
		    					TA0CCR1 = 0;
								while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
								{
									delay_us(50);
									TA0CCR1 += 1;
									if (TA0CCR1 == TA0CCR0)
									{
										if (( (adc_measure(0) >= 150 ) && (adc_measure(0) <= 400) ) && (adc_measure(3) <= 150) )
										{
											lcdSetText("Player 1 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if (( (adc_measure(3) >= 150 ) && (adc_measure(3) <= 400) ) && (adc_measure(0) <= 150) )
										{
											lcdSetText("Player 2 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if ( (adc_measure(0) >= 150) && (adc_measure(3) >= 150) )
											break;
										else if ( (adc_measure(0) <= 150) && (adc_measure(3) <= 150) )
										{
													lcdSetText("Both Lose", 0,1);
													melody();
													n=18;
													j=n;
													TA0CCR1 = TA0CCR0;
										}

									}
								}

		    				case 1:
								lcdClear();
		    					lcdSetText("Back", 0, 0);
		    					TA0CCR1 = 0;
		    					while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
								{
		    						delay_us(50);
		    						TA0CCR1 += 1;
									if (TA0CCR1 == TA0CCR0)
									{
										if (( (adc_measure(0) >= 500 ) && (adc_measure(0) <= 1024) ) && (adc_measure(3) <= 500) )
										{
											lcdSetText("Player 1 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if (( (adc_measure(3) >= 500 ) && (adc_measure(3) <= 1024) ) && (adc_measure(0) <= 500) )
										{
											lcdSetText("Player 2 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if ( (adc_measure(0) >= 500) && (adc_measure(3) >= 500) )
											break;

										else if ( (adc_measure(0) <= 500) && (adc_measure(3) <= 500) )
										{
													lcdSetText("Both Lose", 0,1);
													melody();
													n=18;
													j=n;
													TA0CCR1 = TA0CCR0;
										}

									}
								}

		    				case 2:
								lcdClear();
		    					lcdSetText("Left", 0, 0);
		    					TA0CCR1 = 0;
		    					while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
								{
		    						delay_us(50);
		    						TA0CCR1 += 1;
									if (TA0CCR1 == TA0CCR0)
									{
										if ( (adc_measure(1) >= 390 ) &&  (adc_measure(4) <= 150) )
										{
											lcdSetText("Player 1 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if (( (adc_measure(4) >= 150 ) && (adc_measure(4) <= 400) ) && (adc_measure(1) < 390) )
										{
											lcdSetText("Player 2 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if ( (adc_measure(1) >= 390) && (adc_measure(4) >= 150) )
											break;

										else if ( (adc_measure(1) < 390) && (adc_measure(4) <= 150) )
										{
													lcdSetText("Both Lose", 0,1);
													melody();
													n=18;
													j=n;
													TA0CCR1 = TA0CCR0;
										}

									}
								}

		    				case 3:
								lcdClear();
		    					lcdSetText("Right", 0, 0);
		    					TA0CCR1 = 0;
		    					while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
								{
		    						delay_us(50);
		    						TA0CCR1 += 1;
									if (TA0CCR1 == TA0CCR0)
									{
										if ( (adc_measure(1) <= 305 )  && (adc_measure(4) >= 500) )
										{
											lcdSetText("Player 1 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if (( (adc_measure(4) >= 500 ) && (adc_measure(4) <= 1024) ) && (adc_measure(1) > 310) )
										{
											lcdSetText("Player 2 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if ( (adc_measure(1) <= 305) && (adc_measure(4) >= 500) )
											break;

										else if ( (adc_measure(1) > 310) && (adc_measure(4) <= 500) )
										{
													lcdSetText("Both Lose", 0,1);
													melody();
													n=18;
													j=n;
													TA0CCR1 = TA0CCR0;
										}

									}
								}

		    				case 4:
								lcdClear();
		    					lcdSetText("Up", 0, 0);
		    					TA0CCR1 = 0;
		    					while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
								{
		    						unsigned int up_1, up_2;
		    						delay_us(50);
		    						TA0CCR1 += 1;
		    						if (adc_measure(2) < 1024)
										{
											up_1 = adc_measure(2);
										}
									if (adc_measure(5) < 1024)
										{
											up_2 = adc_measure(5);
										}
									if (TA0CCR1 == TA0CCR0)
									{
										if (( (up_1 >= 150 ) && (up_1 <= 400) ) && (up_2 <= 150) )
										{
											lcdSetText("Player 1 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if (( (up_2 >= 150 ) && (up_2 <= 400) ) && (up_1 <= 150) )
										{
											lcdSetText("Player 2 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if ( (up_1 >= 2) && (up_2 >= 2) )
											break;

										else if ( (up_1 <= 1) && (up_2 <= 1) )
										{
													lcdSetText("Both Lose", 0,1);
													melody();
													n=18;
													j=n;
													TA0CCR1 = TA0CCR0;
										}

									}
								}

		    				case 5:
								lcdClear();
		    					lcdSetText("Down", 0, 0);
		    					TA0CCR1 = 0;
		    					while(TA0CCR1 != TA0CCR0)		// This will allow the user X seconds to solve the direction
								{
		    						unsigned int down_1, down_2;
		    						delay_us(50);
		    						TA0CCR1 += 1;
		    						if (adc_measure(2) < 1024)
										{
											down_1 = adc_measure(2);
										}
									if (adc_measure(5) < 1024)
										{
											down_2 = adc_measure(5);
										}
									if (TA0CCR1 == TA0CCR0)
									{
										if (( (down_1 >= 500 ) && (down_1 <= 1024) ) && (down_2 <= 500) )
										{
											lcdSetText("Player 1 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if (( (down_2 >= 500 ) && (down_2 <= 1024) ) && (down_1 <= 500) )
										{
											lcdSetText("Player 2 wins", 0,1);
											melody();
											n=18;
											j=n;
											TA0CCR1 = TA0CCR0;
										}
										else if ( (down_1 >= 2) && (down_2 >= 2) )
											break;

										else if ( (down_1 <= 1) && (down_2 <= 1) )
										{
													lcdSetText("Both Lose", 0,1);
													melody();
													n=18;
													j=n;
													TA0CCR1 = TA0CCR0;
										}

									}
								}
		    			}
		    		}
		    	}
		}

}
}
