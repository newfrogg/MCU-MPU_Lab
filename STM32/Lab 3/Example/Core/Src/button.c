/*
 * button.c
 *
 *  Created on: Nov 1, 2022
 *      Author: Beelzebufo
 */

#include "button.h"
#include "main.h"
int button1_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;

int TimerForKeyPress = 200;

void subKeyProcess() {
	button1_flag = 1;
	//TODO
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
void getKeyInput() {
	KeyReg2 = KeyReg1;
	KeyReg1 = KeyReg0;
	KeyReg0 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)) {
		if (KeyReg2 != KeyReg3) {
			KeyReg3 = KeyReg2;

			if (KeyReg3 == PRESSED_STATE) {
				TimerForKeyPress = 200;
				subKeyProcess();
			}
		} else {
			TimerForKeyPress--;
			if (TimerForKeyPress == 0) {
				KeyReg3 = NORMAL_STATE;
			}
		}
	}
}

int isButton1Pressed() {
	if (button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}
