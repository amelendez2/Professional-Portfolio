/*
 * ColorLED.h
 *
 *  Created on: Nov 28, 2014
 *      Author: Tony
 */

#ifndef COLORLED_H_
#define COLORLED_H_

#include <Arduino.h>

class ColorLED {
public:
	ColorLED(int red, int green, int blue, int red_pin, int green_pin, int blue_pin);
		void red(int red_pin, int green_pin, int blue_pin);							// methods that set colors to led
		void green(int red_pin, int green_pin, int blue_pin);
		void blue(int red_pin, int green_pin, int blue_pin);
		void purple(int red_pin, int green_pin, int blue_pin);
		void pink(int red_pin, int green_pin, int blue_pin);
		void orange(int red_pin, int green_pin, int blue_pin);
		void yellow(int red_pin, int green_pin, int blue_pin);
		void cyan(int red_pin, int green_pin, int blue_pin);
		void tan(int red_pin, int green_pin, int blue_pin);
		void silver(int red_pin, int green_pin, int blue_pin);
		void white(int red_pin, int green_pin, int blue_pin);
		//------- Common Cathode RGB LED Colors -------------
		void ccred(int red_pin, int green_pin, int blue_pin);							// methods that set colors to led
		void ccgreen(int red_pin, int green_pin, int blue_pin);
		void ccblue(int red_pin, int green_pin, int blue_pin);
		void ccpurple(int red_pin, int green_pin, int blue_pin);
		void ccpink(int red_pin, int green_pin, int blue_pin);
		void ccorange(int red_pin, int green_pin, int blue_pin);
		void ccyellow(int red_pin, int green_pin, int blue_pin);
		void cccyan(int red_pin, int green_pin, int blue_pin);
		void cctan(int red_pin, int green_pin, int blue_pin);
		void ccsilver(int red_pin, int green_pin, int blue_pin);
		void ccwhite(int red_pin, int green_pin, int blue_pin);
		void colorphase(int red, int green, int blue);  				// Used to seamlessly transition colours
		
private:
	int Red_Concentration;
	int Green_Concentration;
	int Blue_Concentration;
	int RedPinOut;
	int GreenPinOut;
	int BluePinOut;
};

#endif /* COLORLED_H_ */
