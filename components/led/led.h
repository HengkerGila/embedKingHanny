#pragma once 

#include <driver/gpio.h>

// LED pin
#define ROW1 GPIO_NUM_12
#define ROW2 GPIO_NUM_14
#define ROW3 GPIO_NUM_27
#define ROW4 GPIO_NUM_26
#define ROW5 GPIO_NUM_25

#define COL1 GPIO_NUM_17
#define COL2 GPIO_NUM_5
#define COL3 GPIO_NUM_18

void led_hal_init();
void testing_doang();
void led_set(int row, int col, bool state);
void led_clear();
void led_set_all(bool state);
void led_test_sequence();