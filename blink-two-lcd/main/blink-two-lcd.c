#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

void app_main() {
	int i = 2;
	gpio_set_direction(2, (unsigned long)2);
  // gpio_set_direction(2, ((uint64_t)(((uint64_t)1)<<32)));
	gpio_set_direction(23, (unsigned long)2);

	while(1) {
		// gpio_set_direction(i, (unsigned long)2);  //Optional
		printf("Hello.. %d\n",i);
		gpio_set_level(i,1);
		vTaskDelay(100);
		gpio_set_level(i,0);
		vTaskDelay(100);
		if(i == 2)
			i = 23;
		else
			i = 2;
	}
}
