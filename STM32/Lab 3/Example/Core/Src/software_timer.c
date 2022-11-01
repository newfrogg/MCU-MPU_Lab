/*
 * software_timer.c
 *
 *  Created on: Nov 1, 2022
 *      Author: Beelzebufo
 */

#include "software_timer.h"

int timer_counter = 0;
int timer_flag = 0;

void setTimer(int duration){
	timer_counter = duration;
	timer_flag = 1;
}

void runTimer(){
	if (timer_counter > 0){
		timer_counter--;
		if (timer_counter == 0) {
			timer_flag = 1;
		}
	}
}
