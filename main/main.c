#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include <string.h>
#include "sdkconfig.h"
#include "app.h"


void app_main(void)
{
	app_init();
	while(1){
		app_game();
	}
}