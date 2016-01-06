/*
 * main_console_menu.h
 *
 *  Created on: Jul 28, 2013
 *      Author: tony
 */

#ifndef MAIN_CONSOLE_MENU_H_
#define MAIN_CONSOLE_MENU_H_

#define 	reset_button	BIT7

void play_main_game(void);
int buffer_1_avg(char coordinate_1);
int buffer_2_avg(char coordinate_2);
void melody(void);
int adc_up_1(void);
int adc_up_2(void);
int adc_down_1(void);
int adc_down_2(void);

#endif /* MAIN_CONSOLE_MENU_H_ */
