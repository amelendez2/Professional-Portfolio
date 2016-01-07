/// Function for calculating average of buffers for each ADC controller
// Also parameters for pass or fail for directions

#include <msp430.h>
#include <stdio.h>
#include <stdlib.h>
#include "adcMsp.h"
#include "main_console_menu.h"

// Buffer for ADC 1 (controller 1)
int buffer_1_avg( char coordinate_1 )
{

int buffer_1[255] = {0};
int i;

unsigned int sum = 0;


	for( i = 0; i < 255; i++ )
	{
		buffer_1[i] = adc_measure(coordinate_1);
		sum += buffer_1[i];
	}
return sum / 255;
}


// Buffer for ADC 2 (controller 2)
int buffer_2_avg( char coordinate_2 )
{
int buffer_2[255];
int i;

unsigned int sum = 0;


	for( i = 0; i < 255; i++ )
	{
		buffer_2[i] = adc_measure(coordinate_2);
		sum += buffer_2[i];
	}
return sum / 255;
}
/*
 *
 */
// Checks for condition when adc 1 up is true
int adc_up_1(void)
{

unsigned int up;

	if (adc_measure(2) < 300)
	{
		up = ADC10MEM;
		TA0CCR1 = TA0CCR0;
	}
	else
		up = adc_measure(2);

return up;
}

// Checks when adc 2 is up
int adc_up_2(void)
{

unsigned int up;

	if (adc_measure(2) < 300)
	{
		up = ADC10MEM;
		TA0CCR1 = TA0CCR0;
	}
	else
		up = adc_measure(2);

return up;
}

// Checks when adc 1 is down
int adc_down_1(void)
{

unsigned int down;

	if (adc_measure(2) < 300)
	{
		down = ADC10MEM;
		TA0CCR1 = TA0CCR0;
	}
	else
		down = adc_measure(2);

return down;
}


// Checks when adc 2 is down
int adc_down_2(void)
{

unsigned int down;

	if (adc_measure(2) < 300)
	{
		down = ADC10MEM;
		TA0CCR1 = TA0CCR0;
	}
	else
		down = adc_measure(2);

return down;
}
