/*
 * parser.c
 *
 *  Created on: Dec 7, 2017
 *      Author: lwsdev
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "parser.h"

#define MAX_STRING_SIZE 	15
#define FILE_PATH			"/home/lwsdev/Desktop/file.txt"

typedef struct {
	float latitude;
	char N_S;
	float longitude;
	char E_W;
} GPS;

void parse(char *input) {
	GPS gps_vals;
	char input_buffer[150];
	char *ln = NULL;
	char *token;
	int count = 0;
	size_t size = 0;

	FILE *fd;
	fd = fopen(FILE_PATH, "r");
	if (NULL == fd) {
		printf("file open failed\n");
	}

	while(getline(&ln, &size, fd) != -1) {
		strcpy(input_buffer, ln);
		token = strtok(input_buffer, ",");
		count = 0;
		while (token != NULL && count < 7) {
			switch (count) {
				case 3:
					gps_vals.latitude = atof(token);
					printf("Latitude: %f\n", gps_vals.latitude);
					break;
				case 4:
					gps_vals.N_S = token[0];
					printf("N/S: %c\n", gps_vals.N_S);
					break;
				case 5:
					gps_vals.longitude = atof(token);
					printf("Longitude: %f\n", gps_vals.longitude);
					break;
				case 6:
					gps_vals.E_W = token[0];
					printf("E/W: %c\n", gps_vals.E_W);
					break;
				default:
					printf("Count is: %d\n", count);
			}
			token = strtok(NULL, ",");
			count++;
		}
	}
	free(ln);

	fclose(fd);
}
