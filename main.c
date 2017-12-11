/*
 ============================================================================
 Name        : Toradex.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "drivers/uart.h"
#include "drivers/gpio.h"
#include "parser/parser.h"

int main(void) {
	printf("Starting...\n");
	int count = 0;
//	uartInit();
//	parse(NULL);
	gpioInit();
	while(1) {
		gpioSet(++count%2);
		sleep(2);
	}
	return 0;
}
