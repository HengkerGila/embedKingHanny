#include "led.h"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void led_hal_init() {
    // Select GPIO pins for rows and columns
    esp_rom_gpio_pad_select_gpio(ROW1);
    esp_rom_gpio_pad_select_gpio(ROW2);
    esp_rom_gpio_pad_select_gpio(ROW3);
    esp_rom_gpio_pad_select_gpio(ROW4);
    esp_rom_gpio_pad_select_gpio(ROW5);
    esp_rom_gpio_pad_select_gpio(COL1);
    esp_rom_gpio_pad_select_gpio(COL2);
    esp_rom_gpio_pad_select_gpio(COL3);

    // Initialize row pins as output
    gpio_set_direction(ROW1, GPIO_MODE_OUTPUT);
    gpio_set_direction(ROW2, GPIO_MODE_OUTPUT);
    gpio_set_direction(ROW3, GPIO_MODE_OUTPUT);
    gpio_set_direction(ROW4, GPIO_MODE_OUTPUT);
    gpio_set_direction(ROW5, GPIO_MODE_OUTPUT);

    // Initialize column pins as output
    gpio_set_direction(COL1, GPIO_MODE_OUTPUT);
    gpio_set_direction(COL2, GPIO_MODE_OUTPUT);
    gpio_set_direction(COL3, GPIO_MODE_OUTPUT);

}

void testing_doang() {
    gpio_set_level(GPIO_NUM_12, 1);
    gpio_set_level(GPIO_NUM_17, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(GPIO_NUM_12, 0);
    gpio_set_level(GPIO_NUM_17, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(GPIO_NUM_14, 1);
    gpio_set_level(GPIO_NUM_17, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(GPIO_NUM_14, 0);
    gpio_set_level(GPIO_NUM_17, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(GPIO_NUM_27, 1);
    gpio_set_level(GPIO_NUM_17, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(GPIO_NUM_27, 0);
    gpio_set_level(GPIO_NUM_17, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(GPIO_NUM_26, 1);
    gpio_set_level(GPIO_NUM_17, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(GPIO_NUM_26, 0);
    gpio_set_level(GPIO_NUM_17, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(GPIO_NUM_25, 1);
    gpio_set_level(GPIO_NUM_17, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_set_level(GPIO_NUM_25, 0);
    gpio_set_level(GPIO_NUM_17, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}


void led_set(int row, int col, bool state) {
    int row_pin;
    int col_pin;

    // Map row and column to GPIO pins
    switch (row) {
        case 0: row_pin = ROW1; break;
        case 1: row_pin = ROW2; break;
        case 2: row_pin = ROW3; break;
        case 3: row_pin = ROW4; break;
        case 4: row_pin = ROW5; break;
        default: return; // Invalid row
    }

    switch (col) {
        case 0: col_pin = COL1; break;
        case 1: col_pin = COL2; break;
        case 2: col_pin = COL3; break;
        default: return; // Invalid column
    }

    // Set the LED state (assuming active low)
    gpio_set_level(row_pin, state ? 0 : 1);
    gpio_set_level(col_pin, state ? 0 : 1);
}

void led_clear() {
    // Turn off all row pins
    gpio_set_level(ROW1, 1);
    gpio_set_level(ROW2, 1);
    gpio_set_level(ROW3, 1);
    gpio_set_level(ROW4, 1);
    gpio_set_level(ROW5, 1);

    // Turn off all column pins
    gpio_set_level(COL1, 1);
    gpio_set_level(COL2, 1);
    gpio_set_level(COL3, 1);
}

void led_set_all(bool state) {
    // Set all row pins
    gpio_set_level(ROW1, state ? 0 : 1);
    gpio_set_level(ROW2, state ? 0 : 1);
    gpio_set_level(ROW3, state ? 0 : 1);
    gpio_set_level(ROW4, state ? 0 : 1);
    gpio_set_level(ROW5, state ? 0 : 1);

    // Set all column pins
    gpio_set_level(COL1, state ? 0 : 1);
    gpio_set_level(COL2, state ? 0 : 1);
    gpio_set_level(COL3, state ? 0 : 1);
}

void led_test_sequence() {
    // Turn on each LED one by one
    for (int row = 0; row <= 5; row++) {
        for (int col = 0; col <= 3; col++) {
            led_set(row, col, true);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            led_set(row, col, false);
        }
    }

    // Turn on all LEDs
    led_set_all(true);
    vTaskDelay(500 / portTICK_PERIOD_MS);

    // Turn off all LEDs
    led_set_all(false);
}