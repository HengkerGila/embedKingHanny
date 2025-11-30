#include "app.h"
#include "display.h"
#include "led.h"
#include "button.h"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <u8g2.h>

extern u8g2_t u8g2;

void app_init() {
    // Initialize hardware components
    led_hal_init();
    // display_init();
    // buttons_init();
}

void app_game() {
    // Main application logic goes here
    // For example, you can run a loop to check button states and update the display or LEDs accordingly.
    // display_draw_logo(u8g2);
    // led_test_sequence();
    testing_doang();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    
}