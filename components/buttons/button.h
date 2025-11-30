#pragma once

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <driver/gpio.h>
#include <esp_log.h>

// Button pins
#define BUTTON_DOWN 15
#define BUTTON_UP 4
#define BUTTON_LEFT 2
#define BUTTON_RIGHT 16
#define BUTTON_SELECT 13

void buttons_init();
bool button_is_pressed(gpio_num_t button_pin);
bool button_wait_for_press(gpio_num_t button_pin, TickType_t timeout);
bool button_wait_for_release(gpio_num_t button_pin, TickType_t timeout);
void button_debounce_delay();
