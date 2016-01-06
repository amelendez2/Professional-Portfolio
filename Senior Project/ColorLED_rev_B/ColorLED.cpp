/*
 * ColorLED.cpp
 *
 *  Created on: Nov 28, 2014
 *      Author: Tony
 */

#include "ColorLED.h"
#include <Arduino.h>

//------- Main Constructor for the ColorLED Class ------------
ColorLED::ColorLED(int red, int green, int blue, int red_pin, int green_pin, int blue_pin)
{

	// Concentration will set the value of RGB 0-255
	int Red_Concentration = red;
	int Green_Concentration = green;
	int Blue_Concentration = blue;

	// This will set the user defined pin i.e. user wants to write to pins 1, 5, 13
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	// This will write the specific hue for each rgb led to the desired output pwm pin
	analogWrite(RedPinOut, Red_Concentration);
	analogWrite(GreenPinOut, Green_Concentration);
	analogWrite(BluePinOut, Blue_Concentration);

}

/*  In the following methods, the user will define the color he/she wants to use
*	An example of this will be red(1,3,7);
*	This will tell the program to send the correct values to pins 1,3, and 7
*	in order to make the color Red.
*/

//---------- Color methods for user defined colors -------
void ColorLED::red(int red_pin, int green_pin, int blue_pin)
{
	// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255, 0, 0, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::green(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(0, 255, 0, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::blue(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(0, 0, 255, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::purple(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(132, 49, 121, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::pink(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(252, 15, 192, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::orange(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255, 127, 80, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::yellow(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255, 215, 0, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::cyan(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(0, 255, 255, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::tan(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(210, 180, 140, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::silver(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(192, 192, 192, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::white(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255, 255, 255, RedPinOut, GreenPinOut, BluePinOut);
}

//-------- The following methods are used when you have a Common Cathode RGB LED ----------------
//----------------------- 0 is high and 255 is low --------------------------------------------

void ColorLED::ccred(int red_pin, int green_pin, int blue_pin)
{
	// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(0, 255, 255, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::ccgreen(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255, 0, 255, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::ccblue(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255, 255, 0, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::ccpurple(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255-132, 255-49, 255-121, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::ccpink(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255-252, 255-15, 255-192, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::ccorange(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255-255, 255-127, 255-80, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::ccyellow(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255-255, 255-215, 255-0, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::cccyan(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255-0, 255-255, 255-255, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::cctan(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255-210, 255-180, 255-140, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::ccsilver(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255-192, 255-192, 255-192, RedPinOut, GreenPinOut, BluePinOut);
}

void ColorLED::ccwhite(int red_pin, int green_pin, int blue_pin)
{
// Copy pins to be used from the user
	int RedPinOut = red_pin;
	int GreenPinOut = green_pin;
	int BluePinOut = blue_pin;

	ColorLED(255-255, 255-255, 255-255, RedPinOut, GreenPinOut, BluePinOut);
}
