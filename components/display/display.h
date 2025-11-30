#pragma once

#include <u8g2.h>

// I2C pins
#define PIN_SDA 21
#define PIN_SCL 22

void display_init();

void display_draw_logo(u8g2_t u8g2);
