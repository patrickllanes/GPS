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
#include "drivers/uart.h"
#include "parser/parser.h"

int main(void) {
	printf("Starting...\n");
//	uartInit();
	parse(NULL);
	printf("done\n");
	return EXIT_SUCCESS;
}
