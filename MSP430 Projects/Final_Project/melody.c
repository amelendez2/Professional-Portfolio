// Interrupt Service Routine To play a Melody and Light an LED
// For PWM use Pin 1.2 or P1.6 only
// Connect P1.X to 330+ Ohm resistor to LED to Ground
// Optional: Connect a (Piezo buzzer + 330+ Ohm resistor) in parallel with the LED through the same P1.X (i.e. P1.2)
// 			 The higher the resistor on the buzzer the lower dB. Without a resistor it can be loud


#include <msp430g2553.h>

#define PERIOD		1000	// Period for Pulse Width Modulation.
							// If clock = 1MHZ -> Period = 1 second
int increment = 1;			// Value to increment my duty cycle,
							// must be declared outside of the ISR

void melody(void)
{

    WDTCTL = WDTPW+WDTTMSEL+WDTCNTCL;      	// Set Watchdog Timer (Setup WDT to be ISR)
    IE1 |= WDTIE;                         	// enable Watchdog timer interrupts

    P1DIR |= BIT6;                        	// Select bit 2 or bit 6 for PWM
    P1SEL |= BIT6;                        	// Selects bit 2 for digital i/o

    TA0CCR0 = PERIOD;                       // PWM period
    TA0CCR1 = 1;                          	// Duty cycle starts at this value (1ms)
    TA0CCTL1 = OUTMOD_7;                  	// TA0CCR1 reset/set
    TA0CTL = TASSEL_2 + MC_1;             	// TASSEL_2 = Timer A control set to
    									  	// SMCLK clock; MC_1 = count up

    _BIS_SR(LPM0_bits + GIE);             	// Enter Low power mode 1 (CPU and MCLK disabled)
}

// Interrupt Service Routine: This is where I will create a varying pulse that will cause
// the buzzer and an LED to vary in freq.

#pragma vector=WDT_VECTOR

  __interrupt void watchdog_timer(void)
  {
	int i;

		for (i=0; i<6; i++){

		switch (i){

			case 1:
				TA0CCR1 += increment*2;           		// Increase/decrease duty cycle
				if( TA0CCR1 > 998 || TA0CCR1 < 2 )   	// Checks the condition when it
														// reaches near full cycle or bottom
					increment = -increment;				// If it reaches the Top, start decrementing
					_delay_cycles(100000);				// delay until next Freq. input
				break;

			case 2:
				TA0CCR1 += increment*4;
				if( TA0CCR1 > 996 || TA0CCR1 < 4 )
					increment = -increment;
					_delay_cycles(100000);
				break;

			case 3:
				TA0CCR1 += increment*16;
				if( TA0CCR1 > 984 || TA0CCR1 < 16 )
									increment = -increment;
					_delay_cycles(100000);
				break;

			case 4:
				TA0CCR1 += increment*32;
				if( TA0CCR1 > 968 || TA0CCR1 < 32 )
									increment = -increment;
					_delay_cycles(100000);
				break;

			case 5:
				TA0CCR1 += increment*64;
				if( TA0CCR1 > 836 || TA0CCR1 < 64 )
									increment = -increment;
					_delay_cycles(100000);
				break;
					}


							}
		_BIC_SR(LPM0_EXIT);
}
