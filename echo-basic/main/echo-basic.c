#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#define MAX_INPUT_SIZE 201

void app_main () {
	char buff[MAX_INPUT_SIZE], c;
	int i;
	while(1) {
		c = ' ';
		i = 0;
		printf("Write Here: ");
		fflush(stdout);
		while(c != '\n' && i < MAX_INPUT_SIZE - 1) {
			while(fread(&c, 1, 1, stdin) !=1) {
				vTaskDelay(1);
			}
			printf("%c", c);
			fflush(stdout);
			buff[i++] = c;
		}
		buff[i] = '\0';
		printf("\nYou've Entered: %s", buff);
	}
}
