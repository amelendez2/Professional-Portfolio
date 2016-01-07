#include <msp430g2553.h>
#include "lcdLib.h"
#include "adcMsp.h"

void main(void)

{

WDTCTL = WDTPW + WDTHOLD;// Stop Watchdog

// Setup I/O config. Initialize ADC and LCD

//P1DIR |= BIT6;                            // P1.6 output
adc_init();								  // Initialize ADC
lcdInit();								  // Initialize LCD

// Display voltage to LCD

while(1){
													// Measure p1.0
lcdSetInt(adc_measure(0), 0, 0);					// Display Voltage on LCD
lcdSetInt(adc_measure(1), 5, 0);					// Display Voltage on LCD
lcdSetInt(adc_measure(2), 10, 0);					// Display Voltage on LCD
lcdSetInt(adc_measure(3), 0, 1);					// Display Voltage on LCD
lcdSetInt(adc_measure(4), 5, 1);					// Display Voltage on LCD
lcdSetInt(adc_measure(5), 10, 1);					// Display Voltage on LCD

	//if (ADC10MEM > 200)
		//P1DIR |= BIT6;
	//else P1DIR |= BIT5;
}


__bis_SR_register(LPM0_bits);   // Enter Low Power Mode 0 without interrupts

}
