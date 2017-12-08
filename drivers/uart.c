/*
 * uart.c
 *
 *  Created on: Dec 7, 2017
 *      Author: lwsdev
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include "uart.h"

#define UART_C 		"/dev/ttymxc2"

void uartInit() {
	int fd;
	struct termios port_options;

	fd = open(UART_C, O_RDWR | O_NOCTTY);
	if (-1 == fd) {
		perror("Could not open UART port");
	}

	tcgetattr(fd, &port_options);

	/* Set baud to GPS module's baud rate (9600) */
	cfsetospeed(&port_options, B9600);

	tcsetattr(fd, TCSANOW, &port_options);
}
