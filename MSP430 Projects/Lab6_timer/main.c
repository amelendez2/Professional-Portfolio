// Lab 6
// TA0CCR1 counts up to 1100

#define INCREMENT_BY 	2   	// increment TA0CCR1 value by this much
#define LOW_DUTY_CYCLE 	2    	// near-zero percent duty cycle
#define HIGH_DUTY_CYCLE 1100   	// near 100% duty cycle
#define COUNT_UP		1		// count up(Brighter)
#define COUNT_DOWN		0		// count down(dim)
#define BUTTON  		BIT3    // push button is P1.3
#define PERIOD			2000	// Timer value
#define INTERVAL  		10  	// Only increment TACCR1 every INTERVAL

#include <msp430g2553.h>

void main(void)
{
  WDTCTL = WDTPW | WDTHOLD;                 // Stop watchdog timer
  BCSCTL3 |= LFXT1S_2;                      // Select VLO as low freq clock

// Setup P1.3(push button), P1.6(LED). Setup Timers
  P1DIR |= BIT6;                            // P1.6 output
  P1SEL |= BIT6;                            // P1.6 Select
  P1REN |= BUTTON;                          // P1.3 pulldown resistor enable
  P1OUT &= ~BUTTON;                         // P1.3 resistor low
  P1SEL &= ~BUTTON;                         // P1.3 I/O

  TACCR0 = PERIOD;                          // PWM Period
  TACCTL0 |= CCIE;                          // enable interrupt
  TACCTL1 = OUTMOD_7;                      // TA0CCR1 reset/set
  TACCR1 = LOW_DUTY_CYCLE;                    // TA0CCR1 PWM to low duty cycle
  TACTL = TASSEL_2 | MC_1 ;                // SMCLK source, count in up mode
  TACCR0 &= ~CCIFG;                        // clear interrupt flag

  // setup pin to toggle LED on and off
  P1DIR &= ~BUTTON;
  P1IN |= BUTTON;
  P1IE |= BUTTON;
  P1IES |= BUTTON;
  P1IFG &= ~BUTTON;


  __bis_SR_register(LPM0_bits + GIE);      // go to sleep in low-power mode 0, all interrupts enabled
}

#pragma vector=PORT1_VECTOR;
void __interrupt Port_1(void) {
    if (P1IFG &= ~BUTTON) {      // button pressed?
        if (TACCR0 == 0) {     // Off, turn it on
            TACCTL1 = OUTMOD_7;   // return to output mode 7
            TACCR0 = PERIOD;
        } else {               // On, turn it off...
            TACCTL1 = OUTMOD_0 & ~OUT;    // by setting the output mode 0 and output pin low...
            TACCR0 = 0;        // and stopping the counter
        }

    }
    P1IFG &= BUTTON;
}

#pragma vector=TIMER0_A0_VECTOR;
void __interrupt Timer0(void) {
    static int intensity = COUNT_UP;    // Increase Intensity of LED
    static int i = 0;      // count the number of times this function is called.

    if (i == INTERVAL) {                        // only execute this every INTERVAL times
        if (TACCR1 > LOW_DUTY_CYCLE && intensity == COUNT_DOWN)   // count down, dim lights
            TACCR1 -= INCREMENT_BY;
        else if (TACCR1 < HIGH_DUTY_CYCLE && intensity == COUNT_UP)   // count up, brighter lights
            TA0CCR1 += INCREMENT_BY;
        if (TACCR1 == LOW_DUTY_CYCLE)                          // hit bottom, turn around and go back up
        	intensity = COUNT_UP;
        if (TACCR1 == HIGH_DUTY_CYCLE)                          // all the way up, start counting back down
            intensity = COUNT_DOWN;
        i = 0;
    } else {
        i++;
    }

}
