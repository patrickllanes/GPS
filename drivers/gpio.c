/*
 * gpio.c
 *
 *  Created on: Dec 11, 2017
 *      Author: patrick
 */

#include <stdio.h>
#include <stdlib.h>
#include "gpio.h"

void gpioInit() {
	// going to initalize Pin 14 on X16 header
	// quick hack to get it to work, move away from using system()
	system("echo 35 > /sys/class/gpio/export");
	system("echo out > /sys/class/gpio/gpio35/direction");
	system("echo rising > /sys/class/gpio/gpio35/edge");
}

void gpioSet(int value) {
	char gpio_command[40];

	sprintf(gpio_command, "echo %d > /sys/class/gpio/gpio35/value", value);
	system(gpio_command);
}
