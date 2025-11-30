#include "button.h"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void buttons_init() {
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = (1ULL << BUTTON_DOWN) | (1ULL << BUTTON_UP) | (1ULL << BUTTON_LEFT) | (1ULL << BUTTON_RIGHT) | (1ULL << BUTTON_SELECT);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE; // Enable pull-up resistors
    gpio_config(&io_conf);
}

bool button_is_pressed(gpio_num_t button_pin) {
    return gpio_get_level(button_pin) == 0; // Active low
}

bool button_wait_for_press(gpio_num_t button_pin, TickType_t timeout) {
    TickType_t start_tick = xTaskGetTickCount();
    while (xTaskGetTickCount() - start_tick < timeout) {
        if (button_is_pressed(button_pin)) {
            return true;
        }
        vTaskDelay(10 / portTICK_PERIOD_MS); // Poll every 10 ms
    }
    return false; // Timeout
}

bool button_wait_for_release(gpio_num_t button_pin, TickType_t timeout) {
    TickType_t start_tick = xTaskGetTickCount();
    while (xTaskGetTickCount() - start_tick < timeout) {
        if (!button_is_pressed(button_pin)) {
            return true;
        }
        vTaskDelay(10 / portTICK_PERIOD_MS); // Poll every 10 ms
    }
    return false; // Timeout
}

void button_debounce_delay() {
    vTaskDelay(50 / portTICK_PERIOD_MS); // 50 ms debounce delay
}